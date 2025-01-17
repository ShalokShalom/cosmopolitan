/*-*- mode:c;indent-tabs-mode:nil;c-basic-offset:2;tab-width:8;coding:utf-8 -*-│
│vi: set net ft=c ts=2 sts=2 sw=2 fenc=utf-8                                :vi│
╞══════════════════════════════════════════════════════════════════════════════╡
│ Copyright 2020 Justine Alexandra Roberts Tunney                              │
│                                                                              │
│ Permission to use, copy, modify, and/or distribute this software for         │
│ any purpose with or without fee is hereby granted, provided that the         │
│ above copyright notice and this permission notice appear in all copies.      │
│                                                                              │
│ THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL                │
│ WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED                │
│ WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE             │
│ AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL         │
│ DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR        │
│ PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER               │
│ TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR             │
│ PERFORMANCE OF THIS SOFTWARE.                                                │
╚─────────────────────────────────────────────────────────────────────────────*/
#include "libc/fmt/itoa.h"
#include "libc/intrin/kprintf.h"
#include "libc/macros.internal.h"
#include "libc/runtime/memtrack.internal.h"

#define ADDR(x) ((intptr_t)((int64_t)((uint64_t)(x) << 32) >> 16))

static bool IsNoteworthyHole(unsigned i, const struct MemoryIntervals *mm) {
  // gaps between shadow frames aren't interesting
  // the chasm from heap to stack ruins statistics
  return !(
      (IsArenaFrame(mm->p[i].y) && !IsArenaFrame(mm->p[i + 1].x)) ||
      (IsShadowFrame(mm->p[i].y) || IsShadowFrame(mm->p[i + 1].x)) ||
      (!IsStaticStackFrame(mm->p[i].y) && IsStaticStackFrame(mm->p[i + 1].x)));
}

void PrintMemoryIntervals(int fd, const struct MemoryIntervals *mm) {
  char *p, mode[8];
  long i, w, frames, maptally = 0, gaptally = 0;
  for (w = i = 0; i < mm->i; ++i) {
    w = MAX(w, LengthInt64Thousands(mm->p[i].y + 1 - mm->p[i].x));
  }
  for (i = 0; i < mm->i; ++i) {
    frames = mm->p[i].y + 1 - mm->p[i].x;
    maptally += frames;
    kprintf("%012lx-%012lx %s %'*ldx%s", ADDR(mm->p[i].x), ADDR(mm->p[i].y + 1),
            DescribeMapping(mm->p[i].prot, mm->p[i].flags, mode), w, frames,
            DescribeFrame(mm->p[i].x));
    if (i + 1 < _mmi.i) {
      frames = mm->p[i + 1].x - mm->p[i].y - 1;
      if (frames && IsNoteworthyHole(i, mm)) {
        gaptally += frames;
        kprintf(" w/ %'ld frame hole", frames);
      }
    }
    if (mm->p[i].h != -1) {
      kprintf(" h=%ld", mm->p[i].h);
    }
    kprintf("%n");
  }
  kprintf("# %ld frames mapped w/ %'ld frames gapped%n", maptally, gaptally);
}

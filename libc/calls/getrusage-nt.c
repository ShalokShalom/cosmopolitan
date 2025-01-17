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
#include "libc/calls/calls.h"
#include "libc/calls/internal.h"
#include "libc/calls/struct/rusage.h"
#include "libc/fmt/conv.h"
#include "libc/nt/accounting.h"
#include "libc/nt/process.h"
#include "libc/nt/runtime.h"
#include "libc/nt/struct/processmemorycounters.h"
#include "libc/nt/thread.h"
#include "libc/str/str.h"
#include "libc/sysv/consts/rusage.h"
#include "libc/sysv/errfuns.h"

textwindows int sys_getrusage_nt(int who, struct rusage *usage) {
  struct NtFileTime CreationFileTime;
  struct NtFileTime ExitFileTime;
  struct NtFileTime KernelFileTime;
  struct NtFileTime UserFileTime;
  struct NtProcessMemoryCountersEx memcount;
  if (!usage) return efault();
  if (who == 99) return enosys(); /* @see libc/sysv/consts.sh */
  bzero(usage, sizeof(*usage));
  if ((who == RUSAGE_SELF ? GetProcessTimes : GetThreadTimes)(
          (who == RUSAGE_SELF ? GetCurrentProcess : GetCurrentThread)(),
          &CreationFileTime, &ExitFileTime, &KernelFileTime, &UserFileTime)) {
    /* xxx: shouldn't clobber memory on failure below */
    usage->ru_utime = WindowsDurationToTimeVal(ReadFileTime(UserFileTime));
    usage->ru_stime = WindowsDurationToTimeVal(ReadFileTime(KernelFileTime));
  } else {
    return __winerr();
  }
  if (GetProcessMemoryInfo(GetCurrentProcess(), &memcount, sizeof(memcount))) {
    usage->ru_maxrss = memcount.PeakWorkingSetSize / 1024;
    usage->ru_majflt = memcount.PageFaultCount;
  } else {
    return __winerr();
  }
  return 0;
}

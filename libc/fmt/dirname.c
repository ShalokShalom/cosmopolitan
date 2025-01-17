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
#include "libc/fmt/conv.h"
#include "libc/str/str.h"

#define ISSLASH(c) (c == '/' || c == '\\')
#define ISDELIM(c) (ISSLASH(c) || c == '.')

/**
 * Returns directory portion of path.
 *
 * This returns "." if path doesn't have slashes. If path is empty then
 * this returns empty string.
 *
 * @param s is mutated and must not be NULL
 */
char *dirname(char *s) {
  size_t i, n;
  if (!(n = strlen(s))) return s;
  while (n && ISDELIM(s[n - 1])) --n;
  if (n) {
    while (n && !ISSLASH(s[n - 1])) --n;
    if (n) {
      while (n && ISDELIM(s[n - 1])) --n;
      if (!n) ++n;
    } else {
      s[n++] = '.';
    }
  } else {
    ++n;
  }
  s[n] = '\0';
  return s;
}

#if 0
/*─────────────────────────────────────────────────────────────────╗
│ To the extent possible under law, Justine Tunney has waived      │
│ all copyright and related or neighboring rights to this file,    │
│ as it is written in the following disclaimers:                   │
│   • http://unlicense.org/                                        │
│   • http://creativecommons.org/publicdomain/zero/1.0/            │
╚─────────────────────────────────────────────────────────────────*/
#endif
#include "libc/log/backtrace.internal.h"
#include "libc/log/log.h"
#include "libc/runtime/runtime.h"
#include "libc/runtime/symbols.internal.h"
#include "libc/stdio/stdio.h"

int main(int argc, char *argv[]) {
  ShowCrashReports();
  if (IsDebuggerPresent(false)) {
    printf("debugger found!\r\n");
    DebugBreak();
    return 0;
  }
  printf("try running: gdb %s\r\n", argv[0]);
  return 1;
}

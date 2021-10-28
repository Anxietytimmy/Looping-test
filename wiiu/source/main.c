#include <coreinit/thread.h>
#include <coreinit/time.h>
#include <time.h>
#include <whb/proc.h>
#include <whb/log.h>
#include <whb/log_console.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <stdio.h>

int
main(int argc, char **argv)
{
   int a; 
   int last_tm_sec = -1;
   OSCalendarTime tm;
   clock_t start = clock()

   ;WHBProcInit();
   WHBLogConsoleInit();
	for (a = 10; a < 9999; a = a + 1) {
		WHBLogPrintf("value of a: %d\n", a);
	}

	clock_t stop = clock();
	double elapsed = (double) (stop - start) * 1000.0 / CLOCKS_PER_SEC;
   WHBLogPrintf("Time elapsed in ms: %f", elapsed);

   while(WHBProcIsRunning()) {
      OSTicksToCalendarTime(OSGetTime(), &tm);

      if (tm.tm_sec != last_tm_sec) {
         WHBLogPrintf("%02d/%02d/%04d %02d:%02d:%02d I'm still here.",
                      tm.tm_mday, tm.tm_mon, tm.tm_year,
                      tm.tm_hour, tm.tm_min, tm.tm_sec);
         last_tm_sec = tm.tm_sec;
       }

      WHBLogConsoleDraw();
      OSSleepTicks(OSMillisecondsToTicks(100));
   }

   WHBLogPrintf("Exiting... good bye.");
   WHBLogConsoleDraw();
   OSSleepTicks(OSMillisecondsToTicks(1000));

   WHBLogConsoleFree();
   WHBProcShutdown();
   return 0;
}

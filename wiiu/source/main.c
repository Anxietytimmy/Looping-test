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
   clock_t start = clock()

   ;WHBProcInit();
   WHBLogConsoleInit();
   WHBLogPrintf("Built on 10/29/2021");

	for (a = 10; a < 99999; a = a + 1) {
		WHBLogPrintf("value of a: %d\n", a);
	}

	clock_t stop = clock();
	double elapsed = (double) (stop - start) * 1000.0 / CLOCKS_PER_SEC;
   WHBLogPrintf("Time elapsed in ms: %f", elapsed);



   WHBLogPrintf("Exiting... good bye.");
   WHBLogConsoleDraw();
   OSSleepTicks(OSMillisecondsToTicks(1000));

   WHBLogConsoleFree();
   WHBProcShutdown();
   return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <3ds.h>
#include <time.h>

int main(int argc, char* argv[])
{
	int a;
	gfxInitDefault();
	gfxSetWide(true);
	consoleInit(GFX_TOP, NULL);
	
 	clock_t start = clock();

	for( a = 1; a <9999 ; a = a + 1 ){
      printf("value of a: %d\n", a);
   }

 	clock_t stop = clock();
    double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("Time elapsed in ms: %f", elapsed);

	// Main loop
	while (aptMainLoop())
	{
		gspWaitForVBlank();
		gfxSwapBuffers();
		hidScanInput();

		// Your code goes here
		u32 kDown = hidKeysDown();
		if (kDown & KEY_START)
			break; // break in order to return to hbmenu
	}

	gfxExit();
	return 0;
}
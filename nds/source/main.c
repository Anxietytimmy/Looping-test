
#include <nds.h>
#include <stdio.h>
#include <time.h>
//---------------------------------------------------------------------------------
int main(void) {
//---------------------------------------------------------------------------------
	consoleDemoInit();
	// int a variable for the loop later on 
	int a;
	// set what screen to print to 
	PrintConsole topScreen;
	
	videoSetMode(MODE_0_2D);
	videoSetModeSub(MODE_0_2D);

	vramSetBankA(VRAM_A_MAIN_BG);
	vramSetBankC(VRAM_C_SUB_BG);

	consoleInit(&topScreen, 3,BgType_Text4bpp, BgSize_T_256x256, 31, 0, true, true);

	// select a console to print to 
	consoleSelect(&topScreen);
	// Start a clock
	clock_t start = clock();
	// start the loop 
    for( a = 1; a < 9999; a = a + 1 ){
      printf("value of a: %d\n", a);
   }
	// stop the clock
	clock_t stop = clock();
    double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
	// print the time that the loop took (currently broken)
    printf("Time elapsed in ms: %f", elapsed);


	while(1) {
		swiWaitForVBlank();
		scanKeys();
		int pressed = keysDown();
		// Exit back to twilight menu or shut down when pressing start 
		if(pressed & KEY_START) break;
	}

} 

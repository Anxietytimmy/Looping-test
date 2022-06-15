
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
	// start the loop 
    for( a = 1; a < 9999; a = a + 1 ){
      printf("value of a: %d\n", a);
   }


	while(1) {
		swiWaitForVBlank();
		scanKeys();
		int pressed = keysDown();
		// Exit back to twilight menu or shut down when pressing start 
		if(pressed & KEY_START) break;
	}

} 

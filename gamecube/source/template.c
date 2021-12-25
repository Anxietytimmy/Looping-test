#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <ogcsys.h>
#include <gccore.h>
#include <time.h>

static void *xfb = NULL;
static GXRModeObj *rmode = NULL;

void *Initialise();
int a;
int main(int argc, char **argv) {

	xfb = Initialise();
	clock_t start = clock(); // start a clock 
		// start a loop 
		for (a = 10; a < 9999; a = a + 1) {
		printf("value of a: %d\n", a);
	}

	clock_t stop = clock();
	double elapsed = (double) (stop - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("Time elapsed in ms: %f", elapsed);  // print the elapsed time

	while(1) {

		VIDEO_WaitVSync();
		PAD_ScanPads();

		int buttonsDown = PAD_ButtonsDown(0);
		// i have no idea why this is here 
		if( buttonsDown & PAD_BUTTON_A ) {
			printf("Button A pressed.\n");
		}
	// return to menu if start is pressed
		if (buttonsDown & PAD_BUTTON_START) {
			exit(0);
		}
	}

	return 0;
}

void * Initialise() {

	void *framebuffer;

	VIDEO_Init();
	PAD_Init();
	
	rmode = VIDEO_GetPreferredMode(NULL);

	framebuffer = MEM_K0_TO_K1(SYS_AllocateFramebuffer(rmode));
	console_init(framebuffer,20,20,rmode->fbWidth,rmode->xfbHeight,rmode->fbWidth*VI_DISPLAY_PIX_SZ);
	
	VIDEO_Configure(rmode);
	VIDEO_SetNextFramebuffer(framebuffer);
	VIDEO_SetBlack(FALSE);
	VIDEO_Flush();
	VIDEO_WaitVSync();
	if(rmode->viTVMode&VI_NON_INTERLACE) VIDEO_WaitVSync();

	return framebuffer;

}

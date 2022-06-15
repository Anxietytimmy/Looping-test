// Include the most common headers from the C standard library
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h> 

// Include the main libnx system header, for Switch development
#include <switch.h>

// Main program entrypoint
int main(int argc, char* argv[])
{
    // This example uses a text console, as a simple way to output text to the screen.
    consoleInit(NULL);
    // int a variable for the loop 
    int a;

    // Configure our supported input layout: a single player with standard controller styles
    padConfigureInput(1, HidNpadStyleSet_NpadStandard);

    // Initialize the default gamepad (which reads handheld mode inputs as well as the first connected controller)
    PadState pad;
    padInitializeDefault(&pad);
    // print A int text
    printf("Press A to start looping\n");            
    // Try to get an imput with A, and if pressed, start a loop from 1 to 9999
    padUpdate(&pad);
    u64 kDown = padGetButtonsDown(&pad);
    if(kDown & HidNpadButton_A);{    
        sleep(1);
        system("cls");
        for( a = 1; a < 9999; a = a + 1 ){
            printf("value of a: %d\n", a);
       }
    }
    // add this in case the loop doesnt work 
    printf("endloop");
    // Main loop
    while (appletMainLoop())
    {
        // Scan the gamepad. This should be done once for each frame
        padUpdate(&pad);

        // padGetButtonsDown returns the set of buttons that have been
        // newly pressed in this frame compared to the previous one
        u64 kDown = padGetButtonsDown(&pad);


        if (kDown & HidNpadButton_Plus)
            break; // break in order to return to hbmenu

        // Update the console, sending a new frame to the display
        consoleUpdate(NULL);
    }

    // Deinitialize and clean up resources used by the console (important!)
    consoleExit(NULL);
    return 0;
}

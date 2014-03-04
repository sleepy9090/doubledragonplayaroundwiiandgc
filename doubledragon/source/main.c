/*
@author Shawn M. Crawford
Make Billy from Double Dragon walk.
For Gamecube/Wii
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <ogcsys.h>
#include <gccore.h>
#include <unistd.h>
#include <jpeg/jpgogc.h>

extern char fwalk1picdata[];
extern int  fwalk1piclength;
extern char fwalk2picdata[];
extern int  fwalk2piclength;
extern char fwalk3picdata[];
extern int  fwalk3piclength;
extern char fwalk4picdata[];
extern int  fwalk4piclength;
extern char bwalk1picdata[];
extern int  bwalk1piclength;
extern char bwalk2picdata[];
extern int  bwalk2piclength;
extern char bwalk3picdata[];
extern int  bwalk3piclength;
extern char bwalk4picdata[];
extern int  bwalk4piclength;

static u32 *xfb;
static GXRModeObj *rmode;

void displayJPG(JPEGIMG jpeg, int x, int y) {

    unsigned int *jpegout = (unsigned int *) jpeg.outbuffer;

    int i,j;
    int height = jpeg.height;
    int width = jpeg.width / 2;

    for(i=0;i<=width;i++) {
        for(j=0;j<=height-2;j++) {
            xfb[(i+x)+320*(j+y)]=jpegout[i+width*j];	
        }
    }
}

void init() {

    VIDEO_Init();
    PAD_Init();

    rmode = VIDEO_GetPreferredMode(NULL);

    xfb = MEM_K0_TO_K1(SYS_AllocateFramebuffer(rmode));
    console_init(xfb,20,20,rmode->fbWidth,rmode->xfbHeight,rmode->fbWidth*VI_DISPLAY_PIX_SZ);

    VIDEO_Configure(rmode);
    VIDEO_SetNextFramebuffer(xfb);
    VIDEO_SetBlack(FALSE);
    VIDEO_Flush();
    VIDEO_WaitVSync();

    if (rmode->viTVMode&VI_NON_INTERLACE) {
        VIDEO_WaitVSync();
    }
}

int main() {

    JPEGIMG fwalk1;
    JPEGIMG fwalk2;
    JPEGIMG fwalk3;
    JPEGIMG fwalk4;
    JPEGIMG bwalk1;
    JPEGIMG bwalk2;
    JPEGIMG bwalk3;
    JPEGIMG bwalk4;

    memset(&fwalk1, 0, sizeof(JPEGIMG));
    memset(&fwalk2, 0, sizeof(JPEGIMG));
    memset(&fwalk3, 0, sizeof(JPEGIMG));
    memset(&fwalk4, 0, sizeof(JPEGIMG));
    memset(&bwalk1, 0, sizeof(JPEGIMG));
    memset(&bwalk2, 0, sizeof(JPEGIMG));
    memset(&bwalk3, 0, sizeof(JPEGIMG));
    memset(&bwalk4, 0, sizeof(JPEGIMG));

    fwalk1.inbuffer = fwalk1picdata;
    fwalk1.inbufferlength = fwalk1piclength;
    fwalk2.inbuffer = fwalk2picdata;
    fwalk2.inbufferlength = fwalk2piclength;
    fwalk3.inbuffer = fwalk3picdata;
    fwalk3.inbufferlength = fwalk3piclength;
    fwalk4.inbuffer = fwalk4picdata;
    fwalk4.inbufferlength = fwalk4piclength;

    bwalk1.inbuffer = bwalk1picdata;
    bwalk1.inbufferlength = bwalk1piclength;
    bwalk2.inbuffer = bwalk2picdata;
    bwalk2.inbufferlength = bwalk2piclength;
    bwalk3.inbuffer = bwalk3picdata;
    bwalk3.inbufferlength = bwalk3piclength;
    bwalk4.inbuffer = bwalk4picdata;
    bwalk4.inbufferlength = bwalk4piclength;

    JPEG_Decompress(&fwalk1);
    JPEG_Decompress(&fwalk2);
    JPEG_Decompress(&fwalk3);
    JPEG_Decompress(&fwalk4);
    JPEG_Decompress(&bwalk1);
    JPEG_Decompress(&bwalk2);
    JPEG_Decompress(&bwalk3);
    JPEG_Decompress(&bwalk4);

    bool facingforward = true;

    init();

    while(1) {

        VIDEO_ClearFrameBuffer (rmode, xfb, COLOR_BLACK);

        if (facingforward) {
            displayJPG(fwalk1, 50, 50);
        } else {
            displayJPG(bwalk1, 50, 50);
        }

        PAD_ScanPads();

        if (PAD_StickX(0) > 18) {
            VIDEO_ClearFrameBuffer (rmode, xfb, COLOR_BLACK);
            displayJPG(fwalk1, 50, 50);
            // sleep for 1/2 second
            usleep(500000);
            VIDEO_ClearFrameBuffer (rmode, xfb, COLOR_BLACK);
            displayJPG(fwalk2, 50, 50);
            usleep(500000);
            VIDEO_ClearFrameBuffer (rmode, xfb, COLOR_BLACK);
            displayJPG(fwalk3, 50, 50);
            usleep(500000);
            VIDEO_ClearFrameBuffer (rmode, xfb, COLOR_BLACK);
            displayJPG(fwalk4, 50, 50);
            usleep(500000);
            VIDEO_ClearFrameBuffer (rmode, xfb, COLOR_BLACK);
            facingforward = true;
        }

        if (PAD_StickX(0) < -18) {
            VIDEO_ClearFrameBuffer (rmode, xfb, COLOR_BLACK);
            displayJPG(bwalk1, 50, 50);
            // sleep for 1/2 second
            usleep(500000);
            VIDEO_ClearFrameBuffer (rmode, xfb, COLOR_BLACK);
            displayJPG(bwalk2, 50, 50);
            usleep(500000);
            VIDEO_ClearFrameBuffer (rmode, xfb, COLOR_BLACK);
            displayJPG(bwalk3, 50, 50);
            usleep(500000);
            VIDEO_ClearFrameBuffer (rmode, xfb, COLOR_BLACK);
            displayJPG(bwalk4, 50, 50);
            usleep(500000);
            VIDEO_ClearFrameBuffer (rmode, xfb, COLOR_BLACK);
            facingforward = false;
        }

    VIDEO_WaitVSync();

    }

    return 0;
}

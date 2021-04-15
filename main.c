/*** Copyright (C) 2021 Andreas Riebesehl
**** This work is licensed under: This work is presently unlicensed.
****
***/
#include <stdio.h>
#include <ZTK.h>
// USER DEFINES
//#define DRAW_GRID // uncomment to enable drawing grid and legend
#define PATH_SOURCE "C:\\Users\\Andi\\Desktop\\arulco\\sources\\a01.bmp" // files *must* be called "yxx.bmp"
#define PATH_OUTPUT "C:\\Users\\Andi\\Desktop\\arulco\\full-0.bmp"
// SYSTEM DEFINES // do not change!
#define MAP_X 16
#define MAP_Y 16
#define IMAGE_X 640
#define IMAGE_Y 320
#ifdef DRAW_GRID
#define COLOR_GRID 0xff00c8f8
#define SIZE_GRID 2
#define SIZE_LEGEND (IMAGE_Y >> 1)
#else
#define SIZE_LEGEND 0
#endif // DRAW_GRID
void gMain(void) {
    // INIT
    ZT_EVENT* lEvent;
    while (ZTK_PollMessages(&lEvent));
    // MAP COMPOSITION
    ZT_CHAR lPath[] = PATH_SOURCE;
    ZT_INDEX lEnum00X = ZTC8_GetLength(lPath) - 5;
    ZT_INDEX lEnum0X0 = lEnum00X - 1;
    ZT_INDEX lEnumY00 = lEnum0X0 - 1;
    ZT_RECT lCrop;
    lCrop.y = SIZE_LEGEND;
    lCrop.w = IMAGE_X;
    lCrop.h = IMAGE_Y;
    ZT_I lPixelsX = MAP_X * IMAGE_X + 2 * SIZE_LEGEND;
    ZT_I lPixelsY = MAP_Y * IMAGE_Y + 2 * SIZE_LEGEND;
    ZT_SURFACE* lComposite = ZTM_SurfaceNewFromIntegers(lPixelsX, lPixelsY, NULL);
    for (lPath[lEnumY00] = 0x61; lPath[lEnumY00] < 0x61 + MAP_Y; ++lPath[lEnumY00]) {
        lCrop.x = SIZE_LEGEND;
        for (ZT_INDEX i = 1; i <= MAP_X; ++i) {
            lPath[lEnum0X0] = (i / 10) + 0x30;
            lPath[lEnum00X] = (i % 10) + 0x30;
            printf("(%04d, %04d) Loading \"%s\"...", lCrop.x, lCrop.y, (const char*)lPath);
            ZT_SURFACE* lBitmap = ZTM_SurfaceFromBitmap(lPath, ZTM_PALETTE_ABGR);
            if (lBitmap != NULL) {
                printf("ok!\n");
                ZTM_SurfaceBlend(lBitmap, lComposite, NULL, &lCrop, ZTM_PALETTE_ABGR);
                ZTM_SurfaceFree(lBitmap);
            } else {
                printf("fail!\n");
            }
            lCrop.x += IMAGE_X;
        }
        lCrop.y += IMAGE_Y;
    }
    // GRID
    #ifdef DRAW_GRID
    for (ZT_I i = 0; i <= MAP_Y; ++i) {
        for (ZT_I g = 0; g < SIZE_GRID; ++g) {
            ZT_I lOffset = lPixelsX * (SIZE_LEGEND + (i * IMAGE_Y) + g) - 1;
            for (ZT_I x = 0; x < lPixelsX; ++x) {lComposite->pixels[++lOffset] = COLOR_GRID;}
        }
    }
    for (ZT_I i = 0; i <= MAP_X; ++i) {
        for (ZT_I g = 0; g < SIZE_GRID; ++g) {
            ZT_I lOffset = (SIZE_LEGEND + i * IMAGE_X + g) - lPixelsX;
            for (ZT_I y = 0; y < lPixelsY; ++y) {lComposite->pixels[lOffset += lPixelsX] = COLOR_GRID;}
        }
    }
    // LEGEND
    ZTK_PaletteUser(ZTM_PALETTE_ABGR);
    ZT_FONT* lFont = ZTK_FontNew(NULL, (const ZT_CHAR*)"Arial", SIZE_LEGEND / 2, ZTK_FONT_STYLE_NORMAL, COLOR_GRID);
    for (ZT_I i = 0; i < MAP_Y; ++i) {
        ZT_CHAR lText[3];
        ZT_CHAR n = i + 1;
        if (n < 10) {
            lText[0] = 0x30 + n;
            lText[1] = 0x0;
        } else {
            lText[0] = 0x30 + (n / 10);
            lText[1] = 0x30 + (n % 10);
            lText[2] = 0x0;
        }
        ZT_FLAG lPalette;
        ZT_SURFACE* lLegend = ZTK_SurfaceFromFont(lText, lFont, &lPalette);
        ZTM_SurfaceConvert(lLegend, lPalette, ZTM_PALETTE_ABGR);
        ZT_RECT lRect;
        lRect.w = lLegend->block.x;
        lRect.h = lLegend->block.y;
        lRect.x = SIZE_LEGEND + IMAGE_X / 2 + i * IMAGE_X - lLegend->block.x / 2;
        lRect.y = SIZE_LEGEND / 2 - lLegend->block.y / 2;
        ZTM_SurfaceBlend(lLegend, lComposite, NULL, &lRect, ZTM_PALETTE_ABGR);
        lRect.y = lPixelsY - SIZE_LEGEND / 2 - lLegend->block.y / 2;
        ZTM_SurfaceBlend(lLegend, lComposite, NULL, &lRect, ZTM_PALETTE_ABGR);
        ZTM_SurfaceFree(lLegend);
    }
    for (ZT_I i = 0; i < MAP_X; ++i) {
        ZT_CHAR lText[2] = {0x41 + i, 0x0};
        ZT_FLAG lPalette;
        ZT_SURFACE* lLegend = ZTK_SurfaceFromFont(lText, lFont, &lPalette);
        ZTM_SurfaceConvert(lLegend, lPalette, ZTM_PALETTE_ABGR);
        ZT_RECT lRect;
        lRect.w = lLegend->block.x;
        lRect.h = lLegend->block.y;
        lRect.y = SIZE_LEGEND + IMAGE_Y / 2 + i * IMAGE_Y - lLegend->block.y / 2;
        lRect.x = SIZE_LEGEND / 2 - lLegend->block.x / 2;
        ZTM_SurfaceBlend(lLegend, lComposite, NULL, &lRect, ZTM_PALETTE_ABGR);
        lRect.x = lPixelsX - SIZE_LEGEND / 2 - lLegend->block.x / 2;
        ZTM_SurfaceBlend(lLegend, lComposite, NULL, &lRect, ZTM_PALETTE_ABGR);
        ZTM_SurfaceFree(lLegend);
    }
    ZTK_FontFree(lFont);
    #endif // DRAW_GRID
    // WRITEOUT
    printf("\nWriting \"%s\"...\n", PATH_OUTPUT);
    ZT_SIZE lBytesWritten = ZTM_SurfaceSaveToBitmapFile(lComposite, (const ZT_CHAR*)PATH_OUTPUT, ZTM_PALETTE_ABGR);
    printf("\t%u byte(s) written!\n", lBytesWritten);
    // EXIT
    ZTM_SurfaceFree(lComposite);
    ZTK_Quit();
}
int main() {
    ZTK_New(&gMain, NULL, NULL, NULL);
    ZTK_Open();
    while (ZTK_Main());
    ZTK_Free();
    return 0;
}

# Complete Jagged Alliance 2 Map of Arulco



A composition of all the Arulco radarmaps from *Jagged Alliance 2*, into one large image.



![](https://github.com/ariebesehl/JA2-Radarmap/raw/main/grid-2.jpg)



## Results

1) Entire map, **no grid**, compressed .jpg, [10240x5120](https://github.com/ariebesehl/JA2-Radarmap/raw/main/full-0.jpg), [5120x2560](https://github.com/ariebesehl/JA2-Radarmap/raw/main/full-1.jpg), [2560x1280](https://github.com/ariebesehl/JA2-Radarmap/raw/main/full-2.jpg), [1280x640](https://github.com/ariebesehl/JA2-Radarmap/raw/main/full-3.jpg)

2) Entire map, **with grid**, compressed .jpg, [10560x5440](https://github.com/ariebesehl/JA2-Radarmap/raw/main/grid-0.jpg), [5280x2720](https://github.com/ariebesehl/JA2-Radarmap/raw/main/grid-1.jpg), [2640x1360](https://github.com/ariebesehl/JA2-Radarmap/raw/main/grid-2.jpg), [1320x680](https://github.com/ariebesehl/JA2-Radarmap/raw/main/grid-3.jpg)

3) Entire map, 7-zipped archive of uncompressed bitmap [with](https://github.com/ariebesehl/JA2-Radarmap/raw/main/grid-0.bmp.7z) and [without](https://github.com/ariebesehl/JA2-Radarmap/raw/main/full-0.bmp.7z) grid

4) 7-zipped archive of uncompressed composition [source bitmaps](https://github.com/ariebesehl/JA2-Radarmap/raw/main/sources.7z)

5) Composition tool [source code](https://github.com/ariebesehl/JA2-Radarmap/raw/main/main.c) and [Code::Blocks project file](https://github.com/ariebesehl/JA2-Radarmap/raw/main/main.cbp)


## Method

1) Every passable sector was opened in the JA2 v1.13 Map Editor, a radarmap was displayed, and a screenshot was taken. Screenshots are saved in Targa Truevision format.

2) Screenshots were then cropped to only the displayed radarmap, and saved in bitmap file format for easy handling.

3) Bitmaps were then composited into a full map with a custom-written binary (`main.c`) utilizing the ZDK library, and saved as one large bitmap.


## Tools

1) [IrfanView](https://www.irfanview.com/), for viewing and converting .tga files, batch cropping, conversion and renaming, and (resampled) resizing of output files

2) [ZDK](https://github.com/ZaidaTek/ZDK), for loading and saving bitmaps into pixel arrays, and image, grid and font composition

3) [Code::Blocks](https://www.codeblocks.org/), for compiling (with GCC and MingW)

4) [7-Zip](https://www.7-zip.org/), for handling 7z-archives


## Motivation

About twenty years ago, when I first played JA2, I always imagined what it would be like as a tactical first-person-shooter. Fast-forward fifteen years, and I find myself playing ARMA 3 when I realized, this is actually it, it's just missing the characters, plot and soul from JA2... and since ARMA 3 is *very* mod-friendly, everything's already there. It just needs to be put together...


## License

All copyrights belong to their respective owners. Radarmaps are screenshotted, and so should fall under a fair-use policy. Code I've written is unlicensed.


![](https://github.com/ariebesehl/JA2-Radarmap/raw/main/full-2.jpg)


#ifndef DEFINES_H
#define DEFINES_H

#include <fstream>

struct RGB{
    int red;
    int green;
    int blue;
};

void saveBitmap(const char * fileName, int width, int height, int dpi, RGB * data) {

    /*
     * File pointer
     */

    FILE *file;

    /*
     * bmp data size
     */

    int k = width * height;
    int s = 4 * k;

    /*
     * Total size of bmp file = bmp file header size + bmp info header size + bmp data size
     * bmp file header size = 14
     * bmp info header size = 40
     */

    int fileSize = 40 + 14 + s;

    /*
     * The pixel per meter for the given dpi
     */

    int factor = 39;
    int ppm = dpi * factor;

    /*
     * bitmapFileHeader contains information about the bmp file itself
     * bmp file header of 14 bytes
     * First 2 bytes (index 0 and 1) are for "B" and "M"
     * Next 4 bytes (index 2..5) specifies size of bmp file in bytes
     * Next 2 bytes (index 6, 7) must be set to 0
     * Next 2 bytes (index 8, 9) must be set to 0
     * Next 4 bytes (index 10, 11, 12, 13) specifies offset from the beginning of the file to the bitmap data
     */
    unsigned char bitmapFileHeader[14] = {'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0};

    /*
     * Set the 2...5 indices of bitmapFileHeader
     * Index 3 = fileSize >> 8 := moves already consumed byte (8 bits) to the right so that fresh byte can be set
     */

    bitmapFileHeader[2] = (unsigned char) (fileSize);
    bitmapFileHeader[3] = (unsigned char) (fileSize >> 8);
    bitmapFileHeader[4] = (unsigned char) (fileSize >> 16);
    bitmapFileHeader[5] = (unsigned char) (fileSize >> 24);

    /*
     * bitmapInfoHeader contains information about the bitmap like height, width, colors etc
     * First 4 bytes (index 0...3) specifies the size of bmp info header
     * Next 4 bytes (index 4...7) specifies the width of image in pixels
     * Next 4 bytes (index 8...11) specifies the height of image in pixels
     * Next 2 bytes (index 12..13) specifies the no. of planes of target device, must be 0
     * Next 2 bytes (index 14..15) specifies the no. of bits per pixel
     * Next 4 bytes (index 16..19) specifies the type of compression (no compression values to 0)
     * Next 4 bytes (index 20..23) specifies the size of the image data, in bytes. If there is no compression, it is valid to set this member to zero
     * Next 4 bytes (index 24...27) specifies the the horizontal pixels per meter
     * Next 4 bytes (index 28...31) specifies the the vertical pixels per meter
     * Next 4 bytes (index 32...35) specifies the number of colors used in the bitmap
     * Next 4 bytes (index 36...39) specifies the number of color that are 'important' for the bitmap, if set to zero, all colors are important
     */

    unsigned char bitmapInfoHeader[40] = {40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24, 0};

    /*
     * Sets the bmp info header according to the bmp data
     */

    bitmapInfoHeader[4] = (unsigned char) (width);
    bitmapInfoHeader[5] = (unsigned char) (width >> 8);
    bitmapInfoHeader[6] = (unsigned char) (width >> 16);
    bitmapInfoHeader[7] = (unsigned char) (width >> 24);

    bitmapInfoHeader[8] = (unsigned char) (height);
    bitmapInfoHeader[9] = (unsigned char) (height >> 8);
    bitmapInfoHeader[10] = (unsigned char) (height >> 16);
    bitmapInfoHeader[11] = (unsigned char) (height >> 24);

    bitmapInfoHeader[20] = (unsigned char) (s);
    bitmapInfoHeader[21] = (unsigned char) (s >> 8);
    bitmapInfoHeader[22] = (unsigned char) (s >> 16);
    bitmapInfoHeader[23] = (unsigned char) (s >> 24);

    bitmapInfoHeader[24] = (unsigned char) (ppm);
    bitmapInfoHeader[25] = (unsigned char) (ppm >> 8);
    bitmapInfoHeader[26] = (unsigned char) (ppm >> 16);
    bitmapInfoHeader[27] = (unsigned char) (ppm >> 24);

    bitmapInfoHeader[28] = (unsigned char) (ppm);
    bitmapInfoHeader[29] = (unsigned char) (ppm >> 8);
    bitmapInfoHeader[30] = (unsigned char) (ppm >> 16);
    bitmapInfoHeader[31] = (unsigned char) (ppm >> 24);

    /*
     * Save the bmpFileHeader and the bmpInfoHeader
     */

    file = fopen(fileName, "wb");
    fwrite(bitmapFileHeader, 1, 14, file);
    fwrite(bitmapInfoHeader, 1, 40, file);

    /*
     * Add the bmp image data to the bmp file
     */

    for (int i = 0; i < k; i++) {
        RGB rgb = data[i];

        double red = data[i].red * 255;
        double green = data[i].green * 255;
        double blue = data[i].blue * 255;

        unsigned char color[3] = { (unsigned char)floor(blue),
                                   (unsigned char)floor(green),
                                   (unsigned char)floor(red) };
        fwrite(color, 1, 3, file);
    }

    fclose(file);
}

#endif  //DEFINES_H

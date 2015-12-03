#ifndef READ_BMP_BMP2_H
#define READ_BMP_BMP2_H

#include <cstddef>
#include <iostream>

struct BMPHeader {
  //tagBITMAPFILEHEADER
  int16_t bfType;
  int32_t bfSize;
  int16_t bfReserved1;
  int16_t bfReserved2;
  int32_t bfOffBits;

  //tagBITMAPINFOHEADER
  int32_t biSize;
  int32_t biWidth;
  int32_t biHeight;
  int16_t biPlanes;
  int16_t biBitCount;
  int32_t biCompression;
  int32_t biSizeImage;
  int32_t biXPelsPerMeter;
  int32_t biYPelsPerMeter;
  int32_t biClrUsed;
  int32_t biClrImportant;
};



#define __O(NAME) offsetof(BMPHeader, NAME)


size_t OFFSET2[] = {
  __O(bfType),
  __O(bfSize),
  __O(bfReserved1),
  __O(bfReserved2),
  __O(bfOffBits),

  __O(biSize),
  __O(biWidth),
  __O(biHeight),
  __O(biPlanes),
  __O(biBitCount),
  __O(biCompression),
  __O(biSizeImage),
  __O(biXPelsPerMeter),
  __O(biYPelsPerMeter),
  __O(biClrUsed),
  __O(biClrImportant),
};



#define __S(NAME) sizeof(BMPHeader::NAME)

size_t SIZE2[] = {
  __S(bfType),
  __S(bfSize),
  __S(bfReserved1),
  __S(bfReserved2),
  __S(bfOffBits),

  __S(biSize),
  __S(biWidth),
  __S(biHeight),
  __S(biPlanes),
  __S(biBitCount),
  __S(biCompression),
  __S(biSizeImage),
  __S(biXPelsPerMeter),
  __S(biYPelsPerMeter),
  __S(biClrUsed),
  __S(biClrImportant)
};


void readBMPHeader2(BMPHeader *header, FILE *file) {
  size_t length = sizeof(OFFSET2) / sizeof(size_t);
  char *dest = (char*)header;

  for (size_t i = 0; i < length; ++i)
    fread(dest + OFFSET2[i], SIZE2[i], 1, file);
}

#undef __S
#undef __O


#endif //READ_BMP_BMP2_H

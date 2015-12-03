
#ifndef READ_BMP_BMP1_H_H
#define READ_BMP_BMP1_H_H

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


size_t OFFSET1[] = {
  offsetof(BMPHeader, bfType),
  offsetof(BMPHeader, bfSize),
  offsetof(BMPHeader, bfReserved1),
  offsetof(BMPHeader, bfReserved2),
  offsetof(BMPHeader, bfOffBits),

  offsetof(BMPHeader, biSize),
  offsetof(BMPHeader, biWidth),
  offsetof(BMPHeader, biHeight),
  offsetof(BMPHeader, biPlanes),
  offsetof(BMPHeader, biBitCount),
  offsetof(BMPHeader, biCompression),
  offsetof(BMPHeader, biSizeImage),
  offsetof(BMPHeader, biXPelsPerMeter),
  offsetof(BMPHeader, biYPelsPerMeter),
  offsetof(BMPHeader, biClrUsed),
  offsetof(BMPHeader, biClrImportant)
};

size_t SIZE1[] = {
  sizeof(BMPHeader::bfType),
  sizeof(BMPHeader::bfSize),
  sizeof(BMPHeader::bfReserved1),
  sizeof(BMPHeader::bfReserved2),
  sizeof(BMPHeader::bfOffBits),

  sizeof(BMPHeader::biSize),
  sizeof(BMPHeader::biWidth),
  sizeof(BMPHeader::biHeight),
  sizeof(BMPHeader::biPlanes),
  sizeof(BMPHeader::biBitCount),
  sizeof(BMPHeader::biCompression),
  sizeof(BMPHeader::biSizeImage),
  sizeof(BMPHeader::biXPelsPerMeter),
  sizeof(BMPHeader::biYPelsPerMeter),
  sizeof(BMPHeader::biClrUsed),
  sizeof(BMPHeader::biClrImportant)
};

void readBMPHeader1(BMPHeader *header, FILE *file) {
  size_t length = sizeof(OFFSET1) / sizeof(size_t);
  char *dest = (char*)header;

  for (size_t i = 0; i < length; ++i)
    fread(dest + OFFSET1[i], SIZE1[i], 1, file);
}



#endif //READ_BMP_BMP1_H_H

#ifndef READ_BMP_BMP0_H
#define READ_BMP_BMP0_H

#include <cstddef>
#include <iostream>


#pragma pack(push)
#pragma pack(1)

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

#pragma pack(pop)


void readBMPHeader0(BMPHeader *header, FILE *file) {
  fread(header, sizeof(BMPHeader), 1, file);
}

#endif //READ_BMP_BMP0_H

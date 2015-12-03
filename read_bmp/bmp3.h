#ifndef READ_BMP_BMP3_H
#define READ_BMP_BMP3_H

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



struct OffSize
{

  OffSize(size_t offset, size_t size) : offset(offset), size(size)
  { }

  size_t offset;
  size_t size;
};



#define __O(NAME) offsetof(BMPHeader, NAME)
#define __S(NAME) sizeof(BMPHeader::NAME)
#define __OS(NAME) OffSize(__O(NAME), __S(NAME))



OffSize OFF_SIZE3[] = {
  __OS(bfType),
  __OS(bfSize),
  __OS(bfReserved1),
  __OS(bfReserved2),
  __OS(bfOffBits),

  __OS(biSize),
  __OS(biWidth),
  __OS(biHeight),
  __OS(biPlanes),
  __OS(biBitCount),
  __OS(biCompression),
  __OS(biSizeImage),
  __OS(biXPelsPerMeter),
  __OS(biYPelsPerMeter),
  __OS(biClrUsed),
  __OS(biClrImportant)
};




void readBMPHeader3(BMPHeader *header, FILE *file) {
  size_t length = sizeof(OFF_SIZE3) / sizeof(size_t);
  char *dest = (char*)header;

  for (size_t i = 0; i < length; ++i)
    fread(dest + OFF_SIZE3[i].offset, OFF_SIZE3[i].size, 1, file);
}



#undef __OS
#undef __S
#undef __O

#endif //READ_BMP_BMP3_H

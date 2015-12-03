#ifndef READ_BMP_BMP4_H
#define READ_BMP_BMP4_H

#include <cstddef>
#include <iostream>



struct OffSize
{

  OffSize(size_t offset, size_t size) : offset(offset), size(size)
  { }

  size_t offset;
  size_t size;
};


#define __FOR_FIELDS(__DO)                  \
        __DO(int16_t, bfType)               \
        __DO(int32_t, bfSize)               \
        __DO(int16_t, bfReserved1)          \
        __DO(int16_t, bfReserved2)          \
        __DO(int32_t, bfOffBits)            \
        __DO(int32_t, biSize)               \
        __DO(int32_t, biWidth)              \
        __DO(int32_t, biHeight)             \
        __DO(int16_t, biPlanes)             \
        __DO(int16_t, biBitCount)           \
        __DO(int32_t, biCompression)        \
        __DO(int32_t, biSizeImage)          \
        __DO(int32_t, biXPelsPerMeter)      \
        __DO(int32_t, biYPelsPerMeter)      \
        __DO(int32_t, biClrUsed)            \
        __DO(int32_t, biClrImportant)



#define __DECLARE(TYPE, NAME) TYPE NAME;




struct BMPHeader
{
  __FOR_FIELDS(__DECLARE)
};




#define __O(NAME) offsetof(BMPHeader, NAME)
#define __S(NAME) sizeof(BMPHeader::NAME)
#define __OS(NAME) OffSize(__O(NAME), __S(NAME))
#define __OS2(TYPE, NAME) __OS(NAME),




OffSize OFF_SIZE4[] = {__FOR_FIELDS(__OS2)};


void readBMPHeader4(BMPHeader *header, FILE *file) {
  size_t length = sizeof(OFF_SIZE4) / sizeof(size_t);
  char *dest = (char*)header;

  for (size_t i = 0; i < length; ++i)
    fread(dest + OFF_SIZE4[i].offset, OFF_SIZE4[i].size, 1, file);
}





#undef __OS2
#undef __OS
#undef __S
#undef __O
#undef __DECLARE
#undef __FOR_FIELDS

#endif //READ_BMP_BMP4_H

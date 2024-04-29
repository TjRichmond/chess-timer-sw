#ifndef __MAX7219_H__
#define __MAX7219_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "main.h"

  extern MAX7219_HandleTypeDef hmax7219;

  void MX_MAX7219_Init(
    SPI_HandleTypeDef *hspi
  );

#ifdef __cplusplus
}
#endif

#endif

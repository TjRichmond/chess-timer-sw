/**
 * @file    hal_ls027b7.h
 * @brief   Module for Sharp 2.7" 1-bit memory LCD display
 */
#ifndef _HAL_LS027B7_H
#define _HAL_LS027B7_H

#ifdef __cplusplus
extern "C" {
#endif
#include "stm32u0xx_hal.h"

#define LS027B7_DUMMY_DATA 0
#define LS027B7_DATA_OFFSET 2


/**
 * @brief HAL LS027B7 command definition
 */
typedef enum {
  DISPLAY_MODE = 0x00,
  CLEAR_MODE = 0x20,
  LS027B7_UPDATE_MODE = 0x80
} LS027B7_CommandTypeDef;

/**
 * @brief LS027B7 handle structure definition 
 */
typedef struct __LS027B7_HandleTypeDef {
  GPIO_TypeDef *CSPort;
  uint16_t CSPin;
  SPI_HandleTypeDef *hspi;
  uint8_t DisplayData[240][54];
} LS027B7_HandleTypeDef;

HAL_StatusTypeDef HAL_LS027B7_Init(
  LS027B7_HandleTypeDef *hls027b7
);

HAL_StatusTypeDef HAL_LS027B7_DrawLine(
  LS027B7_HandleTypeDef *hls027b7,
  uint8_t row
);

HAL_StatusTypeDef HAL_LS027B7_DrawPixel(
  LS027B7_HandleTypeDef *hls027b7,
  uint8_t row,
  uint8_t col
);

HAL_StatusTypeDef HAL_LS027B7_ClearDisplay(
  LS027B7_HandleTypeDef *hls027b7
);

#ifdef __cplusplus
}
#endif

#endif
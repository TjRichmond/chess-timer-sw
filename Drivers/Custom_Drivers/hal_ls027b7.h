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

/*! Resolution macros */
#define LS027B7_HEIGHT 240
#define LS027B7_WIDTH_BITS 400
#define LS027B7_WIDTH_BYTES (LS027B7_WIDTH_BITS / 8)

/**
 * @brief HAL LS027B7 command definition
 */
typedef enum {
  LS027B7_DISPLAY_MODE = 0x00,
  LS027B7_CLEAR_MODE = 0x20,
  LS027B7_UPDATE_MODE = 0x80
} LS027B7_CommandTypeDef;

/*! Message bytes */
typedef enum {
  LS027B7_MSG_CMD,
  LS027B7_MSG_ADDR,
  LS027B7_MSG_HEADER_SIZE,

  LS027B7_MSG_COL_START = LS027B7_MSG_HEADER_SIZE,
  LS027B7_MSG_COL_END = LS027B7_MSG_COL_START + LS027B7_WIDTH_BYTES,
  LS027B7_MSG_SIZE = LS027B7_MSG_COL_END
} LS027B7_MsgBytesTypeDef;

/**
 * @brief LS027B7 handle structure definition 
 */
typedef struct __LS027B7_HandleTypeDef {
  GPIO_TypeDef *CSPort;
  uint16_t CSPin;
  SPI_HandleTypeDef *hspi;
  uint8_t DisplayData[LS027B7_HEIGHT][LS027B7_MSG_SIZE];
} LS027B7_HandleTypeDef;

HAL_StatusTypeDef HAL_LS027B7_Init(
  LS027B7_HandleTypeDef *hls027b7
);

HAL_StatusTypeDef HAL_LS027B7_DrawChar(
  LS027B7_HandleTypeDef *hls027b7,
  uint8_t x,
  uint8_t y,
  uint8_t c
);

HAL_StatusTypeDef HAL_LS027B7_DrawString(
  LS027B7_HandleTypeDef *hls027b7,
  uint8_t x,
  uint8_t y,
  char* string,
  uint8_t stringSize
);

HAL_StatusTypeDef HAL_LS027B7_DrawLine(
  LS027B7_HandleTypeDef *hls027b7,
  uint8_t y
);

HAL_StatusTypeDef HAL_LS027B7_DrawPixel(
  LS027B7_HandleTypeDef *hls027b7,
  uint8_t x,
  uint8_t y
);

HAL_StatusTypeDef HAL_LS027B7_ClearDisplay(
  LS027B7_HandleTypeDef *hls027b7
);

#ifdef __cplusplus
}
#endif

#endif
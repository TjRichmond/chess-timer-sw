/**
 * @file    hal_ls027b7.c
 * @brief   Module for Sharp 2.7" 1-bit LCD display
 */

#include "hal_fonts.h"
#include "hal_ls027b7.h"

static uint8_t reverseBits(
  uint8_t byte
);

static void updateRows(
  LS027B7_HandleTypeDef *hls027b7,
  uint8_t y1,
  uint8_t y2
);

/*! Macro to convert column number to bit position */
#define LS027B7_COL_TO_BIT(col) ~(1 << (col % 8))
#define LS027B7_X_TO_BYTE(x) (x / 8)
#define LS027B7_X_TO_BIT_POS(x) (x % 8)

#define LS027B7_EMPTY_ROW 0xFF
#define LS027B7_MSG_TIMEOUT 1000

const uint8_t displayMsg[LS027B7_MSG_HEADER_SIZE] = {LS027B7_DISPLAY_MODE, LS027B7_DUMMY_DATA};
const uint8_t clearMsg[LS027B7_MSG_HEADER_SIZE] = {LS027B7_CLEAR_MODE, LS027B7_DUMMY_DATA};
const uint8_t spareBytes[LS027B7_MSG_HEADER_SIZE] = {LS027B7_DUMMY_DATA, LS027B7_DUMMY_DATA};

/**
 * @brief Initialize screen pixel values and screen struct
 */
HAL_StatusTypeDef HAL_LS027B7_Init(
  LS027B7_HandleTypeDef *hls027b7
)
{
  uint8_t i, j;

  for (j = LS027B7_MSG_CMD; j < LS027B7_HEIGHT; j++) {
    for (i = LS027B7_MSG_COL_START; i < LS027B7_MSG_COL_END; i++) {
      /*! Initialize all pixels in row to off */
      hls027b7->DisplayData[j][i] = LS027B7_EMPTY_ROW;
    }

    /*! Initialize dummy bytes */
    hls027b7->DisplayData[j][LS027B7_MSG_CMD] = LS027B7_UPDATE_MODE;
    hls027b7->DisplayData[j][LS027B7_MSG_ADDR] = reverseBits(j);
  }

  return HAL_OK;
}

HAL_StatusTypeDef HAL_LS027B7_DrawChar(
  LS027B7_HandleTypeDef *hls027b7,
  uint8_t x,
  uint8_t y,
  uint8_t c
)
{
  uint8_t i;
  for (i = 0; i < 8; i++) {
    hls027b7->DisplayData[y + i][LS027B7_X_TO_BYTE(x) + LS027B7_MSG_COL_START] &= ~(cp437[c][i]);
  }
  
  updateRows(hls027b7, y, y + 7);

  return HAL_OK;
}

HAL_StatusTypeDef HAL_LS027B7_DrawString(
  LS027B7_HandleTypeDef *hls027b7,
  uint8_t x,
  uint8_t y,
  char* string,
  uint8_t stringSize
)
{
  uint8_t i, j;
  for (j = 0; j < stringSize; j++) {
    for (i = 0; i < 8; i++) {
      hls027b7->DisplayData[y + i][LS027B7_X_TO_BYTE(x) + LS027B7_MSG_COL_START + j*8] &=
       ~(cp437[string[j]][i]);
    }
  }

  updateRows(hls027b7, y, y + 7);

  return HAL_OK;
}

/**
 * @brief Draw as line between two given coordinates
 */
HAL_StatusTypeDef HAL_LS027B7_DrawLine(
  LS027B7_HandleTypeDef *hls027b7,
  uint8_t y
)
{
  /*! Turn on all the pixels in the given row */
  uint8_t i;
  for (i = LS027B7_MSG_COL_START; i < LS027B7_MSG_COL_END; i++) {
    hls027b7->DisplayData[y][i] = 0;
  }

  /*! Update screen with data */
  updateRows(hls027b7, y, y);

  return HAL_OK;
}

/**
 * @brief Draw a pixel given an x and y coordinate
 */
HAL_StatusTypeDef HAL_LS027B7_DrawPixel(
  LS027B7_HandleTypeDef *hls027b7,
  uint8_t x,
  uint8_t y
)
{
  /*! Turn on the desired pixel */
  hls027b7->DisplayData[y][(x / 8) + LS027B7_MSG_COL_START] &= LS027B7_COL_TO_BIT(x);

  /*! Update screen with data */
  updateRows(hls027b7, y, y);

  return HAL_OK;
}

/**
 * @brief Set all pixels to off
 */
HAL_StatusTypeDef HAL_LS027B7_ClearDisplay(
LS027B7_HandleTypeDef *hls027b7
)
{
  HAL_GPIO_WritePin(hls027b7->CSPort, hls027b7->CSPin, GPIO_PIN_SET);
  HAL_SPI_Transmit(hls027b7->hspi, (uint8_t*)&clearMsg, LS027B7_MSG_HEADER_SIZE, LS027B7_MSG_TIMEOUT);
  HAL_GPIO_WritePin(hls027b7->CSPort, hls027b7->CSPin, GPIO_PIN_RESET);

  return HAL_OK;
}

/**
 * @brief Reverse the bit order given a byte
 */
static uint8_t reverseBits(
  uint8_t byte
)
{
  byte = (byte & 0xF0) >> 4 | (byte & 0x0F) << 4; /*! Swap nibbles */
  byte = (byte & 0xCC) >> 2 | (byte & 0x33) << 2; /*! Swap pairs */
  byte = (byte & 0xAA) >> 1 | (byte & 0x55) << 1; /*! Swap neighboring bits */

  return byte;
}

/**
 * @brief Update given range of rows on screen
 */
static void updateRows(
  LS027B7_HandleTypeDef *hls027b7,
  uint8_t y1,
  uint8_t y2
)
{
  /*! Validate y is within resolution */
  if ((y1 <= y2) && (y2 < LS027B7_HEIGHT)) {
    /*! Toggle CS to high */
    HAL_GPIO_WritePin(hls027b7->CSPort, hls027b7->CSPin, GPIO_PIN_SET);

    /*! Transfer data */
    uint8_t row;
    for (row = y1; row <= y2; row++) {

      HAL_SPI_Transmit(hls027b7->hspi, 
        (uint8_t*)&hls027b7->DisplayData[row][LS027B7_MSG_CMD],
        LS027B7_MSG_SIZE, LS027B7_MSG_TIMEOUT);
    }

    HAL_SPI_Transmit(hls027b7->hspi,
      (uint8_t*)&spareBytes[0],
      2, LS027B7_MSG_TIMEOUT);

    /*! Toggle CS to low */
    HAL_GPIO_WritePin(hls027b7->CSPort, hls027b7->CSPin, GPIO_PIN_RESET);
  }
}
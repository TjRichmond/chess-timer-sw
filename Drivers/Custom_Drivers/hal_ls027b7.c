/**
 * @file    hal_ls027b7.c
 * @brief   Module for Sharp 2.7" 1-bit LCD display
 */

  #include "hal_ls027b7.h"

  static uint8_t reverseBits(uint8_t byte);

  /*! Macro to convert column number to bit position */
  #define LS027B7_COL_TO_BIT(col) ~(1 << (col % 8))

  const uint8_t displayMsg[2] = {DISPLAY_MODE, LS027B7_DUMMY_DATA};
  const uint8_t clearMsg[2] = {CLEAR_MODE, LS027B7_DUMMY_DATA};
  const uint8_t spareBytes[2] = {LS027B7_DUMMY_DATA, LS027B7_DUMMY_DATA};


  HAL_StatusTypeDef HAL_LS027B7_Init(
    LS027B7_HandleTypeDef *hls027b7
  )
  {
    uint8_t i,j;

    for (j=0;j<240;j++){
      for (i=LS027B7_DATA_OFFSET;i<52;i++) {
        /*! Initialize all pixels in row to off */
        hls027b7->DisplayData[j][i] = 0xFF;
      }

      /*! Initialize dummy bytes */
      hls027b7->DisplayData[j][0] = LS027B7_UPDATE_MODE;
      hls027b7->DisplayData[j][1] = reverseBits(j);
      hls027b7->DisplayData[j][52] = LS027B7_DUMMY_DATA;
      hls027b7->DisplayData[j][53] = LS027B7_DUMMY_DATA;
    }

    return HAL_OK;
  } 

  HAL_StatusTypeDef HAL_LS027B7_DrawLine(
    LS027B7_HandleTypeDef *hls027b7,
    uint8_t row
  )
  {
    /*! Turn on all the pixels in the given row */
    uint8_t i;
    for (i=LS027B7_DATA_OFFSET; i<52; i++) {
      hls027b7->DisplayData[row][i] = 0;
    }

    /*! Toggle CS to high */
    HAL_GPIO_WritePin(hls027b7->CSPort, hls027b7->CSPin, GPIO_PIN_SET);

    /*! Transfer data */
    HAL_SPI_Transmit(hls027b7->hspi, (uint8_t*)&hls027b7->DisplayData[row][0], 54, 100);

    /*! Toggle CS to low */
    HAL_GPIO_WritePin(hls027b7->CSPort, hls027b7->CSPin, GPIO_PIN_RESET);

    return HAL_OK;
  }

  HAL_StatusTypeDef HAL_LS027B7_DrawPixel(
    LS027B7_HandleTypeDef *hls027b7,
    uint8_t row,
    uint8_t col
  )
  {
    /*! Turn on the desired pixel */
    hls027b7->DisplayData[row][(col/8) + LS027B7_DATA_OFFSET] &= LS027B7_COL_TO_BIT(col);

    /*! Toggle CS to high */
    HAL_GPIO_WritePin(hls027b7->CSPort, hls027b7->CSPin, GPIO_PIN_SET);

    /*! Transfer data */
    HAL_SPI_Transmit(hls027b7->hspi, (uint8_t*)&hls027b7->DisplayData[row][0], 54, 100);

    /*! Toggle CS to low */
    HAL_GPIO_WritePin(hls027b7->CSPort, hls027b7->CSPin, GPIO_PIN_RESET);

    return HAL_OK;
  }

  HAL_StatusTypeDef HAL_LS027B7_ClearDisplay(
  LS027B7_HandleTypeDef *hls027b7
  )
  {
    HAL_GPIO_WritePin(hls027b7->CSPort, hls027b7->CSPin, GPIO_PIN_SET);
    HAL_SPI_Transmit(hls027b7->hspi, (uint8_t*)&clearMsg, 2, 100);
    HAL_GPIO_WritePin(hls027b7->CSPort, hls027b7->CSPin, GPIO_PIN_RESET);

    return HAL_OK;
  }


static uint8_t reverseBits(uint8_t byte) {
  byte = (byte & 0xF0) >> 4 | (byte & 0x0F) << 4; /*! Swap nibbles */
  byte = (byte & 0xCC) >> 2 | (byte & 0x33) << 2; /*! Swap pairs */
  byte = (byte & 0xAA) >> 1 | (byte & 0x55) << 1; /*! Swap neighboring bits */

  return byte;
}
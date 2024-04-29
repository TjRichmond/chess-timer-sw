#include "max7219.h"

MAX7219_HandleTypeDef hmax7219;

void MX_MAX7219_Init(SPI_HandleTypeDef *hspi)
{
  hmax7219.Init.CSPort = MAX1719_CS_GPIO_Port;
  hmax7219.Init.CSPin = MAX1719_CS_Pin;
  hmax7219.Init.hspi  = hspi;
  if (HAL_MAX7219_Init(&hmax7219) != HAL_OK)
  {
    Error_Handler();
  }
}
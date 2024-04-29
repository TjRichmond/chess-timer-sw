/**
 * @file    stm32u0xx_hal_max7219.c
 * @brief   Module for max7219 8-digit LED Display Driver
 */

#include "stm32u0xx_hal_max7219.h"

HAL_StatusTypeDef HAL_MAX7219_Init(
  MAX7219_HandleTypeDef *hmax7219)
{
  /* Check the MAXC7219 handle allocation */
  if (hmax7219 == NULL)
  {
    return HAL_ERROR;
  }

  /* Check the parameters */
  assert_param(IS_GPIO_ALL_INSTANCE(hmax7219->Init.CSPort));
  assert_param(IS_GPIO_PIN(hmax7219->Init.CSPin));

  return HAL_OK;
}

/**
 * @brief   Send a single message to max7219
 * @param   hmax7219 pointer to a MAX7219_HandleTypeDef structure that contains
 *                    the configuration information for MAX7219 IC.
 * @param   Addr register address on MAX7219 to send data to
 * @param   Cmd data to send to register
 * @retval  HAL status
*/
HAL_StatusTypeDef HAL_MAX7219_SendMessage(
    MAX7219_HandleTypeDef *hmax7219,
    HAL_MAX7219_AddressTypeDef Addr,
    HAL_MAX7219_CommandTypeDef Cmd)
{
  uint16_t message = ((uint16_t)Addr << 8) | (uint16_t)Cmd;

  HAL_GPIO_WritePin(hmax7219->Init.CSPort, hmax7219->Init.CSPin, GPIO_PIN_RESET);
  HAL_SPI_Transmit(hmax7219->Init.hspi, (uint8_t *)&message, 1, 100);
  HAL_GPIO_WritePin(hmax7219->Init.CSPort, hmax7219->Init.CSPin, GPIO_PIN_SET);

  return HAL_OK;
}
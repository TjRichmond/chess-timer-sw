/**
 * @file    stm32u0xx_hal_max7219.c
 * @brief   Module for max7219 8-digit LED Display Driver
 */

#include "hal_max7219.h"

HAL_StatusTypeDef HAL_MAX7219_Init(
    MAX7219_HandleTypeDef *hmax7219)
{
  /* Check the MAXC7219 handle allocation */
  if (hmax7219 == NULL)
  {
    return HAL_ERROR;
  }

  /* Check the parameters */
  assert_param(IS_GPIO_ALL_INSTANCE(hmax7219->CSPort));
  assert_param(IS_GPIO_PIN(hmax7219->CSPin));

  /*! Disable Test Mode */
  HAL_MAX7219_SendMessage(hmax7219,
                          MAX7219_ADDRESS_DISPLAY_TEST,
                          MAX7219_COMMAND_TEST_DISABLE);

  /*! Ensure normal operation mode */
  HAL_MAX7219_SendMessage(hmax7219,
                          MAX7219_ADDRESS_SHUTDOWN,
                          MAX7219_COMMAND_NORMAL_OPERATION);

  /*! Decome mode 0-7 */
  HAL_MAX7219_SendMessage(hmax7219,
                          MAX7219_ADDRESS_DECODE_MODE,
                          MAX7219_COMMAND_CODE_B_DIGIT_7_0);

  /*! Scan mode 0-7 */
  HAL_MAX7219_SendMessage(hmax7219,
                          MAX7219_ADDRESS_SCAN_LIMIT,
                          MAX7219_COMMAND_SCAN_7_0);

  /*! Minimum brightness */
  HAL_MAX7219_SendMessage(hmax7219,
                          MAX7219_ADDRESS_INTENSITY,
                          MAX7219_COMMAND_INTENSITY_MIN);

  /*! Initialize display to be blank */
  uint8_t i;
  for (i = 0; i < 8; i++)
  {
    hmax7219->Display[i] = MAX7219_CODE_B_BLANK;
    HAL_MAX7219_SendMessage(hmax7219,
                            i + 1,
                            MAX7219_CODE_B_DP_BLANK);
  }

  return HAL_OK;
}

/**
 * @brief   Send a single message to max7219
 * @param   hmax7219 pointer to a MAX7219_HandleTypeDef structure that contains
 *                   the configuration information for MAX7219 IC
 * @param   Addr register address on MAX7219 to send data to
 * @param   Cmd data to send to register
 * @returns  HAL status
 */
HAL_StatusTypeDef HAL_MAX7219_SendMessage(
    MAX7219_HandleTypeDef *hmax7219,
    MAX7219_AddressTypeDef Addr,
    MAX7219_CommandTypeDef Cmd)
{
  /*! Pack message */
  uint16_t message = ((uint16_t)Addr << 8) | (uint16_t)Cmd;

  /*! Transmit message */
  HAL_GPIO_WritePin(hmax7219->CSPort, hmax7219->CSPin, GPIO_PIN_RESET);
  HAL_SPI_Transmit(hmax7219->hspi, (uint8_t *)&message, 1, 100);
  HAL_GPIO_WritePin(hmax7219->CSPort, hmax7219->CSPin, GPIO_PIN_SET);

  return HAL_OK;
}

/**
 * @brief   Write a symbol to a specific digit
 * @param   hmax72199 pointer to a MAX7219_HandleTypeDef structure that contains
 *                    the configuration information for MAX7219 IC
 * @param   Position  digit position in display
 * @param   Symbol    symbol to be written
 * @returns HAL status
 */
HAL_StatusTypeDef HAL_MAX7219_WriteDigit(
    MAX7219_HandleTypeDef *hmax7219,
    MAX7219_DigitPosTypeDef Position,
    MAX7219_CodeBTypeDef Symbol)
{
  /*! Update position's symbol */
  hmax7219->Display[Position] = Symbol;

  /*! Pack message */
  uint16_t message = ((uint16_t)Position + 1) << 8 | (uint16_t)Symbol;

  /*! Transmit message */
  HAL_GPIO_WritePin(hmax7219->CSPort, hmax7219->CSPin, GPIO_PIN_RESET);
  HAL_SPI_Transmit(hmax7219->hspi, (uint8_t *)&message, 1, 100);
  HAL_GPIO_WritePin(hmax7219->CSPort, hmax7219->CSPin, GPIO_PIN_SET);

  return HAL_OK;
}

/**
 * @brief   Update all digits on display
 * @param   hmax7219 pointer to a MAX7219_HandleTypeDef structure that contains
 *                   the configuration information for MAX7219 IC
 * @returns HAL status
 */
HAL_StatusTypeDef HAL_MAX7219_UpdateDisplay(
    MAX7219_HandleTypeDef *hmax7219)
{
  uint8_t i;
  for (i = 0; i < 8; i++)
  {
    HAL_MAX7219_SendMessage(hmax7219, i + 1, hmax7219->Display[i]);
  }

  return HAL_OK;
}

/**
 * @brief   Takes an integer and converts to BCD
 * @param   hmax7219  pointer to MAX7219 configuration struct
 * @param   int_value integer value to be displayed
 * @returns HAL status
 */
HAL_StatusTypeDef HAL_MAX7219_IntToBCD(
    MAX7219_HandleTypeDef *hmax7219,
    uint32_t int_value)
{
  /*! Get remainder of int_value/10 and divide int_value/10 to shift digit*/
  uint8_t i;
  for (i = 0; i < 8; i++)
  {
    hmax7219->Display[i] = int_value % 10;
    int_value /= 10;
  }

  return HAL_OK;
}

/**
 * @brief   Takes an integer and writes to display
 * @param   hmax7219  pointer to MAX7219 configuration struct
 * @param   int_value integer value to be displayed
 * @returns HAL status
 */
HAL_StatusTypeDef HAL_MAX7219_WriteInt(
    MAX7219_HandleTypeDef *hmax7219,
    uint32_t int_value)
{
  /*! Get remainder of int_value/10 and divide int_value/10 to shift digit*/
  uint8_t i;
  for (i = 0; i < 8; i++)
  {
    hmax7219->Display[i] = int_value % 10;
    int_value /= 10;
    HAL_MAX7219_SendMessage(hmax7219, i + 1, hmax7219->Display[i]);
  }

  return HAL_OK;
}
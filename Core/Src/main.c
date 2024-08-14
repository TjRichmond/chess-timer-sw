/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "spi.h"
#include "tim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "hal_max7219.h"
#include "hal_ls027b7.h"
#include "chess.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
ChessGame Game;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_SPI1_Init();
  MX_TIM6_Init();
  MX_TIM7_Init();
  /* USER CODE BEGIN 2 */
  // MAX7219_HandleTypeDef hmax7219;
  // hmax7219.hspi = &hspi1;
  // hmax7219.CSPort = MAX1719_CS_GPIO_Port;
  // hmax7219.CSPin = MAX1719_CS_Pin;
  // HAL_MAX7219_Init(&hmax7219);

  // HAL_TIM_Base_Start_IT(&htim6);

  // Game.GameState = NEW_GAME;
  // Game.MatchLength = LEN_10SEC;
  LS027B7_HandleTypeDef hls027b7;
  hls027b7.hspi = &hspi1;
  hls027b7.CSPort = MAX1719_CS_GPIO_Port;
  hls027b7.CSPin = MAX1719_CS_Pin;
  HAL_LS027B7_Init(&hls027b7);

  HAL_LS027B7_ClearDisplay(&hls027b7);
  HAL_LS027B7_DrawLine(&hls027b7, (uint8_t)120);
  HAL_LS027B7_DrawPixel(&hls027b7, (uint8_t)100, (uint8_t)200);
  HAL_LS027B7_DrawChar(&hls027b7, 24, 24);
  /* USER CODE END 2 */

  /* Initialize leds */
  BSP_LED_Init(LED_GREEN);

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    // GameLoop(&hmax7219, &Game);
    // HAL_LS027B7_DrawLine(&hls027b7, (uint8_t)69);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE2);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void HAL_GPIO_EXTI_Rising_Callback(uint16_t GPIO_Pin)
{
  if (GPIO_Pin == WHITE_Pin && Game.GameState == WHITE_TURN)
  {
    Game.GameState = BLACK_TURN;
  }
  else if (GPIO_Pin == BLACK_Pin && Game.GameState == BLACK_TURN)
  {
    Game.GameState = WHITE_TURN;
  }
  else if (GPIO_Pin == NEW_GAME_Pin)
  {
    switch (Game.GameState)
    {
    case NEW_GAME:
      Game.GameState = WHITE_TURN;
      break;
    default:
      Game.GameState = NEW_GAME;
      break;
    }
  }
  else if (GPIO_Pin == MODE_SELECT_Pin)
  {
    if(Game.MatchLength == LEN_30MIN)
    {
      Game.MatchLength = LEN_10SEC;
    }
    else
    {
      Game.MatchLength++;
    }
  }
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  if (htim->Instance == TIM6)
  {
    if (Game.GameState == WHITE_TURN)
    {
      if (Game.WhiteTick10ms % 10000 == 0)
      {
        Game.WhiteTick10ms -= 4000;
      }
      else
      {
        Game.WhiteTick10ms--;
      }
    }
    else if (Game.GameState == BLACK_TURN)
    {
      if (Game.BlackTick10ms % 10000 == 0)
      {
        Game.BlackTick10ms -= 4000;
      }
      else
      {
        Game.BlackTick10ms--;
      }
    }
    else if (Game.GameState == GAME_OVER)
    {
      Game.WinnerTick10ms++;
      if (Game.WinnerTick10ms > 99)
      {
        Game.WinnerTick10ms = 0;
        Game.GameOverBlink = !Game.GameOverBlink;
      }
    }
  }
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

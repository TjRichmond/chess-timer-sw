/**
 * @file    chess.c
 * @brief   Module for chess game logic
 */

#include "chess.h"

/**
 * @brief   brief
 * @param   argument
 * @returns return value
 */
void GameLoop(MAX7219_HandleTypeDef *hmax7219, ChessGame *Game)
{
  if (Game->GameState == WHITE_TURN)
  {
    if (Game->WhiteTick10ms % 100 == 0)
    {
      HAL_MAX7219_WriteInt(hmax7219, ((Game->WhiteTick10ms / 100) * 10000) + Game->BlackTick10ms / 100);
    }
  }
  else
  {
    if (Game->BlackTick10ms % 100 == 0)
    {
      HAL_MAX7219_WriteInt(hmax7219, ((Game->WhiteTick10ms / 100) * 10000) + Game->BlackTick10ms / 100);
    }
  }
}

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
  /*! State machine determing stage of game */
  switch (Game->GameState)
  {
  
  /*! Reset tick counters and await button start */
  case NEW_GAME:
    Game->WhiteTick10ms = 10000;
    Game->BlackTick10ms = 10000;

  /*! Display flashing numbers of winner */
  case GAME_OVER:
    break;
  
  /*! Update display to reflect counters current value */
  case WHITE_TURN:
  case BLACK_TURN:
    if (Game->WhiteTick10ms > 0 && Game->BlackTick10ms > 0)
    {
      HAL_MAX7219_WriteInt(hmax7219, ((Game->WhiteTick10ms / 100) * 10000) + Game->BlackTick10ms / 100);
    }
    else
    {
      Game->GameState = GAME_OVER;
    }
    break;

  default:
    break;
  }
}

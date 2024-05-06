/**
 * @file    chess.c
 * @brief   Module for chess game logic
 */

#include "chess.h"

/**
 * @brief   Game logic state machine
 * @param   hmax7219 pointer to display struct
 * @param   Game pointer to game logic info
 */
void GameLoop(MAX7219_HandleTypeDef *hmax7219, ChessGame *Game)
{
  /*! State machine determing stage of game */
  switch (Game->GameState)
  {

  /*! Reset tick counters and await button start */
  case NEW_GAME:
    switch (Game->MatchLength)
    {
    case LEN_10SEC:
      Game->WhiteTick10ms = 1000;
      Game->BlackTick10ms = 1000;
      Game->TotalTime = 100010;
      HAL_MAX7219_WriteInt(hmax7219, Game->TotalTime);
      break;
    case LEN_1MIN:
      Game->WhiteTick10ms = 10000;
      Game->BlackTick10ms = 10000;
      Game->TotalTime = 1000100;
      HAL_MAX7219_WriteInt(hmax7219, Game->TotalTime);
      break;
    case LEN_3MIN:
      Game->WhiteTick10ms = 30000;
      Game->BlackTick10ms = 30000;
      Game->TotalTime = 3000300;
      HAL_MAX7219_WriteInt(hmax7219, Game->TotalTime);
      break;
    case LEN_5MIN:
      Game->WhiteTick10ms = 50000;
      Game->BlackTick10ms = 50000;
      Game->TotalTime = 5000500;
      HAL_MAX7219_WriteInt(hmax7219, Game->TotalTime);
      break;
    case LEN_10MIN:
      Game->WhiteTick10ms = 100000;
      Game->BlackTick10ms = 100000;
      Game->TotalTime = 10001000;
      HAL_MAX7219_WriteInt(hmax7219, Game->TotalTime);
      break;
    case LEN_30MIN:
      Game->WhiteTick10ms = 300000;
      Game->BlackTick10ms = 300000;
      Game->TotalTime = 30003000;
      HAL_MAX7219_WriteInt(hmax7219, Game->TotalTime);
      break;
    default:
      break;
    }
    Game->WinnerTick10ms = 0;
    Game->Winner = NO_WIN;
    break;

  /*! Display flashing numbers of winner */
  case GAME_OVER:
    if (Game->GameOverBlink == BLINK_ON)
    {
      if (Game->Winner == BLACK_WIN)
      {
        hmax7219->Display[0] = (Game->BlackTick10ms / 100) % 10;
        hmax7219->Display[1] = (Game->BlackTick10ms / 1000) % 10;
        hmax7219->Display[2] = (Game->BlackTick10ms / 10000) % 10;
        hmax7219->Display[3] = (Game->BlackTick10ms / 100000) % 10;
        hmax7219->Display[4] = MAX7219_CODE_B_DASH;
        hmax7219->Display[5] = MAX7219_CODE_B_DASH;
        hmax7219->Display[6] = MAX7219_CODE_B_DASH;
        hmax7219->Display[7] = MAX7219_CODE_B_DASH;
        HAL_MAX7219_UpdateDisplay(hmax7219);
      }
      else if (Game->Winner == WHITE_WIN)
      {
        hmax7219->Display[0] = MAX7219_CODE_B_DASH;
        hmax7219->Display[1] = MAX7219_CODE_B_DASH;
        hmax7219->Display[2] = MAX7219_CODE_B_DASH;
        hmax7219->Display[3] = MAX7219_CODE_B_DASH;
        hmax7219->Display[4] = (Game->WhiteTick10ms / 100) % 10;
        hmax7219->Display[5] = (Game->WhiteTick10ms / 1000) % 10;
        hmax7219->Display[6] = (Game->WhiteTick10ms / 10000) % 10;
        hmax7219->Display[7] = (Game->WhiteTick10ms / 100000) % 10;
        HAL_MAX7219_UpdateDisplay(hmax7219);
      }
    }
    else
    {
      HAL_MAX7219_WriteInt(hmax7219, Game->TotalTime);
    }
    break;

  /*! Update display to reflect counters current value */
  case WHITE_TURN:
  case BLACK_TURN:
    if (Game->WhiteTick10ms > 0 && Game->BlackTick10ms > 0)
    {
      /*! Update display */
      Game->TotalTime = (Game->WhiteTick10ms / 100) * 10000 + (Game->BlackTick10ms / 100);
      HAL_MAX7219_WriteInt(hmax7219, Game->TotalTime);
    }
    else
    {
      /*! Change current game state to game over since a timer ran out */
      if (Game->WhiteTick10ms < 1)
      {
        Game->Winner = BLACK_WIN;
      }
      else if (Game->BlackTick10ms < 1)
      {
        Game->Winner = WHITE_WIN;
      }
      Game->GameState = GAME_OVER;
    }
    break;

  default:
    break;
  }
}

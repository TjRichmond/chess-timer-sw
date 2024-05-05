/**
 * @file    chess.h
 * @brief   Header to contain chess data types
 */
#ifndef _CHESS_H
#define _CHESS_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "hal_max7219.h"

  typedef enum
  {
    WHITE_TURN,
    BLACK_TURN,
    NEW_GAME,
    GAME_OVER
  } GameStateTypeDef;

  typedef struct _ChessGame
  {
    GameStateTypeDef GameState;
    uint32_t WhiteTick10ms;
    uint32_t BlackTick10ms;
  } ChessGame;

  void GameLoop(MAX7219_HandleTypeDef *hmax7219, ChessGame *Game);

  

#ifdef __cplusplus
}
#endif

#endif
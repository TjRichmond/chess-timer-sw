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
    NEW_GAME,
    START_GAME,
    WHITE_TURN,
    BLACK_TURN,
    GAME_OVER
  } GameStateTypeDef;

  typedef enum
  {
    NO_WIN,
    WHITE_WIN,
    BLACK_WIN
  } WinnerTypeDef;

  typedef enum
  {
    LEN_10SEC,
    LEN_1MIN,
    LEN_3MIN,
    LEN_5MIN,
    LEN_10MIN,
    LEN_30MIN
  } MatchLengthTypeDef;

  typedef enum
  {
    BLINK_OFF,
    BLINK_ON
  } GameOverTypeDef;

  typedef struct _ChessGame
  {
    GameStateTypeDef GameState;
    uint32_t WhiteTick10ms;
    uint32_t BlackTick10ms;
    uint8_t WinnerTick10ms;
    uint32_t TotalTime;
    GameOverTypeDef GameOverBlink;
    WinnerTypeDef Winner;
    MatchLengthTypeDef MatchLength;
  } ChessGame;

  void GameLoop(MAX7219_HandleTypeDef *hmax7219, ChessGame *Game);

#ifdef __cplusplus
}
#endif

#endif
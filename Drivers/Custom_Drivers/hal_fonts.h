/**
 * @file    hal_fonts.h
 * @brief   Module for letters and digit fonts
 */
#ifndef _HAL_FONTS_H
#define _HAL_FONTS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32u0xx_hal.h"

uint8_t cp437[256][8] = {
    // Character 0 (NULL)
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    // Character 1 (SOH)
    {0x7E, 0x81, 0xA5, 0x81, 0xA5, 0x81, 0x7E, 0x00},
    // Character 2 (STX)
    {0x7E, 0xFF, 0xDB, 0xFF, 0xDB, 0xFF, 0x7E, 0x00},
    // Character 3 (ETX)
    {0x6C, 0xFE, 0xFE, 0xFE, 0x7C, 0x38, 0x10, 0x00},
    // Character 4 (EOT)
    {0x10, 0x38, 0x7C, 0xFE, 0x7C, 0x38, 0x10, 0x00},
    // Character 5 (ENQ)
    {0x38, 0x7C, 0x38, 0xFE, 0xFE, 0xD6, 0x10, 0x00},
    // Character 6 (ACK)
    {0x10, 0x38, 0x7C, 0xFE, 0x38, 0x38, 0x7C, 0x00},
    // Character 7 (BEL)
    {0x38, 0x7C, 0x7C, 0x7C, 0x7C, 0x7C, 0x38, 0x00},
    // Character 8 (BS)
    {0x38, 0x7C, 0x7C, 0x7C, 0x7C, 0x38, 0x00, 0x7C},
    // Character 9 (HT)
    {0x38, 0x7C, 0x7C, 0x7C, 0x7C, 0x38, 0x7C, 0x7C},
    // Character 10 (LF)
    {0x18, 0x3C, 0x7E, 0x18, 0x18, 0x7E, 0x3C, 0x18},
    // Character 11 (VT)
    {0x66, 0x66, 0x66, 0x66, 0x66, 0x00, 0x66, 0x00},
    // Character 12 (FF)
    {0xFE, 0xC6, 0xBA, 0xAA, 0xAA, 0xBA, 0xC6, 0xFE},
    // Character 13 (CR)
    {0x7E, 0x66, 0x76, 0x6E, 0x7E, 0x00, 0x7E, 0x00},
    // Character 14 (SO)
    {0x7E, 0x66, 0x6E, 0x76, 0x7E, 0x00, 0x7E, 0x00},
    // Character 15 (SI)
    {0x3E, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30},
    // Character 16 (DLE)
    {0x3E, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30},
    // Character 17 (DC1)
    {0x3E, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30},
    // Character 18 (DC2)
    {0x3E, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30},
    // Character 19 (DC3)
    {0x3E, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30},
    // Character 20 (DC4)
    {0x3E, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30},
    // Character 21 (NAK)
    {0x3E, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30},
    // Character 22 (SYN)
    {0x3E, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30},
    // Character 23 (ETB)
    {0x3E, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30},
    // Character 24 (CAN)
    {0x3E, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30},
    // Character 25 (EM)
    {0x3E, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30},
    // Character 26 (SUB)
    {0x3E, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30},
    // Character 27 (ESC)
    {0x3E, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30},
    // Character 28 (FS)
    {0x3E, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30},
    // Character 29 (GS)
    {0x3E, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30},
    // Character 30 (RS)
    {0x3E, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30},
    // Character 31 (US)
    {0x3E, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30},
    // Character 32 (Space)
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    // Character 33 (!)
    {0x30, 0x78, 0x78, 0x78, 0x30, 0x30, 0x00, 0x30},
    // Character 34 (")
    {0x6C, 0x6C, 0x6C, 0x24, 0x00, 0x00, 0x00, 0x00},
    // Character 35 (#)
    {0x6C, 0x6C, 0xFE, 0x6C, 0x6C, 0xFE, 0x6C, 0x6C},
    // Character 36 ($)
    {0x30, 0x7C, 0xC0, 0x78, 0x0C, 0xF8, 0x30, 0x30},
    // Character 37 (%)
    {0x00, 0xC6, 0xCC, 0x18, 0x30, 0x66, 0xC6, 0x00},
    // Character 38 (&)
    {0x38, 0x6C, 0x38, 0x70, 0xDE, 0xCC, 0x76, 0x00},
    // Character 39 (')
    {0x30, 0x30, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00},
    // Character 40 (()
    {0x0C, 0x18, 0x30, 0x30, 0x30, 0x18, 0x0C, 0x00},
    // Character 41 ())
    {0x30, 0x18, 0x0C, 0x0C, 0x0C, 0x18, 0x30, 0x00},
    // Character 42 (*)
    {0x00, 0x66, 0x3C, 0xFF, 0x3C, 0x66, 0x00, 0x00},
    // Character 43 (+)
    {0x00, 0x18, 0x18, 0x7E, 0x18, 0x18, 0x00, 0x00},
    // Character 44 (,)
    {0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x60, 0x00},
    // Character 45 (-)
    {0x00, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x00, 0x00},
    // Character 46 (.)
    {0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00, 0x00},
    // Character 47 (/)
    {0x06, 0x0C, 0x18, 0x30, 0x60, 0xC0, 0x80, 0x00},
    // Character 48 (0)
    {0x7C, 0xC6, 0xCE, 0xD6, 0xE6, 0xC6, 0x7C, 0x00},
    // Character 49 (1)
    {0x30, 0x70, 0x30, 0x30, 0x30, 0x30, 0x78, 0x00},
    // Character 50 (2)
    {0x7C, 0xC6, 0x06, 0x1C, 0x70, 0xC0, 0xFE, 0x00},
    // Character 51 (3)
    {0x7C, 0xC6, 0x06, 0x3C, 0x06, 0xC6, 0x7C, 0x00},
    // Character 52 (4)
    {0x1C, 0x3C, 0x6C, 0xCC, 0xFE, 0x0C, 0x0C, 0x00},
    // Character 53 (5)
    {0xFE, 0xC0, 0xFC, 0x06, 0x06, 0xC6, 0x7C, 0x00},
    // Character 54 (6)
    {0x3C, 0x60, 0xC0, 0xFC, 0xC6, 0xC6, 0x7C, 0x00},
    // Character 55 (7)
    {0xFE, 0xC6, 0x0C, 0x18, 0x30, 0x30, 0x30, 0x00},
    // Character 56 (8)
    {0x7C, 0xC6, 0xC6, 0x7C, 0xC6, 0xC6, 0x7C, 0x00},
    // Character 57 (9)
    {0x7C, 0xC6, 0xC6, 0x7E, 0x06, 0x0C, 0x78, 0x00},
    // Character 58 (:)
    {0x00, 0x30, 0x30, 0x00, 0x00, 0x30, 0x30, 0x00},
    // Character 59 (;)
    {0x00, 0x30, 0x30, 0x00, 0x30, 0x30, 0x60, 0x00},
    // Character 60 (<)
    {0x0C, 0x18, 0x30, 0x60, 0x30, 0x18, 0x0C, 0x00},
    // Character 61 (=)
    {0x00, 0x00, 0x7E, 0x00, 0x7E, 0x00, 0x00, 0x00},
    // Character 62 (>)
    {0x30, 0x18, 0x0C, 0x06, 0x0C, 0x18, 0x30, 0x00},
    // Character 63 (?)
    {0x7C, 0xC6, 0x0E, 0x1C, 0x30, 0x00, 0x30, 0x00},
    // Character 64 (@)
    {0x7C, 0xC6, 0xDE, 0xDE, 0xDE, 0xC0, 0x7E, 0x00},
    // Character 65 (A)
    {0x10, 0x38, 0x6C, 0xC6, 0xFE, 0xC6, 0xC6, 0x00},
    // Character 66 (B)
    {0xFC, 0x66, 0x66, 0x7C, 0x66, 0x66, 0xFC, 0x00},
    // Character 67 (C)
    {0x3C, 0x66, 0xC0, 0xC0, 0xC0, 0x66, 0x3C, 0x00},
    // Character 68 (D)
    {0xF8, 0x6C, 0x66, 0x66, 0x66, 0x6C, 0xF8, 0x00},
    // Character 69 (E)
    {0xFE, 0x62, 0x68, 0x78, 0x68, 0x62, 0xFE, 0x00},
    // Character 70 (F)
    {0xFE, 0x62, 0x68, 0x78, 0x68, 0x60, 0xF0, 0x00},
    // Character 71 (G)
    {0x3C, 0x66, 0xC0, 0xC0, 0xCE, 0x66, 0x3A, 0x00},
    // Character 72 (H)
    {0xC6, 0xC6, 0xC6, 0xFE, 0xC6, 0xC6, 0xC6, 0x00},
    // Character 73 (I)
    {0x7E, 0x18, 0x18, 0x18, 0x18, 0x18, 0x7E, 0x00},
    // Character 74 (J)
    {0x1E, 0x0C, 0x0C, 0x0C, 0xCC, 0xCC, 0x78, 0x00},
    // Character 75 (K)
    {0xE6, 0x66, 0x6C, 0x78, 0x6C, 0x66, 0xE6, 0x00},
    // Character 76 (L)
    {0xF0, 0x60, 0x60, 0x60, 0x62, 0x66, 0xFE, 0x00},
    // Character 77 (M)
    {0xC6, 0xEE, 0xFE, 0xFE, 0xD6, 0xC6, 0xC6, 0x00},
    // Character 78 (N)
    {0xC6, 0xE6, 0xF6, 0xFE, 0xDE, 0xCE, 0xC6, 0x00},
    // Character 79 (O)
    {0x38, 0x6C, 0xC6, 0xC6, 0xC6, 0x6C, 0x38, 0x00},
    // Character 80 (P)
    {0xFC, 0x66, 0x66, 0x7C, 0x60, 0x60, 0xF0, 0x00},
    // Character 81 (Q)
    {0x78, 0xCC, 0xCC, 0xCC, 0xCC, 0xD8, 0x7C, 0x06},
    // Character 82 (R)
    {0xFC, 0x66, 0x66, 0x7C, 0x6C, 0x66, 0xE6, 0x00},
    // Character 83 (S)
    {0x7C, 0xC6, 0x60, 0x38, 0x0C, 0xC6, 0x7C, 0x00},
    // Character 84 (T)
    {0xFF, 0xDB, 0x18, 0x18, 0x18, 0x18, 0x3C, 0x00},
    // Character 85 (U)
    {0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0x7C, 0x00},
    // Character 86 (V)
    {0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0x6C, 0x38, 0x00},
    // Character 87 (W)
    {0xC6, 0xC6, 0xC6, 0xD6, 0xFE, 0xFE, 0x6C, 0x00},
    // Character 88 (X)
    {0xC6, 0xC6, 0x6C, 0x38, 0x38, 0x6C, 0xC6, 0x00},
    // Character 89 (Y)
    {0xC6, 0xC6, 0xC6, 0x7C, 0x18, 0x18, 0x3C, 0x00},
    // Character 90 (Z)
    {0xFE, 0xC6, 0x8C, 0x18, 0x32, 0x66, 0xFE, 0x00},
    // Character 91 ([)
    {0x78, 0x60, 0x60, 0x60, 0x60, 0x60, 0x78, 0x00},
    // Character 92 (\)
    {0xC0, 0x60, 0x30, 0x18, 0x0C, 0x06, 0x02, 0x00},
    // Character 93 (])
    {0x78, 0x18, 0x18, 0x18, 0x18, 0x18, 0x78, 0x00},
    // Character 94 (^)
    {0x10, 0x38, 0x6C, 0xC6, 0x00, 0x00, 0x00, 0x00},
    // Character 95 (_)
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00},
    // Character 96 (`)
    {0x30, 0x30, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00},
    // Character 97 (a)
    {0x00, 0x00, 0x7C, 0x06, 0x7E, 0xC6, 0x7E, 0x00},
    // Character 98 (b)
    {0xE0, 0x60, 0x7C, 0x66, 0x66, 0x66, 0xDC, 0x00},
    // Character 99 (c)
    {0x00, 0x00, 0x7C, 0xC6, 0xC0, 0xC6, 0x7C, 0x00},
    // Character 100 (d)
    {0x1C, 0x0C, 0x7C, 0xCC, 0xCC, 0xCC, 0x76, 0x00},
    // Character 101 (e)
    {0x00, 0x00, 0x7C, 0xC6, 0xFE, 0xC0, 0x7C, 0x00},
    // Character 102 (f)
    {0x1E, 0x30, 0x30, 0x78, 0x30, 0x30, 0x78, 0x00},
    // Character 103 (g)
    {0x00, 0x00, 0x76, 0xCC, 0xCC, 0x7C, 0x0C, 0xF8},
    // Character 104 (h)
    {0xE0, 0x60, 0x6C, 0x76, 0x66, 0x66, 0xE6, 0x00},
    // Character 105 (i)
    {0x18, 0x00, 0x78, 0x18, 0x18, 0x18, 0x7E, 0x00},
    // Character 106 (j)
    {0x0C, 0x00, 0x0C, 0x0C, 0x0C, 0xCC, 0xCC, 0x78},
    // Character 107 (k)
    {0xE0, 0x60, 0x66, 0x6C, 0x78, 0x6C, 0xE6, 0x00},
    // Character 108 (l)
    {0x78, 0x18, 0x18, 0x18, 0x18, 0x18, 0x7E, 0x00},
    // Character 109 (m)
    {0x00, 0x00, 0xFC, 0xFE, 0xD6, 0xD6, 0xD6, 0x00},
    // Character 110 (n)
    {0x00, 0x00, 0xDC, 0x66, 0x66, 0x66, 0x66, 0x00},
    // Character 111 (o)
    {0x00, 0x00, 0x7C, 0xC6, 0xC6, 0xC6, 0x7C, 0x00},
    // Character 112 (p)
    {0x00, 0x00, 0xDC, 0x66, 0x66, 0x7C, 0x60, 0xF0},
    // Character 113 (q)
    {0x00, 0x00, 0x76, 0xCC, 0xCC, 0x7C, 0x0C, 0x1E},
    // Character 114 (r)
    {0x00, 0x00, 0xDC, 0x76, 0x66, 0x60, 0xF0, 0x00},
    // Character 115 (s)
    {0x00, 0x00, 0x7E, 0xC0, 0x7C, 0x06, 0xFC, 0x00},
    // Character 116 (t)
    {0x30, 0x30, 0xFC, 0x30, 0x30, 0x30, 0x1E, 0x00},
    // Character 117 (u)
    {0x00, 0x00, 0xCC, 0xCC, 0xCC, 0xCC, 0x76, 0x00},
    // Character 118 (v)
    {0x00, 0x00, 0xC6, 0xC6, 0xC6, 0x6C, 0x38, 0x00},
    // Character 119 (w)
    {0x00, 0x00, 0xC6, 0xD6, 0xD6, 0xFE, 0x6C, 0x00},
    // Character 120 (x)
    {0x00, 0x00, 0xC6, 0x6C, 0x38, 0x6C, 0xC6, 0x00},
    // Character 121 (y)
    {0x00, 0x00, 0xC6, 0xC6, 0xC6, 0x7E, 0x06, 0xFC},
    // Character 122 (z)
    {0x00, 0x00, 0xFE, 0x8C, 0x18, 0x32, 0xFE, 0x00},
    // Character 123 ({)
    {0x1C, 0x30, 0x30, 0xE0, 0x30, 0x30, 0x1C, 0x00},
    // Character 124 (|)
    {0x18, 0x18, 0x18, 0x00, 0x18, 0x18, 0x18, 0x00},
    // Character 125 (})
    {0xE0, 0x30, 0x30, 0x1C, 0x30, 0x30, 0xE0, 0x00},
    // Character 126 (~)
    {0x76, 0xDC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    // Character 127 (DEL)
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    // Character 128 (Ç)
    {0x7C, 0xC6, 0xC0, 0xC0, 0xC6, 0x7C, 0x18, 0x70},
    // Character 129 (ü)
    {0xCC, 0x00, 0xCC, 0xCC, 0xCC, 0xCC, 0x76, 0x00},
    // Character 130 (é)
    {0x1C, 0x0C, 0x7C, 0xCC, 0xFC, 0xC0, 0x7C, 0x00},
    // Character 131 (â)
    {0x38, 0x6C, 0x00, 0x7C, 0x06, 0x7E, 0xC6, 0x7E},
    // Character 132 (ä)
    {0x6C, 0x00, 0x7C, 0x06, 0x7E, 0xC6, 0x7E, 0x00},
    // Character 133 (à)
    {0x18, 0x0C, 0x00, 0x7C, 0x06, 0x7E, 0xC6, 0x7E},
    // Character 134 (å)
    {0x38, 0x6C, 0x38, 0x7C, 0x06, 0x7E, 0xC6, 0x7E},
    // Character 135 (ç)
    {0x00, 0x00, 0x7C, 0xC6, 0xC0, 0xC6, 0x7C, 0x18},
    // Character 136 (ê)
    {0x38, 0x6C, 0x00, 0x7C, 0xC6, 0xFE, 0xC0, 0x7C},
    // Character 137 (ë)
    {0x6C, 0x00, 0x7C, 0xC6, 0xFE, 0xC0, 0x7C, 0x00},
    // Character 138 (è)
    {0x18, 0x0C, 0x00, 0x7C, 0xC6, 0xFE, 0xC0, 0x7C},
    // Character 139 (ï)
    {0x6C, 0x00, 0x7E, 0x18, 0x18, 0x18, 0x7E, 0x00},
    // Character 140 (î)
    {0x38, 0x6C, 0x00, 0x7E, 0x18, 0x18, 0x7E, 0x00},
    // Character 141 (ì)
    {0x18, 0x0C, 0x00, 0x7E, 0x18, 0x18, 0x7E, 0x00},
    // Character 142 (Ä)
    {0x6C, 0x00, 0x38, 0x6C, 0xC6, 0xFE, 0xC6, 0xC6},
    // Character 143 (Å)
    {0x38, 0x6C, 0x38, 0x38, 0x6C, 0xC6, 0xFE, 0xC6},
    // Character 144 (É)
    {0x1C, 0x0C, 0x00, 0xFE, 0x62, 0x78, 0x62, 0xFE},
    // Character 145 (æ)
    {0x00, 0x00, 0x7C, 0xDE, 0xDE, 0xC0, 0x7E, 0x00},
    // Character 146 (Æ)
    {0x3E, 0x6C, 0xCC, 0xFC, 0xCC, 0xCC, 0xCE, 0x00},
    // Character 147 (ô)
    {0x38, 0x6C, 0x00, 0x7C, 0xC6, 0xC6, 0x7C, 0x00},
    // Character 148 (ö)
    {0x6C, 0x00, 0x7C, 0xC6, 0xC6, 0xC6, 0x7C, 0x00},
    // Character 149 (ò)
    {0x18, 0x0C, 0x00, 0x7C, 0xC6, 0xC6, 0x7C, 0x00},
    // Character 150 (û)
    {0x38, 0x6C, 0x00, 0xC6, 0xC6, 0xC6, 0x7E, 0x00},
    // Character 151 (ù)
    {0x18, 0x0C, 0x00, 0xC6, 0xC6, 0xC6, 0x7E, 0x00},
    // Character 152 (ÿ)
    {0x6C, 0x00, 0xC6, 0xC6, 0xC6, 0x7E, 0x06, 0x7C},
    // Character 153 (Ö)
    {0x6C, 0x00, 0x38, 0x6C, 0xC6, 0xC6, 0x38, 0x00},
    // Character 154 (Ü)
    {0x6C, 0x00, 0xC6, 0xC6, 0xC6, 0xC6, 0x7C, 0x00},
    // Character 155 (ø)
    {0x00, 0x00, 0x78, 0xDC, 0xF6, 0x66, 0xBC, 0x00},
    // Character 156 (£)
    {0x3C, 0x66, 0x60, 0xF8, 0x60, 0x66, 0xFC, 0x00},
    // Character 157 (Ø)
    {0x7C, 0xCC, 0xDC, 0xF6, 0xE6, 0xCC, 0x78, 0x00},
    // Character 158 (×)
    {0x00, 0x82, 0x44, 0x28, 0x10, 0x28, 0x44, 0x82},
    // Character 159 (ƒ)
    {0x1C, 0x30, 0x7C, 0x30, 0x30, 0x30, 0x30, 0x30},
    // Character 160 (á)
    {0x18, 0x0C, 0x00, 0x7C, 0x06, 0x7E, 0xC6, 0x7E},
    // Character 161 (í)
    {0x0C, 0x06, 0x00, 0x7E, 0x18, 0x18, 0x7E, 0x00},
    // Character 162 (ó)
    {0x18, 0x0C, 0x00, 0x7C, 0xC6, 0xC6, 0x7C, 0x00},
    // Character 163 (ú)
    {0x18, 0x0C, 0x00, 0xC6, 0xC6, 0xC6, 0x7E, 0x00},
    // Character 164 (ñ)
    {0x36, 0x6C, 0x00, 0xDC, 0x66, 0x66, 0x66, 0x00},
    // Character 165 (Ñ)
    {0x36, 0x6C, 0x00, 0xC6, 0xE6, 0xF6, 0xDE, 0xC6},
    // Character 166 (ª)
    {0x30, 0x00, 0x7C, 0xC6, 0xFE, 0xC0, 0x7C, 0x00},
    // Character 167 (º)
    {0x18, 0x00, 0x7C, 0xC6, 0xC6, 0xC6, 0x7C, 0x00},
    // Character 168 (¿)
    {0x18, 0x00, 0x18, 0x30, 0x60, 0x66, 0x3C, 0x00},
    // Character 169 (®)
    {0x7E, 0x81, 0xB9, 0x85, 0xB9, 0x99, 0x81, 0x7E},
    // Character 170 (¬)
    {0x00, 0x00, 0xFE, 0x02, 0x02, 0x00, 0x00, 0x00},
    // Character 171 (½)
    {0x61, 0x91, 0x23, 0xC4, 0x18, 0x32, 0x47, 0x02},
    // Character 172 (¼)
    {0x61, 0x91, 0x22, 0xC4, 0x1A, 0x34, 0x4B, 0x02},
    // Character 173 (¡)
    {0x18, 0x18, 0x18, 0x18, 0x00, 0x18, 0x18, 0x00},
    // Character 174 («)
    {0x00, 0x12, 0x24, 0x48, 0x24, 0x12, 0x00, 0x00},
    // Character 175 (»)
    {0x00, 0x48, 0x24, 0x12, 0x24, 0x48, 0x00, 0x00},
    // Character 176 (░)
    {0x00, 0x00, 0x00, 0x00, 0xC6, 0x00, 0x00, 0x00},
    // Character 177 (▒)
    {0x6C, 0x00, 0x6C, 0x00, 0x6C, 0x00, 0x6C, 0x00},
    // Character 178 (▓)
    {0xFE, 0x92, 0xFE, 0x92, 0xFE, 0x92, 0xFE, 0x92},
    // Character 179 (│)
    {0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18},
    // Character 180 (┤)
    {0x18, 0x18, 0x18, 0xF8, 0x18, 0x18, 0x18, 0x18},
    // Character 181 (╡)
    {0x3C, 0x24, 0x3C, 0x24, 0x24, 0x24, 0xFC, 0x00},
    // Character 182 (╢)
    {0x18, 0x18, 0xF8, 0x18, 0xF8, 0x18, 0x18, 0x18},
    // Character 183 (╖)
    {0xFC, 0x20, 0x20, 0x3C, 0x20, 0x20, 0xFC, 0x00},
    // Character 184 (╕)
    {0x00, 0x00, 0xFC, 0x20, 0x20, 0x20, 0x00, 0x00},
    // Character 185 (╣)
    {0x18, 0x18, 0x18, 0x1F, 0x18, 0x18, 0x18, 0x18},
    // Character 186 (║)
    {0x18, 0x18, 0x18, 0xFF, 0x18, 0x18, 0x18, 0x18},
    // Character 187 (╗)
    {0xF8, 0x18, 0x18, 0x18, 0x18, 0x18, 0xF8, 0x18},
    // Character 188 (╝)
    {0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0xF8, 0x18},
    // Character 189 (╜)
    {0x18, 0x18, 0x18, 0x1F, 0x18, 0x18, 0x18, 0x1F},
    // Character 190 (╛)
    {0x18, 0x18, 0x18, 0xFF, 0x18, 0x18, 0x18, 0xFF},
    // Character 191 (┐)
    {0x18, 0x18, 0x18, 0xF8, 0x18, 0x18, 0x18, 0xFF},
    // Character 192 (└)
    {0x18, 0x18, 0x18, 0x1F, 0x18, 0x18, 0x18, 0xF8},
    // Character 193 (┴)
    {0xFC, 0x30, 0x30, 0x3C, 0x30, 0x30, 0xFC, 0x30},
    // Character 194 (┬)
    {0x30, 0x30, 0x30, 0x3C, 0x30, 0x30, 0x30, 0x3C},
    // Character 195 (├)
    {0x30, 0x30, 0xFC, 0x30, 0x30, 0xFC, 0x30, 0x30},
    // Character 196 (─)
    {0x00, 0x00, 0xFF, 0x00, 0x00, 0xFF, 0x00, 0x00},
    // Character 197 (┼)
    {0xF8, 0x30, 0x30, 0x3C, 0x30, 0x30, 0xF8, 0x30},
    // Character 198 (╞)
    {0xF8, 0x30, 0x30, 0xFC, 0x30, 0x30, 0xFC, 0x30},
    // Character 199 (╟)
    {0x00, 0x30, 0x30, 0xFC, 0x30, 0x30, 0x30, 0x00},
    // Character 200 (╚)
    {0xF8, 0x30, 0x30, 0xFC, 0x30, 0x30, 0xF8, 0x30},
    // Character 201 (╔)
    {0x18, 0x18, 0x18, 0x18, 0xFF, 0x18, 0x18, 0x18},
    // Character 202 (╩)
    {0x30, 0x30, 0xF8, 0x30, 0x30, 0x30, 0xF8, 0x30},
    // Character 203 (╦)
    {0x00, 0x30, 0x30, 0xFC, 0x30, 0x30, 0xF8, 0x30},
    // Character 204 (╠)
    {0xF8, 0x30, 0x30, 0x3C, 0x30, 0x30, 0x3C, 0x00},
    // Character 205 (═)
    {0x30, 0x30, 0x3C, 0x00, 0x30, 0x30, 0x3C, 0x00},
    // Character 206 (╬)
    {0x30, 0x30, 0x3C, 0x00, 0x30, 0x30, 0x3C, 0x30},
    // Character 207 (¤)
    {0x00, 0x00, 0xF8, 0x30, 0x30, 0x30, 0xF8, 0x30},
    // Character 208 (ð)
    {0x38, 0x6C, 0x00, 0x7C, 0xC6, 0xC6, 0x7C, 0x18},
    // Character 209 (Ð)
    {0xFC, 0x60, 0x7C, 0x66, 0x66, 0x60, 0xFC, 0x00},
    // Character 210 (Ê)
    {0x38, 0x6C, 0x00, 0x7C, 0xC6, 0xFE, 0xC6, 0x7C},
    // Character 211 (Ë)
    {0x6C, 0x00, 0xFE, 0x60, 0x7C, 0x60, 0xFE, 0x00},
    // Character 212 (È)
    {0x18, 0x0C, 0x00, 0x7C, 0xC6, 0xC6, 0x7C, 0x00},
    // Character 213 (ı)
    {0x30, 0x18, 0x00, 0x7E, 0x18, 0x18, 0x7E, 0x00},
    // Character 214 (Î)
    {0x38, 0x6C, 0x00, 0x7C, 0x06, 0x7E, 0xC6, 0x7E},
    // Character 215 (Ï)
    {0x6C, 0x00, 0x38, 0x6C, 0xC6, 0xC6, 0x38, 0x00},
    // Character 216 (╓)
    {0xFC, 0x30, 0x30, 0x3C, 0x30, 0x30, 0x30, 0x30},
    // Character 217 (╖)
    {0xF8, 0x30, 0x30, 0xFC, 0x30, 0x30, 0xF8, 0x30},
    // Character 218 (╘)
    {0x30, 0x30, 0xFC, 0x30, 0x30, 0x30, 0xF8, 0x00},
    // Character 219 (╙)
    {0x00, 0x30, 0x30, 0xFC, 0x30, 0x30, 0xF8, 0x00},
    // Character 220 (╚)
    {0x30, 0x30, 0xF8, 0x30, 0x30, 0xF8, 0x00, 0x00},
    // Character 221 (╠)
    {0xF8, 0x30, 0x30, 0xF8, 0x30, 0x30, 0xF8, 0x00},
    // Character 222 (╦)
    {0x00, 0xF8, 0x30, 0x30, 0xFC, 0x30, 0x30, 0x00},
    // Character 223 (╩)
    {0x00, 0xF8, 0x30, 0x30, 0xF8, 0x30, 0x30, 0x30},
    // Character 224 (╦)
    {0x30, 0xF8, 0x30, 0x30, 0xF8, 0x30, 0x30, 0x30},
    // Character 225 (╦)
    {0x00, 0xF8, 0x30, 0x30, 0xF8, 0x30, 0x30, 0x00},
    // Character 226 (╨)
    {0x00, 0x00, 0xFC, 0x30, 0x30, 0x30, 0xFC, 0x30},
    // Character 227 (╤)
    {0x00, 0xF8, 0x30, 0x30, 0xF8, 0x30, 0x30, 0x00},
    // Character 228 (╩)
    {0x00, 0xF8, 0x30, 0x30, 0x30, 0xFC, 0x30, 0x30},
    // Character 229 (╩)
    {0x00, 0xF8, 0x30, 0x30, 0x30, 0xF8, 0x30, 0x30},
    // Character 230 (╦)
    {0x00, 0xFC, 0x30, 0x30, 0x30, 0xFC, 0x30, 0x30},
    // Character 231 (╠)
    {0x30, 0x30, 0xFC, 0x30, 0x30, 0xFC, 0x30, 0x00},
    // Character 232 (╧)
    {0x30, 0x30, 0x30, 0xFC, 0x30, 0x30, 0xFC, 0x00},
    // Character 233 (╤)
    {0x30, 0x30, 0x30, 0xFC, 0x30, 0x30, 0xFC, 0x00},
    // Character 234 (╨)
    {0x30, 0x30, 0x30, 0xFC, 0x30, 0x30, 0xFC, 0x00},
    // Character 235 (╩)
    {0x30, 0x30, 0x30, 0xFC, 0x30, 0x30, 0xFC, 0x00},
    // Character 236 (╟)
    {0xFC, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0xFC},
    // Character 237 (╩)
    {0x30, 0x30, 0x30, 0x30, 0xFC, 0x30, 0x30, 0xFC},
    // Character 238 (╥)
    {0x30, 0x30, 0x30, 0x30, 0xF8, 0x30, 0x30, 0xFC},
    // Character 239 (╤)
    {0x00, 0xF8, 0x30, 0x30, 0xF8, 0x30, 0x30, 0xF8},
    // Character 240 (░)
    {0x00, 0xF8, 0x30, 0x30, 0xF8, 0x30, 0x30, 0xF8},
    // Character 241 (▓)
    {0x00, 0xFC, 0x30, 0x30, 0xFC, 0x30, 0x30, 0xFC},
    // Character 242 (▒)
    {0x00, 0xFC, 0x30, 0x30, 0xFC, 0x30, 0x30, 0xFC},
    // Character 243 (│)
    {0x30, 0x30, 0x30, 0x30, 0xF8, 0x30, 0x30, 0xFC},
    // Character 244 (╣)
    {0x00, 0xFC, 0x30, 0x30, 0xFC, 0x30, 0x30, 0x00},
    // Character 245 (═)
    {0x00, 0xFF, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00},
    // Character 246 (╩)
    {0x30, 0x30, 0x30, 0xF8, 0x30, 0x30, 0x30, 0xF8},
    // Character 247 (╪)
    {0x00, 0x30, 0x30, 0xF8, 0x30, 0x30, 0x30, 0x30},
    // Character 248 (╫)
    {0x00, 0x18, 0x18, 0xFE, 0x18, 0x18, 0x00, 0x00},
    // Character 249 (╩)
    {0x30, 0x30, 0x30, 0xF8, 0x30, 0x30, 0x30, 0xF8},
    // Character 250 (╪)
    {0x00, 0x30, 0x30, 0xF8, 0x30, 0x30, 0x30, 0x30},
    // Character 251 (╢)
    {0x30, 0x30, 0x30, 0xFC, 0x30, 0x30, 0x30, 0x00},
    // Character 252 (╟)
    {0x00, 0x30, 0x30, 0xFC, 0x30, 0x30, 0x30, 0x00},
    // Character 253 (╩)
    {0x00, 0xF8, 0x30, 0x30, 0xF8, 0x30, 0x30, 0xFC},
    // Character 254 (╚)
    {0x30, 0x30, 0xF8, 0x30, 0x30, 0xF8, 0x00, 0x00},
    // Character 255 (╝)
    {0x30, 0x30, 0xF8, 0x30, 0x30, 0xF8, 0x00, 0x00}
};

#ifdef __cplusplus
}
#endif

#endif
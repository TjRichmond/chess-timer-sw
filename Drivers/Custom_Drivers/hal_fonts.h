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

uint8_t cp437[95][8] = {
    // Character 0x20 (Space)
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
    // Character 0x21 (!)
    { 0x00, 0x00, 0x00, 0x0E, 0x1F, 0x0E, 0x00, 0x00 },
    // Character 0x22 (")
    { 0x00, 0x03, 0x07, 0x00, 0x00, 0x07, 0x03, 0x00 },
    // Character 0x23 (#)
    { 0x14, 0x7F, 0x14, 0x7F, 0x14, 0x00, 0x00, 0x00 },
    // Character 0x24 ($)
    { 0x08, 0x1C, 0x08, 0x3E, 0x18, 0x00, 0x00, 0x00 },
    // Character 0x25 (%)
    { 0x03, 0x03, 0x00, 0x18, 0x06, 0x03, 0x00, 0x00 },
    // Character 0x26 (&)
    { 0x1E, 0x21, 0x2A, 0x12, 0x0C, 0x00, 0x00, 0x00 },
    // Character 0x27 (')
    { 0x00, 0x03, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00 },
    // Character 0x28 (()
    { 0x00, 0x0E, 0x1B, 0x11, 0x00, 0x00, 0x00, 0x00 },
    // Character 0x29 ())
    { 0x00, 0x11, 0x1B, 0x0E, 0x00, 0x00, 0x00, 0x00 },
    // Character 0x2A (*)
    { 0x00, 0x12, 0x0E, 0x1F, 0x0E, 0x12, 0x00, 0x00 },
    // Character 0x2B (+)
    { 0x08, 0x08, 0x1C, 0x08, 0x08, 0x00, 0x00, 0x00 },
    // Character 0x2C (,)
    { 0x00, 0x00, 0x00, 0x00, 0x06, 0x0C, 0x00, 0x00 },
    // Character 0x2D (-)
    { 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00 },
    // Character 0x2E (.)
    { 0x00, 0x00, 0x00, 0x00, 0x06, 0x06, 0x00, 0x00 },
    // Character 0x2F (/)
    { 0x00, 0x01, 0x03, 0x06, 0x0C, 0x18, 0x00, 0x00 },
    // Character 0x30 (0)
    { 0x1E, 0x21, 0x21, 0x21, 0x1E, 0x00, 0x00, 0x00 },
    // Character 0x31 (1)
    { 0x00, 0x22, 0x3F, 0x02, 0x00, 0x00, 0x00, 0x00 },
    // Character 0x32 (2)
    { 0x22, 0x31, 0x29, 0x25, 0x22, 0x00, 0x00, 0x00 },
    // Character 0x33 (3)
    { 0x22, 0x21, 0x25, 0x19, 0x12, 0x00, 0x00, 0x00 },
    // Character 0x34 (4)
    { 0x18, 0x1C, 0x16, 0x3F, 0x00, 0x00, 0x00, 0x00 },
    // Character 0x35 (5)
    { 0x27, 0x25, 0x25, 0x19, 0x12, 0x00, 0x00, 0x00 },
    // Character 0x36 (6)
    { 0x1C, 0x22, 0x25, 0x25, 0x19, 0x00, 0x00, 0x00 },
    // Character 0x37 (7)
    { 0x01, 0x01, 0x31, 0x0E, 0x07, 0x00, 0x00, 0x00 },
    // Character 0x38 (8)
    { 0x1E, 0x25, 0x25, 0x25, 0x1E, 0x00, 0x00, 0x00 },
    // Character 0x39 (9)
    { 0x1E, 0x25, 0x25, 0x15, 0x0E, 0x00, 0x00, 0x00 },
    // Character 0x3A (:)
    { 0x00, 0x06, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00 },
    // Character 0x3B (;)
    { 0x00, 0x06, 0x00, 0x00, 0x06, 0x0C, 0x00, 0x00 },
    // Character 0x3C (<)
    { 0x08, 0x1C, 0x36, 0x63, 0x00, 0x00, 0x00, 0x00 },
    // Character 0x3D (=)
    { 0x00, 0x1C, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00 },
    // Character 0x3E (>)
    { 0x00, 0x63, 0x36, 0x1C, 0x08, 0x00, 0x00, 0x00 },
    // Character 0x3F (?)
    { 0x02, 0x01, 0x01, 0x19, 0x0E, 0x00, 0x00, 0x00 },
    // Character 0x40 (@)
    { 0x0E, 0x11, 0x15, 0x12, 0x0D, 0x00, 0x00, 0x00 },
    // Character 0x41 (A)
    { 0x7E, 0x11, 0x11, 0x11, 0x7E, 0x00, 0x00, 0x00 },
    // Character 0x42 (B)
    { 0x7F, 0x49, 0x49, 0x49, 0x36, 0x00, 0x00, 0x00 },
    // Character 0x43 (C)
    { 0x3E, 0x41, 0x41, 0x41, 0x22, 0x00, 0x00, 0x00 },
    // Character 0x44 (D)
    { 0x7F, 0x41, 0x41, 0x41, 0x3E, 0x00, 0x00, 0x00 },
    // Character 0x45 (E)
    { 0x7F, 0x49, 0x49, 0x49, 0x41, 0x00, 0x00, 0x00 },
    // Character 0x46 (F)
    { 0x7F, 0x09, 0x09, 0x09, 0x01, 0x00, 0x00, 0x00 },
    // Character 0x47 (G)
    { 0x3E, 0x41, 0x49, 0x49, 0x7A, 0x00, 0x00, 0x00 },
    // Character 0x48 (H)
    { 0x7F, 0x08, 0x08, 0x08, 0x7F, 0x00, 0x00, 0x00 },
    // Character 0x49 (I)
    { 0x00, 0x41, 0x7F, 0x41, 0x00, 0x00, 0x00, 0x00 },
    // Character 0x4A (J)
    { 0x20, 0x40, 0x41, 0x3F, 0x01, 0x00, 0x00, 0x00 },
    // Character 0x4B (K)
    { 0x7F, 0x08, 0x14, 0x22, 0x41, 0x00, 0x00, 0x00 },
    // Character 0x4C (L)
    { 0x7F, 0x40, 0x40, 0x40, 0x40, 0x00, 0x00, 0x00 },
    // Character 0x4D (M)
    { 0x7F, 0x20, 0x10, 0x20, 0x7F, 0x00, 0x00, 0x00 },
    // Character 0x4E (N)
    { 0x7F, 0x30, 0x0F, 0x01, 0x7F, 0x00, 0x00, 0x00 },
    // Character 0x4F (O)
    { 0x3E, 0x41, 0x41, 0x41, 0x3E, 0x00, 0x00, 0x00 },
    // Character 0x50 (P)
    { 0x7F, 0x09, 0x09, 0x09, 0x06, 0x00, 0x00, 0x00 },
    // Character 0x51 (Q)
    { 0x3E, 0x41, 0x51, 0x21, 0x5E, 0x00, 0x00, 0x00 },
    // Character 0x52 (R)
    { 0x7F, 0x09, 0x19, 0x29, 0x46, 0x00, 0x00, 0x00 },
    // Character 0x53 (S)
    { 0x26, 0x49, 0x49, 0x49, 0x32, 0x00, 0x00, 0x00 },
    // Character 0x54 (T)
    { 0x01, 0x01, 0x7F, 0x01, 0x01, 0x00, 0x00, 0x00 },
    // Character 0x55 (U)
    { 0x7E, 0x40, 0x40, 0x40, 0x7E, 0x00, 0x00, 0x00 },
    // Character 0x56 (V)
    { 0x7C, 0x20, 0x10, 0x08, 0x7C, 0x00, 0x00, 0x00 },
    // Character 0x57 (W)
    { 0x7E, 0x40, 0x30, 0x40, 0x7E, 0x00, 0x00, 0x00 },
    // Character 0x58 (X)
    { 0x63, 0x14, 0x08, 0x14, 0x63, 0x00, 0x00, 0x00 },
    // Character 0x59 (Y)
    { 0x03, 0x04, 0x78, 0x04, 0x03, 0x00, 0x00, 0x00 },
    // Character 0x5A (Z)
    { 0x61, 0x51, 0x49, 0x45, 0x43, 0x00, 0x00, 0x00 },
    // Character 0x5B ([)
    { 0x00, 0x3F, 0x41, 0x41, 0x00, 0x00, 0x00, 0x00 },
    // Character 0x5C (\)
    { 0x00, 0x01, 0x03, 0x06, 0x0C, 0x18, 0x00, 0x00 },
    // Character 0x5D (])
    { 0x00, 0x41, 0x41, 0x3F, 0x00, 0x00, 0x00, 0x00 },
    // Character 0x5E (^)
    { 0x00, 0x03, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00 },
    // Character 0x5F (_)
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00 },
    // Character 0x60 (`)
    { 0x00, 0x03, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00 },
    // Character 0x61 (a)
    { 0x00, 0x1C, 0x36, 0x36, 0x3F, 0x00, 0x00, 0x00 },
    // Character 0x62 (b)
    { 0x7F, 0x24, 0x24, 0x18, 0x00, 0x00, 0x00, 0x00 },
    // Character 0x63 (c)
    { 0x00, 0x1C, 0x22, 0x22, 0x00, 0x00, 0x00, 0x00 },
    // Character 0x64 (d)
    { 0x00, 0x18, 0x24, 0x24, 0x7F, 0x00, 0x00, 0x00 },
    // Character 0x65 (e)
    { 0x00, 0x1C, 0x2A, 0x2A, 0x1A, 0x00, 0x00, 0x00 },
    // Character 0x66 (f)
    { 0x00, 0x0C, 0x3E, 0x0C, 0x0C, 0x00, 0x00, 0x00 },
    // Character 0x67 (g)
    { 0x00, 0x1A, 0x2A, 0x2A, 0x1E, 0x00, 0x00, 0x00 },
    // Character 0x68 (h)
    { 0x7F, 0x08, 0x08, 0x08, 0x00, 0x00, 0x00, 0x00 },
    // Character 0x69 (i)
    { 0x00, 0x22, 0x3F, 0x02, 0x00, 0x00, 0x00, 0x00 },
    // Character 0x6A (j)
    { 0x00, 0x04, 0x02, 0x3F, 0x00, 0x00, 0x00, 0x00 },
    // Character 0x6B (k)
    { 0x7F, 0x08, 0x14, 0x22, 0x41, 0x00, 0x00, 0x00 },
    // Character 0x6C (l)
    { 0x00, 0x41, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00 },
    // Character 0x6D (m)
    { 0x00, 0x7F, 0x20, 0x18, 0x7F, 0x00, 0x00, 0x00 },
    // Character 0x6E (n)
    { 0x00, 0x7F, 0x30, 0x0F, 0x00, 0x00, 0x00, 0x00 },
    // Character 0x6F (o)
    { 0x00, 0x1E, 0x21, 0x21, 0x1E, 0x00, 0x00, 0x00 },
    // Character 0x70 (p)
    { 0x00, 0x7F, 0x09, 0x09, 0x06, 0x00, 0x00, 0x00 },
    // Character 0x71 (q)
    { 0x00, 0x06, 0x09, 0x09, 0x7F, 0x00, 0x00, 0x00 },
    // Character 0x72 (r)
    { 0x00, 0x7F, 0x08, 0x08, 0x00, 0x00, 0x00, 0x00 },
    // Character 0x73 (s)
    { 0x00, 0x24, 0x2A, 0x2A, 0x12, 0x00, 0x00, 0x00 },
    // Character 0x74 (t)
    { 0x00, 0x08, 0x3E, 0x09, 0x00, 0x00, 0x00, 0x00 },
    // Character 0x75 (u)
    { 0x00, 0x3F, 0x40, 0x40, 0x3F, 0x00, 0x00, 0x00 },
    // Character 0x76 (v)
    { 0x00, 0x3E, 0x40, 0x20, 0x1E, 0x00, 0x00, 0x00 },
    // Character 0x77 (w)
    { 0x00, 0x7F, 0x40, 0x30, 0x7F, 0x00, 0x00, 0x00 },
    // Character 0x78 (x)
    { 0x00, 0x63, 0x14, 0x08, 0x63, 0x00, 0x00, 0x00 },
    // Character 0x79 (y)
    { 0x00, 0x67, 0x28, 0x28, 0x1E, 0x00, 0x00, 0x00 },
    // Character 0x7A (z)
    { 0x00, 0x61, 0x51, 0x49, 0x45, 0x00, 0x00, 0x00 },
    // Character 0x7B ({)
    { 0x00, 0x0E, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00 },
    // Character 0x7C (|)
    { 0x00, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
    // Character 0x7D (})
    { 0x00, 0x11, 0x11, 0x0E, 0x00, 0x00, 0x00, 0x00 },
    // Character 0x7E (~)
    { 0x00, 0x19, 0x0E, 0x19, 0x00, 0x00, 0x00, 0x00 },
    // Character 0x7F (DEL)
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }
};

#ifdef __cplusplus
}
#endif

#endif
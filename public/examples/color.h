/*
**  File        :   app/color.h
**  Authors     :   Leschuk O.G.
**  Created on  :   14.12.2018
**  Modified on :   25.06.2021
**  Description :   color
*/

#ifndef APP_COLOR_H_
#define APP_COLOR_H_

#include "lib_common/col.h"

const _CMN::TCol3f COL_SEPARATE_LINE(_CMN::ub2f(50), _CMN::ub2f(210), _CMN::ub2f(50));
const _CMN::TCol3f  BLACK_FONE(  26.f/255.f,  26.f/255.f,  26.f/255.f );
const _CMN::TCol3f  GRAY_FONE ( 197.f/255.f, 197.f/255.f, 197.f/255.f );
const _CMN::TCol3f  BLACK     (         0.f,         0.f,         0.f );
const _CMN::TCol3f  BLACK2    (  26.f/255.f,  26.f/255.f,  26.f/255.f );
const _CMN::TCol3f  WHITE     (        1.0f,        1.0f,        1.0f );
const _CMN::TCol3f  RED       (        1.0f,         0.f,         0.f );
const _CMN::TCol3f  LIGHTRED  (        1.0f,         0.f,         0.f );
const _CMN::TCol3f  RED2      ( 227.f/255.f,  30.f/255.f,  36.f/255.f );
const _CMN::TCol3f  RED3      ( 247.f/255.f,   8.f/255.f,   8.f/255.f );
const _CMN::TCol3f  DARKRED   ( 222.f/256.f,   0.f/255.f,  45.f/256.f );
const _CMN::TCol3f  MAGENTA   ( 255.f/255.f,   0.f/255.f, 255.f/255.f );
const _CMN::TCol3f  MAGENTA2  ( 205.f/255.f, 100.f/255.f, 202.f/255.f );
const _CMN::TCol3f  ORANGE    ( 252.f/255.f, 168.f/255.f,  84.f/255.f );    // оранжевый
const _CMN::TCol3f  ORANGE2   ( 239.f/255.f, 127.f/255.f,  26.f/255.f );
const _CMN::TCol3f  ORANGE3   ( 255.f/255.f, 149.f/255.f,  79.f/255.f );
const _CMN::TCol3f  ORANGE4   ( 255.f/255.f, 102.f/255.f,   0.f/255.f );
const _CMN::TCol3f  BLUE      (  10.f/255.f, 100.f/255.f, 230.f/255.f );   // голубой
const _CMN::TCol3f  BLUE2     (  10.f/255.f, 160.f/255.f, 227.f/255.f );
const _CMN::TCol3f  BLUE3     (   0.f/255.f, 255.f/255.f, 255.f/255.f );
const _CMN::TCol3f  BLUE4     (   0.f/255.f, 204.f/255.f, 255.f/255.f );
const _CMN::TCol3f  BLUE5     (  46.f/255.f,  62.f/255.f, 209.f/255.f );
const _CMN::TCol3f  BLUE6     (  58.f/255.f, 132.f/255.f, 132.f/255.f );
const _CMN::TCol3f  BLUE7     (  52.f/255.f, 126.f/255.f, 157.f/255.f );
const _CMN::TCol3f  BLUE8     ( 196.f/255.f, 209.f/255.f, 254.f/255.f );
const _CMN::TCol3f  BLUE9     (   2.f/255.f, 254.f/255.f, 251.f/255.f );
const _CMN::TCol3f  LIGHTBLUE (   0.f/255.f, 141.f/255.f, 210.f/255.f );
const _CMN::TCol3f  AZURE     (         0.f, 141.f/255.f, 210.f/255.f );
const _CMN::TCol3f  GREEN     (         0.f, 255.f/255.f,   0.f/255.f );
const _CMN::TCol3f  GREEN2    (         0.f, 152.f/255.f,  70.f/255.f );
const _CMN::TCol3f  GREEN3    (  51.f/255.f, 102.f/255.f, 102.f/255.f );
const _CMN::TCol3f  GREEN4    (  51.f/255.f, 153.f/255.f, 102.f/255.f );
const _CMN::TCol3f  GREEN5    (           0, 173.f/255.f,   0.f/255.f );
const _CMN::TCol3f  GREEN6    (   0.f/255.f, 152.f/255.f,  70.f/255.f );
const _CMN::TCol3f  GREEN7    ( 204.f/255.f, 255.f/255.f, 204.f/255.f );
const _CMN::TCol3f  GREEN8    (  52.f/255.f, 126.f/255.f, 157.f/255.f );
const _CMN::TCol3f  DARKGREEN (         0.f, 146.f/255.f,   0.f/255.f );
const _CMN::TCol3f  LIGHTGREEN( 132.f/255.f, 194.f/255.f,  37.f/255.f );
const _CMN::TCol3f  LIGHTGREEN2(204.f/255.f, 255.f/255.f, 204.f/255.f );
const _CMN::TCol3f  BROWN     ( 181.f/255.f,  83.f/255.f,  43.f/255.f );
const _CMN::TCol3f  LIGHTBROWN( 228.f/255.f, 217.f/255.f, 157.f/255.f );    //светло-коричневый
const _CMN::TCol3f  BROWN1    ( 239.f/255.f, 127.f/255.f,  26.f/255.f );
const _CMN::TCol3f  BROWN2    ( 158.f/255.f, 129.f/255.f, 110.f/255.f );
const _CMN::TCol3f  DARKGRAY  (  78.f/255.f,  86.f/255.f,  90.f/255.f );
const _CMN::TCol3f  GRAY      (  67.f/255.f,  66.f/255.f,  66.f/255.f );
const _CMN::TCol3f  GRAY2     ( 158.f/255.f, 159.f/255.f, 159.f/255.f );
const _CMN::TCol3f  GRAY3     ( 128.f/255.f, 128.f/255.f, 128.f/255.f );
const _CMN::TCol3f  GRAY4     ( 204.f/255.f, 255.f/255.f, 204.f/255.f );
const _CMN::TCol3f  LIGHTGRAY (  87.f/255.f,  87.f/255.f,  87.f/255.f );
const _CMN::TCol3f  LIGHTGRAY2( 222.f/255.f, 222.f/255.f, 221.f/255.f );
const _CMN::TCol3f  LIGHTGRAY3( 197.f/255.f, 197.f/255.f, 197.f/255.f );
const _CMN::TCol3f  YELLOW    ( 255.f/255.f, 237.f/255.f,   0.f/255.f );    // желтый цвет
const _CMN::TCol3f  YELLOW2   ( 240.f/255.f, 200.f/255.f,   0.f/255.f );
const _CMN::TCol3f  YELLOW3   ( 255.f/255.f, 255.f/255.f,   0.f/255.f );
const _CMN::TCol3f  DARKORANGE( 255.f/255.f, 118.f/255.f,  34.f/255.f );    // оранжевый цвет
const _CMN::TCol3f  PINK      ( 204.f/255.f,  51.f/255.f, 153.f/255.f );    /* розовый*/

#endif /* APP_COLOR_H_ */

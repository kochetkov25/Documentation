/*
**  File        :   plt_vspeed.h
**  Authors     :   
**  Created on  :   
**  Modified on :   
**  Description :	plt_vspeed
*/

#ifndef	_PLT_VSPEED_H
#define	_PLT_VSPEED_H

#include "lib_common/interface.h"
#include "lib_common/render.h"
#include "lib_common/font.h"
#include "lib_common/math.h"
#include "lib_common/col.h"
#include "app/color.h"
#include "vspeed_dat.h"
#include <string>

class cls_plt_vspeed
{
public:
	/*конструктор по умолчанию*/
	cls_plt_vspeed();
	/*установка параметров*/
	void setXY(float x_c, float y_c);
	/*отрисовка шкалы в виде текстуры*/
	void scale(void);
	/*отрисовка стрелки вертикальной скорости*/
	void index(float Vvert);
	/*отрисовка текстового индекса*/
	void indexT(float Vvert);
	/*инициализаци€ объектов дл€ формировани€ изображени€ в OpenGL
	и последующей отрисовки*/
	bool init(void);
	/*инициализаци€ полей класса дл€ корректной отрисовки*/
	void initCommon(void);

private:
	/*расчет коэффициента движени€*/
	float getKoef(void);
	/*координата x центра фрагмента*/
	float _x_c;
	/*координата y центра фрагмента*/
	float _y_c;
	const int _z = -1;
	/*верхнее ограничение шкалы*/
	float _par_min;
	/*нижнее ограничение шкалы*/
	float _par_max;
	/*поле дл€ инициализации*/
	int _init = 1;
	/*объ€вление объекта класса TRender дл€ формировани€ изображени€ в OpenGL*/
	_CMN::TRender _pRender;
	/*объ€вление объекта класса TInterface дл€ отрисовки графических функций*/
	_CMN::TInterface *_pInterface;
	/*объ€вление объекта класса TSymgen_yakPil152 дл€ загрузки текстур*/
	vspeed_dat _symgen;
};
#endif
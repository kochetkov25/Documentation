/*
**  File        :   plt_speed.cpp
**  Authors     :   
**  Created on  :   
**  Modified on :   
**  Description :	plt_speed
*/

#ifndef	_PLT_SPEED_H
#define	_PLT_SPEED_H

#include "lib_common/interface.h"
#include "lib_common/render.h"
#include "lib_common/render.h"
#include "lib_common/font.h"
#include "lib_common/math.h"
#include "lib_common/col.h"
#include "app/color.h"
#include "yakPil152.h"
#include <string>

class cls_plt_speed
{
public:
	/*конструктор по умолчанию*/
	cls_plt_speed();
	/* установка центра фрагмента*/
	void setXY(float x_c, float y_c);
	/*отрисовка шкалы в виде текстуры*/
	void scale(void);
	/*отрисовка стрелки истинной скорости*/
	void indexVist(float Vist);
	/*отрисовка стрелки приборной сокорости*/
	void indexVprib(float Vpr);
	/*отрисовка текстового индекса*/
	void indexT(float Vpr);
	/*отрисовка индекса ограничени€ минимальной скорости*/
	void indexVprMin(float Vpr_min);
	/*отрисовка индекса ограничени€ максимальной скорости*/
	void indexVprMax(float Vpr_max);
	/*отрисовка индекса прогрнозируемой скорости*/
	void indexVprog(float Vpr_prog);
	/*инициализаци€ объектов дл€ формировани€ изображени€ в OpenGL
	и последующей отрисовки*/
	bool init(void);
	/*инициализаци€ полей класса дл€ корректной отрисовки*/
	void initCommon(void);
private:
	/*расчет коэффициента шкалы*/
	float getParam(float par);
	/*координата x центра фрагмента*/
	float _x_c;
	/*координата y центра фрагмента*/
	float _y_c;
	/*радиус шкалы*/
	float _rad;
	const int _z = -1;
	/*поле дл€ инициализации*/
	int _init = 1;
	/*объ€вление объекта класса TRender дл€ формировани€ изображени€ в OpenGL*/
	_CMN::TRender _pRender;
	/*объ€вление объекта класса TInterface дл€ отрисовки графических функций*/
	_CMN::TInterface *_pInterface;
	/*объ€вление объекта класса TSymgen_yakPil152 дл€ загрузки текстур*/
	TSymgen_yakPil152 _symgen;
};

#endif//_PLT_SPEED_H
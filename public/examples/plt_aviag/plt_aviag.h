/*
**  File        :   plt_aviag.h
**  Authors     :   
**  Created on  :   
**  Modified on :   
**  Description :	plt_aviag
*/

#ifndef HEADER_PLT_AVIAG_H_
#define HEADER_PLT_AVIAG_H_


#include "lib_common/interface.h"
#include "lib_common/render.h"
#include "lib_common/font.h"
#include "lib_common/math.h"
#include "lib_common/col.h"
#include "app/color.h"
#include "aviag_dat.h"
#include <string>

class cls_plt_aviag
{
public:
	/*конструктор по умолчанию*/
	cls_plt_aviag();
	/*отрисовка шкалы крена*/
	void scaleKren(void);
	/*отрисовка шкалы тангажа в виде текстуры*/
	void scaleTang(float par_Tang_Tek);
	/*отрисовка положени€ шасси в виде текстуры*/
	void chassi(float par_grad, bool ChassisLeftOn, bool ChassisRightOn, bool ChassisFrontOn);
	/*отрисовка положени€ закрылок в виде текстуры*/
	void flaps(float Flaps_position, float par_grad);
	/*отрисовка силуэта летательного аппарата в виде текстуры*/
	void indexLA(float par_grad);
	/*установка параметров*/
	void setXY(float x_c, float y_c);

	/*отрисовка вертикальной директорной планки*/
	void dirPlankaVert(float Dk);
	/*отрисовка горизонтальной директорной планки*/
	void dirPlankaHor(float Dt);
	/*инициализаци€ объектов дл€ формировани€ изображени€ в OpenGL
	и последующей отрисовки*/
	bool init(void);
	/*инициализаци€ полей класса дл€ корректной отрисовки*/
	void initCommon(void);

private:
	/*координата x центра фрагмента*/
	float _x_c;
	/*координата y центра фрагмента*/
	float _y_c;
	/*радиус текстуры*/
	float _rad;
	const int _z = -1;
	/*поле дл€ инициализации*/
	int _init = 1;
	/*объ€вление объекта класса TRender дл€ формировани€ изображени€ в OpenGL*/
	_CMN::TRender _pRender;
	/*объ€вление объекта класса TInterface дл€ отрисовки графических функций*/
	_CMN::TInterface *_pInterface;
	/*объ€вление объекта класса TSymgen_yakPil152 дл€ загрузки текстур*/
	aviag_dat _symgen;
};


#endif /* HEADER_PLT_PLT_AVIAG_H_ */

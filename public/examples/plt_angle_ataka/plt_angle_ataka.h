/*
** File : plt_angle_ataka.h
** Authors :
** Created on :
** Modified on :
** Description : plt_angle_ataka
*/

#ifndef HEADER_PLT_ANGLE_ATAKA_H_
#define HEADER_PLT_ANGLE_ATAKA_H_

#include "lib_common/interface.h"
#include "lib_common/render.h"
#include "lib_common/math.h"
#include "lib_common/font.h"
#include "lib_common/col.h"
#include "app/color.h"
#include "angle_ataka_dat.h"
#include <string>

class cls_plt_angle_ataka
{

public:

	enum ELocation{
		_e_Up, _e_Down
	};
	/*конструктор по умолчанию*/
	cls_plt_angle_ataka();
	/*установка координат центра фрагмента*/
	void setXY(float x_c, float y_c);
	/*отрисовка шкалы в виде текстуры*/
	void scale(void);
	/*отрисовка стрелки в виде текстуры*/
	void index(float Angle_attak);
	/*отрисовка текстового индекса*/
	void indexT(ELocation loc, float Angle_attak);
	/*отрисовка cектора критических углов атаки*/
	void AngleAttakCritical(float Angle_attak_max);
	/*отрисовка символа альфа*/
	void AngleAttakSym();
	/*инициализаци€ объектов дл€ формировани€ изображени€ в OpenGL
	и последующей отрисовки*/
	bool init(void);
	/*инициализаци€ полей класса дл€ корректной отрисовки*/
	void initCommon(void);

private:
	/*расчет коэффициента движени€ дл€ стрелки*/
	float getKoef(void);
	/*расчет коэффициента движени€ дл€ дуги*/
	float getKoefArc(void);

	/*координата x центра фрагмента*/
	float _x_c;
	/*координата y центра фрагмента*/
	float _y_c;
	/*радиус дл€ отрисовки текстур*/
	float _rad;
	const int _z = -1;
	/*поле дл€ инициализации*/
	int _init = 1;
	/*нижнее ограничение шкалы*/
	float _par_min;
	/*верхнее ограничение шкалы*/
	float _par_max;
	/*центр дл€ отрисовки дуг сектора критических углов*/
	float _x_c_arc;
	/*центр дл€ отрисовки стрелки*/
	float _x_c_index;
	/*объ€вление объекта класса TRender дл€ формировани€ изображени€ в OpenGL*/
	_CMN::TRender _pRender;
	/*объ€вление объекта класса TInterface дл€ отрисовки графических функций*/
	_CMN::TInterface *_pInterface;
	/*объ€вление объекта класса TSymgen_yakPil152 дл€ загрузки текстур*/
	angle_ataka_dat _symgen;
};

#endif /* HEADER_PLT_PLT_ANGLE_ATAKA_H_ */

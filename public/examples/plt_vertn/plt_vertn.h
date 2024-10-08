/*
** File : plt_vertn.h
** Authors :
** Created on :
** Modified on :
** Description : plt_vertn
*/

#ifndef HEADER_PLT_VERTN_H_
#define HEADER_PLT_VERTN_H_

#include "lib_common/interface.h"
#include "lib_common/render.h"
#include "lib_common/math.h"
#include "lib_common/font.h"
#include "lib_common/col.h"
#include "app/color.h"
#include "vertn_dat.h"
#include <string>

class cls_plt_vertn
{

public:

	/*конструктор по умолчанию*/
	cls_plt_vertn();
	/*установка координат центра фрагмента*/
	void setXY(float x_c, float y_c);
	/*отрисовка шкалы в виде текстуры*/
	void scale(void);
	/*отрисовка текстового индекса и стрелки*/
	void indexT(float Ny);
	/*отрисовка символа ny*/
	void NySym(void);
	/*отрисовка сектора критических положительных перегрузок*/
	void NyMaxLim(float Ny_max);
	/*отрисовка сектора критических отрицательных перегрузок*/
	void NyMinLim(float Ny_min);
	/*отрисовка максимально достигнутого значени€ положительной
	перегрузки*/
	void NyMaxFlight(float Ny);
	/*отрисовка максимально достигнутого значени€ отрицательной
	перегрузки*/
	void NyMinFlight(float Ny);
	/*отрисовка предела аэродинамических ограничений*/
	void NyDisp(float Ny_disp);
	/*инициализаци€ объектов дл€ формировани€ изображени€ в OpenGL
	и последующей отрисовки*/
	bool init(void);
	/*инициализаци€ полей класса дл€ корректной отрисовки*/
	void initCommon(void);

private:
	/*расчет коэффициента движени€*/
	float getKoef(void);
	/*координата x центра фрагмета*/
	float _x_c;
	/*координата y центра фрагмента*/
	float _y_c;
	/*длинна текстуры*/
	float _length;
	const int _z = -1;
	/*поле дл€ инициализации*/
	int _init = 1;
	/*ограничение шкалы сверху*/
	float _max_par;
	/*ограничение шкалы снизу*/
	float _min_par;
	/*объ€вление объекта класса TRender дл€ формировани€ изображени€ в OpenGL*/
	_CMN::TRender _pRender;
	/*объ€вление объекта класса TInterface дл€ отрисовки графических функций*/
	_CMN::TInterface *_pInterface;
	/*объ€вление объекта класса TSymgen_yakPil152 дл€ загрузки текстур*/
	vertn_dat _symgen;
};


#endif /* HEADER_PLT_PLT_VERTN_H_ */
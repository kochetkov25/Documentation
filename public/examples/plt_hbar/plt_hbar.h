/*
**  File        :   plt_hbar.h
**  Authors     :   
**  Created on  :   
**  Modified on :  
**  Description :	plt_hbar
*/

#ifndef	_PLT_HBAR_H
#define	_PLT_HBAR_H

#include "lib_common/interface.h"
#include "lib_common/render.h"
#include "lib_common/math.h"
#include "lib_common/font.h"
#include "lib_common/col.h"
#include "app/color.h"
#include "hbar_dat.h"
#include <string>

class cls_plt_hbar
{
public:
	/*конструктор по умолчанию*/
	cls_plt_hbar();
	/*установка центра фрагмента*/
	void setXY(float x_c, float y_c);
	/*отрисовка шкалы в виде текстуры*/
	void scale(void);
	/*отрисовка стрелки в виде текстуры*/
	void indexHbar(float Hbar);
	/*отрисовка текстового индекса высоты*/
	void indexT(float Hbar);
	/*отрисовка индекса опасной высоты в виде текстуры*/
	void indexHdanger(float Hop);
	/*отрисовка индекса геометрической высоты*/
	void indexHgeom(float Hg);
	/*отрисовка индекса прогнозируемой геометрической высоты в виде текстуры*/
	void indexHprog(float H_prog);
	/*отрисовка цифрового индикатора геометрической высоты*/
	void textHgeom(float Hg);
	/*отрисовка сектора допустимых отклонений от заданной высоты*/
	void indexDopOtklonHzad(float Hzad);
	/*отрисовка индекса заданной высоты в виде текстуры*/
	void indexHzad(float Hzad);
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
	hbar_dat _symgen;
};

#endif	//_PLT_HBAR_H

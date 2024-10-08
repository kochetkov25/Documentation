/*
**  File        :   plt_ndvig.h
**  Authors     :   
**  Created on  :   
**  Modified on :   
**  Description :	plt_ndvig
*/

#ifndef HEADER_PLT_NDVIG_H_
#define HEADER_PLT_NDVIG_H_

#include "lib_common/interface.h"
#include "lib_common/render.h"
#include "lib_common/math.h"
#include "lib_common/font.h"
#include "lib_common/col.h"
#include "app/color.h"
#include "ndvig_dat.h"
#include <string>

class cls_plt_ndvig
{
public:
	/*конструктор по умолчанию*/
	cls_plt_ndvig(); 
	/*установка центра фрагмента*/
	void setXY(float x_c, float y_c);
	/*отрисовка шкалы в виде текстуры*/
	void scale(void);
	/*отрисовка индекса оборотов*/
	void index(float PropRev);
	/*отрисовка текстового индекса*/
	void indexT(float PropRev);
	/*отрисовка индекса-ограничител€ максимально допустимых оборотов винта в виде текстуры*/
	void indexLimit(float PropRevLim);
	/*инициализаци€ объектов дл€ формировани€ изображени€ в OpenGL
	и последующей отрисовки*/
	bool init(void);
	/*инициализаци€ полей класса дл€ корректной отрисовки*/
	void initCommon(void);

private:
	/*расчет коэффициента шкалы в зависимости от диапазона*/
	float getKoef(void);

	/*координата x центра фрагмента*/
	float _x_c;
	/*координата y центра фрагмента*/
	float _y_c;
	/*длинна текстуры*/
	float _length;
	const int _z = -1;
	/*поле дл€ инициализации*/
	int _init = 1;
	/*верхнее ограничение шкал*/
	float _max_par;
	/*нижнее ограничение шкалы*/
	float _min_par;
	/*объ€вление объекта класса TRender дл€ формировани€ изображени€ в OpenGL*/
	_CMN::TRender _pRender;
	/*объ€вление объекта класса TInterface дл€ отрисовки графических функций*/
	_CMN::TInterface *_pInterface;
	/*объ€вление объекта класса TSymgen_yakPil152 дл€ загрузки текстур*/
	ndvig_dat _symgen;
};


#endif /* HEADER_PLT_PLT_NDVIG_H_ */

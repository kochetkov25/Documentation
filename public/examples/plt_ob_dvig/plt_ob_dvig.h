/*
**  File        :   plt_ob_dvig.h
**  Authors     :   
**  Created on  :   
**  Modified on :   
**  Description :	plt_ob_dvig
*/

#ifndef HEADER_PLT_OB_DVIG_H_
#define HEADER_PLT_OB_DVIG_H_

#include "lib_common/interface.h"
#include "lib_common/render.h"
#include "lib_common/math.h"
#include "lib_common/font.h"
#include "lib_common/col.h"
#include "app/color.h"
#include "ob_dvig_dat.h"
#include <string>

class cls_plt_ob_dvig
{
public:
	/*конструктор по умолчанию*/
	cls_plt_ob_dvig();
	/*установка координат центра фрагмента*/
	void setXY(float x_c, float y_c);
	/*отрисовка шкалы в виде текстуры*/
	void scale(void);
	/*отрисовка стрелки мощности в виде текстуры*/
	void index(float Power);
	/*отрисовка текстового индекса*/
	void indexT(float Power);
	/*отрисовка указател€ положени€ –”ƒ*/
	void indexRud(float pQ_PWL);
	/*отрисовка индексов номинальных значений мощности двигател€*/
	void indexLimit(void);
	/*инициализаци€ объектов дл€ формировани€ изображени€ в OpenGL
	и последующей отрисовки*/
	bool init(void);
	/*инициализаци€ полей класса дл€ корректной отрисовки*/
	void initCommon(void);

private:
	/*расчет коэффициента угла поворота*/
	float getPar(float par);

	/*координата x центра фрагмента*/
	float _x_c;
	/*координата y центра фрагмента*/
	float _y_c;
	/*радиус текстуры*/
	float _rad;
	const int z = -1;
	/*поле дл€ инициализации*/
	int _init = 1;
	/*верхнее ограничение шкалы*/
	float _max_par;
	/*нижнее ограничение шкалы*/
	float _min_par;
	/*объ€вление объекта класса TRender дл€ формировани€ изображени€ в OpenGL*/
	_CMN::TRender _pRender;
	/*объ€вление объекта класса TInterface дл€ отрисовки графических функций*/
	_CMN::TInterface *_pInterface;
	/*объ€вление объекта класса TSymgen_yakPil152 дл€ загрузки текстур*/
	ob_dvig_dat _symgen;
};


#endif /* HEADER_PLT_PLT_OB_DVIG_H_ */
/*
**  File        :   plt_kurs.h
**  Authors     :   
**  Created on  :  
**  Modified on :  
**  Description :	plt_kurs
*/

#ifndef	_PLT_KURS_H
#define	_PLT_KURS_H

#include "lib_common/interface.h"
#include "lib_common/render.h"
#include "lib_common/math.h"
#include "lib_common/font.h"
#include "lib_common/col.h"
#include "app/color.h"
#include "kurs_dat.h"
#include <string>

class cls_plt_kurs 
{
public:

	/*конструктор по умолчанию*/
	cls_plt_kurs();
	/*установка координат центра фрагмента*/
	void setXY(float x_c, float y_c);
	/*отрисовка шкалы курса в виде текстуры*/
	void scale(void);
	/*отрисовка текущего индекса*/
	void indexTek(void);
	/*отрисовка заданного индекса*/
	void indexZad(float Course_giv);
	/*отрисовка индекса заданного ПУ*/
	void indexZadPU(float Course_giv_track);
	/*отрисовка углового индекса*/
	void indexAngle(float par_grad, _CMN::TCol3f color);
	/*установка параметров для шкалы отклонений*/
	void setParamOtkl(void);
	/*отрисовка шкалы отклонений*/
	void scaleOtkl(void);
	/*отрисовка вертикального индекса отклонений*/
	void indexOtklVert(float par_otkl_vert);
	/*отрисовка горизонтального индекса отклонений*/
	void indexOtklGor(float par_otkl_gor);
	/*установка коэффициента шкалы*/
	void setKurs(float M_cur, float True_cur, bool _pr_M);
	/*отрисовка указателя угла сноса (ФПУ)*/
	void indexDriftAngle(float TrackAngle);
	/*отрисовка стрелочного указатель пеленга РМ РСБН*/
	void indexAzRsbn(float Az_rsbn);
	/*инициализация объектов для формирования изображения в OpenGL
	и последующей отрисовки*/
	bool init(void);
	/*инициализация полей класса для корректной отрисовки*/
	void initCommon(void);

private:
	/*расчет вертикального коэффициента шкалы отклонений*/
	float getKoeffVert(void);
	/*расчет горизонтального коэффициента шкалы отклонений*/
	float getKoeffGor(void);

	/*координата х центра фрагмента*/
	float _x_c;
	/*координата у центра фрагмента*/
	float _y_c;
	/*радиус текстуры для корректной отрисовки*/
	float _rad;
	/*максимальное значение шкалы отклонений*/
	float _max_par;
	/*высота шкалы отклонений*/
	float _max_length_vert;
	/*длинна шкалы отклонений*/
	float _max_length_gor;
	const int z = -1;
	/*поле для инициализации*/
	int _init = 1;
	/*значение текущего курса*/
	float _tekKurs;
	int _pr_M;

	/*объявление объекта класса TRender для формирования изображения в OpenGL*/
	_CMN::TRender _pRender;
	/*объявление объекта класса TInterface для отрисовки графических функций*/
	_CMN::TInterface *_pInterface;
	/*объявление объекта класса TSymgen_yakPil152 для загрузки текстур*/
	kurs_dat _symgen;
};

#endif	//_PLT_KURS_H

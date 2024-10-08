/*
**  File        :   plt_kurs.cpp
**  Authors     :  
**  Created on  :  
**  Modified on :  
**  Description :   plt_kurs
*/

#include "plt_kurs.h"

cls_plt_kurs  	plt_kurs;

/*****************************************************************************/
/*standard constructor*/
cls_plt_kurs::cls_plt_kurs()
{
	_x_c = 0;
	_y_c = 0;
	_rad = 0;
}

/*инициализация объектов для формирования изображения в OpenGL
и последующей отрисовки*/
bool cls_plt_kurs::init(){
	if (_init){
		/*инициализация интерфейса*/
		_pInterface = _pRender.getInterface();
		/*инициализация текстур*/
		if (!_pInterface)
			return false;
		_pInterface->readSymgen(_symgen, "./files/dat/yakPil152.dat");
		/*установка параметров отрисовки*/
		_pRender.BlendFunc(_CMN::TRender::SRC_ALPHA,
			_CMN::TRender::ONE_MINUS_SRC_ALPHA);
		_pRender.TexEnvMode(_CMN::TRender::MODULATE);
		/*инициализация шрифта*/
		_pRender.initFonts("./files/fonts/");
		/*инициализация полей для корректной отрисовки*/
		plt_kurs.initCommon();
		_init = 0;
	}
}

/*инициализация полей класса для корректной отрисовки*/
void cls_plt_kurs::initCommon(){
	/*задание смещения для корректной отрисовки*/
	_rad = 142;
}

/*****************************************************************************/
/*установка координат центра фрагмента*/
void cls_plt_kurs::setXY(float x_c, float y_c)
{
	_x_c = x_c;
	_y_c = y_c;
}

/*****************************************************************************/
/*отрисовка шкалы курса в виде текстуры*/
void cls_plt_kurs::scale(void)
{
	float par_grad = _tekKurs;

	_pInterface->enableTexsym();
	_pRender.PushMatrix();
	_pRender.Translatef(_x_c, _y_c, -1);
	_pRender.Rotatef(par_grad, 0, 0, 1);
	_pRender.Color3fv(WHITE);
	_pInterface->drawTexsym(_CMN::TVec2f(0, 0), _symgen.sym_Kurs_scale);
	_pRender.PopMatrix();
	_pInterface->drawTexsym(_CMN::TVec2f(_x_c, _y_c), _symgen.sym_Kurs_KUR);
	_pInterface->disableTexsym();
}

/*****************************************************************************/
/*отрисовка заданного индекса*/
void cls_plt_kurs::indexZad(float Course_giv)
{
	float par_grad = Course_giv - _tekKurs;
	_CMN::TCol3f color = MAGENTA;

	_pInterface->enableTexsym();
	_pRender.PushMatrix();
	_pRender.Translatef(_x_c, _y_c, -1);
	_pRender.Rotatef(par_grad, 0, 0, -1);
	_pRender.Translatef(0, _rad, -1);
	_pRender.Color3fv(color);
	_pInterface->drawTexsym(_CMN::TVec2f(0, 0), _symgen.sym_kurs_zad);
	_pRender.PopMatrix();
	_pInterface->disableTexsym();
}

/*****************************************************************************/
/*отрисовка индекса заданного ПУ*/
void cls_plt_kurs::indexZadPU(float Course_giv_track)
{
	float par_grad = Course_giv_track - _tekKurs;
	_CMN::TTexsym *sym_up = _symgen.sym_kurs_zadPU_plan_up.texsym;
	_CMN::TTexsym *sym_down = _symgen.sym_kurs_zadPU_plan_down.texsym;
	float rad_dop = _rad - 5;

	//Рисуем шкалу в виде тексутры и вращаем ее
	_pInterface->enableTexsym();
	_pRender.PushMatrix();
	_pRender.Translatef(_x_c, _y_c, -1);
	_pRender.Rotatef(par_grad, 0, 0, -1);
	_pRender.Translatef(0, 0, -1);
	_pRender.Color3fv(MAGENTA);
	_pInterface->drawTexsym(_CMN::TVec2f(0, rad_dop), sym_up);
	_pRender.Color3fv(MAGENTA);
	_pInterface->drawTexsym(_CMN::TVec2f(0, -rad_dop), sym_down);
	_pRender.PopMatrix();
	_pInterface->disableTexsym();

}

/*****************************************************************************/
/*отрисовка указателя угла сноса (ФПУ)*/
void cls_plt_kurs::indexDriftAngle(float TrackAngle)
{
	float par_grad = TrackAngle - _tekKurs;

	//Рисуем шкалу в виде тексутры и вращаем ее
	_pInterface->enableTexsym();
	_pRender.PushMatrix();
	_pRender.Translatef(_x_c, _y_c, -1);
	_pRender.Rotatef(par_grad, 0, 0, -1);
	_pRender.Translatef(0, _rad, 0);
	_pRender.Color3fv(GREEN);
	_pInterface->drawTexsym(_CMN::TVec2f(0, 0), _symgen.sym_index_fpu);
	_pRender.PopMatrix();
	_pInterface->disableTexsym();
}

/*****************************************************************************/
/*отрисовка стрелочного указатель пеленга РМ РСБН*/
void cls_plt_kurs::indexAzRsbn(float Az_rsbn)
{
	float par_grad = Az_rsbn - _tekKurs;
	float par_rad = _rad - 5;
	//Рисуем шкалу в виде тексутры и вращаем ее
	_pInterface->enableTexsym();
	_pRender.PushMatrix();
	_pRender.Translatef(_x_c, _y_c, -1);
	_pRender.Rotatef(par_grad, 0, 0, -1);
	_pRender.Color3fv(GREEN);
	_CMN::TVec2f center(0, par_rad);
	_pInterface->drawTexsym(center, _symgen.sym_index_pelengRm_up);
	center.y = -par_rad;
	_pInterface->drawTexsym(center, _symgen.sym_index_pelengRm_down);
	_pRender.PopMatrix();
	_pInterface->disableTexsym();
}


/*****************************************************************************/
/*отрисовка углового индекса*/
void cls_plt_kurs::indexAngle(float par_grad, _CMN::TCol3f color)
{
	float par_rad = _rad - 5;

	_pInterface->enableTexsym();
	_pRender.PushMatrix();
	_pRender.Translatef(_x_c, _y_c, -1);
	_pRender.Rotatef(par_grad, 0, 0, -1);
	_pRender.Color3fv(color);
	_CMN::TVec2f center(0, par_rad);
	_pInterface->drawTexsym(center, _symgen.sym_kurs_index_up);
	center.y = -par_rad;
	_pInterface->drawTexsym(center, _symgen.sym_kurs_index_down);
	_pRender.PopMatrix();
	_pInterface->disableTexsym();
}

/*****************************************************************************/
/*отрисовка текущего индекса*/
void cls_plt_kurs::indexTek(void)
{
	float dx1 = 62;
	float dx2 = 20;
	float dy1 = 42;
	float dy2 = 10;

	_CMN::TVec2f v[8];
	Tfloat x0 = _x_c;
	Tfloat y0 = _y_c + _rad;

	v[0].x = x0;
	v[1].x = x0 - dx2 / 2;
	v[2].x = x0 - dx1 / 2;
	v[3].x = x0 - dx1 / 2;
	v[4].x = x0 + dx1 / 2;
	v[5].x = x0 + dx1 / 2;
	v[6].x = x0 + dx2 / 2;
	v[7].x = x0;

	v[0].y = y0;
	v[1].y = y0 + dy2;
	v[2].y = y0 + dy2;
	v[3].y = y0 + dy1;
	v[4].y = y0 + dy1;
	v[5].y = y0 + dy2;
	v[6].y = y0 + dy2;
	v[7].y = y0;

	_CMN::TRect2f rect(v[3].x, v[3].y, v[5].x, v[5].y);

	_pRender.Color3fv(WHITE);
	_pInterface->enableTexsym();
	_pInterface->drawTexsym(_CMN::TVec2f(x0, y0), _symgen.sym_ramka_kurs);
	_pInterface->disableTexsym();

	auto *pFont = _pRender.getFont(_CMN::Font_mono32);
	if (!pFont)
		return;

	_pRender.Color3fv(WHITE);
		char str[8];
		sprintf(str, "%03d", _CMN::round_(_tekKurs));
		float x_s1 = pFont->getCharWidth(' ')*strlen(str) / 2; //сдвиг относительно центра
		float x = _x_c - x_s1;
		float y = y0 + 10;
		pFont->begin();
		if (_CMN::round_(_tekKurs) == 360)
			pFont->drawText(x, y, -0.9f, "000");
		else
			pFont->drawText(x, y, -0.9f, str);
		pFont->end();
}

/*****************************************************************************/
/*установка параметров для шкалы отклонений*/
void cls_plt_kurs::setParamOtkl(void)
{
	_max_par = 256;
	_max_length_gor = _symgen.sym_otklon_scale_new.texsym->width;
	_max_length_vert = _symgen.sym_otklon_scale_new.texsym->height;
}

/*****************************************************************************/
/*отрисовка шкалы отклонений*/
void cls_plt_kurs::scaleOtkl(void)
{
	_pInterface->enableTexsym();
	_pRender.Color3fv(WHITE);
	_pInterface->drawTexsym(_CMN::TVec2f(_x_c-0.1f, _y_c-0.6f), _symgen.sym_otklon_scale_new);
	_pInterface->disableTexsym();
}

/*****************************************************************************/
/*отрисовка горизонтального индекса отклонений*/
void cls_plt_kurs::indexOtklGor(float par_otkl_gor)
{
	float par = _CMN::clamp_(par_otkl_gor, -_max_par, _max_par);
	float koef = plt_kurs.getKoeffGor();
	float dy = 2;
	float par_tmp = par*koef;

	_pRender.Color3fv(WHITE);
	_CMN::TRect2f rect;
	rect.x_l = _x_c-_max_length_gor / 2;
	rect.y_b = _y_c+par_tmp - dy;

	rect.x_r = _x_c+_max_length_gor / 2;
	rect.y_t = _y_c+par_tmp + dy;
	_pInterface->drawBar(rect);
}

/*****************************************************************************/
/*отрисовка вертикального индекса отклонений*/
void cls_plt_kurs::indexOtklVert(float par_otkl_vert)
{
	float par = _CMN::clamp_(par_otkl_vert, -_max_par, _max_par);
	float koef = plt_kurs.getKoeffVert();
	float dx = 2;
	float par_tmp = par*koef;

	_pRender.Color3fv(WHITE);
	_CMN::TRect2f rect;
	rect.x_l =_x_c+par_tmp-dx;
	rect.y_b =_y_c-_max_length_gor/2;

	rect.x_r =_x_c+par_tmp+dx;
	rect.y_t =_y_c+_max_length_gor/2;
	_pInterface->drawBar(rect);
}

/*расчет вертикального коэффициента шкалы отклонений*/
/*****************************************************************************/
float cls_plt_kurs::getKoeffVert(void)
{
	return _max_length_vert / (_max_par*2);
}

/*расчет горизонтального коэффициента шкалы отклонений*/
/*****************************************************************************/
float cls_plt_kurs::getKoeffGor(void)
{
	return _max_length_gor / (_max_par*2);
}

/*****************************************************************************/
/*установка коэффициента шкалы*/
void cls_plt_kurs::setKurs(float M_cur, float True_cur, bool _pr_M)
{
	if (_pr_M)
	{
		_tekKurs = M_cur;
	}
	else
	{
		_tekKurs = True_cur;
	}
}



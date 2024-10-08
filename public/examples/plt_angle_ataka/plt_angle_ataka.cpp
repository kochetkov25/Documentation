/*
** File : plt_angle_ataka.cpp
** Authors :
** Created on :
** Modified on :
** Description : plt_angle_ataka
*/

#include "plt_angle_ataka.h"

cls_plt_angle_ataka plt_angle_ataka;

/*****************************************************************************/
/*конструктор по умолчанию*/
cls_plt_angle_ataka::cls_plt_angle_ataka()
{
	_x_c = 0;
	_y_c = 0;
	_rad = 0;
}

/*инициализаци€ объектов дл€ формировани€ изображени€ в OpenGL
и последующей отрисовки*/
bool cls_plt_angle_ataka::init(){
	if (_init){
		/*инициализаци€ интерфейса*/
		_pInterface = _pRender.getInterface();
		/*инициализаци€ текстур*/
		if (!_pInterface)
			return false;
		_pInterface->readSymgen(_symgen, "./files/dat/yakPil152.dat");
		/*установка параметров отрисовки*/
		_pRender.BlendFunc(_CMN::TRender::SRC_ALPHA,
			_CMN::TRender::ONE_MINUS_SRC_ALPHA);
		_pRender.TexEnvMode(_CMN::TRender::MODULATE);
		/*инициализаци€ шрифта*/
		_pRender.initFonts("./files/fonts/");
		/*инициализаци€ полей дл€ корректной отрисовки*/
		plt_angle_ataka.initCommon();
		_init = 0;
	}
}

/*инициализаци€ полей класса дл€ корректной отрисовки*/
void cls_plt_angle_ataka::initCommon(){
	/*задание смещени€ дл€ корректной отрисовки*/
	_rad = 210;
	/*минимальное значение шкалы*/
	_par_min = -10;
	/*максимальное значение шкалы*/
	_par_max = 20;
}

/*****************************************************************************/
/*установка начальных параметров*/
void cls_plt_angle_ataka::setXY(float x_c, float y_c)
{
	_x_c = x_c;
	_y_c = y_c;

	/*центр дл€ отрисовки дуги*/
	_x_c_arc = x_c + 215;
	/*центр дл€ отрисовки стрелки*/
	_x_c_index = x_c + 215;
}

/*****************************************************************************/
/*отрисовка шкалы в виде текстуры*/
void cls_plt_angle_ataka::scale(void)
{
	_pInterface->enableTexsym();
	_pRender.Color3fv(WHITE);
	_CMN::TVec2f center(_x_c, _y_c);
	_pInterface->drawTexsym(center, _symgen.sym_AngelAtak_scale);
	_pInterface->disableTexsym();
}

/*****************************************************************************/
/*отрисовка стрелки в виде текстуры*/
void cls_plt_angle_ataka::index(float Angle_attak)
{

	float par = Angle_attak;
	par = _CMN::clamp_(par, _par_min, _par_max);

	float par_grad = 90 - par*getKoef();

	_pInterface->enableTexsym();
	_pRender.PushMatrix();
	_pRender.Translatef(_x_c_index, _y_c, -1);
	_pRender.Rotatef(par_grad, 0, 0, 1);
	_pRender.Translatef(0, _rad, 0);
	_pRender.Color3fv(WHITE);
	_pInterface->drawTexsym(_CMN::TVec2f(0, 0), _symgen.sym_AngelAtak_index);
	_pRender.PopMatrix();
	_pInterface->disableTexsym();
}

/*****************************************************************************/
/*отрисовка сектора критических углов атаки*/
void cls_plt_angle_ataka::AngleAttakCritical(float Angle_attak_max)
{

	float par = Angle_attak_max;
	if (par >= _par_max)
		return;

	float ang_end_gr = 180 - par*getKoefArc() + 0.2;
	float ang_stt_gr = 180 - _par_max*getKoefArc() + 0.2;

	_pRender.LineWidth(2);
	_pInterface->enableLineSmooth();
	_pRender.Color3fv(RED);
	_CMN::TVec2f center(_x_c_arc, _y_c + 3);
	_pInterface->drawArc_tex(center, ang_stt_gr, ang_end_gr, _rad - 1, 16);
	_pInterface->disableLineSmooth();
}

/*****************************************************************************/
/*отрисовка символа альфа*/
void cls_plt_angle_ataka::AngleAttakSym()
{
	float x = _x_c + 40;
	float y = _y_c + 180;

	_pInterface->enableTexsym();
	_pRender.Color3fv(WHITE);
	_pInterface->drawTexsym(_CMN::TVec2f(x, y), _symgen.sym_alfa_new);
	_pInterface->disableTexsym();
}

/*****************************************************************************/
/*отрисовка текстового индекса*/
void cls_plt_angle_ataka::indexT(ELocation loc, float Angle_attak)
{

	char str[8];
	float x = _x_c + 30;
	float y = _y_c - 135;

	if (loc == _e_Up)
	{

		x = _x_c + 125;
		y = _y_c + 175;
	}
	auto *pFont = _pRender.getFont(_CMN::Font_mono24);

	if (!pFont)
		return;
	_pRender.Color3fv(WHITE);
	if (pFont)
	{

		pFont->begin();
		sprintf(str, "%d", _CMN::round_(Angle_attak));
		pFont->drawText(x, y, -1, str);
		pFont->end();
	}
}

/*****************************************************************************/
/*расчет коэффициента движени€ дл€ стрелки*/
float cls_plt_angle_ataka::getKoef(void)
{

	return 92.f / 30.f;
}

/*****************************************************************************/
/*расчет коэффициента движени€ дл€ дуг*/
float cls_plt_angle_ataka::getKoefArc(void)
{

	return 92.f / 30.f;
}

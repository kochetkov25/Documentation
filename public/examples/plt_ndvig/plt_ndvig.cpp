/*
**  File        :   plt_ndvig.cpp
**  Authors     :   
**  Created on  :   
**  Modified on :   
**  Description :	plt_ndvig
*/

#include "plt_ndvig.h";

cls_plt_ndvig  	plt_ndvig;

/*****************************************************************************/
/*конструктор по умолчанию*/
cls_plt_ndvig::cls_plt_ndvig()
{
	_x_c = 0;
	_y_c = 0;
	_length = 0;
}

/*инициализация объектов для формирования изображения в OpenGL
и последующей отрисовки*/
bool cls_plt_ndvig::init(){
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
		plt_ndvig.initCommon();
		_init = 0;
	}
}

/*инициализация полей класса для корректной отрисовки*/
void cls_plt_ndvig::initCommon(){
	/*задание смещения для корректной отрисовки*/
	_length = 210;
	/*максимальное значение шкалы*/
	_max_par = 100;
	/*минимальное значени шкалы*/
	_min_par = 0;
}

/*****************************************************************************/
/*установка начальных параметров*/
void cls_plt_ndvig::setXY(float x_c,float y_c)
{
	_x_c = x_c;
	_y_c = y_c;
}

/*****************************************************************************/
/*отрисовка шкалы в виде текстуры*/
void cls_plt_ndvig::scale()
{
	_pInterface->enableTexsym();
	_pRender.Color3fv(WHITE);
	_pInterface->drawTexsym(_CMN::TVec2f(_x_c, _y_c), _symgen.sym_Ndvig_scale);
	_pInterface->disableTexsym();
}

/*****************************************************************************/
/*отрисовка индекса-ограничителя максимально допустимых оборотов винта в виде текстуры*/
void cls_plt_ndvig::indexLimit(float PropRevLim)
{
	int par = 0;
	if (PropRevLim == 0)
		par = 25;
	else if (PropRevLim == 1)
		par = 40;
	else if (PropRevLim == 2)
		par = 60;

	float koef_par = getKoef();
	float y = _y_c + par*koef_par - 4;
	float x = _x_c + 6;

	_pInterface->enableTexsym();
	_pRender.Color3fv(RED);
	_pInterface->drawTexsym(_CMN::TVec2f(x, y), _symgen.sym_lim_gor);
	_pInterface->disableTexsym();
}

/*****************************************************************************/
/*отрисовка индекса*/
void cls_plt_ndvig::index(float PropRev)
{
	float dx = 12;
	float x = _x_c + 5;
	float y = _y_c;

	float koef_par = getKoef();
	float par = PropRev;

	par = _CMN::clamp_(par, _min_par, _max_par);

	float dy = par*koef_par;

	_pRender.Color3fv(LIGHTGRAY2);
	_CMN::TVec2f center(x, y + dy - dy);
	_pInterface->drawBar(_CMN::TRect2f(center, dx, dy));
}

/*****************************************************************************/
/*отрисовка текстового индекса*/
void cls_plt_ndvig::indexT(float PropRev)
{
	float dx = 45;
	float dy = 30;
	float x = _x_c - dx / 2 + 10;
	float y = _y_c + 215;

	_pRender.Color3fv(WHITE);
	_pInterface->enableLineSmooth();
	_CMN::TVec2f center(x, y);
	_pInterface->drawRectOval_tex(_CMN::TRect2f(center, dx, dy), 2, 4);
	_pInterface->disableLineSmooth();

	char str[8];
	auto *pFont = _pRender.getFont(_CMN::Font_mono24);
	if (!pFont)
		return;
	int sizeMono = pFont->getCharWidth('M');


	_pRender.Color3fv(GRAY2);

	pFont->begin();
	_pRender.Color3fv(WHITE);
	pFont->drawText(x - sizeMono, y, -1, "n");

	float par = PropRev;
	par = _CMN::clamp_(par, 0.f, 100.f);
	sprintf(str, "%3d", _CMN::round_(par));
	pFont->drawText(x + 1, y, -1, str);

	_pRender.Color3fv(GRAY2);
	pFont->drawText(x + dx + 2, y, -1, "%");
	pFont->end();
}

/*****************************************************************************/
/*расчет коэффициента шкалы в зависимости от диапазона*/
float cls_plt_ndvig::getKoef(void)
{
	return _length / 100.f;
}
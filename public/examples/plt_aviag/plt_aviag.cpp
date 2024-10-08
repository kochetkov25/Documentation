/*
**  File        :   plt_aviag.cpp
**  Authors     :   
**  Created on  :   
**  Modified on :   
**  Description :	plt_aviag
*/


#include "plt_aviag.h"

cls_plt_aviag 	plt_aviag;

/******************************************************************************/
/*конструктор по умолчанию*/
cls_plt_aviag::cls_plt_aviag()
{
	_x_c = 0;
	_y_c = 0;
	_rad = 0;
}

/*инициализация объектов для формирования изображения в OpenGL
и последующей отрисовки*/
bool cls_plt_aviag::init(){
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
		plt_aviag.initCommon();
		_init = 0;
	}
}

/*инициализация полей класса для корректной отрисовки*/
void cls_plt_aviag::initCommon(){
	/*задание смещения для корректной отрисовки*/
	_rad = 188;
}

/******************************************************************************/
/*установка координат центра фрагмента*/
void cls_plt_aviag::setXY(float x_c, float y_c)
{
	_x_c = x_c;
	_y_c = y_c;
}


/******************************************************************************/
short Nhigher(short x, short y)
{
	short k = x / y;
	if (x%y == 0 || x<0)
		return k = k - 1;
	return k;
}

short Na10_180(short a)
{
	a = (3600 + a) % 3600;
	if (a>1800) return a - 3600;
	return a;
}
/*отрисовка шкалы тангажа в виде текстуры*/
void cls_plt_aviag::scaleTang(float par_Tang_Tek)
{
	par_Tang_Tek = _CMN::clamp_(par_Tang_Tek, -90.f, 90.f);

	float delta = 25;
	float	anglen_2 = 320; // половинный размер шкалы в градусах помноженных на 10
	float	anglen_2_pks = _rad - 10; // половинный размер шкалы в пкс
	float	dy = anglen_2_pks / 6.f / 2;  //шаг между делениями пкс(5 градуса)
	float	dy1 = (float)(dy / 2.5 / 10.); // 1 градус шкалы 
	float   pitch_curr = (float)Na10_180(round(-par_Tang_Tek * 10));
	float	L1 = 30;	//10 гр длина рисок
	float	L2 = 20;	//5 гр длина рисок
	float	L3 = _rad;	//10 гр длина рисок
	float	L4 = 10;	//10 гр длина рисок
	float	L;
	float	p0 = (float)(Nhigher(pitch_curr + anglen_2, delta)*delta);
	float	y;
	float x_arr[10];
	float y_arr[10];
	char str[10][10];
	int t = 0;

	float size_blue = 0;
	float size_brown = 0;
	double koef_a = anglen_2_pks / 30.f;
	float y_zero = par_Tang_Tek * koef_a;
	if (y_zero > _rad)
		y_zero = _rad;
	if (y_zero<-_rad)
		y_zero = -_rad;
	if (y_zero >= 0)
	{
		size_blue = _rad + abs(y_zero);
		size_brown = _rad - abs(y_zero);
	}
	if (y_zero<0)
	{
		size_blue = _rad - abs(y_zero);
		size_brown = _rad + abs(y_zero);
	}

	_pRender.Color3fv(BLUE);
	_pInterface->setZ(-1.0f);

	_pInterface->drawBar(_CMN::TRect2f(
		_CMN::TVec2f(_x_c - _rad, _y_c + _rad - size_blue),
		2 * _rad,
		size_blue));

	_pRender.Color3fv(BROWN);
	_pInterface->setZ(-1.0f);
	_pInterface->drawBar(_CMN::TRect2f(
		_CMN::TVec2f(_x_c - _rad, _y_c - y_zero - size_brown),
		2 * _rad, size_brown));

	y = (float)(-(p0 - pitch_curr)*dy1);

	_pRender.LineWidth(3);
	_pInterface->beginLine2d_cycle();
	_pInterface->setZ(-0.8f);
	_pRender.Color3fv(WHITE);
	for (float pitch = p0; pitch>(p0 - 2 * anglen_2 + 20); y += dy, pitch -= delta)
	{
		short p = abs(Na10_180(pitch)) / 10.;

		if (p % 10 == 0 && p != 0)
		{
			L = L1;
			if (abs(p) >= 100)
				p = 180 - p;

			sprintf(str[t], "%d", p);
			x_arr[t] = _x_c;
			y_arr[t] = _y_c + y - 10;
			t++;
			float xl = (float)(_x_c - 20 - L);
			float yl = (float)(_y_c + y);
			float xr = (float)(_x_c - 20);
			float yr = (float)(_y_c + y);
			_pInterface->drawLine2d_cycle(_CMN::TVec2f(xl, yl), _CMN::TVec2f(xr, yr));
			xl = (float)(_x_c + 20);
			yl = (float)(_y_c + y);
			xr = (float)(_x_c + 20 + L);
			yr = (float)(_y_c + y);
			_pInterface->drawLine2d_cycle(_CMN::TVec2f(xl, yl), _CMN::TVec2f(xr, yr));
		}
		else if (p % 5 == 0 && p % 10 != 0 && p != 0)
		{
			L = L2;
			float xl = (float)(_x_c - L);
			float yl = (float)(_y_c + y);
			float xr = (float)(_x_c + L);
			float yr = (float)(_y_c + y);
			_pInterface->drawLine2d_cycle(_CMN::TVec2f(xl, yl), _CMN::TVec2f(xr, yr));
		}
		else if (p == 0)
		{
			L = L3;
		}
		else if (p == 2)
		{
			L = L4;
			float xl = (float)(_x_c - L);
			float yl = (float)(_y_c + y);
			float xr = (float)(_x_c + L);
			float yr = (float)(_y_c + y);
			_pInterface->drawLine2d_cycle(_CMN::TVec2f(xl, yl), _CMN::TVec2f(xr, yr));
		}
		else
			L = 0;
	}
	_pInterface->endLine2d_cycle();

	auto *pFont = _pRender.getFont(_CMN::Font_mono26);
	_pRender.Color3fv(WHITE);
	if (pFont)
	{
		pFont->begin();
		for (int i = 0; i < t; i++)
		{
			char strForDraw[4];
			std::string str_tmp = str[i];
			sprintf(strForDraw, "%c", str_tmp[0]);
			pFont->drawText(x_arr[i] - 20, y_arr[i] - 5, -0.8f, strForDraw);
			sprintf(strForDraw, "%c", str_tmp[1]);
			pFont->drawText(x_arr[i] - 20 + 22, y_arr[i] - 5, -0.8f, strForDraw);
		}
		pFont->end();
	}

	_pInterface->enableTexsym();
	_pRender.Color3fv(BLACK);
	_pInterface->drawTexsym(_CMN::TVec2f(_x_c, _y_c), _symgen.sym_maska);
	_pInterface->disableTexsym();

	_pInterface->enableLineSmooth();
	_pInterface->drawCircleLine_tex(_x_c, _y_c, _rad - 4, 2);
	_pInterface->disableLineSmooth();

	_pInterface->drawBar(_CMN::TRect2f(
		_CMN::TVec2f(_x_c - _rad / 2, _y_c - _rad - 40),
		_rad, 40));
}

/******************************************************************************/
/*отрисовка индекса летательного аппарата*/
void cls_plt_aviag::indexLA(float par_grad)
{
	_pRender.Color3fv(YELLOW3);
	_pInterface->enableTexsym();
	_pRender.PushMatrix();
	_pRender.Translatef(_x_c, _y_c, -1);
	_pRender.Rotatef(par_grad, 0, 0, -1);
	_pInterface->drawTexsym(_CMN::TVec2f(0, 0), _symgen.sym_SymbLA_new);
	_pRender.PopMatrix();
	_pInterface->disableTexsym();
}


/******************************************************************************/
/*отрисовка шкалы крена*/
void cls_plt_aviag::scaleKren(void)
{
	_pInterface->enableTexsym();
	_pRender.Color3fv(WHITE);
	_pInterface->drawTexsym(_CMN::TVec2f(_x_c, _y_c), _symgen.sym_kren_scale);
	_pInterface->disableTexsym();

	_pInterface->enableLineSmooth();
	_pRender.Color3fv(BLACK);
	_pInterface->drawCircleLine_tex(_x_c, _y_c, 368 / 2, 4);
	_pInterface->disableLineSmooth();

}

/******************************************************************************/
/*отрисовка положения шасси в виде текстуры*/
void cls_plt_aviag::chassi(float par_grad, bool ChassisLeftOn, bool ChassisRightOn, bool ChassisFrontOn)
{
	float x_sdvig = 53;
	float y_sdvig = 20;

	_pInterface->enableTexsym();
	_pRender.PushMatrix();
	_pRender.Translatef(_x_c, _y_c, -1);
	_pRender.Rotatef(par_grad, 0, 0, -1);
	_pRender.Translatef(_x_c - x_sdvig, -y_sdvig, -1);
	_pRender.Color3fv(WHITE);
	if (ChassisLeftOn)
		_pInterface->drawTexsym(_CMN::TVec2f(0, 0), _symgen.sym_sym_shassi_new_max);

	_pRender.Translatef(_x_c + x_sdvig, 0, -1);
	if (ChassisRightOn)
		_pInterface->drawTexsym(_CMN::TVec2f(0, 0), _symgen.sym_sym_shassi_new_min);

	_pRender.Translatef(_x_c + x_sdvig, 0, -1);
	if (ChassisFrontOn)
		_pInterface->drawTexsym(_CMN::TVec2f(0, 0), _symgen.sym_sym_shassi_new_max);

	_pRender.PopMatrix();
	_pInterface->disableTexsym();
}

/******************************************************************************/
/*отрисовка положения закрылок в виде текстуры*/
void cls_plt_aviag::flaps(float Flaps_position, float par_grad)
{
	if (!Flaps_position)
		return;


	float dx = 48;
	float dy = 8;
	float sdvig_x = 70;

	float x_l = _x_c - sdvig_x - dx;
	float x_r = _x_c + sdvig_x + 4;
	float y = -10;
	float y2 = y - dy - 3;

	_pInterface->enableTexsym();

	if (Flaps_position >= 2)
	{
		_pRender.PushMatrix();
		_pRender.Translatef(_x_c, _y_c, -1);
		_pRender.Rotatef(par_grad, 0, 0, -1);
		_pRender.Translatef(x_l, y2, -1);
		_pRender.Color3fv(WHITE);
		_pInterface->drawTexsym(_CMN::TVec2f(0, 0), _symgen.sym_flap);
		_pRender.PopMatrix();

		_pRender.PushMatrix();
		_pRender.Translatef(_x_c, _y_c, -1);
		_pRender.Rotatef(par_grad, 0, 0, -1);
		_pRender.Translatef(x_r, y2, -1);
		_pRender.Color3fv(WHITE);
		_pInterface->drawTexsym(_CMN::TVec2f(0, 0), _symgen.sym_flap);
		_pRender.PopMatrix();
	}
	if (Flaps_position >= 1)
	{
		_pRender.PushMatrix();
		_pRender.Translatef(_x_c, _y_c, -1);
		_pRender.Rotatef(par_grad, 0, 0, -1);
		_pRender.Translatef(x_l, y, -1);
		_pRender.Color3fv(WHITE);
		_pInterface->drawTexsym(_CMN::TVec2f(0, 0), _symgen.sym_flap);
		_pRender.PopMatrix();

		_pRender.PushMatrix();
		_pRender.Translatef(_x_c, _y_c, -1);
		_pRender.Rotatef(par_grad, 0, 0, -1);
		_pRender.Translatef(x_r, y, -1);
		_pRender.Color3fv(WHITE);
		_pInterface->drawTexsym(_CMN::TVec2f(0, 0), _symgen.sym_flap);
		_pRender.PopMatrix();
	}


	_pInterface->disableTexsym();
}

/******************************************************************************/
/*отрисовка вертикальной директорной планки*/
void cls_plt_aviag::dirPlankaVert(float Dk)
{
	float delta = 80;
	float line = 180;
	_CMN::TVec2f v1, v2;
	v1.x = 0;
	v2.x = 0;
	v1.y = delta;
	v2.y = v1.y + line;

	float par_vert = Dk * 100;
	float width_scale2 = 23; //половина шкалы в градусах
	float max_par = 100;//макс значение
	float koef_par = width_scale2 / max_par;
	float angle = par_vert*koef_par;
	angle = _CMN::clamp_(angle, -23.f, 23.f);
	float x = _x_c;
	float y = _y_c - _rad;

	_pInterface->enableLineSmooth();
	_pRender.PushMatrix();
	_pRender.Translatef(x, y, 0);
	_pRender.Rotatef(angle, 0, 0, -1);
	_pRender.Color3fv(BLACK);
	_pInterface->drawLine2d_tex(v1, v2, 6);
	_pRender.Color3fv(MAGENTA);
	_pInterface->drawLine2d_tex(v1, v2, 4);
	_pRender.PopMatrix();
	_pInterface->disableLineSmooth();

}

/******************************************************************************/
/*отрисовка горизонтальной директорной планки*/
void cls_plt_aviag::dirPlankaHor(float Dt)
{
	float line = 180;
	_CMN::TVec2f v1, v2;
	float par = Dt * 100;
	float max_par = 100;
	float height_2 = (2.f*_rad / 3.f); //диапазон полшкалы в пикселах
	float koef_par = height_2 / max_par;
	float y = par*koef_par;
	if (y >= 0)
		y = _CMN::clamp_(y, 0.f, height_2);
	if (y < 0)
		y = _CMN::clamp_(y, -height_2, 0.f);


	v1.x = _x_c - line / 2;
	v2.x = _x_c + line / 2;
	v1.y = _y_c + y;
	v2.y = _y_c + y;

	_pInterface->enableLineSmooth();
	_pRender.Color3fv(BLACK);
	_pInterface->drawLine2d_tex(v1, v2, 6);
	_pRender.Color3fv(MAGENTA);
	_pInterface->drawLine2d_tex(v1, v2, 4);
	_pInterface->disableLineSmooth();
}

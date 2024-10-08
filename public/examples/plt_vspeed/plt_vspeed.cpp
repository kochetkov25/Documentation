/*
**  File        :   plt_vspeed.cpp
**  Authors     :   
**  Created on  :   
**  Modified on :   
**  Description :   plt_vspeed
*/

#include "plt_vspeed.h"

cls_plt_vspeed  plt_vspeed;

/*****************************************************************************/
/*����������� �� ���������*/
cls_plt_vspeed::cls_plt_vspeed()
{
	_x_c = 0;
	_y_c = 0;
}

/*������������� �������� ��� ������������ ����������� � OpenGL
� ����������� ���������*/
bool cls_plt_vspeed::init(){
	if (_init){
		/*������������� ����������*/
		_pInterface = _pRender.getInterface();
		/*������������� �������*/
		if (!_pInterface)
			return false;
		_pInterface->readSymgen(_symgen, "./files/dat/yakPil152.dat");
		/*��������� ���������� ���������*/
		_pRender.BlendFunc(_CMN::TRender::SRC_ALPHA,
			_CMN::TRender::ONE_MINUS_SRC_ALPHA);
		_pRender.TexEnvMode(_CMN::TRender::MODULATE);
		/*������������� ������*/
		_pRender.initFonts("./files/fonts/");
		/*������������� ����� ��� ���������� ���������*/
		plt_vspeed.initCommon();
		_init = 0;
	}
}

/*������������� ����� ������ ��� ���������� ���������*/
void cls_plt_vspeed::initCommon(){
	/*������������ �������� �����*/
	_par_max = 15;
	/*����������� �������� �����*/
	_par_min = -15;
}

/*****************************************************************************/
/*��������� ��������� ����������*/
void cls_plt_vspeed::setXY(float x_c, float y_c)
{
	_x_c = x_c;
	_y_c = y_c;
}

/*****************************************************************************/
/*��������� ����� � ���� ��������*/
void cls_plt_vspeed::scale()
{
	//������ ����� � ���� ��������
	_pInterface->enableTexsym();
	_pRender.Color3fv(WHITE);
	_pInterface->drawTexsym(_CMN::TVec2f(_x_c, _y_c), _symgen.sym_Vvert_scale);
	_pInterface->disableTexsym();

	auto pFont = _pRender.getFont(_CMN::Font_mono24);
	if (!pFont)
		return;
	pFont->begin();
	_pRender.Color3fv(LIGHTGRAY3);
	pFont->drawText(_x_c + 95.f, _y_c - 10.f, -0.9f, "�/�");
	pFont->end();
}

/*****************************************************************************/
/*��������� ������� � ���� ��������*/
void cls_plt_vspeed::index(float Vvert)
{
	float par = Vvert;
	/*198 - �������� ��-�� ����,��� ������ �������� ����� �������� ����� �� 
	��������� 0*/
	float x = _x_c+198;
	float y = _y_c;

	if (par > _par_max)
		par = _par_max;
	if (par < _par_min)
		par = _par_min;

	float par_grad = 90 - par*getKoef();
	/*118 - �������� ��� ��������� �������*/
	float rad = 118;

	//������ ����� � ���� ��������
	_pInterface->enableTexsym();
	_pRender.PushMatrix();
	_pRender.Translatef(x, y, -1);
	_pRender.Rotatef(par_grad, 0, 0, 1);
	_pRender.Translatef(0, rad, 0);
	_pRender.Color3fv(WHITE);
	_pInterface->drawTexsym(_CMN::TVec2f(0, 0), _symgen.sym_Vvert_index);
	_pRender.PopMatrix();
	_pInterface->disableTexsym();
}

/*****************************************************************************/
/*��������� ���������� �������*/
void cls_plt_vspeed::indexT(float Vvert)
{
	float par = Vvert;
	char str[8];
	float x = _x_c + 78;
	float y_u = _y_c + 20;
	float y_d = _y_c - 45;
	float y = 0;

	par = _CMN::clamp_(par, -100.f, 100.f);



	if (par >= -10 && par <= 10)
		return;
	if (par>10)
		y = y_u;
	if (par<-10)
		y = y_d;

	auto *pFont = _pRender.getFont(_CMN::Font_mono24);
	if (!pFont)
		return;

	sprintf(str, "%+d", _CMN::round_(par));
	float dx = strlen(str)*pFont->getCharWidth(' ') + 10;
	float dy = pFont->getCellHeight() + 5;
	/*�����*/
	_CMN::TRect2f rect{ x, y, x + dx, y + dy };
	_pInterface->enableLineSmooth();
	_pInterface->drawRectOval_tex(rect, 2, 4);
	_pInterface->disableLineSmooth();
	/*�����*/
	_pRender.Color3fv(WHITE);
	pFont->begin();
	pFont->drawText(x + 5, y, -1, str);
	pFont->end();
}

/*****************************************************************************/
/*������ ������������ ��������*/
float cls_plt_vspeed::getKoef(void)
{
	return 86.f / 30.f;
}
/*
**  File        :   plt_speed.cpp
**  Authors     :   
**  Created on  :   
**  Modified on :   
**  Description :	plt_speed
*/

#ifndef	_PLT_SPEED_H
#define	_PLT_SPEED_H

#include "lib_common/interface.h"
#include "lib_common/render.h"
#include "lib_common/render.h"
#include "lib_common/font.h"
#include "lib_common/math.h"
#include "lib_common/col.h"
#include "app/color.h"
#include "yakPil152.h"
#include <string>

class cls_plt_speed
{
public:
	/*����������� �� ���������*/
	cls_plt_speed();
	/* ��������� ������ ���������*/
	void setXY(float x_c, float y_c);
	/*��������� ����� � ���� ��������*/
	void scale(void);
	/*��������� ������� �������� ��������*/
	void indexVist(float Vist);
	/*��������� ������� ��������� ���������*/
	void indexVprib(float Vpr);
	/*��������� ���������� �������*/
	void indexT(float Vpr);
	/*��������� ������� ����������� ����������� ��������*/
	void indexVprMin(float Vpr_min);
	/*��������� ������� ����������� ������������ ��������*/
	void indexVprMax(float Vpr_max);
	/*��������� ������� ��������������� ��������*/
	void indexVprog(float Vpr_prog);
	/*������������� �������� ��� ������������ ����������� � OpenGL
	� ����������� ���������*/
	bool init(void);
	/*������������� ����� ������ ��� ���������� ���������*/
	void initCommon(void);
private:
	/*������ ������������ �����*/
	float getParam(float par);
	/*���������� x ������ ���������*/
	float _x_c;
	/*���������� y ������ ���������*/
	float _y_c;
	/*������ �����*/
	float _rad;
	const int _z = -1;
	/*���� ��� �������������*/
	int _init = 1;
	/*���������� ������� ������ TRender ��� ������������ ����������� � OpenGL*/
	_CMN::TRender _pRender;
	/*���������� ������� ������ TInterface ��� ��������� ����������� �������*/
	_CMN::TInterface *_pInterface;
	/*���������� ������� ������ TSymgen_yakPil152 ��� �������� �������*/
	TSymgen_yakPil152 _symgen;
};

#endif//_PLT_SPEED_H
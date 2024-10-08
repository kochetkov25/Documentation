/*
**  File        :   plt_aviag.h
**  Authors     :   
**  Created on  :   
**  Modified on :   
**  Description :	plt_aviag
*/

#ifndef HEADER_PLT_AVIAG_H_
#define HEADER_PLT_AVIAG_H_


#include "lib_common/interface.h"
#include "lib_common/render.h"
#include "lib_common/font.h"
#include "lib_common/math.h"
#include "lib_common/col.h"
#include "app/color.h"
#include "aviag_dat.h"
#include <string>

class cls_plt_aviag
{
public:
	/*����������� �� ���������*/
	cls_plt_aviag();
	/*��������� ����� �����*/
	void scaleKren(void);
	/*��������� ����� ������� � ���� ��������*/
	void scaleTang(float par_Tang_Tek);
	/*��������� ��������� ����� � ���� ��������*/
	void chassi(float par_grad, bool ChassisLeftOn, bool ChassisRightOn, bool ChassisFrontOn);
	/*��������� ��������� �������� � ���� ��������*/
	void flaps(float Flaps_position, float par_grad);
	/*��������� ������� ������������ �������� � ���� ��������*/
	void indexLA(float par_grad);
	/*��������� ����������*/
	void setXY(float x_c, float y_c);

	/*��������� ������������ ����������� ������*/
	void dirPlankaVert(float Dk);
	/*��������� �������������� ����������� ������*/
	void dirPlankaHor(float Dt);
	/*������������� �������� ��� ������������ ����������� � OpenGL
	� ����������� ���������*/
	bool init(void);
	/*������������� ����� ������ ��� ���������� ���������*/
	void initCommon(void);

private:
	/*���������� x ������ ���������*/
	float _x_c;
	/*���������� y ������ ���������*/
	float _y_c;
	/*������ ��������*/
	float _rad;
	const int _z = -1;
	/*���� ��� �������������*/
	int _init = 1;
	/*���������� ������� ������ TRender ��� ������������ ����������� � OpenGL*/
	_CMN::TRender _pRender;
	/*���������� ������� ������ TInterface ��� ��������� ����������� �������*/
	_CMN::TInterface *_pInterface;
	/*���������� ������� ������ TSymgen_yakPil152 ��� �������� �������*/
	aviag_dat _symgen;
};


#endif /* HEADER_PLT_PLT_AVIAG_H_ */

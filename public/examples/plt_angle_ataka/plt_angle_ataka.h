/*
** File : plt_angle_ataka.h
** Authors :
** Created on :
** Modified on :
** Description : plt_angle_ataka
*/

#ifndef HEADER_PLT_ANGLE_ATAKA_H_
#define HEADER_PLT_ANGLE_ATAKA_H_

#include "lib_common/interface.h"
#include "lib_common/render.h"
#include "lib_common/math.h"
#include "lib_common/font.h"
#include "lib_common/col.h"
#include "app/color.h"
#include "angle_ataka_dat.h"
#include <string>

class cls_plt_angle_ataka
{

public:

	enum ELocation{
		_e_Up, _e_Down
	};
	/*����������� �� ���������*/
	cls_plt_angle_ataka();
	/*��������� ��������� ������ ���������*/
	void setXY(float x_c, float y_c);
	/*��������� ����� � ���� ��������*/
	void scale(void);
	/*��������� ������� � ���� ��������*/
	void index(float Angle_attak);
	/*��������� ���������� �������*/
	void indexT(ELocation loc, float Angle_attak);
	/*��������� c������ ����������� ����� �����*/
	void AngleAttakCritical(float Angle_attak_max);
	/*��������� ������� �����*/
	void AngleAttakSym();
	/*������������� �������� ��� ������������ ����������� � OpenGL
	� ����������� ���������*/
	bool init(void);
	/*������������� ����� ������ ��� ���������� ���������*/
	void initCommon(void);

private:
	/*������ ������������ �������� ��� �������*/
	float getKoef(void);
	/*������ ������������ �������� ��� ����*/
	float getKoefArc(void);

	/*���������� x ������ ���������*/
	float _x_c;
	/*���������� y ������ ���������*/
	float _y_c;
	/*������ ��� ��������� �������*/
	float _rad;
	const int _z = -1;
	/*���� ��� �������������*/
	int _init = 1;
	/*������ ����������� �����*/
	float _par_min;
	/*������� ����������� �����*/
	float _par_max;
	/*����� ��� ��������� ��� ������� ����������� �����*/
	float _x_c_arc;
	/*����� ��� ��������� �������*/
	float _x_c_index;
	/*���������� ������� ������ TRender ��� ������������ ����������� � OpenGL*/
	_CMN::TRender _pRender;
	/*���������� ������� ������ TInterface ��� ��������� ����������� �������*/
	_CMN::TInterface *_pInterface;
	/*���������� ������� ������ TSymgen_yakPil152 ��� �������� �������*/
	angle_ataka_dat _symgen;
};

#endif /* HEADER_PLT_PLT_ANGLE_ATAKA_H_ */

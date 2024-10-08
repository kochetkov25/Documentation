/*
**  File        : plt_angle_ataka.h
**  Authors		:
**  Created on	:
**  Modified on :
**  Description : plt_angle_ataka
*/

#include "plt_angle_ataka.h"

extern cls_plt_angle_ataka plt_angle_ataka;
void drawAngle_ataka(void)
{
	/*��������� ��� ��������� ��������� ������� �� ���������. ��� �������
	��������� ������ �����������*/
	/*���������� x ������ ���������*/
	float x_c = 0;
	/*���������� y ������ ���������*/
	float y_c = 0;
	/*���� �����*/
	float angle_attak = 10;
	/*����������� ���������� ���� �����*/
	float angle_attak_max = 12;
	/*������������� �������� ��� ������������ ����������� � OpenGL �
	����������� ���������*/
	if (plt_angle_ataka.init()){
		/*��������� ������ ���������*/
		plt_angle_ataka.setXY(0, 0);
		/*��������� ������� ����������� ����� �����*/
		plt_angle_ataka.AngleAttakCritical(12);
		/*��������� ����� � ���� ��������*/
		plt_angle_ataka.scale();
		/*��������� ���������� �������*/
		plt_angle_ataka.indexT(cls_plt_angle_ataka::ELocation::_e_Up, 10);
		/*��������� ������� � ���� ��������*/
		plt_angle_ataka.index(10);
		/*��������� ������� ����� � ���� ��������*/
		plt_angle_ataka.AngleAttakSym();
	}
}

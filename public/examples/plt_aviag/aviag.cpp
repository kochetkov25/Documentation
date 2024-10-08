/*
**  File        : aviag.cpp
**  Authors		:
**  Created on	:
**  Modified on :
**  Description : aviag
*/

#include "plt_aviag.h"

extern cls_plt_aviag 	plt_aviag;
void drawAviag(void){
	/*��������� ��� ��������� ��������� ������� �� ���������. ��� �������
	��������� ������ �����������*/

	/*���������� x ������ ���������*/
	float x_c = 0;
	/*���������� y ������ ���������*/
	float y_c = 0;
	/*���� �������*/
	float par_Tang = 10;
	/*���� �����*/
	float par_Kren = 15;
	/*������� ��������*/
	float flap_position = 1;
	/*�������� �������������� ����������� ������.
	�������� � �������� -1 - 1*/
	float Dt = 0.1;
	/*�������� ������������ ����������� ������.
	�������� � �������� -1 - 1*/
	float Dk = -0.1;
	/*��������� ����� ������*/
	bool chassiRightOn = true;
	/*��������� ����� �����*/
	bool chassiLeftOn = true;
	/*��������� ������� ������ �����*/
	bool chassiFrontOn = true;
	/*������������� �������� ��� ������������ ����������� � OpenGL �
	����������� ���������*/
	if (plt_aviag.init()){
		/*��������� ������ ���������*/
		plt_aviag.setXY(x_c, y_c);
		/*��������� ����� ������� � ���� ��������*/
		plt_aviag.scaleTang(par_Tang);
		/*��������� ����� ����� � ���� ��������*/
		plt_aviag.scaleKren();
		/*��������� ������� ������������ ��������*/
		plt_aviag.indexLA(par_Kren);
		/*��������� �������� � ���� ��������*/
		plt_aviag.flaps(flap_position, par_Kren);
		/*��������� ����� � ���� ��������*/
		plt_aviag.chassi(par_Kren, chassiRightOn, chassiLeftOn, chassiFrontOn);
		/*��������� �������������� ����������� ������*/
		plt_aviag.dirPlankaHor(Dt);
		/*��������� ������������ ����������� ������*/
		plt_aviag.dirPlankaVert(Dk);
	}
}
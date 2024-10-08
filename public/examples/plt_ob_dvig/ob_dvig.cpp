/*
**  File        : ob_dvig.cpp
**  Authors		:
**  Created on	:
**  Modified on :
**  Description : ob_dvig
*/

#include "plt_ob_dvig.h"

extern cls_plt_ob_dvig  	plt_ob_dvig;
void drawOb_dvig(void){
	/*��������� ��� ��������� ��������� ������� �� ���������. ��� �������
	��������� ������ �����������*/

	/*���������� x ������ ���������*/
	float x_c = 0;
	/*���������� y ������ ���������*/
	float y_c = 0;
	/*��������� ���*/
	float pQ_PWL = 70;
	/*�������� ���������*/
	float power = 70;
	/*������������� �������� ��� ������������ ����������� � OpenGL �
	����������� ���������*/
	if (plt_ob_dvig.init()){
		/*��������� ������ ���������*/
		plt_ob_dvig.setXY(x_c, y_c);
		/*��������� ����� � ���� ��������*/
		plt_ob_dvig.scale();
		/*��������� �������� ����������� �������� �������� ���������*/
		plt_ob_dvig.indexLimit();
		/*��������� ��������� ��������� ���*/
		plt_ob_dvig.indexRud(pQ_PWL);
		/*��������� ���������� �������*/
		plt_ob_dvig.indexT(power);
		/*��������� ������� �������� � ���� ��������*/
		plt_ob_dvig.index(power);
	}
}
/*
**  File        : ndvig.cpp
**  Authors		:
**  Created on	:
**  Modified on :
**  Description : ndvig
*/

#include "plt_ndvig.h";

extern cls_plt_ndvig  	plt_ndvig;
void drawNdvig(void){
	/*��������� ��� ��������� ��������� ������� �� ���������. ��� �������
	��������� ������ �����������*/

	/*���������� x ������ ���������*/
	float x_c = 0;
	/*���������� y ������ ���������*/
	float y_c = 0;
	/*������� ���������*/
	float PropRev = 75;
	/*����������� ����������� ���������� �������. ��������� �������� 0, 1, 2.*/
	float PropRevLim = 2;
	/*������������� �������� ��� ������������ ����������� � OpenGL �
	����������� ���������*/
	if (plt_ndvig.init()){
		/*������� ������ ���������*/
		plt_ndvig.setXY(x_c, y_c);
		/*��������� ����� � ���� ��������*/
		plt_ndvig.scale();
		/*��������� ������� ��������*/
		plt_ndvig.index(PropRev);
		/*��������� ������� ������������ ���������� ��������*/
		plt_ndvig.indexLimit(PropRevLim);
		/*��������� ���������� �������*/
		plt_ndvig.indexT(PropRev);
	}
}
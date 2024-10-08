

#include "plt_kurs.h"
extern cls_plt_kurs  	plt_kurs;

void drawKurs(){
	/*��������� ��� ��������� ��������� ������� �� ���������. ��� �������
	��������� ������ �����������*/

	/*���������� x ������ ���������*/
	float x_c = 0;
	/*���������� y ������ ���������*/
	float y_c = 0;
	/*��������� ����*/
	float M_cur = 0;
	/*�������� ����*/
	float true_cur = 50;
	/*�������� ��� ������ �����*/
	bool pr_M = 0;
	/*������ �� ����*/
	float AzRsbn = 90;
	/*���� �����*/
	float TrackAngle = 30;
	/*�������� ����*/
	float CourseGiv = 60;
	/*�������� ������� ����*/
	float CourseGivTrack = 45;
	/*����*/
	float parGrad = -10;
	/*�������������� ����������*/
	float parOtklGor = -20;
	/*������������ ����������*/
	float parOtklVert = 40;
	/*����*/
	_CMN::TCol3f color = YELLOW;
	/*������������� �������� ��� ������������ ����������� � OpenGL �
	����������� ���������*/
	if (plt_kurs.init()){
		/*��������� ��������� ������ ���������*/
		plt_kurs.setXY(x_c, y_c);
		/*��������� ������������ �����*/
		plt_kurs.setKurs(M_cur, true_cur, pr_M);
		/*��������� �����*/
		plt_kurs.scale();
		/*��������� ����������� ��������� ������� �� ����*/
		plt_kurs.indexAzRsbn(AzRsbn);
		/*��������� ��������� ���� �����*/
		plt_kurs.indexDriftAngle(TrackAngle);
		/*��������� �������� �������*/
		plt_kurs.indexTek();
		/*��������� ��������� �������*/
		plt_kurs.indexZad(CourseGiv);
		/*������������������ ��*/
		plt_kurs.indexZadPU(CourseGivTrack);
		/*��������� �������� �������*/
		plt_kurs.indexAngle(parGrad, color);
		/*��������� ���������� ��� ����� ����������*/
		plt_kurs.setParamOtkl();
		/*��������� ����� ����������*/
		plt_kurs.scaleOtkl();
		/*��������� ��������������� ������� ����������*/
		plt_kurs.indexOtklGor(parOtklGor);
		/*��������� ������������� ������� ����������*/
		plt_kurs.indexOtklVert(parOtklVert);
	}
}
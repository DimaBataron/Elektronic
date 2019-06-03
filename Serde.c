#include<stdio.h> //������ ������������ �����-������
#include<conio.h> /*������ ������� ���������� �����-������*/
#include<windows.h>
#include<math.h> //���������� ���������� �������������� �������

void main()
{
	double Vm; //����� �������������� ��^3
	double a=0.0012; //����������� �������������
	// ��� ������� 1.2 * 10^-3
	double uc;  // ������������� ��������� �������������
	//������ ��������� ��� ������� ���������
	double imax; // ������������ ��� ����� �������������
	double dT;   // ���������� �������� ����������
	double L;   // �������� ������������� �������
	double Uin, Uout; // ������� � �������� ���������� �����
	double D; //����������� ����������
	double f; //������� ��������
	double Rn; // ������������� �������� Om
	double ls; //le ����������� ������ ���������� ���� mm
	double Ae; //����������� ������� ���������� mm^2
	double B; // ���������� ������� ��������������
	double Al; // ������������� �� ����� ������/w^2
	double w;  // ���������� ������ ������� ��� �����������
	//��������� �������������
	double w2; // ������ ������ ����� ������������� �� ����� (Al)
	double Bmax; // ������ ��������� �������� ��� ������������ ����
	double kzm;  //����������� ���������� ���� �����
	double Dpr; // ������� �������
	do
		{
		printf("BBOD: Uin Uout f(k) Rn L(u)\n");
		scanf("%lf%lf%lf%lf%lf",&Uin,&Uout,&f,&Rn,&L);
		D= (double)Uout/Uin; // ����. ����������
		printf("\nD=%1.4f",D);
		f=f*10*10*10; // ������� �������� � �����
		imax= Uin*((double)D/Rn + (double)(D*(1-D))/(2*f*((double)L/1000000)));
		printf("\nimax=%5.5f A",imax);
		printf("\n\nBBOD uc dT\n");
		scanf("%lf%lf",&uc,&dT);
		Vm=(double)(2.5*1000*((double)L/1000000)*imax*imax)/(uc*((double)1.2/1000)*dT);
		Vm=Vm*Vm*Vm;
		Vm= sqrt(sqrt(Vm)); // � �����������
		printf("Vm=%4.5f cm^3\n",Vm);
		printf("\nBBOD : le(cm) , Ae(cm^2), B(mm), Al(nH/w^2)\n");
		scanf("%lf%lf%lf%lf",&ls,&Ae,&B,&Al);
		w=(double)(((double)L/1000000)*((double)ls/100))/(4*((double)3.1415926/10000000)*uc*((double)Ae/10000));
		w=sqrt(w);
		w2=(double)(L*1000)/Al;
		w2=sqrt(w2);
		printf("\nVitki w=%.2f  w2=%.2f",w,w2);
		Bmax=(double)(((double)L/1000000)*imax)/(w*((double)Ae/10000));
		printf("\nBmax=%.5f",Bmax);
		B=(double)B/2; //������ ���� � ��
		B= B*B*3.14159265; // ������� ���� �������������� mm
		printf("\nBBOD D(mm) provod obmotki\n");
		scanf("%lf",&Dpr);
		Dpr=(double)Dpr/2;
		Dpr= Dpr*Dpr*3.14159265; // ������� ����������� ������� ������� mm
		kzm= (double)(Dpr*w)/B;
		printf("kzm=%f\n",kzm);
		getch();
		}
	while(1); 
}
#include<stdio.h> //Модуль стандартного ввода-вывода
#include<conio.h> /*Модуль функций расширения ввода-вывода*/
#include<windows.h>
#include<math.h> //Подключаем библиотеку математических функций

void main()
{
	double Vm; //объем магнитопровода см^3
	double a=0.0012; //коэффициэнт теплопередачи
	// для воздуха 1.2 * 10^-3
	double uc;  // эквивалентная магнитная проницаемость
	//вводим начальную для данного материала
	double imax; // максимальный ток через индуктивность
	double dT;   // допустимый перегрев сердечника
	double L;   // заданная индуктивность мкГенри
	double Uin, Uout; // Входное и выходное напряжение вольт
	double D; //коэффициэнт заполнения
	double f; //частота килогерц
	double Rn; // сопротивление нагрузки Om
	double ls; //le эффективная длинна магнитного пути mm
	double Ae; //эффективное сечение сердечника mm^2
	double B; // внутренний диаметр магнитопровода
	double Al; // индуктивность на виток наноГн/w^2
	double w;  // количество витков обмотки для обеспечения
	//зхаданной индуктивности
	double w2; // расчет витков через Индуктивность на виток (Al)
	double Bmax; // расчет магнитной индукции при максимальном токе
	double kzm;  //коэффициэнт заполнения окна медью
	double Dpr; // диаметр провода
	do
		{
		printf("BBOD: Uin Uout f(k) Rn L(u)\n");
		scanf("%lf%lf%lf%lf%lf",&Uin,&Uout,&f,&Rn,&L);
		D= (double)Uout/Uin; // коэф. заполнения
		printf("\nD=%1.4f",D);
		f=f*10*10*10; // перевод килоГерц в Герцы
		imax= Uin*((double)D/Rn + (double)(D*(1-D))/(2*f*((double)L/1000000)));
		printf("\nimax=%5.5f A",imax);
		printf("\n\nBBOD uc dT\n");
		scanf("%lf%lf",&uc,&dT);
		Vm=(double)(2.5*1000*((double)L/1000000)*imax*imax)/(uc*((double)1.2/1000)*dT);
		Vm=Vm*Vm*Vm;
		Vm= sqrt(sqrt(Vm)); // в сантиметрах
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
		B=(double)B/2; //Радиус окна в мм
		B= B*B*3.14159265; // площадь окна магнитопровода mm
		printf("\nBBOD D(mm) provod obmotki\n");
		scanf("%lf",&Dpr);
		Dpr=(double)Dpr/2;
		Dpr= Dpr*Dpr*3.14159265; // Площадь поперечного сечения обмотки mm
		kzm= (double)(Dpr*w)/B;
		printf("kzm=%f\n",kzm);
		getch();
		}
	while(1); 
}
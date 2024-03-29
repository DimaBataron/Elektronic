/*
Программа автоматизирующая выбор магнитопровода
1.Вводим параметры материала магнитопровода
2. Программа расчитывает объем
3.Программа расчитывает количество витков провода
4.Вводим площадь окна и диаметр провода обмотки
5.Программа расчитывает помещается ли проводка в окно и выводик коэффициэн заполнения
6.Программа для данных параметров не входит ли магнитопровод в насыщение
*/
#include<stdio.h> //Модуль стандартного ввода-вывода
#include<conio.h> /*Модуль функций расширения ввода-вывода*/
#include<windows.h>
#include<math.h> //Подключаем библиотеку математических функций
void main() {
	double Vm; // объем магнитопровода см^3
	double uc; //эквивалентная магнитная проницаемость сердечника
	double imax; // Максимальный ток сердечника А
	double dT; // Допустимый перегрев градусов цельсия
	double L; // индуктивность в мкГенри
	double w; // витки первым способом
	double w2; // расчет витков используя Al (нано генри виток^2);
	double Ae; // эффективное поперечное сечение магнитопровода см^2 
	double le; // средняя линия магнитопровода см
	double Al; // индуктивность наногенри на виток^2
	double B; // Диаметр окна в mm;
	double Bmax; //Магнитная индукция в магнитопроводе
	double Dpr; // диаметр провода в мм
	double kzm; // коэффициэнт заполнения окна медью

	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	printf_s("Ввод: Индуктивность=L[uG] Максимальный ток=imax[A] \n");
	printf_s("Магнитная проницаемость=uc Допустимый перегрев=dT[degC]\n");
	scanf_s("%lf%lf%lf%lf",&L,&imax,&uc,&dT);
	Vm = (double)(2.5 * 1000 * ((double)L/1000000) * imax * imax) / (uc * ((double)1.2 / 1000) * dT);
	Vm = Vm * Vm * Vm;
	Vm = sqrt(sqrt(Vm)); // получаем объем в сантиметрах
	printf_s("Объем магнитопровода: %f [см^2] \n",Vm);
	printf_s("Ввод : Средняя линия=le[cm]  Поперечное сечение=Ae[cm^2] \n");
	printf_s("Индуктивность на виток=Al[nH/w^2]\n");
	scanf_s("%lf%lf%lf", &le, &Ae, &Al);
	w = (double)(((double)L/1000000) * ((double)le / 100)) / (4 * ((double)3.1415926 / 10000000) * uc * ((double)Ae / 10000));
	w2 = (double)((double)L*1000) / Al; // здесь изменил
	w = sqrt(w);
	w2 = sqrt(w2);
	printf_s("Количество витков 1 w=%lf Количество витков 2 w2=%lf\n", w, w2);
	Bmax = (double)(((double)L / 1000000) * imax) / (w * ((double)Ae / 10000));
	printf_s("Магнитная индукция в магнитопроводе Bmax = %lf[T]\n", Bmax);
	printf_s("Ввод:  Диаметр окна=B[mm] Диаметр провода= Dpr[mm]\n ");
	scanf_s("%lf%lf",&B,&Dpr);
	B = (double)B / 2; //Радиус окна в мм
	B = B * B * 3.14159265; // площадь окна магнитопровода mm
	Dpr = (double)Dpr / 2;
	Dpr = Dpr * Dpr * 3.14159265; // Площадь поперечного сечения обмотки mm
	kzm = (double)(Dpr * w) / B;
	printf_s("kzm=%lf\n", kzm);
	_getch();
}
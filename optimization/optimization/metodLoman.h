#pragma once

#include <iostream>

using namespace std;
struct Trial
{
	double x;
	double z;
	int k=1;
};
Trial checkInfo(double a_, double b_, int MaxTrial_, double eps_, double m_);//a и b границы отрезка
double func(double x);//какая функция
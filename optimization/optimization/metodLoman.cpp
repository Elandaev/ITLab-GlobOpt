#include "metodLoman.h"
#include<math.h>
#include <vector>
using namespace std;

double func(double x)
{
	return sin(x) + sin(10*x/3);
}
Trial checkInfo(double a_, double b_, int MaxTrial_, double eps_, double m_)
{
	int T=1;//хранится номер лучшего интервала
	Trial tmp;
	tmp.k = 2;//количество испытаний 
	double eps = eps_;//точность

	vector<Trial> searchInfo(MaxTrial_);// ;
	vector<double> R(MaxTrial_);//запись характеристик 
	
	double m = m_;
	searchInfo[0].x = a_;
	searchInfo[1].x = b_;
	searchInfo[0].z = func(a_);
	searchInfo[0].k = 1;
	searchInfo[1].z = func(b_);
	searchInfo[1].k = 2;

	int t = 1;//тк имеем один интервал
	
    double best_Character;

	R[1] = 0.5*m*(searchInfo[1].x - searchInfo[0].x) - (searchInfo[1].z + searchInfo[0].z) / 2;
	do
	{
		best_Character = R[1];
		for (int i = 1; i < t; i++)
		{
			
			R[i] = 0.5*m*(searchInfo[i].x - searchInfo[i - 1].x) - (searchInfo[i].z + searchInfo[i - 1].z) / 2;
			if (R[i] >= best_Character)
			{
				best_Character = R[i];
				T = i;
			}
		}
				t++;//колич интервалов		
				tmp.x = 0.5*(searchInfo[T].x + searchInfo[T - 1].x) - (searchInfo[T].z - searchInfo[T - 1].z) / (2 * m);  				
				tmp.z = func(tmp.x);
				tmp.k++;				
				 searchInfo.insert(searchInfo.begin() + T, tmp);	                                     	
	} while (tmp.k < MaxTrial_ && fabs(searchInfo[T].x - searchInfo[T - 1].x) > eps );
	
	return tmp;
}



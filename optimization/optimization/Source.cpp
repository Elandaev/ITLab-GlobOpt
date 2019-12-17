#include<iostream>
#include<math.h>
#include "metodLoman.h"
//#include <string> 
using namespace std;
int main()
{
	Trial temp;
	setlocale(LC_ALL, "Russian");


	int MaxTrial;//кол-во проб(нач испыт)
	cout << "введите количество проб"  << "\n";
	cin >> MaxTrial;
	double a, b;
	cout << "введите промежуток от а до b" << "\n";
	cin >> a >> b;
	double Epsilon;
	cout << "введите точность" << "\n";
	cin >> Epsilon;
	double M;
	cout << "введите параметр" << "\n";
	cin >> M;

	temp = checkInfo( a,  b,  MaxTrial, Epsilon, M);

	cout << " (x =  " << temp.x << " ; y = " << temp.z << " ) " <<  "\n";
	cout << "количество испытаний    " << temp.k << "\n";
	
	system("pause");
	return 0;
	

}
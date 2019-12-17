#include <iostream>
#include <locale>

void main()
{
	setlocale(LC_ALL,"Russian");
	std::cout<<"Теперь можно выводить русские символы"<<std::endl;
}

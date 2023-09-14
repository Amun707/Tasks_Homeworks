#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

//Задача 1.
template <typename T>
void print_arr(T arr[], const int length) {
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }" << std::endl;
}

//Задача 2.
void p_power(int* pointer, int num);

//Задача 4.
int str_sum(std::string str);

//Задача 5.
std::string lowerCamelCase(std::string str);

int main() {
	system("chcp 1251>nul");
	int n, m;
	//Задача 1.(домашка №22). Попарный свап.
	std::cout << "Задача 1.\nИзначальный массив:\n";
	const int size1 = 10;
	int arr1[size1]{ 1,2,3,4,5,6,7,8,9,10 };
	print_arr(arr1, size1);

	for (int i = 0; i < size1 - 1; i += 2)
		//std::swap(arr1[i], arr1[i + 1]);//вариант решения с синтаксисом массивов
		std::swap(*(arr1 + i), *(arr1 + i + 1));//вариант решения с синтаксисом указателей
	std::cout << "Итоговый массив:\n";
	print_arr(arr1, size1);
	std::cout << std::endl;

	//Задача 2. (домашка 22). Степень числа
	std::cout << "Задача 2.\nВведите два числа -> ";
	std::cin >> n >> m;
	p_power(&n, m);
	std::cout << "Итог: " << n << "\n\n";


	//Задача 4 из занятия 52. Сумма строки
	std::cout << "Задача 4.\nВведите выражение -> ";
	std::string str4;
	std::getline(std::cin, str4);
	std::cout << str4 << " = " << str_sum(str4) << std::endl;


	//зАДАЧА 5. lowerCameCase
	std::cout << "Задача.\nВведите строку ->\n";
	std::string str5;
	std::getline(std::cin, str5);
	std::cout << lowerCamelCase(str5) << std::endl;


	return 0;
}


//Задача 5.
std::string lowerCamelCase(std::string str) {
	for (int i = 0; i < str.length(); i++)
		str[i] = std::tolower(str[i]);
	for (size_t i = 0; i < str.length(); ) {//size_t - unsigned long long
		i = str.find(' ', i);//поиск пробела который нужно вырезать
		if (i < str.length()) {//если пробел есть, то:
			str.replace(i, 1, "");//1. Вырезаем пробел
			str[i] = std::toupper(str[i]);//2. Возводим текущий символ в верхний регистр
		}
	}
	return str;
}




//задача4
int str_sum(std::string str) {
	int result = 0;
	for (unsigned long long i = 0; i < str.length();/*пусто так как изменения происходят в теле цикла*/) {
		result += std::stoi(str.substr(i));
		i = str.find(" + ", i);
		if (i < str.length())
			i += 3ULL;//3ULL перевели тип данных
	}


	return result;
}






void p_power(int* pointer, int num) {
	if (num <= 1) {
		*pointer = 0;
		return;
	}
	int tmp = *pointer;//разыменовываем указатель
	for (int i = 1; i < num; i++)
		*pointer *= tmp;//умножаем с присваиванием
}
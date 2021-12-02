// Лаба 1 задание 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


/*Функция strcat.
Формат char* strcat(char* dest, const char* src).
Функция приписывает строку src к строке dest.*/

#include <iostream>

using namespace std;

char* strcat(char* dest, char* src)
{
	int count1 = 0; // считаем кол-во символов в исходнике
	while (dest[count1] != 0)
	{
		count1++;
	}


	int count2 = 0;
	while (src[count2] != 0)
	{ // дописываем в конец первой строки символы второй строки
		dest[count1] = src[count2];
		count1++;
		count2++;
	}
	return dest;
    
}
void E3()
{
    char src[] = "Hello Ivan Savenkov";
    char dest[128] = "I'm Ilya Mospanko & ";

    char* outsided = strcat(dest, src);
    printf("\nмоя функция: %s", outsided);

}
int main()
{
	setlocale(LC_ALL, "Russian");
	printf("Нажмите 3\n");
	int choice = 0;
	cin >> choice;
	switch (choice)
	{
	case 3: system("cls"); E3();
		break;
		return 0;
	}
}
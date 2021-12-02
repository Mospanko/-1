#include <iostream>
#include <string>
#include <utility>

/*Объявить массив из n=20 целых чисел, проинициализировать нулями. Функция
processArray() должна заполнить массив случайными числами от одного до пяти,
вычислить и вернуть наименее часто встречающееся значение в массиве (если таких
несколько, вернуть наименьшее из них) и сформировать выходной массив из всех
элементов входного, отсортированных в порядке возрастания. Вывести на экран
массивы.
*/
using namespace std;

void printArr(int* arr, size_t N, string s) {
    printf(" %s", s.c_str());
    printf("\n[");
    for (size_t i = 0; i < N; ++i)
    {
        printf(" %i ", arr[i]);        
    }
    printf("]\n");    
}
int process(int* arr, int* res, size_t N) {
    for (size_t i = 0; i < N; ++i)              //заполнение исходного массива
    {
        arr[i] = ((rand() % 5) + 1);
        res[i] = arr[i];
    }
    double rareliest = 0.0;
    int help[5] = { 0 };

    for (size_t i = 0; i < N; i++)            //работа с выходным массивом
    {
        int smallest_ind = i;
        for (size_t j = i + 1; j < N; j++)
        {
            if (res[j] < res[smallest_ind])
            {
                smallest_ind = j;
            }
        }
        swap(res[i], res[smallest_ind]);
    }

    for (size_t i = 0; i < N; ++i) {            //выборка наименьшего
        help[arr[i] - 1]++;
    }
    int min = help[0];
    int min_ind = 0;
    for (int i = 0; i < 5; ++i)
    {
        if (help[i] < min)
        {
            min = help[i];
            min_ind = i;
        }
    }

    return min_ind + 1;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    const size_t N = 20;
    int arr[N] = { 0 };
    int res[N] = { 0 };
    srand(0);
    int rareliest = process(arr, res, N);
    printArr(arr, N, "Вход");
    printArr(res, N, "Выход");
    printf("Наименее часто встречающееся: %i", rareliest);
}

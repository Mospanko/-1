#include <iostream>
#include <cmath>

/*Преобразование: 2D → 1D. Двумерный массив 5х3 вещественных чисел необходимо
выложить в один ряд по элементам по столбцам сверху вниз.
Инициализация: заполнить массив числами x[i][j] = sin(i – j) + cos(i + j).
Вывод на экран: на каждый элемент массива отвести 10 позиций.*/

using namespace std;

double* MakeArr1D(double** arr, size_t rows, size_t cols) {
    double* arr1D = new double[rows * cols];
    for (size_t i = 0; i < rows * cols; i++)
    {
        for (size_t j = 0; j < rows; j++)
        {
            for (size_t l = 0; l < cols; l++)
            {
                *(arr1D + i) = *(*(arr + j) + l);
            }
        }
    }
    return arr1D;
}
void freeArray1D(double* arr)
{
    delete[] arr;
}

void freeArray2D(double** arr2D, size_t N)
{
    for (int i = 0; i < N; i++)
    {
        delete[] arr2D[i];
    }
    delete[] arr2D;
}

void PrintArr2D(double** arr, size_t rows, size_t cols)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            cout << *(*(arr + i) + j) << endl;
        }
    }
}
void PrintArr1D(double* arr, size_t N) {
    printf("\n[");
    for (size_t i = 0; i < N; ++i)
    {

        printf(" %d ", arr[i]);
        
    }
    printf("]\n");
}
void InitializeArr(double** arr, size_t rows, size_t cols) {

    
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            *(*(arr + i) + j) = sin(i - j) + cos(i + j);
        }
    }
}
int main()
{
    const size_t LEN = 15;
    const size_t M = 3;
    const size_t N = 5;

    double** arr = new double* [N];
    for (size_t i = 0; i < N; i++)
    {
        *(arr + i) = new double[M];
    }
    InitializeArr(arr, N, M);
    PrintArr2D(arr, N, M);
    double* arr_res = MakeArr1D(arr, N, M);
    PrintArr1D(arr_res, 15);
}


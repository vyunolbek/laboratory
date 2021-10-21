#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

const float RAND_MAX_F = RAND_MAX;

double get_rand()    // Генератор рандомного числа
{
    return rand() / RAND_MAX_F;
}

double get_rand_range(const double min, const double max)   // Генератор рандомного числа в диапазоне
{
    return get_rand() * (max - min) + min;
}

int main()
{
    srand(time(NULL));      // Семя для полностью рандомного числа
    float minimum, maximum;
    double *arr, sum = 0;
    int ost, arr_size, degree;
    printf("Input count of numbers:");
    scanf_s("%d", &arr_size);
    printf("Count of number after decimal point:");
    scanf_s("%d", &degree);
    printf("Minimum of random number:");
    scanf_s("%f", &minimum);       // Рандомное число от
    printf("Maximum of random number:");
    scanf_s("%f", &maximum);      // Рандомное число до
    arr = (double*)malloc(arr_size * sizeof(double));
    if (minimum > maximum || arr_size <= 0)     // Проверка входных
    {
        printf("Input is wrong");
        return 1;
    }
    for (int i = 0; i < arr_size; i++)   // Заполняем массив
    {
        arr[i] = get_rand_range(minimum, maximum);
    }
    for (int j = 0; j < arr_size; j++)   // Отделяем дробную часть и проверяем
    {
        ost = (arr[j] - (int)arr[j]) * pow(10, degree);     // Умножаем на 10^(degree) для того чтобы сдвинуть дробную часть влево
        //printf("%d   %llf \n", ost, arr[j]);
        if (ost < arr_size)         // Проверка на существование индекса в массиве
        {
            sum -= arr[j];
        } else
        {
            sum += arr[j];
        }

    }
    printf("\n %lf", sum);
    return 0;
}

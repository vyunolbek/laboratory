#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define ARR_SIZE 100000     // Размер массива

const float RAND_MAX_F = RAND_MAX;

float get_rand()    // Генератор рандомного числа
{
    return rand() / RAND_MAX_F;
}

float get_rand_range(const float min, const float max)   // Генератор рандомного числа в диапазоне
{
    return get_rand() * (max - min) + min;
}

int main()
{
    //srand(time(NULL));      // Семя для полностью рандомного числа
    float minimum, maximum, arr[ARR_SIZE];
    int num, sum = 0, ost;
    scanf_s("%f", &minimum);      // Рандомное число от
    scanf_s("%f", &maximum);      // Рандомное число до
    for (int i = 0; i < ARR_SIZE; i++)   // Заполняем массив
    {
        arr[i] = get_rand_range(minimum, maximum);
    }
    for (int j = 0; j < ARR_SIZE; j++)   // Отделяем дробную часть и проверяем
    {
        ost = (arr[j] - (int)arr[j]) * 1000000;     // Умножаем на 1000000 для того чтобы сдвинуть дробную часть влево
        printf("%d   %f \n", ost, arr[j]);
        if (ost < ARR_SIZE)         // Проверка на существование индекса в массиве
        {
            sum -= arr[ost];
        } else
        {
            sum += arr[j];
        }
    }
    printf("%d", sum);
    return 0;
}
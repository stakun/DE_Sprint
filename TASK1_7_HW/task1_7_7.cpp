// Практическое задание по теме 1.7 « Синтаксис языка программирования С++»
// Выполнил: Стакун Алексей
// Задача 7. Написать программу, которая выводит таблицу значений функции
// y=-2 * x^2 - 5 * x - 8 в диапазоне от –4 до +4, с шагом 0,5

#include <iostream>
using namespace std;

double func(const double x) // Обявляем нашу функцию
{
    return -2 * x * x - 5 * x - 8;
}

int main()
{
    double x1 = -4, x2 = 4; // Задаем диапазон изменения функций
    double x = x1;          // Устанавливаем итератор цикла на левую границу диапазона
    cout << "--------------------\n"
         << "x"
         << "\t | \t "
         << "f(x)\n"
         << "--------------------"
         << endl;

    while (x <= x2)
    {
        cout << x << "\t | \t" << func(x) << endl; // Вычисляем значение функции для текущего x
        x += 0.5;                                  // Делаем шаг итератора
    }
    system("pause");
    return 0;
}
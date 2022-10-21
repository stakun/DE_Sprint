// Практическое задание по теме 1.7 « Синтаксис языка программирования С++»
// Выполнил: Стакун Алексей
// Задача 1. Написать программу, которая сравнивает два введённых с клавиатуры числа.
// Программа должна указать, какое число больше или, если числа равны, вывести соответствующее сообщение.

#include <iostream>
using namespace std;
int main()
{
    // setlocale(LC_ALL, "Russian");

    float a, b;
    cout << "Enter first number and press <Enter> \n";
    cin >> a;
    cout << "Enter second number and press  <Enter> \n";
    cin >> b;
    if (a == b)
        cout << "Numbers " << a << " and " << b << " are equal" << endl;
    else
        cout << a << ((a < b) ? " less then " : " more then ") << b << endl;
    system("pause");
    return 0;
}
// Практическое задание по теме 1.7 « Синтаксис языка программирования С++»
// Выполнил: Стакун Алексей
// Задача 4. Проверить на чётность введённое с клавиатуры число.

#include <iostream>
using namespace std;
int main()
{
    int a;
    cout << "Enter your number and press <Enter> \n";
    cin >> a;
    if (a % 2 == 0)
    {
        cout << "Number " << a << " is even" << endl;
    }
    else
    {
        cout << "Number " << a << " is odd" << endl;
    }
}
// Практическое задание по теме 1.7 « Синтаксис языка программирования С++»
// Выполнил: Стакун Алексей
// Задача 3. Написать программу решения квадратного уравнения.
// Программа должна проверять правильность исходных данных и в случае, если коэффициент
// при второй степени неизвестного равен нулю, выводить соответствующее сообщение.

#include <iostream>
#include <cmath>
using namespace std;

void QuadraticEquation(double x1, double x2, double c)
{
    double root1, root2;
    if (x1 == 0) // Случай если коэффициент при второй степени равен 0
    {
        cout << "Equation not quadratic \n";
        // Решение:
        // x2*x+c = 0
        root1 = 0;
        root2 = -(c / x2);
        cout << "Root is " << root2 << endl;
    }
    else
    {
        double D = pow(x2, 2) - 4 * x1 * c;
        cout << "Discriminant is " << D << endl;
        if (D < 0)
        {
            cout << "Discriminant is equl to zero => roots of complex numbers" << endl;
        }
        if (D == 0)
        {
            root1 = 0;
            root2 = -(x2 / (2 * x1));
            cout << "x1 = x2 = " << root2 << endl;
        }
        if (D > 0)
        {
            // Вычисляем корни уравнения
            root1 = (-x2 + pow(D, 0.5)) / (2 * x1);
            root2 = (-x2 - pow(D, 0.5)) / (2 * x1);
            cout << "Roots: " << root1 << ", " << root2 << endl;
        }
    }
}

int main()
{
    double x1, x2, c;
    cout << "Enter coefficient at x1 <Enter> \n";
    cin >> x1;
    cout << "Enter coefficient at x2 <Enter> \n";
    cin >> x2;
    cout << "Enter coefficient c <Enter> \n";
    cin >> c;

    QuadraticEquation(x1, x2, c);

    return 0;
}
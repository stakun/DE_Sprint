// Практическое задание по теме 1.7 « Синтаксис языка программирования С++»
// Выполнил: Стакун Алексей
// Задача 10. Создайте структуру с именем train, содержащую поля:
// название пункта назначения, номер поезда, время отправления.
// Ввести данные в массив из пяти элементов типа train, упорядочить элементы по номерам поездов.
// Добавить возможность вывода информации о поезде, номер которого введен пользователем.
// Добавить возможность сортировки массив по пункту назначения, причем поезда с одинаковыми пунктами
// назначения должны быть упорядочены по времени отправления.

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

using namespace std;

struct train
{
    char dest[255]; // название пункта назначения
    int trNum;      // номер поезда
    int hh;         // час времени отправления
    int mm;         // минуты времени отправления
};

void PrintTime(int hours, int minutes)
{
    if (hours <= 9)
    {
        if (minutes <= 9)
            cout << 0 << hours << ":" << 0 << minutes;
        else
            cout << 0 << hours << ":" << minutes;
    }
    else if (minutes <= 9)
        cout << hours << ":" << 0 << minutes;
    else
        cout << hours << ":" << minutes;
}

void fillTrainStruct(train *tr, int n) // Функция для заполнения массива элементами структуры train в количестве trCount
{
    for (int i = 0; i < n; i++) // в цикле по количеству поездов
    {
        // cin.ignore(32767, '\n'); // игнорируем символы перевода строки "\n" во входящем потоке длиной 32767 символов
        cout << "Enter train " << i + 1 << " destignation: " << endl;
        // getline(cin, tr[i].dest); // полностью извлекаем строку в переменную trDest
        cin >> tr[i].dest; // Заполняем поле dest в текущем элементе структуры
        cout << "Enter train " << i + 1 << " number: " << endl;
        cin >> tr[i].trNum; // Заполняем поле trNum в текущем элементе структуры
        cout << "Enter train " << i + 1 << " departure time:" << endl;
        cout << "Hours: ";
        cin >> tr[i].hh; // Заполняем поле hh (часы) в текущем элементе структуры
        // добавить проверку введенных часов функцией CheckingHours
        cout << "Minutes: ";
        // добавить проверку введенных минут функцией CheckingMinutes
        cin >> tr[i].mm; // Заполняем поле mm (минуты) в текущем элементе структуры
        cout << endl;
    }
}

void sortTrainStructbyNum(train *tr, int n) // Функция для сортировки массива элементов структуры train по номерам поездов
{
    train buffer;                    // Создаем экземпляр структуры train для буфера
    for (int i = n - 1; i >= 1; i--) //
        for (int j = 0; j < i; j++)  //
        {
            if (tr[j].trNum > tr[j + 1].trNum) // Если текущий номер поезда больше следующего
            {
                // Меняем элементы местами
                buffer = tr[j];     // Сохраняем текущую структуру в буфер
                tr[j] = tr[j + 1];  // Текущий элемент структуры заменяем на следующий
                tr[j + 1] = buffer; // Следующий элемент структуры меняем на буфер
            }
        }
}

void showTrainInfo(train *tr, int n) // Функция для отображения информации о поезде номер которого ввел пользователь
{
    int nom;              // Переменная для номера поезда
    bool isTrain = false; // Флаг наличия номера поезда в стурктуре
    cout << "Enter train number: ";
    cin >> nom;                 // Получаем от пользователя номер поезда
    for (int i = 0; i < n; i++) // в цикле по количеству поездов
    {
        if (tr[i].trNum == nom)
        {
            cout << "----------------------------" << endl;
            cout << "Destination : " << tr[i].dest << endl;
            cout << "Number : " << tr[i].trNum << endl;
            cout << "Departure : ";
            PrintTime(tr[i].hh, tr[i].mm);
            cout << endl;
            cout << "----------------------------" << endl;
            isTrain = true;
        }
    }
    if (isTrain == false)
        cout << "No information about that train!" << endl;
}

void sortTrainStructbyDest(train *tr, int n) // Функция для сортировки массива элементов структуры train по пункту назначения
{
    for (int i = 0; i < n; i++) // в цикле по количеству поездов
    {
        for (int j = 0; j < n - i; j++) // в цикле по количеству поездов минус уже отсортированные
        {
            //Сравниваем 2 строки
            // strcmp - возвращает 1 если левая строка > правой строки
            //возвращает 0 если левая строка == правой строки
            //возвращает -1 если левая < правой строки
            int res = strcmp(tr[j].dest, tr[j + 1].dest);
            //Если левая строка > правой то свапаем
            if (res == 1)
                swap(tr[j], tr[j + 1]);
            //если пункты назначения равны
            else if (res == 0)
            {
                //Проверяем уже по времени
                //Если час отправления левого поезда > правого, то свапаем
                if (tr[j].hh > tr[j + 1].hh)
                    swap(tr[j], tr[j + 1]);
                else if (tr[j].hh == tr[j + 1].hh)
                {
                    //Аналогично часам
                    if (tr[j].mm > tr[j + 1].mm)
                        swap(tr[j], tr[j + 1]);
                }
            }
        }
    }
}

void showStructure(train *tr, int n) // Функция для вывода структуры на экран
{
    cout << "-----------------------------------\n"
         << "Num\t|\tDestignation\t|\tDeparture"
         << "-----------------------------------\n"
         << endl;               // Шапка таблицы
    for (int i = 0; i < n; i++) // в цикле по количеству поездов
    {
        cout << tr[i].trNum << "\t|\t"
             << tr[i].dest << "\t|\t";
        PrintTime(tr[i].hh, tr[i].mm);
        cout << endl;
    }
}

int main() // Главная программа
{
    int trNum; // поездов
    cout << "Enter number of trains: ";
    cin >> trNum;                 // Задаем число поездов (размер структуры traim)
    train *tr = new train[trNum]; // Создаем новый элемент структуры с динамическим выделением памяти с помощью указателя (*)
    fillTrainStruct(tr, trNum);   // Заполнение массива элементами структуры train в количестве trNum
    cout << "Source structure" << endl;
    showStructure(tr, trNum);        // Выводим структуру на экран
    sortTrainStructbyNum(tr, trNum); // Сортировка массива элементов структуры train по возрастанию номера поезда
    cout << "Sorting by train number" << endl;
    showStructure(tr, trNum);         // Выводим структуру на экран
    showTrainInfo(tr, trNum);         // Вывод информации о поезде по введенному номеру поезду
    sortTrainStructbyDest(tr, trNum); // Сортировка массива элементов структуры train по пункту назначения
    cout << "Sorting by destignation" << endl;
    showStructure(tr, trNum); // Выводим структуру на экран
    return 0;
}
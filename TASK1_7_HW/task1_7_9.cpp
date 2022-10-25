// Практическое задание по теме 1.7 « Синтаксис языка программирования С++»
// Выполнил: Стакун Алексей
// Задача 9. Создайте структуру с именем student, содержащую поля: фамилия и инициалы,
// номер группы, успеваемость (массив из пяти элементов). Создать массив из десяти элементов
// такого типа, упорядочить записи по возрастанию среднего балла. Добавить возможность вывода
// фамилий и номеров групп студентов, имеющих оценки, равные только 4 или 5.

#include <iostream>
#include <string>

using namespace std;

struct student
{
    string stName;  // фамилия и инициалы студента
    int stGroupe;   // номер группы студента
    int stSES[5];   // успеваемость студента (массив из пяти элементов)
    float avgGrade; // средний балл
};

void fillStudentStruct(student *st, int n) // Функция для заполнения массива элементами структуры student в количестве stNum
{
    for (int i(0); i < n; ++i) // в цикле по количеству студентов
    {
        st[i].avgGrade = 0;      // Обнуляем счетчик среднего балла
        cin.ignore(32767, '\n'); // игнорируем символы перевода строки "\n" во входящем потоке длиной 32767 символов
        cout << "Enter student name: ";
        // cin >> st[i].stName; // заполняем поле stName в текущем элементе структуры
        getline(cin, st[i].stName); // полностью извлекаем строку в переменную stName
        cout << "Enter group number: ";
        cin >> st[i].stGroupe; // Заполняем поле stGroupe в текущем элементе структуры
        cout << "Enter student grades:\n";
        for (int j(0); j < 5; ++j) // В цикле
        {
            cout << j + 1
                 << " grade: ";
            cin >> st[i].stSES[j];            // Заполняем текущее значение stSES в текущем элементе структуры
            st[i].avgGrade += st[i].stSES[j]; // Суммируем оценки, чтобы расчитать средний балл
        }
        st[i].avgGrade /= 5; // Расчитываем средний балл
        cout << "Average grade: " << st[i].avgGrade << endl;
    }
}

void sortStudentStruct(student *st, int n) // Функция для сортировки массива элементов структуры student по возрастанию среднего балла
{
    student buffer;                  // Создаем экземпляр структуры student для буфера
    for (int i = n - 1; i >= 1; i--) //
        for (int j = 0; j < i; j++)  //
        {
            if (st[j].avgGrade > st[j + 1].avgGrade) // Если текущий средний балл больше следующего
            {
                // Меняем элементы местами
                buffer = st[j];     // Сохраняем текущую структуру в буфер
                st[j] = st[j + 1];  // Текущий элемент структуры заменяем на следующий
                st[j + 1] = buffer; // Следующий элемент структуры меняем на буфер
            }
        }
}

void showStudentStruct(student *st, int n) // Вывод фамилий и номеров групп студентов, имеющих оценки, равные только 4 или 5
{
    bool goodGrades; // Признак, что студент хорошист или отличник
    int cnt = 0;     // Счетчик хорошистов и отличников
    cout
        << "Students with only 4 and 5 grades list" << endl;
    for (int i = 0; i < n; i++) // Цикл по всем студентам
    {
        goodGrades = true; // Устанавливаем признак студента хорошиста или отличника в true
        for (int j = 0; j < n; j++)
        {
            if (st[i].stSES[j] < 4) // Если у студента есть оценки ниже 4
            {
                goodGrades = false; // меняем признак хорошиста и отличника
                break;              // выходим из цикла перебора оценок и возвращаемся в цикл перебора студентов
            }
        }
        if (goodGrades) // Если у студента оценки только 4 и 5
        {
            // Выводим на экран запись о студенте
            cout << "Name: " << st[i].stName
                 << " Groupe: " << st[i].stGroupe
                 << " Avg. grade: " << st[i].avgGrade
                 << endl;
            cnt++;
        }
    }
    if (0 == cnt)
        cout << "No students without 1, 2 or 3 grades";
}

int main()
{
    int stNum; // Число студентов
    cout << "Enter number of students: ";
    cin >> stNum;

    student *st = new student[stNum]; // Создаем новый элемент структуры с динамическим выделением памяти с помощью указателя (*)
    fillStudentStruct(st, stNum);     // Заполнение массива элементами структуры student в количестве stNum
    sortStudentStruct(st, stNum);     // Сортировка массива элементов структуры student по возрастанию среднего балла
    showStudentStruct(st, stNum);     // Вывод фамилий и номеров групп студентов, имеющих оценки, равные только 4 или 5 (>=4)
    return 0;
}
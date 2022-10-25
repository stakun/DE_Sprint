#include <conio.h>
#include <iostream>
#include <cstdlib>
using namespace std;
 
struct Train {
    int number;
    char path[10];
	int hour;
	int min;
};
using namespace std;
 
int main() {
	const int N = 3;
    setlocale(LC_ALL, "Russian");
    Train trains[5];
    for (int i = 0; i < N; i++) {
        cout << "Введите пункт назначения поезда " << i + 1 << endl; 
        cin >> trains[ i ].path ;
        cout << "Введите номер для поезда " << i + 1 << endl;
        cin >> trains[ i ].number;
		cout << "Введите время отправления для поезда (часы) " << i + 1 << endl;
		cin >> trains[ i ].hour ;
		cout << "Введите время отправления для поезда (минуты) " << i + 1 << endl;
		cin >> trains[ i ].min ;
    }
	for(int i = 0; i < N; i++) {
		for(int j = i + 1; j < N; j++) {
			if(strcmp(trains[i].path, trains[j].path)>0)
            {
				Train tmp = trains[i];
				trains[i] = trains[j];
				trains[j] = tmp;
            }
		}
	}
    for (int i = 0; i < N; ++i) {
        cout << " Пункт назначения: " << trains[ i ].path << "   номер: " << trains[ i ].number << "   Время отправления: " << trains[ i ].hour << ":" << trains[ i ].min  << endl << endl;
    }

	int time_h;
	int time_min;
	int k = 0;
	cout << "Введите ваше время (часы затем минуты)" << endl;
	cin >> time_h >> time_min;
	cout << " Ваше время:" << time_h <<":" << time_min << endl << endl;
	for(int i = 0; i < N; i++) {
		if((time_h < trains[i].hour) || (time_h == trains[i].hour && time_min < trains[i].min))
		{
			cout << " следующие поезда отправятся после вашего времени: " << trains[i].number  <<" с временем "<< trains[i].hour << ":"<< trains[i].min << endl;
			k++;
		}
	}
	if(k == 0)
		cout << " Нет подходящих поездов" << endl;
	
	_getch();
	return 0;
}
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
        cout << "������� ����� ���������� ������ " << i + 1 << endl; 
        cin >> trains[ i ].path ;
        cout << "������� ����� ��� ������ " << i + 1 << endl;
        cin >> trains[ i ].number;
		cout << "������� ����� ����������� ��� ������ (����) " << i + 1 << endl;
		cin >> trains[ i ].hour ;
		cout << "������� ����� ����������� ��� ������ (������) " << i + 1 << endl;
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
        cout << " ����� ����������: " << trains[ i ].path << "   �����: " << trains[ i ].number << "   ����� �����������: " << trains[ i ].hour << ":" << trains[ i ].min  << endl << endl;
    }

	int time_h;
	int time_min;
	int k = 0;
	cout << "������� ���� ����� (���� ����� ������)" << endl;
	cin >> time_h >> time_min;
	cout << " ���� �����:" << time_h <<":" << time_min << endl << endl;
	for(int i = 0; i < N; i++) {
		if((time_h < trains[i].hour) || (time_h == trains[i].hour && time_min < trains[i].min))
		{
			cout << " ��������� ������ ���������� ����� ������ �������: " << trains[i].number  <<" � �������� "<< trains[i].hour << ":"<< trains[i].min << endl;
			k++;
		}
	}
	if(k == 0)
		cout << " ��� ���������� �������" << endl;
	
	_getch();
	return 0;
}
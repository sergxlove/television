#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
class television
{
public:
	television();
	television(string name_programm, string leader, int channel, string day_release, float time_release, float duration, float rating);
	~television();
private:
	string name_programm; //�������� ���������
	string leader; //�������
	int channel; //�����
	string day_release; //���� ������ � ����
	float time_release; //����� ������ � ����
	float duration; //������������
	float rating; //�������
};
class menu
{
public:
	void print_info();
private:
};
int main()
{
	setlocale(LC_ALL, "rus");
	menu m;
	int var = 0;
	bool exit = false;
	m.print_info();
	while (exit == false)
	{
		cout << "�������� ��������" << endl;
		cin >> var;
		switch (var)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
			exit = true;
			break;
		default:
			break;
		}
	}
	return 0;
}

television::television()
{
	this->name_programm = "";
	this->leader = "";
	this->channel = 0;
	this->day_release = "";
	this->time_release = 0.0f;
	this->duration = 0.0f;
	this->rating = 0.0f;
}

television::television(string name_programm, string leader, int channel, string day_release, float time_release, float duration, float rating)
{
	this->name_programm = name_programm;
	this->leader = leader;
	this->channel = channel;
	this->day_release = day_release;
	this->time_release = time_release;
	this->duration = duration;
	this->rating = rating;
}

television::~television()
{
	this->name_programm = "";
	this->leader = "";
	this->channel = 0;
	this->day_release = "";
	this->time_release = 0.0f;
	this->duration = 0.0f;
	this->rating = 0.0f;
}

void menu::print_info()
{
	cout << "������ ���� ��������" << endl;
	cout << "1 - ���� ������ � ���������" << endl;
	cout << "2 - �������� ������ �� ���������" << endl;
	cout << "3 - ���������� ������ � ����" << endl;
	cout << "4 - ������ ������ �� �����" << endl;
	cout << "5 - ����� �� ����� �������" << endl;
	cout << "6 - ����� ������������� �������� ������� " << endl;
	cout << "7 - ����� ������������ �������� �������" << endl;
	cout << "8 - C��������� �� ����� �������" << endl;
	cout << "9 - ����� ���� ������ �������" << endl;
	cout << "10 - ����� �� ���������" << endl;
}

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
	string name_programm; //название программы
	string leader; //ведущий
	int channel; //канал
	string day_release; //день выхода в эфир
	float time_release; //время выхода в эфир
	float duration; //длительность
	float rating; //рейтинг
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
		cout << "выберите действие" << endl;
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
	cout << "Список всех действий" << endl;
	cout << "1 - Ввод данных в коллекцию" << endl;
	cout << "2 - Удаление данных из коллекции" << endl;
	cout << "3 - Сохранение данных в файл" << endl;
	cout << "4 - Чтение данных из файла" << endl;
	cout << "5 - Поиск по полям объекта" << endl;
	cout << "6 - Поиск максимального элемента объекта " << endl;
	cout << "7 - Поиск минимального элемента объекта" << endl;
	cout << "8 - Cортировка по полям объекта" << endl;
	cout << "9 - Вывод всех данных объекта" << endl;
	cout << "10 - Выход из программы" << endl;
}

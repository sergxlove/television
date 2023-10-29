#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
class television
{
public:
	television();
	television(string name_programm, string leader, int channel, string day_release, float time_release, float duration, float rating);
	~television();
	void setData(string name_programm, string leader, int channel, string day_release, float time_release, float duration, float rating);
	void printData();
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
	television t;
	//переменные для ввода данных
	string name_programm, leader, day_release;
	float time_release, duration, rating;
	time_release = duration = rating = 0.0f;
	int chanel = 0;
	vector<television> arr;
	int var = 0;
	bool exit = false;
	int count = 0;
	int var_delete = 0;
	auto it = arr.begin();
	m.print_info();
	while (exit == false)
	{
		cout << "выберите действие" << endl;
		cin >> var;
		switch (var)
		{
		case 1:
			cout << "Введите название программы" << endl;
			cin >> name_programm;
			cout << "Введите фамилию ведущего" << endl;
			cin >> leader;
			cout << "Введите номер канала" << endl;
			cin >> chanel;
			cout << "Введите день ввыхода в эфир" << endl;
			cin >> day_release;
			cout << "Введите время выхода в эфир" << endl;
			cin >> time_release;
			cout << "Введите длительность программы" << endl;
			cin >> duration;
			cout << "Введите рейтинг программы" << endl;
			cin >> rating;
			t.setData(name_programm, leader, chanel, day_release, time_release, duration, rating);
			arr.push_back(t);
			break;
		case 2:
			count = 0;
			for (auto& e : arr)
			{
				cout << "Номер объекта - " <<count<< endl;
			}
			cout << "Какой элемент удалить?" << endl;
			cin >> var_delete;
			it = arr.begin();
			advance(it, var_delete);
			arr.erase(it);
			cout << "Элемент удален" << endl;
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
			if (arr.empty())
			{
				cout << "Вектор пустой" << endl;
			}
			else
			{
				for (auto& e : arr)
				{
					t.printData();
				}
			}
			break;
		case 9:
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

void television::setData(string name_programm, string leader, int channel, string day_release, float time_release, float duration, float rating)
{
	this->name_programm = name_programm;
	this->leader = leader;
	this->channel = channel;
	this->day_release = day_release;
	this->time_release = time_release;
	this->duration = duration;
	this->rating = rating;
}

void television::printData()
{
	cout << "Название программы : " << name_programm << endl;
	cout << "Фамилия лидера : " << leader << endl;
	cout << "Номер канала : " << channel << endl;
	cout << "День выхода в эфир : " << day_release << endl;
	cout << "Время выхода в эфир : " << time_release << endl;
	cout << "Продолжительность программы : " << duration << endl;
	cout << "Рейтинг программы : " <<rating<< endl;
}

void menu::print_info()
{
	cout << "Список всех действий" << endl;
	cout << "1 - Ввод данных в коллекцию" << endl;
	cout << "2 - Удаление данных из коллекции" << endl;
	cout << "3 - Сохранение данных в файл" << endl;
	cout << "4 - Чтение данных из файла" << endl;
	cout << "5 - Поиск по полям объекта" << endl;
	cout << "6 - Поиск максимального или минимального элемента объекта " << endl;
	cout << "7 - Cортировка по полям объекта" << endl;
	cout << "8 - Вывод всех данных объекта" << endl;
	cout << "9 - Выход из программы" << endl;
}

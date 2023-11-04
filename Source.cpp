#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
class television
{
public:
	television();//конструктор
	television(string name_programm, string leader, int channel, string day_release, float time_release, float duration, float rating);//конструктор с параметрами
	~television();//деструктор
	void setData(string name_programm, string leader, int channel, string day_release, float time_release, float duration, float rating);//ввод данных
	void printData();//вывод данных
	void write(string path, vector<television>* arr);//запись в файл
	void read(string path, vector<television>* arr);//чтение из файла
	void search(vector<television>* arr, int var_search, string field);//поиск поля
	void sort_field(vector<television>* arr, int var_sort);//сортировка по полю
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
	void print_info();//вывод доступных действий
	void print_field();//вывод доступных полей
	void print_field_for_min();//вывод полей для максимума и минимума
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
	int var_search = 0;
	int var_switch = 0;
	int var_sort = 0;
	auto it = arr.begin();
	string path = "data.txt";
	string field;
	m.print_info();
	t.read(path, &arr);
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
			if (arr.empty())
			{
				cout << "Вектор пустой" << endl;
			}
			else
			{
				t.write(path,&arr);
				cout << "Данные записаны в файл" << endl;
			}
			break;
		case 4:
			t.read(path, &arr);
			break;
		case 5:
			m.print_field();
			cout << "Выберите поле для поиска" << endl;
			cin >> var_search;
			cout << "Введите данные для поиска" << endl;
			cin >> field;
			t.search(&arr, var_search, field);
		case 6:
			cout << "Что вы хотите найти?" << endl;
			cout << "1 - Минимальное" << endl;
			cout << "2 - Максимальное" << endl;
			cin >> var_search;
			m.print_field_for_min();
			break;
		case 7:
			cout << "Выберите поле для сортировки" << endl;
			cin >> var_sort;
			t.sort_field(&arr, var_sort);
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
					e.printData();
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
void television::write(string path, vector<television>* arr)
{
	fstream file;
	file.open(path, fstream::out);
	if (file.is_open())
	{
		cout << "Файл успешно открыт" << endl;
		file << arr->size() << "\n";
		for (auto& e : *arr)
		{
			file << e.name_programm << "\n";
			file << e.leader << "\n";
			file << e.channel << "\n";
			file << e.day_release << "\n";
			file << e.time_release << "\n";
			file << e.duration << "\n";
			file << e.rating << "\n";
		}
		cout << "Данные успешно записаны" << endl;
		file.close();
	}
	else
	{
		cout << "Ошибка открытия файла" << endl;
	}
}
void television::read(string path, vector<television>* arr)
{
	fstream file;
	string str;
	television tv;
	int size = 0;
	file.open(path, fstream::in);
	if (file.is_open())
	{
		cout << "Файл успешно открыт" << endl;
		getline(file, str);
		size = stoi(str);
		for (int i = 0;i < size;i++)
		{
			getline(file, tv.name_programm);
			getline(file, tv.leader);
			getline(file, str);
			tv.channel = stoi(str);
			getline(file, tv.day_release);
			getline(file, str);
			tv.day_release = stoi(str);
			getline(file, str);
			tv.duration = stoi(str);
			getline(file, str);
			tv.rating = stoi(str);
			arr->push_back(tv);
		}
		file.close();
	}
	else
	{
		cout << "Ошибка открытия файла" << endl;
	}
}
void television::search(vector<television>* arr, int var_search, string field)
{
	for (auto& e : *arr)
	{
		switch (var_search)
		{
		case 1:
			if (e.name_programm == field)
			{
				e.printData();
			}
			break;
		case 2:
			if (e.leader == field)
			{
				e.printData();
			}
			break;
		case 3:
			if (e.channel == stoi(field))
			{
				e.printData();
			}
			break;
		case 4:
			if (e.day_release == field)
			{
				e.printData();
			}
			break;
		case 5:
			if (e.time_release == stoi(field))
			{
				e.printData();
			}
			break;
		case 6:
			if (e.duration == stoi(field))
			{
				e.printData();
			}
			break;
		case 7:
			if (e.rating == stoi(field))
			{
				e.printData();
			}
			break;
		default:
			break;
		}
	}
}
void television::sort_field(vector<television>* arr, int var_sort)
{
	switch (var_sort)
	{
	case 1:
		sort(arr->begin(), arr->end(), [](const television& t1, const television& t2) {return t1.name_programm > t2.name_programm;});
		break;
	case 2:
		sort(arr->begin(), arr->end(), [](const television& t1, const television& t2) {return t1.leader > t2.leader;});
		break;
	case 3:
		sort(arr->begin(), arr->end(), [](const television& t1, const television& t2) {return t1.channel > t2.channel;});
		break;
	case 4:
		sort(arr->begin(), arr->end(), [](const television& t1, const television& t2) {return t1.day_release > t2.day_release;});
		break;
	case 5:
		sort(arr->begin(), arr->end(), [](const television& t1, const television& t2) {return t1.time_release > t2.time_release;});
		break;
	case 6:
		sort(arr->begin(), arr->end(), [](const television& t1, const television& t2) {return t1.duration > t2.duration;});
		break;
	case 7:
		sort(arr->begin(), arr->end(), [](const television& t1, const television& t2) {return t1.rating > t2.rating;});
		break;
	default:
		break;
	}
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
void menu::print_field()
{
	cout << "Доступные поля :" << endl;
	cout << "1 - Название программы" << endl;
	cout << "2 - Ведущий" << endl;
	cout << "3 - Канал" << endl;
	cout << "4 - День выхода в эфир" << endl;
	cout << "5 - Время выхода в эфир" << endl;
	cout << "6 - Длительность программы" << endl;
	cout << "7 - Рейтинг программы" << endl;
}
void menu::print_field_for_min()
{
	cout << "Доступные поля :" << endl;
	cout << "1 - Канал" << endl;
	cout << "2 - Время выхода в эфир" << endl;
	cout << "3 - Длительность программы" << endl;
	cout << "4 - Рейтинг программы" << endl;
}

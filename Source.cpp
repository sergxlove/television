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
	void setData();//ввод данных
	void printData();//вывод данных
	void write(string path, vector<television>* arr);//запись в файл
	void read(string path, vector<television>* arr);//чтение из файла
	void search(vector<television>* arr, int var_search, string field);//поиск поля
	void sort_field(vector<television>* arr, int var_sort);//сортировка по полю
	float find_maxmin(vector<television>* arr, int var_search, int var_sort);//поиск максимального или минимального элемента
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
	//создание объектов класса
	menu m;
	television t;
	vector<television> arr;//создание массива объектов
	int var, count, var_delete, var_search, var_sort;
	var = count = var_delete = var_search = var_sort = 0;
	bool exit = false;
	auto it = arr.begin();
	string path = "data.txt";
	string field;
	m.print_info();
	t.read(path, &arr);
	while (exit == false)
	{
		cout << "выберите действие" << endl;
		cin >> var;
		switch (var)//консольное меню
		{
		case 1://режим 1
			//ввод данных
			t.setData();//передача параметров в поля объекта
			arr.push_back(t);//добавление объекта в вектор
			cout << "Объект создан" << endl;
			break;
		case 2://режим 2
			if (arr.empty())//проверка на наличие элементов в векторе
			{
				cout << "Вектор пустой" << endl;
			}
			else
			{
				count=0;
				for (auto& e : arr)//вывод доступных номеров лбъекта с помощью цикла форич
				{
					cout << "Номер объекта - " <<count<< endl;
					count++;
				}
				cout << "Какой элемент удалить?" << endl;
				cin >> var_delete;
				if (var_delete < arr.size())//проверка корректности введенных данных
				{
					it = arr.begin();//присвоение итератору ссылки на первый элемент вектора
					advance(it, var_delete);//сдвиг итератора
					arr.erase(it);//удаление элемента
					cout << "Элемент удален" << endl;
				}
				else
				{
					cout << "Такого элеемнта нет" << endl;
				}
			}
			break;
		case 3://режим 3
			t.write(path,&arr);//запись данных в файл
			cout << "Данные записаны в файл" << endl;
			break;
		case 4://режим 4
			t.read(path, &arr);//чтение данных из файла
			cout << "Данные успешно считаны из файла" << endl;
			break;
		case 5://режим 5
			if (arr.empty())//проверка на наличие элементов в векторе
			{
				cout << "Вектор пустой" << endl;
			}
			else
			{
				m.print_field();//вывод доступных полей
				cout << "Выберите поле для поиска" << endl;
				cin >> var_search;
				cout << "Введите данные для поиска" << endl;
				cin >> field;
				t.search(&arr, var_search, field);//поиск данных по полю
			}
			break;
		case 6://режим 6
			if (arr.empty())//проверка на наличие элементов в векторе
			{
				cout << "Вектор пустой" << endl;
			}
			else
			{
				cout << "Что вы хотите найти?" << endl;
				cout << "1 - Максимальное" << endl;
				cout << "2 - Минимальноое" << endl;
				cin >> var_search;
				m.print_field_for_min();//вывод полей доступных для поиска макс и мин
				cin >> var_sort;
				cout << "результат : " << t.find_maxmin(&arr, var_search, var_sort) << endl;//поиск и вывод макс или мин элемента
			}
			break;
		case 7://режим 7
			if (arr.empty())//проверка на наличие элементов в векторе
			{
				cout << "Вектор пустой" << endl;
			}
			else
			{
				cout << "Выберите поле для сортировки" << endl;
				m.print_field();//вывод полей
				cin >> var_sort;
				t.sort_field(&arr, var_sort);//сортировка поля
				cout << "Сортировка прошла успешно" << endl;
			}
			break;
		case 8://режим 8
			if (arr.empty())//проверка на наличие элементов в векторе
			{
				cout << "Вектор пустой" << endl;
			}
			else
			{
				for (auto& e : arr)//цикл фор ич
				{
					e.printData();
				}
			}
			break;
		case 9://режим 9
			exit = true;//выход из программы
			cout << "Программа завершенна" << endl;
			break;
		default://при неверном вводе
			cout << "Неверный ввод" << endl;
			break;
		}
	}
	return 0;
}
television::television()//конструктор
{
	//заполнение полей объекта значениями
	this->name_programm = "";
	this->leader = "";
	this->channel = 0;
	this->day_release = "";
	this->time_release = 0.0f;
	this->duration = 0.0f;
	this->rating = 0.0f;
}
television::television(string name_programm, string leader, int channel, string day_release, float time_release, float duration, float rating)//конструктор с параметрами
{
	//заполнение полей объекта значениями
	this->name_programm = name_programm;
	this->leader = leader;
	this->channel = channel;
	this->day_release = day_release;
	this->time_release = time_release;
	this->duration = duration;
	this->rating = rating;
}
television::~television()//деструктор
{
	this->name_programm = "";
	this->leader = "";
	this->channel = 0;
	this->day_release = "";
	this->time_release = 0.0f;
	this->duration = 0.0f;
	this->rating = 0.0f;
}
void television::setData()//ввод данных
{
	//заполнение полей объекта значениями
	cout << "Введите название программы" << endl;
	cin >> name_programm;
	cout << "Введите фамилию ведущего" << endl;
	cin >> leader;
	cout << "Введите номер канала" << endl;
	cin >> channel;
	cout << "Введите день выхода в эфир" << endl;
	cin >> day_release;
	cout << "Введите время выхода в эфир" << endl;
	cin >> time_release;
	cout << "Введите длительность программы" << endl;
	cin >> duration;
	cout << "Введите рейтинг программы" << endl;
	cin >> rating;
}
void television::printData()//вывод данных
{
	cout << "Название программы : " << name_programm << endl;
	cout << "Фамилия лидера : " << leader << endl;
	cout << "Номер канала : " << channel << endl;
	cout << "День выхода в эфир : " << day_release << endl;
	cout << "Время выхода в эфир : " << time_release << endl;
	cout << "Продолжительность программы : " << duration << endl;
	cout << "Рейтинг программы : " <<rating<< endl;
}
void television::write(string path, vector<television>* arr)//запись в файл
{
	fstream file;
	file.open(path, fstream::out);//открытие файла
	if (file.is_open())//проверка открытия файла
	{
		file << arr->size() << "\n";
		for (auto& e : *arr)//цикл фор ич
		{
			//запись в файл
			file << e.name_programm << "\n";
			file << e.leader << "\n";
			file << e.channel << "\n";
			file << e.day_release << "\n";
			file << e.time_release << "\n";
			file << e.duration << "\n";
			file << e.rating << "\n";
		}
		file.close();//заакрытие файла
	}
}
void television::read(string path, vector<television>* arr)//чтение из файла
{
	fstream file;
	string str;
	television tv;
	int size = 0;
	file.open(path, fstream::in);//открытие файла
	if (file.is_open())
	{
		getline(file, str);
		size = stoi(str);
		for (int i = 0;i < size;i++)
		{
			//считывание строк из файла
			//stoi - конвертация символоов к цифрам
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
			arr->push_back(tv);//добавление в вектор
		}
		file.close();//закрытие файла
	}
}
void television::search(vector<television>* arr, int var_search, string field)//поиск данных
{
	for (auto& e : *arr)
	{
		switch (var_search)//поле
		{
		case 1:
			if (e.name_programm == field)//сравнение поля объекта с введенными даннными
			{
				e.printData();
			}
			break;
		case 2:
			if (e.leader == field)//сравнение поля объекта с введенными даннными
			{
				e.printData();
			}
			break;
		case 3:
			if (e.channel == stoi(field))//сравнение поля объекта с введенными даннными
			{
				e.printData();
			}
			break;
		case 4:
			if (e.day_release == field)//сравнение поля объекта с введенными даннными
			{
				e.printData();
			}
			break;
		case 5:
			if (e.time_release == stoi(field))//сравнение поля объекта с введенными даннными
			{
				e.printData();
			}
			break;
		case 6:
			if (e.duration == stoi(field))//сравнение поля объекта с введенными даннными
			{
				e.printData();
			}
			break;
		case 7:
			if (e.rating == stoi(field))//сравнение поля объекта с введенными даннными
			{
				e.printData();
			}
			break;
		default:
			cout << "Данные не найдены" << endl;
			break;
		}
	}
}
void television::sort_field(vector<television>* arr, int var_sort)//сортировка поля
{
	switch (var_sort)//поле
	{
	case 1:
		sort(arr->begin(), arr->end(), [](const television& t1, const television& t2) {return t1.name_programm > t2.name_programm;});//сортировка
		break;
	case 2:
		sort(arr->begin(), arr->end(), [](const television& t1, const television& t2) {return t1.leader > t2.leader;});//сортировка
		break;
	case 3:
		sort(arr->begin(), arr->end(), [](const television& t1, const television& t2) {return t1.channel > t2.channel;});//сортировка
		break;
	case 4:
		sort(arr->begin(), arr->end(), [](const television& t1, const television& t2) {return t1.day_release > t2.day_release;});//сортировка
		break;
	case 5:
		sort(arr->begin(), arr->end(), [](const television& t1, const television& t2) {return t1.time_release > t2.time_release;});//сортировка
		break;
	case 6:
		sort(arr->begin(), arr->end(), [](const television& t1, const television& t2) {return t1.duration > t2.duration;});//сортировка
		break;
	case 7:
		sort(arr->begin(), arr->end(), [](const television& t1, const television& t2) {return t1.rating > t2.rating;});//сортировка
		break;
	default:
		break;
	}
}
float television::find_maxmin(vector<television>* arr, int var_search, int var_sort)//поиск макс или мин
{
	float max = 0.0f;
	float min = 1000000.0f;
	switch (var_search)//мин или макс
	{
	case 1:
		switch (var_sort)//поле
		{
		case 1:
			for (auto& el : *arr)
			{
				if (el.channel >max)
				{
					max = el.channel;
				}
			}
			return max;
			break;
		case 2:
			for (auto& el : *arr)
			{
				if (el.time_release > max)
				{
					max = el.time_release;
				}
			}
			return max;
			break;
		case 3:
			for (auto& el : *arr)
			{
				if (el.duration >max)
				{
					max = el.duration;
				}
			}
			return max;
			break;
		case 4:
			for (auto& el : *arr)
			{
				if (el.rating > max)
				{
					max = el.rating;
				}
			}
			return max;
			break;
		default:
			cout << "Неверный ввод" << endl;
			return 0.0f;
			break;
		}
		break;
	case 2:
		switch (var_sort)
		{
		case 1:
			for (auto& el : *arr)
			{
				if (el.channel < min)
				{
					min = el.channel;
				}
			}
			return min;
			break;
		case 2:
			for (auto& el : *arr)
			{
				if (el.time_release < min)
				{
					min = el.time_release;
				}
			}
			return min;
			break;
		case 3:
			for (auto& el : *arr)
			{
				if (el.duration < min)
				{
					min = el.duration;
				}
			}
			return min;
			break;
		case 4:
			for (auto& el : *arr)
			{
				if (el.rating < min)
				{
					min = el.rating;
				}
			}
			return min;
			break;
		default:
			cout << "Неверный ввод" << endl;
			return 0.0f;
			break;
		}
		break;
	default:
		cout << "Неверный ввод" << endl;
		return 0.0f;
		break;
	}
	return 0.0f;
}
void menu::print_info()//вывод информации о консольном меню
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
void menu::print_field()//вывод информации о полях
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
void menu::print_field_for_min()//поля для макс или мин
{
	cout << "Доступные поля :" << endl;
	cout << "1 - Канал" << endl;
	cout << "2 - Время выхода в эфир" << endl;
	cout << "3 - Длительность программы" << endl;
	cout << "4 - Рейтинг программы" << endl;
}

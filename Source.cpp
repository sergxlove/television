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
	void write(string path, string path_col, vector<television>* arr);
	void ride(string path, string path_col, vector<television>* arr);
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
	television t;
	//���������� ��� ����� ������
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
	string path = "data.txt";
	string path_colvo = "colvo.txt";
	m.print_info();
	t.ride(path, path_colvo, &arr);
	while (exit == false)
	{
		cout << "�������� ��������" << endl;
		cin >> var;
		switch (var)
		{
		case 1:
			cout << "������� �������� ���������" << endl;
			cin >> name_programm;
			cout << "������� ������� ��������" << endl;
			cin >> leader;
			cout << "������� ����� ������" << endl;
			cin >> chanel;
			cout << "������� ���� ������� � ����" << endl;
			cin >> day_release;
			cout << "������� ����� ������ � ����" << endl;
			cin >> time_release;
			cout << "������� ������������ ���������" << endl;
			cin >> duration;
			cout << "������� ������� ���������" << endl;
			cin >> rating;
			t.setData(name_programm, leader, chanel, day_release, time_release, duration, rating);
			arr.push_back(t);
			break;
		case 2:
			count = 0;
			for (auto& e : arr)
			{
				cout << "����� ������� - " <<count<< endl;
			}
			cout << "����� ������� �������?" << endl;
			cin >> var_delete;
			it = arr.begin();
			advance(it, var_delete);
			arr.erase(it);
			cout << "������� ������" << endl;
			break;
		case 3:
			if (arr.empty())
			{
				cout << "������ ������" << endl;
			}
			else
			{
				t.write(path, path_colvo, &arr);
				cout << "������ �������� � ����" << endl;
			}
			break;
		case 4:
			if (arr.empty())
			{
				cout << "������ ������" << endl;
			}
			else
			{
				t.ride(path, path_colvo, &arr);
			}
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
				cout << "������ ������" << endl;
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
	cout << "�������� ��������� : " << name_programm << endl;
	cout << "������� ������ : " << leader << endl;
	cout << "����� ������ : " << channel << endl;
	cout << "���� ������ � ���� : " << day_release << endl;
	cout << "����� ������ � ���� : " << time_release << endl;
	cout << "����������������� ��������� : " << duration << endl;
	cout << "������� ��������� : " <<rating<< endl;
}

void television::write(string path, string path_col, vector<television>* arr)
{
	fstream file;
	fstream file_col;
	file.open(path, fstream::out | fstream::app);
	file_col.open(path_col, fstream::out);
	if (file.is_open() && file_col.is_open())
	{
		cout << "���� ������� ������" << endl;
		for (auto& el : *arr)
		{
			file << el.name_programm << "\n";
			file << el.leader << "\n";
			file << el.channel << "\n";
			file << el.day_release << "\n";
			file << el.time_release << "\n";
			file << el.duration << "\n";
			file << el.rating << "\n";
		}
		file_col.clear();
		file_col << arr->size();
		file.close();
		file_col.close();
	}
	else
	{
		cout << "������ �������� �����" << endl;
	}
}

void television::ride(string path, string path_col, vector<television>* arr)
{
	fstream file;
	fstream file_col;
	television tv;
	string str;
	int count = 0;
	file.open(path, fstream::in);
	file_col.open(path_col, fstream::in);
	if (file.is_open() && file_col.is_open())
	{
		cout << "���� ������� ������" << endl;
		getline(file_col, str);
		count = stoi(str);
		for (int i = 0;i < count;i++)
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
			cout << "������ ������� ������� �� �����" << endl;
			file.close();
			file_col.close();
		}
	}
	else
	{
		cout << "������ �������� �����" << endl;
	}
}

void menu::print_info()
{
	cout << "������ ���� ��������" << endl;
	cout << "1 - ���� ������ � ���������" << endl;
	cout << "2 - �������� ������ �� ���������" << endl;
	cout << "3 - ���������� ������ � ����" << endl;
	cout << "4 - ������ ������ �� �����" << endl;
	cout << "5 - ����� �� ����� �������" << endl;
	cout << "6 - ����� ������������� ��� ������������ �������� ������� " << endl;
	cout << "7 - C��������� �� ����� �������" << endl;
	cout << "8 - ����� ���� ������ �������" << endl;
	cout << "9 - ����� �� ���������" << endl;
}

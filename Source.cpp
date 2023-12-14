#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;
class television
{
public:
	television();//�����������
	television(string name_programm, string leader, int channel, string day_release, float time_release, float duration, float rating);//����������� � �����������
	~television();//����������
	void setData();//���� ������
	void printData();//����� ������
	void write(string path, vector<television>* arr);//������ � ����
	void read(string path, vector<television>* arr);//������ �� �����
	void search(vector<television>* arr, int var_search, string field);//����� ����
	void sort_field(vector<television>* arr, int var_sort);//���������� �� ����
	float find_maxmin(vector<television>* arr, int var_search, int var_sort);//����� ������������� ��� ������������ ��������
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
	void print_info();//����� ��������� ��������
	void print_field();//����� ��������� �����
	void print_field_for_min();//����� ����� ��� ��������� � ��������
private:
};
int main()
{
	setlocale(LC_ALL, "rus");
	//�������� �������� ������
	menu m;
	television t;
	vector<television> arr;//�������� ������� ��������
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
		cout << "�������� ��������" << endl;
		cin >> var;
		switch (var)//���������� ����
		{
		case 1://����� 1
			//���� ������
			t.setData();//�������� ���������� � ���� �������
			arr.push_back(t);//���������� ������� � ������
			cout << "������ ������" << endl;
			break;
		case 2://����� 2
			if (arr.empty())//�������� �� ������� ��������� � �������
			{
				cout << "������ ������" << endl;
			}
			else
			{
				count=0;
				for (auto& e : arr)//����� ��������� ������� ������� � ������� ����� �����
				{
					cout << "����� ������� - " <<count<< endl;
					count++;
				}
				cout << "����� ������� �������?" << endl;
				cin >> var_delete;
				if (var_delete < arr.size())//�������� ������������ ��������� ������
				{
					it = arr.begin();//���������� ��������� ������ �� ������ ������� �������
					advance(it, var_delete);//����� ���������
					arr.erase(it);//�������� ��������
					cout << "������� ������" << endl;
				}
				else
				{
					cout << "������ �������� ���" << endl;
				}
			}
			break;
		case 3://����� 3
			t.write(path,&arr);//������ ������ � ����
			cout << "������ �������� � ����" << endl;
			break;
		case 4://����� 4
			t.read(path, &arr);//������ ������ �� �����
			cout << "������ ������� ������� �� �����" << endl;
			break;
		case 5://����� 5
			if (arr.empty())//�������� �� ������� ��������� � �������
			{
				cout << "������ ������" << endl;
			}
			else
			{
				m.print_field();//����� ��������� �����
				cout << "�������� ���� ��� ������" << endl;
				cin >> var_search;
				cout << "������� ������ ��� ������" << endl;
				cin >> field;
				t.search(&arr, var_search, field);//����� ������ �� ����
			}
			break;
		case 6://����� 6
			if (arr.empty())//�������� �� ������� ��������� � �������
			{
				cout << "������ ������" << endl;
			}
			else
			{
				cout << "��� �� ������ �����?" << endl;
				cout << "1 - ������������" << endl;
				cout << "2 - ������������" << endl;
				cin >> var_search;
				m.print_field_for_min();//����� ����� ��������� ��� ������ ���� � ���
				cin >> var_sort;
				cout << "��������� : " << t.find_maxmin(&arr, var_search, var_sort) << endl;//����� � ����� ���� ��� ��� ��������
			}
			break;
		case 7://����� 7
			if (arr.empty())//�������� �� ������� ��������� � �������
			{
				cout << "������ ������" << endl;
			}
			else
			{
				cout << "�������� ���� ��� ����������" << endl;
				m.print_field();//����� �����
				cin >> var_sort;
				t.sort_field(&arr, var_sort);//���������� ����
				cout << "���������� ������ �������" << endl;
			}
			break;
		case 8://����� 8
			if (arr.empty())//�������� �� ������� ��������� � �������
			{
				cout << "������ ������" << endl;
			}
			else
			{
				for (auto& e : arr)//���� ��� ��
				{
					e.printData();
				}
			}
			break;
		case 9://����� 9
			exit = true;//����� �� ���������
			cout << "��������� ����������" << endl;
			break;
		default://��� �������� �����
			cout << "�������� ����" << endl;
			break;
		}
	}
	return 0;
}
television::television()//�����������
{
	//���������� ����� ������� ����������
	this->name_programm = "";
	this->leader = "";
	this->channel = 0;
	this->day_release = "";
	this->time_release = 0.0f;
	this->duration = 0.0f;
	this->rating = 0.0f;
}
television::television(string name_programm, string leader, int channel, string day_release, float time_release, float duration, float rating)//����������� � �����������
{
	//���������� ����� ������� ����������
	this->name_programm = name_programm;
	this->leader = leader;
	this->channel = channel;
	this->day_release = day_release;
	this->time_release = time_release;
	this->duration = duration;
	this->rating = rating;
}
television::~television()//����������
{
	this->name_programm = "";
	this->leader = "";
	this->channel = 0;
	this->day_release = "";
	this->time_release = 0.0f;
	this->duration = 0.0f;
	this->rating = 0.0f;
}
void television::setData()//���� ������
{
	//���������� ����� ������� ����������
	cout << "������� �������� ���������" << endl;
	cin >> name_programm;
	cout << "������� ������� ��������" << endl;
	cin >> leader;
	cout << "������� ����� ������" << endl;
	cin >> channel;
	cout << "������� ���� ������ � ����" << endl;
	cin >> day_release;
	cout << "������� ����� ������ � ����" << endl;
	cin >> time_release;
	cout << "������� ������������ ���������" << endl;
	cin >> duration;
	cout << "������� ������� ���������" << endl;
	cin >> rating;
}
void television::printData()//����� ������
{
	cout << "�������� ��������� : " << name_programm << endl;
	cout << "������� ������ : " << leader << endl;
	cout << "����� ������ : " << channel << endl;
	cout << "���� ������ � ���� : " << day_release << endl;
	cout << "����� ������ � ���� : " << time_release << endl;
	cout << "����������������� ��������� : " << duration << endl;
	cout << "������� ��������� : " <<rating<< endl;
}
void television::write(string path, vector<television>* arr)//������ � ����
{
	fstream file;
	file.open(path, fstream::out);//�������� �����
	if (file.is_open())//�������� �������� �����
	{
		file << arr->size() << "\n";
		for (auto& e : *arr)//���� ��� ��
		{
			//������ � ����
			file << e.name_programm << "\n";
			file << e.leader << "\n";
			file << e.channel << "\n";
			file << e.day_release << "\n";
			file << e.time_release << "\n";
			file << e.duration << "\n";
			file << e.rating << "\n";
		}
		file.close();//��������� �����
	}
}
void television::read(string path, vector<television>* arr)//������ �� �����
{
	fstream file;
	string str;
	television tv;
	int size = 0;
	file.open(path, fstream::in);//�������� �����
	if (file.is_open())
	{
		getline(file, str);
		size = stoi(str);
		for (int i = 0;i < size;i++)
		{
			//���������� ����� �� �����
			//stoi - ����������� ��������� � ������
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
			arr->push_back(tv);//���������� � ������
		}
		file.close();//�������� �����
	}
}
void television::search(vector<television>* arr, int var_search, string field)//����� ������
{
	for (auto& e : *arr)
	{
		switch (var_search)//����
		{
		case 1:
			if (e.name_programm == field)//��������� ���� ������� � ���������� ��������
			{
				e.printData();
			}
			break;
		case 2:
			if (e.leader == field)//��������� ���� ������� � ���������� ��������
			{
				e.printData();
			}
			break;
		case 3:
			if (e.channel == stoi(field))//��������� ���� ������� � ���������� ��������
			{
				e.printData();
			}
			break;
		case 4:
			if (e.day_release == field)//��������� ���� ������� � ���������� ��������
			{
				e.printData();
			}
			break;
		case 5:
			if (e.time_release == stoi(field))//��������� ���� ������� � ���������� ��������
			{
				e.printData();
			}
			break;
		case 6:
			if (e.duration == stoi(field))//��������� ���� ������� � ���������� ��������
			{
				e.printData();
			}
			break;
		case 7:
			if (e.rating == stoi(field))//��������� ���� ������� � ���������� ��������
			{
				e.printData();
			}
			break;
		default:
			cout << "������ �� �������" << endl;
			break;
		}
	}
}
void television::sort_field(vector<television>* arr, int var_sort)//���������� ����
{
	switch (var_sort)//����
	{
	case 1:
		sort(arr->begin(), arr->end(), [](const television& t1, const television& t2) {return t1.name_programm > t2.name_programm;});//����������
		break;
	case 2:
		sort(arr->begin(), arr->end(), [](const television& t1, const television& t2) {return t1.leader > t2.leader;});//����������
		break;
	case 3:
		sort(arr->begin(), arr->end(), [](const television& t1, const television& t2) {return t1.channel > t2.channel;});//����������
		break;
	case 4:
		sort(arr->begin(), arr->end(), [](const television& t1, const television& t2) {return t1.day_release > t2.day_release;});//����������
		break;
	case 5:
		sort(arr->begin(), arr->end(), [](const television& t1, const television& t2) {return t1.time_release > t2.time_release;});//����������
		break;
	case 6:
		sort(arr->begin(), arr->end(), [](const television& t1, const television& t2) {return t1.duration > t2.duration;});//����������
		break;
	case 7:
		sort(arr->begin(), arr->end(), [](const television& t1, const television& t2) {return t1.rating > t2.rating;});//����������
		break;
	default:
		break;
	}
}
float television::find_maxmin(vector<television>* arr, int var_search, int var_sort)//����� ���� ��� ���
{
	float max = 0.0f;
	float min = 1000000.0f;
	switch (var_search)//��� ��� ����
	{
	case 1:
		switch (var_sort)//����
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
			cout << "�������� ����" << endl;
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
			cout << "�������� ����" << endl;
			return 0.0f;
			break;
		}
		break;
	default:
		cout << "�������� ����" << endl;
		return 0.0f;
		break;
	}
	return 0.0f;
}
void menu::print_info()//����� ���������� � ���������� ����
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
void menu::print_field()//����� ���������� � �����
{
	cout << "��������� ���� :" << endl;
	cout << "1 - �������� ���������" << endl;
	cout << "2 - �������" << endl;
	cout << "3 - �����" << endl;
	cout << "4 - ���� ������ � ����" << endl;
	cout << "5 - ����� ������ � ����" << endl;
	cout << "6 - ������������ ���������" << endl;
	cout << "7 - ������� ���������" << endl;
}
void menu::print_field_for_min()//���� ��� ���� ��� ���
{
	cout << "��������� ���� :" << endl;
	cout << "1 - �����" << endl;
	cout << "2 - ����� ������ � ����" << endl;
	cout << "3 - ������������ ���������" << endl;
	cout << "4 - ������� ���������" << endl;
}

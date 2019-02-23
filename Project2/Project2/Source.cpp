#include<iostream>
#include<fstream>
#include<ctime>
#include<vector>
#include<string>
#include<iomanip>
using namespace std;
struct car
{
	int id;
	string mark;
	int age;
	string color;
	string category;
	float price;
	bool old;


};

int main()
{

	setlocale(LC_ALL, "russian");
	vector<car> base;
	ifstream fin;
	fin.open("input.txt");
	if (fin.is_open() == true)
	{
		while (!fin.eof())
		{
			car buf;
			fin >> buf.id;
			fin >> buf.mark;
			fin >> buf.age;
			fin >> buf.color;
			fin >> buf.category;
			fin >> buf.price;
			fin >> buf.old;
			base.push_back(buf);
		}
	}
	else
	{
		cout << "�� ������� ���������" << endl;
		return 0;
	}
	int answer = -1;
	while (answer != 0)
	{
		cout << "����" << endl
			<< "1.����������" << endl
			<< "2.���������� ���������� � ���� " << endl
			<< "3.�������� ���������� �� ���� id/category" << endl
			<< "4.���������� �� ����������" << endl
			<< "5.���������� ���� � ����" << endl
			<< "6.���������� �� ����" << endl
			<< "7.���������� �� ����" << endl
			<< "0.����� " << endl;

		cin >> answer;
		switch (answer)
		{
		case 1:
		{
			for (int i = 0; i < base.size(); i++)
			{
				cout << left << setw(10) << base[i].id << setw(10) << base[i].mark << setw(10) << base[i].age << setw(10) << base[i].color << setw(10) << base[i].category << setw(10) << base[i].price << setw(10) << base[i].old << endl;
			}
			break;
		}
		case 2:
		{
			car to_add;
			cout << "������� id" << endl;
			cin >> to_add.id;
			cout << "������� mark" << endl;
			cin >> to_add.mark;
			cout << "������� age" << endl;
			cin >> to_add.age;
			cout << "������� color " << endl;
			cin >> to_add.color;
			cout << "������� category" << endl;
			cin >> to_add.category;
			cout << "������� price" << endl;
			cin >> to_add.price;
			cout << "������� old(1(��) ??? 0(���))" << endl;
			cin >> to_add.old;
			base.push_back(to_add);
			break;

		}
		case 3:
		{
			cout << "������� ��" << endl << "1.id" << endl << "2.���������" << endl;
			int ans = 0;
			cin >> ans;
			switch (ans)
			{
			case 1:
			{
				cout << "������� id" << endl;
				int id;
				cin >> id;
				for (int i = 0; i < base.size(); i++)
				{
					if (base[i].id == id)
					{
						base.erase(base.begin() + 1);
						break;
					}
				}
			}
			case 2:
			{
				cout << "������� ��������� " << endl;
				string category;
				cin >> category;
				for (int i = 0; i < base.size(); i++)
				{
					if (base[i].category == category)
					{
						base.erase(base.begin() + 1);
						break;
					}
				}
			}
			}
		case 4:
		{
			string cat;
			cout << "������� ���������" << endl;
			cin >> cat;
			for (int i = 0; i < base.size(); i++)
			{
				if (base[i].category == cat)
				{
					cout << left << setw(10) << base[i].id << setw(10) << base[i].mark << setw(10) << base[i].age << setw(10) << base[i].color << setw(10) << base[i].category << setw(10) << base[i].price << setw(10) << base[i].old << endl;
				}
			}
			break;
		}
		case 5:
		{
			ofstream fout;
			fout.open("input.txt");
			for (int i = 0; i < base.size(); i++)
			{
				fout << left << setw(10) << base[i].id << setw(10) << base[i].mark << setw(10) << base[i].age << setw(10) << base[i].color << setw(10) << base[i].category << setw(10) << base[i].price << setw(10) << base[i].old << endl;
			}
			fout.close();
			break;
		}
		case 6:
		{
			for (int i = 0; i < base.size() - 1; i++)
			{
				for (int i = 0; i < base.size() - 1; i++)
				{
					if (base[i].age < base[i + 1].age)
					{
						swap(base[i].age, base[i + 1].age);
					}
				}

			}

			break;
		}
		case 7:
		{
			int price = 0;
			cout << "������� ����" << endl;
			cin >> price;
			for (int i = 0; i < base.size(); i++)
			{
				if (base[i].price < price)
				{
					cout << left << setw(10) << base[i].id << setw(10) << base[i].mark << setw(10) << base[i].age << setw(10) << base[i].color << setw(10) << base[i].category << setw(10) << base[i].price << setw(10) << base[i].old << endl;
				}


			}
			break;
		}





		system("pause");
		system("cls");
	}
	
}
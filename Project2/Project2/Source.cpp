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
		cout << "не удается загрузить" << endl;
		return 0;
	}
	int answer = -1;
	while (answer != 0)
	{
		cout << "МЕНЮ" << endl
			<< "1.Распечатка" << endl
			<< "2.Добавление автомобиля в базу " << endl
			<< "3.Удаление автомобиля из базы id/category" << endl
			<< "4.Информация по категориям" << endl
			<< "5.Сохранение базы в файл" << endl
			<< "6.Сортировка по году" << endl
			<< "7.Информация по цене" << endl
			<< "0.Выход " << endl;

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
			cout << "введите id" << endl;
			cin >> to_add.id;
			cout << "введите mark" << endl;
			cin >> to_add.mark;
			cout << "введите age" << endl;
			cin >> to_add.age;
			cout << "введите color " << endl;
			cin >> to_add.color;
			cout << "введите category" << endl;
			cin >> to_add.category;
			cout << "введите price" << endl;
			cin >> to_add.price;
			cout << "введите old(1(да) ??? 0(нет))" << endl;
			cin >> to_add.old;
			base.push_back(to_add);
			break;

		}
		case 3:
		{
			cout << "удалить по" << endl << "1.id" << endl << "2.категории" << endl;
			int ans = 0;
			cin >> ans;
			switch (ans)
			{
			case 1:
			{
				cout << "введите id" << endl;
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
				cout << "введите категорию " << endl;
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
			cout << "введите категорию" << endl;
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
			cout << "введите цену" << endl;
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
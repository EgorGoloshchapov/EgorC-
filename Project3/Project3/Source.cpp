#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<ctime>
using namespace std; 
int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	ofstream fout;
	fout.open("input.txt");
	int n; 
	cout << "введите кол-во чисел" << endl;
	cin >> n;
	for (int i = 0;i < n; i++)
	{
		fout << rand() << endl;
	}
	fout.close();
		



	system("pause");
}
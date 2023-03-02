#include "Tree23.h"
#include <conio.h>
#include <iostream>
#include <math.h>
namespace TestEffect
{
	void test_rand(int n);
	void test_sort(int n);
	typedef unsigned long long INT_64;
	INT_64 lrand() { return rand() << 16 | rand(); }
}
//---------------------------------------------------------------------------
//����
void main() {
	T23<int, int> tree;
	T23<int, int>::Iterator it = T23<int, int>::Iterator(&tree);
	T23<int, int>::rIterator rit = T23<int, int>::rIterator(&tree);
	setlocale(LC_ALL, "RUS");
	while (true)
	{
		cout << "1. �������� ������" << endl;
		cout << "2. ������� ������" << endl;
		cout << "3. �������� �� �������" << endl;
		cout << "4. ����� ������ � �������� ������" << endl;
		cout << "5. ���������� ������ � �������� ������" << endl;
		cout << "6. �������� ������ � �������� ������" << endl;
		cout << "7. ����� ������� ������" << endl;
		cout << "8. ��������" << endl;
		cout << "9. �������� ��������" << endl;
		cout << "10. ������������ (���������)" << endl;
		cout << "11. ������������ (�����������)" << endl;
		int n = 0;
		int t;
		int value, key;
		cin >> t;
		switch (t)
		{
		case 1:
			tree.Show();
			_getch();
			break;
		case 2:
			tree.Clear();
			tree.Show();
			_getch();
			break;
		case 3:
			cout << "������� ������: " << tree.IsEmpty() << endl;
			_getch();
			break;
		case 4:
			cin >> key;
			try
			{
				cout << "��������� ��������: " << tree.GetData(key) << endl;
			}
			catch (TreeException e)
			{
				cerr << e.What() << endl;
			}
			_getch();
			break;
		case 5:
			cin >> key;
			cin >> value;
			cout << "������ �������� �������: " << tree.Insert(key, value) << endl;
			tree.Show();

			_getch();
			break;
		case 6:
			cin >> key;
			cout << "������ �������� ��������: " << tree.Delete(key) << endl;
			tree.Show();

			_getch();
			break;
		case 7:
			cout << "������ ������: " << tree.GetSize() << endl;
			_getch();
			break;
		case 8: {
			system("cls");
			bool exit = false;
			while (!exit) {
				cout << "1. �������� ��������" << endl;
				cout << "2. ��������� �� ������" << endl;
				cout << "3. ��������� �� ����������" << endl;
				cout << "4. ���������" << endl;
				cout << "5. ����������" << endl;
				cout << "6. �������� ���������" << endl;
				cout << "7. ��������� ������" << endl;

				int it_t;
				cin >> it_t;
				switch (it_t) {
				case 1:
					try
					{
						cout << *it << endl;
					}
					catch (TreeException e)
					{
						cerr << e.What() << endl;
					}
					break;
				case 2:
					it.beg();
					break;
				case 3:
					it.end();
					break;
				case 4:
					it.next();
					break;
				case 5:
					it.prev();
					break;
				case 6:
					cout << it.IsOff() << endl;
					_getch();
					break;
				case 7:
					cin >> value;
					try {
						*it = value;
					}
					catch (TreeException e)
					{
						cerr << e.What() << endl;
					}
					break;
				default:
					exit = true;
					system("cls");
					break;
				}
			}
		}
				break;
		case 9: {
			system("cls");
			bool exit = false;
			while (!exit) {
				cout << "1. �������� ��������" << endl;
				cout << "2. ��������� �� ������" << endl;
				cout << "3. ��������� �� ����������" << endl;
				cout << "4. ���������" << endl;
				cout << "5. ����������" << endl;
				cout << "6. �������� ���������" << endl;
				cout << "7. ��������� ������" << endl;

				int it_t;
				cin >> it_t;
				switch (it_t) {
				case 1:
					try
					{
						cout << *rit << endl;
					}
					catch (TreeException e)
					{
						cerr << e.What() << endl;
					}
					break;
				case 2:
					rit.beg();
					break;
				case 3:
					rit.end();
					break;
				case 4:
					rit.next();
					break;
				case 5:
					rit.prev();
					break;
				case 6:
					cout << rit.IsOff() << endl;
					_getch();
					break;
				case 7:
					cin >> value;
					try {
						*rit = value;
					}
					catch (TreeException e)
					{
						cerr << e.What() << endl;
					}
					break;
				default:
					exit = true;
					system("cls");
					break;
				}
			}
		}
				break;
		case 10:
			int n;
			cout << "������� ������ ������:" << endl;
			cin >> n;
			TestEffect::test_rand(n);
			break;
		case 11:
			cout << "������� ������ ������:" << endl;
			cin >> n;
			TestEffect::test_sort(n);
			break;
		default:
			exit(0);
		}
	}
}
void TestEffect::test_rand(int n)
{
	T23<INT_64, int> tree;

	INT_64* m = new INT_64[n];

	for (int i = 0; i < n; i++)
	{
		m[i] = lrand();
		tree.Insert(m[i], 1);
	}
	tree.getCountNodesView();
	cout << "������ ������ ��: " << tree.GetSize() << endl;

	double I = 0;
	double D = 0;
	double S = 0;

	for (int i = 0; i < n / 2; i++)
		if (i % 10 == 0)
		{
			tree.Delete(lrand());
			D += tree.getCountNodesView();
			tree.Insert(m[rand() % n], 1);
			I += tree.getCountNodesView();
			try
			{
				tree.GetData(lrand());
				S += tree.getCountNodesView();
			}
			catch (TreeException&) { S += tree.getCountNodesView(); }
		}
		else
		{
			int ind = rand() % n;
			tree.Delete(m[ind]);
			D += tree.getCountNodesView();
			INT_64 key = lrand();
			tree.Insert(key, 1);
			I += tree.getCountNodesView();
			m[ind] = key;
			try {
				tree.GetData(m[rand() % n]);
				S += tree.getCountNodesView();
			}
			catch (TreeException&) { S += tree.getCountNodesView(); }

		}


	cout << "������ ������ �����: " << tree.GetSize() << endl;
	cout << "log2(n)=" << (log((double)n) / log(2.0)) << endl;
	cout << "log3(n)=" << (log((double)n) / log(3.0)) << endl;
	cout << "�������: " << I / (n / 2) << endl;
	cout << "��������: " << D / (n / 2) << endl;
	cout << "�����: " << S / (n / 2) << endl;
	delete[] m;
}

void TestEffect::test_sort(int n)
{
	T23<INT_64, int> tree;
	INT_64* m = new INT_64[n];

	for (int i = 0; i < n; i++) {
		m[i] = i * 1000;
		tree.Insert(m[i], 1);
	}
	tree.getCountNodesView();
	double I = 0;
	double D = 0;
	double S = 0;
	cout << "������ ������ ��: " << tree.GetSize() << endl;
	for (int i = 0; i < n / 2; i++)
	{
		if (i % 10 == 0)
		{
			INT_64 k = lrand() % (1000 * n);
			k = k + !(k % 2);
			tree.Delete(k);
			D += tree.getCountNodesView();
			tree.Insert(m[rand() % n], 1);
			I += tree.getCountNodesView();
			k = lrand() % (1000 * n);
			k = k + !(k % 2);
			try {
				tree.GetData(k);
				S += tree.getCountNodesView();
			}
			catch (TreeException&) { S += tree.getCountNodesView(); }
		}
		else
		{
			int ind = rand() % n;
			try
			{
				tree.GetData(m[rand() % n]);
				S += tree.getCountNodesView();
			}
			catch (TreeException&) { S += tree.getCountNodesView(); }
			tree.Delete(m[ind]);
			D += tree.getCountNodesView();
			int k = lrand() % (1000 * n);
			k = k + k % 2;
			tree.Insert(k, 1);
			I += tree.getCountNodesView();
			m[ind] = k;

		}
	}
	cout << "������ ������ �����: " << tree.GetSize() << endl;
	cout << "log2(n)=" << (log((double)n) / log(2.0)) << endl;
	cout << "log3(n)=" << (log((double)n) / log(3.0)) << endl;
	cout << "�������: " << I / (n / 2) << endl;
	cout << "��������: " << D / (n / 2) << endl;
	cout << "�����: " << S / (n / 2) << endl;
	delete[] m;
}

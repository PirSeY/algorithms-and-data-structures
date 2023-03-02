#include <iostream>
#include "List.h"
#include <string>
#include <clocale>

using namespace std;

void loop() {
	List<string> list;
	string el;
	int parameter;
	bool result = false;
	int position;
	bool flag = 1;
	while (flag) {
		cout << "��������! ��������� � ������ ���������� � 1!" << endl;
		cout << "0 - �����" << endl;
		cout << "1 - ��������" << endl;
		cout << "2 - �������� �� �������" << endl;
		cout << "3 - ������� �������" << endl;
		cout << "4 - ������� � �������" << endl;
		cout << "5 - ������� �� �����" << endl;
		cout << "6 - ��������" << endl;
		cout << "7 - ������� ��������" << endl;
		cout << "8 - �������� ������� �� �������" << endl;
		cout << "9 - ������� �������� � ������" << endl;
		cout << "10 - ������ �� ������" << endl;
		cout << "11 - ������ ������" << endl;
		cout << "12 - ������� ������" << endl;
		cout << "13 - ����� ���������" << endl;
		cin >> parameter;
		if (parameter > 13 || parameter < 0) {
			cout << "������������ �����" << endl;
			cin.get();
			cin.get();
			continue;
		}
		switch (parameter)
		{
		case 0:
			flag = 0;
			break;
		case 1: // insert
			cout << "������� �������" << endl;
			cin >> el;
			list.insert(el);
			break;
		case 2: // insert pos
			cout << "������� ������� � �������" << endl;
			cin >> el >> parameter;
			try {
				list.insert(el, parameter);
			}
			catch (overflow_error& err) {
				cout << err.what() << endl;
				cin.get();
				cin.get();
			}
			break;
		case 3: // remove
			cout << "������� �������" << endl;
			cin >> el;
			try {
				list.remove(el);
			}
			catch (overflow_error& err) {
				cout << err.what() << endl;
				cin.get();
				cin.get();
			}
			break;
		case 4: // remove pos
			cout << "������� �������" << endl;
			cin >> parameter;
			try {
				list.remove_from(parameter);
			}
			catch (overflow_error& err) {
				cout << err.what() << endl;
				cin.get();
				cin.get();
			}
			break;
		case 5: // print
			try {
				list.print();
			}
			catch (overflow_error& err) {
				cout << err.what() << endl;
			}
			cin.get();
			cin.get();
			break;
		case 6: // change         
			cout << "������� ������� � �������" << endl;
			cin >> el >> parameter;
			try {
				list.change(el, parameter);
			}
			catch (overflow_error& err) {
				cout << err.what() << endl;
				cin.get();
				cin.get();
			}
			break;
		case 7: // position        
			cout << "������� �������" << endl;
			cin >> el;
			try {
				cout << list.position(el);
			}
			catch (overflow_error& err) {
				cout << err.what() << endl;
			}
			cin.get();
			cin.get();
			break;
		case 8: // get              
			cout << "������� �������" << endl;
			cin >> parameter;
			try {
				cout << list.get(parameter) << endl;
			}
			catch (overflow_error& err) {
				cout << err.what() << endl;
			}
			cin.get();
			cin.get();
			break;
		case 9: // contains
			cout << "������� �������" << endl;
			cin >> el;
			result = list.contains(el);
			if (result == true) cout << "��������" << endl;
			else cout << "�� ��������" << endl;
			cin.get();
			cin.get();
			break;
		case 10: // is empty
			result = list.isEmpty();
			if (result == 1) cout << "������ �����" << endl;
			else cout << "������ �� ������" << endl;
			cin.get();
			cin.get();
			break;
		case 11: // size
			cout << "������ ������= " << list.size() << endl;
			cin.get();
			cin.get();
			break;
		case 12://clear list
			list.clear();
			cout << "������ ������" << endl;
			cin.get();
			cin.get();
			break;
		case 13:
			List <string>::Iterator iter = list.begin();//������� ��������
			List <string>::Iterator iterEnd = list.end();
			int exit = 1;
			int nom;
			string h;
			while (exit) {
				cout << "����" << endl;
				cout << "��� ��������� ��������� � ������ ������ ������� 1" << endl;
				cout << "��� �������� ��������� end() ������� 2" << endl;
				cout << "��� ������ ��������,�� ������� ��������� ��������, ������� 3" << endl;
				cout << "��� ������������ ��������� ����� ������� 4" << endl;
				cout << "��� ������������ ��������� ����� ������� 5" << endl;
				cout << "��� ������� �������� ��������� ������� 6" << endl;
				cout << "��� ��������� � ���������� end() ������� 7" << endl;
				cout << "��� ������ ������� 8" << endl;
				cin >> nom;
				if (nom > 8 || nom < 1) {
					cout << "������������ �����" << endl;
					cin.get();
					continue;
				}
				switch (nom) {
				case 1:
					iter = list.begin();
					cout << "�������� ���������� �� ������ ������" << endl;
					cin.get();
					cin.get();
					break;

				case 2:
					iter = list.end();
					cout << "������ �������� end()" << endl;
					cin.get();
					cin.get();
					break;

				case 3:
					try {
						cout << *iter;
						cout << "- �� ���� ������� ��������� �������� ";
					}
					catch (std::overflow_error& err) {
						std::cout << err.what() << std::endl;
					}
					cin.get();
					cin.get();
					break;
				case 4:
					try {
						++iter;
					}
					catch (std::overflow_error& err) {
						cout << err.what() << endl;
					}
					cin.get();
					cin.get();
					break;
				case 5:
					try {
						--iter;
					}
					catch (std::overflow_error& err) {
						cout << err.what() << endl;
					}
					cin.get();
					cin.get();
					break;
				case 6:
					try {
						cout << "������� ��������- " << endl;
						cin >> h;
						*iter = h;
					}
					catch (std::overflow_error& err) {
						cout << err.what() << endl;
						cin.get();
						cin.get();
					}
					break;

				case 7:
					if (iter == iterEnd) cout << "��������� �����" << endl;
					else cout << "��������� �� �����" << endl;
					cin.get();
					cin.get();
					break;
				case 8:
					exit = 0;
					break;
				}
			}
			break;
		}
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	loop();
}
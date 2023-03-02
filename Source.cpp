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
		cout << "Внимание! Нумерация в списке начинается с 1!" << endl;
		cout << "0 - выход" << endl;
		cout << "1 - вставить" << endl;
		cout << "2 - вставить на позицию" << endl;
		cout << "3 - удалить элемент" << endl;
		cout << "4 - удалить с позиции" << endl;
		cout << "5 - вывести на экран" << endl;
		cout << "6 - изменить" << endl;
		cout << "7 - позиция элемента" << endl;
		cout << "8 - получить элемент по позиции" << endl;
		cout << "9 - наличие элемента в списке" << endl;
		cout << "10 - пустой ли список" << endl;
		cout << "11 - размер списка" << endl;
		cout << "12 - очистка списка" << endl;
		cout << "13 - вызов итератора" << endl;
		cin >> parameter;
		if (parameter > 13 || parameter < 0) {
			cout << "Неправильный выбор" << endl;
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
			cout << "Введите элемент" << endl;
			cin >> el;
			list.insert(el);
			break;
		case 2: // insert pos
			cout << "Введите элемент и позицию" << endl;
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
			cout << "Введите элемент" << endl;
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
			cout << "Введите позицию" << endl;
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
			cout << "Введите элемент и позицию" << endl;
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
			cout << "Введите элемент" << endl;
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
			cout << "Введите позицию" << endl;
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
			cout << "Введите элемент" << endl;
			cin >> el;
			result = list.contains(el);
			if (result == true) cout << "Содержит" << endl;
			else cout << "Не содержит" << endl;
			cin.get();
			cin.get();
			break;
		case 10: // is empty
			result = list.isEmpty();
			if (result == 1) cout << "Список путой" << endl;
			else cout << "Список не пустой" << endl;
			cin.get();
			cin.get();
			break;
		case 11: // size
			cout << "Размер списка= " << list.size() << endl;
			cin.get();
			cin.get();
			break;
		case 12://clear list
			list.clear();
			cout << "Список очищен" << endl;
			cin.get();
			cin.get();
			break;
		case 13:
			List <string>::Iterator iter = list.begin();//Создаем итератор
			List <string>::Iterator iterEnd = list.end();
			int exit = 1;
			int nom;
			string h;
			while (exit) {
				cout << "Меню" << endl;
				cout << "Для установки итератора в начало списка нажмите 1" << endl;
				cout << "Для создания итератора end() нажмите 2" << endl;
				cout << "Для вывода элемента,на который указывает итератор, нажмите 3" << endl;
				cout << "Для передвижения итератора вперёд нажмите 4" << endl;
				cout << "Для передвижения итератора назад нажмите 5" << endl;
				cout << "Для задания значения итератору нажмите 6" << endl;
				cout << "Для сравнения с итератором end() нажмите 7" << endl;
				cout << "Для выхода нажмите 8" << endl;
				cin >> nom;
				if (nom > 8 || nom < 1) {
					cout << "Неправильный выбор" << endl;
					cin.get();
					continue;
				}
				switch (nom) {
				case 1:
					iter = list.begin();
					cout << "Итератор установлен на начало списка" << endl;
					cin.get();
					cin.get();
					break;

				case 2:
					iter = list.end();
					cout << "Создан итератор end()" << endl;
					cin.get();
					cin.get();
					break;

				case 3:
					try {
						cout << *iter;
						cout << "- На этот элемент указывает итератор ";
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
						cout << "Введите значение- " << endl;
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
					if (iter == iterEnd) cout << "Итераторы равны" << endl;
					else cout << "Итераторы не равны" << endl;
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
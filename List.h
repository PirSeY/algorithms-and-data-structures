#pragma once
#include <iostream>

using namespace std;

template<class T> class List {
private:
	class Node {//элемент списка
	public:
		T element; //значение элемента
		Node* next; //указатель на следующий элемент списка
		Node* pred;
		Node(); //пустой конструктор 
		Node(const T); //конструктор со значением
		~Node(); //деструктор
	};
	Node* _begin; //указатель на начало списка
	int _size; //размер списка
	mutable int _iterations; //количество итераций
	friend class Node;
	friend class Iterator;

public:
	class Iterator {
	public:
		Node* current; //указатель на элемент списка
		Iterator(Node*&); //конструктор
		Iterator(List& lst); //конструктор
		~Iterator(); //деструктор 
		Iterator(); //пустой конструктор
		T& operator* (); //возврат значения 
		Iterator& operator++(); //перемещение итератора вперёд
		Iterator& operator--(); //перемещение итератора назад
		bool operator ==(const Iterator&); //сравнение итераторов на равенство
		bool operator !=(const Iterator&); //сравнение итераторов на неравенство
	};
	List(); //конструктор списка
	List(const List&); //конструктор копирования списка
	~List(); //деструктор списка
	int size() const; //возврат размера списка
	void clear(); //очистка списка
	bool isEmpty() const; //проверка списка на пустоту
	bool contains(const T&) const; //наличие значения 
	T get(const int) const; //возврат элемента по позиции
	void change(const T&, const int);//замена
	int position(const T&);//возврат позиции
	void insert(const T&);//вставка
	void insert(const T&, int);//вставка по позиции
	void remove(const T&);//удаление элемента
	void remove_from(const int);//удаление элемента по позиции
	Iterator& begin();//установка итератора в начало списка
	Iterator& end();//установка итератора в конец списка
	void print() const;//вывод списка
};

template<class T> List<T>::Node::Node() {
	_begin = nullptr;
	next = nullptr;
	pred = nullptr;
	_size = 0;
}

template<class T> List<T>::Node::Node(const T el) {
	element = el;
	next = nullptr;
	pred = nullptr;
}

template<class T> List<T>::Node::~Node() {
}

template<class T> List<T>::Iterator::Iterator(Node*& cur) {
	if (cur != NULL)
		current = cur;
	else {
		current = nullptr;
	}
}

template<class T> List<T>::Iterator::~Iterator() {
}
template<class T> List<T>::Iterator::Iterator() {
	current = nullptr;

}
template<class T> List<T>::Iterator::Iterator(List& lst) {
	current = lst._begin;
}

template<class T> T& List<T>::Iterator::operator*() {
	if (current == nullptr) throw overflow_error("Итератор не установлен.");
	return current->element;
}


template<class T> typename List<T>::Iterator& List<T>::Iterator::operator++() {
	if (current == nullptr) {
		throw overflow_error("Итератор не установлен.");
	}
	current = current->next;
	cout << "Итератор передвинут вперёд";
	return *this;
}

template<class T> typename List<T>::Iterator& List<T>::Iterator::operator--() {
	if (current == nullptr) {
		throw overflow_error("Итератор не установлен.");
	}
	if (current->next != nullptr) {
		Node* t;
		t = current;
		while (t->next != current)
			t = t->next;
		current = t;
		cout << "Итератор передвинут назад";
		return *this;
	}
}

template<class T> bool List<T>::Iterator::operator==(const Iterator& second) {
	return this->current == second.current;
}

template<class T> bool List<T>::Iterator::operator!=(const Iterator& second) {
	return this->current != second.current;
}

template<class T> typename List<T>::Iterator& List<T>::begin() {
	return *(new Iterator(_begin));
}

template<class T> typename List<T>::Iterator& List<T>::end() {
	return *(new Iterator());
}

template<class T> List<T>::List() {
	_size = 0;
	_begin = nullptr;
	_iterations = 0;
}

template<class T> List<T>::List(const List& list) {
	clear();
	Node* tmp = list._begin;
	while (tmp->next != list._begin) {
		insert(tmp->element);
		tmp = tmp->next;
	}
	_size = list._size;
}

template<class T> List<T>::~List() {
	clear();
}

template<class T> int List<T>::size() const {
	return _size;
}

template<class T> void List<T>::clear() {
	if (_begin == nullptr) return;
	for (int i = 0; i < _size - 1; i++) {
		Node* tmp = _begin;
		_begin = _begin->next;
		delete tmp;
	}
	_begin->next == nullptr;
	delete _begin;
	_begin = nullptr;
	_size = 0;
	_iterations = 0;
}

template<class T> bool List<T>::isEmpty() const {
	return _size == 0;
}

template<class T> bool List<T>::contains(const T& el) const {
	if (_begin == nullptr) return false;
	Node* tmp = _begin;
	while (tmp->next != _begin) {
		if (tmp->element == el) return true;
		tmp = tmp->next;
	}
	if (tmp->element == el) return true;
	return false;
}

template<class T> T List<T>::get(const int pos) const {

	if (pos > _size || (pos <= 0))  throw overflow_error("Ошибка!Вы ввели неверную позицию.");
	Node* tmp = _begin;
	for (size_t i = 1; i < pos; i++) tmp = tmp->next;
	return tmp->element;
}

template<class T> void List<T>::change(const T& el, const int pos) {
	if ((pos > _size) || (pos <= 0)) {
		throw overflow_error("Ошибка!Вы ввели неверную позицию.");
	}
	Node* tmp = _begin;
	for (size_t i = 1; i < pos; i++) tmp = tmp->next;
	tmp->element = el;
}

template<class T> int List<T>::position(const T& el) {
	size_t pos = 1;
	Node* tmp = _begin;
	if (_begin == NULL) {
		throw overflow_error("Список пустой.");
	}
	while (tmp->next != _begin) {
		if (tmp->element == el) {
			return pos;
		}
		pos++;
		_iterations++;
		tmp = tmp->next;
	}
	if (tmp->element == el) {
		_iterations++;
		return pos;
	}
	throw overflow_error("Ошибка!Данного элемента нет в списке.");
}

template<class T> void List<T>::insert(const T& el) {
	if (_begin == nullptr) {
		_begin = new Node(el);
		_begin->next = _begin;
		_begin->pred = _begin;
	}
	else {
		Node* tm = _begin;
		Node* tmp = new Node(el);
		while (tm->next != _begin)
			tm = tm->next;
		tm->next = tmp;
		tmp->next = _begin;
		tmp->pred = tm;
		_begin->pred = tmp;
	}
	_size++;
}

template<class T> void List<T>::insert(const T& el, int pos) {
	if ((pos > _size + 1) || (pos <= 0)) {
		throw overflow_error("Ошибка!Вы ввели неверную позицию.");
	}
	else {
		if (_begin == nullptr) {
			_begin = new Node(el);
			_begin->next = _begin;
			_begin->pred = _begin;
		}
		else {
			if (pos == _size + 1) {
				Node* tmp = _begin;
				for (size_t i = 0; i < pos - 2; i++) {
					tmp = tmp->next;
					_iterations++;
				}
				_iterations++;
				Node* newNode = new Node(el);
				tmp->next = newNode;
				newNode->next = _begin;
				newNode->pred = tmp;
				_begin->pred = newNode;
			}
			else {
				if (pos == 1) {
					Node* tmp1 = _begin;
					Node* tmp = _begin->pred;
					Node* newNode = new Node(el);
					tmp->next = newNode;
					newNode->next = tmp1;
					tmp1->pred = newNode;
					newNode->pred = tmp;
					_begin = newNode;

				}
				else {
					Node* tmp = _begin;
					Node* tmp1 = tmp->next;
					for (size_t i = 1; i < pos - 1; i++) {
						tmp1 = tmp1->next;
						tmp = tmp->next;
						_iterations++;
					}
					_iterations++;
					Node* newNode = new Node(el);
					tmp->next = newNode;
					newNode->next = tmp1;
					newNode->pred = tmp;
					tmp1->pred = newNode;
				}
			}
		}
	}
	_size++;
}

template<class T> void List<T>::remove(const T& el) {
	if (_begin == nullptr) {
		throw overflow_error("Список пустой.");
	}
	Node* tmp = _begin->next;
	Node* tmpPrev = _begin;
	Node* tmpNext = tmp->next;
	if (_begin->element == el) {
		if (_begin->next == _begin) {
			_begin->next == nullptr;
			_begin->pred = nullptr;
			_begin = nullptr;
		}
		else {
			while (tmpPrev->next != _begin) {
				tmpPrev = tmpPrev->next;
			}
			tmp = _begin;
			_begin = _begin->next;
			tmp->next = nullptr;
			tmp->pred = nullptr;
			tmpPrev->next = _begin;
			_begin->pred = tmpPrev;
			delete tmp;
		}
		_size--;
		return;
	}
	while (tmp != _begin) {
		if (tmp->element == el) {
			tmpPrev->next = tmp->next;
			tmpNext->pred = tmpPrev;
			tmp->next = nullptr;
			tmp->pred = nullptr;
			delete tmp;
			_size--;
			return;
		}
		tmp = tmp->next;
		tmpPrev = tmpPrev->next;
		tmpNext = tmpNext->next;
	}
	throw overflow_error("Ошибка!Данного элемента нет в списке.");
	cout << "Ошибка!Данного элемента нет в списке" << endl;
	cin.get();
	cin.get();
}

template<class T> void List<T>::remove_from(const int pos) {
	if (_begin == NULL) {
		throw overflow_error("Список пустой.");
	}
	if (pos > _size || pos <= 0)
		throw overflow_error("Ошибка!Неверная позиция");
	if (pos == 1) {
		if (_begin->next != _begin) {
			Node* tmp = _begin;
			Node* tmp1 = _begin;
			while (tmp1->next != _begin)
				tmp1 = tmp1->next;
			_begin = _begin->next;
			delete tmp;
			tmp1->next = _begin;
			_begin->pred = tmp1;
			_iterations++;
		}
		else {
			delete _begin;
			_begin = nullptr;
			_iterations++;
		}
	}
	else {
		Node* tmp = _begin;
		Node* tmp1 = _begin->next;
		Node* tmp2 = tmp1->next;
		for (int i = 1; i < pos - 1; i++) {
			tmp = tmp->next;
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
			_iterations++;
		}
		_iterations++;
		tmp->next = tmp1->next;
		tmp2->pred = tmp;
		delete tmp1;
	}
	_size--;
}

template<class T> void List<T>::print() const {
	if (_begin == nullptr)
		throw overflow_error("Список пустой.");
	else {
		Node* tmp = _begin;
		_iterations++;
		while (tmp->next != _begin) {
			_iterations++;
			cout << tmp->element << " ";
			tmp = tmp->next;
		}
		cout << tmp->element << " ";
		cout << endl;
	}
}

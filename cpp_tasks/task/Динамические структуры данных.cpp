#include <iostream>

using namespace std;

/*
Основываясь на структуре списка создать динамическую структуру данных. 
Программа обязательно должна включать добавление элементов, 
удаление элементов, вывод элементов на экран, 
поиск элемента по индексу и поиск элементов по значению элемента.
Реализовать необходимо как шаблонный класс объектов - обобщение.
*/

template <class T>
struct Element
{
	T data; 
	Element<T>* next;
	Element<T>* prev;
};

template <class T>
class List
{
private:
	Element<T>* begin; // указатель на первый элемент списка
	Element<T>* end; // указатель на последний элемент списка
	int count; // количество элементов в списке

	// Метод, возвращающий элемент в заданной позиции, считается что позиция корректна.
	Element<T>* Move(int index);

	// Метод, копирующий список
	void Copy(const List<T>& obj);

	// Метод, проверяющий корректность позиии (индекса) в списке
	bool CorrectIndex(int index);

public:
	// Конструктор
	List();

	// Конструктор копирования
	List(const List& obj);

	// Оператор копирования
	List<T>& operator=(const List& obj);

	T& operator[](const int index);

	// Деструктор
	~List();


	// Получить элемент списка по индексу
	T GetElement(int index);

	// Изменить значение элемента в заданной позиции
	void SetElement(T _data, int index);

	// Добавить элемент в конец списка
	void AddEnd(T _data);

	// Добавить элемент в начало списка
	void AddBegin(T _data);

	// Вставка элемента в заданную позицию списка
	void Insert(T _data, int index);

	// Удалить элемент в заданной позиции, позиция нумеруется с 0
	void Del(int index);

	// Очистка списка
	void Clear();

	// Вывод списка
	void Print(string msg);

	// Получить количество элементов списка
	int Count();

};

template <class T>
Element<T>* List<T>::Move(int index)
{
	// 1. Установить указатель на начало списка
	Element<T>* t = begin;

	// 2. Перемотать в позицию index
	for (int i = 0; i < index; i++)
		t = t->next;

	// 3. Вернуть указатель
	return t;
}

template <class T>
void List<T>::Copy(const List<T>& obj)
{
	// 1. Очистить список (освободить память)
	Clear();

	// 2. Цикл копирования this <= obj
	Element<T>* t = obj.begin;

	while (t != nullptr)
	{
		AddEnd(t->data);
		t = t->next;
	}
}

template <class T>
bool List<T>::CorrectIndex(int index)
{
	return (index >= 0) && (index < count);
}

template <class T>
List<T>::List()
{
	// Создать пустой список
	begin = end = nullptr;
	count = 0;
}

template <class T>
List<T>::List(const List& obj)
{
	// Сделать копию из списка
	Copy(obj);
}

template <class T>
List<T>& List<T>::operator=(const List& obj)
{
	Copy(obj);
	return *this;
}

template<class T>
T & List<T>::operator[](const int index)
{

	try
	{
		Element<T>* t = begin;
		int counter = 0;
		while (t != nullptr)
		{
			if (counter == index)
			{
				return t->data;
			}
			t = t->next;
			counter++;
		}
	}
	catch (bad_alloc e)
	{
		// Если память не выделена, то вывести системное сообщение
		cout << e.what() << endl;
	}
}

template <class T>
List<T>::~List()
{
	Clear(); // очистить список
}

template <class T>
T List<T>::GetElement(int index)
{
	// Проверка, корректен ли индекс,
	// если индекс не корректен, сгенерировать исключение
	if (!CorrectIndex(index))
		throw out_of_range("Incorrect index.");

	// Если индекс корректен, то вернуть элемент
	Element<T>* t = Move(index);
	return t->data;
}

// Изменить значение элемента в указанной позиции
template <class T>
void List<T>::SetElement(T _data, int index)
{
	// Проверка, корректна ли позиция
	if (!CorrectIndex(index))
		return;

	// Получить элемент по позиции и изменить его значение
	Element<T>* t = Move(index);
	t->data = _data;
}

template <class T>
void List<T>::AddEnd(T _data)
{
	try
	{
		// 1. Создать новый элемент с данными _data
		Element<T>* t = new Element<T>;
		t->next = nullptr; // следующего элемента нет
		t->prev = end; // установить предыдущий элемент
		t->data = _data; // записать данные

		// 2. Заполнить поле next пока что последнего элемента
		if (end != nullptr)
			end->next = t;

		// 3. Проверка, есть ли в списке элементы
		if (count == 0)
		{
			// если элементов нет,
			// то это одновременно и начало и конец списка
			begin = end = t;
		}
		else
		{
			// если элементы в списке есть, то это конец списка
			end = t;
		}

		// 3. Увеличить общее количество элементов
		count++;
	}
	catch (bad_alloc e)
	{
		// Если память не выделена, то вывести системное сообщение
		cout << e.what() << endl;
	}
}

template <class T>
void List<T>::AddBegin(T _data)
{
	try
	{
		// 1. Создать новый элемент (новую ячейку памяти)
		// и заполнить его данными
		Element<T>* t = new Element<T>;
		t->data = _data; // данные
		t->prev = nullptr; // предыдущего элемента нет

		// следующий элемент указывает на предыдущий первый
		t->next = begin;

		// 2. Есть ли элементы в списке?
		if (count > 0)
		{
			// если есть, то перенаправить предыдущее начало списка
			begin->prev = t;
			begin = t;
		}
		else
		{
			// если элементов нет, то начало и конец есть тем самым элементом
			begin = end = t;
		}

		// 3. Увеличить общее количество элементов
		count++;
	}
	catch (bad_alloc e)
	{
		// если память не выделена, то обработать ошибку
		cout << e.what() << endl;
	}
}

template <class T>
void List<T>::Insert(T _data, int index)
{
	// 1. Проверка, корректна ли позиция
	if (!CorrectIndex(index))
		return;

	// 2. Проверка, вставка ли в конец списка (по указателю end)
	if (index == count)
	{
		// Добавить данные по указателю end
		AddEnd(_data);
		return;
	}

	// 3. Проверка, вставка ли в начало списка (перед begin)
	if (index == 0)
	{
		AddBegin(_data);
		return;
	}

	try
	{
		// 4. Получить элемент перед позицией вставки
		Element<T>* itemPrev = Move(index - 1);

		// 5. Получить элемент в позиции вставки
		Element<T>* item = Move(index);

		// 6. Создать новый элемент и вставить его в список
		Element<T>* t = new Element<T>;
		t->data = _data;
		t->next = item;
		t->prev = itemPrev;
		itemPrev->next = t;
		item->prev = t;

		// 7. Увеличить количество элементов
		count++;
	}
	catch (bad_alloc e)
	{
		// Если память не выделена, то вывести системное сообщение
		cout << e.what() << endl;
	}
}


template <class T>
void List<T>::Del(int index)
{
	// 1. Проверка, есть ли элементы в списке
	if (count == 0) return;

	// 2. Игнор, если позиция указана неправильно
	if (!CorrectIndex(index))
		return;

	// 3. Перейти к удаляемому элементу
	Element<T>* item = Move(index);

	// 4. Получить предыдущий элемент
	Element<T>* itemPrev = item->prev;

	// 5. Получить следующий элемент
	Element<T>* itemNext = item->next;

	// 6. Проверка, удаляется ли не первый элемент списка
	if ((count > 1) && (itemPrev != nullptr))
		itemPrev->next = itemNext; // обойти элемент item

	// 7. Проверка, удаляется ли не последний элемент списка
	if ((itemNext != nullptr) && (count > 1))
		itemNext->prev = itemPrev;

	// 8. Если удаляется первый элемент
	if (index == 0)
		begin = itemNext;

	// 9. Если удаляется последний элемент
	if (index == count - 1)
		end = itemPrev;

	// 10. Удалить элемент item
	delete item;

	// 11. Уменьшить общее количество элементов
	count--;
}

template <class T>
void List<T>::Clear()
{
	// Нужно count раз удалить первый элемент списка
	int n = count; // сделать копию из count - важно!
	for (int i = 0; i < n; i++)
		Del(0);
}

template <class T>
void List<T>::Print(string msg)
{
	cout << msg << " => ";

	Element<T>* t = begin;
	for (int i = 0; i < count; i++)
	{
		cout << t->data << " ";
		t = t->next;
	}
	cout << endl;
}

template <class T>
int List<T>::Count()
{
	return count;
}

void main() 
{
	setlocale(LC_ALL, "Russian");
	List<double> L1; 
	// Добавить элементы в список
	L1.AddBegin(2.0);
	L1.AddBegin(1.0);
	L1.AddEnd(10.0);
	L1.AddEnd(4.0);
	L1.Print("L1: ");
	
	// Метод определяющий кол-во элементов в списке
	cout << "Кол-во элементов: " << L1.Count() << endl;

	// Вывод числа по индексу с помощью []
	for (int i = 0; i < L1.Count(); i++)
		cout << L1[i] << endl;

	// Вставить элемент в заданную позицию
	L1.Insert(-2.5, 2);
	L1.Print("L1.Insert: ");

	// Получить элемент
	double x = L1.GetElement(3);
	cout << "x = " << x << endl;

	// Замена элемента по индексу
	L1.SetElement(5.0, 0);
	L1.Print("SetElement: ");

	// Очистка списка
	L1.Clear();
	L1.AddEnd(1.0);
	L1.AddEnd(5.0);
	L1.Print("L1: ");

}

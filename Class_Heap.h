// Автор:Высоцкая И.Д.
#pragma once
#include "../Dynam_array/Templ_d_arr.h"
#include <iostream>
#include <stdexcept>

/// Шаблонный класс для реализации минимальной кучи (самый минимальный элемент находится в корне)
/// Свойство кучи: потомок всегда больше или равен предку
template <typename T>
class Heap 
{
private:
	dynamic_array<T> array; // динамический массив для хранения элементов

public:

	/// Конструктор по умолчанию
	Heap()
	{
		size = 0;
	}

	/// Конструктор с параметрами
	/// Сложность: O(n)
	/// const dynamic_array<T>& arr - массив
	Heap(const dynamic_array<T>& arr) : array(arr)
	{
		for (int i = (array.size()) / 2 - 1; i >= 0; --i)
		{
			down(i);
		}
	}

	/// Упорядоченние по условию кучи
	/// Сложность: O(log n)
	/// size_t ind - индекс
	void bubble_up(size_t ind)
	{
		while (ind > 0)
		{
			if (array[ind] < array[(ind - 1) / 2]) // если узел меньше чем его предок
			{
				swap(array[ind], array[(ind - 1) / 2]); // меняем местами
				ind = ((ind - 1) / 2); // переписываем индекс добавленного узла
			}
			else
			{
				break;
			}
		}
	}

	/// Упорядоченние по условию кучи
	/// Сложность: O(log n)
	/// size_t ind - индекс
	void down(size_t ind)
	{
		while (true) {
			size_t min = ind; // текущий минимальный узел
			size_t left = 2 * ind + 1; // левый потомок текущего узла
			size_t right = 2 * ind + 2; // правый потомок текущего узла
			size_t size = array.size();

			if (left < size && array[left] < array[min]) // есть левый потомок и он меньше текущего узла
				min = left;

			if (right < size && array[right] < array[min]) // есть правый потомок и он меньше текущего узла
				min = right;

			if (min != ind) // если нашли узел с наименьшим значением
			{
				swap(array[ind], array[min]); // меняем местами
				ind = min; // новый текущий узел
			}
			else
			{
				break;
			}
		}
	}

	/// Проверка на пустоту
	/// Сложность O(1)
	/// Возвращает 1 - если пустая, 0 - если не пустая
	bool empty()
	{
		if (array.size() == 0)
		{
			return 1;
		}
		return 0;
	}

	/// Определение количества элементов
	/// Сложность: O(n)
	size_t count()
	{
		return array.size();
	}

	/// Вставка в кучу
	/// Сложность: O(log n)
	/// size_t ind - индекс
	void insert(size_t ind)
	{
		array.push_back(ind); // добавляем один узел
		int i = array.size() - 1;
		bubble_up(i); // вставляем элемент по условию минимальной кучи
	}

	/// Обращение к корню/получение минимального элемента
	/// Сложность: O(1)
	T& root()
	{
		if (array.size() < 1)
		{
			throw runtime_error("Пустая куча"); // бросаем исключение
		}
		return array[0]; // возвращаем корень
	}

	/// Удаление корня из кучи
	/// Сложность: O(log n)
	void delite_root()
	{
		if (array.size() < 1)
		{
			throw runtime_error("Пустая куча"); // бросаем исключение
		}
		array.pop_back(); // удаляем корень
		array[0] = array[array.size() - 1]; // ставим на место корня самый правый лист
		array.pop_back(); // удаляем лист
		down(0); // упорядочиваем кучу по условиям кучи
	}

	/// Поиск элемента в куче
	/// Сложность: O(n)
	/// const T& ind - индекс
	size_t find_elem(const T& ind)
	{
		if (array.size() < 1)
		{
			throw runtime_error("Пустая куча"); // бросаем исключение
		}
		for (size_t i = 0; i < array.size(); ++i)
		{
			if (data[i] == ind) // если элемент найден
			{
				return i; // возвращаем индекс элемента
			}
		}
		string s = "Элемент не найден"; // сообщение
		return s; // пишем, что элемент не найден
	}

	/// Вывод кучи из динамического массива
	/// Сложность: O(n)
	void print_heap() const
	{
		for (size_t i = 0; i < array.size(); i++)
		{
			cout << array[i] << " ";
		}
	}
};
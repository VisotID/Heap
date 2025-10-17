// �����:�������� �.�.
#pragma once
#include "../Dynam_array/Templ_d_arr.h"
#include <iostream>
#include <stdexcept>

/// ��������� ����� ��� ���������� ����������� ���� (����� ����������� ������� ��������� � �����)
/// �������� ����: ������� ������ ������ ��� ����� ������
template <typename T>
class Heap 
{
private:
	dynamic_array<T> array; // ������������ ������ ��� �������� ���������

public:

	/// ����������� �� ���������
	Heap()
	{
		size = 0;
	}

	/// ����������� � �����������
	/// ���������: O(n)
	/// const dynamic_array<T>& arr - ������
	Heap(const dynamic_array<T>& arr) : array(arr)
	{
		for (int i = (array.size()) / 2 - 1; i >= 0; --i)
		{
			down(i);
		}
	}

	/// ������������� �� ������� ����
	/// ���������: O(log n)
	/// size_t ind - ������
	void bubble_up(size_t ind)
	{
		while (ind > 0)
		{
			if (array[ind] < array[(ind - 1) / 2]) // ���� ���� ������ ��� ��� ������
			{
				swap(array[ind], array[(ind - 1) / 2]); // ������ �������
				ind = ((ind - 1) / 2); // ������������ ������ ������������ ����
			}
			else
			{
				break;
			}
		}
	}

	/// ������������� �� ������� ����
	/// ���������: O(log n)
	/// size_t ind - ������
	void down(size_t ind)
	{
		while (true) {
			size_t min = ind; // ������� ����������� ����
			size_t left = 2 * ind + 1; // ����� ������� �������� ����
			size_t right = 2 * ind + 2; // ������ ������� �������� ����
			size_t size = array.size();

			if (left < size && array[left] < array[min]) // ���� ����� ������� � �� ������ �������� ����
				min = left;

			if (right < size && array[right] < array[min]) // ���� ������ ������� � �� ������ �������� ����
				min = right;

			if (min != ind) // ���� ����� ���� � ���������� ���������
			{
				swap(array[ind], array[min]); // ������ �������
				ind = min; // ����� ������� ����
			}
			else
			{
				break;
			}
		}
	}

	/// �������� �� �������
	/// ��������� O(1)
	/// ���������� 1 - ���� ������, 0 - ���� �� ������
	bool empty()
	{
		if (array.size() == 0)
		{
			return 1;
		}
		return 0;
	}

	/// ����������� ���������� ���������
	/// ���������: O(n)
	size_t count()
	{
		return array.size();
	}

	/// ������� � ����
	/// ���������: O(log n)
	/// size_t ind - ������
	void insert(size_t ind)
	{
		array.push_back(ind); // ��������� ���� ����
		int i = array.size() - 1;
		bubble_up(i); // ��������� ������� �� ������� ����������� ����
	}

	/// ��������� � �����/��������� ������������ ��������
	/// ���������: O(1)
	T& root()
	{
		if (array.size() < 1)
		{
			throw runtime_error("������ ����"); // ������� ����������
		}
		return array[0]; // ���������� ������
	}

	/// �������� ����� �� ����
	/// ���������: O(log n)
	void delite_root()
	{
		if (array.size() < 1)
		{
			throw runtime_error("������ ����"); // ������� ����������
		}
		array.pop_back(); // ������� ������
		array[0] = array[array.size() - 1]; // ������ �� ����� ����� ����� ������ ����
		array.pop_back(); // ������� ����
		down(0); // ������������� ���� �� �������� ����
	}

	/// ����� �������� � ����
	/// ���������: O(n)
	/// const T& ind - ������
	size_t find_elem(const T& ind)
	{
		if (array.size() < 1)
		{
			throw runtime_error("������ ����"); // ������� ����������
		}
		for (size_t i = 0; i < array.size(); ++i)
		{
			if (data[i] == ind) // ���� ������� ������
			{
				return i; // ���������� ������ ��������
			}
		}
		string s = "������� �� ������"; // ���������
		return s; // �����, ��� ������� �� ������
	}

	/// ����� ���� �� ������������� �������
	/// ���������: O(n)
	void print_heap() const
	{
		for (size_t i = 0; i < array.size(); i++)
		{
			cout << array[i] << " ";
		}
	}
};
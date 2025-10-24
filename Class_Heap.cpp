// Автор:Высоцкая И.Д.
#include <cassert>
#include "Class_Heap.h"

void test()
{
    // Проверка вставки в кучу, определения количества элементов в куче
    Heap<int> heap1; // один элемент
    heap1.insert(9);
    assert(heap1.count() == 1);

    Heap<int> heap2; // несколько элементов
    heap2.insert(2); 
    heap2.insert(3);
    heap2.insert(10);
    heap2.insert(5);
    heap2.insert(8);
    assert(heap2.count() == 5);

    // Проверка на определение пустоты
    Heap<int> heap3; // пустая
    assert(heap1.empty() == 0); // один элемент
    assert(heap2.empty() == 0); // несколько элементов
    assert(heap3.empty() == 1); // пустая

    // Проверка обращения к самому минимальному элементу/ корню кучи
    assert(heap1.root() == 9); // один элемент
    assert(heap2.root() == 2); // несколько элементов
    try // пустая
    {
        heap3.root();
        assert(false);
    }
    catch (const runtime_error&)
    {

    }

    // Проверка поиска элемента в куче
    // один элемент
    assert(heap1.find_elem(9) == 0); // найден
    try // нет такого элемента
    {
        heap1.find_elem(3);
        assert(false);
    }
    catch (const runtime_error&)
    {

    }

    // несколько элементов
    assert(heap2.find_elem(5) == 3); // найден
    assert(heap2.find_elem(3) == 1); // найден
    try // нет такого элемента
    {
        heap2.find_elem(7);
        assert(false);
    }
    catch (const runtime_error&)
    {

    }

    // пустая
    try
    {
        heap3.find_elem(3);
        assert(false);
    }
    catch (const runtime_error&)
    {

    }

    // Проверка удаления корня из кучи
    heap1.delite_root(); // один элемент
    heap2.delite_root(); // несколько элементов
    assert(heap2.count() == 4);
    assert(heap1.count() == 0);
    try // пустая
    {
        heap3.delite_root();
        assert(false);
    }
    catch (runtime_error)
    {

    }

    /// Проверка функции сортировки кучей
    dynamic_array<int> arr; // несколько элементов
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(10);
    arr.push_back(5);
    arr.push_back(8);
    Sort_heap(arr);
    assert(arr[0] == 2);
    assert(arr[4] == 10);

    dynamic_array<int> arr1; // один элемент
    arr1.push_back(3);
    Sort_heap(arr1);
    assert(arr1[0] == 3);

    dynamic_array<int> arr2; // пустая
    Sort_heap(arr2);
    assert(arr2.size() == 0);
}
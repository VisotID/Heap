// Автор:Высоцкая И.Д.
#include <cassert>
#include "Class_Heap.h"

void test()
{
    dynamic_array<int> arr; // один элемент
    arr.push_back(42);
    assert(arr[0] == 42);

    dynamic_array<int> arr; // несколько элементов 
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(10);
    arr.push_back(5);
    arr.push_back(8);


}
// Автор:Высоцкая И.Д.
#include <iostream>
#include "Class_Heap.h"

using namespace std;

int main()
{
    test();
    dynamic_array<int> arr;
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(10);
    arr.push_back(5);
    arr.push_back(8);

    Heap<int> heap(arr);
    Sort_heap(arr);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    heap.print_heap();

}
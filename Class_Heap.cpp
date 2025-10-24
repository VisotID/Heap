// �����:�������� �.�.
#include <cassert>
#include "Class_Heap.h"

void test()
{
    // �������� ������� � ����, ����������� ���������� ��������� � ����
    Heap<int> heap1; // ���� �������
    heap1.insert(9);
    assert(heap1.count() == 1);

    Heap<int> heap2; // ��������� ���������
    heap2.insert(2); 
    heap2.insert(3);
    heap2.insert(10);
    heap2.insert(5);
    heap2.insert(8);
    assert(heap2.count() == 5);

    // �������� �� ����������� �������
    Heap<int> heap3; // ������
    assert(heap1.empty() == 0); // ���� �������
    assert(heap2.empty() == 0); // ��������� ���������
    assert(heap3.empty() == 1); // ������

    // �������� ��������� � ������ ������������ ��������/ ����� ����
    assert(heap1.root() == 9); // ���� �������
    assert(heap2.root() == 2); // ��������� ���������
    try // ������
    {
        heap3.root();
        assert(false);
    }
    catch (const runtime_error&)
    {

    }

    // �������� ������ �������� � ����
    // ���� �������
    assert(heap1.find_elem(9) == 0); // ������
    try // ��� ������ ��������
    {
        heap1.find_elem(3);
        assert(false);
    }
    catch (const runtime_error&)
    {

    }

    // ��������� ���������
    assert(heap2.find_elem(5) == 3); // ������
    assert(heap2.find_elem(3) == 1); // ������
    try // ��� ������ ��������
    {
        heap2.find_elem(7);
        assert(false);
    }
    catch (const runtime_error&)
    {

    }

    // ������
    try
    {
        heap3.find_elem(3);
        assert(false);
    }
    catch (const runtime_error&)
    {

    }

    // �������� �������� ����� �� ����
    heap1.delite_root(); // ���� �������
    heap2.delite_root(); // ��������� ���������
    assert(heap2.count() == 4);
    assert(heap1.count() == 0);
    try // ������
    {
        heap3.delite_root();
        assert(false);
    }
    catch (runtime_error)
    {

    }

    /// �������� ������� ���������� �����
    dynamic_array<int> arr; // ��������� ���������
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(10);
    arr.push_back(5);
    arr.push_back(8);
    Sort_heap(arr);
    assert(arr[0] == 2);
    assert(arr[4] == 10);

    dynamic_array<int> arr1; // ���� �������
    arr1.push_back(3);
    Sort_heap(arr1);
    assert(arr1[0] == 3);

    dynamic_array<int> arr2; // ������
    Sort_heap(arr2);
    assert(arr2.size() == 0);
}
#include <iostream>
#include <vector>
using namespace std;
class maxHeap
{
    public:
    int *arr;
    int size;
    int totalSize;
    maxHeap(int n)
    {
        arr = new int[n];
        size = 0;
        totalSize = n;
    }
    //inserting operation

    void insert(int val)
    {
        if(size == totalSize)
        {
            cout << "Heap Overflow";
            return ;
        }

        arr[size] = val;
        cout << val << " is added to Heap" << endl;
        int index = size;
        size++;


        while(index > 0)
        {
            if(arr[index] > arr[(index - 1)/2])
            {
                swap(arr[index], arr[(index-1)/2]);
                index = (index-1)/2;
            }
            else
            {
                return ;
            }
            
        }
    }

    void display()
    {
        for(int i = 0; i<size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;

    }

    //Heapify 

    void heapify(int index)
    {
        int largest = index;
        int left = 2*index+1;
        int right = 2*right+1;

        if(left < size && arr[largest] < arr[left])
        {
            largest = left;
        }
        if(right < size && arr[largest] < arr[right])
        {
            largest = right;
        }
        if(largest != index)
        {
            swap(arr[index], arr[largest]);
            heapify(largest);
        }

    }

    void erase()
    {
        if(size == 0)
        {
            cout << "Heap Underflow";
            return ;
        }
        arr[0] = arr[size-1];
        size--;
        heapify(0);
    }

};
int main()
{
    maxHeap m(5);
    m.insert(1);
    m.insert(28);
    m.insert(4);
    m.insert(5);
    m.insert(7);
    m.display();

    m.erase();

    m.display();

    m.erase();

    m.display();
    m.erase();
    m.display();
    m.erase();
    m.display();
    m.erase();
    m.display();
    m.erase();

}
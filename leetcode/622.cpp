#include "stdlib.h"
#include <iostream>
using namespace std;

class MyCircularQueue {
private:
    int *data;
    int size;
    int count;
    int top;
    int bottom;
public:
    MyCircularQueue(int k) {
        size = k;
        count = 0;
        data = (int *)malloc(sizeof(int) * k);
        top = 0;
        bottom = 0;
    }
    
    bool enQueue(int value) {
        if (count == size) return false;

        count++;
        data[bottom] = value;
        bottom = (bottom + 1) % size;
        return true;
    }
    
    bool deQueue() {
        if (count == 0) return false;

        count--;
        top = (top + 1) % size;
        return true;
    }
    
    int Front() {
       if (count == 0) return -1; 

       return data[top];
    }
    
    int Rear() {
       if (count == 0) return -1; 

       return data[(bottom + size - 1) % size];
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == size;
    }
};

int main ()
{
    MyCircularQueue* obj = new MyCircularQueue(8);
    obj->enQueue(3);
    obj->enQueue(9);
    obj->enQueue(5);
    obj->enQueue(0);

    obj->deQueue();
    obj->deQueue();

    cout << obj->Rear() << endl;
    cout << obj->Rear() << endl;
}

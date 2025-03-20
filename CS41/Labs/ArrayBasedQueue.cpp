#include <iostream>
using namespace std;

class ArrayQueue {
private:
    static const int MaxSize = 10;
    int array[MaxSize];
    int count;
    int front;
    int back;

public:
    ArrayQueue() : count(0), front(0), back(-1) {}

    void enqueue(int value) {
        if (count == MaxSize) {
            cout << "Error: Queue is full" << endl;
            return;
        }
        back = (back + 1) % MaxSize;
        array[back] = value;
        count++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Error: Queue is empty" << endl;
            return -1; // Or throw an exception
        }
        int value = array[front];
        front = (front + 1) % MaxSize;
        count--;
        return value;
    }

    bool isEmpty() {
        return count == 0;
    }
};
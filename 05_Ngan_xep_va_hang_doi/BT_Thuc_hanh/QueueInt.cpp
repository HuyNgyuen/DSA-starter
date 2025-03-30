#include <iostream>
using namespace std;

const int MAX = 100;

struct QueueInt {
    int arr[MAX];
    int front, rear, count, size;
};

void InitQueue(QueueInt &q, int size = MAX) {
    q.front = q.rear = -1;
    q.count = 0;
    q.size = size;
}

bool IsEmpty(QueueInt q) {
    return q.front == -1;
}

bool IsFull(QueueInt q) {
    return q.count == q.size;
}

bool Enqueue(QueueInt &q, int x) {
    if (IsFull(q)) return false;

    if (q.front == -1) q.front = 0;

    q.rear = (q.rear + 1) % q.size;
    q.arr[q.rear] = x;
    q.count++;
    return true;
}

bool Dequeue(QueueInt &q, int &x) {
    if (IsEmpty(q)) return false;

    x = q.arr[q.front];
    if (q.front == q.rear) // chỉ còn 1 phần tử
        q.front = q.rear = -1;
    else
        q.front = (q.front + 1) % q.size;

    q.count--;
    return true;
}

bool Peek(QueueInt q, int &x) {
    if (IsEmpty(q)) return false;
    x = q.arr[q.front];
    return true;
}

void Clear(QueueInt &q) {
    q.front = q.rear = -1;
    q.count = 0;
}

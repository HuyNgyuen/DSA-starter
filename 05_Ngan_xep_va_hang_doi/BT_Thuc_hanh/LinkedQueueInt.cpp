#include <iostream>
using namespace std;

struct Node {
    int info;
    Node *next;
};

struct LinkedQueueInt {
    Node *front;
    Node *rear;
    int count;
};

void InitQueue(LinkedQueueInt &q) {
    q.front = q.rear = nullptr;
    q.count = 0;
}

bool IsEmpty(LinkedQueueInt q) {
    return q.front == nullptr;
}

void Enqueue(LinkedQueueInt &q, int x) {
    Node *p = new Node{x, nullptr};
    if (IsEmpty(q))
        q.front = q.rear = p;
    else {
        q.rear->next = p;
        q.rear = p;
    }
    q.count++;
}

bool Dequeue(LinkedQueueInt &q, int &x) {
    if (IsEmpty(q)) return false;
    Node *p = q.front;
    x = p->info;
    q.front = p->next;
    if (q.front == nullptr) q.rear = nullptr;
    delete p;
    q.count--;
    return true;
}

bool Peek(LinkedQueueInt q, int &x) {
    if (IsEmpty(q)) return false;
    x = q.front->info;
    return true;
}

void Clear(LinkedQueueInt &q) {
    while (!IsEmpty(q)) {
        int x;
        Dequeue(q, x);
    }
}

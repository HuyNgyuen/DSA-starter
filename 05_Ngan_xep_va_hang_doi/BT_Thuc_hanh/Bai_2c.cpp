#include <iostream>
#include <cstring>
using namespace std;

struct Node {
    int data;
    Node *next;
};

struct Queue {
    Node *front, *rear;
    int count;
};

void InitQueue(Queue &q) {
    q.front = q.rear = nullptr;
    q.count = 0;
}

bool IsEmpty(Queue q) {
    return q.front == nullptr;
}

void Enqueue(Queue &q, int x) {
    Node *p = new Node{x, nullptr};
    if (IsEmpty(q)) q.front = q.rear = p;
    else {
        q.rear->next = p;
        q.rear = p;
    }
    q.count++;
}

int Dequeue(Queue &q) {
    if (IsEmpty(q)) return -1;
    Node *p = q.front;
    int x = p->data;
    q.front = p->next;
    if (q.front == nullptr) q.rear = nullptr;
    delete p;
    q.count--;
    return x;
}

// Hàm hiển thị mảng
void DisplayArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

// Bước RadixSort với từng chữ số
void RadixSort(Queue bin[], int a[], int n, int digit) {
    for (int i = 0; i < n; i++) {
        int num = (digit == 1) ? a[i] % 10 : (a[i] / 10) % 10;
        Enqueue(bin[num], a[i]);
    }

    // Gom lại dãy từ các bin
    int idx = 0;
    for (int i = 0; i < 10; i++) {
        while (!IsEmpty(bin[i])) {
            a[idx++] = Dequeue(bin[i]);
        }
    }
}

// Main
int main() {
    int a[] = {91, 46, 85, 15, 92, 35, 31, 22};
    int n = sizeof(a) / sizeof(int);

    Queue bin[10];
    for (int i = 0; i < 10; i++) InitQueue(bin[i]);

    cout << "Day ban dau: ";
    DisplayArray(a, n);

    // Bước 1: theo hàng đơn vị
    RadixSort(bin, a, n, 1);
    cout << "Sau buoc 1 (hang don vi): ";
    DisplayArray(a, n);

    // Bước 2: theo hàng chục
    RadixSort(bin, a, n, 10);
    cout << "Sau buoc 2 (hang chuc): ";
    DisplayArray(a, n);

    return 0;
}

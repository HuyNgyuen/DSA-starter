#include <iostream>
#include <cstring>
using namespace std;

// ==== CẤU TRÚC DANCER VÀ QUEUE ====

struct Dancer {
    char Name[100];
    char Sex; // 'M' hoặc 'F'
};

struct Node {
    Dancer data;
    Node* next;
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

void Enqueue(Queue &q, Dancer d) {
    Node* p = new Node{d, nullptr};
    if (IsEmpty(q))
        q.front = q.rear = p;
    else {
        q.rear->next = p;
        q.rear = p;
    }
    q.count++;
}

bool Dequeue(Queue &q, Dancer &d) {
    if (IsEmpty(q)) return false;
    Node* p = q.front;
    d = p->data;
    q.front = p->next;
    if (q.front == nullptr) q.rear = nullptr;
    delete p;
    q.count--;
    return true;
}

bool Peek(Queue q, Dancer &d) {
    if (IsEmpty(q)) return false;
    d = q.front->data;
    return true;
}

void ShowQueue(Queue q) {
    Node* p = q.front;
    while (p != nullptr) {
        cout << p->data.Name << " ";
        p = p->next;
    }
    cout << endl;
}

// Đưa vào hàng đợi từ danh sách tên
void FormLines(Queue &male, Queue &female) {
    const char* dancers[] = {
        "F Trang", "M Truc", "M Thien", "M Bao",
        "F Thu", "M Tien", "F Thuy", "M Nghia",
        "F Thao", "M Phuoc", "M Hung", "F Vy"
    };
    int n = 12;

    for (int i = 0; i < n; i++) {
        Dancer d;
        d.Sex = dancers[i][0]; // M hoặc F
        strcpy(d.Name, dancers[i] + 2);

        if (d.Sex == 'M') Enqueue(male, d);
        else Enqueue(female, d);
    }
}

// Ghép tối đa 4 cặp
void StartDancing(Queue &male, Queue &female) {
    cout << "\n--- CAC CAP NHAY TREN SAN ---\n";

    for (int i = 0; i < 4; i++) {
        if (male.count > 0 && female.count > 0) {
            Dancer m, f;
            Dequeue(male, m);
            Dequeue(female, f);
            cout << m.Name << " - " << f.Name << endl;
        }
    }

    if (male.count > 0 || female.count > 0) {
        cout << "\n--- NHUNG NGUOI DANG CHO ---\n";
        if (male.count > 0) {
            Dancer m;
            Peek(male, m);
            cout << "Dien vien nam dang cho: " << m.Name << endl;
        }
        if (female.count > 0) {
            Dancer f;
            Peek(female, f);
            cout << "Dien vien nu dang cho: " << f.Name << endl;
        }
    }
}

// Main
int main() {
    Queue males, females;
    InitQueue(males);
    InitQueue(females);

    FormLines(males, females);

    cout << "Danh sach dien vien nam: ";
    ShowQueue(males);
    cout << "Danh sach dien vien nu: ";
    ShowQueue(females);

    StartDancing(males, females);

    return 0;
}

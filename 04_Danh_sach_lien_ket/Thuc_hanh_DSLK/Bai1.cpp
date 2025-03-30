#include <iostream>
using namespace std;

// Cấu trúc Node cho danh sách số nguyên
struct Node {
    int info;
    Node* next;
};

struct ListInt {
    Node* head;
    void Init() { head = NULL; }
    bool IsEmpty() { return head == NULL; }
    void InsertFirst(int x);
    void InsertLast(int x);
    void Remove(int x);
    void Merge(ListInt& other);
    void Show();
    void Clear();
};

// Chèn phần tử vào đầu danh sách
void ListInt::InsertFirst(int x) {
    Node* p = new Node{x, head};
    head = p;
}

// Chèn phần tử vào cuối danh sách
void ListInt::InsertLast(int x) {
    Node* p = new Node{x, NULL};
    if (IsEmpty()) {
        head = p;
    } else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = p;
    }
}

// Xóa phần tử có giá trị x
void ListInt::Remove(int x) {
    Node *p = head, *prev = NULL;
    while (p && p->info != x) {
        prev = p;
        p = p->next;
    }
    if (p) {
        if (prev) prev->next = p->next;
        else head = p->next;
        delete p;
    }
}

// Gộp danh sách `other` vào danh sách hiện tại, giữ nguyên thứ tự
void ListInt::Merge(ListInt& other) {
    if (other.head == NULL) return;
    Node* p = other.head;
    while (p) {
        InsertLast(p->info);
        p = p->next;
    }
}

// Hiển thị danh sách
void ListInt::Show() {
    if (IsEmpty()) {
        cout << "Danh sách rỗng.\n";
        return;
    }
    for (Node* p = head; p; p = p->next)
        cout << p->info << " -> ";
    cout << "NULL\n";
}

// Giải phóng bộ nhớ của danh sách
void ListInt::Clear() {
    while (head) {
        Node* p = head;
        head = head->next;
        delete p;
    }
}

int main() {
    ListInt list1, list2;
    list1.Init();
    list2.Init();

    cout << "\n===== NHẬP DANH SÁCH 1 =====\n";
    int num;
    for (int i = 0; i < 10; i++) {
        cout << "Nhập số thứ " << i + 1 << ": ";
        cin >> num;
        list1.InsertLast(num);
    }
    list1.Show();

    cout << "\nNhập số cần xóa: ";
    int k;
    cin >> k;
    list1.Remove(k);
    list1.Show();

    cout << "\n===== NHẬP DANH SÁCH 2 =====\n";
    for (int i = 0; i < 5; i++) {
        cout << "Nhập số thứ " << i + 1 << ": ";
        cin >> num;
        list2.InsertLast(num);
    }
    list2.Show();

    cout << "\nGhép danh sách 2 vào danh sách 1:\n";
    list1.Merge(list2);
    list1.Show();

    // Giải phóng bộ nhớ
    list1.Clear();
    list2.Clear();

    return 0;
}

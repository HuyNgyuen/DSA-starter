#include <iostream>

using namespace std;

struct Node {
    int info;
    Node* next;
};

// Khởi tạo danh sách rỗng
void Init(Node*& pHead) {
    pHead = NULL;
}

// Kiểm tra danh sách rỗng
bool IsEmpty(Node* pHead) {
    return (pHead == NULL);
}

// Tạo một Node mới
Node* CreateNode(int x) {
    Node* p = new Node;
    p->info = x;
    p->next = NULL;
    return p;
}

// Duyệt danh sách
void ShowList(Node* pHead) {
    if (IsEmpty(pHead)) {
        cout << "Danh sách rỗng\n";
        return;
    }
    Node* p = pHead;
    while (p != NULL) {
        cout << p->info << " -> ";
        p = p->next;
    }
    cout << "NULL\n";
}

// Thêm phần tử vào đầu danh sách
void InsertFirst(Node*& pHead, int x) {
    Node* p = CreateNode(x);
    p->next = pHead;
    pHead = p;
}

// Thêm phần tử sau một Node p đã biết
void InsertAfter(Node* p, int x) {
    if (p != NULL) {
        Node* q = CreateNode(x);
        q->next = p->next;
        p->next = q;
    }
}

// Thêm phần tử có thứ tự
void InsertOrder(Node*& pHead, int x) {
    Node* tp = NULL;
    Node* p = pHead;
    while (p != NULL && p->info < x) {
        tp = p;
        p = p->next;
    }
    if (tp == NULL)
        InsertFirst(pHead, x);
    else
        InsertAfter(tp, x);
}

// Tìm kiếm phần tử trong danh sách không có thứ tự
Node* Find(Node* pHead, int x) {
    Node* p = pHead;
    while (p != NULL) {
        if (p->info == x)
            return p;
        p = p->next;
    }
    return NULL;
}

// Tìm kiếm phần tử trong danh sách có thứ tự
Node* FindOrder(Node* pHead, int x) {
    Node* p = pHead;
    while (p != NULL) {
        if (p->info == x)
            return p;
        else if (p->info > x) // Nếu danh sách có thứ tự, không cần tìm tiếp
            return NULL;
        p = p->next;
    }
    return NULL;
}

// Xóa phần tử đầu danh sách
void DeleteFirst(Node*& pHead) {
    if (IsEmpty(pHead)) {
        cout << "Danh sách rỗng!\n";
        return;
    }
    Node* p = pHead;
    pHead = pHead->next;
    delete p;
}

// Xóa phần tử sau nút p
void DeleteAfter(Node* p) {
    if (p == NULL || p->next == NULL) {
        cout << "Không thể xóa nút này!\n";
        return;
    }
    Node* q = p->next;
    p->next = q->next;
    delete q;
}

// Xóa phần tử có giá trị x (danh sách không có thứ tự)
void Remove(Node*& pHead, int x) {
    Node* tp = NULL;
    Node* p = pHead;
    while (p != NULL && p->info != x) {
        tp = p;
        p = p->next;
    }
    if (p == NULL) return;
    if (p == pHead) {
        pHead = p->next;
    } else {
        tp->next = p->next;
    }
    delete p;
}

// Xóa phần tử trong danh sách có thứ tự
void RemoveOrder(Node*& pHead, int x) {
    Node* tp = NULL;
    Node* p = pHead;
    while (p != NULL && p->info < x) {
        tp = p;
        p = p->next;
    }
    if (p == NULL || p->info != x) return;
    if (p == pHead) {
        pHead = p->next;
    } else {
        tp->next = p->next;
    }
    delete p;
}

// Sắp xếp danh sách bằng Selection Sort
void SelectionSort(Node*& pHead) {
    for (Node* p = pHead; p != NULL && p->next != NULL; p = p->next) {
        Node* pMin = p;
        for (Node* q = p->next; q != NULL; q = q->next) {
            if (q->info < pMin->info) {
                pMin = q;
            }
        }
        swap(p->info, pMin->info);
    }
}

// Xóa toàn bộ danh sách
void ClearList(Node*& pHead) {
    Node* p;
    while (pHead != NULL) {
        p = pHead;
        pHead = pHead->next;
        delete p;
    }
}

// Chương trình chính
int main() {
    Node* list;
    Init(list);

    cout << "\n===== THÊM PHẦN TỬ VÀO DANH SÁCH =====\n";
    InsertOrder(list, 5);
    InsertOrder(list, 3);
    InsertOrder(list, 8);
    InsertOrder(list, 1);
    InsertOrder(list, 7);
    ShowList(list);
    
    cout << "\n===== KIỂM TRA DANH SÁCH RỖNG =====\n";
    cout << (IsEmpty(list) ? "Danh sách rỗng" : "Danh sách không rỗng") << "\n";
    
    cout << "\n===== TÌM KIẾM PHẦN TỬ =====\n";
    cout << "Tìm 5: " << (FindOrder(list, 5) ? "Tìm thấy" : "Không tìm thấy") << "\n";
    cout << "Tìm 10: " << (FindOrder(list, 10) ? "Tìm thấy" : "Không tìm thấy") << "\n";
    
    cout << "\n===== XÓA PHẦN TỬ =====\n";
    DeleteFirst(list);
    ShowList(list);
    RemoveOrder(list, 5);
    ShowList(list);
    
    cout << "\n===== SẮP XẾP DANH SÁCH =====\n";
    SelectionSort(list);
    ShowList(list);
    
    cout << "\n===== XÓA TOÀN BỘ DANH SÁCH =====\n";
    ClearList(list);
    ShowList(list);
    
    return 0;
}

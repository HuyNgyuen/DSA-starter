#include <iostream>
using namespace std;

struct Node {
    int info;
    Node *next;
};

struct LinkedStackInt {
    Node *top;
};

// Khởi tạo
void InitStack(LinkedStackInt &s) {
    s.top = nullptr;
}

bool IsEmpty(LinkedStackInt s) {
    return s.top == nullptr;
}

void PushStack(LinkedStackInt &s, int x) {
    Node *p = new Node{x, s.top};
    s.top = p;
}

bool PopStack(LinkedStackInt &s, int &x) {
    if (IsEmpty(s)) return false;
    Node *p = s.top;
    x = p->info;
    s.top = s.top->next;
    delete p;
    return true;
}

bool PeekStack(LinkedStackInt s, int &x) {
    if (IsEmpty(s)) return false;
    x = s.top->info;
    return true;
}

void Clear(LinkedStackInt &s) {
    Node *p;
    while (s.top != nullptr) {
        p = s.top;
        s.top = s.top->next;
        delete p;
    }
}

// LinkedStackString
struct CharNode {
    char info;
    CharNode *next;
};

struct LinkedStackString {
    CharNode *top;
};

void InitStack(LinkedStackString &s) { s.top = nullptr; }
bool IsEmpty(LinkedStackString s) { return s.top == nullptr; }

void PushStack(LinkedStackString &s, char c) {
    CharNode *p = new CharNode{c, s.top};
    s.top = p;
}

bool PopStack(LinkedStackString &s, char &c) {
    if (IsEmpty(s)) return false;
    CharNode *p = s.top;
    c = p->info;
    s.top = p->next;
    delete p;
    return true;
}

char PeekStack(LinkedStackString s) {
    if (!IsEmpty(s)) return s.top->info;
    return '\0'; // hoặc throw nếu muốn
}

// (b) Ứng dụng ngăn xếp để đảo số
void DaoSo_LinkedStack(int n) {
    LinkedStackInt s;
    InitStack(s);
    int temp = n;

    cout << "So dao nguoc cua " << n << " la: ";

    // Push từng chữ số
    while (temp > 0) {
        int digit = temp % 10;
        cout << digit;
        PushStack(s, temp % 10);
        temp /= 10;
    }
    cout << endl;
}

// (c) Ứng dụng ngăn xếp để kiểm tra xâu đối xứng
bool KiemTraDoiXung_LinkedStack(string str) {
    LinkedStackString s;
    InitStack(s);

    for (char c : str) {
        PushStack(s, c);
    }

    for (char c : str) {
        char topChar;
        PopStack(s, topChar);
        if (c != topChar)
            return false;
    }

    return true;
}

// (d) Ứng dụng ngăn xếp để đổi từ số thập phân sang nhị phân
void DoiNhiPhan_LinkedStack(int n) {
    LinkedStackInt s;
    InitStack(s);

    int temp = n;
    if (n == 0) {
        cout << "0";
        return;
    }

    while (temp > 0) {
        PushStack(s, temp % 2);
        temp /= 2;
    }

    cout << "So nhi phan cua " << n << " la: ";
    while (!IsEmpty(s)) {
        int bit;
        PopStack(s, bit);
        cout << bit;
    }
    cout << endl;
}

// (e) Nhập một biểu thức từ bàn phím, hãy chuyển sang dạng hậu tố và tính giá trị biểu thức.
// Chuyển infix → postfix
bool LaToanHang(char c) {
    return isdigit(c); // hoặc isalpha(c)
}

int UuTien(char op) {
    if (op == '(') return 0;
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return -1;
}

string InfixToPostfix_Linked(string infix) {
    LinkedStackString st;
    InitStack(st);
    string postfix = "";

    for (char c : infix) {
        if (LaToanHang(c)) {
            postfix += c;
        }
        else if (c == '(') {
            PushStack(st, c);
        }
        else if (c == ')') {
            char t;
            while (!IsEmpty(st) && PeekStack(st) != '(') {
                PopStack(st, t);
                postfix += t;
            }
            PopStack(st, t); // remove '('
        }
        else {
            while (!IsEmpty(st) && UuTien(c) <= UuTien(PeekStack(st))) {
                char t;
                PopStack(st, t);
                postfix += t;
            }
            PushStack(st, c);
        }
    }

    char t;
    while (!IsEmpty(st)) {
        PopStack(st, t);
        postfix += t;
    }

    return postfix;
}
// Tính giá trị hậu tố
int TinhHauTo_Linked(string postfix) {
    LinkedStackInt st;
    InitStack(st);

    for (char c : postfix) {
        if (isdigit(c)) {
            PushStack(st, c - '0');
        } else {
            int b, a;
            PopStack(st, b);
            PopStack(st, a);
            int kq;
            switch (c) {
                case '+': kq = a + b; break;
                case '-': kq = a - b; break;
                case '*': kq = a * b; break;
                case '/': kq = a / b; break;
            }
            PushStack(st, kq);
        }
    }

    int kq;
    PopStack(st, kq);
    return kq;
}

// Main
int main() {
    // (b)
    int so;
    cout << "Nhap so nguyen can dao: ";
    cin >> so;

    DaoSo_LinkedStack(so);

    // (c)
    string str;
    cout << "Nhap chuoi can kiem tra: ";
    cin >> str;

    if (KiemTraDoiXung_LinkedStack(str))
        cout << "[LinkedList] Chuoi \"" << str << "\" la chuoi doi xung.\n";
    else
        cout << "[LinkedList] Chuoi \"" << str << "\" khong doi xung.\n";

    // (d)
    int n;
    cout << "Nhap so nguyen can doi sang nhi phan: ";
    cin >> n;

    DoiNhiPhan_LinkedStack(n);

    // (e)
    string infix;
    cout << "Nhap bieu thuc trung to: ";
    cin >> infix;

    string postfixLL = InfixToPostfix_Linked(infix);
    cout << "[LINKED LIST] Hau to: " << postfixLL << ", Gia tri: " << TinhHauTo_Linked(postfixLL) << endl;

    return 0;
}

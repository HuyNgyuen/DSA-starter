#include <iostream>
using namespace std;

const int MAX = 100;

struct StackInt {
    int top;
    int arr[MAX];
};

// Khởi tạo
void InitStack(StackInt &s) {
    s.top = -1;
}

bool IsEmptyInt(StackInt s) {
    return s.top == -1;
}

bool IsFullInt(StackInt s) {
    return s.top == MAX - 1;
}

bool PushStackInt(StackInt &s, int x) {
    if (IsFullInt(s)) return false;
    s.arr[++s.top] = x;
    return true;
}

bool PopStackInt(StackInt &s, int &x) {
    if (IsEmptyInt(s)) return false;
    x = s.arr[s.top--];
    return true;
}

bool PeekStackInt(StackInt s, int &x) {
    if (IsEmptyInt(s)) return false;
    x = s.arr[s.top];
    return true;
}

void Clear(StackInt &s) {
    s.top = -1;
}

// Stack String
struct StackString {
    int top;
    char arr[MAX];
};

void InitStack(StackString &s) { s.top = -1; }
bool IsEmpty(StackString s) { return s.top == -1; }
bool IsFull(StackString s) { return s.top == MAX - 1; }

bool PushStack(StackString &s, char c) {
    if (IsFull(s)) return false;
    s.arr[++s.top] = c;
    return true;
}

bool PopStack(StackString &s, char &c) {
    if (IsEmpty(s)) return false;
    c = s.arr[s.top--];
    return true;
}

char PeekStack(StackString s) {
    return s.arr[s.top];
}

// (b) Ứng dụng ngăn xếp để đảo số
void DaoSo_StackArray(int n) {
    StackInt s;
    InitStack(s);
    int temp = n;

    if (temp == 0) {
        cout << "So dao nguoc cua 0 la: 0" << endl;
        return;
    }
    cout << "So dao nguoc cua " << n << " la: ";
    // Push từng chữ số vào stack
    while (temp > 0) {
        int digit = temp % 10;
        cout << digit;
        PushStackInt(s, digit);
        temp /= 10;
    }
    cout << endl;
}


// (c) Ứng dụng ngăn xếp để kiểm tra xâu đối xứng
bool KiemTraDoiXung_StackArray(string str) {
    StackString s;
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
void DoiNhiPhan_StackArray(int n) {
    StackInt s;
    InitStack(s);

    int temp = n;
    if (n == 0) {
        cout << "0";
        return;
    }

    // Chia 2 và đẩy dư vào stack
    while (temp > 0) {
        PushStackInt(s, temp % 2);
        temp /= 2;
    }

    // In ra nhị phân
    cout << "So nhi phan cua " << n << " la: ";
    while (!IsEmptyInt(s)) {
        int bit;
        PopStackInt(s, bit);
        cout << bit;
    }
    cout << endl;
}

// (e) Nhập một biểu thức từ bàn phím, hãy chuyển sang dạng hậu tố và tính giá trị biểu thức.
// Chuyển trung tố → hậu tố
bool LaToanHang(char c) {
    return isdigit(c); // hoặc isalpha(c)
}

int UuTien(char op) {
    if (op == '(') return 0;
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return -1;
}

string InfixToPostfix_Array(string infix) {
    StackString st;
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
            PopStack(st, t); // bỏ '('
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

// Tính biểu thức hậu tố
int TinhHauTo_Array(string postfix) {
    StackInt st;
    InitStack(st);

    for (char c : postfix) {
        if (isdigit(c)) {
            PushStackInt(st, c - '0');
        } else {
            int b, a;
            PopStackInt(st, b);
            PopStackInt(st, a);
            int kq;
            switch (c) {
                case '+': kq = a + b; break;
                case '-': kq = a - b; break;
                case '*': kq = a * b; break;
                case '/': kq = a / b; break;
            }
            PushStackInt(st, kq);
        }
    }

    int kq;
    PopStackInt(st, kq);
    return kq;
}

// Main
int main() {
    // (b)
    int so;
    cout << "Nhap so nguyen can dao: ";
    cin >> so;

    DaoSo_StackArray(so);

    // (c)
    string str;
    cout << "Nhap chuoi can kiem tra: ";
    cin >> str;

    if (KiemTraDoiXung_StackArray(str))
        cout << "[Array] Chuoi \"" << str << "\" la chuoi doi xung.\n";
    else
        cout << "[Array] Chuoi \"" << str << "\" khong doi xung.\n";

    // (d)
    int n;
    cout << "Nhap so nguyen can doi sang nhi phan: ";
    cin >> n;

    DoiNhiPhan_StackArray(n);

    // (e)
    string infix;
    cout << "Nhap bieu thuc trung to: ";
    cin >> infix;

    string postfixArray = InfixToPostfix_Array(infix);
    cout << "[MANG] Hau to: " << postfixArray << ", Gia tri: " << TinhHauTo_Array(postfixArray) << endl;

    return 0;
}

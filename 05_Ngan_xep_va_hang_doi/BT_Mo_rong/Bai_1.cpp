#include <iostream>
#include <stack>
using namespace std;

// (a) Đệ quy tính Fibonacci
int Fibonacci(int n) {
    if (n <= 1) return n;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

// Khử đệ quy tính Fibonacci bằng stack
int Fibonacci_Stack(int n) {
    if (n <= 1) return n;

    stack<int> s;
    for (int i = n; i > 1; i--)
        s.push(i);

    int a = 0, b = 1;
    while (!s.empty()) {
        int temp = b;
        b = a + b;
        a = temp;
        s.pop();
    }
    return b;
}

// (b) Đệ quy đảo ngược số
void DaoNguoc_DeQuy(int n) {
    if (n < 10) {
        cout << n;
        return;
    }
    cout << n % 10;
    DaoNguoc_DeQuy(n / 10);
}

// Khử đệ quy đảo ngược số bằng stack
void DaoNguoc_Stack(int n) {
    stack<int> s;

    while (n > 0) {
        s.push(n % 10);
        n /= 10;
    }

    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
}


// (c) Đệ quy giải bài toán Tháp Hà Nội
void Hanoi_DeQuy(int n, char A, char B, char C) {
    if (n == 1) {
        cout << "Di chuyen dia 1 tu " << A << " sang " << C << endl;
        return;
    }
    Hanoi_DeQuy(n - 1, A, C, B);
    cout << "Di chuyen dia " << n << " tu " << A << " sang " << C << endl;
    Hanoi_DeQuy(n - 1, B, A, C);
}

// Khử đệ quy giải bài toán Tháp Hà Nội bằng stack
struct Frame {
    int n;
    char A, B, C;
    int step;
};

void Hanoi_Stack(int n, char A, char B, char C) {
    stack<Frame> s;
    s.push({n, A, B, C, 0});

    while (!s.empty()) {
        Frame &f = s.top();
        if (f.n == 1) {
            cout << "Di chuyen dia 1 tu " << f.A << " sang " << f.C << endl;
            s.pop();
            continue;
        }

        if (f.step == 0) {
            s.push({f.n - 1, f.A, f.C, f.B, 0});
            f.step++;
        }
        else if (f.step == 1) {
            cout << "Di chuyen dia " << f.n << " tu " << f.A << " sang " << f.C << endl;
            f.step++;
        }
        else if (f.step == 2) {
            s.push({f.n - 1, f.B, f.A, f.C, 0});
            f.step++;
        }
        else {
            s.pop();
        }
    }
}

int main() {
    int n;

    // Fibonacci
    cout << "Fibonacci(6) De quy: " << Fibonacci(6) << endl;
    cout << "Fibonacci(6) Stack: " << Fibonacci_Stack(6) << endl;

    // Đảo ngược số
    cout << "\nDao nguoc so 12345 (de quy): ";
    DaoNguoc_DeQuy(12345);

    cout << "\nDao nguoc so 12345 (stack): ";
    DaoNguoc_Stack(12345);

    // Tháp Hà Nội
    cout << "\n\nThap Ha Noi 3 dia (de quy):\n";
    Hanoi_DeQuy(3, 'A', 'B', 'C');

    cout << "\nThap Ha Noi 3 dia (stack):\n";
    Hanoi_Stack(3, 'A', 'B', 'C');

    return 0;
}


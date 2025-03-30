# NGĂN XẾP VÀ HÀNG ĐỢI
- Sinh viên: Nguyễn Đỗ Huy
- Mã số sinh viên: 3121411085
- Giảng viên: Đỗ Như Tài
- Môn học: Cấu trúc dữ liệu và giải thuật

---

# Bài 1 – Dùng stack khử đệ quy
## 1. Giới thiệu
Đệ quy là kỹ thuật phổ biến trong lập trình, nhưng có thể bị thay thế bằng cách sử dụng **ngăn xếp (stack)** để mô phỏng quá trình gọi hàm.  
Bài này yêu cầu viết chương trình **đệ quy** và **khử đệ quy bằng stack** cho các bài toán:

---

## 2. Tính số Fibonacci

### Đệ quy:
```cpp
int Fibonacci(int n) {
    if (n <= 1) return n;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}
```

### Khử đệ quy bằng stack:
```cpp
int Fibonacci_Stack(int n) {
    if (n <= 1) return n;
    stack<int> s;
    for (int i = n; i > 1; i--) s.push(i);
    int a = 0, b = 1;
    while (!s.empty()) {
        int temp = b;
        b = a + b;
        a = temp;
        s.pop();
    }
    return b;
}
```

---

## 3. Đảo ngược số nguyên

### Đệ quy:
```cpp
void DaoNguoc_DeQuy(int n) {
    if (n < 10) { cout << n; return; }
    cout << n % 10;
    DaoNguoc_DeQuy(n / 10);
}
```

### Khử đệ quy bằng stack:
```cpp
void DaoNguoc_Stack(int n) {
    stack<int> s;
    while (n > 0) { s.push(n % 10); n /= 10; }
    while (!s.empty()) { cout << s.top(); s.pop(); }
}
```

---

## 4. Tháp Hà Nội

### Đệ quy:
```cpp
void Hanoi_DeQuy(int n, char A, char B, char C) {
    if (n == 1) { cout << "Di chuyen dia 1 tu " << A << " sang " << C << endl; return; }
    Hanoi_DeQuy(n - 1, A, C, B);
    cout << "Di chuyen dia " << n << " tu " << A << " sang " << C << endl;
    Hanoi_DeQuy(n - 1, B, A, C);
}
```

### Khử đệ quy bằng stack:
```cpp
struct Frame {
    int n; char A, B, C; int step;
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
        else s.pop();
    }
}
```

---

## 5. Kiểm thử chương trình

| Bài toán | Đầu vào | Đầu ra (mẫu) |
|----------|---------|--------------|
| Fibonacci | `n = 5` | `F(5) = 5` |
| Đảo ngược | `n = 1234` | `4321` |
| Tháp Hà Nội | `n = 3` | Danh sách các bước di chuyển đĩa |

---

## 🛠 Yêu cầu môi trường

- Ngôn ngữ: C++
- Compiler: hỗ trợ chuẩn C++11 trở lên
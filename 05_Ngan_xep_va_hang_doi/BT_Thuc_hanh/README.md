# NGĂN XẾP VÀ HÀNG ĐỢI
- Sinh viên: Nguyễn Đỗ Huy
- Mã số sinh viên: 3121411085
- Giảng viên: Đỗ Như Tài
- Môn học: Cấu trúc dữ liệu và giải thuật

---

# Bài 1 – Ngăn xếp số nguyên và ứng dụng
## 1. Giới thiệu
Ngăn xếp (Stack) là cấu trúc dữ liệu **LIFO** – phần tử thêm vào sau cùng sẽ được lấy ra đầu tiên.

Bài tập gồm:
- Cài đặt ngăn xếp dùng mảng (`StackInt`) và danh sách liên kết (`LinkedStackInt`)
- Các thao tác: Init, Push, Pop, Peek, IsEmpty, IsFull, Clear
- Các ứng dụng:
  - Đảo số nguyên
  - Kiểm tra xâu đối xứng (`StackString`)
  - Đổi số thập phân sang nhị phân
  - Chuyển trung tố → hậu tố và tính biểu thức hậu tố

## 2. Cấu trúc dữ liệu
### 🔹 StackInt (Dùng mảng)
```cpp
struct StackInt {
    int top;
    int arr[MAX];
};
```

### 🔹 LinkedStackInt (Dùng danh sách liên kết)
```cpp
struct Node {
    int info;
    Node* next;
};
struct LinkedStackInt {
    Node* top;
};
```

## 3. Các thao tác ngăn xếp
| Hàm | Mô tả |
|-----|------|
| `InitStack` | Khởi tạo ngăn xếp |
| `IsEmpty` | Kiểm tra rỗng |
| `IsFull` (chỉ dùng cho mảng) | Kiểm tra đầy |
| `PushStack` | Đẩy phần tử vào ngăn xếp |
| `PopStack` | Lấy phần tử khỏi ngăn xếp |
| `PeekStack` | Lấy giá trị đầu ngăn xếp mà không xóa |
| `Clear` | Xóa toàn bộ ngăn xếp |

## 4. Ứng dụng
### (b) Đảo số nguyên
- Tách từng chữ số → Push vào Stack → Pop ra để tạo số đảo.

### (c) Kiểm tra xâu đối xứng
- Push từng ký tự → Pop so sánh với ký tự từ đầu xâu.

### (d) Đổi từ số thập phân sang nhị phân
- Chia liên tiếp cho 2 → Push phần dư → Pop để hiển thị nhị phân.

### (e) Biểu thức hậu tố
- **Chuyển trung tố → hậu tố** dùng Stack để quản lý toán tử và dấu ngoặc.
- **Tính giá trị hậu tố** bằng cách duyệt hậu tố, thực hiện phép tính khi gặp toán tử.

## 5. Kết quả chương trình mẫu
```cpp
- Đảo số 1234       → 4321
- Chuỗi "madam"     → Đối xứng
- 10 → Nhị phân     → 1010
- Biểu thức: (2+3)*4 → hậu tố: 23+4* → giá trị: 20
```

---

# Bài 2 – Hàng đợi số nguyên và ứng dụng
## 1. Giới thiệu
Hàng đợi (Queue) là cấu trúc dữ liệu **FIFO** – phần tử được thêm vào trước sẽ được lấy ra trước.

### Nội dung bài:
- Cài đặt hàng đợi bằng mảng (`QueueInt`) và danh sách liên kết (`LinkedQueueInt`)
- Các thao tác cơ bản: `Init`, `Enqueue`, `Dequeue`, `Peek`, `IsEmpty`, `IsFull`, `Clear`
- Ứng dụng:
  - Xếp lịch **cặp múa** nam/nữ
  - **Radix Sort** – sắp xếp theo chữ số

## 2. Cấu trúc dữ liệu
### 🔹 QueueInt – dùng mảng
```cpp
struct QueueInt {
    int arr[MAX];
    int front, rear, count, size;
};
```

### 🔹 LinkedQueueInt – dùng danh sách liên kết
```cpp
struct Node {
    int info;
    Node* next;
};
struct LinkedQueueInt {
    Node* front;
    Node* rear;
    int count;
};
```

## 3. Các thao tác chính
| Hàm | Mô tả |
|-----|------|
| `InitQueue` | Khởi tạo hàng đợi |
| `IsEmpty` | Kiểm tra rỗng |
| `IsFull` | Kiểm tra đầy (với mảng) |
| `Enqueue` | Thêm phần tử |
| `Dequeue` | Lấy phần tử |
| `Peek` | Xem phần tử đầu |
| `Clear` | Xóa toàn bộ hàng đợi |

## 4. Ứng dụng
### (b) Xếp lịch cặp múa
- Sử dụng 2 hàng đợi:
  - `QueueNam` và `QueueNu`
- Mỗi cặp (nam + nữ) được đưa lên sàn cùng lúc
- Nếu còn người chờ → in ra danh sách chờ

### (c) Radix Sort
- Sắp xếp mảng số nguyên dựa vào từng chữ số
- Dùng 10 hàng đợi (`bin[0..9]`) để phân loại phần tử theo chữ số đang xét
- Duyệt qua:
  - Hàng đơn vị
  - Hàng chục
  - (Tiếp nếu có hàng trăm...)

## 5. Kết quả mẫu
```cpp
// Cặp múa:
-> Bao - Trang
-> Tien - Thu
-> Nghia - Thuy
-> Phuoc - Thao

Dien vien dang cho: Hung, Vy

// Radix Sort:
Ban đầu:         91 46 85 15 92 35 31 22
Sau hàng đơn vị: 91 92 22 15 35 85 46 31
Sau hàng chục:   15 22 31 35 46 85 91 92
```

---

## 🛠 Yêu cầu môi trường

- Ngôn ngữ: C++
- Compiler: hỗ trợ chuẩn C++11 trở lên
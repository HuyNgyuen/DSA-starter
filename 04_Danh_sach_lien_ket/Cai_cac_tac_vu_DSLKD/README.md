# DANH SÁCH LIÊN KẾT
- Sinh viên: Nguyễn Đỗ Huy
- Mã số sinh viên: 3121411085
- Giảng viên: Đỗ Như Tài
- Môn học: Cấu trúc dữ liệu và giải thuật

---
# Danh sách liên kết đơn (Singly Linked List)

## 1. Giới thiệu

- Danh sách liên kết (linked list) là một cấu trúc dữ liệu trong đó các phần tử (node) được nối với nhau thông qua con trỏ.
- Mỗi phần tử trong danh sách liên kết đơn chỉ liên kết tới phần tử **kế tiếp**.
- Báo cáo này trình bày cách cài đặt danh sách liên kết đơn bằng C++ và các thao tác cơ bản như: thêm, xóa, tìm kiếm, duyệt và sắp xếp.

---

## 2. Cấu trúc dữ liệu

Một nút (`Node`) gồm:
- `info`: giá trị của nút (kiểu `int`).
- `next`: con trỏ trỏ đến nút kế tiếp.

```cpp
struct Node {
    int info;
    Node* next;
};
```

---

## 3. Các tác vụ chính

| Hàm | Chức năng |
|-----|-----------|
| `Init` | Khởi tạo danh sách rỗng |
| `IsEmpty` | Kiểm tra danh sách có rỗng không |
| `CreateNode` | Tạo một nút mới |
| `InsertFirst` | Thêm phần tử vào đầu danh sách |
| `InsertAfter` | Chèn phần tử sau một nút |
| `InsertOrder` | Chèn phần tử vào danh sách có thứ tự |
| `DeleteFirst` | Xóa phần tử đầu tiên |
| `DeleteAfter` | Xóa phần tử sau một nút |
| `Remove` | Xóa phần tử theo giá trị |
| `Find` | Tìm phần tử theo giá trị |
| `ShowList` | Hiển thị danh sách |
| `SelectionSort` | Sắp xếp danh sách theo thứ tự tăng dần |
| `ClearList` | Xóa toàn bộ danh sách |

---

## 4. Cài đặt chương trình

### 🔹 Khởi tạo danh sách
```cpp
void Init(Node*& pHead) { pHead = NULL; }
```

### 🔹 Kiểm tra rỗng
```cpp
bool IsEmpty(Node* pHead) { return (pHead == NULL); }
```

### 🔹 Tạo node mới
```cpp
Node* CreateNode(int x) {
    Node* p = new Node;
    p->info = x;
    p->next = NULL;
    return p;
}
```

### 🔹 Duyệt danh sách
```cpp
void ShowList(Node* pHead);
```

### 🔹 Thêm phần tử vào đầu
```cpp
void InsertFirst(Node*& pHead, int x);
```

### 🔹 Thêm sau node đã biết
```cpp
void InsertAfter(Node* p, int x);
```

### 🔹 Chèn có thứ tự tăng dần
```cpp
void InsertOrder(Node*& pHead, int x);
```

### 🔹 Tìm kiếm phần tử
```cpp
Node* Find(Node* pHead, int x);
Node* FindOrder(Node* pHead, int x);  // nếu danh sách có thứ tự
```

### 🔹 Xóa phần tử
```cpp
void DeleteFirst(Node*& pHead);
void DeleteAfter(Node* p);
void Remove(Node*& pHead, int x);
void RemoveOrder(Node*& pHead, int x);
```

### 🔹 Sắp xếp danh sách
```cpp
void SelectionSort(Node*& pHead);
```

### 🔹 Xóa toàn bộ danh sách
```cpp
void ClearList(Node*& pHead);
```

---

##  Ghi chú

- Việc thao tác trên danh sách liên kết yêu cầu quản lý bộ nhớ cẩn thận để tránh rò rỉ.
- Khi xoá node, cần giải phóng đúng vùng nhớ bằng `delete`.

---

## 🛠 Yêu cầu môi trường

- Ngôn ngữ: C++
- Compiler: hỗ trợ chuẩn C++11 trở lên
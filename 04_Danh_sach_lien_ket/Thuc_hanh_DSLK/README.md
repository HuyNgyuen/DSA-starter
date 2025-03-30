# DANH SÁCH LIÊN KẾT
- Sinh viên: Nguyễn Đỗ Huy
- Mã số sinh viên: 3121411085
- Giảng viên: Đỗ Như Tài
- Môn học: Cấu trúc dữ liệu và giải thuật

---
# Bài 1 – Danh sách liên kết số nguyên
## 1. Giới thiệu
Chương trình sử dụng **danh sách liên kết đơn** để quản lý các số nguyên, với các thao tác:
- Thêm phần tử vào đầu/cuối danh sách
- Xóa phần tử theo giá trị bất kỳ
- Gộp hai danh sách liên kết
- Hiển thị danh sách
- Giải phóng bộ nhớ

## 2. Cấu trúc dữ liệu
### Cấu trúc `Node` và `ListInt`
```cpp
struct Node {
    int info;
    Node* next;
};

struct ListInt {
    Node* head;
    void Init();
    bool IsEmpty();
    void InsertFirst(int x);
    void InsertLast(int x);
    void Remove(int x);
    void Merge(ListInt& other);
    void Show();
    void Clear();
};
```

## 3. Các thao tác chính
| Hàm | Mô tả |
|-----|------|
| `Init` | Khởi tạo danh sách rỗng |
| `InsertFirst`, `InsertLast` | Thêm phần tử vào đầu/cuối danh sách |
| `Remove` | Xóa phần tử có giá trị x |
| `Merge` | Gộp danh sách khác vào cuối danh sách hiện tại |
| `Show` | Hiển thị toàn bộ danh sách |
| `Clear` | Xóa toàn bộ danh sách, giải phóng bộ nhớ |
| `IsEmpty` | Kiểm tra danh sách có rỗng không |

## 4. Chương trình chính
1. Nhập 10 số nguyên và thêm vào `list1`
2. Hiển thị `list1`
3. Nhập số `k` và xóa khỏi `list1`
4. Nhập 5 số nguyên vào `list2`
5. Gộp `list2` vào `list1`
6. Hiển thị `list1` sau khi gộp
7. Giải phóng bộ nhớ

## 5. Kiểm thử chương trình
### 1. Kiểm tra danh sách rỗng
| Test | Input | Expected Output |
|------|-------|------------------|
| IsEmpty | Khởi tạo danh sách | true |

### 2. Thêm phần tử
| Test | Input | Expected Output |
|------|-------|------------------|
| Thêm 5 | InsertFirst(5) | 5 -> NULL |
| Thêm 3 | InsertFirst(3) | 3 -> 5 -> NULL |

### 3. Xóa phần tử
| Test | Input | Expected Output |
|------|-------|------------------|
| Xóa 8 | Remove(8) | Không đổi |
| Xóa 1 | Remove(1) | 3 -> 5 -> NULL |
| Xóa 10 | Remove(10) | Không đổi |

### 4. Gộp danh sách
| Test | Input | Expected Output |
|------|-------|------------------|
| list1 = 1->3->5, list2 = 20->21 | Merge(list1, list2) | 1 -> 3 -> 5 -> 20 -> 21 -> NULL |

### 5. Xóa toàn bộ danh sách
| Test | Input | Expected Output |
|------|-------|------------------|
| ClearList | Gọi `Clear()` | Danh sách rỗng |

---

# Bài 2 – Danh sách liên kết sinh viên
## 1. Giới thiệu
Chương trình sử dụng danh sách liên kết đơn để quản lý danh sách sinh viên với các chức năng:
- Thêm, xóa sinh viên theo tên hoặc địa chỉ
- Hiển thị danh sách sinh viên
- Sắp xếp danh sách theo tên, địa chỉ, lớp hoặc khóa học (dùng con trỏ hàm)
- Giải phóng bộ nhớ khi kết thúc

## 2. Cấu trúc dữ liệu
### Cấu trúc `SinhVien` và `ListSV`
```cpp
struct SinhVien {
    char hoTen[50];
    char diaChi[70];
    char lop[10];
    int khoa;
    SinhVien* next;
};

struct ListSV {
    SinhVien* head;
    void Init();
    void Insert(SinhVien sv);
    void RemoveByName(const char* name);
    void RemoveByAddress(const char* address);
    void Show();
    void Clear();
    void Sort(int (*compare)(SinhVien*, SinhVien*));
};
```

## 3. Các thao tác chính
| Hàm | Mô tả |
|-----|------|
| `Init` | Khởi tạo danh sách rỗng |
| `Insert` | Thêm sinh viên vào đầu danh sách |
| `RemoveByName` | Xóa sinh viên theo tên |
| `RemoveByAddress` | Xóa sinh viên theo địa chỉ |
| `Show` | Hiển thị danh sách sinh viên |
| `Clear` | Giải phóng toàn bộ danh sách |
| `Sort` | Sắp xếp danh sách bằng selection sort và con trỏ hàm |

## 4. Hàm so sánh
```cpp
int CompareByName(SinhVien* sv1, SinhVien* sv2);
int CompareByAddress(SinhVien* sv1, SinhVien* sv2);
int CompareByClass(SinhVien* sv1, SinhVien* sv2);
int CompareByCourse(SinhVien* sv1, SinhVien* sv2);
```

## 5. Chương trình chính
1. Nhập 10 sinh viên vào danh sách
2. Hiển thị danh sách
3. Sắp xếp theo tên và hiển thị lại
4. Xóa sinh viên có tên `"Nguyen Van Teo"` và địa chỉ `"Nguyen Van Cu"`
5. Thêm sinh viên `"Tran Thi Mo"` vào danh sách
6. Hiển thị danh sách sau cập nhật
7. Giải phóng bộ nhớ

## 6. Kiểm thử chương trình
### 1. Kiểm tra danh sách rỗng
| Test | Input | Expected Output |
|------|-------|------------------|
| IsEmpty | Init() | true |

### 2. Thêm sinh viên
| Test | Input | Expected Output |
|------|-------|------------------|
| Thêm "Nguyen Van A" | Insert(...) | A hiển thị |
| Thêm "Tran Van B" | Insert(...) | B -> A |

### 3. Xóa sinh viên
| Test | Input | Expected Output |
|------|-------|------------------|
| Xóa "Nguyen Van A" | RemoveByName(...) | Chỉ còn B |
| Xóa "456 Le Loi" | RemoveByAddress(...) | Danh sách rỗng |

### 4. Sắp xếp danh sách
| Test | Input | Expected Output |
|------|-------|------------------|
| Theo tên | Sort(..., CompareByName) | A → B |
| Theo địa chỉ | Sort(..., CompareByAddress) | A → B |
| Theo lớp | Sort(..., CompareByClass) | A → B |
| Theo khóa | Sort(..., CompareByCourse) | Theo thứ tự tăng |

### 5. Xóa toàn bộ danh sách
| Test | Input | Expected Output |
|------|-------|------------------|
| Clear() | Xóa danh sách | Danh sách rỗng |

---

## 🛠 Yêu cầu môi trường

- Ngôn ngữ: C++
- Compiler: hỗ trợ chuẩn C++11 trở lên
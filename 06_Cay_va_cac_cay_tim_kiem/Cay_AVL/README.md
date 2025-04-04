# CÂY VÀ CÁC CÂY TÌM KIẾM
- Sinh viên: Nguyễn Đỗ Huy
- Mã số sinh viên: 3121411085
- Giảng viên: Đỗ Như Tài
- Môn học: Cấu trúc dữ liệu và giải thuật

---

#  Cây AVL: Cài đặt, chèn, xóa, duyệt và tìm kiếm

## I. Ý tưởng cây AVL
- Cây AVL là cây nhị phân tìm kiếm (BST) nhưng được **cân bằng chiều cao**.
- Tại mỗi nút, độ cao cây con trái và phải **không lệch quá 1**.
- Khi thêm hoặc xóa làm mất cân bằng, cần **quay cây**:
  - Quay đơn: LL, RR
  - Quay kép: LR, RL

---

## II. Input / Output
### 1. Input
- Danh sách số nguyên cần thêm vào cây.
- Yêu cầu xóa một số nút (tùy).
- Yêu cầu duyệt cây (NLR, LNR, LRN) hoặc tìm kiếm.

### 2. Output
- Cây AVL sau khi thêm / xóa.
- Kết quả tìm kiếm.
- Duyệt cây theo thứ tự yêu cầu.

---

## III. Tập testcase

```cpp
Input:
values[] = {5, 2, 4, 8, 1, 9, 6};

Output:
InOrder (LNR): 1 2 4 5 6 8 9
PreOrder (NLR): 4 2 1 8 5 6 9
PostOrder (LRN): 1 2 6 5 9 8 4

Tim 4? Co
Tim 10? Khong

Sau khi xoa 2, InOrder: 1 4 5 6 8 9
```

---

## IV. Mã nguồn
### 1. Cấu trúc Node

```cpp
struct Node {
    int info, height, count;
    Node* left;
    Node* right;

    Node(int val) {
        info = val;
        height = 1;
        count = 1;
        left = right = nullptr;
    }
};
```

### 2. Hàm phụ trợ

```cpp
int Height(Node* n) {
    return n ? n->height : 0;
}

int BalanceFactor(Node* n) {
    return n ? Height(n->left) - Height(n->right) : 0;
}

void UpdateHeight(Node* n) {
    n->height = 1 + max(Height(n->left), Height(n->right));
}
```

### 3. Quay cây

```cpp
Node* RotateRight(Node* y);
Node* RotateLeft(Node* x);
```

### 4. Thêm phần tử

```cpp
Node* Insert(Node* root, int key);
```

### 5. Xóa phần tử

```cpp
Node* MinValueNode(Node* n);
Node* Delete(Node* root, int key);
```

### 6. Tìm kiếm

```cpp
bool Search(Node* root, int key);
```

### 7. Duyệt cây

```cpp
void InOrder(Node* root);
void PreOrder(Node* root);
void PostOrder(Node* root);
```

### 8. Hàm main()

```cpp
int main() {
    Node* root = nullptr;
    int values[] = {5, 2, 4, 8, 1, 9, 6};
    for (int x : values) root = Insert(root, x);

    InOrder(root);
    PreOrder(root);
    PostOrder(root);

    Search(root, 4);
    Search(root, 10);

    root = Delete(root, 2);
    InOrder(root);
}
```

---

## Ghi chú

- Cây AVL đảm bảo các phép thêm/xóa có **độ phức tạp O(log n)**.
- Tự động cân bằng thông qua các thao tác **quay cây**.

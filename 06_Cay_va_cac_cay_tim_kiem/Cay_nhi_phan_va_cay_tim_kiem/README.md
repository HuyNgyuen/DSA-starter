# CÂY VÀ CÁC CÂY TÌM KIẾM
- Sinh viên: Nguyễn Đỗ Huy
- Mã số sinh viên: 3121411085
- Giảng viên: Đỗ Như Tài
- Môn học: Cấu trúc dữ liệu và giải thuật

---
# Cây nhị phân
# Bài 001 – Cây nhị phân: Trung bình cộng và tỉ số
## Mô tả
Cho một cây nhị phân, mỗi nút chứa giá trị là một số nguyên. Thực hiện các chức năng sau:

### Yêu cầu:
- Tính trung bình cộng tất cả các nút
- Tính trung bình cộng các số **dương**
- Tính trung bình cộng các số **âm**
- Tính tỉ số `R = tổng số dương / tổng số âm`

## Cấu trúc cây nhị phân
```cpp
struct Node {
    int info;
    Node* pLeft;
    Node* pRight;
};
typedef Node* TREE;
```

## Giải thuật
### (a) Trung bình cộng tất cả các nút
```cpp
int DemNode(TREE Root);        // Đếm tổng số nút
int TongNode(TREE Root);       // Tính tổng giá trị
float TrungBinhCong(TREE Root); // TB = Tổng / Số lượng
```

### (b) Trung bình cộng số **dương**
```cpp
int DemDuong(TREE Root);
int TongDuong(TREE Root);
float TrungBinhDuong(TREE Root);
```

### (c) Trung bình cộng số **âm**
```cpp
int DemAm(TREE Root);
int TongAm(TREE Root);
float TrungBinhCongAm(TREE Root);
```

### (d) Tỉ số R = a / b (a: tổng dương, b: tổng âm)
```cpp
float TinhTySo(TREE Root) {
    int a = TongDuong(Root);
    int b = TongAm(Root);
    if (b == 0) return 0;
    return (float)a / b;
}
```

## Kết quả ví dụ
**Input**:  
```
1 -8 2 9 -3 4 7 3 6 -5
```

**Output**:
```
Tổng số node: 10
Tổng giá trị các node: 16
Trung bình cộng: 1.6

Số node dương: 7
Tổng node dương: 32
Trung bình dương: 4.57143

Số node âm: 3
Tổng node âm: -16
Trung bình âm: -5.33333

Tỷ số tổng dương / tổng âm: -2.0
```

---

# Bài 004 – Cây nhị phân tìm kiếm: Tìm phần tử nhỏ nhất và lớn nhất
## Mô tả
Cho một **cây nhị phân tìm kiếm (BST)**, mỗi nút chứa một số nguyên (`int`). Viết hàm:

- Tìm phần tử **nhỏ nhất**
- Tìm phần tử **lớn nhất**

## Cấu trúc cây
```cpp
struct node {
    int info;
    struct node* pLeft;
    struct node* pRight;
};
typedef struct node NODE;
typedef NODE* TREE;
```

## Giải thuật
### 🔹 Tìm phần tử nhỏ nhất:
Trong BST, phần tử nhỏ nhất nằm ở **ngoài cùng bên trái**.

```cpp
NODE* NhoNhat(TREE Root) {
    if (Root == NULL) return NULL;
    NODE* lc = Root;
    while (lc->pLeft != NULL)
        lc = lc->pLeft;
    return lc;
}
```

### Tìm phần tử lớn nhất:
Trong BST, phần tử lớn nhất nằm ở **ngoài cùng bên phải**.

```cpp
NODE* LonNhat(TREE Root) {
    if (Root == NULL) return NULL;
    NODE* lc = Root;
    while (lc->pRight != NULL)
        lc = lc->pRight;
    return lc;
}
```

## Ví dụ kết quả
**Input** (cây nhị phân tìm kiếm với các giá trị):  
```
10 5 15 3 9 12 18 7 20
```

**Output**:
```
Phần tử nhỏ nhất: 3
Phần tử lớn nhất: 20
```
---

# Bài 005 – Đếm số nút có một nhánh con trong cây nhị phân
## Mô tả
Cho một **cây nhị phân**, hãy viết chương trình để **đếm số lượng nút chỉ có một nhánh con**  
(nghĩa là chỉ có **con trái HOẶC con phải**, không phải cả hai).

## Cấu trúc cây
```cpp
struct node {
    int info;
    node* pLeft;
    node* pRight;
};
typedef node* TREE;
```

## Duyệt cây theo thứ tự NLR (Node – Left – Right)

## Công thức đệ quy

```cpp
int DemMotCon(TREE t) {
    if (t == NULL) return 0;

    if ((t->pLeft && !t->pRight) || (!t->pLeft && t->pRight))
        return 1 + DemMotCon(t->pLeft) + DemMotCon(t->pRight);

    return DemMotCon(t->pLeft) + DemMotCon(t->pRight);
}
```

- Nếu `t` có **chính xác một** nhánh con (trái hoặc phải), tăng đếm lên `1`
- Đệ quy sang trái và phải

## Ví dụ kết quả

| Input | Output |
|-------|--------|
| `1 2 4 3 5` | Số nút có một nhánh con: **2** |
| `0` | Số nút có một nhánh con: **0** |
| `1 2` | Số nút có một nhánh con: **1** |

---

# Bài 006 – Số nút và tổng giá trị các nút trong cây nhị phân tìm kiếm
## Mô tả
Cho một **cây nhị phân tìm kiếm (BST)**, mỗi nút chứa giá trị số nguyên.  
Viết công thức đệ quy và cài đặt chương trình để:

- Đếm **tổng số nút**
- Tính **tổng giá trị các nút**

## Cấu trúc cây

```cpp
struct node {
    int info;
    struct node* pLeft;
    struct node* pRight;
};
typedef struct node NODE;
typedef NODE* TREE;
```

## Công thức đệ quy

### Số nút trong cây:
```cpp
int DemNode(TREE t) {
    if (t == NULL) return 0;
    return 1 + DemNode(t->pLeft) + DemNode(t->pRight);
}
```

### Tổng giá trị các nút:
```cpp
int TongNode(TREE t) {
    if (t == NULL) return 0;
    return t->info + TongNode(t->pLeft) + TongNode(t->pRight);
}
```

---

## Ví dụ kết quả

| Input             | Số nút | Tổng giá trị |
|------------------|--------|--------------|
| 10 5 15 3 9 12 18 7 20 | 9      | 99           |
| 5                | 1      | 5            |
| 10 5 15          | 3      | 30           |

---

# Bài 008 – Duyệt LNR cây nhị phân và ghi ra tập tin nhị phân
## Mô tả
Viết chương trình duyệt cây nhị phân các số thực theo **phương pháp LNR (trái - gốc - phải)**  
và ghi lần lượt các giá trị vào **tập tin nhị phân `data.out`**.

## Cấu trúc cây

```cpp
struct node {
    float info;
    struct node* pLeft;
    struct node* pRight;
};
typedef struct node NODE;
typedef NODE* TREE;
```

## Duyệt cây theo LNR và ghi ra file

```cpp
void LNR(TREE t, FILE* fp) {
    if (t == NULL) return;
    LNR(t->pLeft, fp);
    fwrite(&t->info, sizeof(float), 1, fp); // ghi vào file
    LNR(t->pRight, fp);
}
```

## Ghi ra tập tin nhị phân

```cpp
int Xuat(const char* filename, TREE t) {
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) return 0;
    LNR(t, fp);
    fclose(fp);
    return 1;
}
```

## Ví dụ kết quả

| Input | Output (`data.out`) |
|-------|---------------------|
| `10.5 5.2 15.8 3.1 9.7 12.4 18.9 7.6 20.3` | `3.1 5.2 7.6 9.7 10.5 12.4 15.8 18.9 20.3` |
| `5.5` | `5.5` |
| `10.2 5.1 15.3` | `5.1 10.2 15.3` |

## Ghi chú

- Tập tin `data.out` được ghi theo định dạng **nhị phân** (`wb`)
- Đảm bảo chương trình đọc/ghi đúng định dạng `float` theo hệ thống

---

# Bài 009 – Duyệt NLR cây nhị phân và ghi ra tập tin nhị phân
## Mô tả
Viết chương trình duyệt cây nhị phân các số thực theo **phương pháp NLR (gốc - trái - phải)**  
và ghi lần lượt các giá trị vào **tập tin nhị phân `data.out`**.

## Cấu trúc cây

```cpp
struct node {
    float info;
    struct node* pLeft;
    struct node* pRight;
};
typedef struct node NODE;
typedef NODE* TREE;
```

## Duyệt cây theo NLR và ghi ra file

```cpp
void NLR(TREE t, FILE* fp) {
    if (t == NULL) return;
    fwrite(&t->info, sizeof(float), 1, fp); // ghi vào file
    NLR(t->pLeft, fp);
    NLR(t->pRight, fp);
}
```

## Ghi ra tập tin nhị phân

```cpp
int Xuat(char* filename, TREE t) {
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) return 0;
    NLR(t, fp);
    fclose(fp);
    return 1;
}
```

## Ví dụ kết quả

| Input | Output (`data.out`) |
|-------|---------------------|
| `10.5 5.2 15.8 3.1 9.7 12.4 18.9 7.6 20.3` | `10.5 5.2 3.1 9.7 15.8 12.4 18.9 7.6 20.3` |
| `5.5` | `5.5` |
| `10.2 5.1 15.3` | `10.2 5.1 15.3` |

## Ghi chú

- Tập tin `data.out` được ghi theo định dạng **nhị phân** (`wb`)
- Đảm bảo chương trình đọc/ghi đúng định dạng `float` theo hệ thống

---

# Bài 010 – Duyệt LRN cây nhị phân và ghi ra tập tin nhị phân

## Mô tả
Viết chương trình duyệt cây nhị phân các số thực theo **phương pháp LRN (trái - phải - gốc)**  
và ghi lần lượt các giá trị vào **tập tin nhị phân `data.out`**.

## Cấu trúc cây

```cpp
struct node {
    float info;
    struct node* pLeft;
    struct node* pRight;
};
typedef struct node NODE;
typedef NODE* TREE;
```

## Duyệt cây theo LRN và ghi ra file

```cpp
void LRN(TREE t, FILE* fp) {
    if (t == NULL) return;
    LRN(t->pLeft, fp);
    LRN(t->pRight, fp);
    fwrite(&t->info, sizeof(float), 1, fp); // ghi vào file
}
```

## Ghi ra tập tin nhị phân

```cpp
int Xuat(char* filename, TREE t) {
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) return 0;
    LRN(t, fp);
    fclose(fp);
    return 1;
}
```

## Ví dụ kết quả

| Input | Output (`data.out`) |
|-------|---------------------|
| `10.5 5.2 15.8 3.1 9.7 12.4 18.9 7.6 20.3` | `3.1 9.7 5.2 12.4 7.6 20.3 18.9 15.8 10.5` |
| `5.5` | `5.5` |
| `10.2 5.1 15.3` | `5.1 15.3 10.2` |

## Ghi chú

- Tập tin `data.out` được ghi theo định dạng **nhị phân** (`wb`)
- Đảm bảo chương trình đọc/ghi đúng định dạng `float` theo hệ thống

---

# Bài 013 – Lưu và khôi phục cây nhị phân tìm kiếm từ file nhị phân

## Mô tả
Viết chương trình **ghi một cây nhị phân tìm kiếm các số thực** ra tập tin nhị phân `data.out`,  
và từ nội dung trong tập tin có thể **tái tạo lại đúng cây ban đầu**.

## Cấu trúc cây

```cpp
struct node {
    float info;
    struct node* pLeft;
    struct node* pRight;
};
typedef struct node NODE;
typedef NODE* TREE;
```

## Hàm tạo nút và chèn vào cây

```cpp
NODE* CreateNode(int x) {
    NODE* p = new NODE;
    p->info = x;
    p->pLeft = p->pRight = NULL;
    return p;
}

void Insert(TREE &p, float theKey) {
    if (p == NULL) {
        p = CreateNode(theKey);
    } else if (p->info > theKey) {
        Insert(p->pLeft, theKey);
    } else {
        Insert(p->pRight, theKey);
    }
}
```

## Ghi cây ra tập tin nhị phân theo thứ tự NLR

```cpp
void NLR(TREE t, FILE* fp) {
    if (t == NULL) return;
    fwrite(&t->info, sizeof(float), 1, fp);
    NLR(t->pLeft, fp);
    NLR(t->pRight, fp);
}

int Xuat(char *filename, TREE t) {
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) return 0;
    NLR(t, fp);
    fclose(fp);
    return 1;
}
```

## Đọc tập tin và khôi phục lại cây

```cpp
void DocVaTaoBST(TREE &t, char *filename) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) return;

    float x;
    t = NULL;
    while (fread(&x, sizeof(float), 1, fp) == 1) {
        Insert(t, x);
    }
    fclose(fp);
}
```

## In cây ra màn hình theo NLR

```cpp
void NLR_Print(TREE t) {
    if (t == NULL) return;
    cout << t->info << " ";
    NLR_Print(t->pLeft);
    NLR_Print(t->pRight);
}
```

## Ví dụ kết quả

| Input | Output (sau khi đọc lại) |
|-------|---------------------------|
| `10.5 5.2 15.8 3.1 9.7 12.4 18.9 7.6 20.3` | `10.5 5.2 3.1 9.7 15.8 12.4 18.9 7.6 20.3` |
| `5.5` | `5.5` |
| `10.2 5.1 15.3` | `10.2 5.1 15.3` |

---

# Bài 014 – Tạo danh sách liên kết giảm dần từ cây nhị phân tìm kiếm
## Mô tả
Viết chương trình tạo một **danh sách liên kết đơn** từ **cây nhị phân tìm kiếm (BST)** sao cho:  
**Giá trị các phần tử trong danh sách có thứ tự giảm dần**.

## Cấu trúc cây và danh sách

```cpp
// Cây nhị phân
struct nodetree {
    int info;
    struct nodetree* pLeft;
    struct nodetree* pRight;
};
typedef struct nodetree NODETREE;
typedef NODETREE* TREE;

// Danh sách liên kết đơn
struct nodelist {
    int info;
    struct nodelist* pNext;
};
typedef struct nodelist NODELIST;

struct list {
    NODELIST* pHead;
    NODELIST* pTail;
};
typedef struct list LIST;
```

## Các hàm hỗ trợ

### Khởi tạo danh sách

```cpp
void Init(LIST &l) {
    l.pHead = l.pTail = NULL;
}
```

### Tạo node và thêm vào cuối danh sách

```cpp
NODELIST* GetNode(int x) {
    NODELIST* p = new NODELIST;
    if (p == NULL) return NULL;
    p->info = x;
    p->pNext = NULL;
    return p;
}

void AddTail(LIST &l, NODELIST* p) {
    if (l.pHead == NULL)
        l.pHead = l.pTail = p;
    else {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}
```

## Duyệt cây theo thứ tự RNL để tạo danh sách giảm dần

```cpp
void RNL(TREE Root, LIST &l) {
    if (Root == NULL) return;
    RNL(Root->pRight, l);             // Duyệt bên phải trước
    NODELIST* p = GetNode(Root->info);
    if (p != NULL) AddTail(l, p);     // Thêm vào cuối danh sách
    RNL(Root->pLeft, l);
}
```

### Gọi hàm tạo danh sách

```cpp
void BuildList(TREE Root, LIST &l) {
    Init(l);
    RNL(Root, l);
}
```

## Ví dụ kết quả

| Input cây BST | Output danh sách liên kết (giảm dần) |
|---------------|--------------------------------------|
| `10 5 15 3 9 12 18 7 20` | `20 18 15 12 10 9 7 5 3` |
| `5`           | `5`                                  |
| `10 5 15`     | `15 10 5`                            |

## Ghi chú

- Thứ tự duyệt RNL đảm bảo giảm dần: Right → Node → Left
- Sử dụng danh sách liên kết đơn để lưu trữ kết quả

---
---

# Cây nhị phân tìm kiếm 
# Bài 016 – Xóa phần tử theo So_lan trong cây nhị phân tìm kiếm (BST)
## Mô tả
Cho một cây nhị phân tìm kiếm `t` có cấu trúc nút là `BST_NODE`:

```cpp
struct BST_NODE {
    int Key;       // Khóa của nút
    int So_lan;    // Số lần xuất hiện
    struct BST_NODE* Left;
    struct BST_NODE* Right;
};

struct BST_TREE {
    struct BST_NODE* pRoot; // Nút gốc của cây
};
```

## Yêu cầu
Viết hàm:

1. **Xóa phần tử có khóa X trong cây BST** theo quy tắc:
   - Nếu nút có khóa X tồn tại: giảm `So_lan` đi 1.
   - Nếu không tồn tại: thông báo.
2. **Duyệt cây theo thứ tự NLR** và in ra màn hình các phần tử đang tồn tại (So_lan > 0).

## Hàm xóa phần tử

```cpp
int DeleteNode(BST_TREE &t, int x) {
    if (t.pRoot == NULL)
        return 0;
    if (t.pRoot->Key == x) {
        if (t.pRoot->So_lan > 0) {
            t.pRoot->So_lan--;
            return 1;
        }
        return 0;
    }
    if (x < t.pRoot->Key)
        return DeleteNode(*(BST_TREE*)&t.pRoot->Left, x);
    return DeleteNode(*(BST_TREE*)&t.pRoot->Right, x);
}

void XoaGiaTri(BST_TREE &t, int X) {
    int kq = DeleteNode(t, X);
    if (kq == 0)
        printf("Khong ton tai X hoac So_lan da la 0\n");
    else
        printf("Xoa thanh cong.\n");
}
```

## Hàm duyệt cây theo NLR

```cpp
void NLR(BST_NODE* Root) {
    if (Root == NULL) return;
    if (Root->So_lan > 0)
        printf("%4d (So_lan: %d)", Root->Key, Root->So_lan);
    NLR(Root->Left);
    NLR(Root->Right);
}

void LietKe(BST_TREE t) {
    NLR(t.pRoot);
    printf("\n");
}
```

## Ví dụ kết quả

### Input:
```txt
10 5 15 5 10 3 9 15 20
```

### Các thao tác:
```cpp
LietKe(t);
XoaGiaTri(t, 5);
XoaGiaTri(t, 5);
XoaGiaTri(t, 7);
```

### Output:

```
10(2) 5(2) 3(1) 9(1) 15(2) 20(1)
10(2) 5(1) 3(1) 9(1) 15(2) 20(1)
10(2) 3(1) 9(1) 15(2) 20(1)
Khong ton tai X hoac So_lan da la 0
```

## Ghi chú

- Trường `So_lan` giúp lưu nhiều giá trị trùng nhau trong BST.
- Việc ép kiểu `(BST_TREE*)&t.pRoot->Left` dùng mẹo để xử lý đệ quy mà không cần viết thêm hàm phụ.

---

# Bài 001 – Thu hồi bộ nhớ cây nhị phân tìm kiếm
## Mô tả
Viết hàm thu hồi toàn bộ bộ nhớ đã được cấp phát cho cây nhị phân tìm kiếm các số nguyên.  
Việc thu hồi nhằm đảm bảo không rò rỉ bộ nhớ (memory leak) sau khi không còn sử dụng cây.

## Cấu trúc cây

```cpp
struct node {
    int info;
    struct node* pLeft;
    struct node* pRight;
};
typedef struct node NODE;
typedef NODE* TREE;
```

## Hàm thu hồi bộ nhớ

```cpp
void RemoveAll(TREE &t) {
    if (t == NULL)
        return;
    RemoveAll(t->pLeft);     // Thu hồi cây con bên trái
    RemoveAll(t->pRight);    // Thu hồi cây con bên phải
    delete t;                // Thu hồi chính nút hiện tại
    t = NULL;                // Gán lại con trỏ về NULL để tránh con trỏ treo
}
```

## Giải thích
- Hàm sử dụng **duyệt hậu tự (post-order)** để đảm bảo luôn xóa cây con trước, sau đó mới xóa nút hiện tại.
- Sau khi xóa một nút, cần gán lại con trỏ về `NULL` để tránh lỗi sử dụng vùng nhớ đã bị thu hồi.

## Ví dụ sử dụng

```cpp
TREE t = NULL;
// Giả sử t đã được tạo và có dữ liệu...
RemoveAll(t);
// Sau lời gọi này, toàn bộ bộ nhớ của cây đã được giải phóng.
```

---

# Bài 017 – Tìm phần tử thay thế trong thao tác xóa nút có 2 con (BST)
## Mô tả
Trong **cây nhị phân tìm kiếm (BST)**, khi xóa một nút `P` có **2 con**, ta cần thay thế `P` bằng một nút khác để giữ nguyên tính chất BST.  
Nguyên tắc thay thế: **Tìm phần tử tận cùng bên trái của nhánh phải của P** (gọi là **Successor**).

## Cấu trúc cây

```cpp
struct node {
    int info;
    struct node* pLeft;
    struct node* pRight;
};
typedef struct node NODE;
typedef NODE* TREE;
```

## Hàm tìm phần tử thay thế (SearchStandFor)

```cpp
void SearchStandFor(TREE &p, TREE &q) {
    if (q->pLeft) {
        SearchStandFor(p, q->pLeft); // tiếp tục đi về bên trái
    } else {
        p->info = q->info;           // gán giá trị thay thế
        TREE temp = q;               // giữ địa chỉ cần xóa
        q = q->pRight;               // nối lại nhánh cây
        delete temp;                 // xóa nút thay thế
    }
}
```

- `p`: là nút cần bị xóa (có 2 con).
- `q`: là nhánh phải của `p` → ta đi về bên trái của `q` đến khi tận cùng.

## Ví dụ kết quả

| Input             | Thao tác        | Output sau khi xóa       |
|------------------|------------------|---------------------------|
| `10 5 15 3 9 12 18 7 20` | `Delete(t, 15)` | `10 5 3 9 7 18 12 20` |
| (cây ban đầu)     | `Delete(t, 5)`   | `10 5 3 9 7 18 12 20`     |
| `10 5 15`         | `Delete(t, 10)`  | `15 5`                    |

## Ghi chú

- Hàm `SearchStandFor()` chỉ là 1 bước trong quá trình xóa một nút có 2 con trong BST.
- Sau khi tìm phần tử thay thế, ta gán lại giá trị và xóa nút cũ.
- Cần kết hợp với hàm `DeleteNode()` tổng quát để sử dụng trong thao tác xóa.

---

# Bài 018 – Sắp xếp mảng bằng Cây Nhị Phân Tìm Kiếm (BST)
## Mô tả
Cho một mảng `a` gồm `n` phần tử kiểu `int`. Ta thực hiện sắp xếp mảng bằng cách:
1. Tạo một cây nhị phân tìm kiếm (BST) từ các phần tử trong mảng.
2. Duyệt cây và đưa các phần tử trở lại mảng sao cho mảng được sắp xếp tăng dần.

## Câu a: Phương pháp duyệt

- **Phương pháp duyệt:** LNR (trái – gốc – phải) giúp lấy các phần tử theo thứ tự tăng dần.

## Câu b: Cấu trúc cây nhị phân

```cpp
struct node {
    int info;
    struct node* pLeft;
    struct node* pRight;
};
typedef struct node NODE;
typedef NODE* TREE;
```

## Câu c: Hàm xử lý
### Khởi tạo cây

```cpp
void Init(TREE &t) {
    t = NULL;
}
```

### Tạo node mới

```cpp
NODE* GetNode(int x) {
    NODE* p = new NODE;
    if (p == NULL) return NULL;
    p->info = x;
    p->pLeft = p->pRight = NULL;
    return p;
}
```

### Thêm node vào cây

```cpp
int InsertNode(TREE &t, int x) {
    if (t) {
        if (t->info == x) return 0;
        if (t->info < x) return InsertNode(t->pRight, x);
        return InsertNode(t->pLeft, x);
    }
    t = GetNode(x);
    return (t == NULL) ? -1 : 1;
}
```

### Tạo cây từ mảng

```cpp
int TaoCay(TREE &t, int a[], int n) {
    Init(t);
    for (int i = 0; i < n; i++) {
        if (InsertNode(t, a[i]) == -1)
            return 0;
    }
    return 1;
}
```

### Duyệt LNR và gán lại vào mảng

```cpp
void LNR(TREE t, int a[], int &n) {
    if (t == NULL) return;
    LNR(t->pLeft, a, n);
    a[n++] = t->info;
    LNR(t->pRight, a, n);
}
```

## Ví dụ kết quả

| Input                         | Output                                      |
|------------------------------|---------------------------------------------|
| `10 5 15 3 9 12 18 7 20`      | Mảng trước: `10 5 15 3 9 12 18 7 20`<br>Cây BST: `10 5 3 9 7 15 12 18 20`<br>Mảng sau sắp xếp: `3 5 7 9 10 12 15 18 20` |

---

# Bài 033 – Duyệt cây nhị phân không dùng đệ quy
## Mô tả
Cài đặt các thuật toán duyệt cây nhị phân mà **không sử dụng đệ quy**:

- Duyệt **NLR** (Node-Left-Right) dùng **Stack**
- Duyệt **Level-order** (theo mức) dùng **Queue**

## Cấu trúc cây nhị phân

```cpp
struct node {
    int info;
    struct node* pLeft;
    struct node* pRight;
};
typedef struct node NODE;
typedef NODE* TREE;
```

## Duyệt NLR bằng Stack
### Ý tưởng
- Duyệt theo thứ tự **Node → Left → Right**
- Stack là LIFO, nên ta push **phải trước**, **trái sau**

### Cài đặt

```cpp
void PreOrderNonRecursive(TREE t) {
    if (t == NULL) return;
    Stack s;
    InitStack(s);
    Push(s, t);

    cout << "Duyet NLR bang Stack: ";
    while (!IsEmptyStack(s)) {
        TREE p = Pop(s);
        cout << p->info << " ";

        if (p->pRight) Push(s, p->pRight);
        if (p->pLeft) Push(s, p->pLeft);
    }
    cout << endl;
    ClearStack(s);
}
```

## Duyệt theo mức dùng Queue
### Ý tưởng
- Duyệt từ **trên xuống dưới**, **trái sang phải**
- Queue là FIFO → node nào vào trước sẽ được xử lý trước

### Cài đặt

```cpp
void LevelOrderNonRecursive(TREE t) {
    if (t == NULL) return;
    Queue q;
    InitQueue(q);
    Enqueue(q, t);

    cout << "Duyet theo muc dung Queue: ";
    while (!IsEmptyQueue(q)) {
        TREE p = Dequeue(q);
        cout << p->info << " ";

        if (p->pLeft) Enqueue(q, p->pLeft);
        if (p->pRight) Enqueue(q, p->pRight);
    }
    cout << endl;
    ClearQueue(q);
}
```

## Kết quả chạy thử

| INPUT                 | OUTPUT                                                                 |
|----------------------|------------------------------------------------------------------------|
| `10 5 15 3 9 12 18 7 20` | Duyet NLR bang Stack: `10 5 3 9 7 15 12 18 20`  |
|                      | Duyet theo muc bang Queue: `10 5 15 3 9 12 18 7 20` |

---

# Bài 037 – Kiểm tra cây nhị phân có cân bằng không
## Mô tả
Viết hàm kiểm tra xem một **cây nhị phân** có phải là **cây cân bằng** không. Một cây được gọi là cân bằng nếu:
- Với mỗi nút, hiệu số chiều cao của cây con trái và cây con phải không vượt quá 1.

## Cấu trúc dữ liệu

```cpp
struct node {
    int info;
    struct node* pLeft;
    struct node* pRight;
};
typedef struct node NODE;
typedef NODE* TREE;
```

## Các hàm sử dụng
### Tính chiều cao của cây
```cpp
int ChieuCao(TREE t) {
    if (t == NULL)
        return 0;
    int a = ChieuCao(t->pLeft);
    int b = ChieuCao(t->pRight);
    return max(a, b) + 1;
}
```

### Tìm nút lớn nhất
```cpp
NODE* LonNhat(TREE t) {
    if (t == NULL) return NULL;
    NODE* lc = t;
    NODE* a = LonNhat(t->pLeft);
    if (a && a->info > lc->info) lc = a;
    NODE* b = LonNhat(t->pRight);
    if (b && b->info > lc->info) lc = b;
    return lc;
}
```

### Tìm nút nhỏ nhất
```cpp
NODE* NhoNhat(TREE t) {
    if (t == NULL) return NULL;
    NODE* lc = t;
    NODE* a = NhoNhat(t->pLeft);
    if (a && a->info < lc->info) lc = a;
    NODE* b = NhoNhat(t->pRight);
    if (b && b->info < lc->info) lc = b;
    return lc;
}
```

### Kiểm tra cây cân bằng
```cpp
int ktCanBang(TREE Root) {
    if (Root == NULL) return 1;
    if (!ktCanBang(Root->pLeft) || !ktCanBang(Root->pRight))
        return 0;
    
    NODE* a = LonNhat(Root->pLeft);
    if (a && a->info > Root->info) return 0;
    
    a = NhoNhat(Root->pRight);
    if (a && a->info < Root->info) return 0;
    
    int x = ChieuCao(Root->pLeft);
    int y = ChieuCao(Root->pRight);
    return abs(x - y) <= 1;
}
```

## Kết quả mẫu

| Input               | Output         |
|---------------------|----------------|
| `10 5 15 3 9 12 18` | Cây cân bằng ✅ |
| `10 5 3 2`          | Không cân bằng ❌ |

## Ghi chú
- Cây nhị phân được gọi là **cân bằng** nếu tại mọi nút, chiều cao hai cây con không chênh lệch quá 1.
- Ngoài ra, chương trình còn kiểm tra **tính chất cây nhị phân tìm kiếm** tại mỗi bước để đảm bảo hợp lệ.


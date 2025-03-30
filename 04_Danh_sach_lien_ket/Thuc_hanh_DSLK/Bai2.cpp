#include <iostream>
#include <cstring>

using namespace std;

struct SinhVien {
    char hoTen[50];
    char diaChi[70];
    char lop[10];
    int khoa;
    SinhVien* next;
};

// Danh sách sinh viên
struct ListSV {
    SinhVien* head;
    void Init() { head = NULL; }
    void Insert(SinhVien sv);
    void RemoveByName(const char* name);
    void RemoveByAddress(const char* address);
    void Show();
    void Clear();
    void Sort(int (*compare)(SinhVien*, SinhVien*));
};

// Hàm so sánh theo tiêu chí
int CompareByName(SinhVien* sv1, SinhVien* sv2) {
    return strcmp(sv1->hoTen, sv2->hoTen);
}

int CompareByAddress(SinhVien* sv1, SinhVien* sv2) {
    return strcmp(sv1->diaChi, sv2->diaChi);
}

int CompareByClass(SinhVien* sv1, SinhVien* sv2) {
    return strcmp(sv1->lop, sv2->lop);
}

int CompareByCourse(SinhVien* sv1, SinhVien* sv2) {
    return sv1->khoa - sv2->khoa;
}

// Thêm sinh viên vào danh sách
void ListSV::Insert(SinhVien sv) {
    SinhVien* p = new SinhVien;
    strcpy(p->hoTen, sv.hoTen);
    strcpy(p->diaChi, sv.diaChi);
    strcpy(p->lop, sv.lop);
    p->khoa = sv.khoa;
    p->next = head;
    head = p;
}

// Xóa sinh viên theo tên
void ListSV::RemoveByName(const char* name) {
    SinhVien *p = head, *prev = NULL;
    while (p && strcmp(p->hoTen, name) != 0) {
        prev = p;
        p = p->next;
    }
    if (p) {
        if (prev) prev->next = p->next;
        else head = p->next;
        delete p;
    }
}

// Xóa sinh viên theo địa chỉ
void ListSV::RemoveByAddress(const char* address) {
    SinhVien *p = head, *prev = NULL;
    while (p && strcmp(p->diaChi, address) != 0) {
        prev = p;
        p = p->next;
    }
    if (p) {
        if (prev) prev->next = p->next;
        else head = p->next;
        delete p;
    }
}

// Hiển thị danh sách sinh viên
void ListSV::Show() {
    if (!head) {
        cout << "Danh sách rỗng.\n";
        return;
    }
    for (SinhVien* p = head; p; p = p->next) {
        cout << p->hoTen << " - " << p->diaChi << " - " << p->lop << " - " << p->khoa << "\n";
    }
}

// Xóa toàn bộ danh sách
void ListSV::Clear() {
    while (head) {
        SinhVien* p = head;
        head = head->next;
        delete p;
    }
}

// Sắp xếp danh sách bằng Selection Sort với con trỏ hàm
void ListSV::Sort(int (*compare)(SinhVien*, SinhVien*)) {
    for (SinhVien* p = head; p != NULL; p = p->next) {
        SinhVien* minNode = p;
        for (SinhVien* q = p->next; q != NULL; q = q->next) {
            if (compare(q, minNode) < 0) {
                minNode = q;
            }
        }
        // Hoán đổi nội dung thay vì con trỏ
        if (minNode != p) {
            SinhVien temp = *p;
            *p = *minNode;
            *minNode = temp;
            // Giữ nguyên con trỏ next
            swap(p->next, minNode->next);
        }
    }
}

int main() {
    ListSV svList;
    svList.Init();

    cout << "\n===== NHẬP DANH SÁCH SINH VIÊN =====\n";
    cin.ignore(); // Để loại bỏ ký tự '\n' còn lại trong bộ đệm

    for (int i = 0; i < 10; i++) {
        SinhVien sv;
        cout << "Nhập họ tên: "; cin.getline(sv.hoTen, 50);
        cout << "Nhập địa chỉ: "; cin.getline(sv.diaChi, 70);
        cout << "Nhập lớp: "; cin.getline(sv.lop, 10);
        cout << "Nhập khóa: "; cin >> sv.khoa;
        cin.ignore(); // Loại bỏ ký tự '\n' sau khi nhập số
        svList.Insert(sv);
    }
    svList.Show();

    cout << "\nSắp xếp danh sách theo tên:\n";
    svList.Sort(CompareByName);
    svList.Show();

    cout << "\nXóa sinh viên 'Nguyen Van Teo'\n";
    svList.RemoveByName("Nguyen Van Teo");
    svList.Show();

    cout << "\nXóa sinh viên có địa chỉ 'Nguyen Van Cu'\n";
    svList.RemoveByAddress("Nguyen Van Cu");
    svList.Show();

    SinhVien newSv = {"Tran Thi Mo", "25 Hong Bang", "TT0901", 2009, NULL};
    svList.Insert(newSv);

    cout << "\nDanh sách sau khi thêm sinh viên Tran Thi Mo:\n";
    svList.Show();

    // Giải phóng bộ nhớ
    svList.Clear();

    return 0;
}

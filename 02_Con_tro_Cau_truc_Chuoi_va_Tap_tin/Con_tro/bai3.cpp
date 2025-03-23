#include <iostream>
using namespace std;

bool NguyenAm(char c) {
    c = tolower(c); // Chuyển ký tự về dạng chữ thường để kiểm tra
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void LocNguyenAm(char *a, int n, char *b, int *m) {
    *m = 0; // Khởi tạo số lượng phần tử của b
    for (int i = 0; i < n; i++) {
        if (NguyenAm(*(a + i))) {
            *(b + (*m)) = *(a + i); // Thêm ký tự nguyên âm vào b
            (*m)++;
        }
    }
}

int main() {
    int n;
    cout << "Moi ban nhap so luong phan tu: ";
    cin >> n;

    if (n <= 0 || n > 100) {
        cout << "So luong phan tu khong hop le!" << endl;
        return 0;
    }

    char a[100], b[100];
    int m; // Số lượng phần tử của dãy b

    for (int i = 0; i < n; i++) {
        cout << "Phan tu " << i << ": ";
        cin >> *(a + i); // Nhập giá trị cho mảng a
    }

    LocNguyenAm(a, n, b, &m);

    cout << "Day b chua cac ky tu nguyen am: ";
    for (int i = 0; i < m; i++) {
        cout << *(b + i) << " ";
    }
    cout << endl;

    return 0;
}

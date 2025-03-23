#include <iostream>
#include <cstring>
using namespace std;

void XoaKyTu(char s[], int k) {
    int n = strlen(s);

    // Kiểm tra vị trí k có hợp lệ không
    if (k < 0 || k >= n) {
        cout << "Vi tri xoa khong hop le!" << endl;
        return;
    }

    // Dịch các ký tự từ vị trí k+1 về trước
    for (int i = k; i < n - 1; i++) {
        s[i] = s[i + 1];
    }

    // Đặt ký tự cuối thành '\0' để kết thúc chuỗi
    s[n - 1] = '\0';
}

int main() {
    char s[1001];
    int k;

    // Nhập chuỗi
    cout << "Moi ban nhap chuoi s: ";
    cin.getline(s, 1001);

    // Nhập vị trí cần xóa
    cout << "Moi ban nhap vi tri can xoa: ";
    cin >> k;

    // Gọi hàm xóa ký tự tại vị trí k
    XoaKyTu(s, k);

    // Xuất chuỗi kết quả
    if (k >= 0 && k < strlen(s) + 1) {
        cout << "Chuoi sau khi xoa ky tu tai vi tri " << k << ": " << s << endl;
    }

    return 0;
}

#include <iostream>
#include <cstring>
using namespace std;

void ChenKyTu(char s[], int k, char c) {
    int n = strlen(s);

    // Kiểm tra vị trí k có hợp lệ không
    if (k < 0 || k > n) {
        cout << "Vi tri chen khong hop le!" << endl;
        return;
    }

    // Dịch các ký tự từ vị trí k về sau lùi một ô
    for (int i = n; i >= k; i--) {
        s[i + 1] = s[i];
    }

    // Gán ký tự c vào vị trí k
    s[k] = c;

    // Thêm ký tự kết thúc chuỗi
    s[n + 1] = '\0';
}

int main() {
    char s[1001], c;
    int k;

    // Nhập chuỗi
    cout << "Moi ban nhap chuoi s: ";
    cin.getline(s, 1001);

    // Nhập vị trí cần chèn
    cout << "Moi ban nhap vi tri can chen: ";
    cin >> k;

    // Nhập ký tự cần chèn
    cout << "Moi ban nhap ky tu chen: ";
    cin >> c;

    // Gọi hàm chèn ký tự
    ChenKyTu(s, k, c);

    // Xuất chuỗi kết quả nếu vị trí hợp lệ
    if (k >= 0 && k <= strlen(s)) {
        cout << "Chuoi sau khi them ky tu \"" << c << "\" vao vi tri " << k << ": " << s << endl;
    }

    return 0;
}

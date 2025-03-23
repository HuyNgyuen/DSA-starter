#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

void SapXepChuoi(char s[]) {
    // Lấy độ dài của chuỗi
    int n = strlen(s);

    // Sắp xếp các ký tự trong chuỗi
    sort(s, s + n);
}

int main() {
    char s[1001];

    // Nhập chuỗi từ bàn phím
    cout << "Moi ban nhap chuoi s: ";
    cin.getline(s, 1001);

    // Gọi hàm sắp xếp chuỗi
    SapXepChuoi(s);

    // Xuất chuỗi đã sắp xếp
    cout << "Chuoi sau khi sap xep: " << s << endl;

    return 0;
}

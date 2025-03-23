#include <iostream>
using namespace std;

bool TinhChanLe(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        if ((arr[i] % 2) == (arr[i - 1] % 2)) {
            return false; // Hai phần tử liên tiếp không xen kẽ chẵn lẻ
        }
    }
    return true;
}

bool TinhToanChan(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            return false; // Tìm thấy một phần tử lẻ
        }
    }
    return true;
}

int main() {
    int n;
    cout << "Moi ban nhap so luong phan tu: ";
    cin >> n;

    if (n <= 0 || n > 100) {
        cout << "So luong phan tu khong hop le!" << endl;
        return 0;
    }

    int arr[100];
    for (int i = 0; i < n; i++) {
        cout << "Phan tu " << i << ": ";
        cin >> *(arr + i); // Sử dụng con trỏ để nhập giá trị
    }

    bool isAlternating = TinhChanLe(arr, n);
    bool isAllEven = TinhToanChan(arr, n);

    if (isAlternating) {
        cout << "+ Day co tinh chat chan le" << endl;
    } else {
        cout << "+ Day khong co tinh chat chan le" << endl;
    }

    if (isAllEven) {
        cout << "+ Day co tinh chat toan chan" << endl;
    } else {
        cout << "+ Day khong co tinh chat toan chan" << endl;
    }

    return 0;
}
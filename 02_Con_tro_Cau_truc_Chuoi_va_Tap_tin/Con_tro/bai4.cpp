#include <iostream>
using namespace std;

void mergeArrays(double *a, int n, double *b, int m, double *c, int *k) {
    int i = 0, j = 0, idx = 0;
    while (i < n && j < m) {
        if (*(a + i) < *(b + j)) {
            *(c + idx) = *(a + i);
            i++;
        } else {
            *(c + idx) = *(b + j);
            j++;
        }
        idx++;
    }

    // Copy các phần tử còn lại của a (nếu có)
    while (i < n) {
        *(c + idx) = *(a + i);
        i++;
        idx++;
    }

    // Copy các phần tử còn lại của b (nếu có)
    while (j < m) {
        *(c + idx) = *(b + j);
        j++;
        idx++;
    }

    *k = idx; // Cập nhật số lượng phần tử của c
}

int main() {
    int n, m, k;

    cout << "+ Day so a" << endl;
    cout << "Moi ban nhap so luong phan tu: ";
    cin >> n;
    if (n <= 0 || n > 100) {
        cout << "So luong phan tu khong hop le!" << endl;
        return 0;
    }

    double a[100];
    for (int i = 0; i < n; i++) {
        cout << "Phan tu " << i << ": ";
        cin >> *(a + i);
    }

    cout << "+ Day so b" << endl;
    cout << "Moi ban nhap so luong phan tu: ";
    cin >> m;
    if (m <= 0 || m > 100) {
        cout << "So luong phan tu khong hop le!" << endl;
        return 0;
    }

    double b[100], c[200];
    for (int i = 0; i < m; i++) {
        cout << "Phan tu " << i << ": ";
        cin >> *(b + i);
    }

    mergeArrays(a, n, b, m, c, &k);

    cout << "+ Day so c" << endl;
    cout << "Day so co " << k << " phan tu: ";
    for (int i = 0; i < k; i++) {
        cout << *(c + i) << " ";
    }
    cout << endl;

    return 0;
}

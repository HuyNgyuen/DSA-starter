#include <iostream>
using namespace std;

void ChiaMang(int *a, int n, int *b, int *m, int *c, int *k) {
    *m = 0; // Số lượng phần tử chẵn trong b
    *k = 0; // Số lượng phần tử lẻ trong c
    for (int i = 0; i < n; i++) {
        if (*(a + i) % 2 == 0) {
            *(b + (*m)) = *(a + i); // Thêm số chẵn vào b
            (*m)++;
        } else {
            *(c + (*k)) = *(a + i); // Thêm số lẻ vào c
            (*k)++;
        }
    }
}

int main() {
    int n;
    cout << "+ Day so a" << endl;
    cout << "Moi ban nhap so luong phan tu: ";
    cin >> n;

    if (n <= 0 || n > 100) {
        cout << "So luong phan tu khong hop le!" << endl;
        return 0;
    }

    int a[100], b[100], c[100];
    int m, k; // Số lượng phần tử của dãy b và c

    for (int i = 0; i < n; i++) {
        cout << "Phan tu " << i << ": ";
        cin >> *(a + i);
    }

    ChiaMang(a, n, b, &m, c, &k);

    cout << "+ Day so b chua so chan\nDay so co " << m << " phan tu: ";
    for (int i = 0; i < m; i++) {
        cout << *(b + i) << " ";
    }
    cout << endl;

    cout << "+ Day so c chua so le\nDay so co " << k << " phan tu: ";
    for (int i = 0; i < k; i++) {
        cout << *(c + i) << " ";
    }
    cout << endl;

    return 0;
}

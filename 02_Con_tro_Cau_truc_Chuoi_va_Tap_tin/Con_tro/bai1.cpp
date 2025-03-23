#include <iostream>
#include <cmath>
using namespace std;

void Ptbac2(double a, double b, double c, double *x1, double *x2, int *n) {
    double delta = b * b - 4 * a * c;

    if (delta > 0) {
        *n = 2;
        *x1 = (-b + sqrt(delta)) / (2 * a);
        *x2 = (-b - sqrt(delta)) / (2 * a);
    } else if (delta == 0) {
        *n = 1;
        *x1 = -b / (2 * a);
        *x2 = *x1; // Nghiệm kép, x1 và x2 giống nhau
    } else {
        *n = 0; // Phương trình vô nghiệm
    }
}

int main() {
    double a, b, c;
    cout << "Moi ban nhap he so a, b, c: ";
    cin >> a >> b >> c;

    if (a == 0) {
        cout << "Day khong phai la phuong trinh bac hai." << endl;
        return 0;
    }

    double x1, x2;
    int n;

    Ptbac2(a, b, c, &x1, &x2, &n);

    if (n == 2) {
        cout << "Phuong trinh co 2 nghiem phan biet: x1 = " << x1 << ", x2 = " << x2 << endl;
    } else if (n == 1) {
        cout << "Phuong trinh co 1 nghiem kep x = " << x1 << "." << endl;
    } else {
        cout << "Phuong trinh vo nghiem." << endl;
    }

    return 0;
}

#include <iostream>
#include <cmath> // Thư viện dùng hàm sqrt

using namespace std;

// Hàm giải phương trình bậc 2
void giaiptbac2(double a, double b, double c) {
    // Trường hợp đặc biệt: a = 0
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                cout << "Phuong trinh co vo so nghiem" << endl;
            } else {
                cout << "Phuong trinh vo nghiem" << endl;
            }
        } else {
            // Phương trình bậc 1: bx + c = 0
            double x = -c / b;
            cout << "Phuong trinh co 1 nghiem" << endl;
            printf("%.2f\n", x);
        }
    } else {
        // Phương trình bậc 2: ax^2 + bx + c = 0
        double delta = b * b - 4 * a * c;

        if (delta < 0) {
            cout << "Phuong trinh vo nghiem" << endl;
        } else if (delta == 0) {
            // Phương trình có 1 nghiệm kép
            double x = -b / (2 * a);
            cout << "Phuong trinh co 1 nghiem" << endl;
            printf("%.2f\n", x);
        } else {
            // Phương trình có 2 nghiệm phân biệt
            double x1 = (-b - sqrt(delta)) / (2 * a);
            double x2 = (-b + sqrt(delta)) / (2 * a);

            // Sắp xếp nghiệm theo thứ tự tăng dần
            if (x1 > x2) {
                swap(x1, x2);
            }

            cout << "Phuong trinh co 2 nghiem" << endl;
            printf("%.2f %.2f\n", x1, x2);
        }
    }
}

// Hàm chứa tập testcase
void runTestCases() {
    // cout << "Running test cases...\n";
    
    // Testcase 1: Phương trình có vô số nghiệm
    // cout << "Testcase 1: ";
    giaiptbac2(0, 0, 0);
    cout << " --- \n";

    // Testcase 2: Phương trình vô nghiệm
    // cout << "Testcase 2: ";
    giaiptbac2(1, 2, 10);
    cout << " --- \n";

    // Testcase 3: Phương trình có 1 nghiệm kép
    // cout << "Testcase 4: ";
    giaiptbac2(1, 2, 1);
    cout << " --- \n";

    // Testcase 4: Phương trình có 2 nghiệm phân biệt
    // cout << "Testcase 5: ";
    giaiptbac2(1, -5, 6);
    cout << " --- \n";
}

// Hàm main
int main() {
    // // Chạy các testcase
    // runTestCases();

    // // Nhập liệu từ người dùng
    // double a, b, c;
    // cout << "\nNhap a, b, c: ";
    // cin >> a >> b >> c;

    // // Giải phương trình với dữ liệu người dùng nhập
    // giaiptbac2(a, b, c);

    return 0;
}

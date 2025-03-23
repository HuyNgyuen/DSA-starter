#include <iostream>
#include <cmath>

using namespace std;

// Hàm giải phương trình trùng phương
void giaipttrungphuong(double a, double b, double c) {
    // Kiểm tra xem phương trình có phải là phương trình bậc 2 hay không.
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                cout << "Phuong trinh co vo so nghiem" << endl;
            } else {
                cout << "Phuong trinh vo nghiem" << endl;
            }
        } else {
            // Tính giá trị trung gian t để kiểm tra nghiệm của phương trình khi a = 0.
            double t = -c / b;
            if (t < 0) {
                cout << "Phuong trinh vo nghiem" << endl;
            } else {
                double x1 = -sqrt(t);
                double x2 = sqrt(t);
                cout << "Phuong trinh co 2 nghiem" << endl;
                cout << x1 << " " << x2 << endl;
            }
        }
    } else {
        // Tính delta để kiểm tra nghiệm của phương trình bậc 4.
        double delta = b * b - 4 * a * c;
        if (delta < 0) {
            cout << "Phuong trinh vo nghiem" << endl;
        } else if (delta == 0) {
            double t = -b / (2 * a);
            if (t < 0) {
                cout << "Phuong trinh vo nghiem" << endl;
            } else {
                double x1 = -sqrt(t);
                double x2 = sqrt(t);
                cout << "Phuong trinh co 2 nghiem" << endl;
                cout << x1 << " " << x2 << endl;
            }
        } else {
            double t1 = (-b - sqrt(delta)) / (2 * a);
            double t2 = (-b + sqrt(delta)) / (2 * a);
            double solutions[4]; // Mảng tĩnh để lưu nghiệm của phương trình (tối đa 4 nghiệm).
            int count = 0; // Biến đếm số lượng nghiệm tìm được.

            if (t1 >= 0) {
                solutions[count++] = -sqrt(t1); // Thêm nghiệm \(-\sqrt{t1}\) vào mảng solutions và tăng biến đếm.
                solutions[count++] = sqrt(t1);
            }
            if (t2 >= 0) {
                solutions[count++] = -sqrt(t2);
                solutions[count++] = sqrt(t2);
            }

            if (count == 0) {
                cout << "Phuong trinh vo nghiem" << endl;
            } else {
                cout << "Phuong trinh co " << count << " nghiem" << endl;
                // Duyệt qua các nghiệm trong mảng để sắp xếp chúng theo thứ tự tăng dần.
                for (int i = 0; i < count; i++) {
                    for (int j = i + 1; j < count; j++) {
                        if (solutions[i] > solutions[j]) {
                            double temp = solutions[i];
                            solutions[i] = solutions[j];
                            solutions[j] = temp;
                        }
                    }
                }
                for (int i = 0; i < count; i++) {
                    cout << solutions[i] << " ";
                }
                cout << endl;
            }
        }
    }
}

// Hàm chứa tập testcase
void runTestCases() {
    // cout << "Running test cases..." << endl;

    // Testcase 1: Phương trình có vô số nghiệm
    // cout << "Testcase 1: ";
    giaipttrungphuong(0, 0, 0);
    cout << " --- \n";

    // Testcase 2: Phương trình vô nghiệm
    // cout << "Testcase 2: ";
    giaipttrungphuong(1, 2, 10);
    cout << " --- \n";

    // Testcase 3: Phương trình có 2 nghiệm
    // cout << "Testcase 3: ";
    giaipttrungphuong(1, -2, 1);
    cout << " --- \n";

    // Testcase 4: Phương trình có 4 nghiệm
    // cout << "Testcase 4: ";
    giaipttrungphuong(1, -5, 4);
    cout << " --- \n";

    // Testcase 5: Phương trình vô nghiệm do t < 0
    // cout << "Testcase 5: ";
    giaipttrungphuong(1, 2, 1);
    cout << " --- \n";
}

// Hàm main
int main() {
    // // Chạy các testcase
    // runTestCases();

    // // Nhập liệu từ bàn phím
    // double a, b, c;
    // cout << "\nNhap a, b, c: ";
    // cin >> a >> b >> c;

    // // Giải phương trình với dữ liệu người dùng nhập
    // giaipttrungphuong(a, b, c);

    return 0;
}

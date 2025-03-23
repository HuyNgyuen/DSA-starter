#include <iostream>
#include <cmath>

using namespace std;

// Hàm tìm phần tử chung của ba dãy
void findCommonElements(int nx, int x[], int ny, int y[], int nz, int z[]) {
    // Khởi tạo mảng đếm
    int count_x[10001] = {0};
    int count_y[10001] = {0};
    int count_z[10001] = {0};

    // Đếm số lần xuất hiện của các phần tử trong mỗi dãy
    for (int i = 0; i < nx; i++) {
        count_x[x[i]] = 1;
    }
    for (int i = 0; i < ny; i++) {
        count_y[y[i]] = 1;
    }
    for (int i = 0; i < nz; i++) {
        count_z[z[i]] = 1;
    }

    // Tìm phần tử chung
    int common_count = 0;
    int common_elements[10001];
    for (int i = 0; i <= 10000; i++) {
        if (count_x[i] == 1 && count_y[i] == 1 && count_z[i] == 1) {
            common_elements[common_count++] = i; // Lưu phần tử chung
        }
    }

    // Xuất kết quả
    cout << common_count << endl; // In số lượng phần tử chung
    for (int i = 0; i < common_count; i++) {
        cout << common_elements[i] << " ";
    }
    if (common_count > 0) {
        cout << endl;
    }
}

// Hàm chứa tập testcase
void runTestCases() {
    // Testcase 1
    // cout << "Testcase 1:\n";
    int nx1 = 5;
    int x1[] = {1, 2, 5, 4, 3};
    int ny1 = 4;
    int y1[] = {5, 6, 1, 4};
    int nz1 = 4;
    int z1[] = {5, 3, 5, 1};
    findCommonElements(nx1, x1, ny1, y1, nz1, z1);
    cout << " --- \n";

    // Testcase 2
    // cout << "Testcase 2:\n";
    int nx2 = 6;
    int x2[] = {10, 20, 30, 40, 50, 60};
    int ny2 = 5;
    int y2[] = {15, 25, 35, 40, 50};
    int nz2 = 7;
    int z2[] = {5, 10, 20, 30, 40, 50, 60};
    findCommonElements(nx2, x2, ny2, y2, nz2, z2);
    cout << " --- \n";

    // Testcase 3
    // cout << "Testcase 3:\n";
    int nx3 = 3;
    int x3[] = {1, 1, 1};
    int ny3 = 3;
    int y3[] = {1, 1, 1};
    int nz3 = 3;
    int z3[] = {1, 1, 1};
    findCommonElements(nx3, x3, ny3, y3, nz3, z3);
    cout << " --- \n";

    // Testcase 4
    // cout << "Testcase 4:\n";
    int nx4 = 0; // Không có phần tử
    int x4[] = {};
    int ny4 = 0;
    int y4[] = {};
    int nz4 = 0;
    int z4[] = {};
    findCommonElements(nx4, x4, ny4, y4, nz4, z4);
    cout << " --- \n";

    // Testcase 5
    // cout << "Testcase 5:\n";
    int nx5 = 4;
    int x5[] = {10000, 9999, 9998, 9997};
    int ny5 = 4;
    int y5[] = {9997, 9998, 10000, 9999};
    int nz5 = 4;
    int z5[] = {9999, 9997, 10000, 9998};
    findCommonElements(nx5, x5, ny5, y5, nz5, z5);
    cout << " --- \n";
    cout << endl;
}

int main() {
    // Chạy các testcase
    // runTestCases();

    // // Nhập dữ liệu từ bàn phím
    // int nx, ny, nz;
    // cin >> nx; // Số phần tử của dãy x
    // int x[nx];
    // for (int i = 0; i < nx; i++) {
    //     cin >> x[i];
    // }

    // cin >> ny; // Số phần tử của dãy y
    // int y[ny];
    // for (int i = 0; i < ny; i++) {
    //     cin >> y[i];
    // }

    // cin >> nz; // Số phần tử của dãy z
    // int z[nz];
    // for (int i = 0; i < nz; i++) {
    //     cin >> z[i];
    // }

    // // Gọi hàm xử lý và in kết quả
    // findCommonElements(nx, x, ny, y, nz, z);

    return 0;
}
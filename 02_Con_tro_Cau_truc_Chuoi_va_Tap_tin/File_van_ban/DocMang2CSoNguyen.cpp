#include <stdio.h>
#define FI "MangSo.inp"

void DocMang2Chieu(int a[][100], int *n, int *m) {
    FILE *fi;
    fi = fopen(FI, "rt"); // Mở file đọc

    if (fi == NULL) { // Kiểm tra lỗi mở file
        printf("Khong the doc file\n");
        return;
    }

    // Đọc số dòng và số cột
    fscanf(fi, "%d %d", n, m);

    // Đọc từng phần tử vào mảng
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *m; j++) {
            fscanf(fi, "%d", &a[i][j]);
        }
    }

    fclose(fi); // Đóng file
}

void XuatMang2Chieu(int a[][100], int n, int m) {
    printf("Mang 2 chieu doc duoc:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%5d", a[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int a[100][100]; // Mảng lưu các số nguyên
    int n, m;        // Số dòng và số cột

    DocMang2Chieu(a, &n, &m); // Gọi hàm đọc file

    if (n > 0 && m > 0) { // Nếu đọc thành công, xuất mảng
        XuatMang2Chieu(a, n, m);
    }

    return 0;
}

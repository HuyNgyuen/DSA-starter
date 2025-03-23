#include <stdio.h>
#define FI "DaySoNguyen.inp"

void DocDaySoNguyen(int a[], int *n) {
    FILE *fi;
    fi = fopen(FI, "rt"); // Mở file đọc

    if (fi == NULL) { // Kiểm tra lỗi mở file
        printf("Khong the doc file\n");
        return;
    }

    // Đọc số lượng phần tử
    fscanf(fi, "%d", n);

    // Đọc các số nguyên vào mảng
    for (int i = 0; i < *n; i++) {
        fscanf(fi, "%d", &a[i]);
    }

    fclose(fi); // Đóng file
}

void XuatDaySoNguyen(int a[], int n) {
    printf("Cac so trong file la: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int a[100]; // Mảng lưu các số nguyên
    int n;      // Số lượng phần tử

    DocDaySoNguyen(a, &n); // Gọi hàm đọc file

    if (n > 0) { // Nếu n hợp lệ thì xuất dãy số
        XuatDaySoNguyen(a, n);
    }

    return 0;
}

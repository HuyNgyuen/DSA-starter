#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#define INPUT_FILE "NT.INP"
#define OUTPUT_FILE "NT.OUT"

// Hàm kiểm tra số nguyên tố
bool KiemTraNguyenTo(int x) {
    if (x <= 1) return false; // Không phải số nguyên tố
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) return false; // Không phải số nguyên tố
    }
    return true; // Là số nguyên tố
}

void DocDuLieuVaTimNguyenTo() {
    FILE *fi = fopen(INPUT_FILE, "rt");
    if (fi == NULL) {
        printf("Khong the doc file %s\n", INPUT_FILE);
        return;
    }

    // Đọc số lượng phần tử
    int n;
    fscanf(fi, "%d", &n);

    // Đọc các phần tử và kiểm tra số nguyên tố
    std::vector<int> nguyenTo;
    for (int i = 0; i < n; i++) {
        int x;
        fscanf(fi, "%d", &x);
        if (KiemTraNguyenTo(x)) {
            nguyenTo.push_back(x);
        }
    }
    fclose(fi);

    // Sắp xếp danh sách số nguyên tố tăng dần
    std::sort(nguyenTo.begin(), nguyenTo.end());

    // Ghi kết quả vào file
    FILE *fo = fopen(OUTPUT_FILE, "wt");
    if (fo == NULL) {
        printf("Khong the ghi file %s\n", OUTPUT_FILE);
        return;
    }

    fprintf(fo, "%lu\n", nguyenTo.size()); // Ghi số lượng số nguyên tố
    for (int i = 0; i < nguyenTo.size(); i++) {
        fprintf(fo, "%d ", nguyenTo[i]); // Ghi các số nguyên tố
    }
    fclose(fo);
}

int main() {
    DocDuLieuVaTimNguyenTo();
    printf("Xu ly xong! Ket qua da duoc ghi vao file NT.OUT\n");
    return 0;
}

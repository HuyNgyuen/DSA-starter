#include <stdio.h>
#include <vector>
#define INPUT_FILE "CapSo.INP"
#define OUTPUT_FILE "CapSo.OUT"

// Hàm xử lý tìm các cặp số
void TimCapSo() {
    FILE *fi = fopen(INPUT_FILE, "rt");
    if (fi == NULL) {
        printf("Khong the doc file %s\n", INPUT_FILE);
        return;
    }

    // Đọc số lượng phần tử n và tổng cần tìm k
    int n, k;
    fscanf(fi, "%d %d", &n, &k);

    // Đọc mảng các số nguyên
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        fscanf(fi, "%d", &arr[i]);
    }
    fclose(fi);

    // Tìm các cặp thỏa mãn
    std::vector<std::pair<int, int>> result;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == k) {
                result.push_back({arr[i], arr[j]});
            }
        }
    }

    // Ghi kết quả ra file
    FILE *fo = fopen(OUTPUT_FILE, "wt");
    if (fo == NULL) {
        printf("Khong the ghi file %s\n", OUTPUT_FILE);
        return;
    }

    if (result.empty()) {
        fprintf(fo, "0\n");
    } else {
        for (const auto &p : result) {
            fprintf(fo, "%d %d\n", p.first, p.second);
        }
    }
    fclose(fo);
}

int main() {
    TimCapSo();
    printf("Xu ly xong! Ket qua da duoc ghi vao file %s\n", OUTPUT_FILE);
    return 0;
}

#include <iostream>
#include <vector>
#include <set>

using namespace std;

// (a) Tìm mảng nghịch thế từ hoán vị A
vector<int> findInversionArray(const vector<int>& A) {
    int N = A.size();
    vector<int> B(N, 0);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (A[j] > A[i]) {
                B[A[i] - 1]++; // Lưu vào chỉ số A[i] - 1 vì A là hoán vị của {1..N}
            }
        }
    }

    return B;
}

// (b) Tìm hoán vị A từ mảng nghịch thế B (nếu có)
vector<int> findPermutationFromInversionArray(const vector<int>& B) {
    int N = B.size();
    vector<int> A(N, 0);
    set<int> availableNumbers; // Tập hợp các số từ 1 đến N

    for (int i = 1; i <= N; i++) {
        availableNumbers.insert(i);
    }

    for (int i = N - 1; i >= 0; i--) {
        if (B[i] >= availableNumbers.size()) {
            return {}; // Không thể tạo hoán vị hợp lệ
        }

        auto it = availableNumbers.begin();
        advance(it, B[i]); // Lấy số ở vị trí B[i]
        A[i] = *it;
        availableNumbers.erase(it);
    }

    return A;
}

// Hàm hiển thị mảng
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    // (a) Tìm mảng nghịch thế từ hoán vị A
    vector<int> A = {5, 9, 1, 8, 2, 6, 4, 7, 3};
    cout << "Hoán vị A: ";
    printArray(A);

    vector<int> B = findInversionArray(A);
    cout << "Mảng nghịch thế B: ";
    printArray(B);

    // (b) Tìm hoán vị A từ mảng nghịch thế B
    vector<int> reconstructedA = findPermutationFromInversionArray(B);
    cout << "Hoán vị tái tạo từ B: ";
    if (!reconstructedA.empty()) {
        printArray(reconstructedA);
    } else {
        cout << "Không tồn tại hoán vị hợp lệ.\n";
    }

    return 0;
}

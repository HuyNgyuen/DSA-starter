#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// (a) Tìm số nguyên tố lớn nhất trong ma trận
int findLargestPrime(const vector<vector<int>>& matrix) {
    int maxPrime = -1;
    for (const auto& row : matrix) {
        for (int num : row) {
            if (isPrime(num) && num > maxPrime) {
                maxPrime = num;
            }
        }
    }
    return maxPrime;
}

// (b) Tìm các dòng có ít nhất một số nguyên tố
vector<int> findRowsWithPrime(const vector<vector<int>>& matrix) {
    vector<int> rows;
    for (int i = 0; i < matrix.size(); i++) {
        for (int num : matrix[i]) {
            if (isPrime(num)) {
                rows.push_back(i);
                break;  // Chỉ cần tìm thấy 1 số nguyên tố là đủ
            }
        }
    }
    return rows;
}

// (c) Tìm các dòng chỉ chứa số nguyên tố
vector<int> findRowsWithOnlyPrimes(const vector<vector<int>>& matrix) {
    vector<int> rows;
    for (int i = 0; i < matrix.size(); i++) {
        bool allPrime = true;
        for (int num : matrix[i]) {
            if (!isPrime(num)) {
                allPrime = false;
                break;
            }
        }
        if (allPrime) {
            rows.push_back(i);
        }
    }
    return rows;
}

// Hàm in ma trận
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << "\t";
        }
        cout << endl;
    }
}

// Hàm in danh sách các dòng
void printRows(const vector<int>& rows, const string& message) {
    cout << message;
    if (rows.empty()) {
        cout << "Không có dòng nào." << endl;
    } else {
        for (int row : rows) {
            cout << "Dòng " << row << " ";
        }
        cout << endl;
    }
}

int main() {
    // Ma trận mẫu
    vector<vector<int>> matrix = {
        {4, 6, 7, 8},
        {10, 17, 19, 22},
        {29, 31, 37, 41},
        {9, 15, 21, 25}
    };

    cout << "Ma trận ban đầu:\n";
    printMatrix(matrix);

    // (a) Số nguyên tố lớn nhất trong ma trận
    int maxPrime = findLargestPrime(matrix);
    if (maxPrime != -1) {
        cout << "Số nguyên tố lớn nhất trong ma trận: " << maxPrime << endl;
    } else {
        cout << "Không có số nguyên tố trong ma trận." << endl;
    }

    // (b) Dòng có ít nhất một số nguyên tố
    vector<int> rowsWithPrime = findRowsWithPrime(matrix);
    printRows(rowsWithPrime, "Các dòng chứa ít nhất một số nguyên tố: ");

    // (c) Dòng chỉ chứa số nguyên tố
    vector<int> rowsWithOnlyPrimes = findRowsWithOnlyPrimes(matrix);
    printRows(rowsWithOnlyPrimes, "Các dòng chỉ chứa số nguyên tố: ");

    return 0;
}

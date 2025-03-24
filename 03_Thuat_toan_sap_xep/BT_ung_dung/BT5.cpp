#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm tính tổng của một dòng
int rowSum(const vector<int>& row) {
    int sum = 0;
    for (int num : row) {
        sum += num;
    }
    return sum;
}

// (a) Tìm dòng có tổng lớn nhất
int findMaxSumRow(const vector<vector<int>>& matrix) {
    int maxSum = -1, maxRowIndex = -1;
    for (int i = 0; i < matrix.size(); i++) {
        int sum = rowSum(matrix[i]);
        if (sum > maxSum) {
            maxSum = sum;
            maxRowIndex = i;
        }
    }
    return maxRowIndex;
}

// (b) Sắp xếp các dòng theo tổng giảm dần
void sortRowsBySum(vector<vector<int>>& matrix) {
    sort(matrix.begin(), matrix.end(), [](const vector<int>& a, const vector<int>& b) {
        return rowSum(a) > rowSum(b); // Sắp xếp giảm dần theo tổng dòng
    });
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

    // (a) Tìm dòng có tổng lớn nhất
    int maxRowIndex = findMaxSumRow(matrix);
    if (maxRowIndex != -1) {
        cout << "Dòng có tổng lớn nhất: " << maxRowIndex << endl;
    }

    // (b) Sắp xếp dòng theo tổng giảm dần
    sortRowsBySum(matrix);
    cout << "Ma trận sau khi sắp xếp dòng theo tổng giảm dần:\n";
    printMatrix(matrix);

    return 0;
}

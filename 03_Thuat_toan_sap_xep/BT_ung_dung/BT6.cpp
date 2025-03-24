#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm sắp xếp theo yêu cầu
void sortArray(vector<int>& arr) {
    vector<int> evens, odds;
    vector<int> zeroPositions;

    // Bước 1: Phân loại số chẵn, số lẻ, vị trí số 0
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == 0) {
            zeroPositions.push_back(i);
        } else if (arr[i] % 2 == 0) {
            evens.push_back(arr[i]);
        } else {
            odds.push_back(arr[i]);
        }
    }

    // Bước 2: Sắp xếp số chẵn tăng dần, số lẻ giảm dần
    sort(evens.begin(), evens.end());          // Sắp xếp chẵn tăng dần
    sort(odds.rbegin(), odds.rend());          // Sắp xếp lẻ giảm dần

    // Bước 3: Lắp các số đã sắp xếp vào mảng, giữ nguyên số 0
    int evenIndex = 0, oddIndex = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (find(zeroPositions.begin(), zeroPositions.end(), i) != zeroPositions.end()) {
            continue;  // Giữ nguyên số 0
        } else if (!evens.empty() && arr[i] % 2 == 0) {
            arr[i] = evens[evenIndex++];
        } else {
            arr[i] = odds[oddIndex++];
        }
    }
}

// Hàm hiển thị mảng
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {3, 0, 2, 5, 4, 0, 7, 8, 0, 6, 1};

    cout << "Mảng ban đầu: ";
    printArray(arr);

    // Sắp xếp theo yêu cầu
    sortArray(arr);

    cout << "Mảng sau khi sắp xếp: ";
    printArray(arr);

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

// Hàm sắp xếp chẵn lên đầu, lẻ xuống cuối (O(n))
void sortEvenOdd(vector<int>& arr) {
    int left = 0; // Vị trí chèn số chẵn

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % 2 == 0) { // Nếu là số chẵn
            swap(arr[left], arr[i]);
            left++; // Tăng vị trí đặt số chẵn
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
    vector<int> arr = {3, 8, 5, 2, 4, 7, 6, 9, 10, 1};

    cout << "Mảng ban đầu: ";
    printArray(arr);

    // Sắp xếp theo yêu cầu
    sortEvenOdd(arr);

    cout << "Mảng sau khi sắp xếp (chẵn đầu, lẻ cuối): ";
    printArray(arr);

    return 0;
}

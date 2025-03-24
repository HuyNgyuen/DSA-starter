#include <iostream>
#include <vector>
using namespace std;

// Hàm in mảng
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// 1. Sắp xếp đổi chỗ trực tiếp (Interchange Sort)
void interchangeSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

// 2. Sắp xếp chọn trực tiếp (Selection Sort)
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// 3. Sắp xếp chèn trực tiếp (Insertion Sort)
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// 4. Sắp xếp nổi bọt (Bubble Sort)
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    vector<int> arr = {39, 8, 5, 1, 3, 6, 9, 12, 4, 7, 10};
    vector<int> temp;
    
    cout << "Dãy số ban đầu: ";
    printArray(arr);

    temp = arr;
    interchangeSort(temp);
    cout << "Sau khi sắp xếp đổi chỗ trực tiếp: ";
    printArray(temp);

    temp = arr;
    selectionSort(temp);
    cout << "Sau khi sắp xếp chọn trực tiếp: ";
    printArray(temp);

    temp = arr;
    insertionSort(temp);
    cout << "Sau khi sắp xếp chèn trực tiếp: ";
    printArray(temp);

    temp = arr;
    bubbleSort(temp);
    cout << "Sau khi sắp xếp nổi bọt: ";
    printArray(temp);
    
    return 0;
}

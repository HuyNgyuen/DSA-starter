#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;

// Hàm đọc dữ liệu từ file
vector<int> readFromFile(const string &filename) {
    ifstream file(filename);
    vector<int> arr;
    int num;
    
    while (file >> num) {
        arr.push_back(num);
    }

    file.close();
    return arr;
}

// Hàm ghi dữ liệu vào file
void writeToFile(const string &filename, const vector<int> &arr, double timeTaken) {
    ofstream file(filename);
    
    file << "Thời gian thực hiện: " << timeTaken << " ms\n";
    file << "Dãy số đã sắp xếp:\n";

    for (int num : arr) {
        file << num << " ";
    }

    file.close();
}

// 1️ Interchange Sort (Sắp xếp đổi chỗ trực tiếp)
void interchangeSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

// 2️ Selection Sort (Sắp xếp chọn trực tiếp)
void selectionSort(vector<int> &arr) {
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

// 3️ Insertion Sort (Sắp xếp chèn trực tiếp)
void insertionSort(vector<int> &arr) {
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

// 4️ Bubble Sort (Sắp xếp nổi bọt)
void bubbleSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// 5️ Quick Sort
void quickSort(vector<int> &arr, int left, int right) {
    if (left >= right) return;
    
    int pivot = arr[right];
    int i = left;
    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[right]);

    quickSort(arr, left, i - 1);
    quickSort(arr, i + 1, right);
}

// 6️ Merge Sort
void merge(vector<int> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);
    
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        arr[k++] = (L[i] < R[j]) ? L[i++] : R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int> &arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

// 7️ Heap Sort
void heapify(vector<int> &arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;
    
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Hàm đo thời gian thực hiện
void measureSortTime(void (*sortFunction)(vector<int>&), vector<int> arr, const string &filename) {
    clock_t start = clock();
    sortFunction(arr);
    clock_t end = clock();
    double timeTaken = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    writeToFile(filename, arr, timeTaken);
}

int main() {
    vector<int> arr = readFromFile("input.txt");
    
    measureSortTime(interchangeSort, arr, "interchange_sort.txt");
    measureSortTime(selectionSort, arr, "selection_sort.txt");
    measureSortTime(insertionSort, arr, "insertion_sort.txt");
    measureSortTime(bubbleSort, arr, "bubble_sort.txt");
    measureSortTime(heapSort, arr, "heap_sort.txt");

    return 0;
}

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

// Biến đếm số lần so sánh và đổi chỗ
long long quickComparisons = 0, quickSwaps = 0;
long long mergeComparisons = 0;
long long heapComparisons = 0, heapSwaps = 0;

// Hàm sinh mảng ngẫu nhiên
vector<int> generateRandomArray(int n) {
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;  // Số ngẫu nhiên từ 0 đến 9999
    }
    return arr;
}

// Hàm hoán đổi
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// **1. Quick Sort**
int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high]; 
    int i = low - 1;
    for (int j = low; j < high; j++) {
        quickComparisons++;
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
            quickSwaps++;
        }
    }
    swap(arr[i + 1], arr[high]);
    quickSwaps++;
    return i + 1;
}

void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// **2. Merge Sort**
void merge(vector<int> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        mergeComparisons++;
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int> &arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// **3. Heap Sort**
void heapify(vector<int> &arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    heapComparisons++;
    if (left < n && arr[left] > arr[largest]) largest = left;
    heapComparisons++;
    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapSwaps++;
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapSwaps++;
        heapify(arr, i, 0);
    }
}

// **Hàm đo thời gian chạy thuật toán**
template <typename Func>
double measureTime(Func sortingFunction, vector<int> &arr) {
    auto start = high_resolution_clock::now();
    sortingFunction(arr);
    auto stop = high_resolution_clock::now();
    return duration<double, milli>(stop - start).count();
}

// **Chương trình chính**
int main() {
    srand(time(0)); 

    vector<int> sizes = {10, 100, 200, 500, 1000, 5000, 10000};

    cout << "n\tQuickSort (ms)\tQuickSort Comparisons\tQuickSort Swaps\t"
         << "MergeSort (ms)\tMergeSort Comparisons\t"
         << "HeapSort (ms)\tHeapSort Comparisons\tHeapSort Swaps\n";

    for (int n : sizes) {
        vector<int> arr = generateRandomArray(n);

        // Quick Sort
        quickComparisons = 0, quickSwaps = 0;
        vector<int> quickArr = arr;
        double quickTime = measureTime([&](vector<int> &a) { quickSort(a, 0, a.size() - 1); }, quickArr);

        // Merge Sort
        mergeComparisons = 0;
        vector<int> mergeArr = arr;
        double mergeTime = measureTime([&](vector<int> &a) { mergeSort(a, 0, a.size() - 1); }, mergeArr);

        // Heap Sort
        heapComparisons = 0, heapSwaps = 0;
        vector<int> heapArr = arr;
        double heapTime = measureTime([&](vector<int> &a) { heapSort(a); }, heapArr);

        // Xuất kết quả
        cout << n << "\t"
             << quickTime << "\t" << quickComparisons << "\t" << quickSwaps << "\t"
             << mergeTime << "\t" << mergeComparisons << "\t"
             << heapTime << "\t" << heapComparisons << "\t" << heapSwaps << "\n";
    }

    return 0;
}

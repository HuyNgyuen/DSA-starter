#include <iostream>
using namespace std;
// 1. Sắp xếp chèn (Insertion Sort)
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key) { // Sắp xếp giảm dần
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

//2. Sắp xếp chọn (Selection Sort)
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIdx]) // Tìm phần tử lớn nhất
                maxIdx = j;
        }
        swap(arr[i], arr[maxIdx]);
    }
}

//3. Sắp xếp nổi bọt (Bubble Sort)
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) { // Hoán đổi nếu chưa đúng thứ tự
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; // Nếu không có swap nào, kết thúc sớm
    }
}

//4. Sắp xếp nhanh (Quick Sort)
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] > pivot) { // Sắp xếp giảm dần
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

//5. Sắp xếp trộn (Merge Sort)
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1]; // Cấp phát động
    int* R = new int[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    delete[] L; // Giải phóng bộ nhớ
    delete[] R;
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

//6. Sắp xếp vun đống (Heap Sort)
void heapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest]) smallest = left;
    if (right < n && arr[right] < arr[smallest]) smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i); // Tạo Min-Heap

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]); // Đưa phần tử nhỏ nhất ra cuối
        heapify(arr, i, 0);   // Gọi heapify để điều chỉnh Min-Heap
    }
}

// Hàm kiểm tra
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    // Chạy các thuật toán cần chạy
    insertionSort(arr, n); 
    printArray(arr, n);

    selectionSort(arr, n);
    printArray(arr, n);

    bubbleSort(arr, 0);
    printArray(arr, n);

    quickSort(arr, 0, n - 1);
    printArray(arr, n);
    
    mergeSort(arr, 0, n - 1);
    printArray(arr, n);
    
    heapSort(arr, n);
    printArray(arr, n);

    return 0;
}

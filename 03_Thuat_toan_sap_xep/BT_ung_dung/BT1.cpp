#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Hàm tính tổng các chữ số của một số
int sumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

// Hàm kiểm tra số nguyên tố
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// (a) Tìm vị trí của k phần tử lớn nhất
vector<int> findTopKElements(const vector<int>& arr, int k) {
    vector<pair<int, int>> indexedArr;
    for (int i = 0; i < arr.size(); i++) {
        indexedArr.push_back({arr[i], i});
    }
    
    sort(indexedArr.rbegin(), indexedArr.rend()); // Sắp xếp giảm dần
    vector<int> positions;
    for (int i = 0; i < k && i < indexedArr.size(); i++) {
        positions.push_back(indexedArr[i].second);
    }
    
    return positions;
}

// (b) Sắp xếp tăng dần theo tổng các chữ số
void sortByDigitSum(vector<int>& arr) {
    sort(arr.begin(), arr.end(), [](int a, int b) {
        int sumA = sumOfDigits(a);
        int sumB = sumOfDigits(b);
        return sumA < sumB || (sumA == sumB && a < b);
    });
}

// (c) Xóa tất cả số nguyên tố
void removePrimes(vector<int>& arr) {
    arr.erase(remove_if(arr.begin(), arr.end(), [](int num) {
        return isPrime(num);
    }), arr.end());
}

// Hàm hiển thị mảng
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {29, 18, 12, 47, 56, 23, 34, 89, 77, 45};
    int k = 3;

    // (a) Tìm vị trí k phần tử lớn nhất
    vector<int> topKPositions = findTopKElements(arr, k);
    cout << "Vị trí của " << k << " phần tử lớn nhất: ";
    for (int pos : topKPositions) {
        cout << pos << " ";
    }
    cout << endl;

    // (b) Sắp xếp theo tổng chữ số
    vector<int> sortedArr = arr;
    sortByDigitSum(sortedArr);
    cout << "Sắp xếp theo tổng chữ số: ";
    printArray(sortedArr);

    // (c) Xóa số nguyên tố
    vector<int> filteredArr = arr;
    removePrimes(filteredArr);
    cout << "Dãy sau khi xóa số nguyên tố: ";
    printArray(filteredArr);

    return 0;
}

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

void generateRandomNumbers(const string &filename, int n) {
    ofstream file(filename);
    srand(time(0));

    for (int i = 0; i < n; i++) {
        file << rand() % 100000 << " "; // Số ngẫu nhiên từ 0 đến 99999
    }

    file.close();
}

int main() {
    generateRandomNumbers("input.txt", 30000);
    cout << "Đã tạo file input.txt chứa 30.000 số nguyên ngẫu nhiên." << endl;
    return 0;
}

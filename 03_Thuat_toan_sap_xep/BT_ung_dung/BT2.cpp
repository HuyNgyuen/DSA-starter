#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// (a) Định nghĩa cấu trúc dữ liệu
struct Term {
    double coefficient;  // Hệ số (số thực)
    int exponent;        // Bậc (số nguyên từ 0 đến 100)
};

// Hàm hiển thị danh sách số hạng
void printPolynomial(const vector<Term>& poly) {
    for (const auto& term : poly) {
        cout << term.coefficient << "x^" << term.exponent << "      ";
    }
    cout << endl;
}

// (b) Sắp xếp theo bậc tăng dần
void sortPolynomial(vector<Term>& poly) {
    sort(poly.begin(), poly.end(), [](const Term& a, const Term& b) {
        return a.exponent < b.exponent;
    });
}

int main() {
    // Khởi tạo dãy thức bậc n
    vector<Term> polynomial = {
        {3.5, 2}, {1.2, 5}, {4.0, 3}, {2.1, 0}, {5.6, 1}
    };

    cout << "Dãy thức trước khi sắp xếp:\n";
    printPolynomial(polynomial);

    // Sắp xếp theo bậc tăng dần
    sortPolynomial(polynomial);

    cout << "Dãy thức sau khi sắp xếp theo bậc tăng dần:\n";
    printPolynomial(polynomial);

    return 0;
}

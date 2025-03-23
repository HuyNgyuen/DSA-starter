#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100

struct MatHang {
    char MSMH[11];
    char TenMH[21];
    int SoLuong;
    int DonGia;
};

void NhapMatHang(MatHang &mh) {
    cout << "Nhap ma so mat hang: ";
    cin.ignore();
    cin.getline(mh.MSMH, 11);
    cout << "Nhap ten mat hang: ";
    cin.getline(mh.TenMH, 21);
    cout << "Nhap so luong: ";
    cin >> mh.SoLuong;
    cout << "Nhap don gia: ";
    cin >> mh.DonGia;
}

void NhapDanhSach(MatHang ds[], int &n) {
    cout << "Nhap so luong mat hang: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Nhap mat hang thu " << i + 1 << ":\n";
        NhapMatHang(ds[i]);
    }
}

void XuatMatHang(const MatHang &mh) {
    cout << "MSMH: " << mh.MSMH << endl;
    cout << "Ten mat hang: " << mh.TenMH << endl;
    cout << "So luong: " << mh.SoLuong << endl;
    cout << "Don gia: " << mh.DonGia << endl;
}

int TimMatHangTheoTen(MatHang ds[], int n, const char *tenMH, MatHang &ketQua) {
    for (int i = 0; i < n; i++) {
        if (strcmp(ds[i].TenMH, tenMH) == 0) {
            ketQua = ds[i];
            return 1; // Tìm thấy
        }
    }
    return 0; // Không tìm thấy
}

int TinhTongSoLuong(MatHang ds[], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += ds[i].SoLuong;
    }
    return tong;
}

int main() {
    MatHang ds[MAX];
    int n;

    // Nhập danh sách mặt hàng
    NhapDanhSach(ds, n);

    // Tìm mặt hàng theo tên
    char tenTimKiem[21];
    cout << "Nhap ten mat hang muon tim: ";
    cin.ignore();
    cin.getline(tenTimKiem, 21);

    MatHang ketQua;
    if (TimMatHangTheoTen(ds, n, tenTimKiem, ketQua)) {
        cout << "Mat hang tim duoc:\n";
        XuatMatHang(ketQua);
    } else {
        cout << "Khong co mat hang dang tim.\n";
    }

    // Tính tổng số lượng mặt hàng
    int tongSoLuong = TinhTongSoLuong(ds, n);
    cout << "Tong so luong mat hang: " << tongSoLuong << endl;

    return 0;
}

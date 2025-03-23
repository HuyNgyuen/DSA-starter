#include <iostream>
#include <cstring>
using namespace std;

struct LoaiHoa {
    char Ten[51];       // Tên loại hoa
    int SoLuong;        // Số lượng hiện có
    char DVT[11];       // Đơn vị tính
    float DonGia;       // Đơn giá
};

struct DanhSachLoaiHoa {
    LoaiHoa dsHoa[20];  // Mảng tối đa 20 loại hoa
    int SoLuong;        // Số lượng loại hoa hiện có
};

void NhapLoaiHoa(LoaiHoa &hoa) {
    cout << "Nhap ten loai hoa (toi da 50 ky tu): ";
    cin.ignore();
    cin.getline(hoa.Ten, 51);
    do {
        cout << "Nhap so luong (>= 0): ";
        cin >> hoa.SoLuong;
    } while (hoa.SoLuong < 0);
    cout << "Nhap don vi tinh (toi da 10 ky tu): ";
    cin.ignore();
    cin.getline(hoa.DVT, 11);
    do {
        cout << "Nhap don gia (>= 0): ";
        cin >> hoa.DonGia;
    } while (hoa.DonGia < 0);
}

void NhapDanhSach(DanhSachLoaiHoa &ds) {
    do {
        cout << "Nhap so luong loai hoa (toi da 20): ";
        cin >> ds.SoLuong;
    } while (ds.SoLuong <= 0 || ds.SoLuong > 20);
    for (int i = 0; i < ds.SoLuong; i++) {
        cout << "Nhap thong tin loai hoa thu " << i + 1 << ":\n";
        NhapLoaiHoa(ds.dsHoa[i]);
    }
}

void XuatLoaiHoa(LoaiHoa hoa) {
    cout << "Ten: " << hoa.Ten << ", So luong: " << hoa.SoLuong 
         << ", Don vi tinh: " << hoa.DVT << ", Don gia: " << hoa.DonGia << "\n";
}

void XuatDanhSach(DanhSachLoaiHoa ds) {
    cout << "Danh sach cac loai hoa:\n";
    for (int i = 0; i < ds.SoLuong; i++) {
        cout << "Loai hoa thu " << i + 1 << ":\n";
        XuatLoaiHoa(ds.dsHoa[i]);
    }
}

int TimLoaiHoa(DanhSachLoaiHoa ds, char *tenloai) {
    for (int i = 0; i < ds.SoLuong; i++) {
        if (strcmp(ds.dsHoa[i].Ten, tenloai) == 0)
            return i;
    }
    return -1;
}

void XuLyBanHoa(DanhSachLoaiHoa &ds, char *tenloai, int soluong) {
    int viTri = TimLoaiHoa(ds, tenloai);
    if (viTri == -1) {
        cout << "Khong tim thay loai hoa \"" << tenloai << "\" trong danh sach.\n";
        return;
    }

    LoaiHoa &hoa = ds.dsHoa[viTri];
    if (hoa.SoLuong >= soluong) {
        float tongTien = soluong * hoa.DonGia;
        hoa.SoLuong -= soluong;
        cout << "Ban thanh cong " << soluong << " " << hoa.DVT 
             << " hoa \"" << hoa.Ten << "\". Tong tien: " << tongTien << "\n";
    } else {
        cout << "Khong du so luong hoa \"" << hoa.Ten << "\" trong kho. "
             << "So luong hien co: " << hoa.SoLuong << "\n";
    }
}

int main() {
    DanhSachLoaiHoa ds;
    NhapDanhSach(ds);
    XuatDanhSach(ds);

    char tenHoa[51];
    int soLuongMua;

    cout << "\nNhap ten loai hoa can mua: ";
    cin.ignore();
    cin.getline(tenHoa, 51);
    cout << "Nhap so luong can mua: ";
    cin >> soLuongMua;

    XuLyBanHoa(ds, tenHoa, soLuongMua);
    cout << "\nDanh sach sau khi ban:\n";
    XuatDanhSach(ds);

    return 0;
}

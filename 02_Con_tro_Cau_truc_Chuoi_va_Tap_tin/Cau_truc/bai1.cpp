#include <iostream>
#include <cstring>
using namespace std;

struct NhanVien {
    char MaSo[11];
    char Ho[11];
    char Ten[51];
    int Phai;        // 0 = Nữ, 1 = Nam
    int ThamNien;    // Số năm làm việc ≥ 0
};

struct PhongBan {
    NhanVien aNhanVien[100];
    int SoLuong; // Số lượng nhân viên hiện có
};

void NhapNhanVien(NhanVien &nv) {
    cout << "Nhap Ma So (toi da 10 ky tu): ";
    cin >> nv.MaSo;
    cout << "Nhap Ho (toi da 10 ky tu): ";
    cin >> nv.Ho;
    cout << "Nhap Ten (toi da 50 ky tu): ";
    cin.ignore();
    cin.getline(nv.Ten, 51);
    do {
        cout << "Nhap Phai (0 = Nu, 1 = Nam): ";
        cin >> nv.Phai;
    } while (nv.Phai != 0 && nv.Phai != 1);
    do {
        cout << "Nhap Tham Nien (>= 0): ";
        cin >> nv.ThamNien;
    } while (nv.ThamNien < 0);
}

void NhapPhongBan(PhongBan &pb) {
    do {
        cout << "Nhap so luong nhan vien: ";
        cin >> pb.SoLuong;
    } while (pb.SoLuong <= 0 || pb.SoLuong > 100);
    for (int i = 0; i < pb.SoLuong; i++) {
        cout << "Nhap thong tin nhan vien thu " << i + 1 << ":\n";
        NhapNhanVien(pb.aNhanVien[i]);
    }
}

void XuatNhanVien(NhanVien nv) {
    cout << "Ma So: " << nv.MaSo << ", Ho: " << nv.Ho
         << ", Ten: " << nv.Ten << ", Phai: " << (nv.Phai == 1 ? "Nam" : "Nu")
         << ", Tham Nien: " << nv.ThamNien << " nam\n";
}

void XuatPhongBan(PhongBan pb) {
    cout << "Danh sach nhan vien trong phong ban:\n";
    for (int i = 0; i < pb.SoLuong; i++) {
        cout << "Nhan vien thu " << i + 1 << ":\n";
        XuatNhanVien(pb.aNhanVien[i]);
    }
}

void DemSiSo(PhongBan pb, int &soNam, int &soNu) {
    soNam = soNu = 0;
    for (int i = 0; i < pb.SoLuong; i++) {
        if (pb.aNhanVien[i].Phai == 1)
            soNam++;
        else
            soNu++;
    }
}

void SapXepTangTheoThamNien(PhongBan &pb) {
    for (int i = 0; i < pb.SoLuong - 1; i++) {
        for (int j = i + 1; j < pb.SoLuong; j++) {
            if (pb.aNhanVien[i].ThamNien > pb.aNhanVien[j].ThamNien) {
                NhanVien temp = pb.aNhanVien[i];
                pb.aNhanVien[i] = pb.aNhanVien[j];
                pb.aNhanVien[j] = temp;
            }
        }
    }
}

int main() {
    PhongBan pb;
    int soNam, soNu;

    NhapPhongBan(pb);
    XuatPhongBan(pb);

    DemSiSo(pb, soNam, soNu);
    cout << "Si so nam: " << soNam << ", si so nu: " << soNu << "\n";

    SapXepTangTheoThamNien(pb);
    cout << "Danh sach nhan vien tang dan theo tham nien:\n";
    XuatPhongBan(pb);

    return 0;
}

#include <iostream>
#include <cstring>
using namespace std;

struct DienThoai {
    char MaDT[11];     // Mã điện thoại
    char NhanHieu[21]; // Nhãn hiệu
    int Gia;           // Giá
};

struct DanhSachDienThoai {
    DienThoai ds[100]; // Mảng chứa danh sách điện thoại
    int SoLuong;       // Số lượng điện thoại hiện có
};

void ThemDienThoai(DanhSachDienThoai &ds, DienThoai dt) {
    if (ds.SoLuong >= 100) {
        cout << "Danh sach da day. Khong the them dien thoai.\n";
        return;
    }
    for (int i = 0; i < ds.SoLuong; i++) {
        if (strcmp(ds.ds[i].MaDT, dt.MaDT) == 0) {
            cout << "Dien thoai da ton tai trong danh sach.\n";
            return;
        }
    }
    ds.ds[ds.SoLuong++] = dt;
    cout << "Them dien thoai thanh cong.\n";
}

int TimDienThoai(DanhSachDienThoai ds, char *maDT) {
    for (int i = 0; i < ds.SoLuong; i++) {
        if (strcmp(ds.ds[i].MaDT, maDT) == 0)
            return i;
    }
    return -1;
}

void InThongTinDienThoai(DanhSachDienThoai ds, char *maDT) {
    int index = TimDienThoai(ds, maDT);
    if (index == -1) {
        cout << "Khong tim thay dien thoai voi ma \"" << maDT << "\".\n";
    } else {
        DienThoai dt = ds.ds[index];
        cout << "Nhan hieu: " << dt.NhanHieu << ", Gia: " << dt.Gia << "\n";
    }
}

void CapNhatGia(DanhSachDienThoai &ds, char *maDT, int giaMoi) {
    int index = TimDienThoai(ds, maDT);
    if (index == -1) {
        cout << "Khong tim thay dien thoai voi ma \"" << maDT << "\".\n";
    } else {
        ds.ds[index].Gia = giaMoi;
        cout << "Cap nhat gia thanh cong.\n";
    }
}

void XoaDienThoai(DanhSachDienThoai &ds, char *maDT) {
    int index = TimDienThoai(ds, maDT);
    if (index == -1) {
        cout << "Khong tim thay dien thoai voi ma \"" << maDT << "\".\n";
    } else {
        for (int i = index; i < ds.SoLuong - 1; i++) {
            ds.ds[i] = ds.ds[i + 1];
        }
        ds.SoLuong--;
        cout << "Xoa dien thoai thanh cong.\n";
    }
}

void XuatDanhSach(DanhSachDienThoai ds) {
    if (ds.SoLuong == 0) {
        cout << "Danh sach dien thoai rong.\n";
        return;
    }
    for (int i = 0; i < ds.SoLuong; i++) {
        DienThoai dt = ds.ds[i];
        cout << "Ma: " << dt.MaDT << ", Nhan hieu: " << dt.NhanHieu << ", Gia: " << dt.Gia << "\n";
    }
}

void Menu() {
    DanhSachDienThoai ds = { {}, 0 };
    int choice;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Them dien thoai\n";
        cout << "2. In thong tin dien thoai theo ma\n";
        cout << "3. Cap nhat gia dien thoai\n";
        cout << "4. Xoa dien thoai\n";
        cout << "5. Xuat danh sach dien thoai\n";
        cout << "0. Thoat\n";
        cout << "Lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                DienThoai dt;
                cout << "Nhap ma dien thoai (toi da 10 ky tu): ";
                cin.ignore();
                cin.getline(dt.MaDT, 11);
                cout << "Nhap nhan hieu (toi da 20 ky tu): ";
                cin.getline(dt.NhanHieu, 21);
                cout << "Nhap gia: ";
                cin >> dt.Gia;
                ThemDienThoai(ds, dt);
                break;
            }
            case 2: {
                char maDT[11];
                cout << "Nhap ma dien thoai: ";
                cin.ignore();
                cin.getline(maDT, 11);
                InThongTinDienThoai(ds, maDT);
                break;
            }
            case 3: {
                char maDT[11];
                int giaMoi;
                cout << "Nhap ma dien thoai: ";
                cin.ignore();
                cin.getline(maDT, 11);
                cout << "Nhap gia moi: ";
                cin >> giaMoi;
                CapNhatGia(ds, maDT, giaMoi);
                break;
            }
            case 4: {
                char maDT[11];
                cout << "Nhap ma dien thoai: ";
                cin.ignore();
                cin.getline(maDT, 11);
                XoaDienThoai(ds, maDT);
                break;
            }
            case 5: {
                XuatDanhSach(ds);
                break;
            }
            case 0:
                cout << "Thoat chuong trinh.\n";
                break;
            default:
                cout << "Lua chon khong hop le.\n";
        }
    } while (choice != 0);
}

int main() {
    Menu();
    return 0;
}

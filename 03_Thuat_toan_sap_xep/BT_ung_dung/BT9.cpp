#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct SinhVien {
    int maSo;
    string hoVaDem;
    string ten;
    int ngaySinh, thangSinh, namSinh;
    string phai;
    float diemTB;
};

// Hàm nhập danh sách sinh viên
void nhapDanhSach(vector<SinhVien>& danhSach) {
    int n;
    cout << "Nhập số lượng sinh viên (tối thiểu 10): ";
    cin >> n;
    cin.ignore();
    danhSach.resize(n);

    ofstream file("SINHVIEN.DAT", ios::binary | ios::trunc);
    if (!file) {
        cout << "Không thể mở file để ghi!\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        cout << "Nhập thông tin sinh viên " << i + 1 << ":\n";
        cout << "Mã số: "; cin >> danhSach[i].maSo;
        cin.ignore();
        cout << "Họ và đệm: "; getline(cin, danhSach[i].hoVaDem);
        cout << "Tên: "; getline(cin, danhSach[i].ten);
        cout << "Ngày sinh: "; cin >> danhSach[i].ngaySinh;
        cout << "Tháng sinh: "; cin >> danhSach[i].thangSinh;
        cout << "Năm sinh: "; cin >> danhSach[i].namSinh;
        cin.ignore();
        cout << "Phái (Nam/Nữ): "; getline(cin, danhSach[i].phai);
        cout << "Điểm trung bình: "; cin >> danhSach[i].diemTB;
        cin.ignore();

        file.write(reinterpret_cast<char*>(&danhSach[i]), sizeof(SinhVien));
    }

    file.close();
    cout << "Lưu danh sách sinh viên vào SINHVIEN.DAT thành công!\n";
}

// Hàm đọc danh sách sinh viên từ file
void docDanhSach(vector<SinhVien>& danhSach) {
    ifstream file("SINHVIEN.DAT", ios::binary);
    if (!file) {
        cout << "Không thể mở file!\n";
        return;
    }

    danhSach.clear();
    SinhVien sv;
    while (file.read(reinterpret_cast<char*>(&sv), sizeof(SinhVien))) {
        danhSach.push_back(sv);
    }

    file.close();
}

// Hàm hiển thị danh sách sinh viên
void hienThiDanhSach(const vector<SinhVien>& danhSach) {
    cout << "\nDanh sách sinh viên:\n";
    for (const auto& sv : danhSach) {
        cout << sv.maSo << " | " << sv.hoVaDem << " " << sv.ten
             << " | " << sv.ngaySinh << "/" << sv.thangSinh << "/" << sv.namSinh
             << " | " << sv.phai << " | Điểm TB: " << sv.diemTB << endl;
    }
}

// Hàm tạo tập tin chỉ mục
void taoChiMuc(const vector<SinhVien>& danhSach, const string& tenFile, 
               bool (*cmp)(const SinhVien&, const SinhVien&)) {
    vector<int> chiMuc(danhSach.size());
    for (size_t i = 0; i < danhSach.size(); i++) chiMuc[i] = i;

    sort(chiMuc.begin(), chiMuc.end(), [&](int a, int b) {
        return cmp(danhSach[a], danhSach[b]);
    });

    ofstream file(tenFile, ios::binary);
    for (int index : chiMuc) {
        file.write(reinterpret_cast<char*>(&index), sizeof(int));
    }
    file.close();
}

// Các hàm so sánh
bool cmpMaSo(const SinhVien& a, const SinhVien& b) {
    return a.maSo < b.maSo;
}

bool cmpTen(const SinhVien& a, const SinhVien& b) {
    if (a.ten != b.ten) return a.ten < b.ten;
    return a.hoVaDem < b.hoVaDem;
}

bool cmpDiemTB(const SinhVien& a, const SinhVien& b) {
    return a.diemTB > b.diemTB;
}

// Hàm đọc danh sách theo chỉ mục
void docTheoChiMuc(const vector<SinhVien>& danhSach, const string& tenFile) {
    ifstream file(tenFile, ios::binary);
    if (!file) {
        cout << "Không thể mở file chỉ mục!\n";
        return;
    }

    vector<SinhVien> dsSapXep;
    int index;
    while (file.read(reinterpret_cast<char*>(&index), sizeof(int))) {
        dsSapXep.push_back(danhSach[index]);
    }
    file.close();

    hienThiDanhSach(dsSapXep);
}

int main() {
    vector<SinhVien> danhSach;
    nhapDanhSach(danhSach);
    
    // Đọc lại danh sách từ file để đảm bảo dữ liệu nhất quán
    danhSach.clear();
    docDanhSach(danhSach);

    // Sắp xếp danh sách theo mã số và hiển thị
    sort(danhSach.begin(), danhSach.end(), cmpMaSo);
    cout << "\nDanh sách sau khi sắp xếp theo Mã số:\n";
    hienThiDanhSach(danhSach);

    // Tạo các tập tin chỉ mục
    taoChiMuc(danhSach, "SVMASO.IDX", cmpMaSo);
    taoChiMuc(danhSach, "SVTH.IDX", cmpTen);
    taoChiMuc(danhSach, "SVDTB.IDX", cmpDiemTB);

    // Đọc danh sách theo từng chỉ mục
    cout << "\nDanh sách theo Mã số tăng dần:\n";
    docTheoChiMuc(danhSach, "SVMASO.IDX");

    cout << "\nDanh sách theo Tên (A → Z):\n";
    docTheoChiMuc(danhSach, "SVTH.IDX");

    cout << "\nDanh sách theo Điểm trung bình giảm dần:\n";
    docTheoChiMuc(danhSach, "SVDTB.IDX");

    return 0;
}

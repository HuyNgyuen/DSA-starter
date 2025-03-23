# 02. Cấu trúc
- Sinh viên: Nguyễn Đỗ Huy
- Mã số sinh viên: 3121411085
- Giảng viên: Đỗ Như Tài
- Môn học: Cấu trúc dữ liệu và giải thuật

---

# Bài tập 1: Quản lý nhân viên
## Bài toán yêu cầu
Một phòng ban có tối đa 100 nhân viên, mỗi nhân viên (NhanVien) gồm các thông tin sau:
- **MaSo**: chuỗi tối đa 10 ký tự.
- **Ho**: chuỗi tối đa 10 ký tự.
- **Ten**: chuỗi tối đa 50 ký tự.
- **Phai**: số nguyên (0 = Nữ, 1 = Nam).
- **ThamNien**: số nguyên dương ≥ 0.

Phòng ban (PhongBan) bao gồm:
- **aNhanVien**: mảng tối đa 100 nhân viên.
- **SoLuong**: số lượng nhân viên hiện có.

Chương trình cần thực hiện các chức năng:
- Nhập danh sách nhân viên với dữ liệu hợp lệ.
- Xuất danh sách nhân viên.
- Đếm sĩ số nhân viên nam và nữ.
- Sắp xếp danh sách nhân viên tăng dần theo thâm niên.

---
## Input
- Số lượng nhân viên trong phòng ban (≤ 100).
- Thông tin từng nhân viên: mã số, họ, tên, giới tính, thâm niên.

## Output
- Danh sách nhân viên trong phòng ban.
- Số lượng nhân viên nam và nữ.
- Danh sách nhân viên sau khi được sắp xếp theo thâm niên.

---
## Chức năng
### 1. Nhập danh sách nhân viên (**NhapPhongBan**)
- Nhập số lượng nhân viên, kiểm tra không vượt quá 100.
- Nhập thông tin từng nhân viên đảm bảo đúng định dạng.

### 2. Xuất danh sách nhân viên (**XuatPhongBan**)
- Hiển thị danh sách nhân viên trên màn hình.

### 3. Đếm sĩ số nhân viên (**DemSiSo**)
- Đếm và hiển thị số lượng nhân viên nam và nữ.

### 4. Sắp xếp danh sách nhân viên theo thâm niên (**SapXepTangTheoThamNien**)
- Sử dụng thuật toán sắp xếp (Bubble Sort hoặc Selection Sort) để sắp xếp theo thâm niên.

### 5. Chương trình chính (**main**)
- Gọi các hàm trên để thực hiện các yêu cầu bài toán.

---
## Ý tưởng
- Sử dụng **struct** để tổ chức dữ liệu nhân viên và phòng ban.
- Dùng **mảng một chiều** để lưu danh sách nhân viên.
- Duyệt mảng và sử dụng thuật toán sắp xếp để sắp xếp danh sách theo thâm niên.
- Hiển thị dữ liệu theo yêu cầu bằng cách duyệt mảng và in ra màn hình.

---

# Bài Tập 2: Quản Lý Bán Hoa

## 1. Bài Toán
Một cửa hàng bán hoa có tối đa 20 loại hoa, mỗi loại hoa gồm các thông tin sau:
- **Tên loại** (Ten): Tên của loại hoa (chuỗi, tối đa 50 ký tự).
- **Số lượng** (SoLuong): Số lượng hoa hiện có (số nguyên ≥ 0).
- **Đơn vị tính** (DVT): Chuỗi tối đa 10 ký tự (ví dụ: "bó", "cành").
- **Đơn giá** (DonGia): Giá bán của một đơn vị hoa (số thực ≥ 0).

Với tên loại và số lượng hoa mà khách hàng yêu cầu, chương trình sẽ kiểm tra:
- Loại hoa có tồn tại trong danh sách không.
- Nếu có, số lượng có đủ để bán không.
- Nếu đủ, tính tổng tiền khách hàng cần trả.

## 2. Yêu Cầu
Viết chương trình thực hiện các chức năng sau:
1. **Khai báo cấu trúc** `LoaiHoa` và `DanhSachLoaiHoa`.
2. **Hàm nhập danh sách các loại hoa.**
   ```cpp
   void NhapDanhSach(DanhSachLoaiHoa &ds);
   ```
3. **Hàm xuất danh sách loại hoa ra màn hình.**
   ```cpp
   void XuatDanhSach(DanhSachLoaiHoa ds);
   ```
4. **Hàm tìm loại hoa theo tên.**
   ```cpp
   int TimLoaiHoa(DanhSachLoaiHoa ds, char *tenloai);
   ```
   - Trả về vị trí của loại hoa trong danh sách nếu tìm thấy.
   - Trả về `-1` nếu không tìm thấy.
5. **Hàm xử lý bán hoa.**
   ```cpp
   void XuLyBanHoa(DanhSachLoaiHoa &ds, char *tenloai, int soluong);
   ```
   - Kiểm tra hoa có tồn tại không.
   - Nếu có:
     - Kiểm tra số lượng có đủ không.
     - Nếu đủ, tính tổng tiền và cập nhật lại số lượng hoa còn lại.
     - Nếu không đủ, thông báo số lượng không đủ.
   - Nếu không có, thông báo không tìm thấy hoa.
6. **Hàm `main` thực hiện các chức năng trên.**
   ```cpp
   int main();
   ```

## 3. Input / Output
### Input
- Số lượng loại hoa trong danh sách (tối đa 20).
- Thông tin từng loại hoa (Tên loại, Số lượng, Đơn vị tính, Đơn giá).
- Tên loại hoa khách hàng muốn mua.
- Số lượng hoa khách hàng yêu cầu.

### Output
- Danh sách loại hoa trong cửa hàng.
- Thông báo kết quả tìm kiếm hoa:
  - **Nếu tìm thấy:**
    - Nếu đủ số lượng: Tổng tiền khách hàng cần trả.
    - Nếu không đủ: Thông báo số lượng không đủ.
  - **Nếu không tìm thấy:** Thông báo loại hoa không có trong danh sách.

## 4. Chức Năng Chính
### 1. Nhập danh sách các loại hoa (`NhapDanhSach`)
- Nhập số lượng loại hoa (tối đa 20).
- Nhập thông tin từng loại hoa với ràng buộc dữ liệu hợp lệ.

### 2. Xuất danh sách hoa (`XuatDanhSach`)
- Hiển thị danh sách hoa hiện có trong cửa hàng.

### 3. Tìm kiếm hoa theo tên (`TimLoaiHoa`)
- Duyệt danh sách để kiểm tra hoa có tồn tại không.
- Trả về vị trí nếu tìm thấy, ngược lại trả về `-1`.

### 4. Xử lý bán hoa (`XuLyBanHoa`)
- Kiểm tra hoa có trong danh sách không.
- Nếu có:
  - Kiểm tra số lượng có đủ không.
  - Nếu đủ:
    - Tính tổng tiền: `Tổng tiền = Số lượng * Đơn giá`.
    - Cập nhật số lượng hoa còn lại.
    - Hiển thị tổng tiền.
  - Nếu không đủ: Thông báo số lượng không đủ.
- Nếu không có: Thông báo không tìm thấy loại hoa.

### 5. Chương trình chính (`main`)
- Gọi các hàm trên để xử lý theo yêu cầu đề bài.

## 5. Ý Tưởng Triển Khai
- Sử dụng **mảng một chiều** để lưu danh sách loại hoa.
- Duyệt danh sách bằng **con trỏ** để tìm kiếm hoa theo tên.
- Xử lý nhập, xuất và bán hoa theo các hàm riêng biệt.
- Kiểm tra điều kiện hợp lệ khi nhập và xử lý dữ liệu.
- Cập nhật dữ liệu sau khi bán hàng.

---

# Bài Tập 3: Quản Lý điện thoại
## 1. Bài Toán
Quản lý danh sách tối đa 100 điện thoại, mỗi điện thoại bao gồm các thông tin:
- Mã điện thoại (tối đa 10 ký tự).
- Nhãn hiệu (tối đa 20 ký tự).
- Giá (số nguyên).

## 2. Yêu Cầu
Viết chương trình có các chức năng sau:
1. **Thêm điện thoại**:
   - Thêm điện thoại vào danh sách.
   - Kiểm tra danh sách đã đầy hoặc điện thoại đã tồn tại.
   - Báo lỗi nếu danh sách đã đầy hoặc điện thoại đã có.
2. **Tìm điện thoại theo mã**:
   - Nhập mã điện thoại.
   - In nhãn hiệu và giá của điện thoại đó.
   - Báo lỗi nếu không tìm thấy.
3. **Cập nhật giá điện thoại**:
   - Nhập mã điện thoại và giá mới.
   - Cập nhật giá mới nếu tìm thấy.
   - Báo lỗi nếu không tìm thấy.
4. **Xóa điện thoại theo mã**:
   - Nhập mã điện thoại.
   - Xóa điện thoại nếu tìm thấy.
   - Báo lỗi nếu không tìm thấy.
5. **Xuất danh sách điện thoại**:
   - Hiển thị danh sách tất cả điện thoại.
6. **Menu tương tác**:
   - Cho phép người dùng chọn chức năng mong muốn.

## 3. Input / Output
- **Input**: Nhập từ bàn phím danh sách điện thoại, mã điện thoại, giá cập nhật...
- **Output**: Hiển thị danh sách, thông báo thành công hoặc lỗi khi thực hiện các thao tác.

## 4. Ý tưởng Triển Khai
### Cấu trúc dữ liệu
#### 1. Struct `DienThoai`
Chứa thông tin về điện thoại:
```c
struct DienThoai {
    char MaDT[10];
    char NhanHieu[20];
    int Gia;
};
```
#### 2. Struct `DanhSachDienThoai`
Chứa danh sách các điện thoại:
```c
struct DanhSachDienThoai {
    DienThoai ds[100];
    int SoLuong;
};
```

### Chức năng chính
1. **Thêm điện thoại (`ThemDienThoai`)**:
   - Kiểm tra danh sách đã đầy hay chưa.
   - Kiểm tra mã điện thoại đã tồn tại hay chưa.
   - Nếu hợp lệ, thêm vào danh sách.

2. **Tìm điện thoại (`TimDienThoai`)**:
   - Duyệt danh sách tìm theo mã điện thoại.
   - Trả về vị trí nếu tìm thấy, -1 nếu không.

3. **In thông tin điện thoại (`InThongTinDienThoai`)**:
   - Tìm kiếm điện thoại theo mã.
   - Nếu tìm thấy, hiển thị nhãn hiệu và giá.
   - Báo lỗi nếu không tìm thấy.

4. **Cập nhật giá (`CapNhatGia`)**:
   - Nhập giá mới và cập nhật.
   - Báo lỗi nếu mã điện thoại không tồn tại.

5. **Xóa điện thoại (`XoaDienThoai`)**:
   - Tìm kiếm và xóa phần tử trong danh sách.
   - Báo lỗi nếu không tìm thấy.
6. **Xuất danh sách điện thoại (`XuatDanhSach`)**:
   - Hiển thị toàn bộ danh sách điện thoại có trong hệ thống.

---

# Bài Tập 4: Quản lý danh mục mặt hàng trong cửa hàng tạp hóa
## 1. Yêu cầu
Viết chương trình quản lý danh sách mặt hàng tại một cửa hàng tạp hóa, bao gồm các chức năng:
1. Nhập danh sách n mặt hàng (n ≤ 100).
2. Tìm kiếm mặt hàng theo tên, nếu có thì in ra thông tin đầy đủ, nếu không có thì thông báo.
3. Tính tổng số lượng tất cả các mặt hàng trong danh sách.

## 2. Input - Dữ liệu đầu vào
- Số lượng mặt hàng (n) cần nhập (1 ≤ n ≤ 100).
- Danh sách mặt hàng gồm các thông tin:
   - MSMH (Mã số mặt hàng - chuỗi tối đa 10 ký tự).
   - TenMH (Tên mặt hàng - chuỗi tối đa 20 ký tự).
   - SoLuong (Số lượng mặt hàng - số nguyên dương).
   - DonGia (Đơn giá - số nguyên dương).
- Tên mặt hàng cần tìm kiếm.

## 3. Output - Dữ liệu đầu ra
- Danh sách mặt hàng sau khi nhập.
- Thông tin đầy đủ của mặt hàng cần tìm (hoặc thông báo "Không có mặt hàng đang tìm" nếu không tìm thấy).
- Tổng số lượng tất cả các mặt hàng.

## 4. Chức năng chính
1. Nhập danh sách mặt hàng (NhapDanhSach)
- Nhập MSMH, TenMH, SoLuong, DonGia cho từng mặt hàng.
- Kiểm tra dữ liệu đầu vào:
   - MSMH không được để trống.
   - SoLuong và DonGia phải lớn hơn 0.

2. Tìm kiếm mặt hàng theo tên (TimMatHang)
- Nhập TenMH cần tìm.
- Duyệt danh sách và so sánh với TenMH nhập vào.
- Nếu tìm thấy, hiển thị thông tin mặt hàng.
- Nếu không tìm thấy, thông báo: "Không có mặt hàng đang tìm".

3. Tính tổng số lượng tất cả mặt hàng (TinhTongSoLuong)
- Khởi tạo biến tongSoLuong = 0.
- Duyệt danh sách mặt hàng và cộng dồn giá trị SoLuong vào tongSoLuong.
- Xuất tổng số lượng tất cả mặt hàng.

4. Hàm main (main)
- Nhập danh sách mặt hàng.
- Nhập tên mặt hàng cần tìm và hiển thị kết quả.
- Tính tổng số lượng mặt hàng và hiển thị.

## 5. Ý tưởng triển khai
### Cấu trúc dữ liệu
#### 1. Struct `MatHang`
Chứa thông tin về điện thoại:
```c
struct MatHang {
    char MSMH[10];   // Mã số mặt hàng
    char TenMH[20];  // Tên mặt hàng
    int SoLuong;     // Số lượng
    int DonGia;      // Đơn giá
};
```
#### 2. Struct `DanhSachMatHang`
Chứa thông tin danh sáchsách:
```c
struct DanhSachMatHang {
    MatHang ds[100];  // Mảng chứa danh sách mặt hàng
    int SoLuongMH;    // Số lượng mặt hàng hiện có
};
```
- Các bước xử lý
   1. Nhập danh sách mặt hàng, kiểm tra ràng buộc dữ liệu.
   2. Tìm kiếm mặt hàng theo tên, trả về thông tin hoặc báo lỗi.
   3. Tính tổng số lượng bằng cách duyệt danh sách và cộng dồn số lượng từng mặt hàng.
   4. Hiển thị kết quả theo yêu cầu đề bài.

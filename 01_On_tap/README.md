# PHÂN TÍCH BÀI TOÁN, THIẾT KẾ GIẢI THUẬT VÀ KIỂM THỬ CHƯƠNG TRÌNH
- Sinh viên: Nguyễn Đỗ Huy
- Mã số sinh viên: 3121411085
- Giảng viên: Đỗ Như Tài
- Môn học: Cấu trúc dữ liệu và giải thuật

# Ghi chú về bài làm

## Bài 1. Giải Phương Trình Bậc 2

### 1. Phân tích bài toán
#### 1.1. Bài toán yêu cầu
- Nhận hệ số a, b, c của phương trình bậc 2.
- Giải phương trình và biện luận số nghiệm, sau đó xuất kết quả theo định dạng yêu cầu.

#### 1.2. Input
- Một dòng chứa ba số a, b, c cách nhau bởi khoảng trắng.

#### 1.3. Output
- Dòng 1: Thông báo về số nghiệm của phương trình, gồm:
  - "Phuong trinh co vo so nghiem" (nếu phương trình đúng với mọi giá trị x).
  - "Phuong trinh vo nghiem" (nếu phương trình không có nghiệm).
  - "Phuong trinh co 1 nghiem" (nếu có một nghiệm duy nhất).
  - "Phuong trinh co 2 nghiem" (nếu có hai nghiệm phân biệt).
- Dòng 2: Liệt kê các nghiệm (nếu có), theo thứ tự tăng dần, định dạng số thập phân với 2 chữ số lẻ, cách nhau bởi khoảng trắng.

#### 1.4. Chức năng
- Tính phương trình bậc 2.

## Bài 2. Giải Phương Trình Trùng Phương

### 1. Phân tích bài toán
#### 1.1. Bài toán yêu cầu
- Nhận hệ số a, b, c của phương trình trùng phương.
- Giải và biện luận số nghiệm phương trình, sau đó xuất kết quả theo định dạng yêu cầu.

#### 1.2. Input
- Một dòng chứa ba số a, b, c cách nhau bởi khoảng trắng.

#### 1.3. Output
- Dòng 1: Thông báo về số nghiệm của phương trình, gồm:
  - "Phuong trinh co vo so nghiem" (nếu phương trình đúng với mọi giá trị x).
  - "Phuong trinh vo nghiem" (nếu phương trình không có nghiệm).
  - "Phuong trinh co [xx] nghiem" (với xx = 1, 2, 3 hay 4).
- Dòng 2: Liệt kê các nghiệm (nếu có), theo thứ tự tăng dần, định dạng số thập phân với 2 chữ số lẻ, cách nhau bởi khoảng trắng.

#### 1.4. Chức năng
- Tính phương trình trùng phương.

## Bài 3. Phần tử chung

### 1. Phân tích bài toán
#### 1.1. Bài toán yêu cầu
- Nhận ba dãy số nguyên dương x, y, z lần lượt có nx, ny, nz phần tử.
- Tìm phần tử chung của ba dãy số trên, sau đó xuất kết quả theo định dạng yêu cầu.

#### 1.2. Input
- Số lượng phần tử nx, ny, nz của ba dãy số x, y, z.
- Các phần tử của ba dãy số: x, y, z.

#### 1.3. Output
- Số lượng phần tử chung.
- Danh sách các phần tử chung (theo thứ tự tăng dần, không trùng lặp).

#### 1.4. Ràng buộc
- 0 ≤ nx, ny, nz ≤ 1000: Số phần tử trong mỗi dãy tối đa là 1000.
- 0 ≤ xi, yi, zi ≤ 10000: Giá trị mỗi phần tử nằm trong [0, 10000].

#### 1.5. Chức năng
- Tìm phần tử chung của các dãy.


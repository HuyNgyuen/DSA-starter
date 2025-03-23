# 03. Xử lý chuỗi
- Sinh viên: Nguyễn Đỗ Huy
- Mã số sinh viên: 3121411085
- Giảng viên: Đỗ Như Tài
- Môn học: Cấu trúc dữ liệu và giải thuật

---

# Bài tập 1: Sắp xếp ký tự trong chuỗi theo thứ tự tăng dần
## 1. Bài toán yêu cầu
Cho một chuỗi ký tự `s` (độ dài tối đa 1.000). Hãy sắp xếp các ký tự trong chuỗi theo thứ tự tăng dần dựa trên mã ASCII và in ra kết quả.

## 2. Input
- Một chuỗi `s` có độ dài tối đa 1.000 ký tự.

## 3. Output
- Chuỗi `s` sau khi sắp xếp các ký tự theo thứ tự tăng dần.

## 4. Chức năng chính
- **Nhập chuỗi**: Nhận đầu vào từ người dùng.
- **Sắp xếp chuỗi**: Sử dụng thuật toán sắp xếp để sắp xếp các ký tự trong chuỗi theo thứ tự tăng dần.
- **Xuất kết quả**: In chuỗi đã sắp xếp ra màn hình.

## 5. Ý tưởng
- **Cấu trúc dữ liệu**:
  - Chuỗi `s` chứa các ký tự cần sắp xếp.
  - Sử dụng mảng để biểu diễn chuỗi và thao tác trên các phần tử của nó.
- **Thuật toán**:
  - Dùng thuật toán sắp xếp có sẵn như `sort()` trong thư viện `<algorithm>` của C++ để sắp xếp chuỗi.
  - Thuật toán sắp xếp này có độ phức tạp trung bình là `O(n log n)`, đảm bảo hiệu suất tốt ngay cả với chuỗi dài.

## 6. Ví dụ
### **Input**:
```
Moi ban nhap chuoi s: abcba
```
### **Output**:
```
Chuoi "abcba" sau khi sap xep: aabbc
```

---

# Bài tập 2: Xóa ký tự tại vị trí k trong chuỗi

## 1. Yêu cầu bài toán
Cho chuỗi `s` và số nguyên `k` (0 ≤ k ≤ |s| - 1). Hãy viết chương trình xóa ký tự tại vị trí `k` trong chuỗi.

## 2. Input
- Một chuỗi `s` (|s| ≤ 1000).
- Một số nguyên `k` (0 ≤ k ≤ |s| - 1).

## 3. Output
- Chuỗi sau khi xóa ký tự tại vị trí `k`.

## 4. Ví dụ
**Input:**
```
Moi ban nhap chuoi s: abcba
Moi ban nhap vi tri can xoa: 1
```
**Output:**
```
Chuoi "abcba" sau khi xoa ky tu tai vi tri 1: acba
```

## 5. Chức năng chính
- **Nhập chuỗi và vị trí cần xóa**:
  - Nhập chuỗi `s` từ bàn phím.
  - Nhập số nguyên `k` (đảm bảo nằm trong khoảng hợp lệ).
- **Xóa ký tự tại vị trí k**:
  - Duyệt qua chuỗi và tạo một chuỗi mới không chứa ký tự tại vị trí `k`.
  - Có thể sử dụng phương thức `erase` trong C++ để xóa trực tiếp.
- **Xuất kết quả**:
  - In chuỗi sau khi đã xóa ký tự.

## 6. Ý tưởng
- **Sử dụng mảng ký tự hoặc string để lưu trữ chuỗi.**
- **Kiểm tra điều kiện hợp lệ của k trước khi xử lý.**
- **Xóa ký tự bằng cách dịch các phần tử hoặc sử dụng hàm `erase`.**
- **In kết quả ra màn hình.**

---

## Bài Tập 3: Chèn Ký Tự c Vào Vị Trí k Trong Chuỗi

### 1. Yêu Cầu Bài Toán
Cho chuỗi s ( |s| ≤ 1.000 ), số nguyên k ( 0 ≤ k ≤ |s| ) và ký tự c. Viết hàm chèn ký tự c vào chuỗi s tại vị trí k.

### 2. Input
- Nhập chuỗi s.
- Nhập vị trí k cần chèn.
- Nhập ký tự c cần chèn.

### 3. Output
- Chuỗi sau khi chèn ký tự c tại vị trí k.

## 4. Ví dụ
**Input:**
```
Moi ban nhap chuoi s: abcba
Moi ban nhap vi tri can chen: 1
Moi ban nhap ky tu chen: d
```
**Output:**
```
Chuoi sau khi them ky tu "d" vao vi tri 1: adbcba
```

### 5. Chức Năng
1. Nhập chuỗi s.
2. Nhập vị trí k cần chèn.
3. Nhập ký tự c cần chèn.
4. Chèn ký tự c vào vị trí k.
5. Xuất chuỗi kết quả.

### 6. Ý Tưởng
- Sử dụng hàm `insert` của C++ để chèn trực tiếp ký tự c vào vị trí k.


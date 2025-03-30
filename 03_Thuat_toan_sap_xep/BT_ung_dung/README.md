# 02. Bài tập ứng dụng
- Sinh viên: Nguyễn Đỗ Huy
- Mã số sinh viên: 3121411085
- Giảng viên: Đỗ Như Tài
- Môn học: Cấu trúc dữ liệu và giải thuật

---

# Bài tập 1:
## 1. Yêu cầu bài toán
Cho dãy số nguyên gồm `n` phần tử: `a₀, a₁, ..., aₙ₋₁`, thực hiện các chức năng sau:

1. **Tìm vị trí của `k` phần tử có giá trị lớn nhất trong dãy.**
2. **Sắp xếp các phần tử tăng dần theo tổng chữ số của từng phần tử.**
3. **Xóa tất cả các số nguyên tố có trong dãy.**

## 2. Input
- Một mảng số nguyên `arr` gồm `n` phần tử.
- Một số nguyên `k` xác định số phần tử lớn nhất cần tìm vị trí.

Ví dụ:
```cpp
arr = {29, 18, 12, 47, 56, 23, 34, 89, 77, 45}
k = 3
```

## 3. Output
- **(a)** Vị trí (chỉ số) của `k` phần tử lớn nhất trong dãy.
- **(b)** Mảng đã được sắp xếp theo tổng chữ số.
- **(c)** Mảng sau khi đã loại bỏ toàn bộ số nguyên tố.

## 4. Chức năng chính
| Chức năng | Mô tả |
|----------|------|
| `findTopKElements` | Trả về danh sách vị trí của `k` phần tử có giá trị lớn nhất trong mảng. |
| `sortByDigitSum` | Sắp xếp mảng tăng dần theo tổng các chữ số của từng phần tử. Nếu tổng bằng nhau, sắp xếp theo giá trị gốc. |
| `removePrimes` | Xóa tất cả các phần tử là số nguyên tố trong mảng. |
| `sumOfDigits` | Tính tổng các chữ số của một số nguyên. |
| `isPrime` | Kiểm tra một số có phải là số nguyên tố hay không. |
| `printArray` | Hiển thị nội dung mảng ra terminal. |

## 5. Ý tưởng triển khai
### 🔹 (a) Tìm vị trí `k` phần tử lớn nhất
- Tạo vector các cặp `(giá trị, vị trí)`.
- Sắp xếp giảm dần theo giá trị.
- Lấy `k` phần tử đầu tiên và thu thập chỉ số.

### 🔹 (b) Sắp xếp theo tổng chữ số
- Xây dựng hàm `sumOfDigits(num)` để tính tổng chữ số.
- Dùng `sort()` với comparator so sánh tổng chữ số.
- Nếu tổng bằng nhau thì so sánh giá trị gốc để giữ thứ tự tăng.

### 🔹 (c) Xóa số nguyên tố
- Xây dựng hàm `isPrime(num)` để kiểm tra số nguyên tố.
- Dùng `remove_if` kết hợp với `erase` để lọc các phần tử nguyên tố khỏi mảng.

---

# Bài tập 2:
## 1. Yêu cầu bài toán
Thông tin về mỗi số hạng của một dãy thức bậc `n` bao gồm:
- **Hệ số** – là một số thực.
- **Bậc** – là một số nguyên có giá trị từ 0 đến 100.

### Các yêu cầu cụ thể:

1. **Định nghĩa cấu trúc dữ liệu** để lưu trữ thông tin các số hạng.
2. **Sắp xếp các số hạng** trong dãy theo thứ tự tăng dần của bậc.

## 2. Input
- Một danh sách các số hạng, mỗi số hạng gồm: hệ số (double), bậc (int từ 0 đến 100).

Ví dụ:
```cpp
{3.5, 2}, {1.2, 5}, {4.0, 3}, {2.1, 0}, {5.6, 1}
```

## 3. Output
- Danh sách số hạng trước và sau khi sắp xếp theo bậc tăng dần.

## 4. Chức năng chính
| Chức năng | Mô tả |
|----------|------|
| `struct Term` | Cấu trúc lưu trữ một số hạng với hệ số và bậc. |
| `printPolynomial` | Hiển thị các số hạng của dãy thức. |
| `sortPolynomial` | Sắp xếp danh sách số hạng theo bậc tăng dần. |

## 5. Ý tưởng triển khai
### 🔹 (a) Định nghĩa cấu trúc dữ liệu
- Sử dụng `struct Term` gồm hai thành phần: `coefficient` (hệ số) và `exponent` (bậc).
- Lưu trữ các số hạng trong `vector<Term>`.

### 🔹 (b) Sắp xếp theo bậc tăng dần
- Dùng hàm `sort()` trong thư viện `algorithm`.
- Truyền comparator để so sánh theo `exponent`.

---

# Bài tập 3:
## 1. Yêu cầu bài toán

Thông tin về mỗi phòng thi tại một hội đồng thi bao gồm:
- **Số phòng** – là số nguyên trong khoảng từ 1 → 200.
- **Nhà** – là một chữ cái in hoa từ A → Z.
- **Khả năng chứa** – là số nguyên trong khoảng từ 10 → 250.

### Các yêu cầu:
1. **Định nghĩa cấu trúc dữ liệu** để lưu trữ các phòng thi.
2. **Cài đặt và thực hiện các thuật toán sắp xếp**:
   - Giảm dần theo **Khả năng chứa**.
   - Tăng dần theo **Nhà**, cùng nhà thì tăng theo **Số phòng**.
   - Tăng dần theo **Nhà**, cùng nhà thì **giảm dần** theo **Khả năng chứa**.

## 2. Input
- Một danh sách các phòng thi, mỗi phòng có: `roomNumber`, `building`, `capacity`.

Ví dụ:
```cpp
{101, 'B', 100}, {102, 'A', 150}, {103, 'B', 90}, {201, 'A', 200},
{202, 'C', 120}, {301, 'C', 250}, {203, 'C', 180}, {204, 'A', 80}
```

## 3. Output
- Danh sách phòng thi ban đầu và sau mỗi lần sắp xếp theo tiêu chí.

## 4. Chức năng chính
| Chức năng | Mô tả |
|----------|------|
| `struct Room` | Cấu trúc lưu trữ thông tin một phòng thi. |
| `printRooms` | Hiển thị danh sách các phòng thi. |
| `sortByCapacity` | Sắp xếp theo khả năng chứa giảm dần. |
| `sortByBuildingAndRoom` | Sắp xếp theo nhà tăng dần, cùng nhà thì theo số phòng tăng. |
| `sortByBuildingAndCapacity` | Sắp xếp theo nhà tăng dần, cùng nhà thì theo sức chứa giảm. |

## 5. Ý tưởng triển khai
### 🔹 (a) Định nghĩa cấu trúc dữ liệu
- Dùng `struct Room` gồm: `roomNumber`, `building`, `capacity`.
- Dùng `vector<Room>` để lưu danh sách các phòng.

### 🔹 (b) Sắp xếp
- Dùng `sort()` từ STL với các tiêu chí so sánh khác nhau.

---

# Bài tập 4:
## 1. Yêu cầu bài toán
Cho ma trận hai chiều kích thước `m x n` với các phần tử là **số nguyên dương**.

### Các yêu cầu cụ thể:
1. **Tìm số nguyên tố lớn nhất** trong ma trận.
2. **Tìm các dòng có chứa ít nhất một số nguyên tố.**
3. **Tìm các dòng chỉ chứa toàn số nguyên tố.**

## 2. Input
- Một ma trận `m x n` gồm các số nguyên dương.

Ví dụ:
```cpp
matrix = {
    {4, 6, 7, 8},
    {10, 17, 19, 22},
    {29, 31, 37, 41},
    {9, 15, 21, 25}
}
```

## 3. Output
- Số nguyên tố lớn nhất trong ma trận (nếu có).
- Danh sách các dòng chứa ít nhất một số nguyên tố.
- Danh sách các dòng chỉ chứa toàn số nguyên tố.

## 4. Chức năng chính
| Chức năng | Mô tả |
|----------|------|
| `isPrime` | Kiểm tra một số có phải là số nguyên tố hay không. |
| `findLargestPrime` | Tìm số nguyên tố lớn nhất trong ma trận. |
| `findRowsWithPrime` | Tìm các dòng có ít nhất một số nguyên tố. |
| `findRowsWithOnlyPrimes` | Tìm các dòng chỉ chứa toàn bộ là số nguyên tố. |
| `printMatrix` | Hiển thị nội dung ma trận. |
| `printRows` | In danh sách chỉ số các dòng thỏa yêu cầu. |

## 5. Ý tưởng triển khai
### 🔹 (a) Tìm số nguyên tố lớn nhất
- Duyệt qua toàn bộ các phần tử.
- Nếu là số nguyên tố và lớn hơn giá trị lớn nhất hiện tại → cập nhật.

### 🔹 (b) Dòng có chứa số nguyên tố
- Duyệt từng dòng.
- Nếu dòng đó có **ít nhất một** số nguyên tố thì lưu chỉ số dòng.

### 🔹 (c) Dòng chỉ chứa số nguyên tố
- Duyệt từng dòng.
- Nếu **toàn bộ** phần tử trong dòng là số nguyên tố thì lưu chỉ số dòng.

---

# Bài tập 5:
## 1. Yêu cầu bài toán
Cho ma trận hai chiều kích thước `m x n` với các phần tử là **số nguyên dương**.

### Các yêu cầu:
1. **Tìm dòng có tổng lớn nhất.**
2. **Sắp xếp các dòng theo tổng giảm dần**, dòng có tổng lớn hơn sẽ nằm phía trên.

## 2. Input
- Một ma trận `m x n` gồm các số nguyên dương.

Ví dụ:
```cpp
matrix = {
    {4, 6, 7, 8},
    {10, 17, 19, 22},
    {29, 31, 37, 41},
    {9, 15, 21, 25}
}
```

## 3. Output
- Vị trí dòng có tổng lớn nhất.
- Ma trận sau khi sắp xếp các dòng theo tổng giảm dần.

## 4. Chức năng chính
| Chức năng | Mô tả |
|----------|------|
| `rowSum` | Tính tổng các phần tử trong một dòng. |
| `findMaxSumRow` | Tìm chỉ số dòng có tổng lớn nhất. |
| `sortRowsBySum` | Sắp xếp các dòng theo tổng giảm dần. |
| `printMatrix` | Hiển thị nội dung ma trận ra màn hình. |

## 5. Ý tưởng triển khai
### 🔹 (a) Tìm dòng có tổng lớn nhất
- Duyệt từng dòng trong ma trận.
- Tính tổng các phần tử của dòng.
- Nếu lớn hơn tổng lớn nhất hiện tại → cập nhật.

### 🔹 (b) Sắp xếp dòng theo tổng giảm dần
- Dùng `sort()` trong STL với comparator so sánh tổng từng dòng.
- Sắp xếp giảm dần để dòng có tổng lớn hơn nằm phía trên.

---

# Bài tập 6:
## 1. Yêu cầu bài toán
Cho mảng một chiều gồm `n` phần tử là **các số nguyên không âm**.

### Các yêu cầu:
- **Sắp xếp các số chẵn** theo **thứ tự tăng dần**.
- **Sắp xếp các số lẻ** theo **thứ tự giảm dần**.
- **Các số 0 giữ nguyên vị trí ban đầu**.

## 2. Input
- Một mảng các số nguyên không âm.

Ví dụ:
```cpp
arr = {3, 0, 2, 5, 4, 0, 7, 8, 0, 6, 1}
```

## 3. Output
- Mảng sau khi đã được sắp xếp theo yêu cầu:
  - Số chẵn tăng dần.
  - Số lẻ giảm dần.
  - Số 0 giữ nguyên vị trí.

## 4. Chức năng chính
| Chức năng | Mô tả |
|----------|------|
| `sortArray` | Thực hiện sắp xếp mảng theo yêu cầu. |
| `printArray` | Hiển thị nội dung mảng ra màn hình. |

## 5. Ý tưởng triển khai
### 🔹 Bước 1: Phân loại
- Duyệt qua mảng, phân chia:
  - Số **chẵn** → lưu vào `evens`.
  - Số **lẻ** → lưu vào `odds`.
  - Vị trí **số 0** → lưu vào `zeroPositions`.

### 🔹 Bước 2: Sắp xếp
- `evens` sắp xếp **tăng dần**.
- `odds` sắp xếp **giảm dần**.

### 🔹 Bước 3: Xây dựng lại mảng
- Duyệt lại mảng ban đầu.
- Giữ nguyên vị trí các số 0.
- Thay các số chẵn và lẻ đã sắp xếp vào vị trí tương ứng.

---

# Bài tập 7:
## 1. Yêu cầu bài toán
Cho mảng một chiều gồm `n` phần tử là **các số nguyên dương**.

### Yêu cầu:
- **Đưa các số chẵn lên đầu mảng**, các số **lẻ về cuối mảng**.
- Đảm bảo độ phức tạp **O(n)**.

## 2. Input
- Một mảng số nguyên dương.

Ví dụ:
```cpp
arr = {3, 8, 5, 2, 4, 7, 6, 9, 10, 1}
```

## 3. Output
- Mảng sau khi sắp xếp sao cho:
  - Các phần tử **chẵn nằm ở đầu**.
  - Các phần tử **lẻ nằm ở cuối**.

## 4. Chức năng chính
| Chức năng | Mô tả |
|----------|------|
| `sortEvenOdd` | Sắp xếp chẵn ở đầu, lẻ ở cuối trong O(n) bằng hoán đổi tại chỗ. |
| `printArray` | In ra nội dung mảng. |

## 5. Ý tưởng triển khai
### 🔹 Cách tiếp cận tuyến tính (O(n))
- Sử dụng **một biến `left`** để chỉ vị trí cần đặt số chẵn.
- Duyệt qua mảng một lần:
  - Nếu phần tử là **số chẵn**, hoán đổi với phần tử tại vị trí `left`, rồi tăng `left`.
  - Nếu là **số lẻ**, giữ nguyên vị trí.

### 🔹 Đặc điểm
- **Không dùng sort()**, không cần mảng phụ.
- Chạy **duy nhất một vòng lặp** → O(n).

---

# Bài tập 8:
## 1. Yêu cầu bài toán
Cho hoán vị `A = (a₁, a₂, ..., aₙ)` của `N` số tự nhiên đầu tiên.

Định nghĩa **mảng nghịch thế** `B = (b₁, b₂, ..., bₙ)` như sau:
- `bᵢ` là số lượng phần tử đứng **trước số i** và **lớn hơn i** trong hoán vị A.

### Ví dụ:
Nếu `A = (5, 9, 1, 8, 2, 6, 4, 7, 3)` → `B = (2, 3, 6, 4, 0, 2, 2, 1, 0)`

### Yêu cầu:
1. Viết hàm tìm **mảng nghịch thế B** từ **hoán vị A**.
2. Viết hàm tìm **hoán vị A** từ **mảng nghịch thế B** (nếu tồn tại).

## 2. Input
- Một hoán vị A hoặc một mảng nghịch thế B.

Ví dụ:
```cpp
A = {5, 9, 1, 8, 2, 6, 4, 7, 3}
```

## 3. Output
- Mảng nghịch thế `B` tương ứng với `A`.
- Hoán vị `A` được xây dựng lại từ `B` nếu tồn tại.

## 4. Chức năng chính
| Chức năng | Mô tả |
|----------|------|
| `findInversionArray` | Tính mảng nghịch thế từ hoán vị A. |
| `findPermutationFromInversionArray` | Tính hoán vị A từ mảng nghịch thế B (nếu có). |
| `printArray` | In mảng ra màn hình. |

## 5. Ý tưởng triển khai
### 🔹 (a) Tìm mảng nghịch thế từ A
- Duyệt từng `i`, so sánh với các phần tử đứng trước.
- Đếm số lượng phần tử `A[j] > A[i]` với `j < i`.
- Lưu vào `B[A[i] - 1]` (do A là hoán vị từ 1 đến N).

### 🔹 (b) Tìm hoán vị từ mảng nghịch thế
- Sử dụng `set` chứa tập `{1..N}`.
- Duyệt từ phải qua trái.
- Với mỗi `B[i]`, chọn phần tử thứ `B[i]` trong `set` để gán vào `A[i]`.
- Xóa phần tử đã chọn khỏi `set`.

### 🔹 Độ phức tạp
- (a) `O(n²)` – có thể tối ưu `O(n log n)` với Fenwick Tree.
- (b) `O(n log n)` – nhờ thao tác `set` và `advance` iterator.

---

# Bài tập 9:
## 1. Yêu cầu bài toán
Quản lý thông tin sinh viên gồm các trường:
- **Mã số**: số nguyên dương.
- **Họ và đệm**: chuỗi tối đa 20 ký tự.
- **Tên**: chuỗi tối đa 40 ký tự.
- **Ngày sinh / Tháng sinh / Năm sinh**: số nguyên dương.
- **Phái**: "Nam" hoặc "Nữ".
- **Điểm trung bình**: số thực từ 0.00 đến 10.00.

### Yêu cầu:
1. Nhập danh sách sinh viên (≥10), không trùng mã, lưu vào file `SINHVIEN.DAT`.
2. Sắp xếp danh sách tăng dần theo **Mã số**, in ra màn hình.
3. Tạo các **tập tin chỉ mục** sắp xếp theo:
   - Mã số (tăng dần) → `SVMASO.IDX`
   - Tên (A → Z), cùng tên thì theo Họ và đệm (A → Z) → `SVTH.IDX`
   - Điểm trung bình (giảm dần) → `SVDTB.IDX`
4. Dùng các tập tin chỉ mục để đọc dữ liệu trong `SINHVIEN.DAT` và in ra màn hình theo thứ tự tương ứng.
5. Nhận xét về việc sắp xếp dữ liệu thông qua chỉ mục.

## 2. Input
- Danh sách sinh viên nhập từ bàn phím.

## 3. Output
- Danh sách sinh viên được hiển thị theo từng cách sắp xếp:
  - Theo **Mã số**
  - Theo **Tên → Họ đệm**
  - Theo **Điểm trung bình giảm dần**

## 4. Chức năng chính
| Chức năng | Mô tả |
|----------|------|
| `nhapDanhSach` | Nhập và lưu danh sách sinh viên vào file `SINHVIEN.DAT`. |
| `docDanhSach` | Đọc danh sách sinh viên từ file. |
| `hienThiDanhSach` | Hiển thị danh sách sinh viên ra màn hình. |
| `taoChiMuc` | Tạo tập tin chỉ mục theo tiêu chí nhất định. |
| `docTheoChiMuc` | Đọc danh sách sinh viên theo chỉ mục đã tạo. |
| `cmpMaSo`, `cmpTen`, `cmpDiemTB` | Hàm so sánh dùng để sắp xếp. |

## 5. Ý tưởng triển khai
### 🔹 Quản lý và nhập dữ liệu
- Nhập từ bàn phím và kiểm tra không trùng mã số.
- Ghi toàn bộ danh sách vào file nhị phân `SINHVIEN.DAT`.

### 🔹 Tạo và sử dụng chỉ mục
- Tạo mảng chỉ mục `int index[]` tương ứng với từng sinh viên.
- Sắp xếp chỉ mục theo tiêu chí, **không sắp xếp dữ liệu gốc**.
- Dùng chỉ mục để đọc lại sinh viên từ file theo thứ tự đã sắp.

### 🔹 Ưu điểm của chỉ mục
- **Tiết kiệm chi phí ghi đè file dữ liệu.**
- Dễ dàng sắp xếp và lọc dữ liệu theo nhiều tiêu chí khác nhau.

---

## 🛠 Cài đặt

Toàn bộ chương trình được viết bằng C++, thích hợp chạy trên mọi trình biên dịch hỗ trợ chuẩn C++11 trở lên.
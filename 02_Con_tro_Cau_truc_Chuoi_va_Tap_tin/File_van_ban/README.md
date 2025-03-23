# 04. File văn bản
- Sinh viên: Nguyễn Đỗ Huy
- Mã số sinh viên: 3121411085
- Giảng viên: Đỗ Như Tài
- Môn học: Cấu trúc dữ liệu và giải thuật

---

# Bài tập 1: Chương trình Đọc các số nguyên từ file văn bản

## 1. Bài toán yêu cầu
Viết chương trình đọc dữ liệu từ file văn bản chứa danh sách số nguyên và xuất kết quả ra màn hình.

## 2. Input
Dữ liệu được đọc từ file `DaySoNguyen.inp`, gồm:
- Dòng thứ nhất: Chứa một số nguyên `n` (số phần tử của danh sách).
- Dòng thứ hai: Chứa `n` số nguyên, mỗi số cách nhau ít nhất một khoảng trắng.

Ví dụ nội dung file `DaySoNguyen.inp`:
```
5
4 3 5 3 2
```

## 3. Output
Chương trình sẽ xuất danh sách số nguyên đã đọc từ file ra màn hình.

Ví dụ đầu ra:
```
Danh sách số nguyên đọc được:
4 3 5 3 2
```

## 4. Chức năng chính
- **Đọc file (`DocDaySoNguyen`)**
  - Mở file `DaySoNguyen.inp` để đọc dữ liệu.
  - Đọc số nguyên đầu tiên `n` (số phần tử của danh sách).
  - Đọc tiếp `n` số nguyên và lưu vào mảng.
  - Đóng file sau khi đọc xong.
- **Xuất danh sách số nguyên (`XuatDaySoNguyen`)**
  - In danh sách số nguyên vừa đọc ra màn hình.
- **Hàm `main`**
  - Khai báo biến và mảng lưu trữ số nguyên.
  - Gọi hàm `DocDaySoNguyen` để đọc dữ liệu từ file.
  - Nếu đọc thành công, gọi `XuatDaySoNguyen` để hiển thị kết quả.

## 5. Ý tưởng
- **Bước 1:** Mở file `DaySoNguyen.inp` ở chế độ đọc.
- **Bước 2:** Đọc số lượng phần tử `n`.
- **Bước 3:** Đọc `n` số nguyên từ file và lưu vào mảng.
- **Bước 4:** Hiển thị danh sách số nguyên ra màn hình.
- **Bước 5:** Đóng file sau khi hoàn thành.

---

# Bài tập 2: Đọc mảng 2 chiều

## 1. Yêu cầu bài tóan
Viết chương trình đọc file chứa mảng 2 chiều các số nguyên. Xuất kết quả đọc được ra màn hình.

## 2. Input
- Dữ liệu vào được lưu trủ trong file `MangSo.inp`, gồm:
  - Dòng đầu tiên: Hai số nguyên `n` và `m` là số dòng và số cột của mảng.
  - `n` dòng tiếp theo: Mỗi dòng chứa `m` số nguyên, các số cách nhau ít nhất một khoảng trắng.

### Ví dụ file `MangSo.inp`:
```
3 5
5 3 5 7 2
4 5 5 7 1
5 4 5 3 9
```

## 3. Output
- Xuất mảng hai chiều vừa đọc được ra màn hình theo dạng bảng.

### Ví dụ output:
```
5  3  5  7  2
4  5  5  7  1
5  4  5  3  9
```

## 4. Chức năng chính
1. **Đọc file**
   - Mở file `MangSo.inp` với chế độ đọc.
   - Đọc hai số nguyên `n` và `m` từ dòng đầu.
   - Khai báo một mảng hai chiều để lưu các giá trị.
   - Duyệt qua `n` dòng, đọc `m` số nguyên trong từng dòng và lưu vào mảng.
   - Đóng file sau khi đọc xong.

2. **Xuất dữ liệu**
   - Duyệt qua mảng hai chiều.
   - In ra màn hình dưới dạng bảng các số nguyên.

## 5. Ý tưởng
- Mở file để đọc dữ liệu.
- Đọc số dòng và số cột của mảng.
- Đọc dữ liệu và lưu vào mảng hai chiều.
- Xuất kết quả ra màn hình dưới dạng bảng.

---

# Bài tập 3: Tìm số nguyên tố
## 1. Bài toán yêu cầu
Viết chương trình đọc một dãy số nguyên từ file, tìm các số nguyên tố trong dãy, sắp xếp theo thứ tự tăng dần và ghi kết quả vào file.

## 2. Input
- File `NT.INP` gồm:
  - Dòng đầu tiên chứa số nguyên `n` (1 < n ≤ 10.000) là số phần tử của dãy số.
  - `n` dòng tiếp theo, mỗi dòng chứa một số nguyên `a_i`.

Ví dụ nội dung file `NT.INP`:
```
5
10
3
7
4
11
```

## 3. Output
- File `NT.OUT` chứa:
  - Dòng đầu tiên ghi số lượng số nguyên tố `m` tìm được.
  - Dòng thứ hai ghi `m` số nguyên tố theo thứ tự tăng dần, cách nhau ít nhất một khoảng trắng.

Ví dụ nội dung file `NT.OUT`:
```
3
3 7 11
```

## 4. Chức năng chính
- Đọc dữ liệu từ file `NT.INP`.
- Kiểm tra từng số trong dãy có phải là số nguyên tố không.
- Lưu các số nguyên tố vào danh sách và sắp xếp theo thứ tự tăng dần.
- Ghi kết quả vào file `NT.OUT`.

## 5. Ý tưởng
### Đọc dữ liệu từ file
- Mở file `NT.INP` để đọc dữ liệu.
- Đọc số nguyên `n` từ dòng đầu tiên.
- Đọc `n` số nguyên còn lại và lưu vào danh sách.

### Kiểm tra số nguyên tố
- Một số nguyên tố là số tự nhiên lớn hơn 1, chỉ chia hết cho 1 và chính nó.
- Sử dụng thuật toán kiểm tra số nguyên tố:
  - Nếu số nhỏ hơn 2 thì không phải số nguyên tố.
  - Kiểm tra chia hết từ 2 đến \(\sqrt{x}\).

### Xử lý và ghi kết quả
- Lọc danh sách chỉ giữ lại số nguyên tố.
- Sắp xếp danh sách theo thứ tự tăng dần.
- Ghi số lượng số nguyên tố vào dòng đầu file `NT.OUT`.
- Ghi danh sách số nguyên tố vào dòng thứ hai.

---

# Bài tập 4: Tìm cặp số
## 1. Yêu cầu bài toán
Cho dãy n số nguyên \( a_0, a_1, ..., a_{n-1} \) và số nguyên k. Hãy tìm các cặp \( (a_i, a_j) \) sao cho \( a_i + a_j = k \) với \( 0 \leq i < j \leq n-1 \).

## 2. Dữ liệu vào
Dữ liệu được đọc từ tệp **CapSo.INP**, gồm:
- Dòng đầu tiên: Chứa hai số nguyên **n** (số lượng phần tử trong dãy) và **k** (tổng cần tìm).
- **n** dòng tiếp theo: Mỗi dòng chứa một số nguyên **a[i]**.

### Ví dụ tệp **CapSo.INP**:
```
5 8
1
3
5
2
6
```

## 3. Kết quả
Kết quả được ghi vào tệp **CapSo.OUT**:
- Nếu không tìm được cặp số nào thì ghi **số 0**.
- Ngược lại, ghi danh sách các cặp số tìm được, mỗi cặp trên một dòng.

### Ví dụ tệp **CapSo.OUT**:
```
1 7
2 6
```

## 4. Chức năng chính
- **Đọc dữ liệu**:
  - Mở tệp **CapSo.INP** và đọc số **n** và **k**.
  - Đọc **n** số nguyên từ tệp và lưu vào một mảng.
- **Tìm cặp số thoả mãn**:
  - Duyệt qua tất cả các cặp \( (a_i, a_j) \) sao cho \( i < j \).
  - Kiểm tra xem \( a_i + a_j = k \).
  - Nếu đúng, lưu cặp số vào danh sách kết quả.
- **Ghi kết quả**:
  - Nếu danh sách kết quả rỗng, ghi **0** vào tệp **CapSo.OUT**.
  - Ngược lại, ghi danh sách các cặp số vào tệp, mỗi cặp trên một dòng.

## 5. Ý tưởng
- Sử dụng **vòng lặp lồng nhau** để duyệt qua tất cả các cặp \( (a_i, a_j) \) với \( i < j \) và kiểm tra tổng.
- Tối ưu bằng **tậu bản đồng**:
  - Sử dụng **unordered_set** để lưu các phần tử đã duyệt.
  - Mỗi lần duyệt, kiểm tra xem \( k - a[i] \) đã tồn tại trong tập hợp hay chưa.
  - Cách này giúp giảm độ phức tạp từ **O(n^2)** xuống **O(n)**.


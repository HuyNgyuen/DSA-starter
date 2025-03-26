# 01. Bài tập cơ sở
- Sinh viên: Nguyễn Đỗ Huy
- Mã số sinh viên: 3121411085
- Giảng viên: Đỗ Như Tài
- Môn học: Cấu trúc dữ liệu và giải thuật

---

# Bài tập 1: 
## 1. Yêu cầu
Cho dãy **n** số nguyên:  
**39, 8, 5, 1, 3, 6, 9, 12, 4, 7, 10**

Thực hiện các yêu cầu sau:
1. Mô phỏng các bước sắp xếp tăng dần bằng các giải thuật:
   - Sắp xếp đổi chỗ trực tiếp
   - Sắp xếp chọn trực tiếp
   - Sắp xếp chèn trực tiếp
   - Sắp xếp nổi bót
2. Cài đặt hoàn chỉnh các giải thuật trên.
3. Chứng minh độ phức tạp của các giải thuật đã triển khai.

## 2. Input
- Một danh sách các số nguyên (**39, 8, 5, 1, 3, 6, 9, 12, 4, 7, 10**).

## 3. Output
- Danh sách số sau khi sắp xếp bằng từng giải thuật.
- Các bước trung gian của mỗi giải thuật.
- Độ phức tạp của từng giải thuật.

## 4. Chức năng của chương trình
- Nhận danh sách số nguyên làm dữ liệu đầu vào.
- Thực hiện các phương pháp sắp xếp theo thứ tự:
  1. **Sắp xếp đổi chỗ trực tiếp** (Interchange Sort).
  2. **Sắp xếp chọn trực tiếp** (Selection Sort).
  3. **Sắp xếp chèn trực tiếp** (Insertion Sort).
  4. **Sắp xếp nổi bót** (Bubble Sort).
- Hiển thị kết quả và các bước trung gian trong quá trình sắp xếp.
- Phân tích và chứng minh độ phức tạp của từng giải thuật.

## 5. Ý tưởng
Chương trình triển khai các thuật toán sắp xếp truyền thống nhằm so sánh độ hiệu quả. Mỗi giải thuật sẽ được cài đặt và đưa ra kết quả tương ứng, giúp người dùng nhận thấy sự khác biệt giữa các cách sắp xếp.

Chương trình có thể sử dụng ngôn ngữ **C++** để cài đặt các giải thuật. Mỗi giải thuật sẝ được chạy với danh sách ban đầu, và hiển thị kết quả sau khi sắp xếp.

Ngoài ra, độ phức tạp thời gian tối đa (**O(n^2)** hoặc **O(n)**) sẽ được phân tích để so sánh độ hiệu quả giữa các giải thuật.

---

# Bài tập 2:
## 1. Yêu cầu
1. **Mô phỏng các bước sắp xếp** dãy số bằng ba thuật toán:
   - Quick Sort
   - Merge Sort
   - Heap Sort
2. **Cài đặt hoàn chỉnh các thuật toán** trên.
3. **Chứng minh độ phức tạp** của các thuật toán đã triển khai.

## 2. Dữ liệu đầu vào
Dãy số nguyên cần sắp xếp:
```
[8, 5, 1, 3, 6, 9, 12, 4, 7, 10]
```

## 3. Kết quả mong đợi
Sau khi thực thi, dãy số sẽ được sắp xếp theo thứ tự tăng dần:
```
[1, 3, 4, 5, 6, 7, 8, 9, 10, 12]
```

## 4. Giải thuật sử dụng
### Quick Sort
- Chọn một phần tử làm pivot.
- Phân chia dãy số thành hai phần: nhỏ hơn pivot và lớn hơn pivot.
- Đệ quy sắp xếp hai phần này.
- **Độ phức tạp**: Trung bình `O(n log n)`, xấu nhất `O(n^2)`.

### Merge Sort
- Chia dãy số thành hai nửa bằng nhau.
- Sắp xếp từng nửa bằng đệ quy.
- Trộn hai nửa đã sắp xếp lại với nhau.
- **Độ phức tạp**: Luôn là `O(n log n)`.

### Heap Sort
- Xây dựng cây max-heap từ dãy số.
- Trích xuất phần tử lớn nhất và sắp xếp lại heap.
- Lặp lại đến khi dãy số được sắp xếp.
- **Độ phức tạp**: `O(n log n)`.

---
# Bài tập 3:
## 1. Bài toán yêu cầu
Viết chương trình sử dụng hàm `random` trong C để tạo một dãy số nguyên gồm `n` phần tử. Thực hiện sắp xếp dãy số theo thứ tự tăng dần bằng các thuật toán sắp xếp:
- **Quick Sort**
- **Merge Sort**
- **Heap Sort**

Chương trình sẽ đo lường số lần so sánh, số lần đổi chỗ và thời gian thực thi của từng thuật toán. Thực nghiệm với các kích thước mảng `n = 10, 100, 200, ..., 10000` và thực hiện nhiều lần để đánh giá hiệu suất.

## 2. Input và Output
### **Input:**
- Số phần tử của mảng `n`.
- Các phần tử của mảng được sinh ngẫu nhiên từ 0 đến 9999.

### **Output:**
- Thời gian thực thi (ms) của từng thuật toán.
- Số lần so sánh và đổi chỗ (swap) của từng thuật toán.
- Nhận xét hiệu suất của các thuật toán dựa trên kết quả thực nghiệm.

## 3. Chức năng chính
- **Sinh mảng ngẫu nhiên** (`generateRandomArray`).
- **Cài đặt các thuật toán sắp xếp:**
  - Quick Sort
  - Merge Sort
  - Heap Sort
- **Đếm số lần so sánh và đổi chỗ**:
  - `quickComparisons`, `quickSwaps` cho Quick Sort.
  - `mergeComparisons` cho Merge Sort.
  - `heapComparisons`, `heapSwaps` cho Heap Sort.
- **Đo thời gian thực thi** (`measureTime`) bằng `chrono`.
- **Thực nghiệm với nhiều kích thước mảng khác nhau** (`n = 10, 100, ..., 10000`).
- **Xuất kết quả dưới dạng bảng so sánh.**

## 4. Ý tưởng
- Sinh mảng số nguyên ngẫu nhiên với giá trị từ 0 đến 9999.
- Triển khai các thuật toán sắp xếp.
- Sử dụng biến đếm để theo dõi số lần so sánh và đổi chỗ.
- Đo thời gian chạy thuật toán bằng `chrono`.
- Lặp lại quá trình với các giá trị `n` khác nhau để đánh giá hiệu suất.

## 5. Nhận xét về các thuật toán sắp xếp
### **Quick Sort**
- **Thời gian trung bình nhanh nhất trong các thuật toán được so sánh.**
- Khi `n < 500`, thời gian chạy gần như bằng 0 ms.
- Khi `n = 1000`, thời gian tăng lên (~1.5 ms).
- Khi `n = 10000`, số lần so sánh lên đến 159300 nhưng thời gian chỉ khoảng 0.5 ms, cho thấy hiệu suất tốt.
- **Nhược điểm:** Số lần hoán đổi cao, ảnh hưởng đến bộ nhớ cache.
- **Độ phức tạp:**
  - Trung bình: `O(n log n)`.
  - Trường hợp xấu nhất: `O(n²)` (khi chọn pivot không tốt).

### **Merge Sort**
- **Số lần so sánh thấp hơn Quick Sort**, đặc biệt khi `n ≥ 5000`.
- Khi `n = 10000`, số lần so sánh là 120440 (thấp hơn Quick Sort).
- **Nhược điểm:** Thời gian chạy lâu hơn (5.7 ms so với 0.5 ms của Quick Sort) do sử dụng bộ nhớ phụ `O(n)`.
- **Độ phức tạp:** `O(n log n)` trong mọi trường hợp.

### **Heap Sort**
- **Số lần so sánh nhiều nhất trong các thuật toán.**
- Khi `n = 10000`, số lần so sánh là 258346, gấp 2.15 lần Merge Sort và 1.62 lần Quick Sort.
- **Nhược điểm:** Số lần hoán đổi cao nhất (124173 swaps), ảnh hưởng hiệu suất bộ nhớ.
- **Độ phức tạp:** `O(n log n)`, không cần bộ nhớ phụ nhưng có số lần hoán đổi lớn.

## 6. Kết luận
- **Quick Sort** phù hợp cho trường hợp trung bình và tốt nhất, nhưng có thể chậm trong trường hợp xấu nhất.
- **Merge Sort** ổn định, có hiệu suất tốt nhưng tốn bộ nhớ.
- **Heap Sort** không cần bộ nhớ phụ nhưng số lần hoán đổi cao, ảnh hưởng đến hiệu suất thực tế.
- **Lựa chọn thuật toán phụ thuộc vào tình huống sử dụng cụ thể.**

---

# Bài Tập 4:
## 1. Yêu Cầu Bài Toán
Hãy đo thời gian thi hành của các thuật toán sắp xếp trên cùng một bộ dữ liệu chứa khoảng 30.000 số nguyên ngẫu nhiên và trên cùng một máy tính.

## 2. Input
- Dữ liệu vào được lưu trên file văn bản `input.txt`, gồm 30.000 số nguyên ngẫu nhiên.

## 3. Output
- Kết quả sắp xếp được lưu trên các file văn bản tương ứng với mỗi thuật toán.
- Thời gian chạy của từng thuật toán được lưu trong file kèm theo kết quả sắp xếp.

## 4. Các Thuật Toán Sắp Xếp
Bài tập yêu cầu đo thời gian của các thuật toán sau:
- **Sắp xếp đổi chỗ trực tiếp (Interchange Sort)**
- **Sắp xếp chọn trực tiếp (Selection Sort)**
- **Sắp xếp chèn trực tiếp (Insertion Sort)**
- **Sắp xếp nổi bôt (Bubble Sort)**
- **Sắp xếp nhanh (Quick Sort)**
- **Sắp xếp trộn (Merge Sort)**
- **Sắp xếp cây (Heap Sort)**

## 5. Chức Năng Của Chương Trình
- **Đọc dữ liệu** từ file `input.txt`.
- **Đo thời gian chạy** của mỗi thuật toán sắp xếp.
- **Lưu kết quả sắp xếp** và thời gian vào các file riêng lẻ.
- **So sánh hiệu suất** của các thuật toán.

## 6. Ý Tưởng
1. **Tạo file `input.txt`** chứa 30.000 số nguyên ngẫu nhiên.
2. **Cài đặt các thuật toán sắp xếp**, mỗi thuật toán sẽ được triển khai trong một hàm riêng.
3. **Đo thời gian chạy của từng thuật toán**.
4. **Lưu kết quả vào các file tương ứng**.
5. **Phân tích và so sánh hiệu suất** dựa trên thời gian chạy.

## 7. Kết Quả So Sánh
| Thuật toán      | Thời gian (ms) |
|-----------------|----------------|
| **Heap Sort**        | **10** |
| **Selection Sort**   | 1799 |
| **Insertion Sort**   | 1275 |
| **Bubble Sort**      | 4102 |
| **Interchange Sort** | 4399 |

### 8. Phân Tích Hiệu Suất
- **Heap Sort** nhanh nhất do tính chất O(n log n).
- **Selection Sort** và **Insertion Sort** chậm do tính chất O(n²).
- **Bubble Sort** và **Interchange Sort** chậm nhất do quá nhiều lần hoán đổi.


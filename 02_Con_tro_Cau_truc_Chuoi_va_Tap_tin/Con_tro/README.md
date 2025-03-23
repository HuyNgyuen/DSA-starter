# 01. Con trỏ
- Sinh viên: Nguyễn Đỗ Huy
- Mã số sinh viên: 3121411085
- Giảng viên: Đỗ Như Tài
- Môn học: Cấu trúc dữ liệu và giải thuật

---

# Con trỏ cho đối tượng và mảng một chiều

## 1. Con trỏ cho đối tượng

### Bài tập 1

#### Bài toán yêu cầu
Cho hệ số a, b, c của phương trình bậc hai. Viết chương trình giải phương trình bậc hai (dùng con trỏ).

#### Input
- Nhập hệ số a, b, c.

#### Output
- Kết quả nghiệm của phương trình bậc hai.

#### Chức năng
- Nhập các hệ số a, b, c.
- Tính delta = b^2 - 4ac để kiểm tra loại nghiệm.
- Sử dụng con trỏ để lưu và trả về các nghiệm của phương trình.

#### Ý tưởng
Chương trình giải phương trình bậc hai ax^2 + bx + c = 0 bằng cách sử dụng con trỏ:
- Nhập các hệ số a, b, c.
- Tính delta để xác định số nghiệm (2 nghiệm, 1 nghiệm kép hoặc vô nghiệm).
- Sử dụng con trỏ để lưu kết quả và xuất ra màn hình.

---

## 2. Con trỏ cho mảng một chiều

### Bài tập 2

#### Bài toán yêu cầu
Cho dãy số nguyên a có n phần tử (n ≤ 100). Kiểm tra các tính chất của dãy số:
- Tính chẵn lẻ (các phần tử xen kẽ nhau chẵn lẻ).
- Tính toàn chẵn (dãy số chứa toàn số chẵn).

#### Input
- Nhập số lượng phần tử n và giá trị của từng phần tử trong dãy số nguyên a.

#### Output
- Kiểm tra và hiển thị các tính chất của dãy số.

#### Chức năng
- Kiểm tra nếu các phần tử có tính chất xen kẽ giữa số chẵn và số lẻ.
- Kiểm tra nếu toàn bộ phần tử trong dãy là số chẵn.

#### Ý tưởng
- Duyệt qua các phần tử và kiểm tra điều kiện xen kẽ.
- Kiểm tra toàn bộ dãy có phải số chẵn hay không.

---

### Bài tập 3

#### Bài toán yêu cầu
Cho dãy ký tự a có n phần tử (n ≤ 100). Hãy tạo dãy b chứa các ký tự nguyên âm của a và xuất b ra màn hình.

#### Input
- Nhập số lượng phần tử n và giá trị của từng phần tử trong dãy ký tự a.

#### Output
- Dãy b chứa các nguyên âm của a.

#### Chức năng
- Lọc các ký tự nguyên âm từ dãy a.
- Xuất dãy b ra màn hình.

#### Ý tưởng
- Duyệt qua mảng a, kiểm tra nếu phần tử là nguyên âm (a, e, i, o, u) thì thêm vào dãy b.
- Xuất dãy b ra màn hình.

---

### Bài tập 4

#### Bài toán yêu cầu
Cho dãy số thực a có n phần tử và b có m phần tử (n,m ≤ 100) tăng dần. Hãy tạo dãy c từ hai dãy a, b sao cho tăng dần (không dùng sắp xếp).

#### Input
- Nhập hai dãy số a và b đã được sắp xếp tăng dần.

#### Output
- Dãy số c được gộp từ a và b mà vẫn giữ thứ tự tăng dần.

#### Chức năng
- Nhập hai dãy số tăng dần a và b.
- Gộp hai dãy thành dãy c mà không cần sắp xếp lại.
- Xuất dãy c ra màn hình.

#### Ý tưởng
- Sử dụng hai con trỏ duyệt song song dãy a và b, so sánh và đưa phần tử nhỏ hơn vào dãy c trước.
- Nếu một dãy hết phần tử, đưa toàn bộ phần tử còn lại của dãy kia vào dãy c.
- Xuất dãy c ra màn hình.

---

### Bài tập 5

#### Bài toán yêu cầu
Cho dãy số nguyên a có n phần tử (n ≤ 100). Hãy tách dãy a thành dãy b chứa số chẵn và dãy c chứa số lẻ.

#### Input
- Nhập số lượng phần tử n và giá trị từng phần tử của mảng a.

#### Output
- Dãy b chứa số chẵn.
- Dãy c chứa số lẻ.

#### Chức năng
- Nhập dãy số nguyên a.
- Phân loại các phần tử vào hai dãy b (chẵn) và c (lẻ).
- Xuất hai dãy b và c ra màn hình.

#### Ý tưởng
- Sử dụng con trỏ để duyệt từng phần tử của mảng a.
- Tạo hai mảng b và c để chứa các số chẵn và số lẻ, tương ứng.
- Kiểm tra tính chẵn lẻ của từng phần tử trong a:
  - Nếu số đó chẵn, thêm vào b.
  - Nếu số đó lẻ, thêm vào c.
- Xuất dãy b và dãy c ra màn hình.

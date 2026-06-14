# THE LEGEND OF HCMUS - RPG CONSOLE GAME

Đây là Đồ án môn học Cấu trúc Dữ liệu và Giải thuật (DSA) - Lớp 25CTT4.
Dự án bao gồm hai phần cốt lõi: Xây dựng Thư viện C++ sử dụng Templates và Ứng dụng thực tế (Game RPG Console).

## Đội ngũ phát triển

* **Thành viên A (Phát triển Thư viện):** Văn Thành Phát - MSSV: 25120267
* **Thành viên B (Phát triển Ứng dụng):** Nguyễn Hoàng Quân - MSSV: 25120269

## Cấu trúc thư mục

Dự án được tổ chức theo cấu trúc độc lập giữa thư viện và ứng dụng để đảm bảo tính module hóa:

* `/lib`: Chứa toàn bộ mã nguồn thư viện C++ Templates.
* `/app`: Chứa mã nguồn ứng dụng game RPG The Legend of HCMUS (bao gồm UI, Systems logic và hàm `main.cpp`).
* `/app/data`: Thư mục tự động sinh ra khi chơi game để lưu trữ file save và lịch sử mạo hiểm của Kị sĩ.
* `Makefile`: File hỗ trợ biên dịch nhanh ứng dụng.

## Hướng dẫn biên dịch và chạy mã nguồn

**Yêu cầu hệ thống:**
* Trình biên dịch C++ hỗ trợ tiêu chuẩn C++11/C++17 trở lên (khuyên dùng GCC/MinGW).
* Môi trường Terminal/Command Prompt hỗ trợ hiển thị ASCII.

**Cách 1: Sử dụng Makefile (Khuyên dùng cho Windows kèm MinGW)**
1. Mở Terminal/Command Prompt tại thư mục gốc của dự án.
2. Gõ lệnh sau để biên dịch:
mingw32-make
Khởi chạy game:
./main.exe

**Đối với linux**
1. Mở Terminal/Command Prompt tại thư mục gốc của dự án.
2. Gõ lệnh sau để biên dịch: 
make
Khởi chạy game:
./main.exe
**Cách 2: Biên dịch thủ công bằng dòng lệnh**
Nếu hệ thống của bạn không có make, bạn có thể biên dịch trực tiếp file main.cpp bằng lệnh g++:

Mở Terminal tại thư mục gốc của dự án.

Gõ lệnh biên dịch:
g++ -std=c++17 app/main.cpp -o main.exe

Khởi chạy game:
./main.exe


## Hướng dẫn trải nghiệm nhanh
Trong lần đầu khởi động, hệ thống sẽ yêu cầu bạn nhập tên Kị sĩ để tạo file Save.

Sử dụng các phím số và Enter để điều hướng qua các Menu chức năng.

Đảm bảo không thay đổi kích thước cửa sổ Terminal quá nhỏ (khuyến nghị chiều ngang > 70 ký tự) để trải nghiệm giao diện khung ASCII 65 ký tự được hiển thị hoàn hảo nhất.
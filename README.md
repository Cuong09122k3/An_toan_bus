# 🚍 Hệ Thống Cảnh Báo Đảm Bảo An Toàn Trên Xe Đưa Đón Học Sinh

> 🧩 **Đề tài Nghiên cứu Khoa học cấp sinh viên năm học 2023–2024**  
> **Trường Đại học Giao thông Vận tải**

---

## 🎯 Mục tiêu
Xây dựng một **mô hình hệ thống cảnh báo thông minh** nhằm ngăn chặn tình trạng **bỏ quên học sinh trên xe đưa đón**, thông qua việc **giám sát, đếm học sinh và gửi cảnh báo tự động** cho tài xế hoặc phụ huynh.

---

## 👥 Nhóm thực hiện
- **Lê Văn Minh**  
- **Đỗ Văn Huy**  
- **Trịnh Văn Mạnh**  
- **Phạm Đăng Khôi**  
- **Nguyễn Văn Cường**

---

## ⚙️ Phần cứng & Công nghệ sử dụng

### 🧠 Bộ điều khiển
- **Arduino UNO R3**: điều khiển chính, xử lý tín hiệu cảm biến.  
- **ESP32**: truyền dữ liệu lên ứng dụng và hiển thị thông tin lên **màn hình OLED**.

### 📡 Module & Cảm biến
- **Cảm biến hồng ngoại (IR Sensor)** – đếm số lượng học sinh lên/xuống xe.  
- **Module SIM800A** – tự động gọi cảnh báo cho tài xế khi phát hiện có học sinh bị bỏ quên.  
- **Module GPS NEO-6M V2** – theo dõi vị trí, hành trình xe.  
- **Màn hình OLED SSD1306** – hiển thị trạng thái và số lượng học sinh.

### 🔌 Chuẩn giao tiếp
- **UART** – truyền dữ liệu giữa Arduino, ESP32 và SIM800A.  
- **I2C** – kết nối ESP32 với màn hình OLED.

---

## 💻 Phần mềm & Lập trình

### 🔹 Vi điều khiển
- **Ngôn ngữ:** C/C++  
- **Môi trường:** Arduino IDE  
- **Chức năng chính:**
  - Đọc tín hiệu cảm biến IR.  
  - Gửi dữ liệu qua Serial sang ESP32.  
  - Kích hoạt cuộc gọi cảnh báo khi cần.  

### 🔹 ESP32
- Kết nối Wi-Fi và Firebase Realtime Database.  
- Nhận dữ liệu từ Arduino UNO.  
- Hiển thị lên OLED và đồng bộ dữ liệu lên Firebase.

### 🔹 Ứng dụng di động (Java)
- **Ngôn ngữ:** Java (Android Studio)  
- **Tính năng:**  
  - Đăng ký / đăng nhập tài khoản người dùng.  
  - Hiển thị số lượng học sinh và trạng thái xe theo thời gian thực.  
  - Đọc dữ liệu từ Firebase Realtime Database.

---

## 🧩 Kết quả đạt được
- Hoàn thiện mô hình thu nhỏ hoạt động ổn định.  
- Dữ liệu hiển thị thời gian thực trên ứng dụng di động.  
- Tự động gọi điện cảnh báo khi có học sinh bị bỏ quên.  
- Góp phần nâng cao an toàn trong vận chuyển học sinh.

---

## 🧰 Công cụ & Nền tảng hỗ trợ
| Loại | Công cụ |
|------|----------|
| IDE | Arduino IDE, Android Studio |
| CSDL | Firebase Realtime Database |
| Giao tiếp | UART, I2C |
| Môi trường thử nghiệm | Mạch Arduino, ESP32, cảm biến IR, module SIM800A |

---

> 📘 *Dự án được thực hiện trong khuôn khổ chương trình Nghiên cứu Khoa học Sinh viên năm học 2023–2024.*

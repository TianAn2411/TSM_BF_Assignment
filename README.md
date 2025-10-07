
# **Discrete mathematics - Assignment: Traveling Salesman Problem (TSP) and Bellman-Ford Algorithm**

## **About me**
- **Trương Thiên Ân** - MSSV 2310190 - Trường Đại học Bách Khoa - DHQG TPHCM
- **Email**: an.truong241105@hcmut.edu.vn

Phần bài tập lớn này được thực hiện vào HK241, mong các bạn có thể tham khảo qua về những thuật toán mà mình sử dụng, và nếu có cần trao đổi, bổ sung và sửa lỗi đừng ngần ngại email cho mình nhé. Xin cảm ơn các bạn
## **Introduction**

Dự án này triển khai giải quyết hai bài toán quan trọng trong lý thuyết đồ thị: **Traveling Salesman Problem (TSP)** và **Bellman-Ford Algorithm**. 

1. **TSP (Traveling Salesman Problem)**: Tìm lộ trình ngắn nhất cho một người bán hàng đi qua tất cả các thành phố trong danh sách, mỗi thành phố được ghé qua đúng một lần và quay lại thành phố xuất phát.
2. **Bellman-Ford Algorithm**: Tìm đường đi ngắn nhất từ một đỉnh đến tất cả các đỉnh còn lại trong đồ thị có trọng số, có thể xử lý các cạnh có trọng số âm.

## **Algorithms**

### **Traveling Salesman Problem (TSP)**
- **Thuật toán**: **Dynamic Programming** kết hợp **Bitmasking** để giảm bớt độ phức tạp của bài toán TSP.
- **Chiến lược**: Mỗi trạng thái trong bài toán được lưu trữ để tránh tính toán lại nhiều lần. Thuật toán DP với bitmasking cho phép đánh dấu các đỉnh đã thăm và tìm ra chu trình tối ưu.
  
**Để hiểu hơn về thuật toán sử dụng trong bài TSP các bạn có thể xem file [báo cáo](https://github.com/TianAn2411/TSM_BF_Assignment/blob/8e8a5fbad982ebe293c2fdf261ee45a42c947592/2310190_tsm.pdf) nhé**
### **Bellman-Ford Algorithm**
- **Thuật toán**: Sử dụng **relaxation** để tìm đường đi ngắn nhất từ đỉnh bắt đầu đến tất cả các đỉnh còn lại trong đồ thị, đồng thời có thể xử lý các cạnh có trọng số âm.
- **Ưu điểm**: Có thể phát hiện chu trình âm trong đồ thị, điều này rất quan trọng khi làm việc với các bài toán về đồ thị không có chu trình âm.

## **Folder structure**

Dự án bao gồm các thư mục và file sau:

```
ASSIGNMENT_CTRR/
├── inc/
│   ├── bellman.h         # Header file cho thuật toán Bellman-Ford
│   └── tsm.h             # Header file cho thuật toán TSP
├── src/
│   ├── bellman.cpp       # Implementations of Bellman-Ford algorithm
│   ├── tsm.cpp           # Implementations of TSP algorithm
│
├── main.cpp              # File chính để chạy chương trình
└── 2310190_tsm.pf        # File báo cáo và có giải thích các thuật toán
```
### **Thư mục `inc/`**
- **`tsm.h`**: Chứa các khai báo và chức năng liên quan đến thuật toán TSP.
- **`bellman.h`**: Chứa các khai báo và chức năng liên quan đến thuật toán Bellman-Ford.

### **Thư mục `src/`**
- **`tsm.cpp`**: Chứa các hàm thực thi cho thuật toán TSP.
- **`bellman.cpp`**: Chứa các hàm thực thi cho thuật toán Bellman-Ford.
- **`main.cpp`**: File chính để nhập liệu và kiểm tra các thuật toán.

## **Installation**

### **System requirements**
- **Cài đặt g++**: Đảm bảo rằng bạn đã cài đặt **g++** hoặc một trình biên dịch C++ khác trên hệ thống của mình.

### **Compile and run the program**
Để biên dịch và chạy chương trình, hãy thực hiện các bước sau:

1. **Mở terminal** trong VSCode hoặc terminal trên máy tính của bạn.
2. **Chuyển đến thư mục chứa mã nguồn** của dự án:
3. **Biên dịch mã nguồn** bằng lệnh sau:
   ```bash
   g++ -I./inc src/main.cpp src/tsm.cpp src/bellman.cpp -o main
   ```
4. Sau khi biên dịch thành công, bạn có thể chạy chương trình bằng lệnh sau (Windows):
  ```bash
  ./main
  ```

### **Providing inputs**
Khi chương trình chạy, bạn sẽ được yêu cầu nhập vào:
- **Đỉnh xuất phát** trong bài toán TSP.
- **Đỉnh xuất phát và đỉnh đích** trong thuật toán Bellman-Ford.

### **Examples**
- **Traveling Salesman Problem (TSP)**: Chương trình sẽ yêu cầu bạn nhập vào **đỉnh xuất phát**, và sau đó nó sẽ tính toán lộ trình ngắn nhất qua tất cả các thành phố.
- **Bellman-Ford**: Chương trình sẽ yêu cầu bạn nhập vào **đỉnh xuất phát** và **đỉnh đích**, sau đó tính toán đường đi ngắn nhất giữa hai đỉnh này.

## **Main features**
- **Traveling (TSP)**: Tính toán lộ trình tối ưu cho bài toán TSP.
- **Bellman-Ford**: Tìm đường đi ngắn nhất từ một đỉnh đến các đỉnh khác trong đồ thị.

## **References**
1. Slide bài giảng môn Cấu trúc rời rạc cho Khoa Học Máy tính của các giảng viên.
2. Kenneth H. Rosen, *Discrete Mathematics and Its Applications*, 2019.



# Tấm pin mặt trời luôn hướng mặt trời

Hệ thống theo dõi ánh sáng và tự động xoay tấm pin solar 2 trục về vị trí sáng nhất. Dùng 4 cảm biến quang trở so sánh cường độ sáng và điều khiển 2 servo để tối ưu thu năng lượng.

## Luồng hoạt động
1. Đọc 4 cảm biến ánh sáng (trái trên, phải trên, trái dưới, phải dưới).
2. So sánh cường độ sáng giữa các cảm biến.
3. Điều chỉnh servo ngang/dọc (+2° hoặc -2°) về phía sáng hơn.
4. Lặp liên tục để duy trì hướng tối ưu.

## Công nghệ sử dụng
- Phần cứng: Arduino, 4x quang trở (LDR), 2x Servo, tấm pin mặt trời
- Ngôn ngữ: C++ (Arduino)
- IDE: Arduino IDE

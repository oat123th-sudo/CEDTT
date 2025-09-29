#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::vector<int> sum;  // sum[i] = digit ที่ตำแหน่ง i (0=หน่วย), ฐาน 10

    while (std::cin >> s) {
        if (s == "END") break;

        int carry = 0;
        int i = 0;
        // บวก s เข้ากับ sum จากขวาไปซ้าย
        for (int k = static_cast<int>(s.size()) - 1; k >= 0; --k, ++i) {
            int d = s[k] - '0';                 // แปลง char -> digit
            if (i == static_cast<int>(sum.size()))
                sum.push_back(0);               // ขยายถ้าจำเป็น

            int t = sum[i] + d + carry;         // บวกหลัก + carry
            sum[i] = t % 10;                    // เก็บหลัก
            carry = t / 10;                     // อัปเดต carry
        }
        // เคลียร์ carry ที่ยังเหลือ
        while (carry) {
            if (i == static_cast<int>(sum.size()))
                sum.push_back(0);
            int t = sum[i] + carry;
            sum[i] = t % 10;
            carry = t / 10;
            ++i;
        }
    }

    if (sum.empty()) {          // ไม่มีอินพุตก่อนเจอ END
        std::cout << 0;
        return 0;
    }

    // พิมพ์จากหลักมากไปน้อย และตัด leading zeros
    int i = static_cast<int>(sum.size()) - 1;
    while (i > 0 && sum[i] == 0) --i;
    for (; i >= 0; --i) std::cout << sum[i];
    return 0;
}

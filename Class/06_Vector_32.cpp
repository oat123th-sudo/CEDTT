#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

struct oo {
    std::vector<int> num;  // สมาชิกในกล่อง
    int sum = 0;           // ผลรวมของกล่อง
};

// ---------- FIRST-FIT: ใส่ค่าทีละตัวลง "กล่องแรก" ที่ยังพอ ----------
std::vector<oo> first(const std::vector<int>& v) {
    std::vector<oo> ret;                 // รายการกล่องที่สร้างไว้แล้ว
    for (int x : v) {                    // พิจารณาทีละตัว ตามลำดับอินพุต
        bool put = false;
        for (std::size_t i = 0; i < ret.size(); ++i) {
            if (ret[i].sum + x <= 100) { // กล่องแรกที่ใส่ได้
                ret[i].num.push_back(x);
                ret[i].sum += x;
                put = true;
                break;                   // เจอแล้วหยุด → ไปดูเลขตัวถัดไป
            }
        }
        if (!put) {                      // ไม่มีที่ใส่ → สร้างกล่องใหม่
            oo p;
            p.num.push_back(x);
            p.sum = x;
            ret.push_back(std::move(p));
        }
    }
    return ret;
}

// ---------- BEST-FIT: เลือกกล่องที่ใส่แล้ว "เหลือพื้นที่น้อยสุด" ----------
std::vector<oo> best(const std::vector<int>& v) {
    std::vector<oo> ret;
    for (int x : v) {                         // พิจารณาทีละตัว ตามลำดับอินพุต
        int best_i = -1;
        int best_rem = 101;                   // ส่วนที่เหลือน้อยสุดชนะ

        for (int i = 0; i < (int)ret.size(); ++i) {
            if (ret[i].sum + x <= 100) {
                int rem = 100 - (ret[i].sum + x); // สูตรที่ถูก: 100 - (sum+x)
                if (rem < best_rem) {             // ดีกว่าเดิมเท่านั้นจึงเลือก
                    best_rem = rem;
                    best_i = i;
                }
            }
        }

        if (best_i == -1) {                      // ไม่มีที่ใส่ → เปิดกล่องใหม่
            oo p;
            p.num.push_back(x);
            p.sum = x;
            ret.push_back(std::move(p));
        } else {
            ret[best_i].num.push_back(x);
            ret[best_i].sum += x;
        }
    }
    return ret;
}

// ---------- กติกาการเรียงผลลัพธ์ของกล่อง ----------
bool cmpBin(oo a, oo b) {
    if (a.sum != b.sum) return a.sum > b.sum;                      // 1) ผลรวมมากก่อน
    if (a.num.size() != b.num.size()) return a.num.size() < b.num.size(); // 2) จำนวนสมาชิกน้อยก่อน
    return a.num < b.num;                                          // 3) เทียบลำดับสมาชิก (ต้องเรียงในกล่องก่อน)
}

int main() {
    // อ่านวิธีและบรรทัดตัวเลข
    std::string method, line;
    if (!(std::cin >> method)) return 0;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, line);

    // แปลงบรรทัดที่สองเป็นตัวเลข
    std::stringstream ss(line);
    std::vector<int> vec;
    for (int x; ss >> x; ) vec.push_back(x);

    // ประมวลผลตามวิธี
    std::vector<oo> ans = (method == "first") ? first(vec) : best(vec);

    // เรียงตัวเลขภายในแต่ละกล่องก่อน (เพื่อใช้เทียบ lexicographic)
    for (auto& b : ans) std::sort(b.num.begin(), b.num.end());

    // เรียงกล่องตามกติกา
    std::sort(ans.begin(), ans.end(), cmpBin);

    // แสดงผล: หนึ่งกล่องต่อหนึ่งบรรทัด ตัวเลขคั่นด้วยช่องว่าง
    for (const auto& b : ans) {
        for (std::size_t j = 0; j < b.num.size(); ++j) {
            if (j) std::cout << ' ';
            std::cout << b.num[j];
        }
        std::cout << '\n';
    }
    return 0;
}

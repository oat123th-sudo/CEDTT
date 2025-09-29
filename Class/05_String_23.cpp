#include <bits/stdc++.h>
using namespace std;

// แปลงตัวอักษรเป็นเลข 0..25 และกลับกัน
static inline int c2i(char c){ return c - 'A'; }
static inline char i2c(int x){ return char('A' + x); }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string li;          // รูปแบบเช่น "2ZZ-998"
    long long m;
    if(!(cin >> li >> m)) return 0;

    // แยกส่วน: D L1 L2 '-' NNN
    int D  = li[0] - '0';
    int L1 = c2i(li[1]);
    int L2 = c2i(li[2]);
    int N  = (li[4]-'0')*100 + (li[5]-'0')*10 + (li[6]-'0');

    // 1) บวก m เข้ากับเลขสามหลัก แล้วแตกเป็น carry
    long long totalN = (long long)N + m;   // อาจเกิน 999 ได้
    long long carry_to_L2 = totalN / 1000; // ทุกๆ 1000 เลข ขยับ L2 หนึ่งครั้ง
    N = (int)(totalN % 1000);

    // 2) เอา carry ไปเพิ่ม L2 แล้วแตกเป็น carry ไป L1
    long long totalL2 = (long long)L2 + carry_to_L2;
    long long carry_to_L1 = totalL2 / 26;
    L2 = (int)(totalL2 % 26);

    // 3) เอา carry ไปเพิ่ม L1 แล้วแตกเป็น carry ไป D
    long long totalL1 = (long long)L1 + carry_to_L1;
    long long carry_to_D = totalL1 / 26;
    L1 = (int)(totalL1 % 26);

    // 4) เพิ่มเข้า D (โจทย์กำหนดว่าช่วง valid คือ 0..9)
    D += (int)carry_to_D; // ถ้าอินพุต+ m อยู่ในขอบเขต โค้ดจะไม่เกิน 9

    // 5) พิมพ์ผลลัพธ์
    cout << D << i2c(L1) << i2c(L2) << "-";
    cout << setw(3) << setfill('0') << N << "\n";
    return 0;
}

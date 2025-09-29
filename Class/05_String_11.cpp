#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    while (getline(cin, line)) {
        if (line.empty()) { cout << '\n'; continue; }

        char delim = line.back();   // อักขระพิเศษ (ตัวแบ่ง) คือ ตัวสุดท้ายของบรรทัด
        bool in = false;            // อยู่ในช่วงที่ต้องเก็บตัวอักษรหรือไม่
        string out;

        for (char c : line) {
            if (c == delim) {
                in = !in;           // พบตัวแบ่ง → สลับสถานะ
            } else if (in) {
                out += c;           // เก็บเฉพาะตอนอยู่ในช่วง
            }
        }
        cout << out << '\n';
    }
    return 0;
}

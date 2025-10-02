#include <bits/stdc++.h>
using namespace std;

map<string,int> base = {
    {"soon",0}, {"neung",1}, {"song",2}, {"sam",3}, {"si",4},
    {"ha",5}, {"hok",6}, {"chet",7}, {"paet",8}, {"kao",9},
    {"et",1}, {"yi",2}
};

map<string,int> unit = {
    {"sip",10}, {"roi",100}, {"phan",1000}, {"muen",10000},
    {"saen",100000}, {"lan",1000000}
};

long long parse(vector<string> &words) {
    long long total = 0;      // ยอดรวมทั้งบรรทัด (ผลลัพธ์สุดท้าย)
    long long segment = 0;    // บล็อกย่อย (ต่ำกว่า "ล้าน")
    int digit = -1;           // เลขหลักเดียวล่าสุดที่รอจับคู่หน่วย (-1 = ยังไม่มี)

    // เคสพิเศษ: บรรทัดเดียวเป็น "soon" → 0
    if (words.size() == 1 && words[0] == "soon") return 0;

    for (const string &w : words) {
        if (base.count(w)) {
            // เจอเลขเดี่ยว: เก็บไว้รอจับคู่กับหน่วย
            digit = base[w];
        }
        else if (unit.count(w)) {
            int u = unit[w];
            if (w == "lan") {
                // ปิดบล็อกล้าน: (segment + digit(ถ้ามี)) × 1e6
                long long block = segment + (digit == -1 ? 0 : digit);
                if (block == 0) block = 1; // "lan" เดี่ยว ๆ = 1 ล้าน
                total += block * 1000000LL;
                segment = 0;
                digit = -1;
            } else {
                // หน่วยสิบ–แสน: จับคู่เฉพาะกับ digit (ถ้าไม่มีให้เป็น 1)
                int d = (digit == -1 ? 1 : digit);
                segment += 1LL * d * u;
                digit = -1;
            }
        }
        // คำอื่น (ไม่น่ามีตามสเปค) ไม่ต้องทำอะไร
    }

    // ปิดท้าย: บวกเศษบล็อกที่เหลือ
    return total + segment + (digit == -1 ? 0 : digit);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    while (true) {
        getline(cin, line);
        if (line == "q") break;
        stringstream ss(line);
        vector<string> words;
        string w;
        while (ss >> w) words.push_back(w);

        cout << parse(words) << "\n";
    }
    return 0;
}

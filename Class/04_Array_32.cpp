#include <bits/stdc++.h>
using namespace std;

struct lift{
    int num,now,go;
};
struct people{
    int pnow,pgo;
};

/* ✅ อธิบายแนวคิดสั้น ๆ
   - โค้ดเดิมใช้ bool upl/upp เพื่อบอกทิศ (ขึ้น/ลง) แต่ "ไม่รีเซ็ต" ทุกคำถาม (แต่ละคน) → ค่าค้างจากรอบก่อน
   - มีบรรทัดใช้ '=' (กำหนดค่า) แทน '==' (เปรียบเทียบ) ใน if → เงื่อนไขกลายเป็นจริง/เท็จผิด ๆ
   - มีการอ้างดัชนีผิด: ใช้ rlift[i].go ในลูปของ j → ควรเป็น rlift[j].go
   - ตัวแปรผลลัพธ์ o อาจไม่ถูกกำหนดค่าเลยถ้าไม่เข้าเงื่อนไขใด ๆ → Undefined Behavior
   แนวทางแก้:
   1) รีเซ็ต upp ต่อคนทุกครั้ง และคำนวณ upl ต่อ “ลิฟต์แต่ละตัว” ทุกครั้ง
   2) แก้ '=' เป็น '=='
   3) แก้ rlift[i].go → rlift[j].go
   4) คิด “ต้นทุน/ภาระ” (cost) แบบเดียวกันทุกเคส เพื่อเลือกตัวที่ดีที่สุดได้แน่นอน
*/

static int extraCost(const lift& L, int from, int to) {
    // ฟังก์ชันคำนวณภาระเพิ่มอย่างสอดคล้องกันทุกกรณี
    int a = L.now, b = L.go;
    if (a == b) {
        // ลิฟต์หยุดนิ่งที่ชั้น a: ต้องวิ่งมารับเราแล้วพาไป
        return abs(from - a) + abs(to - from);
    }
    bool upL = (b > a);             // ทิศของลิฟต์
    int lo = min(a,b), hi = max(a,b);
    bool onPath = (from >= lo && from <= hi); // เราอยู่บนทางผ่านของลิฟต์ไหม
    bool upP = (to > from);         // ทิศที่ผู้โดยสารต้องการ

    if (!onPath) {
        // ไม่ผ่านชั้นที่เรายืน → ต้องไปถึงปลายทางเดิมก่อน แล้วอ้อมมารับเรา
        return abs(from - b) + abs(to - from);
    }

    // อยู่บนทางผ่านแล้ว
    if (upL == upP) {
        // ไปทางเดียวกัน
        if (upL) {
            // ลิฟต์ขึ้น: ถ้า to อยู่ระหว่าง from..hi → แวะส่งได้เลย (ภาระ 0)
            if (to >= from && to <= hi) return 0;
            // ถ้า to เลย hi → ภาระคือ to - hi (แถมทางจาก hi ไปถึง to)
            return to - hi;
        } else {
            // ลิฟต์ลง
            if (to <= from && to >= lo) return 0;
            return lo - to; // to ต่ำกว่า lo → แถมทางจาก lo ลงไปถึง to
        }
    } else {
        // ทิศสวนทางกัน: ลิฟต์ต้องไปให้สุดทางเดิมก่อนแล้วค่อยย้อน
        if (upL) {
            // ลิฟต์ขึ้นอยู่ ไปสุด hi แล้วค่อยย้อนมาที่ to
            return (hi - from) + abs(to - hi);
        } else {
            // ลิฟต์ลงอยู่ ไปสุด lo แล้วค่อยย้อนมาที่ to
            return (from - lo) + abs(to - lo);
        }
    }
}

int main(){
    int n,m;
    // ⚠️ หมายเหตุ: VLA (เช่น lift rlift[n]) ไม่ใช่มาตรฐาน C++ แต่ g++ อนุญาตเป็น extension
    // ถ้าอยากให้เป็นมาตรฐาน 100% ควรใช้ vector แทน (ที่นี่คงรูปแบบเดิมตามคำขอ)
    cin >> n;
    lift rlift[n];
    for(int i=0;i<n;i++){
        cin >> rlift[i].num >> rlift[i].now >> rlift[i].go;
    }
    cin >> m;
    people p[m];
    for(int i=0;i<m;i++){
        cin >> p[i].pnow >> p[i].pgo;
    }

    for(int i=0;i<m;i++){
        // ❌ เดิม: bool upl=0, upp=0 ถูกประกาศนอกลูป แล้วไม่รีเซ็ตในแต่ละรอบ → ค่าค้าง
        // ✅ แก้: คำนวณ upp ต่อรอบของ "ผู้โดยสารคน i" และคำนวณ upl ต่อ "ลิฟต์แต่ละตัว" ในลูป j
        bool upp = (p[i].pgo > p[i].pnow); // ทิศทางที่คน i ต้องการ (ขึ้น/ลง)

        int mn = INT_MAX;
        int o  = -1; // ✅ กำหนดค่าเริ่มต้นกัน UB

        for(int j=0;j<n;j++){
            bool upl = (rlift[j].go > rlift[j].now); // ทิศทางของลิฟต์ตัว j

            // ---------- จุดผิดเดิม ----------
            // 1) มีการใช้ rlift[i].go ในลูปของ j → ผิด index (ควรเป็น rlift[j].go)
            // 2) else if (upp = upl && ...) ใช้ '=' (กำหนดค่า) แทน '==' (เปรียบเทียบ)
            // 3) เงื่อนไขซับซ้อนและไม่ครอบคลุมทุกกรณี ทำให้ o อาจไม่ถูกอัปเดตเลย
            // ---------------------------------

            // ✅ แทนที่ด้วยการคำนวณ cost ที่ชัดเจน ครอบคลุมทุกกรณี
            int cost = extraCost(rlift[j], p[i].pnow, p[i].pgo);

            // เลือก cost น้อยสุด; ถ้าเท่ากันให้เลือกหมายเลขลิฟต์ (num) น้อยสุด
            if (cost < mn || (cost == mn && rlift[j].num < o)) {
                mn = cost;
                o  = rlift[j].num;
            }
        }

        cout << ">> " << o << "\n";
    }
}

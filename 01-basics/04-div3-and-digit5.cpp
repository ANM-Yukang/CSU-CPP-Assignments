/*
 * 筛选同时满足两个条件的数
 * ------------------------------------------------------------
 * 找出 1 ~ 599 之间，同时满足以下条件的数：
 *   1. 能被 3 整除（i % 3 == 0）
 *   2. 百位、十位、个位中至少有一位是 5
 *
 * 原作业代码：
 *   bool div3  = (i % 3 == 0);
 *   int baiwei = i / 100;         // 百位
 *   int shiwei = (i / 10) % 10;   // 十位
 *   int gewei  = i % 10;          // 个位
 *   bool you5  = (baiwei == 5) || (shiwei == 5) || (gewei == 5);
 *
 * 注意：原代码 #include <ciso646> 是让 and/or 关键字可用的头文件，
 *       现代 C++ 中 && || 本身即可用，这里改为标准写法。
 */

#include <iostream>

using namespace std;

int main() {
    cout << "1 ~ 599 中，能被 3 整除且含数字 5 的数：" << endl;

    int count = 0;  // 顺便统计个数
    for (int i = 1; i <= 599; ++i) {
        bool divisibleBy3 = (i % 3 == 0);

        int hundreds = i / 100;         // 百位
        int tens = (i / 10) % 10;       // 十位
        int units = i % 10;             // 个位

        bool hasFive = (hundreds == 5) || (tens == 5) || (units == 5);

        if (divisibleBy3 && hasFive) {
            cout << i << " ";
            ++count;
        }
    }

    cout << endl;
    cout << "共 " << count << " 个。" << endl;

    return 0;
}

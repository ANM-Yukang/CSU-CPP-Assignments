/*
 * Wallis 公式求 π
 * ------------------------------------------------------------
 * Wallis 公式：
 *   π/2 = (2/1 · 2/3) · (4/3 · 4/5) · (6/5 · 6/7) · ...
 *
 * 即：
 *   π = 2 · ∏[i=1..n] ( (2i)² / ((2i-1)(2i+1)) )
 *
 * 原作业代码用累乘写法：
 *   pi *= 2i / (2i - 1);
 *   pi *= 2i / (2i + 1);
 *   最后输出 pi * 2
 *
 * 说明：
 *   Wallis 公式收敛很慢，n = 10^7 时大约只能精确到小数点后 6 位。
 *   若要更高精度需要更大的 n 或换用其他级数（如 Machin 公式）。
 */

#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    const int n = 10000000;  // 迭代次数

    double pi = 1.0;
    for (int i = 1; i <= n; ++i) {
        pi *= (2.0 * i) / (2.0 * i - 1);
        pi *= (2.0 * i) / (2.0 * i + 1);
    }
    pi *= 2.0;  // 得到 π 的近似值

    cout << fixed << setprecision(10);
    cout << "迭代 " << n << " 次后，π ≈ " << pi << endl;
    cout << "标准值        π = " << 3.141592653589793 << endl;

    return 0;
}

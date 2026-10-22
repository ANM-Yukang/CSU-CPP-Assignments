/*
 * 递归求幂级数部分和
 * ------------------------------------------------------------
 * 求幂级数：x - x² + x³ - x⁴ + ... + (-1)^(n-1) · x^n
 * 的前 n 项之和。
 *
 * 递归思路：
 *   px(x, 1) = x
 *   px(x, n) = px(x, n-1) + (-1)^(n-1) · x^n
 *
 * 原作业代码的问题：
 *   1. 使用 pow(-1, n-1) * pow(x, n)，每次递归都重新算幂，效率低且误差累积
 *   2. 用 float 精度不足
 *   3. 递归深度大时容易栈溢出
 *
 * 改进：改用 double，并用迭代替代递归避免深度问题（保留递归版本作对照）。
 */

#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

// 递归版本（原作业思路，已优化精度）
double powerSeriesRecursive(double x, int n) {
    if (n == 1) {
        return x;
    }
    // 第 n 项：(-1)^(n-1) * x^n
    double term = ((n - 1) % 2 == 0 ? 1.0 : -1.0) * pow(x, n);
    return powerSeriesRecursive(x, n - 1) + term;
}

// 迭代版本（推荐：效率高、无栈溢出风险）
double powerSeriesIterative(double x, int n) {
    double sum = 0.0;
    double power = x;       // x^1
    double sign = 1.0;      // 当前项符号

    for (int k = 1; k <= n; ++k) {
        sum += sign * power;
        power *= x;         // 递推得到下一个幂
        sign = -sign;       // 符号交替
    }
    return sum;
}

int main() {
    double x;
    int n;

    cout << "请输入 x 和 n 的值（如：0.5 10）：";
    cin >> x >> n;

    if (n <= 0) {
        cout << "n 必须为正整数。" << endl;
        return 1;
    }

    cout << fixed << setprecision(10);
    cout << "递归结果：" << powerSeriesRecursive(x, n) << endl;
    cout << "迭代结果：" << powerSeriesIterative(x, n) << endl;

    // 数学验证：该级数是等比数列求和
    // 当 |x| < 1 时，无穷级数和为 x / (1 + x)
    if (fabs(x) < 1.0) {
        cout << "理论极限（n→∞）：" << x / (1.0 + x) << endl;
    }

    return 0;
}

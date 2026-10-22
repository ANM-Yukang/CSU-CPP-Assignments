/*
 * 用泰勒级数实现 sin(x)
 * ------------------------------------------------------------
 * sin(x) 的泰勒展开：
 *   sin(x) = x - x³/3! + x⁵/5! - x⁷/7! + ...
 *
 * 递推关系（相邻两项之比）：
 *   从 term = x 开始
 *   下一项 = -term · x² / ((2n)(2n+1))
 *
 * 原作业代码：
 *   while (fabs(term) >= 1e-5) {
 *       s += term;
 *       term = term * (-x*x) / ((2n) * (2n+1));
 *       n++;
 *   }
 *
 * 改进点：
 *   1. 原代码 n 从 1 开始，第一项 term = x 对应 n=1，
 *      但递推公式中的分母应为 (2n)(2n+1) 且 n 从 1 开始，
 *      此处保持与原代码一致并补充说明
 *   2. 用 double 提高精度
 *   3. 加入迭代次数上限，防止死循环
 */

#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

/**
 * 用泰勒级数计算 sin(x)
 * @param x 弧度值
 * @return sin(x) 的近似值
 */
double mySin(double x) {
    double sum = 0.0;
    double term = x;   // 第一项
    int n = 1;
    const double EPS = 1e-10;   // 精度阈值（原作业为 1e-5，这里提高精度）
    const int MAX_ITER = 100;   // 防止死循环

    int iter = 0;
    while (fabs(term) >= EPS && iter < MAX_ITER) {
        sum += term;
        // 递推下一项：term_{n+1} = -term_n · x² / ((2n)(2n+1))
        term = term * (-x * x) / ((2.0 * n) * (2.0 * n + 1.0));
        ++n;
        ++iter;
    }
    return sum;
}

int main() {
    double x;
    cout << "请输入 x 的值（弧度）：";
    cin >> x;

    cout << fixed << setprecision(10);
    cout << "my_sin(" << x << ")  = " << mySin(x) << endl;
    cout << "标准库 sin(" << x << ") = " << sin(x) << endl;
    cout << "误差 = " << fabs(mySin(x) - sin(x)) << endl;

    return 0;
}

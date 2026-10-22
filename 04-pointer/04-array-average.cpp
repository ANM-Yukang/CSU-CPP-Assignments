/*
 * 数组遍历求平均值（普通写法）
 * ------------------------------------------------------------
 * 与「指针遍历求平均值」对比：这是不用指针的普通写法。
 *
 * 原作业代码：
 *   int a[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
 *   int sum = 0;
 *   for (int i = 0; i < 10; ++i) sum += a[i];
 *   double avg = sum / 10.0;
 *
 * 关键点：
 *   sum / 10.0  中 10.0 是 double，所以做浮点除法，得到正确小数
 *   如果写 sum / 10  ，则是整数除法，会截断成整数（如 55 而不是 55.0）
 *
 * 这是初学者最常见的坑之一。
 */

#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    int a[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    int sum = 0;
    for (int i = 0; i < 10; ++i) {
        sum += a[i];
    }

    double avg = static_cast<double>(sum) / 10.0;

    cout << fixed << setprecision(2);
    cout << "总和：" << sum << endl;
    cout << "平均值：" << avg << endl;

    // 演示整数除法的陷阱
    int wrongAvg = sum / 10;   // 整数除法，小数被截断
    cout << "（对比）若写成 sum / 10 会得到：" << wrongAvg << endl;

    return 0;
}

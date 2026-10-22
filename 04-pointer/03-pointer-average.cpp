/*
 * 指针遍历数组求平均值
 * ------------------------------------------------------------
 * 用指针访问数组元素，求 10 个数的平均值。
 *
 * 两种写法对比：
 *   写法 A：sum += *(p + i);        指针 + 偏移
 *   写法 B：sum += *(p++);          指针自增遍历
 *
 * 原作业代码用的是写法 A：
 *   int* p = a;
 *   for (int i = 0; i < 10; ++i) sum = sum + *(p + i);
 *
 * 说明：
 *   int* p = a;  等价于  int* p = &a[0];
 *   数组名退化为首元素地址，赋给指针后即可用指针运算访问。
 *
 * 注意：sum 的类型。原代码用 int 累加再除，若数据有小数会丢精度。
 *       这里数据都是整数，用 int 求和 + double 除法没问题。
 */

#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    int a[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    // ===== 写法 A：指针 + 偏移 =====
    int sumA = 0;
    int* p = a;  // 指向首元素
    for (int i = 0; i < 10; ++i) {
        sumA += *(p + i);
    }
    double avgA = static_cast<double>(sumA) / 10.0;

    // ===== 写法 B：指针自增 =====
    int sumB = 0;
    int* q = a;
    for (int i = 0; i < 10; ++i) {
        sumB += *q;   // 取当前指向的值
        ++q;          // 指针后移
    }
    double avgB = static_cast<double>(sumB) / 10.0;

    cout << fixed << setprecision(2);
    cout << "写法 A（指针+偏移）：" << endl;
    cout << "  总和 = " << sumA << "，平均值 = " << avgA << endl;
    cout << "写法 B（指针自增）：" << endl;
    cout << "  总和 = " << sumB << "，平均值 = " << avgB << endl;

    return 0;
}

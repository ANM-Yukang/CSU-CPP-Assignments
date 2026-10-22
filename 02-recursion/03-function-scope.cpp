/*
 * 函数调用与局部变量作用域
 * ------------------------------------------------------------
 * 原作业代码：
 *   int func2(int a, int b) {
 *       int c;
 *       c = a * b % 3;
 *       return (c);
 *   }
 *   int func1(int a, int b) {
 *       int c;
 *       a += a;          // a 变为 2a
 *       b += b;          // b 变为 2b
 *       c = func2(a, b); // 调用 func2
 *       return (c * c);
 *   }
 *   void main() {
 *       int x = 7, y = 17;
 *       cout << func1(x, y) << endl;
 *   }
 *
 * 执行过程分析：
 *   func1(7, 17)
 *     a = 7 + 7 = 14
 *     b = 17 + 17 = 34
 *     c = func2(14, 34)
 *           = 14 * 34 % 3
 *           = 476 % 3
 *           = 2        （因为 476 = 3 × 158 + 2）
 *     return c * c = 2 * 2 = 4
 *
 * 输出结果：4
 *
 * 注意点：
 *   1. func1 和 func2 中的 c 是各自独立的局部变量，互不影响
 *   2. 参数按值传递，func1 修改 a、b 不影响 main 中的 x、y
 *   3. 原代码用 void main() 不规范，应改为 int main() 并 return 0
 */

#include <iostream>

using namespace std;

// 计算 a * b % 3
int func2(int a, int b) {
    int c;
    c = a * b % 3;
    return c;
}

// 参数翻倍后调用 func2，返回结果平方
int func1(int a, int b) {
    int c;
    a += a;   // a = 2a
    b += b;   // b = 2b
    c = func2(a, b);
    return c * c;
}

int main() {
    int x = 7, y = 17;

    cout << "func1(7, 17) = " << func1(x, y) << endl;
    cout << "调用后 x = " << x << ", y = " << y << "（值传递，未被修改）" << endl;

    return 0;
}

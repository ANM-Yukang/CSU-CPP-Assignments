/*
 * 用指针实现选择排序
 * ------------------------------------------------------------
 * 通过指针运算访问数组元素，实现选择排序。
 *
 * 关键语法：
 *   *(a + i)      等价于 a[i]
 *   *(a + maxIdx) 等价于 a[maxIdx]
 *
 * 指针版与数组版本质相同：
 *   数组名在表达式中会退化为指向首元素的指针，
 *   所以 a[i] 会被编译器解释为 *(a + i)。
 *
 * 原作业代码：
 *   if (*(a + j) > *(a + max)) max = j;
 *   temp = *(a + i); *(a + i) = *(a + max); *(a + max) = temp;
 *
 * 改进点：
 *   1. 变量改名 maxIdx，语义更清晰
 *   2. 加入边界检查
 *   3. 补充说明：这种写法虽可读性略差，但能帮助理解指针与数组的关系
 */

#include <iostream>

using namespace std;

/**
 * 用指针运算实现选择排序（降序）
 * @param a 数组首地址
 * @param n 元素个数
 */
void pointerSelectionSort(float* a, int n) {
    if (a == nullptr || n <= 1) {
        return;  // 无需排序
    }

    for (int i = 0; i < n - 1; ++i) {
        int maxIdx = i;
        for (int j = i + 1; j < n; ++j) {
            // 指针写法：*(a + j) 就是 a[j]
            if (*(a + j) > *(a + maxIdx)) {
                maxIdx = j;
            }
        }
        if (maxIdx != i) {
            float temp = *(a + i);
            *(a + i) = *(a + maxIdx);
            *(a + maxIdx) = temp;
        }
    }
}

int main() {
    float a[10] = {10, 25, 90, 80, 70, 35, 65, 40, 55, 5};

    cout << "排序前：";
    for (int i = 0; i < 10; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    pointerSelectionSort(a, 10);

    cout << "排序后：";
    for (int i = 0; i < 10; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}

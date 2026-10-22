/*
 * 选择排序（float 版本）
 * ------------------------------------------------------------
 * 对浮点数组用选择排序升序排列。
 *
 * 与 int 版本的区别：
 *   临时变量 temp 必须是 float，否则小数部分会被截断。
 *
 * 原作业代码：
 *   void sort(float a[], int n) {
 *       int i, j, max;
 *       float temp;
 *       for (i = 0; i < n - 1; i++) {
 *           max = i;
 *           for (j = i + 1; j < n; j++)
 *               if (a[j] > a[max]) max = j;
 *           temp = a[i]; a[i] = a[max]; a[max] = temp;
 *       }
 *   }
 *
 * 注意：变量名叫 max 但实际是「最大值的下标」，容易误解，
 *       这里改名为 maxIdx 更清晰。
 */

#include <iomanip>
#include <iostream>

using namespace std;

// 选择排序（升序）
void selectionSort(float a[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int maxIdx = i;   // 假设当前位置是最大
        for (int j = i + 1; j < n; ++j) {
            if (a[j] > a[maxIdx]) {
                maxIdx = j;
            }
        }
        if (maxIdx != i) {
            float temp = a[i];
            a[i] = a[maxIdx];
            a[maxIdx] = temp;
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

    selectionSort(a, 10);

    cout << "排序后（降序）：";
    for (int i = 0; i < 10; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}

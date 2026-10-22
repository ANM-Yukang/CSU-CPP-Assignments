/*
 * 冒泡排序 vs 选择排序（含成绩统计）
 * ------------------------------------------------------------
 * 对 10 个成绩用两种排序算法分别排序并输出，
 * 同时统计各分数段人数。
 *
 * 两种排序的对比：
 *   冒泡排序：相邻元素两两比较，大的往后冒。每轮把最大值送到末尾。
 *   选择排序：每轮找到剩余部分的最小值，与当前位置交换。
 *
 * 时间复杂度都是 O(n²)，但选择排序的交换次数更少（每轮最多 1 次）。
 */

#include <iostream>

using namespace std;

// 冒泡排序
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;   // 优化：若某轮无交换说明已有序
        for (int j = 0; j < n - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

// 选择排序
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            int temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
    }
}

// 输出数组
void printArray(const int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i];
        if (i != n - 1) cout << ", ";
    }
    cout << endl;
}

int main() {
    const int N = 10;
    int score[N] = {90, 85, 80, 75, 70, 65, 60, 55, 50, 45};

    cout << "原始数据：" << endl;
    printArray(score, N);

    // 冒泡排序
    int bubb[N];
    for (int i = 0; i < N; ++i) bubb[i] = score[i];
    bubbleSort(bubb, N);
    cout << "冒泡排序后：" << endl;
    printArray(bubb, N);

    // 选择排序
    int sel[N];
    for (int i = 0; i < N; ++i) sel[i] = score[i];
    selectionSort(sel, N);
    cout << "选择排序后：" << endl;
    printArray(sel, N);

    return 0;
}

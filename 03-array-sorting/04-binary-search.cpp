/*
 * 二分查找
 * ------------------------------------------------------------
 * 在有序数组中查找目标值，返回其下标；找不到返回 -1。
 *
 * 算法：
 *   每次取中间元素与目标比较：
 *     arr[mid] == target → 找到，返回 mid
 *     arr[mid] <  target → 目标在右半部分，left = mid + 1
 *     arr[mid] >  target → 目标在左半部分，right = mid - 1
 *
 * 时间复杂度 O(log n)，远优于线性查找的 O(n)。
 * 前提：数组必须已排序。
 *
 * 原作业代码注意事项：
 *   int mid = left + (right - left) / 2;  // 避免 left+right 溢出
 *   这个写法是对的，比 (left + right) / 2 更安全。
 */

#include <iostream>

using namespace std;

/**
 * 二分查找
 * @param arr    已排序的数组
 * @param left   左边界（含）
 * @param right  右边界（含）
 * @param target 目标值
 * @return 找到返回下标，否则返回 -1
 */
int binarySearch(const int arr[], int left, int right, int target) {
    while (left <= right) {
        // 防止 (left + right) 溢出
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;   // 目标在右半部分
        } else {
            right = mid - 1;  // 目标在左半部分
        }
    }
    return -1;  // 未找到
}

int main() {
    int arr[] = {10, 12, 14, 16, 18, 20, 22, 24, 26, 28};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "数组：";
    for (int i = 0; i < n; ++i) {
        cout << arr[i];
        if (i != n - 1) cout << ", ";
    }
    cout << endl;

    // 测试几个目标值
    int targets[] = {16, 10, 28, 15};
    for (int t : targets) {
        int index = binarySearch(arr, 0, n - 1, t);
        if (index == -1) {
            cout << "数 " << t << " 未找到" << endl;
        } else {
            cout << "数 " << t << " 在数组中的位置（下标）为：" << index << endl;
        }
    }

    return 0;
}

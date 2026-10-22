/*
 * 二维数组：查找最值与主对角线求和
 * ------------------------------------------------------------
 * 给定一个 5×5 的二维数组，求：
 *   1. 最大值及其位置（行、列）
 *   2. 最小值及其位置
 *   3. 主对角线元素之和
 *
 * 原作业代码思路正确，改进点：
 *   1. 位置从 0 开始存储，输出时 +1 转成人类习惯的 1-based
 *   2. 用 struct 封装最值信息，避免散落的变量
 *   3. 支持任意行数列数的方阵
 */

#include <iostream>

using namespace std;

const int ROWS = 5;
const int COLS = 5;

// 封装最值信息
struct Extremum {
    int value;
    int row;
    int col;
};

int main() {
    int a[ROWS][COLS] = {
        {1, 2, 3, 4, 5},
        {2, 3, 4, 5, 6},
        {3, 4, 5, 6, 7},
        {4, 5, 6, 7, 8},
        {5, 6, 7, 8, 9},
    };

    // 初始化为第一个元素
    Extremum maxVal = {a[0][0], 0, 0};
    Extremum minVal = {a[0][0], 0, 0};
    int diagonalSum = 0;

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (a[i][j] > maxVal.value) {
                maxVal = {a[i][j], i, j};
            }
            if (a[i][j] < minVal.value) {
                minVal = {a[i][j], i, j};
            }
            // 主对角线：行下标 == 列下标
            if (i == j) {
                diagonalSum += a[i][j];
            }
        }
    }

    cout << "========== 二维数组分析 ==========" << endl;
    cout << "最大值：" << maxVal.value
         << "，位置：第 " << maxVal.row + 1 << " 行，第 " << maxVal.col + 1 << " 列" << endl;
    cout << "最小值：" << minVal.value
         << "，位置：第 " << minVal.row + 1 << " 行，第 " << minVal.col + 1 << " 列" << endl;
    cout << "主对角线元素之和：" << diagonalSum << endl;

    return 0;
}

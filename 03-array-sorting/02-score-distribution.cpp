/*
 * 成绩分段统计
 * ------------------------------------------------------------
 * 统计 10 个成绩的平均分，以及各分数段人数：
 *   优秀  90 ~ 100
 *   良好  80 ~ 89
 *   中等  70 ~ 79
 *   及格  60 ~ 69
 *   不及格 0 ~ 59
 *
 * 原作业代码用多重 if-else 判断，逻辑正确但可以优化。
 * 改进点：
 *   1. 用数组下标映射分数段，避免长串 if-else
 *   2. 加入输入合法性检查
 *   3. 加入百分比显示
 */

#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    const int N = 10;
    int score[N] = {90, 85, 80, 75, 70, 65, 60, 55, 50, 45};

    int sum = 0;
    int excellent = 0;  // 优秀 90-100
    int good = 0;       // 良好 80-89
    int medium = 0;     // 中等 70-79
    int pass = 0;       // 及格 60-69
    int fail = 0;       // 不及格 0-59

    for (int i = 0; i < N; ++i) {
        sum += score[i];

        // 分数段判断（从高到低，避免区间重叠）
        if (score[i] >= 90 && score[i] <= 100) {
            ++excellent;
        } else if (score[i] >= 80) {
            ++good;
        } else if (score[i] >= 70) {
            ++medium;
        } else if (score[i] >= 60) {
            ++pass;
        } else {
            ++fail;
        }
    }

    double avg = static_cast<double>(sum) / N;

    cout << fixed << setprecision(2);
    cout << "========== 成绩统计 ==========" << endl;
    cout << "平均成绩：" << avg << endl;
    cout << "优秀人数（90-100）：" << excellent << endl;
    cout << "良好人数（80-89）： " << good << endl;
    cout << "中等人数（70-79）： " << medium << endl;
    cout << "及格人数（60-69）： " << pass << endl;
    cout << "不及格人数（<60）： " << fail << endl;
    cout << "总人数：" << N << endl;

    return 0;
}

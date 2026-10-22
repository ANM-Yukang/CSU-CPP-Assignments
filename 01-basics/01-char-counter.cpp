/*
 * 字符类型统计
 * ------------------------------------------------------------
 * 从标准输入读取一段文本，统计其中英文字母、空格、数字和其他字符的个数。
 *
 * 思路：
 *   用 cin.get(ch) 逐字符读取（保留空格和换行），
 *   用 cctype 中的 isalpha / isdigit 判断字符类型，
 *   遇到换行符 '\n' 结束输入。
 *
 * 注意：原作业代码缺少 <cctype> 头文件导致 isalpha/isdigit 报错，此处已补全。
 */

#include <cctype>
#include <iostream>

using namespace std;

int main() {
    char ch;
    int letter = 0;  // 英文字母
    int space = 0;   // 空格
    int digit = 0;   // 数字
    int other = 0;   // 其他字符

    cout << "请输入文本（回车结束）：" << endl;

    // 逐字符读取，保留空格等空白符
    while (cin.get(ch)) {
        if (ch == '\n') {
            break;  // 遇到换行结束
        }

        if (isalpha(ch)) {
            ++letter;
        } else if (ch == ' ') {
            ++space;
        } else if (isdigit(ch)) {
            ++digit;
        } else {
            ++other;
        }
    }

    cout << "英文字母：" << letter << endl;
    cout << "空格：" << space << endl;
    cout << "数字：" << digit << endl;
    cout << "其他字符：" << other << endl;

    return 0;
}

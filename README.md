# CSU-CPP-Assignments

中南大学《计算机程序设计（C++）》课程作业整理。

每题包含完整的原题说明、实现思路、关键知识点注释，并在原作业基础上做了修正与优化。

## 目录结构

```
01-basics/            基础语法与数值计算
  01-char-counter.cpp         字符类型统计（字母/空格/数字/其他）
  02-recurrence-sequence.cpp  四阶递推数列（前 20 项）
  03-wallis-pi.cpp            Wallis 公式求 π
  04-div3-and-digit5.cpp      能被 3 整除且含数字 5 的数

02-recursion/         递归与函数
  01-power-series.cpp         递归/迭代求幂级数部分和
  02-taylor-sin.cpp           泰勒级数实现 sin(x)
  03-function-scope.cpp       函数调用与局部变量作用域

03-array-sorting/     数组与排序
  01-bubble-vs-selection.cpp  冒泡排序 vs 选择排序
  02-score-distribution.cpp   成绩分段统计
  03-2d-array-extremum.cpp    二维数组最值与主对角线求和
  04-binary-search.cpp        二分查找

04-pointer/           指针与内存
  01-selection-sort-float.cpp 选择排序（float 版）
  02-pointer-sort.cpp         用指针实现选择排序
  03-pointer-average.cpp      指针遍历求平均值
  04-array-average.cpp        数组遍历求平均值
```

## 内容说明

每份代码开头都有一段块注释，包含：

- **题目描述** —— 这道题要做什么
- **实现思路** —— 用了什么算法、为什么这样写
- **原作业问题** —— 原始代码中的问题及修正（如缺少头文件、整数除法陷阱等）
- **关键知识点** —— 涉及的语言特性、易错点

## 相对原作业的改进

| 类别 | 改进内容 |
|---|---|
| 头文件 | 补全 `<cctype>`、`<cmath>`、`<iomanip>` 等缺失的头文件 |
| 数据类型 | 递归数列改用 `long long` 防溢出，浮点计算用 `double` 提高精度 |
| 主函数 | `void main()` 统一改为标准的 `int main()` + `return 0` |
| 整数除法 | 显式 `static_cast<double>` 或 `/ 10.0`，避免截断 |
| 命名 | `max` → `maxIdx` 等，让变量名反映真实含义 |
| 边界处理 | 加入空指针检查、参数校验、迭代次数上限 |
| 输出格式 | 用 `setprecision` 控制小数位，分隔符处理更规范 |

## 编译运行

任选一种方式：

```bash
# g++ / MinGW
g++ 01-basics/01-char-counter.cpp -o char-counter
./char-counter

# MSVC
cl 01-basics/01-char-counter.cpp
char-counter.exe
```

Visual Studio 中直接新建空项目，添加 .cpp 文件即可运行。

## 说明

这些是课程学习期间的练习代码，主要用于理解 C++ 基础语法与常见算法。代码保留了原始作业的思路，在此基础上补充了注释与改进，便于复习查阅。

## License

MIT

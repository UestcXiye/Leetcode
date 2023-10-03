#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <algorithm>
using namespace std;

string longestPalindrome(string s);
// 辅函数 - 对原始字符串进行预处理（添加分隔符）
string addBoundaries(string s, char divide);
int expand(string s, int left, int right);

int main()
{
    // string s = "cbbd";
    // cout << addBoundaries(s, '#') << endl;
    // cout << longestPalindrome(s) << endl;

    unordered_map<char, string> dict{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}};
    string digits = "3";
    cout << dict[digits[0]] << endl;

    system("pause");
    return 0;
}

string longestPalindrome(string s)
{
    if (s.empty() || s.size() < 2)
        return s;
    // 对原始字符串做处理，将abc变成#a#b#c#
    string str = addBoundaries(s, '#');
    int n = str.size();
    // right表示目前计算出的最右端范围，right和左边都是已探测过的
    int right = 0;
    // center最右端位置的中心对称点
    int center = 0;
    int start = 0;
    int maxLen = 0;
    // p数组记录所有已探测过的回文半径，后面我们再计算i时，根据p[i_mirror]计算i
    vector<int> p(n, 0);
    // 从左到右遍历处理过的字符串，求每个字符的回文半径
    for (int i = 0; i < n; ++i)
    {
        // 根据i和right的位置分为两种情况：
        // 1、i<=right利用已知的信息来计算i
        // 2、i>right，说明i的位置时未探测过的，只能用中心探测法
        if (right >= i)
        {
            // 这句是关键，不用再像中心探测那样，一点点的往左/右扩散，根据已知信息
            // 减少不必要的探测，必须选择两者中的较小者作为左右探测起点
            int minArmLen = min(right - i, p[2 * center - i]);
            p[i] = expand(str, i - minArmLen, i + minArmLen);
        }
        else
        {
            // i落在right右边，是没被探测过的，只能用中心探测法
            p[i] = expand(str, i, i);
        }
        // 大于right，说明可以更新最右端范围了，同时更新center
        if (i + p[i] > right)
        {
            center = i;
            right = i + p[i];
        }
        // 找到了一个更长的回文半径，更新原始字符串的start位置
        if (p[i] > maxLen)
        {
            maxLen = p[i];
            start = (i - p[i]) / 2;
        }
    }
    // 根据start和maxLen，从原始字符串中截取一段返回
    return s.substr(start, maxLen);
}

// 辅函数 - 以left和right为起点，计算回文半径
int expand(string s, int left, int right)
{
    while (left >= 0 && right < s.size() && s[left] == s[right])
    {
        --left;
        ++right;
    }
    // 由于while循环退出后left和right各多走了一步，所以在返回的总长度时要减去2
    return (right - left - 2) / 2;
}
// 辅函数 - 对原始字符串进行预处理（添加分隔符）
string addBoundaries(string s, char divide)
{
    if (s.empty())
        return "";
    string t;
    for (char &c : s)
    {
        t += divide;
        t += c;
    }
    t += divide;
    return t;
}
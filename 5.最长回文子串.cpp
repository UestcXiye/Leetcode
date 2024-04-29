/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start

// Time Limit Exceeded

// class Solution
// {
// private:
//     bool isPalindrome(string &s)
//     {
//         return s == string(s.rbegin(), s.rend());
//     }

// public:
//     string longestPalindrome(string s)
//     {
//         int n = s.size();
//         string ans;
//         for (int i = 0; i < n; i++)
//             for (int len = 1; len <= n - i; len++)
//             {
//                 string temp = s.substr(i, len);
//                 if (isPalindrome(temp) && temp.size() > ans.size())
//                     ans = temp;
//             }
//         return ans;
//     }
// };

// 动态规划

class Solution
{
public:
    string longestPalindrome(string s)
    {
        // 特判
        if (s.size() < 2)
            return s;
        int n = s.size(), maxLen = 1, begin = 0;
        // 状态矩阵
        vector<vector<int>> dp(n, vector<int>(n, false));
        // dp[i][j] 表示 s[i...j] 是否是回文串
        // 初始化：所有长度为 1 的子串都是回文串
        for (int i = 0; i < n; i++)
            dp[i][i] = true;
        // 状态转移
        for (int len = 2; len <= n; len++) // 枚举子串长度
            for (int i = 0; i < n; i++)    // 枚举左边界
            {
                int j = i + len - 1; // 计算右边界
                if (j >= n)          // 右边界越界
                    break;
                if (s[i] != s[j])
                    dp[i][j] = false;
                else
                {
                    if (j - i <= 2)
                        dp[i][j] = true;
                    else
                        dp[i][j] = dp[i + 1][j - 1];
                }
                if (dp[i][j] == true && j - i + 1 > maxLen)
                {
                    maxLen = j - i + 1;
                    begin = i;
                }
            }
        return s.substr(begin, maxLen);
    }
};

中心拓展

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); i++)
        {
            auto [left1, right1] = expandAroundCenter(s, i, i);
            auto [left2, right2] = expandAroundCenter(s, i, i + 1);
            // 更新 start 和 end
            if (right1 - left1 > end - start)
            {
                start = left1;
                end = right1;
            }
            if (right2 - left2 > end - start)
            {
                start = left2;
                end = right2;
            }
        }
        return s.substr(start, end - start + 1);
    }
    // 辅函数 - 计算以 s[left...right] 为初始向两边拓展的最长回文子串的起始下标和终止下标
    pair<int, int> expandAroundCenter(const string &s, int left, int right)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            left--;
            right++;
        }
        return {left + 1, right - 1};
    }
};

// Manacher 算法

// class Solution
// {
// private:
//     string manacher(string s)
//     {
//         // 特判
//         if (s.empty() || s.size() < 2)
//             return s;
//         // 对原始字符串 s 做处理，添加分隔符（例如：将 abc 变成 #a#b#c#）
//         string str = addBoundaries(s, '#');
//         int n = str.size();
//         // right 表示已经探测到的字符串最右边的可达范围
//         int right = 0;
//         // center 表示根据最右边的可达范围的中心对称位置
//         int center = 0;
//         int start = 0, maxLen = 0;
//         // p 数组记录所有已探测过的回文半径，后面我们再计算 i 时，根据 p[i_mirror] 计算 i
//         vector<int> p(n, 0);
//         // 从左到右遍历处理过的字符串，求每个字符的回文半径
//         for (int i = 0; i < n; i++)
//         {
//             // 根据i和right的位置分为两种情况：
//             // 1. i <= right，利用已知的信息来计算 i
//             // 2. i > right，说明 i 的位置时未探测过的，只能用中心探测法
//             if (right >= i)
//             {
//                 // 这句是关键，不用再像中心探测那样，一点点的往左/右扩散，根据已知信息
//                 // 减少不必要的探测，必须选择两者中的较小者作为左右探测起点
//                 int minArmLen = min(right - i, p[2 * center - i]);
//                 p[i] = expand(str, i - minArmLen, i + minArmLen);
//             }
//             else // i 落在 right 右边，是没被探测过的，只能用中心探测法
//                 p[i] = expand(str, i, i);
//             // 大于right，说明可以更新最右端范围了，同时更新 center
//             if (i + p[i] > right)
//             {
//                 center = i;
//                 right = i + p[i];
//             }
//             // 找到了一个更长的回文半径，更新原始字符串的 start 位置
//             if (p[i] > maxLen)
//             {
//                 maxLen = p[i];
//                 start = (i - p[i]) / 2;
//             }
//         }
//         // 根据 start 和 maxLen ，从原始字符串中截取一段返回
//         return s.substr(start, maxLen);
//     }
//     // 辅函数 - 以s [left...right] 为起点，计算回文半径（可拓展的步数）
//     int expand(string s, int left, int right)
//     {
//         while (left >= 0 && right < s.size() && s[left] == s[right])
//         {
//             left--;
//             right++;
//         }
//         // 由于while循环退出后left和right各多走了一步，所以在返回的总长度时要减去2
//         return (right - left - 2) / 2;
//     }
//     // 辅函数 - 对原始字符串 s 进行预处理（添加分隔符）
//     string addBoundaries(string s, char divide)
//     {
//         if (s.empty())
//             return "";
//         string t;
//         for (char &c : s)
//         {
//             t += divide;
//             t += c;
//         }
//         t += divide;
//         return t;
//     }

// public:
//     string longestPalindrome(string s)
//     {
//         return manacher(s);
//     }
// };
// @lc code=end

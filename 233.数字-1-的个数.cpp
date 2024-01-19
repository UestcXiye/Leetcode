/*
 * @lc app=leetcode.cn id=233 lang=cpp
 *
 * [233] 数字 1 的个数
 */

// @lc code=start

// 数学

// class Solution
// {
// public:
//     int countDigitOne(int n)
//     {
//         int res = 0;
//         long digit = 1;
//         int high = n / 10, cur = n % 10, low = 0;
//         while (high != 0 || cur != 0)
//         {
//             if (cur == 0)
//                 res += high * digit;
//             else if (cur == 1)
//                 res += high * digit + low + 1;
//             else
//                 res += (high + 1) * digit;
//             low += cur * digit;
//             cur = high % 10;
//             high /= 10;
//             digit *= 10;
//         }
//         return res;
//     }
// };

// 数位 DP

class Solution
{
public:
    int countDigitOne(int n)
    {
        // 转换成为字符串
        string s = to_string(n);
        int len = s.length();
        if (len == 1)
            return n == 0 ? 0 : 1;
        // 第 1 部分：求「整块」的 1 的个数
        // A[i] 表示：0 ~ pow(10, i+1) - 1 里包含 1 的个数
        // i = 0 时，pow(10, i+1) - 1 = 10 - 1 = 9
        // i = 1 时，pow(10, i+1) - 1 = 100 - 1 = 99
        // 5 位数，例如 12345，讨论到 0 ~ 9999 里出现的 1 的总数就可以了
        vector<int> A(len + 1, 0);
        A[0] = 1;
        for (int i = 1; i < len - 1; i++)
            A[i] = 10 * A[i - 1] + (int)pow(10, i);

        // 第 2 部分：求「余项」的 1 的个数
        vector<int> dp(len, 0);
        if (s[len - 1] == '0')
            dp[0] = 0;
        else
            dp[0] = 1;
        for (int i = 1; i < len; i++)
        {
            // 从右向左读每一个数位
            char curChar = s[len - i - 1];
            if (curChar == '0')
            {
                // 高位是 0，没有 1，就取决于低位中 1 的个数
                dp[i] = dp[i - 1];
            }
            else if (curChar == '1')
            {
                // 最高位是 1，高位是 1 的个数取决于后面有多少个数，要记得加 1
                int rest = stoi(s.substr(len - i, len)) + 1;
                // dp[i - 1] 和情况 1 一样理解
                // A[i - 1] 比如 199，A[i - 1] 表示 0 到 99 的里 1 的个数
                dp[i] = rest + dp[i - 1] + A[i - 1];
            }
            else // 最高位是 2、3、4、5、6、7、8、9、10
            {
                // (curChar - '0') * A[i - 1] 表示有几个整块
                // dp[i - 1] 表示余数部分
                // (int)pow(10, i) 最高位是 1 每一位都是 1 所以是 10 的方幂
                dp[i] = (curChar - '0') * A[i - 1] + dp[i - 1] + (int)pow(10, i);
            }
        }
        return dp[len - 1];
    }
};
// @lc code=end

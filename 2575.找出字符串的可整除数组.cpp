/*
 * @lc app=leetcode.cn id=2575 lang=cpp
 *
 * [2575] 找出字符串的可整除数组
 */

// @lc code=start
class Solution
{
public:
    vector<int> divisibilityArray(string word, int m)
    {
        int n = word.length();
        vector<int> arr(n, 0);
        // 设 a = k1 * m + r1, b = k2 * m + r2
        // 那么 (a + b) % m = (r1 + r2) % m = (a % m + b % m) % m
        long long x = 0;
        for (int i = 0; i < n; i++)
        {
            int d = word[i] - '0';
            x = (10 * x + d) % m;
            if (x == 0)
                arr[i] = 1;
        }
        return arr;
    }
};
// @lc code=end

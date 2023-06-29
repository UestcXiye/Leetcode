/*
 * @lc app=leetcode.cn id=1317 lang=cpp
 *
 * [1317] 将整数转换为两个无零整数的和
 */

// @lc code=start
class Solution
{
public:
    vector<int> getNoZeroIntegers(int n)
    {
        for (int A = 1; A < n; A++)
        {
            int B = n - A;
            if ((to_string(A) + to_string(B)).find('0') == string::npos)
                return {A, B};
        }
        return {};
    }
};
// @lc code=end

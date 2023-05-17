/*
 * @lc app=leetcode.cn id=2094 lang=cpp
 *
 * [2094] 找出 3 位偶数
 */

// @lc code=start
class Solution
{
public:
    vector<int> findEvenNumbers(vector<int> &digits)
    {
        int n = digits.size();
        set<int> ans;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    if (i != j && j != k && i != k)
                        if (digits[i] != 0)
                        {
                            int num = 100 * digits[i] + 10 * digits[j] + digits[k];
                            if (num % 2 == 0)
                                ans.insert(num);
                        }
        return vector<int>(ans.begin(), ans.end());
    }
};
// @lc code=end

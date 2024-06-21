/*
 * @lc app=leetcode.cn id=3184 lang=cpp
 *
 * [3184] 构成整天的下标对数目 I
 */

// @lc code=start
class Solution
{
public:
    int countCompleteDayPairs(vector<int> &hours)
    {
        int n = hours.size();
        int count = 0;
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                if ((hours[i] + hours[j]) % 24 == 0)
                    count++;
        return count;
    }
};
// @lc code=end

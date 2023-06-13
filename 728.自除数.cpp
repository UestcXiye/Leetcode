/*
 * @lc app=leetcode.cn id=728 lang=cpp
 *
 * [728] 自除数
 */

// @lc code=start
class Solution
{
public:
    vector<int> selfDividingNumbers(int left, int right)
    {
        vector<int> ans;
        for (int i = left; i <= right; i++)
        {
            int number = i;
            bool judge = true;
            while (number)
            {
                int x = number % 10;
                // 自除数不允许包含0
                if (x == 0 || i % x != 0)
                {
                    judge = false;
                    break;
                }
                number /= 10;
            }
            if (judge)
                ans.push_back(i);
        }
        return ans;
    }
};
// @lc code=end

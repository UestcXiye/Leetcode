/*
 * @lc app=leetcode.cn id=2293 lang=cpp
 *
 * [2293] 极大极小游戏
 */

// @lc code=start
class Solution
{
public:
    int minMaxGame(vector<int> &nums)
    {
        int n = nums.size();
        while (n != 1)
        {
            vector<int> newNums(n / 2);
            for (int i = 0; i < newNums.size(); i++)
            {
                if (i % 2 == 0)
                    newNums[i] = min(nums[2 * i], nums[2 * i + 1]);
                else
                    newNums[i] = max(nums[2 * i], nums[2 * i + 1]);
            }
            nums = newNums;
            n /= 2;
        }
        return nums[0];
    }
};
// @lc code=end

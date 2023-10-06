/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        int max_far = 0; // 目前能跳到的最远位置
        for (int i = 0; i < n; i++)
        {
            if (i <= max_far)
            {
                max_far = max(max_far, i + nums[i]);
                if (max_far >= n - 1)
                    return true;
            }
        }
        return false;
    }
};
// @lc code=end

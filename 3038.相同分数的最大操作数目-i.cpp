/*
 * @lc app=leetcode.cn id=3038 lang=cpp
 *
 * [3038] 相同分数的最大操作数目 I
 */

// @lc code=start
class Solution
{
public:
    int maxOperations(vector<int> &nums)
    {
        if (nums.size() < 2)
            return 0;

        int count = 1;
        int score = nums[0] + nums[1];
        int n = nums.size(), i = 2;

        while (i + 1 < n)
        {
            if (nums[i] + nums[i + 1] == score)
            {
                count++;
                i += 2;
            }
            else
                break;
        }

        return count;
    }
};
// @lc code=end

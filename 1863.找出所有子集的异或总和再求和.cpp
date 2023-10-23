/*
 * @lc app=leetcode.cn id=1863 lang=cpp
 *
 * [1863] 找出所有子集的异或总和再求和
 */

// @lc code=start
class Solution
{
private:
    int xor_sum = 0;

public:
    int subsetXORSum(vector<int> &nums)
    {
        vector<int> comb;
        backtracking(nums, 0, comb);
        return xor_sum;
    }
    // 辅函数 - 回溯算法
    void backtracking(vector<int> &nums, int level, vector<int> &comb)
    {
        if (level == nums.size())
        {
            if (comb.empty())
                return;
            int sum = comb[0];
            for (int i = 1; i < comb.size(); i++)
                sum ^= comb[i];
            xor_sum += sum;
            return;
        }
        comb.push_back(nums[level]);
        backtracking(nums, level + 1, comb);
        comb.pop_back();
        backtracking(nums, level + 1, comb);
    }
};
// @lc code=end

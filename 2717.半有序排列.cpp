/*
 * @lc app=leetcode.cn id=2717 lang=cpp
 *
 * [2717] 半有序排列
 */

// @lc code=start
class Solution
{
public:
    int semiOrderedPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int headIndex, tailIndex;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1)
                headIndex = i;
            if (nums[i] == n)
                tailIndex = i;
        }
        return headIndex + (n - 1 - tailIndex) - (headIndex > tailIndex);
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=3314 lang=cpp
 *
 * [3314] 构造最小位运算数组 I
 */

// @lc code=start
class Solution
{
public:
    vector<int> minBitwiseArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            bool flag = false;
            int x;
            for (x = 0; x < nums[i]; x++)
            {
                if ((x | (x + 1)) == nums[i])
                {
                    flag = true;
                    break;
                }
            }
            ans[i] = flag ? x : -1;
        }

        return ans;
    }
};
// @lc code=end

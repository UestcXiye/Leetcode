/*
 * @lc app=leetcode.cn id=1313 lang=cpp
 *
 * [1313] 解压缩编码列表
 */

// @lc code=start
class Solution
{
public:
    vector<int> decompressRLElist(vector<int> &nums)
    {
        vector<int> ans;
        for (int i = 0; i < nums.size() / 2; i++)
        {
            int freq = nums[2 * i], val = nums[2 * i + 1];
            for (int j = 0; j < freq; j++)
                ans.push_back(val);
        }
        return ans;
    }
};
// @lc code=end

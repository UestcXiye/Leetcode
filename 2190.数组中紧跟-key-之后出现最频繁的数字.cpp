/*
 * @lc app=leetcode.cn id=2190 lang=cpp
 *
 * [2190] 数组中紧跟 key 之后出现最频繁的数字
 */

// @lc code=start
class Solution
{
public:
    int mostFrequent(vector<int> &nums, int key)
    {
        int n = nums.size();
        unordered_map<int, int> freq; // 统计出现次数的哈希表
        for (int i = 0; i < n - 1; i++)
            if (nums[i] == key)
                freq[nums[i + 1]]++;
        // 计算并返回最高频元素
        int maxfreq = 0;
        int res = 0;
        for (const auto &[v, f] : freq)
        {
            if (f > maxfreq)
            {
                res = v;
                maxfreq = f;
            }
        }
        return res;
    }
};
// @lc code=end

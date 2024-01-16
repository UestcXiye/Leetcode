/*
 * @lc app=leetcode.cn id=3005 lang=cpp
 *
 * [3005] 最大频率元素计数
 */

// @lc code=start
class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        // 特判
        if (nums.empty())
            return 0;

        unordered_map<int, int> cnt;
        for (int &num : nums)
            cnt[num]++;

        int max_freq = 0, sum = 0;
        for (auto &[num, freq] : cnt)
        {
            if (freq > max_freq)
            {
                max_freq = freq;
                sum = freq;
            }
            else if (freq == max_freq)
                sum += freq;
        }
        return sum;
    }
};
// @lc code=end

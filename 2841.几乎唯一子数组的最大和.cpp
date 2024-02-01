/*
 * @lc app=leetcode.cn id=2841 lang=cpp
 *
 * [2841] 几乎唯一子数组的最大和
 */

// @lc code=start

// 滑动窗口

class Solution
{
public:
    long long maxSum(vector<int> &nums, int m, int k)
    {
        // 特判
        if (nums.empty() || m > k)
            return 0LL;

        long long max_sum = 0LL;
        vector<int> window;
        unordered_map<int, int> mp;
        long long sum = 0LL;

        for (int i = 0; i < nums.size(); i++)
        {
            window.push_back(nums[i]);
            mp[nums[i]]++;
            sum += nums[i];
            while (window.size() > k)
            {
                auto it = window.begin();
                mp[*it]--;
                if (mp[*it] == 0)
                    mp.erase(*it);
                sum -= *it;
                window.erase(it);
            }
            if (mp.size() >= m)
                max_sum = max(max_sum, sum);
        }
        return max_sum;
    }
};
// @lc code=end

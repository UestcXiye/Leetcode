/*
 * @lc app=leetcode.cn id=2808 lang=cpp
 *
 * [2808] 使循环数组所有元素相等的最少秒数
 */

// @lc code=start
class Solution
{
public:
    int minimumSeconds(vector<int> &nums)
    {
        // 特判
        if (nums.size() <= 1)
            return 0;

        int n = nums.size();
        // mp[x] 表示所有等于 x 的元素下标
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
            mp[nums[i]].push_back(i);

        int ans = INT_MAX;
        for (auto &[_, vec] : mp)
        {
            // 计算最终元素为 x = p.first 的情况下需要的时间
            int max_gap = 0;
            for (int i = 0; i < vec.size(); i++)
            {
                // 计算两个 x 之间的元素数量
                int gap = 0;
                // 注意序列是环形的
                if (i + 1 < vec.size())
                    gap = vec[i + 1] - vec[i] - 1;
                else
                    gap = n - 1 - vec[i] + vec[0];
                max_gap = max(max_gap, gap);
            }
            // 需要的时间，就是元素的最大间隔，除以 2 上取整
            ans = min(ans, (max_gap + 1) / 2);
        }
        return ans;
    }
};
// @lc code=end

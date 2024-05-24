/*
 * @lc app=leetcode.cn id=2653 lang=cpp
 *
 * [2653] 滑动子数组的美丽值
 */

// @lc code=start

// 滑动窗口

class Solution
{
public:
    vector<int> getSubarrayBeauty(vector<int> &nums, int k, int x)
    {
        int n = nums.size();
        vector<int> ans(n - k + 1);
        vector<int> cnt(110, 0);
        for (int i = 0; i < k; i++)
            cnt[nums[i] + 50]++;

        ans[0] = findAns(cnt, x);
        for (int i = k; i < n; i++)
        {
            cnt[nums[i - k] + 50]--;
            cnt[nums[i] + 50]++;
            ans[i - k + 1] = findAns(cnt, x);
        }

        return ans;
    }
    // 辅函数 - 找区间中第 x 小元素的值
    int findAns(vector<int> &cnt, int x)
    {
        for (int i = 0; i < 110; i++)
        {
            x -= cnt[i];
            if (x <= 0)
                return i - 50 < 0 ? i - 50 : 0;
        }
        return 0;
    }
};
// @lc code=end

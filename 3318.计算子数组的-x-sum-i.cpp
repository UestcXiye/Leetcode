/*
 * @lc app=leetcode.cn id=3318 lang=cpp
 *
 * [3318] 计算子数组的 x-sum I
 */

// @lc code=start
class Solution
{
public:
    vector<int> findXSum(vector<int> &nums, int k, int x)
    {
        int n = nums.size();
        vector<int> ans(n - k + 1);

        auto cal_x_sum = [&](int start) -> int
        {
            unordered_map<int, int> cnt;
            for (int i = start; i < start + k; i++)
                cnt[nums[i]]++;

            if (cnt.size() < x)
                return accumulate(nums.begin() + start, nums.begin() + start + k, 0);

            vector<pair<int, int>> vp;
            for (auto &[x, c] : cnt)
                vp.push_back(make_pair(x, c));
            sort(vp.begin(), vp.end(),
                 [&](const pair<int, int> &p1, const pair<int, int> &p2)
                 {
                     if (p1.second != p2.second)
                         return p1.second > p2.second;
                     else
                         return p1.first > p2.first;
                 });

            int sum = 0;
            for (int i = 0; i < x; i++)
                sum += vp[i].first * vp[i].second;
            return sum;
        };

        for (int i = 0; i < ans.size(); i++)
            ans[i] = cal_x_sum(i);

        return ans;
    }
};
// @lc code=end

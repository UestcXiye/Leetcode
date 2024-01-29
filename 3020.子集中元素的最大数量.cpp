/*
 * @lc app=leetcode.cn id=3020 lang=cpp
 *
 * [3020] 子集中元素的最大数量
 */

// @lc code=start
class Solution
{
public:
    int maximumLength(vector<int> &nums)
    {
        // 特判
        if (nums.empty())
            return 0;

        unordered_map<long long, int> cnt;
        for (int &num : nums)
            cnt[num]++;

        // 特判 x=1 的情况
        int ans = cnt[1] - (cnt[1] % 2 == 0);
        cnt.erase(1);

        for (auto &[num, _] : cnt)
        {
            int res = 0;
            long long x;
            for (x = num; cnt.contains(x) && cnt[x] > 1; x *= x)
                res += 2;
            if (cnt.contains(x))
                res++;
            else
                res--;
            ans = max(ans, res);
        }
        return ans;
    }
};
// @lc code=end

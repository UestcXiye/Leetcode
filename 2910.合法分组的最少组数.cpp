/*
 * @lc app=leetcode.cn id=2910 lang=cpp
 *
 * [2910] 合法分组的最少组数
 */

// @lc code=start
class Solution
{
public:
    int minGroupsForValidAssignment(vector<int> &nums)
    {
        unordered_map<int, int> hash; // <value, frequency>
        for (const int &num : nums)
            hash[num]++;
        auto cmp = [](const auto &a, const auto &b) -> bool
        {
            return a.second < b.second;
        };
        int k = min_element(hash.begin(), hash.end(), cmp)->second;
        int ans = 0;
        for (;; k--)
        {
            for (auto &[num, freq] : hash)
            {
                int q = freq / k, r = freq % k;
                if (q < r)
                {
                    ans = 0;
                    break;
                }
                ans += ceil((double)freq / (k + 1));
            }
            if (ans)
                break;
        }
        return ans;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start
class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end(),
             [&](const int &a, const int &b)
             { return to_string(a) + to_string(b) > to_string(b) + to_string(a); });
        string ans;
        for (int &num : nums)
            ans += to_string(num);
        return ans[0] == '0' ? "0" : ans;
    }
};
// @lc code=end

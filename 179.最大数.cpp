/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start
class Solution
{
private:
    static bool cmp(const int &a, const int &b)
    {
        return to_string(a) + to_string(b) > to_string(b) + to_string(a);
    }

public:
    string largestNumber(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end(), cmp);
        string ans;
        for (const int &num : nums)
            ans += to_string(num);
        return ans[0] == '0' ? "0" : ans;
    }
};
// @lc code=end

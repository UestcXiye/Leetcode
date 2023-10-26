/*
 * @lc app=leetcode.cn id=961 lang=cpp
 *
 * [961] 在长度 2N 的数组中找出重复 N 次的元素
 */

// @lc code=start
class Solution
{
public:
    int repeatedNTimes(vector<int> &nums)
    {
        int frq = nums.size() / 2, ans;
        for (int &num : nums)
            if (count(nums.begin(), nums.end(), num) == frq)
            {
                ans = num;
                break;
            }
        return ans;
    }
};
// @lc code=end

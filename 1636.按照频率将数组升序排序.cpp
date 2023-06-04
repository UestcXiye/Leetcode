/*
 * @lc app=leetcode.cn id=1636 lang=cpp
 *
 * [1636] 按照频率将数组升序排序
 */

// @lc code=start
class Solution
{
public:
    vector<int> frequencySort(vector<int> &nums)
    {
        unordered_map<int, int> cnt;
        for (int num : nums)
            cnt[num]++;
        sort(nums.begin(), nums.end(), [&](const int a, const int b)
             {
            if (cnt[a] != cnt[b]) {
                return cnt[a] < cnt[b];
            }
            return a > b; });
        return nums;
    }
};
// @lc code=end

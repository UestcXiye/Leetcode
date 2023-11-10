/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        int left = 0, right = n - 1;
        int ans = -1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            function<pair<int, int>(int)> get = [&](int index) -> pair<int, int>
            {
                if (index == -1 || index == n)
                    return {0, 0};
                return {1, nums[index]};
            };
            if (get(mid - 1) < get(mid) && get(mid) > get(mid + 1))
            {
                ans = mid;
                break;
            }
            if (get(mid) < get(mid + 1))
                left = mid + 1;
            else
                right = mid - 1;
        }
        return ans;
    }
};
// @lc code=end

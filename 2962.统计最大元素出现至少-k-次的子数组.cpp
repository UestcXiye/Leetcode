/*
 * @lc app=leetcode.cn id=2962 lang=cpp
 *
 * [2962] 统计最大元素出现至少 K 次的子数组
 */

// @lc code=start

// 滑动窗口

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        int mx = *max_element(nums.begin(), nums.end());
        long long ans = 0;
        int count_mx = 0, left = 0;
        for (int right = 0; right < nums.size(); right++)
        {
            if (nums[right] == mx)
                count_mx++;
            while (count_mx >= k)
            {
                if (nums[left] == mx)
                    count_mx--;
                left++;
            }
            // [0, right],...,[left-1, right] 是 mx 至少出现 k 次的子数组
            ans += left;
        }
        return ans;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start

// STL

// class Solution
// {
// public:
//     void nextPermutation(vector<int> &nums)
//     {
//         next_permutation(nums.begin(), nums.end());
//     }
// };

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        // 找到较小数 nums[i]，此时 [i+1, n) 必然是下降序列
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1])
            i--;
        if (i >= 0)
        {
            // 在区间 [i+1, n) 中从后向前查找第一个元素 a[j] 满足 a[i]<a[j]，即为较大数
            int j = nums.size() - 1;
            while (j >= 0 && nums[i] >= nums[j])
                j--;
            // 交换 a[i]、a[j]
            swap(nums[i], nums[j]);
        }
        // 区间 [i+1, n) 必为降序，直接反转该区间元素变为升序
        reverse(nums.begin() + i + 1, nums.end());
        // sort(nums.begin() + i + 1, nums.end());
    }
};

// @lc code=end

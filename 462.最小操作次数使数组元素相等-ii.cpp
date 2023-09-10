/*
 * @lc app=leetcode.cn id=462 lang=cpp
 *
 * [462] 最小操作次数使数组元素相等 II
 */

// @lc code=start

// class Solution
// {
// public:
//     int minMoves2(vector<int> &nums)
//     {
//         // 所有元素都变成 nums⌊n/2⌋ 时，所需的移动数最少
//         sort(nums.begin(), nums.end());
//         int n = nums.size(), x = nums[n / 2], ans = 0;
//         for (int &num : nums)
//             ans += abs(num - x);
//         return ans;
//     }
// };

// 快速选择

class Solution
{
private:
    int quickSelect(vector<int> &nums, int left, int right, int index)
    {
        int q = randomPartition(nums, left, right);
        if (q == index)
            return nums[q];
        else
            return q < index ? quickSelect(nums, q + 1, right, index) : quickSelect(nums, left, q - 1, index);
    }

    inline int randomPartition(vector<int> &nums, int left, int right)
    {
        int pos = rand() % (right - left + 1) + left;
        swap(nums[pos], nums[right]);
        return partition(nums, left, right);
    }

    inline int partition(vector<int> &nums, int left, int right)
    {
        int x = nums[right], pos = left - 1;
        for (int j = left; j < right; ++j)
            if (nums[j] <= x)
                swap(nums[++pos], nums[j]);
        swap(nums[pos + 1], nums[right]);
        return pos + 1;
    }

public:
    int minMoves2(vector<int> &nums)
    {
        srand(time(0));
        int n = nums.size();
        int x = quickSelect(nums, 0, n - 1, n / 2), ans = 0;
        for (int i = 0; i < n; ++i)
            ans += abs(nums[i] - x);
        return ans;
    }
};
// @lc code=end

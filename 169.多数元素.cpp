/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
// class Solution
// {
// public:
//     int majorityElement(vector<int> &nums)
//     {
//         int n = nums.size();
//         sort(nums.begin(), nums.end());
//         return nums[n / 2];
//     }
// };

// 摩尔投票算法（Boyer–Moore majority vote algorithm）

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count = 0;
        int candidate = nums[0];
        for (int &num : nums)
        {
            if (count == 0)
                candidate = num;
            if (candidate == num)
                count++;
            else
                count--;
        }
        return candidate;
    }
};

// @lc code=end

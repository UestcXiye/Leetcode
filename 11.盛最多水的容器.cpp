/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start

// Time Limit Exceeded

// class Solution
// {
// public:
//     int maxArea(vector<int> &height)
//     {
//         int max_area = INT_MIN;
//         for (int i = 0; i < height.size() - 1; i++)
//             for (int j = i + 1; j < height.size(); j++)
//                 max_area = max(max_area, min(height[i], height[j]) * (j - i));
//         return max_area;
//     }
// };

// 双指针

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0, right = height.size() - 1;
        int max_area = INT_MIN;
        while (left < right)
        {
            int area = min(height[left], height[right]) * (right - left);
            max_area = max(max_area, area);
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return max_area;
    }
};
// @lc code=end

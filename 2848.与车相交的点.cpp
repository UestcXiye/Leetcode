/*
 * @lc app=leetcode.cn id=2848 lang=cpp
 *
 * [2848] 与车相交的点
 */

// @lc code=start
// class Solution
// {
// public:
//     int numberOfPoints(vector<vector<int>> &nums)
//     {
//         vector<bool> seat(101, false);
//         for (const vector<int> &num : nums)
//         {
//             int start = num[0], end = num[1];
//             for (int i = start; i <= end; i++)
//                 seat[i] = true;
//         }
//         int count = 0;
//         for (int i = 1; i <= 100; i++)
//             if (seat[i])
//                 count++;
//         return count;
//     }
// };

// 差分数组

class Solution
{
public:
    int numberOfPoints(vector<vector<int>> &nums)
    {
        int n = nums.size();
        vector<int> diffArr(102, 0); // 差分数组
        // 构造差分数组
        for (const vector<int> &section : nums)
        {
            int start = section[0], end = section[1];
            diffArr[start] += 1;
            diffArr[end + 1] -= 1;
        }
        int count = 0;
        vector<int> finalArr(101, 0); // 最终数组
        // 还原
        for (int i = 0; i <= 100; i++)
        {
            if (i == 0)
                finalArr[i] = diffArr[0];
            else
                finalArr[i] = finalArr[i - 1] + diffArr[i];
            if (finalArr[i] > 0)
                count++;
        }
        return count;
    }
};
// @lc code=end

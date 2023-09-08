/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start

// 动态规划

class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        // 特判
        if (nums.size() <= 1)
            return nums.size();
        int n = nums.size();
        // 状态数组
        // up[i]：表示以前i个元素中的某一个为结尾的最长的「上升摆动序列」的长度
        vector<int> up(n + 1, 0);
        // down[i]：表示以前i个元素中的某一个为结尾的最长的「下降摆动序列」的长度
        vector<int> down(n + 1, 0);
        // 初始化
        // 对于长度为1的序列，它既是「上升摆动序列」，也是「下降摆动序列」
        up[1] = down[1] = 1;
        // 状态转移
        for (int i = 2; i <= n; i++)
        {
            if (nums[i - 1] > nums[i - 2])
            {
                up[i] = max(up[i - 1], down[i - 1] + 1);
                down[i] = down[i - 1];
            }
            else if (nums[i - 1] < nums[i - 2])
            {
                up[i] = up[i - 1];
                down[i] = max(up[i - 1] + 1, down[i - 1]);
            }
            else
            {
                up[i] = up[i - 1];
                down[i] = down[i - 1];
            }
        }
        return max(up[n], down[n]);
    }
};

// 动态规划-空间优化

// class Solution
// {
// public:
//     int wiggleMaxLength(vector<int> &nums)
//     {
//         // 特判
//         if (nums.size() <= 1)
//             return nums.size();
//         int n = nums.size();
//         int up = 1, down = 1;
//         // 状态转移
//         for (int i = 1; i < n; i++)
//         {
//             if (nums[i] > nums[i - 1])
//                 up = max(up, down + 1);
//             else if (nums[i] < nums[i - 1])
//                 down = max(down, up + 1);
//         }
//         return max(up, down);
//     }
// };

// 贪心

// class Solution
// {
// public:
//     int wiggleMaxLength(vector<int> &nums)
//     {
//         // 特判
//         if (nums.size() <= 1)
//             return nums.size();
//         int n = nums.size();
//         int preDiff = nums[1] - nums[0];
//         int ans = preDiff != 0 ? 2 : 1;
//         for (int i = 2; i < n; i++)
//         {
//             int diff = nums[i] - nums[i - 1];
//             if ((diff > 0 && preDiff <= 0) || (diff < 0 && preDiff >= 0))
//             {
//                 ans++;
//                 preDiff = diff;
//             }
//         }
//         return ans;
//     }
// };

// 贪心2

// class Solution
// {
// public:
//     int wiggleMaxLength(vector<int> &nums)
//     {
//         // 特判
//         if (nums.size() <= 1)
//             return nums.size();
//         int n = nums.size();
//         int direction = 0; //-1表示下降，1表示上升
//         int count = 0;     // 变化次数
//         for (int i = 1; i < n; i++)
//         {
//             if (nums[i] > nums[i - 1])
//             {
//                 if (direction != 1)
//                 {
//                     direction = 1;
//                     count++;
//                 }
//             }
//             else if (nums[i] < nums[i - 1])
//             {
//                 if (direction != -1)
//                 {
//                     direction = -1;
//                     count++;
//                 }
//             }
//         }
//         // 因为统计的是变化的次数，最终的结果是序列的长度，所以需要+1
//         return count + 1;
//     }
// };
// @lc code=end

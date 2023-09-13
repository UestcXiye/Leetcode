/*
 * @lc app=leetcode.cn id=769 lang=cpp
 *
 * [769] 最多能完成排序的块
 */

// @lc code=start

// 贪心

class Solution
{
public:
    int maxChunksToSorted(vector<int> &arr)
    {
        // 特判
        if (arr.empty())
            return 0;
        int block = 0, cur_max = 0, n = arr.size();
        for (int i = 0; i < n; i++)
        {
            cur_max = max(cur_max, arr[i]);
            if (cur_max == i)
                block++;
        }
        return block;
    }
};

// 前缀和

// class Solution
// {
// public:
//     int maxChunksToSorted(vector<int> &arr)
//     {
//         // 特判
//         if (arr.empty())
//             return 0;
//         int arrSum = 0, prefixSum = 0, block = 0;
//         for (int i = 0; i < arr.size(); i++)
//         {
//             arrSum += arr[i];
//             prefixSum += i;
//             if (arrSum == prefixSum)
//                 block++;
//         }
//         return block;
//     }
// };
// @lc code=end

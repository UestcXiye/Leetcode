/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start

// 暴力
// Time Limit Exceeded

// class Solution
// {
// public:
//     int subarraySum(vector<int> &nums, int k)
//     {
//         int n = nums.size(), ans = 0;
//         for (int i = 0; i < n; i++)
//         {
//             int sum = 0;
//             for (int j = i; j < n; j++)
//             {
//                 sum += nums[j];
//                 if (sum == k)
//                     ans++;
//             }
//         }
//         return ans;
//     }
// };

// 前缀和

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        int pSum = 0;
        int ans = 0;
        unordered_map<int, int> hash; //<前缀和，前缀和出现的次数>
        hash[0] = 1;                  // 初始化
        for (int &num : nums)
        {
            pSum += num;
            ans += hash[pSum - k];
            hash[pSum]++;
        }
        return ans;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=594 lang=cpp
 *
 * [594] 最长和谐子序列
 */

// @lc code=start

// 排序 + 枚举

// class Solution
// {
// public:
//     int findLHS(vector<int> &nums)
//     {
//         int n = nums.size();
//         sort(nums.begin(), nums.end());
//         int begin = 0, maxLen = 0;
//         for (int end = 0; end < n; end++)
//         {
//             while (nums[end] - nums[begin] > 1)
//                 begin++;
//             if (nums[end] - nums[begin] == 1)
//                 maxLen = max(maxLen, end - begin + 1);
//         }
//         return maxLen;
//     }
// };

// 哈希

class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        unordered_map<int, int> hash; //<值，出现次数>
        // 把所有数字放到一个哈希表
        for (int &num : nums)
            hash[num]++;
        int maxLen = 0;
        for (auto it = hash.begin(); it != hash.end(); it++)
        {
            int cur = it->first, count_cur = it->second;
            int next = cur + 1;
            if (hash.count(next))
            {
                int count_next = hash[next];
                maxLen = max(maxLen, count_cur + count_next);
            }
        }
        return maxLen;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=2300 lang=cpp
 *
 * [2300] 咒语和药水的成功对数
 */

// @lc code=start
// class Solution
// {
// public:
//     vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
//     {
//         int n = spells.size(), m = potions.size();
//         vector<int> pairs(n, 0);
//         for (int i = 0; i < n; i++)
//         {
//             int count = 0;
//             for (const int &potion : potions)
//                 if ((long long)spells[i] * potion >= success)
//                     count++;
//             pairs[i] = count;
//         }
//         return pairs;
//     }
// };

class Solution
{
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        int n = spells.size(), m = potions.size();
        vector<int> pairs(n, 0);
        sort(potions.begin(), potions.end());
        for (int i = 0; i < n; i++)
        {
            long long target = ceil(1.0 * success / spells[i]);
            int left = 0, right = m - 1;
            while (left <= right)
            {
                int mid = (left + right) / 2;
                if ((long long)spells[i] * potions[mid] >= success)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            pairs[i] = m - left;
        }
        return pairs;
    }
};
// @lc code=end

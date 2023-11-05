/*
 * @lc app=leetcode.cn id=1128 lang=cpp
 *
 * [1128] 等价多米诺骨牌对的数量
 */

// @lc code=start
// class Solution
// {
// public:
//     int numEquivDominoPairs(vector<vector<int>> &dominoes)
//     {
//         int n = dominoes.size(), count = 0;
//         for (int i = 0; i < n - 1; i++)
//             for (int j = i + 1; j < n; j++)
//             {
//                 if (dominoes[i] == dominoes[j] || dominoes[i] == vector<int>(dominoes[j].rbegin(), dominoes[j].rend()))
//                     count++;
//             }
//         return count;
//     }
// };

class Solution
{
public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes)
    {
        int n = dominoes.size();
        map<vector<int>, int> hash;
        for (vector<int> &domino : dominoes)
        {
            sort(domino.begin(), domino.end());
            hash[domino]++;
        }
        int count = 0;
        for (auto it = hash.begin(); it != hash.end(); it++)
        {
            int freq = it->second;
            // 组合：C(n, 2) = n * (n - 1) / 2
            count += freq * (freq - 1) / 2;
        }
        return count;
    }
};
// @lc code=end

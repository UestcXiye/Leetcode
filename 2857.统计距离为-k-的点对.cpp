/*
 * @lc app=leetcode.cn id=2857 lang=cpp
 *
 * [2857] 统计距离为 k 的点对
 */

// @lc code=start

// 暴力

// class Solution
// {
// public:
//     int countPairs(vector<vector<int>> &coordinates, int k)
//     {
//         int n = coordinates.size();

//         int count = 0;
//         for (int i = 0; i < n - 1; i++)
//             for (int j = i + 1; j < n; j++)
//             {
//                 int x1 = coordinates[i][0], y1 = coordinates[i][1];
//                 int x2 = coordinates[j][0], y2 = coordinates[j][1];
//                 int d = (x1 ^ x2) + (y1 ^ y2);
//                 if (d == k)
//                     count++;
//             }

//         return count;
//     }
// };

// 哈希

class Solution
{
public:
    int countPairs(vector<vector<int>> &coordinates, int k)
    {
        int n = coordinates.size();
        unordered_map<long long, int> cnt;
        int count = 0;

        for (vector<int> &coordinate : coordinates)
        {
            int x = coordinate[0], y = coordinate[1];
            // 令 x1 ^ x2 = i，i 的范围为 [0, k]
            for (int i = 0; i <= k; i++)
            {
                // 把 (x, y) 压缩成一个整数，例如 1e6 * x + y
                auto iter = cnt.find(1000000LL * (x ^ i) + (y ^ (k - i)));
                if (iter != cnt.end())
                    count += iter->second;
            }
            cnt[1000000LL * x + y]++;
        }

        return count;
    }
};
// @lc code=end

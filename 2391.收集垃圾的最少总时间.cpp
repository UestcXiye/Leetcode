/*
 * @lc app=leetcode.cn id=2391 lang=cpp
 *
 * [2391] 收集垃圾的最少总时间
 */

// @lc code=start
// class Solution
// {
// public:
//     int garbageCollection(vector<string> &garbage, vector<int> &travel)
//     {
//         int n = garbage.size();
//         int sum = 0;
//         vector<int> last(3, -1); // m、p、g 最后出现的下标
//         for (int i = 0; i < n; i++)
//         {
//             string gar = garbage[i];
//             sum += gar.length(); // 收拾垃圾的时间
//             int m = 0, p = 0, g = 0;
//             for (char &c : gar)
//             {
//                 if (c == 'M')
//                     last[0] = i;
//                 else if (c == 'P')
//                     last[1] = i;
//                 else
//                     last[2] = i;
//             }
//         }
//         // 路径长度前缀和
//         vector<int> pre(n, 0);
//         for (int i = 1; i < n; i++)
//             pre[i] = pre[i - 1] + travel[i - 1];
//         for (int i = 0; i < 3; i++)
//             if (last[i] != -1)
//                 sum += pre[last[i]] - pre[0]; // 行驶的时间
//         return sum;
//     }
// };

// 一次遍历

class Solution
{
public:
    int garbageCollection(vector<string> &garbage, vector<int> &travel)
    {
        int n = garbage.size();
        int sum = garbage[0].length();
        int time = 0; // 行驶时间
        // 每辆垃圾车的行驶时间
        unordered_map<char,int> drive;
        for (int i = 1; i < n; i++)
        {
            string gar = garbage[i];
            sum += gar.length(); // 收拾垃圾的时间
            time += travel[i - 1];
            for (char &c : gar)
            {
                // 更新垃圾对应垃圾车的行驶时间
                sum += time - drive[c];
                drive[c] = time;
            }
        }
        return sum;
    }
};
// @lc code=end

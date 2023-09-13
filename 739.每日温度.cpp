/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start

// 暴力
// Time Limit Exceeded

// class Solution
// {
// public:
//     vector<int> dailyTemperatures(vector<int> &temperatures)
//     {
//         int n = temperatures.size();
//         vector<int> answer(n, 0);
//         for (int i = 0; i < n - 1; i++)
//         {
//             int j = i + 1;
//             while (j < n && temperatures[i] >= temperatures[j])
//                 j++;
//             answer[i] = j == n ? 0 : j - i;
//         }
//         return answer;
//     }
// };

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<int> indices;
        for (int i = 0; i < n; i++)
        {
            while (!indices.empty())
            {
                int preIndex = indices.top();
                if (temperatures[i] <= temperatures[preIndex])
                    break;
                indices.pop();
                answer[preIndex] = i - preIndex;
            }
            indices.push(i);
        }
        return answer;
    }
};
// @lc code=end

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

// 单调栈-从左到右

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
            int cur = temperatures[i];
            // 当前温度>栈顶下标的温度
            while (!indices.empty() && cur > temperatures[indices.top()])
            {
                // 取出栈顶元素，更新对应下标的间隔天数
                int j = indices.top();
                indices.pop();
                answer[j] = i - j;
            }
            indices.push(i);
        }
        return answer;
    }
};

// 单调栈-从右到左

// class Solution
// {
// public:
//     vector<int> dailyTemperatures(vector<int> &temperatures)
//     {
//         int n = temperatures.size();
//         vector<int> ans(n);
//         stack<int> st;
//         for (int i = n - 1; i >= 0; i--)
//         {
//             int t = temperatures[i];
//             // 当前温度大于等于之前的最大温度，小于等于当前温度的栈中温度全部全掉
//             while (!st.empty() && t >= temperatures[st.top()])
//                 st.pop();
//             if (!st.empty())
//                 ans[i] = st.top() - i;
//             st.push(i);
//         }
//         return ans;
//     }
// };
// @lc code=end

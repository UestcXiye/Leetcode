/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start

// 前后缀分解

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        // pre_max[i] 表示从 height[0] 到 height[i] 的最大值
        vector<int> pre_max(n);
        pre_max[0] = height[0];
        for (int i = 1; i < n; i++)
            pre_max[i] = max(pre_max[i - 1], height[i]);
        // suf_max[i] 表示从 height[i] 到 height[n-1] 的最大值
        vector<int> suf_max(n);
        suf_max[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
            suf_max[i] = max(suf_max[i + 1], height[i]);

        // 将接雨水视为一个个底边长度为 1 的水桶，
        // 水桶的高度是 min(pre_max[i], suf_max[i]) - height[i]
        // 水桶的宽度为 1，接水量为两者的乘积
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += min(pre_max[i], suf_max[i]) - height[i];
        return sum;
    }
};

// 相向双指针

// class Solution
// {
// public:
//     int trap(vector<int> &height)
//     {
//         int n = height.size();
//         int left = 0, right = n - 1;
//         // pre_max 表示前缀最大值，suf_max 表示后缀最大值
//         int pre_max = 0, suf_max = 0;
//         int sum = 0;

//         while (left < right)
//         {
//             // 更新前后缀最大值
//             pre_max = max(pre_max, height[left]);
//             suf_max = max(suf_max, height[right]);
//             if (pre_max < suf_max)
//             {
//                 sum += pre_max - height[left];
//                 left++;
//             }
//             else
//             {
//                 sum += suf_max - height[right];
//                 right--;
//             }
//         }

//         return sum;
//     }
// };

// 单调栈

// class Solution
// {
// public:
//     int trap(vector<int> &height)
//     {
//         int ans = 0;
//         stack<int> st;
//         for (int i = 0; i < height.size(); i++)
//         {
//             while (!st.empty() && height[i] >= height[st.top()])
//             {
//                 int bottom_h = height[st.top()];
//                 st.pop();
//                 if (st.empty())
//                     break;
//                 int left = st.top();
//                 // 面积的高和宽
//                 int dh = min(height[left], height[i]) - bottom_h;
//                 int dw = i - left - 1;
//                 ans += dh * dw;
//             }
//             st.push(i);
//         }
//         return ans;
//     }
// };

// @lc code=end

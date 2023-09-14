/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start

// 单调栈 + 循环数组

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> answer(n, -1);
        stack<int> indices;
        // 把这个循环数组「拉直」，即复制该序列的前 n-1 个元素拼接在原序列的后面
        for (int i = 0; i < 2 * n - 1; i++)
        {
            while (!indices.empty())
            {
                int preIndex = indices.top();
                if (nums[i % n] <= nums[preIndex])
                    break;
                indices.pop();
                answer[preIndex] = nums[i % n];
            }
            indices.push(i % n);
        }
        return answer;
    }
};
// @lc code=end

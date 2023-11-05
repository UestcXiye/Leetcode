/*
 * @lc app=leetcode.cn id=1299 lang=cpp
 *
 * [1299] 将每个元素替换为右侧最大元素
 */

// @lc code=start
class Solution
{
public:
    vector<int> replaceElements(vector<int> &arr)
    {
        int n = arr.size();
        int max_right_element = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            int num = arr[i];
            arr[i] = max_right_element;
            max_right_element = max(max_right_element, num);
        }
        return arr;
    }
};
// @lc code=end

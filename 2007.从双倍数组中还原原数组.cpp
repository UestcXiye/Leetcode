/*
 * @lc app=leetcode.cn id=2007 lang=cpp
 *
 * [2007] 从双倍数组中还原原数组
 */

// @lc code=start
class Solution
{
public:
    vector<int> findOriginalArray(vector<int> &changed)
    {
        if (changed.size() % 2)
            return {};

        sort(changed.begin(), changed.end());
        unordered_multiset<int> mark;
        vector<int> ans;
        for (int &x : changed)
        {
            auto it = mark.find(x);
            if (it == mark.end()) // x 不是双倍后的元素
            {
                ans.push_back(x);
                // 标记一个双倍元素
                mark.insert(2 * x);
            }
            else // x 是双倍后的元素
            {
                // 清除一个标记
                mark.erase(it);
            }
        }
        // 只有所有双倍标记都被清除掉，才能说明 changed 是一个双倍数组
        return mark.empty() ? ans : vector<int>{};
    }
};
// @lc code=end

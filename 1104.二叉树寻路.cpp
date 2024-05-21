/*
 * @lc app=leetcode.cn id=1104 lang=cpp
 *
 * [1104] 二叉树寻路
 */

// @lc code=start
class Solution
{
private:
    int getBegin(int level)
    {
        return pow(2, level);
    }
    int getEnd(int level)
    {
        return pow(2, level + 1) - 1;
    }

public:
    vector<int> pathInZigZagTree(int label)
    {
        // 对于满二叉树，节点 i 的父节点是 i/2
        vector<int> ans;
        // 构建正常的二叉树路径
        ans.insert(ans.begin(), label);
        while (label > 1)
        {
            ans.insert(ans.begin(), label / 2);
            label /= 2;
        }
        int n = ans.size();
        for (int i = n - 2; i >= 0; i -= 2)
        { // 对变换位置的行中的结点进行调整
            ans[i] = getBegin(i) + getEnd(i) - ans[i];
        }
        return ans;
    }
};
// @lc code=end

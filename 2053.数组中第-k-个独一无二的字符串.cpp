/*
 * @lc app=leetcode.cn id=2053 lang=cpp
 *
 * [2053] 数组中第 K 个独一无二的字符串
 */

// @lc code=start
class Solution
{
public:
    string kthDistinct(vector<string> &arr, int k)
    {
        unordered_map<string, int> umap;
        for (string s : arr)
            umap[s]++;
        for (string s : arr)
            if (umap[s] == 1)
            {
                k--;
                if (k == 0)
                    return s;
            }
        return "";
    }
};
// @lc code=end

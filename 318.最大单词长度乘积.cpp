/*
 * @lc app=leetcode.cn id=318 lang=cpp
 *
 * [318] 最大单词长度乘积
 */

// @lc code=start

// 为每个字母串建立一个长度为 26 的二进制数字，每个位置表示是否存在该字母。
// 如果两个字母串含有重复数字，那它们的二进制表示的按位与不为 0。

class Solution
{
public:
    int maxProduct(vector<string> &words)
    {
        unordered_map<int, int> hash;
        int ans = 0;
        for (string &word : words)
        {
            int len = word.size();
            int mask = 0;
            for (char &c : word)
                mask |= 1 << (c - 'a');
            hash[mask] = max(hash[mask], len);
            for (auto &[h_mask, h_len] : hash)
                if ((h_mask & mask) == 0)
                    ans = max(ans, len * h_len);
        }
        return ans;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=3085 lang=cpp
 *
 * [3085] 成为 K 特殊字符串需要删除的最少字符数
 */

// @lc code=start
class Solution
{
public:
    int minimumDeletions(string word, int k)
    {
        unordered_map<char, int> mp;
        for (char &c : word)
            mp[c]++;
        vector<int> freq;
        for (auto &[ch, cnt] : mp)
            freq.push_back(cnt);
        sort(freq.begin(), freq.end());

        int min_del = INT_MAX;
        int front_sub = 0; // 前置差用来存储较小，并且需要减去的数
        for (int &f : freq)
        {
            int upper = f + k;
            int back_sub = 0; // 后置差用来存储后面较大数据需要减去的数
            for (int &j : freq)
                if (j > upper)
                    back_sub += j - upper;
            min_del = min(min_del, front_sub + back_sub);
            // 如果以后面一个大一点的数为最小值，此时前置差就得加上当前这个数
            front_sub += f;
        }
        return min_del;
    }
};
// @lc code=end
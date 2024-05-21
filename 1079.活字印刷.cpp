/*
 * @lc app=leetcode.cn id=1079 lang=cpp
 *
 * [1079] 活字印刷
 */

// @lc code=start
class Solution
{
public:
    int numTilePossibilities(string tiles)
    {
        int n = tiles.length();
        unordered_map<char, int> cnt;
        set<char> alpha;
        for (char &c : tiles)
        {
            cnt[c]++;
            alpha.insert(c);
        }
        function<int(int)> backtrack = [&](int pos) -> int
        {
            if (pos >= n)
                return 1;
            int res = 1;
            for (const char &c : alpha)
                if (cnt[c] > 0)
                {
                    cnt[c]--;
                    res += backtrack(pos + 1);
                    cnt[c]++;
                }
            return res;
        };
        // 因为题目要求返回非空字符串的数目，所以结果还要减一
        return backtrack(0) - 1;
    }
};
// @lc code=end

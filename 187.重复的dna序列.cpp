/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 */

// @lc code=start
class Solution
{
private:
    const int LEN = 10;

public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        // 特判
        if (s.size() <= 10)
            return {};
        unordered_map<string, int> hash;
        set<string> sequences;
        for (int i = 0; i <= s.size() - LEN; i++)
        {
            string temp = s.substr(i, LEN);
            hash[temp]++;
            if (hash[temp] >= 2)
                sequences.insert(temp);
        }
        return vector<string>(sequences.begin(), sequences.end());
    }
};
// @lc code=end

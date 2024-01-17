/*
 * @lc app=leetcode.cn id=3008 lang=cpp
 *
 * [3008] 找出数组中的美丽下标 II
 */

// @lc code=start

// KMP + 二分查找

class Solution
{
public:
    vector<int> beautifulIndices(string s, string a, string b, int k)
    {
        vector<int> posA = kmp(s, a);
        vector<int> posB = kmp(s, b);

        vector<int> ans;

        // 二分查找
        // for (int i : posA)
        // {
        //     auto it = lower_bound(posB.begin(), posB.end(), i);
        //     if (it != posB.end() && *it - i <= k ||
        //         it != posB.begin() && i - *--it <= k)
        //     {
        //         ans.push_back(i);
        //     }
        // }

        // 双指针
        int j = 0, m = posB.size();
        for (int i : posA)
        {
            while (j < m && posB[j] < i - k)
                j++;
            if (j < m && posB[j] <= i + k)
                ans.push_back(i);
        }

        return ans;
    }
    // 辅函数 - KMP
    vector<int> kmp(string &text, string &pattern)
    {
        int m = pattern.length();
        vector<int> nxt = getNxt(pattern);
        vector<int> res;
        int tar = 0; // 主串中将要匹配的位置
        int pos = 0; // 模式串中将要匹配的位置
        while (tar < text.length())
        {
            if (text[tar] == pattern[pos])
            {
                // 若两个字符相等，则 tar、pos 各进一步
                tar++;
                pos++;
            }
            else if (pos != 0)
            {
                // 失配，如果 pos != 0，则依据 nxt 移动标尺
                pos = nxt[pos - 1];
            }
            else
            {
                // pos[0] 失配，标尺右移一位
                tar++;
            }

            // pos 走到了 pattern.length()，匹配成功
            if (pos == pattern.length())
            {
                // 保存主串上的匹配起点
                res.push_back(tar - pos);
                // 移动标尺
                pos = nxt[pos - 1];
            }
        }
        return res;
    }
    // 辅函数 - 计算 nxt 数组
    // vector<int> getNxt(string &pattern)
    // {
    //     int m = pattern.length();
    //     vector<int> nxt(m, 0);
    //     for (int i = 0; i < m; i++)
    //     {
    //         string sub = pattern.substr(0, i + 1);
    //         for (int j = sub.length() - 1; j >= 0; j--)
    //         {
    //             string prev = sub.substr(0, j);
    //             string suf = sub.substr(sub.length() - j, j);
    //             if (prev == suf)
    //             {
    //                 nxt[i] = j;
    //                 break;
    //             }
    //         }
    //     }
    //     return nxt;
    // }
    vector<int> getNxt(string &pattern)
    {
        vector<int> nxt;
        // next[0] 必然是 0
        nxt.push_back(0);
        // 从 next[1] 开始求
        int x = 1, now = 0;
        while (x < pattern.length())
        {
            if (pattern[now] == pattern[x])
            {
                // 如果 pattern[now] == pattern[x]，向右拓展一位
                now++;
                x++;
                nxt.push_back(now);
            }
            else if (now != 0)
            {
                // 缩小 now，改成 nxt[now - 1]
                now = nxt[now - 1];
            }
            else
            {
                // now 已经为 0，无法再缩小，故 next[x] = 0
                nxt.push_back(0);
                x++;
            }
        }
        return nxt;
    }
};
// @lc code=end

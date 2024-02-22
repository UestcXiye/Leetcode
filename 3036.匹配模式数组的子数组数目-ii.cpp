/*
 * @lc app=leetcode.cn id=3036 lang=cpp
 *
 * [3036] 匹配模式数组的子数组数目 II
 */

// @lc code=start

// Z 函数（扩展 KMP）

class Solution
{
public:
    int countMatchingSubarrays(vector<int> &nums, vector<int> &pattern)
    {
        int m = pattern.size();

        // 为了防止匹配越界，中间插入一个不在数组中的数字
        pattern.push_back(2);

        for (int i = 1; i < nums.size(); i++)
        {
            int x = nums[i - 1], y = nums[i];
            // if (x < y)
            //     pattern.push_back(1);
            // else if (x == y)
            //     pattern.push_back(0);
            // else
            //     pattern.push_back(-1);
            pattern.push_back((y > x) - (y < x));
        }

        int n = pattern.size();
        vector<int> z(n);

        int l = 0, r = 0; // Z box 的左右边界
        for (int i = 1; i < n; i++)
        {
            if (i <= r) // i 在 Z box 内
            {
                z[i] = min(z[i - l], r - i + 1);
            }
            // 继续向后暴力匹配
            while (i + z[i] < n && pattern[z[i]] == pattern[i + z[i]])
            {
                l = i;
                r = i + z[i];
                z[i]++;
            }
        }

        int ans = 0;
        for (int i = m + 1; i < n; i++)
        {
            if (z[i] >= m)
                ans++;
        }

        return ans;
    }
};

// KMP

// class Solution
// {
// private:
//     // KMP 算法
//     vector<int> getNxt(string &pattern)
//     {
//         vector<int> nxt;
//         // next[0] 必然是 0
//         nxt.push_back(0);
//         // 从 next[1] 开始求
//         int x = 1, now = 0;
//         while (x < pattern.length())
//         {
//             if (pattern[now] == pattern[x])
//             {
//                 // 如果 pattern[now] == pattern[x]，向右拓展一位
//                 now++;
//                 x++;
//                 nxt.push_back(now);
//             }
//             else if (now != 0)
//             {
//                 // 缩小 now，改成 nxt[now - 1]
//                 now = nxt[now - 1];
//             }
//             else
//             {
//                 // now 已经为 0，无法再缩小，故 next[x] = 0
//                 nxt.push_back(0);
//                 x++;
//             }
//         }
//         return nxt;
//     }

//     vector<int> kmp(string &s, string &pattern)
//     {
//         int m = pattern.length();
//         vector<int> nxt = getNxt(pattern);
//         vector<int> res;
//         int tar = 0; // 主串中将要匹配的位置
//         int pos = 0; // 模式串中将要匹配的位置
//         while (tar < s.length())
//         {
//             if (s[tar] == pattern[pos])
//             {
//                 // 若两个字符相等，则 tar、pos 各进一步
//                 tar++;
//                 pos++;
//             }
//             else if (pos != 0)
//             {
//                 // 失配，如果 pos != 0，则依据 nxt 移动标尺
//                 pos = nxt[pos - 1];
//             }
//             else
//             {
//                 // pos[0] 失配，标尺右移一位
//                 tar++;
//             }

//             if (pos == pattern.length())
//             {
//                 res.push_back(tar - pos);
//                 pos = nxt[pos - 1];
//             }
//         }
//         return res;
//     }

// public:
//     int countMatchingSubarrays(vector<int> &nums, vector<int> &pattern)
//     {
//         // 特判
//         if (nums.empty() || pattern.empty())
//             return 0;
//         if (nums.size() <= pattern.size())
//             return 0;

//         int count = 0;
//         int m = nums.size(), n = pattern.size();

//         // 1 对应 'a'，0 对应 'b'，-1 对应 'c'
//         string s;
//         for (int i = 0; i < m - 1; i++)
//         {
//             int diff = nums[i + 1] - nums[i];
//             int p = getPattern(diff);
//             if (p == 1)
//                 s += "a";
//             else if (p == 0)
//                 s += "b";
//             else
//                 s += "c";
//         }

//         string p;
//         for (int &pa : pattern)
//         {
//             if (pa == 1)
//                 p += "a";
//             else if (pa == 0)
//                 p += "b";
//             else
//                 p += "c";
//         }

//         return kmp(s, p).size();
//     }
//     // 辅函数 - 计算 pattern
//     int getPattern(int diff)
//     {
//         if (diff == 0)
//             return 0;
//         return diff > 0 ? 1 : -1;
//     }
// };
// @lc code=end

/*
 * @lc app=leetcode.cn id=331 lang=cpp
 *
 * [331] 验证二叉树的前序序列化
 */

// @lc code=start

class Solution
{
public:
    bool isValidSerialization(string preorder)
    {
        vector<string> vec = split(preorder, ',');
        // 用栈模拟
        vector<string> stk;
        for (string &v : vec)
        {
            stk.push_back(v);
            int sz = stk.size();
            // 遇到数字+#+#，说明遇到了一个叶子节点，替换成#
            while (sz >= 3 && stk[sz - 1] == "#" && stk[sz - 2] == "#" && stk[sz - 3] != "#")
            {
                stk.pop_back();
                stk.pop_back();
                stk.pop_back();
                stk.push_back("#");
                sz = stk.size();
            }
        }
        // 如果最后模拟栈中只剩一个 #，说明是合法的序列
        return stk.size() == 1 && *stk.begin() == "#";
    }
    // bool isValidSerialization(string preorder)
    // {
    //     // 性质 1：空节点个数 = 非空节点个数 + 1
    //     // 性质 2：在遍历完之前，非空节点个数不会大于空结点个数
    //     vector<string> vec = split(preorder, ',');
    //     int n = vec.size();
    //     int node = 0, empty = 0;
    //     for (int i = 0; i < n; i++)
    //     {
    //         if (vec[i] == "#")
    //             empty++;
    //         else
    //             node++;
    //         if (empty > node && i != n - 1)
    //             return false;
    //     }
    //     return node + 1 == empty;
    // }
    // 辅函数 - 按字符 delim 分割字符串 s
    vector<string> split(const string &s, char delim)
    {
        vector<string> v;
        string cur;
        for (const char &c : s)
        {
            if (c == delim)
            {
                v.push_back(cur);
                cur.clear();
            }
            else
                cur += c;
        }
        v.push_back(cur);
        return v;
    }
};
// @lc code=end

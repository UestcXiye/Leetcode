/*
 * @lc app=leetcode.cn id=2696 lang=cpp
 *
 * [2696] 删除子串后的字符串最小长度
 */

// @lc code=start

class Solution
{
public:
    int minLength(string s)
    {
        // 先查询原始字符串中是否存在子字符串AB或CD
        int IndexAB = s.find("AB"), indexCD = s.find("CD");
        string temp = s;
        // 如果还能找到AB或CD子字符串，则循环继续
        while (IndexAB != -1 || indexCD != -1)
        {
            if (IndexAB != -1)
            {
                // 如果找到子字符串AB，则将其从原始字符串中删除
                temp = s.substr(0, IndexAB) + s.substr(IndexAB + 2);
            }
            // 为了防止上面删除AB字符串后，原本CD字符串的为值发生改变，此处重新计算
            indexCD = temp.find("CD");
            if (indexCD != -1)
            {
                // 如果找到子字符串CD，则将其从原始字符串中删除
                temp = temp.substr(0, indexCD) + temp.substr(indexCD + 2);
            }
            IndexAB = temp.find("AB");
            indexCD = temp.find("CD");
            s = temp;
        }
        return s.size();
    }
};
// @lc code=end

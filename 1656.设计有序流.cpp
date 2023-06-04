/*
 * @lc app=leetcode.cn id=1656 lang=cpp
 *
 * [1656] 设计有序流
 */

// @lc code=start
class OrderedStream
{
private:
    vector<string> stream;
    int ptr;

public:
    OrderedStream(int n)
    {
        stream.resize(n + 1);
        ptr = 1;
    }

    vector<string> insert(int idKey, string value)
    {
        stream[idKey] = value;
        vector<string> res;
        while (ptr < stream.size() && !stream[ptr].empty())
        {
            res.push_back(stream[ptr]);
            ptr++;
        }
        return res;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
// @lc code=end

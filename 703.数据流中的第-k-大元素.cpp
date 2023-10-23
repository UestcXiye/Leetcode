/*
 * @lc app=leetcode.cn id=703 lang=cpp
 *
 * [703] 数据流中的第 K 大元素
 */

// @lc code=start
class KthLargest
{
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    KthLargest(int k, vector<int> &nums)
    {
        this->k = k;
        for (int &num : nums)
            pq.push(num);
        updatePriorityQueue();
    }

    int add(int val)
    {
        pq.push(val);
        updatePriorityQueue();
        return pq.top();
    }

    void updatePriorityQueue()
    {
        while (pq.size() > k)
            pq.pop();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end

/*
 * @lc app=leetcode.cn id=307 lang=cpp
 *
 * [307] 区域和检索 - 数组可修改
 */

// @lc code=start

// 线段树

class NumArray
{
private:
    vector<int> segmentTree;
    int n;
    // 建树
    void build(int node, int s, int e, vector<int> &nums)
    {
        if (s == e)
        {
            segmentTree[node] = nums[s];
            return;
        }
        int mid = s + (e - s) / 2;
        build(node * 2 + 1, s, mid, nums);
        build(node * 2 + 2, mid + 1, e, nums);
        segmentTree[node] = segmentTree[node * 2 + 1] + segmentTree[node * 2 + 2];
    }
    // 单点修改
    void change(int index, int val, int node, int s, int e)
    {
        if (s == e)
        {
            segmentTree[node] = val;
            return;
        }
        int mid = s + (e - s) / 2;
        if (index <= mid)
            change(index, val, node * 2 + 1, s, mid);
        else
            change(index, val, node * 2 + 2, mid + 1, e);
        segmentTree[node] = segmentTree[node * 2 + 1] + segmentTree[node * 2 + 2];
    }
    // 范围求和
    int range(int left, int right, int node, int s, int e)
    {
        if (left == s && right == e)
            return segmentTree[node];
        int mid = s + (e - s) / 2;
        if (right <= mid)
            return range(left, right, node * 2 + 1, s, mid);
        else if (left > mid)
            return range(left, right, node * 2 + 2, mid + 1, e);
        else
            return range(left, mid, node * 2 + 1, s, mid) + range(mid + 1, right, node * 2 + 2, mid + 1, e);
    }

public:
    NumArray(vector<int> &nums) : n(nums.size()), segmentTree(nums.size() * 4)
    {
        build(0, 0, n - 1, nums);
    }

    void update(int index, int val)
    {
        change(index, val, 0, 0, n - 1);
    }

    int sumRange(int left, int right)
    {
        return range(left, right, 0, 0, n - 1);
    }
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end

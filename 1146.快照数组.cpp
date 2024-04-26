/*
 * @lc app=leetcode.cn id=1146 lang=cpp
 *
 * [1146] 快照数组
 */

// @lc code=start
class SnapshotArray
{
private:
    // 当前 snap_id
    int cur_snap_id = 0;
    // 每个 index 的历史修改记录
    unordered_map<int, vector<pair<int, int>>> history;

public:
    SnapshotArray(int length)
    {
    }

    void set(int index, int val)
    {
        auto p = pair<int, int>(cur_snap_id, val);
        history[index].push_back(p);
    }

    int snap()
    {
        return cur_snap_id++;
    }

    int get(int index, int snap_id)
    {
        auto &h = history[index];
        // 找快照编号 <= snap_id 的最后一次修改记录
        // 等价于找快照编号 >= snap_id+1 的第一个修改记录，它的上一个就是答案
        pair<int, int> p = {snap_id + 1, -1};
        int j = lower_bound(h.begin(), h.end(), p) - h.begin() - 1;
        return j >= 0 ? h[j].second : 0;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
// @lc code=end

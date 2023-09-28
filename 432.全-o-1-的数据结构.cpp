/*
 * @lc app=leetcode.cn id=432 lang=cpp
 *
 * [432] 全 O(1) 的数据结构
 */

// @lc code=start
class AllOne
{
    // 链表中的每个节点存储一个字符串集合 keys，和一个正整数 count，表示 keys 中中的字符串均出现 count 次
    list<pair<unordered_set<string>, int>> lst;
    // 维护每个字符串当前所处的链表节点
    unordered_map<string, list<pair<unordered_set<string>, int>>::iterator> nodes;

public:
    AllOne() {}

    void inc(string key)
    {
        if (nodes.count(key))
        {
            // 设 key 所在节点为 cur
            auto cur = nodes[key], nxt = next(cur);
            if (nxt == lst.end() || nxt->second > cur->second + 1)
            {
                // 先插入一个 count = cur.count + 1 的新节点至 cur 之后
                unordered_set<string> s({key});
                nodes[key] = lst.emplace(nxt, s, cur->second + 1);
            }
            else
            {
                nxt->first.emplace(key);
                nodes[key] = nxt;
            }
            // 将 key 从 cur.keys 中移除
            cur->first.erase(key);
            // 若移除后 cur.keys 为空，则将 cur 从链表中移除。
            if (cur->first.empty())
                lst.erase(cur);
        }
        else // key 不在链表中
        {
            // 若链表为空或头节点的 count > 1
            if (lst.empty() || lst.begin()->second > 1)
            {
                // 先插入一个 count = 1 的新节点至链表头部
                unordered_set<string> s({key});
                lst.emplace_front(s, 1);
            }
            else
            {
                // 直接将 key 插入到链表头节点的字符串集合 keys 中
                lst.begin()->first.emplace(key);
            }
            // 更新 nodes 中 key 所处的节点
            nodes[key] = lst.begin();
        }
    }

    void dec(string key)
    {
        auto cur = nodes[key];
        if (cur->second == 1)
        {
            // key 仅出现一次，将其移出 nodes
            nodes.erase(key);
        }
        else
        {
            auto pre = prev(cur);
            if (cur == lst.begin() || pre->second < cur->second - 1)
            {
                // 先插入一个 count = cur.count - 1 的新节点至 cur 之前
                // 再更新 nodes 中 key 所处的节点
                unordered_set<string> s({key});
                nodes[key] = lst.emplace(cur, s, cur->second - 1);
            }
            else
            {
                pre->first.emplace(key);
                nodes[key] = pre;
            }
        }
        // 将 key 从 cur.keys 中移除
        cur->first.erase(key);
        // 若移除后 cur.keys 为空，则将 cur 从链表中移除。
        if (cur->first.empty())
            lst.erase(cur);
    }

    string getMaxKey()
    {
        // 在链表不为空时，返回链表尾节点的 keys 中的第一个元素
        return lst.empty() ? "" : *lst.rbegin()->first.begin();
    }

    string getMinKey()
    {
        // 在链表不为空时，返回链表头节点的 keys 中的第一个元素
        return lst.empty() ? "" : *lst.begin()->first.begin();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
// @lc code=end

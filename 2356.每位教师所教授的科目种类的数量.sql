--
-- @lc app=leetcode.cn id=2356 lang=mysql
--
-- [2356] 每位教师所教授的科目种类的数量
--

-- @lc code=start
# Write your MySQL query statement below
SELECT teacher_id, COUNT(DISTINCT subject_id) AS cnt FROM Teacher
GROUP BY teacher_id;
-- @lc code=end


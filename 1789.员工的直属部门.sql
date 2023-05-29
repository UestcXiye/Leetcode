--
-- @lc app=leetcode.cn id=1789 lang=mysql
--
-- [1789] 员工的直属部门
--

-- @lc code=start
# Write your MySQL query statement below
SELECT employee_id, department_id
FROM employee
GROUP BY employee_id
HAVING COUNT(department_id) = 1
UNION
SELECT employee_id, department_id
FROM employee
WHERE primary_flag = 'Y'
-- @lc code=end


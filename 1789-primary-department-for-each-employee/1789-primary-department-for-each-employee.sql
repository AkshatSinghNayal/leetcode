SELECT employee_id, department_id
FROM (
    SELECT
        employee_id,
        department_id,
        primary_flag,
        COUNT(*) OVER (PARTITION BY employee_id) AS cnt
    FROM Employee
) t
WHERE cnt = 1
   OR primary_flag = 'Y';

WITH temp AS (
    SELECT
        employee_id,
        department_id,
        primary_flag,
        COUNT(*) OVER (PARTITION BY employee_id) AS ele_count
    FROM Employee
)
SELECT
    employee_id,
    department_id
FROM temp
WHERE ele_count = 1
   OR primary_flag = 'Y';

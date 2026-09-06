WITH employee_count AS (
    SELECT employee_id, COUNT(*) AS cnt
    FROM Employee
    GROUP BY employee_id
)

select e.employee_id , d.department_id
from employee_count as e 
left join Employee as d 
on e.employee_id = d.employee_id
where e.cnt = 1 or d.primary_flag = 'Y'
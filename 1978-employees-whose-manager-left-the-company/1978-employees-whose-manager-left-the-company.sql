with temp as(
    select *
from Employees
where salary < 30000
)

select t.employee_id
from temp  as t 
left join Employees as e
on t.manager_id = e.employee_id
where e.employee_id is null and t.manager_id is not null
order by t.employee_id

with temp as (
    select d.name as Department , e.name as Employee , e.salary  as Salary, 
    dense_rank() over(
        partition by d.name
        order by e.salary desc 
    ) as rnk
    from Employee as e 
    left join Department as d 
    on e.departmentId = d.id
)

select Department,Employee, Salary
from temp 
where rnk <= 3
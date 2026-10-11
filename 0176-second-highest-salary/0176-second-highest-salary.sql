with sec as (
    select salary ,dense_rank() over(
        order by salary desc
    ) as rnk
    from Employee
)

select max(salary) as "SecondHighestSalary"
from sec
where rnk = 2
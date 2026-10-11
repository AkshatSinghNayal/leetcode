with sec as (
    select salary ,dense_rank() over(
        order by salary desc
    ) as rnk
    from Employee
)

select case when count(*) >= 1 then salary else null end as "SecondHighestSalary"
from sec
where rnk = 2
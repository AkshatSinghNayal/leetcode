with temp as(
    select 
    case when income < 20000 then 'Low Salary'
    when income >= 20000 and income <= 50000 then 'Average Salary'
    else 'High Salary' end as type
    from Accounts 
),

categories AS (
    SELECT 'Low Salary' AS category
    UNION ALL
    SELECT 'Average Salary'
    UNION ALL
    SELECT 'High Salary'
)

select c.category, case when t.type is null then 0 else count(*) end as accounts_count
from categories as c 
left join temp as t 
on c.category = t.type
group by t.type
order by accounts_count

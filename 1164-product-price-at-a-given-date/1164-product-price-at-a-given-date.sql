with temp as (
    select * , 
    rank() over(
        partition by product_id
        order by change_date desc
    ) as rnk
    from Products
    where change_date<='2019-08-16'
),
final as (
    select *
    from temp
    where rnk=1
)

select p.product_id , case when t.rnk is not null then t.new_price else 10 end as price
from Products as p 
left join temp as t 
on p.product_id = t.product_id 
where t.rnk =1 or t.rnk is null
group by p.product_id

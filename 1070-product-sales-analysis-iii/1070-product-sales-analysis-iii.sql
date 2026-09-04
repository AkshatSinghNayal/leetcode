with first as (
    select product_id , min(year) as year
    from Sales
    group by product_id
)

select a.product_id , a.year as first_year , a.quantity , a.price
from first as f
left join Sales as a
on f.product_id=a.product_id and f.year = a.year 
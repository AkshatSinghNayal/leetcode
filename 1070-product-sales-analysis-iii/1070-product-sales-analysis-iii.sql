with first as (
    select product_id , min(year) as year , quantity , price
    from Sales
    group by product_id
)

select a.product_id , a.year as first_year , a.quantity , a.price
from first as a

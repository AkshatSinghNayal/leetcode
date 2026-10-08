with temp as (
    select*, row_number() over( 
        partition by customer_id
        order by order_date asc
    ) as rnk 
    from Delivery 
)

select round(SUM(order_date = customer_pref_delivery_date)/count(distinct customer_id)*100,2) as immediate_percentage
from temp
where rnk = 1 
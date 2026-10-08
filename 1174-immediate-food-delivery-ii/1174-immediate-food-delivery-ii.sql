with temp as (
    select*, row_number() over( 
        partition by customer_id
        order by order_date asc
    ) as rnk 
    from Delivery 
)

select round(count(*)/(select count(distinct customer_id )from Delivery)*100,2) as immediate_percentage
from temp
where rnk = 1 and order_date = customer_pref_delivery_date ; 
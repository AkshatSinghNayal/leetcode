select 
round(sum( case when temp.order_date = temp.customer_pref_delivery_date then 1 else 0 end )/count(*)*100,2) as immediate_percentage
from (select * ,
row_number() over(
    partition by customer_id
    order by order_date 
) as rnk
from Delivery
) as temp

where temp.rnk = 1

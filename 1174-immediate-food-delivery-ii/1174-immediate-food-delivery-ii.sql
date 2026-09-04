select round(sum( case when d.order_date = d.customer_pref_delivery_date then 1 else 0 end )/count(*)*100,2) as immediate_percentage
from Delivery AS d 
where d.order_date = (
    select min(temp.order_date)
    from Delivery as temp
    where temp.customer_id = d.customer_id
)
WITH temp as(
    select person_name,
    sum(weight) over(order by turn ) as weight 
    from Queue
), final as (
    select person_name,
    rank() over( order by weight desc) as rnk
    from temp
    where weight <= 1000
)


select person_name
from final 
where rnk =1 
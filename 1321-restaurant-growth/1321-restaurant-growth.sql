with daily as (
    select visited_on , sum(amount) as amount 
    from Customer 
    group by visited_on
), 
temp as (
    select visited_on,
    sum(amount) over( order by visited_on 
        rows between 6 preceding and current row
    ) as amount
    , 
    round(avg(amount) over( 
        order by visited_on
        rows between 6 preceding and current row 
    ),2) as average_amount
    ,
    count(*) over( order by visited_on 
    rows between 6 preceding and current row 
    
    ) as cnt 
    from daily
)

select visited_on , amount , average_amount
from temp
where cnt = 7 
order by visited_on
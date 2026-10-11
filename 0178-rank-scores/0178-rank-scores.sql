with score as(
    select score as scr , 
    dense_rank() over(
        order by score desc
    ) as rnk
    from Scores
)
select scr as score , rnk as "rank"
from score

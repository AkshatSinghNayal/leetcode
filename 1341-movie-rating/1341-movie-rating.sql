with final as (
    select m.title as movie, mr.rating as rating , mr.created_at daate , u.name as name
    from Movies as m
    left join MovieRating as mr on mr.movie_id = m.movie_id
    left join Users as u on mr.user_id = u.user_id
)

(
select name as results
from final 
    group by name
    order by count(*) desc, name asc
    limit 1
)

union all 
(
select movie as results
from final
        where year(daate) = 2020 and month(daate) = 2
        group by movie
        order by avg(rating) desc, movie asc
        limit 1
)
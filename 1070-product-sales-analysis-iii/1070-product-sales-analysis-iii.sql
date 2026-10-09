with temp as (
    select*, rank() over(
        partition by product_id
        order by year asc
    ) as rnk 
    from Sales
)

SELECT product_id,
       year AS first_year,
       quantity,
       price
FROM temp
WHERE rnk = 1;
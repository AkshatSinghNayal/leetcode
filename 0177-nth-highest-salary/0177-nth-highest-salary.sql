CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
        with sec as (
            select salary, dense_rank() over(order by salary  desc) as rnk
            from Employee
        )

        select max(salary)
        from sec
        where rnk = N

  );
END
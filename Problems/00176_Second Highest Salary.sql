# Write your MySQL query statement below
-- second select is necessary as null being returned needs to be put into a table as value null
select
(
    select
        distinct(salary)
    from
        employee
    order by
        salary desc
    limit
        1
    offset
        1
)
as SecondHighestSalary
;
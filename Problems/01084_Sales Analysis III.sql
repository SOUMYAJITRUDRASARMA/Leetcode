# Write your MySQL query statement below
select 
    distinct Product.product_id, 
    product_name
from
    Product
    right join
    Sales
on
    Product.product_id = Sales.product_id
where
    sale_date between '2019-01-01' and '2019-03-31'
    and
    Product.product_id not in
    (
        select
            distinct product_id
        from
            Sales
        where
            sale_date < '2019-01-01'
            or
            sale_date > '2019-03-31'
    )
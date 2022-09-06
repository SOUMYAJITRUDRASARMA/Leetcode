# Write your MySQL query statement below
select
    user_id as buyer_id, 
    join_date, 
    ifnull(orders_in_2019, 0) as orders_in_2019
from 
    Users
    left join
    (
        select
            buyer_id, 
            count(*) as orders_in_2019
        from
            Orders
        where
            year(order_date) = '2019'
        group by
            buyer_id
    ) as Freq
on
    Users.user_id = Freq.buyer_id
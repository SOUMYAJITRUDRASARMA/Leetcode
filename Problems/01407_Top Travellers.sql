# Write your MySQL query statement below
select 
    name, 
    ifnull(travelled_distance, 0) as travelled_distance
from
    Users
    left join
    (
        select
            user_id, 
            sum(distance) as travelled_distance
        from 
            Rides
        group by
            user_id

    ) as RidesAccumulatedDistance
on 
    Users.id = RidesAccumulatedDistance.user_id
order by
    travelled_distance desc, 
    name asc
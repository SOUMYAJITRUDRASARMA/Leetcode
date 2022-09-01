# Write your MySQL query statement below
select
    Weather.id as id
from
    Weather
join
    Weather w  -- internal join
on
    datediff(Weather.recordDate, w.recordDate) = 1
    and
    Weather.temperature > w.temperature
;
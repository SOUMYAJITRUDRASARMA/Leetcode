# Write your MySQL query statement below
select
    name, 
    ifnull(sum(amount), 0) as balance
from
    Users
    left join
    Transactions
on
    Users.account = Transactions.account
group by
    Users.account
having
    balance > 10000
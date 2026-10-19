# Write your MySQL query statement below
select b.id from weather a join weather b on datediff(b.recorddate,a.recorddate)=1 where b.temperature > a.temperature
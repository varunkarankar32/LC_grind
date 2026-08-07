# Write your MySQL query statement below
select Employee.name, Bonus.bonus from employee left join Bonus on employee.empId = Bonus.empId where Bonus.bonus is NULL or Bonus.bonus < 1000;
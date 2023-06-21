# Write your MySQL query statement below
select EmployeeUNI.unique_id,Employees.name from Employees 
LEFT JOIN EmployeeUNI
ON Employees.id=EmployeeUNI.id; 
SELECT CASE
WHEN (SELECT Distinct COUNT(salary) FROM Employee) <= 1 or (SELECT MAX(salary) FROM Employee)= (SELECT MIN(salary) FROM Employee) THEN NULL

ELSE 
(SELECT TOP 1 salary AS SecondHighestSalary
FROM (SELECT Distinct TOP 2 (salary) FROM Employee ORDER BY salary desc) as subquery ORDER BY SecondHighestSalary ASC) 

END as SecondHighestSalary ;
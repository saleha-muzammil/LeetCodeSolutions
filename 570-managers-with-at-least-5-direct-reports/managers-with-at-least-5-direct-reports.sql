SELECT e.name FROM Employee e 
INNER JOIN 
(Select managerId FROM Employee 
GROUP BY managerId 
HAVING COUNT(*) >= 5 ) m 
on e.id  =m.managerId ;

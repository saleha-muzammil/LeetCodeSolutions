CREATE FUNCTION getNthHighestSalary(@N INT) RETURNS INT AS
BEGIN
    RETURN (
        SELECT CASE 
            WHEN @N = 1 AND (SELECT COUNT(DISTINCT salary) FROM employee) = 1 THEN 
                (SELECT TOP 1 salary FROM employee)
            WHEN (SELECT COUNT(DISTINCT salary) FROM employee) < @N OR
                 (SELECT MAX(salary) FROM employee) = (SELECT MIN(salary) FROM employee) THEN 
                NULL 
            ELSE 
                (SELECT TOP 1 salary 
                FROM (
                    SELECT DISTINCT TOP (@N) salary 
                    FROM Employee 
                    ORDER BY salary DESC
                ) AS subquery 
                ORDER BY salary ASC)
        END
    );
END

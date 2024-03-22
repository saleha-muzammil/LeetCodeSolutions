SELECT m.id, 
CASE
WHEN m.p_id IS NULL THEN 'Root'
WHEN m.p_id IN (SELECT id FROM Tree) AND m.id IN (SELECT p_id FROM Tree) THEN 'Inner'
ELSE 'Leaf'
END AS type FROM Tree m; 
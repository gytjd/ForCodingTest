SELECT o.animal_id AS ANIMAL_ID, o.name AS NAME
FROM animal_outs o
WHERE o.animal_id NOT IN (SELECT i.animal_id FROM animal_ins i)
ORDER BY o.animal_id;
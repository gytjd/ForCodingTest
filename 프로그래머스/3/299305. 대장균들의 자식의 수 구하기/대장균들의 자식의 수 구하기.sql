SELECT e.id as ID,case when t.parent_count is null then 0 else t.parent_count end CHILD_COUNT
FROM ecoli_data e
LEFT JOIN (
    SELECT parent_id, COUNT(parent_id) AS parent_count
    FROM ecoli_data
    WHERE parent_id IS NOT NULL
    GROUP BY parent_id
) t ON e.id = t.parent_id;
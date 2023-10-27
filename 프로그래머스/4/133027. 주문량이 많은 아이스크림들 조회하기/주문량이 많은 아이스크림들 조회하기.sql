-- 코드를 입력하세요
SELECT
    q.flavor
FROM
    (
        SELECT
            e.flavor,
            SUM(e.fsum) AS esum
        FROM
            (
                SELECT
                    f.flavor,
                    SUM(f.total_order) AS fsum
                FROM
                    first_half f
                GROUP BY
                    f.flavor
                UNION
                SELECT
                    j.flavor,
                    SUM(j.total_order) AS jsum
                FROM
                    july j
                GROUP BY
                    j.flavor
            ) e
        GROUP BY
            e.flavor
        ORDER BY
            esum DESC
    ) q
WHERE ROWNUM<=3
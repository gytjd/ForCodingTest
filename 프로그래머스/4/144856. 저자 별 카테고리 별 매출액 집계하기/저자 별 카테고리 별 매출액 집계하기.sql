-- 코드를 입력하세요
SELECT
    e.author_id,
    e.author_name,
    e.category,
    SUM(e.total_sales) AS total_sales
FROM
    (
        SELECT
            b.author_id            AS author_id,
            a.author_name          AS author_name,
            b.category             AS category,
            b.price * SUM(s.sales) AS total_sales
        FROM
            (
                     book b
                JOIN author     a ON b.author_id = a.author_id
            )
            JOIN book_sales s ON b.book_id = s.book_id
        WHERE TO_CHAR(s.SALES_DATE,'YYYY-MM')='2022-01'
        GROUP BY
            b.author_id,
            a.author_name,
            b.category,
            b.price
    ) e
GROUP BY
    e.author_id,
    e.author_name,
    e.category
ORDER BY
    e.author_id ASC,
    e.category DESC
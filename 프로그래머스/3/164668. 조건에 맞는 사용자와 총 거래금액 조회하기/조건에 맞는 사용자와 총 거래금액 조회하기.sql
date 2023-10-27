SELECT
    u.user_id,
    u.nickname,
    SUM(b.price) AS TOTAL_SALES
FROM
    used_goods_user u JOIN used_goods_board b ON u.USER_ID=b.WRITER_ID
WHERE
    b.STATUS='DONE'
GROUP BY u.user_id,u.nickname
HAVING SUM(b.price)>=700000
ORDER BY TOTAL_SALES ASC;
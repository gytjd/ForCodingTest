-- 코드를 입력하세요
SELECT
    b.TITLE,b.BOARD_ID,r.REPLY_ID,r.WRITER_ID,r.CONTENTS,to_char(r.created_DATE, 'YYYY-MM-DD') AS CREATED_DATE
FROM
         used_goods_board b
    JOIN used_goods_reply r ON b.board_id = r.board_id
WHERE
        to_char(b.created_date, 'YYYY-MM') = '2022-10'

ORDER BY r.CREATED_DATE ASC,B.TITLE ASC
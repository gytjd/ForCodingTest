SELECT
    fi.ID,
    fni.FISH_NAME,
    fi.LENGTH
FROM
    FISH_INFO fi
JOIN
    FISH_NAME_INFO fni ON fi.FISH_TYPE = fni.FISH_TYPE
JOIN
    (
        SELECT
            FISH_TYPE,
            MAX(LENGTH) AS MAX_LENGTH
        FROM
            FISH_INFO
        WHERE
            LENGTH IS NOT NULL
        GROUP BY
            FISH_TYPE
    ) max_lengths ON fi.FISH_TYPE = max_lengths.FISH_TYPE AND fi.LENGTH = max_lengths.MAX_LENGTH
ORDER BY
    fi.ID ASC;
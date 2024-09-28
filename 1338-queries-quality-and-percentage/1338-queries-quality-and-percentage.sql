# Write your MySQL query statement below
WITH QualityCTE AS (
    SELECT 
        query_name, 
        AVG(CAST(rating AS DECIMAL(10,2)) / position) AS quality
    FROM 
        Queries
    GROUP BY 
        query_name
),
PoorQueryCTE AS (
    SELECT 
        query_name, 
        COUNT(CASE WHEN rating < 3 THEN 1 END) * 100.0 / COUNT(*) AS poor_query_percentage
    FROM 
        Queries
    GROUP BY 
        query_name
)
SELECT 
    q.query_name, 
    ROUND(q.quality, 2) AS quality, 
    ROUND(p.poor_query_percentage, 2) AS poor_query_percentage
FROM 
    QualityCTE q
JOIN 
    PoorQueryCTE p ON q.query_name = p.query_name;

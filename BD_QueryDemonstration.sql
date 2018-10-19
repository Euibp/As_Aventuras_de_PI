SELECT 
    [dbo].[tag].[numero_tag],[dbo].[refrigerador].[nome_refrigerado],[dbo].[produto].[nome_produto],[dbo].[produto].[real_preco],[dbo].[cor].[nome_cor] 
FROM
    [dbo].[tag],
    [dbo].[refrigerador],
	[dbo].[produto],
	[dbo].[cor]
WHERE [dbo].[tag].[fk_id_refrigerador] = 01
	  AND [dbo].[refrigerador].[id_refrigerador] = 01
	  AND [dbo].[produto].[id_produto] = [dbo].[tag].[fk_id_produto] 
	  AND [dbo].[produto].[fk_id_cor] = [dbo].[cor].[id_cor];
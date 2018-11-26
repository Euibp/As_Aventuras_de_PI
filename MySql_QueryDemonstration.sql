SELECT 
     tag.numero_tag, refrigerador.nome_refrigerador, produto.nome_produto,produto.real_preco,cor.nome_cor
FROM
    tag,
    refrigerador,
	produto,
	cor
WHERE tag.fk_id_refrigerador = 01
	  AND refrigerador.id_refrigerador = 01
	  AND produto.id_produto = tag.fk_id_produto 
	  AND produto.fk_id_cor = cor.id_cor;
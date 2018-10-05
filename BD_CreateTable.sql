CREATE TABLE id_cor 
    (
    nome_cor    VARCHAR(50),
    id_cor_id   NUMERIC(28) NOT NULL IDENTITY NOT for replication ) 
GO

ALTER TABLE Id_Cor ADD constraint id_cor_pk PRIMARY KEY CLUSTERED (Id_Cor_ID)
     WITH (
     ALLOW_PAGE_LOCKS = ON , 
     ALLOW_ROW_LOCKS = ON ) 
GO

CREATE TABLE id_produto 
    (
    nome_produto   VARCHAR(50),
    produto_id     NUMERIC(28) NOT NULL IDENTITY NOT FOR REPLICATION , 
     Id_Cor_Id_Cor_ID NUMERIC (28) NOT NULL ) 
GO

ALTER TABLE Id_Produto ADD constraint produto_pk PRIMARY KEY CLUSTERED (Produto_ID)
     WITH (
     ALLOW_PAGE_LOCKS = ON , 
     ALLOW_ROW_LOCKS = ON ) 
GO

CREATE TABLE id_refrigerador 
    (
    id_refigerador    INTEGER DEFAULT 0,
    refrigerador_id   NUMERIC(28) NOT NULL IDENTITY NOT for replication ) 
GO

ALTER TABLE Id_Refrigerador ADD constraint refrigerador_pk PRIMARY KEY CLUSTERED (Refrigerador_ID)
     WITH (
     ALLOW_PAGE_LOCKS = ON , 
     ALLOW_ROW_LOCKS = ON ) 
GO

CREATE TABLE tag (
    numero_tag                     INTEGER DEFAULT 0,
    refrigerador_refrigerador_id   NUMERIC(28) NOT NULL,
    produto_produto_id             NUMERIC(28) NOT NULL
)

GO

ALTER TABLE Id_Produto
    ADD CONSTRAINT id_produto_id_cor_fk FOREIGN KEY ( id_cor_id_cor_id )
        REFERENCES id_cor ( id_cor_id )
ON DELETE NO ACTION 
    ON UPDATE NO ACTION 
GO

ALTER TABLE Tag
    ADD CONSTRAINT tag_produto_fk FOREIGN KEY ( produto_produto_id )
        REFERENCES id_produto ( produto_id )
ON DELETE NO ACTION 
    ON UPDATE NO ACTION 
GO

ALTER TABLE Tag
    ADD CONSTRAINT tag_refrigerador_fk FOREIGN KEY ( refrigerador_refrigerador_id )
        REFERENCES id_refrigerador ( refrigerador_id )
ON DELETE NO ACTION 
    ON UPDATE NO ACTION 
GO
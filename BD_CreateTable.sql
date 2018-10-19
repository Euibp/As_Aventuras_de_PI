-- Gerado por Oracle SQL Developer Data Modeler 18.2.0.179.0756
--   em:        2018-10-19 15:04:54 BRT
--   site:      SQL Server 2012
--   tipo:      SQL Server 2012



CREATE TABLE cor 
    (
    nome_cor   VARCHAR(50),
    id_cor     NUMERIC(28) NOT NULL IDENTITY NOT for replication ) 

ALTER TABLE Cor ADD constraint pk_cor PRIMARY KEY CLUSTERED (ID_Cor)
     WITH (
     ALLOW_PAGE_LOCKS = ON , 
     ALLOW_ROW_LOCKS = ON ) 

CREATE TABLE produto 
    (
    nome_produto   VARCHAR(50),
    real_preco     REAL,
    id_produto     NUMERIC(28) NOT NULL IDENTITY NOT FOR REPLICATION , 
     FK_ID_Cor NUMERIC (28) NOT NULL ) 

ALTER TABLE Produto ADD constraint pk_produto PRIMARY KEY CLUSTERED (ID_Produto)
     WITH (
     ALLOW_PAGE_LOCKS = ON , 
     ALLOW_ROW_LOCKS = ON ) 

CREATE TABLE refrigerador 
    (
    nome_refrigerado   VARCHAR(50),
    id_refrigerador    NUMERIC(28) NOT NULL IDENTITY NOT for replication ) 

ALTER TABLE Refrigerador ADD constraint pk_refrigerador PRIMARY KEY CLUSTERED (ID_Refrigerador)
     WITH (
     ALLOW_PAGE_LOCKS = ON , 
     ALLOW_ROW_LOCKS = ON ) 

CREATE TABLE tag (
    numero_tag           VARCHAR(50),
    fk_id_refrigerador   NUMERIC(28) NOT NULL,
    fk_id_produto        NUMERIC(28) NOT NULL
)



ALTER TABLE Produto
    ADD CONSTRAINT fk_produto_cor FOREIGN KEY ( fk_id_cor )
        REFERENCES cor ( id_cor )
ON DELETE NO ACTION 
    ON UPDATE NO ACTION 

ALTER TABLE Tag
    ADD CONSTRAINT fk_tag_produto FOREIGN KEY ( fk_id_produto )
        REFERENCES produto ( id_produto )
ON DELETE NO ACTION 
    ON UPDATE NO ACTION 

ALTER TABLE Tag
    ADD CONSTRAINT fk_tag_refrigerador FOREIGN KEY ( fk_id_refrigerador )
        REFERENCES refrigerador ( id_refrigerador )
ON DELETE NO ACTION 
    ON UPDATE NO ACTION
GO
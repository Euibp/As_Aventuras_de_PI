USE [As_Aventuras_de_PI_4]
GO


INSERT INTO [dbo].[refrigerador]([nome_refrigerado]) VALUES
           ('Estoque'),('Richard_Parcker')
GO

INSERT INTO [dbo].[cor]([nome_cor]) 
	VALUES('Verde'),('Vermelho'),('Preto'),('Azul'),('Branco'),('Amarelo')
GO

INSERT INTO [dbo].[produto]([nome_produto],[real_preco],[fk_id_cor]) VALUES
		('CAIXA01',10.90,1),
		('CAIXA02',11.80,2),
		('CAIXA03',12.70,3),
		('CAIXA04',13.60,4),
		('CAIXA05',14.50,5),
		('CAIXA06',15.40,6),
		('CAIXA07',16.30,1),
		('CAIXA08',17.20,2),
		('CAIXA09',18.10,3),
		('CAIXA0A',19.00,4),
		('CAIXA0B',09.90,5),
		('CAIXA0C',08.80,6),
		('CAIXA0D',07.70,1),
		('CAIXA0E',06.60,2),
		('CAIXA0F',05.50,3),
		('CAIXA10',04.40,4),
		('CAIXA11',03.30,5),
		('CAIXA12',02.02,6)
GO

INSERT INTO [dbo].[tag]([numero_tag],[fk_id_refrigerador],[fk_id_produto]) VALUES
           ('1A007C58DFE1',01, 01),
		   ('1A007C58447A',02, 02),
		   ('1A007C5B4A77',01, 03),
		   ('1A007C593B04',02, 04),
		   ('1A007C581E20',01, 05),
		   ('1A007C5B4D70',02, 06),
		   ('1A007C594F70',01, 07),
		   ('1A007C58201E',02, 08),
		   ('1A007C59340B',01, 09),
		   ('1A007C581927',02, 10),
		   ('1A007C59B08F',01, 11),
		   ('1A007C58E08F',02, 12),
		   ('1A007C90EF19',01, 13),
		   ('1B00571A84D2',02, 14),
		   ('1A007C90F204',01, 15),
		   ('1A007C91B542',02, 16),
		   ('1A007C917C8B',01, 17)
GO






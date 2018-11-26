<?php

$tag = $_GET['tag'];
$local = $_GET['local'];

$servername = "localhost";
$bdrname = "pi";
$username = "root";
$password = "richardParker18";

try{
	$conn = new PDO("mysql:host=" . $servername . ";dbname=" . $bdrname . ";charset=utf8", $username, $password );
	$conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	$stmt =  $conn->prepare("SELECT   tag.numero_tag, refrigerador.nome_refrigerador, produto.nome_produto,produto.real_preco,cor.nome_cor
											FROM tag, refrigerador, produto,	cor
											WHERE tag.numero_tag ="  . $tag .
												  "AND refrigerador.id_refrigerador = tag.fk_id_refrigerador
												  AND produto.id_produto = tag.fk_id_produto 
												  AND produto.fk_id_cor = cor.id_cor;  ");
	$stmt->execute();
	
	$result = $stmt->setFetchMode(PDO::FETCH_ASSOC); 
	$vector = $stmt->fetchAll();
	
	// '*' é character verificador;
	echo ("StartData*");
	//Função verifica existencia da tag no banco
	if(empty($vector)){
		echo "INVALIDO*";
		return;
	}
	//Função de Remover 
	//Não usa strings!!!
	if($vector[0]['nome_refrigerador']== $local){
		echo "R*";
		$sql = "UPDATE tag
					SET fk_id_refrigerador = 1
					WHERE numero_tag = " . $tag . ";";
		$conn->exec($sql);
		
	}else{
	echo "I*";
		$sql = "UPDATE tag
					SET fk_id_refrigerador = 2
					WHERE numero_tag = " . $tag . ";";
		$conn->exec($sql);
	}
		printf($vector[0]['nome_cor'] . "*");
		printf($vector[0]['real_preco'] . "*");
		printf($vector[0]['numero_tag'] . "*");
		printf($vector[0]['nome_refrigerador'] . "*");
		//printf( $vector[0][0] . "\n");
								  
	//echo "Connected successfully"; 
	}
	// Create connection
	//$conn = mysqli_connect($servername, $username, $password);
	catch(PDOException $erro){
			echo "Erro de Conexao, detalhes: " . $erro->getMessage();	
	}
	
	// Check connection
//	if (!$conn) {
//		die("Connection failed: " . mysqli_connect_error());
//	}
	
?>
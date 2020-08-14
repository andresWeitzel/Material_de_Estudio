<?php
//Cabecera para que al trabajar ccon php y Json NO TENGAMOS ERRORES
header("Content-type : appplication/json; charset=UTF-8 ");

//Quitamos los warnings
error_reporting(0);

//$objeto=json_decode($_GET["objeto"], false);

//definimos directamente en php ..
$objeto=json_decode('{"tabla":" NIC","valor": 343434}');

//Definimos los parametros de conexion de la  BBDD en MYSQL
$servidor="localhost";
$usuario="root"; 
$password="";
$bbdd="db_pruebas1";

//Crearemos la conexion a la database
$conexion= new mysqli($servidor,$usuario,$password,$bbdd);

//Comprobaremos la conexion 
if($conexion->connect_errno){
    die("Error en la conexion: " +  $conexion->connect_error);
}else{
    //Conexion Correcta
    //Creamos la consulta SQL
    $sql="SELECT NIF, NOMBRE, APELLIDO, EDAD FROM $objeto->tabla WHERE  NIF >= $objeto->valor";

    //Obtenemos el resultado
    $resultado=$conexion->query($sql);
    $salida=array();
    //$salida=$resultado->fetch_all(MYSQLI_ASSOC);
    $salida= mysqli_fetch_all($resultado,MYSQLI_ASSOC);

    
    echo json_encode($salida);
}
$conexion->close();
?>
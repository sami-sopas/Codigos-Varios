<?php

    //Conexion e insercion a BD

    $servidor = "localhost"; //127.0.0.1
    $usuario = "root";
    $password = "";

    try{
        //              //Objeto para poder conectarse
        $conexion = new PDO("mysql:host=$servidor;dbname=album", $usuario,$password);

        // Datos para poder mostrar los errores
        $conexion->setAttribute(PDO::ATTR_ERRMODE,PDO::ERRMODE_EXCEPTION);

        //Instruccion para insertar en la BD
        $sql = "INSERT INTO `fotos` (`id`, `nombre`, `ruta`) VALUES (NULL, 'Jugando con la programacion', 'foto.jpg');";
        $conexion->exec($sql);

        echo "Conexion establecida";
           
    }catch(PDOException $error){
        echo "Conexion erronea".$error;
    }
?>
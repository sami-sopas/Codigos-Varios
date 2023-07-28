<?php

    //Leer datos 

    $servidor = "localhost"; //127.0.0.1
    $usuario = "root";
    $password = "";

    try{
        //              //Objeto para poder conectarse
        $conexion = new PDO("mysql:host=$servidor;dbname=album", $usuario,$password);

        // Datos para poder mostrar los errores
        $conexion->setAttribute(PDO::ATTR_ERRMODE,PDO::ERRMODE_EXCEPTION);

        //Instruccion para seleccionar los campos
        $sql = "SELECT * FROM `fotos`";

        //Los resultados se guardan en esa sententencia
        $sentencia = $conexion->prepare($sql);

        //Ejecutamos la sentencia
        $sentencia->execute();

        //El metodo regresa el resultado de esa sentencia
        $resultado = $sentencia->fetchAll();

        //print_r($resultado); //Imprime en modo de arreglo

        foreach($resultado as $foto)
        {
            echo $foto['nombre']."<br>"; //Muestra solo el campo nombre de los registros
        }

        echo "Conexion establecida";
           
    }catch(PDOException $error){
        echo "Conexion erronea".$error;
    }
?>
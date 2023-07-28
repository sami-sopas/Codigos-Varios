<?php

    //Leyendo el dato de ejercicio30.php

    session_start();

    if( isset($_SESSION["usuario"])){ //Validar que existe la sesion

    echo "Sesion iniciada en ejercicio 30_1"."<br>";

    echo "Usuario: ".$_SESSION["usuario"]." Estatus: ".$_SESSION["estatus"];

    }
    else
    {
        echo "No hay datos";
    }
?>
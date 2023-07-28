<?php
    //Consumir formatos JSON

    $jsonContenido = '[ 
        {"nombre":"Oscar", "apellido":"Uh"},
        {"nombre":"Jose", "apellido":"Perez"}
        ]';

    //Funcion para convertir ese string a un resultado
    $resultado = json_decode($jsonContenido);

    // print_r($resultado); //Imprime un arreglo

    //Para recorrer el arreglo convertido
    foreach($resultado as $persona)
    {
        echo($persona->nombre)." ".($persona->apellido)."<br>"; //Imprime objetos
    }


?>
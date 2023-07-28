<?php

    //Arreglos
    $frutas = array("fresa","manzana","pera");

    //Muestra como esta organizada la informacion
    print_r($frutas); // Array ( [0] => fresa [1] => manzana [2] => pera ) 

    echo "<br>";

    echo $frutas[0]; //Fresa

    for($i = 0; $i < 3; $i++ )
    {
        echo "<br>".$frutas[$i]; //Imprime todo el array
    }
?>
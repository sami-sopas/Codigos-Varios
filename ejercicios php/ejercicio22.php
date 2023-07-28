<?php
    
    //Arreglos 2

    //Asignarle un indice a un elemento del arreglo con el operador =>
    $frutas = array("f"=>"fresa","m"=>"manzana","p"=>"pera");
    //                 0 => f       1 => m        2 => p

    print_r($frutas); //Array ( [f] => fresa [m] => manzana [p] => pera )

    echo "<br>";

    echo $frutas["p"]; //Pera

    foreach($frutas as $indice=>$valor)
    {
        echo "<br> El valor ".$valor." tiene el indice ".$indice; //Imprime los indices: f, m , p
    }

    foreach($frutas as $indice)
    {
        echo "<br>".$indice; //Imprime los valores
    }


?>

<?php
    //Metodos estaticos
    class UnaClase {

        public static function unMetodo()
        {
            echo "Hola soy un metodo estatico";
        }


    }

    $obj = new UnaClase();
    $obj->unMetodo();

    echo "<br>";

    //Acceder al metodo estatico
    UnaClase::unMetodo();


?>
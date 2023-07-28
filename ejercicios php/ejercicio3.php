<?php
    //Se recibe la informacion por el meotodo get
    if($_GET)
    {
        $nombre = $_GET['nombre'];

        echo "HOla ".$nombre;
    }

?>
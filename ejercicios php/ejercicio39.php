<?php
    /// Escribiendo en un archivo

    $nombreArchivo = "archivo.txt";

    $contenidoArchivo = "Hola, saludos";

    //Abrir archivo en modo escritura
    $archivoACrear = fopen($nombreArchivo,"w");

    //Escribir en el archivo
    fwrite($archivoACrear,$contenidoArchivo);

    //Cerrarlo
    fclose($archivoACrear);
?>
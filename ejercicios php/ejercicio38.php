<?php
    /// Lectura de archivos

    $archivo = "contenido.txt";

    //Abrir el archivo en modo lectura
    $archivoAbierto = fopen($archivo,"r");

    //Leer el contenido
    $contenido = fread($archivoAbierto,filesize($archivo));

    //Imprimiendo
    echo $contenido;
?>
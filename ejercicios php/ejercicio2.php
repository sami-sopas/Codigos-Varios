<?php

    if($_POST) //Si hubo envio...
    {
        // Recibir informacion del formulario HTML ( Metodo POST)
        $nombre =$_POST['txtNombre'];

        echo "Hola ".$nombre;
    }

   
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>

    <form action="ejercicio2.php" method="post"> <!-- El formulario hace un envio a ejercicio2.php por el metodo post -->
        Nombre:
        <input type="text" name="txtNombre" id=""> <!-- para escribir un nombre -->
        <br>
        <input type="submit" value="Enviar"> <!-- boton para realizar la acction -->
    </form>
</body>
</html>
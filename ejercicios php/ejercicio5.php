<?php
    
    if($_POST)
    {
        $txtNombre = $_POST['txtNombre'];
        $txtApellido = $_POST['txtApellido'];

        echo "Hola ".$txtNombre." ".$txtApellido; //Concatenacion de strings
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

<form action="ejercicio5.php" method="post"> <!-- El formulario hace un envio a ejercicio2.php por el metodo post -->

        Nombre:
        <input type="text" name="txtNombre" id=""> <!-- para escribir un nombre -->
        <br>

        Apellido:
        <input type="text" name="txtApellido" id=""> <!-- para el apellido -->
        <br>

        <input type="submit" value="Enviar"> <!-- boton para realizar la acction -->
</form>
    
</body>
</html>
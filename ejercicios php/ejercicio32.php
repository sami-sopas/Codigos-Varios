<?php //TRABAJAR CON INPUT FILES

    if($_POST)
    {
        print_r($_POST); //El post solo recibe el nombre del archivo

        //Usando otro mecanismo de envio
        print_r($_FILES['archivo']['name']); //Obtener solo nombre del archivo 

        //Obtenemos el archivo temporal y lo vamos a mover con su nombre original en la misma carpeta
        move_uploaded_file($_FILES['archivo']['tmp_name'],$_FILES['archivo']['name']);
    }
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Input files</title>
</head>
<body>
                                 <!-- parametro para enviar info -->
    <form action="ejercicio32.php" enctype="multipart/form-data" method="post">
        Imagen:
        <br>
        <input type="file" name="archivo" id="">
        <br>
        <input type="submit" name="enviar" value="Enviar informacion">


    </form>
    
</body>
</html>
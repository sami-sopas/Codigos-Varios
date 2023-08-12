<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <?php require 'views/header.php' ?>

    <div id="main">
        <h1 class="center">Seccion de nuevo</h1>

        <div class="center"><?php echo $this->mensaje ?></div>

        <form action="<?php echo constant('URL'); ?>nuevo/registrarAlumno" method="POST">
            <p>
                <label for="matricula">Matricula</label> <br>
                <input type="text" name="matricula" id="" required> <br>

                <label for="nombre">Nombre</label> <br>
                <input type="text" name="nombre" id="" required> <br>

                <label for="apellido">Apellido</label> <br>
                <input type="text" name="apellido" id="" required> <br>
    
            </p>

            <p>
                <br>
                <input type="submit" value="Registrar nuevo alumno">
            </p>
        </form>
    </div>
    
    <?php require 'views/footer.php' ?>

</body>
</html>
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
        <h1 class="center">Seccion de consulta</h1>

        <table style="width: 100%">
            <thead>
                <tr>
                    <th>Matricula</th>
                    <th>Nombre</th>
                    <th>Apellido</th>
                </tr>
            </thead>
            <tbody>
                <?php 
                    include_once 'models/alumno.php';

                    foreach($this->alumnos as $row){
                        $alumno = new Alumno();
                        $alumno = $row;
                    
                 ?>
                <tr>
                    <td><?php echo $alumno->matricula; ?></td>
                    <td><?php echo $alumno->nombre; ?></td>
                    <td><?php echo $alumno->apellido; ?></td>
                                                                <!-- llamandoa las funcioens y pasandoles el ID -->
                    <td><a href="<?php echo constant('URL') . 'consulta/verAlumno/' . $alumno->matricula; ?>">Editar</a></td>
                    <td><a href="<?php echo constant('URL') . 'consulta/eliminarAlumno/' . $alumno->matricula; ?>">Eliminar</a></td>
                </tr>
                 <?php } ?>

            </tbody>
        </table>

        
    </div>
    
    <?php require 'views/footer.php' ?>

</body>
</html>
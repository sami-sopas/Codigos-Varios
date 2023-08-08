<?php
    include_once("includes/survey.php")

?>

<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="style.css">
    <title>Encuesta</title>
</head>
<body>

    <form action="#" method="POST">
        <?php
            $survey = new Survey();

            //Variable para validar si quiero mostrar el formulario o los resultados
            $showResults = false;

            //SI se realizo un envio con el valor de la opcion seleccionada
            if(isset($_POST['lenguaje']))
            {
                $showResults = true;
                $survey->setOptionSelected($_POST['lenguaje']);
                $survey->vote();
            }
        ?>

        <h2>¿Cual es tu lenguaje de programacion favorito?</h2>

        <?php

            //Vista para mostrar los votos totales
            if($showResults == true)
            {
                $lenguajes = $survey->showResults();

                echo '<h2>' . $survey->getTotalVotes() . ' votos totales </h2>';

                foreach($lenguajes as $lenguaje){
                    $porcentaje = $survey->getPercentageVotes($lenguaje['votos']);

                    include ("vistas/vista-resultado.php");

                }
                echo "<br>";
                echo ' <a href="index.php" >Volver</a> ';
            }
            else //Mostrar la vista de la votacion
            {
                include ("vistas/vista-votacion.php");
            }

        ?>
    </form>
    
</body>
</html>
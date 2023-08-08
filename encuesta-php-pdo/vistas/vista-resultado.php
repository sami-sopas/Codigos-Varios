<div class="opcion">
    <?php
        //Aqui configuramos para mostrar las barras de porcentaje

        $widthBar = $porcentaje * 5;
        $estilo = "barra"; //Para configurar el color de fondo, dependiendo de la opcion seleccionada

        //Si la opcion seleccionada coindice con la opcion del lenguaje, esa cambiara su estilo
        if($survey->getOptionSelected() == $lenguaje['opcion'])
        {
            $estilo = "seleccionado";
        }

        echo $lenguaje['opcion'];

    ?>

        <!-- Y aqui es donde aplicamos esos estilos -->
    <div class="<?php echo $estilo ?>" style="width: <?php echo $widthBar . 'px' ?>" ><?php echo $porcentaje . '%'?></div>

</div>
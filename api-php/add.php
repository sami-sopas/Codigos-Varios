<?php
    include_once('apipeliculas.php');

    //Consumimos la api
    $api = new ApiPeliculas();

    //Validamos el envio de las dos variables
    if(isset($_POST['nombre']) && isset($_FILES['imagen']))
    {
        //Validar que el archivo sea correcto
        if($api->subirImagen($_FILES['imagen']))
        {
            //Crear arreglo con los datos e indice
            $item = array(
               // indice        valor
                'nombre' => $_POST['nombre'],
                'imagen' => $api->getImagen()
            );

            //Enviar los datos a la api
            $api->add(($item));
        }
        else //Errores de imagen
        {
            $api->error('Error con el archivo: ' . $api->getError());
        }

    }
    else{
        $api->error('Error al llamar a la API');
    }

?>
<?php
    include_once('apipeliculas.php');

    //Consumimos la api
    $api = new ApiPeliculas();

    //Si se realiza el envio de la variable ID
    if(isset($_GET['id'])){

        //Guardamos el ID enviado por el link en esta variable
        $id = $_GET['id'];

        //Verificamos que si sea un numero el ID que envian 
        if(is_numeric($id))
        {
            //LLamamos unicamente a ese regitro
            $api->getById($_GET['id']);
        }else
        {
            $api->error('Los parametros son incorrectos');
        }

    }
    else
    {
        //Si no llamamos a todos los registros
        $api->getAll();
    }
    
?>
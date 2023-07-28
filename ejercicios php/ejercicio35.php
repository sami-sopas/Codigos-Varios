<?php
    //Consumir una API

    $url = "https://api.dailymotion.com/videos?channel=sport&limit=10";

    //Desactivar compatibilidad para poder leer el HTTPS
    $opciones = array("ssl"=>array("verify_peer"=>false,"verify_peer_name"=>false));

    //Leer todo el contenido y convertirlo a String
    $respuesta = file_get_contents($url,false,stream_context_create($opciones));

    //Decoficiarlo
    $objRespuesta = json_decode($respuesta);

    //print_r($objRespuesta);

    //Leer registro por registro

    //Accedemos a la lista del JSON [list]
    foreach($objRespuesta->list as $video)
    {
        //print_r($video->title);
        //print_r($video->channel);


    }

?>

    <!-- Mostramos los datos en una lista HTML con codigo embebido -->

<ul>
    <?php foreach($objRespuesta->list as $video) {?>
        <li> <?php echo ($video->title); ?> | <?php echo($video->channel); ?> </li>
    <?php } ?>
</ul>
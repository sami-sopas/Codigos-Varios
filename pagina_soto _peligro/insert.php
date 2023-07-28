<?php

include("conexion.php");

//lo que se reciba a traves del metodo POST se guarda aqui
if(isset($_POST['save_task']))
{
    $id = $_POST['id'];
    $nombre = $_POST['nombre'];
    $cantidad = $_POST['cantidad'];

    $query = "INSERT INTO pan (id,nombre,cantidad) VALUES ($id,'$nombre',$cantidad);";
    $result = mysqli_query($miConexion,$query);

    if(!$result)
    {
        die("Fallo al insertar");
    }

    $_SESSION['message'] = 'Panesito guardado :)';
    $_SESSION['message_type'] = 'success';

    //echo 'Datos insertados';
    header("Location: segunda.php");
}


?>
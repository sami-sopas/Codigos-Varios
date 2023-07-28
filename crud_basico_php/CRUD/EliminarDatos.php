<?php
    include("../Config/Conexion.php");

    //Recibimos el ID por parametro desde el index (Como el request de editar)
    $Id = $_GET['Id'];
    $sql = "DELETE FROM productos WHERE IdProducto = '$Id' ";

    $query = mysqli_query($conexion,$sql);

    if($query == TRUE)
    {
        header("location:../index.php");
    }
?>
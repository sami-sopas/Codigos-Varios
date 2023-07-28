<?php
    include_once("../Config/Conexion.php");

    $id = $_POST['Id'];
    $categoria = $_POST['Categorias'];
    $marcas = $_POST['Marcas'];
    $precio = $_POST['Precio'];
    $descripcion = $_POST['Descripcion'];
    $nombre = $_POST['Nombre'];

    $sql = "UPDATE productos SET
            categoriaId='".$categoria."',
            MarcaId='".$marcas."',
            Precio='".$precio."',
            DescripcionProducto='".$descripcion."',
            Nombre='".$nombre."' WHERE IdProducto = '".$id."'";

    if($resultado = $conexion->query($sql)) {
        header('location:../index.php');
    }
    
?>
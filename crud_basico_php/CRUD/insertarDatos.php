<?php
    include("../Config/Conexion.php");
    
    $categoria = $_POST['CategoriaP'];
    $marca = $_POST['MarcaP'];
    $precio = $_POST['Precio'];
    $descripcion = $_POST['Descripcion'];
    $nombre = $_POST['Nombre'];

    $sql = "INSERT INTO productos(CategoriaId,MarcaId,Precio,DescripcionProducto,Nombre) VALUES
    ('$categoria','$marca','$precio','$descripcion','$nombre')";

    $resultado = mysqli_query($conexion,$sql);

    if($resultado == true)
    {
        header("location:../index.php");
    }
    else {
        echo "Datos NO insertados";
    }
?>
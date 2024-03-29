<!doctype html>
<html lang="es">

<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>CRUD RELACIONAL</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.1/dist/css/bootstrap.min.css" rel="stylesheet"
        integrity="sha384-4bw+/aepP/YC94hEpVNVgiZdgIC5+VKNBQNGCHeKRQN+PtmoHDEXuppvnDJzQIu9" crossorigin="anonymous">
</head>

<body>
    <br>

    <div class="container">
        <h1 class="text-center" style="background-color: black; color: white;">LISTADO DE PRDUCTOS</h1>
    </div>

    <br>

    <div class="container">
        <table class="table">
            <thead>
                <tr>
                    <th scope="col">ID</th>
                    <th scope="col">Categoria</th>
                    <th scope="col">Marca</th>
                    <th scope="col">Precio</th>
                    <th scope="col">Descripcion</th>
                    <th scope="col">Nombre</th>
                    <th scope="col">Acciones</th>
                </tr>
            </thead>
            <tbody>
                <?php
                    require("Config/Conexion.php");

                    $sql = $conexion->query("SELECT * FROM productos
                        INNER JOIN categorias ON productos.CategoriaId = categorias.Id 
                        INNER JOIN marcas ON productos.MarcaId = marcas.Id
                    ");

                    while($resultado = $sql->fetch_assoc()) {       
                ?>

                    <tr>
                        <th> <?php echo $resultado['IdProducto'];?> </th>
                        <th> <?php echo $resultado['NombreCategoria'];?> </th>
                        <th> <?php echo $resultado['NombreMarca'];?> </th>
                        <th> <?php echo $resultado['Precio'];?> </th>
                        <th> <?php echo $resultado['DescripcionProducto'];?> </th>
                        <th> <?php echo $resultado['Nombre'];?> </th>
                        <th> <!-- Mapear el ID para enviarselo como parameto -->
                            <a href="Formularios/EditarForm.php?Id=<?php echo $resultado['IdProducto']; ?>" class="btn btn-warning">Editar</a>
                            <a href="CRUD/EliminarDatos.php?Id=<?php echo $resultado['IdProducto']; ?>" class="btn btn-danger">Eliminar</a>
                        </th>
                    </tr>
                <?php

                }

                ?>

            </tbody>
        </table>
        <div class="container">
            <a href="Formularios/AgregarForm.php" class="btn btn-success">Agregar Producto</a>
            
        </div>

    </div>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.1/dist/js/bootstrap.bundle.min.js"
        integrity="sha384-HwwvtgBNo3bZJJLYd8oVXjrBZt8cqVSpeBNS5n7C8IVInixGAoxmnlMuBnhbgrkm" crossorigin="anonymous">
    </script>
</body>

</html>
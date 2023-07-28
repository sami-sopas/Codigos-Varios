<!doctype html>
<html lang="en">

<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Editar Producto</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.1/dist/css/bootstrap.min.css" rel="stylesheet"
        integrity="sha384-4bw+/aepP/YC94hEpVNVgiZdgIC5+VKNBQNGCHeKRQN+PtmoHDEXuppvnDJzQIu9" crossorigin="anonymous">
</head>

<body>
    <h1 class="text-center" style="background-color: black; color: white;">EDITAR PRDUCTOS</h1>
    <br>
    <form class="container" action="../CRUD/EditarDatos.php" method="POST">

        <!-- TRAER DATOS DE LA TABLA PRODUCTOS -->
        <?php
            //Nos traemos los datos del producto a editar
            include_once('../Config/Conexion.php');

            //Aqui seleccionamos el producto que coincida con el ID que enviamos desde el Index como parametro
            $sql = "SELECT * FROM productos where IdProducto =".$_REQUEST['Id'];

            $resultado = $conexion->query($sql);

            //Asociamos el resultado con un fetch_assoc
            $row = $resultado->fetch_assoc();

        ?>

        <!-- INPUT HIDDEN PARA TRAER EL ID DE MANERA OCULTO, MAPEARLO Y ENVIARLO A 
            EditarDatos.php PARA MODIFICARLO-->
        <input type="hidden" class="form-control" name="Id" value="<?php echo $row['IdProducto']; ?>" >

        <!-- TRAER DATOS CATEGORIA (TABLA RELACIONADA) -->

        <label class="form-label">Categorias</label>
        <select class="form-select mb-3" aria-label="Default select example" name="Categorias">
            <option selected disabled>--Seleccione Categorias--</option>
            <?php

                //CONSULTA PARA TRAER LA CATEGORIA SELECCIONADA
                include("../Config/Conexion.php");

                $sql1 = "SELECT * FROM categorias WHERE Id =".$row['CategoriaId'];

                $resultado1 = $conexion->query($sql1);

                $row1 = $resultado1->fetch_assoc();

                //el selected es el que hace que aparezca seleccionada esa opcion y no otra
                echo "<option selected value='".$row1['Id']."'>".$row1['NombreCategoria']."</option>";

                //CONSULTA PARA TRAER LAS DEMAS CATEGORIAS PARA ASI PUEDA ELEGIR OTRAS OPCIONES

                $sql2 = "SELECT * FROM categorias";

                $resultado2 = $conexion->query($sql2);

                //fetch assoc y array es lo mismo para este caso
                while($fila = $resultado2->fetch_array())
                {
                    echo "<option value='".$fila['Id']."'>".$fila['NombreCategoria']."</option>";
                }

            ?>
        </select>
        <label class="form-label">Marcas</label>
        <select class="form-select mb-3" aria-label="Default select example" name="Marcas">
            <option selected disabled>--Seleccione Marcas--</option>
            <?php

                //CONSULTA PARA TRAER LA MARCA SELECCIONADA
                include("../Config/Conexion.php");
                
                //Recordar que el ID lo enviamos como parametro desde el index
                $sql3 = "SELECT * FROM marcas WHERE Id =".$row['MarcaId'];

                $resultado3 = $conexion->query($sql3);

                $row3 = $resultado3->fetch_assoc();

                //el selected es el que hace que aparezca seleccionada esa opcion y no otra
                echo "<option selected value='".$row3['Id']."'>".$row3['NombreMarca']."</option>";

                //CONSULTA PARA TRAER LAS DEMAS CATEGORIAS PARA ASI PUEDA ELEGIR OTRAS OPCIONES

                $sql4 = "SELECT * FROM marcas";

                $resultado4 = $conexion->query($sql4);

                //fetch assoc y array es lo mismo para este caso
                while($Fila = $resultado4->fetch_array())
                {
                    echo "<option value='".$Fila['Id']."'>".$Fila['NombreMarca']."</option>";
                }

            ?>
        </select>
        <div class="mb-3">
            <label class="form-label">Precio</label>
            <input type="text" class="form-control" name="Precio" value="<?php echo $row['Precio'] ?>">
        </div>
        <div class="mb-3">
            <label class="form-label">Descripcion</label>
            <input type="text" class="form-control" name="Descripcion" value="<?php echo $row['DescripcionProducto'] ?>">
        </div>
        <div class="mb-3">
            <label class="form-label">Nombre</label>
            <input type="text" class="form-control" name="Nombre" value="<?php echo $row['Nombre'] ?>">
        </div>
        <div class="text-center">
            <button type="submit" class="btn btn-danger">Agregar</button>
            <a href="../index.php" type="submit" class="btn btn-dark">Regresar</a>
        </div>
    </form>


    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.1/dist/js/bootstrap.bundle.min.js"
        integrity="sha384-HwwvtgBNo3bZJJLYd8oVXjrBZt8cqVSpeBNS5n7C8IVInixGAoxmnlMuBnhbgrkm" crossorigin="anonymous">
    </script>
</body>

</html>
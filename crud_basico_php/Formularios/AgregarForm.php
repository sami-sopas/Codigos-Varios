<!doctype html>
<html lang="es">

<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Agregar Producto</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.1/dist/css/bootstrap.min.css" rel="stylesheet"
        integrity="sha384-4bw+/aepP/YC94hEpVNVgiZdgIC5+VKNBQNGCHeKRQN+PtmoHDEXuppvnDJzQIu9" crossorigin="anonymous">
</head>

<body>
    <h1 class="bg-black p-2 text-white text-center">Agregar producto</h1>
    <br>
    <div class="container">
        <form action="../CRUD/insertarDatos.php" method="POST">
            <label for="" class="mb-3">Categorias</label>
            <select class="form-select mb-3" name="CategoriaP">
                <option selected disabled>--Seleccionar categoria--</option>
                <?php
                    include("../Config/Conexion.php");

                    $sql = $conexion->query("SELECT * FROM categorias"); //calarle despues hacer un SELECT NOMBRE FROM

                    while($resultado = $sql->fetch_assoc()) {
                        echo "<option value='".$resultado['Id']."'>".$resultado['NombreCategoria']."</option>";
                    }
                ?>
            </select>
            <label for="" class="mb-3">Marcas</label>
            <select class="form-select mb-3" name="MarcaP">
                <option selected disabled>--Seleccionar marca--</option>
                <?php
                    include("../Config/Conexion.php");

                    $sql = $conexion->query("SELECT * FROM marcas"); //calarle despues hacer un SELECT NOMBRE FROM

                    while($resultado = $sql->fetch_assoc()) {
                        echo "<option value='".$resultado['Id']."'>".$resultado['NombreMarca']."</option>";
                    }
                ?>
            </select>
            <div class="mb-3">
                <label class="form-label">Precio</label>
                <input type="text" class="form-control" name="Precio">
            </div>
            <div class="mb-3">
                <label class="form-label">Descripcion</label>
                <input type="text" class="form-control" name="Descripcion">
            </div>
            <div class="mb-3">
                <label class="form-label">Nombre</label>
                <input type="text" class="form-control" name="Nombre">
            </div>

            <div class="text-center">
                <button type="submit" class="btn btn-danger">Enviar</button>
                <a href="../Index.php" class="btn btn-dark">Regresar</a>
            </div>
        </form>
    </div>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.1/dist/js/bootstrap.bundle.min.js"
        integrity="sha384-HwwvtgBNo3bZJJLYd8oVXjrBZt8cqVSpeBNS5n7C8IVInixGAoxmnlMuBnhbgrkm" crossorigin="anonymous">
    </script>
</body>

</html>
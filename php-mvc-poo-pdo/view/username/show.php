<?php
    //LLamando a la vista del header
    require_once("C://xampp/htdocs/php-mvc-poo-pdo/view/head/head.php");

    //LLamando al controlador del susuario
    require_once("C://xampp/htdocs/php-mvc-poo-pdo/controller/usernameController.php");

    //Creamos una nueva instancia del objeto
    $obj = new usernameController();

    //Recordar que enviamos el id mediante la url
    //Asi que obtenemos de aqui el valor con el metodo get
    // y los almacenamos en esta variable date
    $date = ($obj->show($_GET['id']));

    //print_r($date);
?>
    <h2 class="text-center">Detalles del registro</h2>

    <div class="pb-3">
        <a href="index.php" class="btn btn-primary">Volver</a>
        <a href="edit.php?id=<?= $date['0'] ?>" class="btn btn-success">Actualizar</a>
         <!-- Button trigger modal -->
    <a class="btn btn-danger" data-bs-toggle="modal" data-bs-target="#exampleModal">Eliminar</a>
    </div>

    <!-- Modal -->
    <div class="modal fade" id="exampleModal" tabindex="-1" aria-labelledby="exampleModalLabel" aria-hidden="true">
    <div class="modal-dialog">
        <div class="modal-content">
        <div class="modal-header">
            <h1 class="modal-title fs-5" id="exampleModalLabel">¿Desea eliminar el registro?</h1>
            <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
        </div>
        <div class="modal-body">
            Una vez eliminado, no se podra recuperar
        </div>
        <div class="modal-footer">
            <button type="button" class="btn btn-danger" data-bs-dismiss="modal">Cerrar</button>
            <a href="delete.php?id=<?= $date['0']?>" class="btn btn-primary">Eliminar</a>
        </div>
        </div>
    </div>
    </div>

    <table class="table container-lg">
        <thead>
            <tr>
                <th scope="col">ID</th>
                <th scope="col">Nombre</th>
            </tr>
        </thead>

        <tbody>
            <tr> <!-- accedemos a 0 y 1 porque son los indices en donde estan nuestros datos -->
                 <!-- tambien podemos acceder a estos mediante su nombre (id,nombre) -->
                <td scope="col"> <?= $date['id'] ?> </td>
                <td scope="col"> <?= $date['nombre'] ?> </td>
            </tr>
        </tbody>
    </table>

<?php
    require_once("C://xampp/htdocs/php-mvc-poo-pdo/view/head/footer.php");
?>
<?php
    require_once("C:/xampp/htdocs/php-mvc-poo-pdo/view/head/head.php");

    //LLamando a controlador
    require_once("C:/xampp/htdocs/php-mvc-poo-pdo/controller/usernameController.php");

    ///Comprobacion de que retorna los registros
    $obj = new usernameController();

    ///Comprobacion de que retorna los registros
    //print_r($obj->index());

    //En esta variable guardamos todos los registros que nos regresa
    $rows = $obj->index();
?>

<div class="mb-3">
    <a href="/php-mvc-poo-pdo/view/username/create.php" class="btn btn-primary">Agregar nuevo usuario</a>
</div>

<table class="table">
    <thead>
        <tr>
            <th scope="col">ID</th>
            <th scope="col">Nombre</th>
            <th scope="col">Acciones</th>
        </tr>
    </thead>
    <tbody>
        <?php if($rows): ?>
            <?php foreach($rows as $row): ?>
                <tr>
                    <th> <?= $row['id'] ?> </th>
                    <th> <?= $row['nombre'] ?> </th>
                    <th>
                        <a href="show.php?id=<?= $row['id'] ?>" class="btn btn-primary">Ver</a>
                        <a href="edit.php?id=<?= $row['id'] ?>" class="btn btn-success">Actualizar</a>
                        <a class="btn btn-danger" data-bs-toggle="modal" data-bs-target="#exampleModal">Eliminar</a>
                    </th>
                </tr>
            <?php endforeach;?>

        <?php else: ?>
            <tr>
                <td colspan="3" class="text-center">No hay registros</td>
            </tr>

        <?php endif; ?>
    </tbody>
</table>

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
            <button type="button" class="btn btn-primary" data-bs-dismiss="modal">Cerrar</button>
            <a href="delete.php?id=<?= $row['id']?>" class="btn btn-danger">Eliminar</a>
        </div>
        </div>
    </div>
    </div>


<?php
    require_once("C:/xampp/htdocs/php-mvc-poo-pdo/view/head/footer.php");
?>
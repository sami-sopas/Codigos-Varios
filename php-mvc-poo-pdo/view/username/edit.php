<?php
    require_once("C:/xampp/htdocs/php-mvc-poo-pdo/view/head/head.php");

    //LLamando a controlador
    require_once("C:/xampp/htdocs/php-mvc-poo-pdo/controller/usernameController.php");

    $obj = new usernameController();

    $user = $obj->show($_GET['id']);

?>  

<form action="update.php" method="POST" autocomplete="off">
    <h2>Modificando registro</h2>
    <br>
    <div class="mb-3 row">
        <label for="staticEmail" class="col-sm-2 col-form-label">ID</label>
         <div class="col-sm-10">
        <input type="text" name="id" readonly class="form-control-plaintext" id="staticEmail" value="<?= $user['id']?>">
        </div>
    </div>

    <div class="mb-3 row">
        <label for="inputPassword" class="col-sm-2 col-form-label">Nuevo nombre</label>
        <div class="col-sm-10">
        <input type="text" name="nombre"class="form-control" id="inputPassword" value="<?= $user['nombre']?>">
        </div>
    </div>

    <div>
        <input class="btn btn-success" type="submit" value="Actualizar">
        <a class="btn btn-danger" href="show.php?id=<?= $user['id']?>">Cancelar</a>
    </div>
</form>

<?php
    require_once("C:/xampp/htdocs/php-mvc-poo-pdo/view/head/footer.php");
?>
<?php
    require_once("C://xampp/htdocs/php-mvc-poo-pdo/controller/usernameController.php");

    //Cremos una instancia del controlador
    $obj = new usernameController();

    //Le pasamos el nombre mediante el metodo post
    $obj->guardar($_POST["nombre"]);

?>
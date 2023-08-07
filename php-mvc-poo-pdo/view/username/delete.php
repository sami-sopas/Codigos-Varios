<?php
    //LLamando a controlador
    require_once("C:/xampp/htdocs/php-mvc-poo-pdo/controller/usernameController.php");

    $obj = new usernameController();

    $obj->delete($_GET['id']);
?>
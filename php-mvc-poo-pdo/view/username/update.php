<?php
      //LLamando a controlador
      require_once("C:/xampp/htdocs/php-mvc-poo-pdo/controller/usernameController.php");

      $obj = new usernameController();

      $obj->update($_POST['id'],$_POST['nombre']);

?>
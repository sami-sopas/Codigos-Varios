<?php

    //Variables sessions

    /*Sirve para mantener informacion en cualquier pagina
      cuando el navegador este abierto */

    session_start();

    $_SESSION["usuario"] = "develoteca";
    $_SESSION["estatus"] = "logueado";

    echo "Sesion iniciada"."<br>";

    echo "Usuario: ".$_SESSION["usuario"]." Estatus: ".$_SESSION["estatus"];

?>
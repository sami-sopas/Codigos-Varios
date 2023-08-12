<?php

    class View {

        function __construct()
        {
            //echo "<p>Vista base</p>";
        }

        //Cargar la vista de acuerdo al nombre
        function render($nombre)
        {
            require 'views/' . $nombre . '.php';
        }

    }
?>
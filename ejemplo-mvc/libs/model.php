<?php
    //Cada modelo tendra una conexion a la base de datos

    class Model {

        public $db;

        function __construct()
        {
            $this->db = new Database();
        }

    }
?>
<?php
    
    class usernameModel{
        private $PDO; //Atributo donde almacenaremos la conexion sql

        public function __construct()
        {
            //para traernos la base de datos
            require_once("C://xampp/htdocs/php-mvc-poo-pdo/config/db.php");
            $con = new db();
            $this->PDO = $con->conexion();
        }

        //Recibimos el dato que vamos a insertar a la bd
        public function insertar($nombre)
        {
            //accedemos al PDO (donde esta guardada la conexion a la BD)

            //Con :nombre estmamos utilizando un placeholder, para evitar poner
            //la variable directamente en la consulta
            $statment = $this->PDO->prepare("INSERT INTO username (nombre) VALUES (:nombre)");

            //Aqui vinculamos esa variable, con el placeholder
            $statment->bindParam(":nombre",$nombre);

            //If acortado
            //Si la sentencia se realiza, se regresa el ultimo ID del elemento insertado, si no regresamos un falso
            return ($statment->execute()) ? $this->PDO->lastInsertId() : false;
        }

        //Mostrar los datos dependiendo del id
        public function show($id)
        {
            $statment = $this->PDO->prepare("SELECT * FROM username where id = :id limit 1");
            $statment->bindParam(":id",$id);

            //Si la consulta se ejecuta...
            //Convertimos lo que nos regreso en un arreglo
            //Si no, retornamos falso
            return ($statment->execute()) ? $statment->fetch() : false;
        }

        //Mostrar todos los registros
        public function index()
        {
            $statment = $this->PDO->prepare("SELECT * FROM username");

            //Como aqui retornamos varios registros, usamos fetchAll
            return ($statment->execute()) ? $statment->fetchAll() : false;
        }

        //Actualizar registro
        public function update($id,$nombre)
        {
            $statment = $this->PDO->prepare("UPDATE username SET nombre = :nombre WHERE id = :id");

            $statment->bindParam(":nombre",$nombre);
            $statment->bindParam(":id",$id);

            //Si la sentencia se ejecuta, retornamos el id del registro
            return ($statment->execute()) ? $id : false;
        }

        //Eliminar registro
        public function delete($id)
        {
            $statment = $this->PDO->prepare("DELETE FROM username WHERE id = :id");

            $statment->bindParam(":id",$id);

            return ($statment->execute()) ? true : false;
        }
        
    }
?>
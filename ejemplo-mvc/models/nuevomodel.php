<?php
    //Aqui se realizaran las operaciones a la BD

    class NuevoModel extends Model{

        public function __construct()
        {
            parent::__construct(); //LLamamos al constructor del Model
        }

        //Recibimos el arreglo que mandamos desde controllers/nuevo.php
        public function insert($datos){
            //Insertar datos a la bd

            //Validamos el execute en caso de error, poder manejarlo
            try{
                $query = $this->db->connect()->prepare('INSERT INTO ALUMNOS (MATRICULA, NOMBRE, APELLIDO) VALUES (:matricula, :nombre, :apellido) ');
                $query->execute(['matricula' => $datos['matricula'], 'nombre' => $datos['nombre'],'apellido' => $datos['apellido']]);
                //echo "Insertar datos...";
                return true;
            }
            catch(PDOException $e)
            {
                //echo $e->getMessage();
                //echo "Ya existe esa matricula";
                return false;
            }
            
        }

    }
?>
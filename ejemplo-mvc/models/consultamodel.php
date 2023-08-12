<?php
    //Aqui se realizaran las operaciones a la BD

    include_once 'models/alumno.php';

    class ConsultaModel extends Model{

        public function __construct()
        {
            parent::__construct(); //LLamamos al constructor del Model
        }

        public function get(){
            $items = []; //Regresaremos un arreglo

            try{

                $query = $this->db->connect()->query("SELECT * FROM alumnos");

                while($row = $query->fetch())
                {
                    //Creacion de objeto y asignandole las propiedades
                    $item = new Alumno();
                    $item->matricula = $row['matricula'];
                    $item->nombre = $row['nombre'];
                    $item->apellido = $row['apellido'];

                    //Metemos al arreglo items el objeto item
                    array_push($items, $item);
                }

                return $items;

            }catch(PDOException $e)
            {
                return []; //Regresamos un arreglo vacio en caso de error
            }
            
        }

        public function getById($id)
        {
            $item = new Alumno();

            try{
                $query = $this->db->connect()->prepare("SELECT * FROM alumnos WHERE matricula = :matricula");
                $query->execute(['matricula' => $id]);

                while($row = $query->fetch()){
                    $item->matricula = $row['matricula'];
                    $item->nombre = $row['nombre'];
                    $item->apellido = $row['apellido'];
                }

                return $item; //Regresamos el objeto

            }catch(PDOException $e)
            {
                return null;
            }
        }

        //actualizar alumno
        public function update($item){
            $query = $this->db->connect()->prepare("UPDATE alumnos SET nombre = :nombre, apellido = :apellido WHERE matricula = :matricula");

            try{
                
                $query->execute([
                    'matricula' => $item['matricula'],
                    'nombre' => $item['nombre'],
                    'apellido' => $item['apellido']
                ]);

                return true;
            }catch(PDOException $e)
            {
                return false;
            }

        }

        public function delete($id){
            $query = $this->db->connect()->prepare("DELETE FROM alumnos WHERE matricula = :id");

            try{
                
                $query->execute([
                    'id' => $id,
                ]);

                return true;
            }catch(PDOException $e)
            {
                return false;
            }

        }

    }
?>
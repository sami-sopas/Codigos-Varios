<?php
    //Aqui se trabaja con las vistas y el modelo para poder realizar las consultas

    class usernameController{
        private $model; //Variable donde guardaremos la instancia de nuestro modelo
        
        public function __construct()
        {
            require_once("C://xampp/htdocs/php-mvc-poo-pdo/model/usernameModel.php");
            $this->model = new usernameModel();
        }

        public function guardar($nombre)
        {
            //Accedemos al metodo de insertar de la clase usernameModel
            //Recordemos que devuelve el id del elemento insertado si se hizo correctamente
            $id = $this->model->insertar($nombre);

            //Si me devuelve algo diferente de falso (se inserto correctamente), lo posicionamos en una vista para mostrarlo
            //Caso contrario, lo regresamos a la vista para crear usuario 
            return ($id != false) ? header("Location:show.php?id=".$id) : header("Location:create.php");
        }

        public function show($id)
        {
            //Si la consulta funciono, regresamos el arreglo con los datos que nos trajo
            //Si no lo regresamos al inicio
            return ($this->model->show($id) != false) ? $this->model->show($id) : header("Location:index.php");
        }
        
        public function index()
        {
            //Si se cumple la funcion, entonces retornamos ese arreglo con la informacion
            //Si no regresamos un falso
            return ($this->model->index()) ? $this->model->index() : false;
        }

        public function update($id,$nombre)
        {
            //Si se cumple la update, lo movemos a la opcion para mostrar ese registro con ese id
            //Si no se cumple, lo regresamos al index
            return ($this->model->update($id,$nombre) != false) ? header("Location: show.php?id=".$id) : header("Location: index.php");
        }

        public function delete($id)
        {
            return ($this->model->delete($id) != false) ? header("Location: index.php") : header("Location: show.php?id=".$id) ;
        }
    }
?>
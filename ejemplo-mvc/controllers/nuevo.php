<?php

class Nuevo extends Controller{

    function __construct(){

        //LLamando al constructor de controler
        parent::__construct();
        $this->view->mensaje = "";

        //$this->view->render('nuevo/index');

        //echo "<p>Nuevo controlador Main</p>";
    }

    //Funcion para cargar la vista aparte y no directamente en el constructor
    function render()
    {
        $this->view->render('nuevo/index');
    }

    //Esta funcion se manda a llamar desde views/nuevo/index
    function registrarAlumno()
    {
        //En el controlador hacemos las verificaciones que sean necesarias
        $matricula = $_POST['matricula'];
        $nombre = $_POST['nombre'];
        $apellido = $_POST['apellido'];

        $mensaje = "";

        //LLamamos al modelo para registrar el cambio

        //pasamos la informacion a traves de un arreglo
        if($this->model->insert(['matricula' => $matricula, 'nombre' => $nombre, 'apellido' => $apellido])){
            $mensaje = "Nuevo alumno creado";
        }else{
            $mensaje = "Matricula ya existe";
        }

        //Cargando mensaje para mostrarlo en la vista
        $this->view->mensaje = $mensaje;

        //Cargamos de nuevo la vista para ver el mensaje ahora centrado
        $this->render();
    }
}

?>
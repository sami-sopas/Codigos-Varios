
<?php

class Main extends Controller{

    function __construct(){

        //LLamando al constructor de controler
        parent::__construct();

        //$this->view->render('main/index');

        //echo "<p>Nuevo controlador Main</p>";
    }

    //Funcion para cargar la vista aparte y no directamente en el constructor
    function render()
    {
        $this->view->render('main/index');
    }

    function saludo(){
        echo "<p>Ejecutaste el método Saludo</p>";
    }
}

?>
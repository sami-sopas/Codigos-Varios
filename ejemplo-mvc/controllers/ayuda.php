<?php

    class Ayuda extends Controller{

        function __construct()
        {
            parent::__construct();
            //$this->view->render('ayuda/index');
        }

        //Funcion para cargar la vista aparte y no directamente en el constructor
        function render()
        {
            $this->view->render('ayuda/index');
        }
    }
?>
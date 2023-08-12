<?php

    //Dependiendo de lo que envie l a vista, es con lo que trabajara el modelo

    class Controller {

        public $view;
        public $model;

        function __construct()
        {
           // echo "<p>Controlador base</p>";

            //Ligando controlador con una vista
            $this->view = new View();
        }

        //FUncion para que acepte nuestro modelo
        function loadModel($model){

            //Construimos la url de la ubicacion del modelo
            $url = 'models/' . $model . 'model.php';

            //validamos que exista ese archivo
            if(file_exists(($url)))
            {
                require $url; //incrustamos la url aqui

                $modelName = $model . 'Model';
                $this->model = new $modelName(); //Modelo creado
            }

        }


    }
?>
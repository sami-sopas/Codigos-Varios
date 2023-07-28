<?php

    //Uso de Herencia

    class Persona {

        //Atributos
        public $nombre;
        private $edad; //Solo se puede acceder en la clase que lo definio
        protected $altura; //Solo se puede acceder por la misma clases y sus herencias

        //Metodos
        public function asignarNombre($nuevoNombre)
        {
            $this->nombre = $nuevoNombre;
        }

        public function imprimirNombre()
        {
            echo "Hola soy ".$this->nombre;
        }

        public function mostrarEdad()
        {
            $this->edad = 20;
            return $this->edad;
        }

    }

    //Trabajador hereda lo de persona
    class Trabajador extends Persona{

        public $puesto;

        public function presentarse()
        {
            echo "Hola soy".$this->nombre." y soy un ".$this->puesto;
        }

    }

    //Crear un nuevo objeto
    $objTrabajador = new Trabajador();

    //LLamar a metodo de objeto
    $objTrabajador->asignarNombre("Oscar");

    $objTrabajador->puesto = "Profesor";

    //echo $objTrabajador->puesto;

    $objTrabajador->presentarse();



?>
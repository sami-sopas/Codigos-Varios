<?php
    //Uso de constructores

    class Persona {

        //Constructor
        function __construct($nuevoNombre)
        {
            $this->nombre = $nuevoNombre;
        }

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

    //Crear un nuevo objeto
    $objAlumno = new Persona("Oscar");

    $objAlumno->imprimirNombre();





?>
<?php
    //Uso de clases

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

    //Crear un nuevo objeto
    $objAlumno = new Persona();

    //LLamar a metodo de objeto
    $objAlumno->asignarNombre("Oscar");

    //Acceder a atributo del objeto
    echo $objAlumno->nombre;

    $objAlumno2 = new Persona();

    $objAlumno2->asignarNombre("Pedro");

    echo $objAlumno2->nombre;

    echo "<br>";

    $objAlumno->imprimirNombre();
    $objAlumno2->imprimirNombre();

    echo $objAlumno2->mostrarEdad();

?>
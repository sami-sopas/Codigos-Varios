<?php

    include_once("db.php");

    class Survey extends DB{

        private $totalVotes; //Conteo del numero total de votos
        private $optionSelected; //Opcion que el ususario selecciona, aqui se guarda el valor

        public function setOptionSelected($option)
        {
            //Cuando de click, llamo la funcion para enviarle la opcion seleccionada
            $this->optionSelected = $option;
        }

        public function getOptionSelected()
        {
            return $this->optionSelected;
        }

        public function vote()
        {
            //Recordar que connect lo herdamos de DB                                                //placeholder
            $query = $this->connect()->prepare('UPDATE lenguajes SET votos = votos + 1 WHERE opcion = :opcion');

            //Aqui cambiamos el placeholder por una variable real
            $query->execute(['opcion' => $this->optionSelected]);
        }

        public function showResults()
        {
            //Esto regresa un objeto con todos los valores de las consultar
            return $this->connect()->query("SELECT * FROM lenguajes");
        }

        public function getTotalVotes()
        {
            //Consulta que regresa la suma de los votos
            $query = $this->connect()->query("SELECT SUM(votos) AS votos_totales FROM lenguajes");

            //Con Fetch parseamos los resultados como un objeto y accedemos a la columna votos_totales
            $this->totalVotes = $query->fetch(PDO::FETCH_OBJ)->votos_totales;

            //Finalmente retornamos el numero total de votos
            return $this->totalVotes;
        }

        //Funcion para obtener porcentaje de votos, recibe los votos de la opcion
        public function getPercentageVotes($votes)
        {
            //Dividimos los votos de esa opcion por la cantidad total y multiplicamos por 100
            //finalmente redondeamos
            return round(($votes / $this->totalVotes) * 100,0);
        }
    }
?>
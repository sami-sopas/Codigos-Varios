<?php
    include_once ('db.php');

    class Peliculas extends DB{

        private $paginaActual; //Guarda el valor de la pagina actual
        private $totalPaginas; //Guarda el numero de paginas generadas a partir de los resultados
        private $nResultados; //Numero de registros
        private $resultadosPorPagina; //Guarda el numero de resultados que quiero mostrar x pagina
        private $indice; //Variable para guardar el elemento de la pagina en la que estoy

        private $error = false; //Detectar algun error
    

    //Recibimos el numero de resultados que queramos mostrar por pagina
    function __construct($nPorPagina)
    {
        //Inicializar constructor de la base de datos (DB)
        parent::__construct(); 

        //Guardamos los resultados que queremos mostrar por pagina
        $this->resultadosPorPagina = $nPorPagina;

        //Ponemos el indice en 0
        $this->indice = 0;

        //Definimos la pagina que queremos visitar (por defecto la primera)
        $this->paginaActual = 1;

        $this->calcularPaginas();
    }

    //Funcion para calcular el numero de paginas y actualizar los valores
    function calcularPaginas()
    {
        //Regresa el numero de registros
        $query = $this->connect()->query('SELECT COUNT(*) AS total FROM pelicula');

        //Lo igualamos al numero de resultados totales, extraemos del objeto que devuelve, la columna total
        $this->nResultados = $query->fetch(PDO::FETCH_OBJ)->total;

        //Calculamos el numero total de paginas
        $this->totalPaginas = $this->nResultados / $this->resultadosPorPagina;

        //Si se hace un envio de la variable pagina...
        if(isset($_GET['pagina']))
        {
            //Validar que pagina sea un numero
            if(is_numeric($_GET['pagina']))
            {
                //Validar que pagina sea mayor o igual a 1 y menor  o igual a total
                if($_GET['pagina'] >= 1  && $_GET['pagina'] <= round($this->totalPaginas))
                {
                     //Una vez validado, Actualizamos el indice y la pagina actual
                     $this->paginaActual = $_GET['pagina'];

                     //                          1             *                 3            = 3 (mostrar registros a partir de ahi)
                     $this->indice = ($this->paginaActual - 1) * ($this->resultadosPorPagina);
                }
                else
                {
                    echo "No existe esa pagina";
                    $this->error = true;
                }
            }
            else
            {
                echo "Error al mostrar la pagina";
                $this->error = true;
            }
            

        
        }
    }

    //Funcion para mostrar peliculas
    function mostrarPeliculas()
    {
        if(!$this->error == true)
        {
            //Continuar (no hay error)

            //indicamos de que posicion de la tabla queremos que apunte con pos y con n mostramos la cantidad
            $query = $this->connect()->prepare('SELECT * FROM pelicula LIMIT :pos, :n');

            //Hacemos los binding de la posicion y el numero de elementos 
            $query->execute(['pos' => $this->indice, 'n' => $this->resultadosPorPagina]);

            foreach($query as $pelicula)
            {
                include 'vista-peliculas.php';
            }
        }else
        {
            echo "Error";
        }
    }

    //Funcion para mostrar las paginas
    function mostrarPaginas()
    {
        //Identificar pagina actual
        $actual = '';

        echo "<ul>";

        //Imprimir todas las paginas
        for($i = 0; $i < $this->totalPaginas; $i++)
        {
            if($i + 1 == $this->paginaActual)
            {
                $actual = ' class="actual" ';
            }
            else{
                $actual = '';
            }

            echo '<li> <a href="?pagina=' . ($i + 1) . '" ' . $actual . '  >' . ($i + 1) . '</a> </li>';
        }
        echo "</ul>";
    }

}

?>
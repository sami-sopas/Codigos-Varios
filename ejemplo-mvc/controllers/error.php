<?

class MyError extends Controller{

    function __construct(){
        
        //LLamando al constructor de controler
        parent::__construct();

        //Transmitir un mensaje a traves del controlador
        $this->view->mensaje = "Hubo un error o no existe la pagina";

        $this->view->render('error/index');

        //echo "<p>Error al cargar recurso</p>";

    }

}

?>
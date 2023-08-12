<?
require_once 'controllers/error.php';

class App{

    function __construct(){
        //echo "<p>Nueva app</p>";

        //en caso de que no se acceda mediante a un controlador directamente
        $url = isset($_GET['url']) ? $_GET['url'] : null;
        $url = rtrim($url, '/');
        $url = explode('/', $url);

        //SI NO ENCUENTRA NINGUN CONTROLADOR EN LA URL, CARGAMOS LA MAIN
        if(empty($url[0])){
            //var_dump($url);
            $archivoController = 'controllers/main.php';
            //mandamos a llamar al controlador que se acaba de crear
            require_once $archivoController;
            //creamos un nuevo controlador
            $controller = new Main();
            $controller->loadModel('main'); //llamando al modelo
            $controller->render(); //Cargamos las vistas
            return false;

        }
        //SI NO VALIDAMOS LO DEMAS
        $archivoController = 'controllers/' . $url[0] . '.php';

        //CUANDO EXISTE YA UN CONTROLADOR
        if(file_exists($archivoController)){
            require_once $archivoController;

            //inicializar controlador

            //Posicion [0] = para el controlador
            //Posicion [1] = para el metodo
            //Posicion [>2] = posibles parametros

            $controller = new $url[0];
            $controller->loadModel($url[0]); //LLamando al modelo

            //Sacamos el numero de parametros que tenga la url
            $nparam = sizeof($url);

            if($nparam > 1)
            {
                if($nparam > 2) //Cuando hay mas de 2 elementos, es porque hay parametros
                {
                    $param = [];  
                    for($i = 2; $i < $nparam; $i++)
                    {
                        array_push($param,$url[$i]);
                    }                  
                    //Con esto mandamos a llamar al metodo con sus parametros
                    $controller->{$url[1]}($param);
                }
                else{
                    //Si no hay parametros, entonces solo llamamos al metodo
                    $controller->{$url[1]}();
                }
            }
            else{
                //Renderizamos la vista por default
                $controller->render();
            }

            /*si hay un metodo que se requiere cargar
            if(isset($url[1])){
                $controller->{$url[1]}();
            }
            else{
                //Carguemos un metodo o no, aun asi cargamos la vista
                $controller->render();
            } */

        }else{
            $controller = new MyError();
        }
    }
}

?>
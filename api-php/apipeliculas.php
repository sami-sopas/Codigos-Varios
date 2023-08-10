<?php
    include_once 'pelicula.php';

    class ApiPeliculas{

        private $imagen;
        private $error; //variable para manejar los errores de subir imagen

        //Funcion que traera al objeto pelicula y lo convertira a JSON
        function getAll()
        {
            $pelicula = new Pelicula();

            //Declaramos un arreglo de peliculas
            $peliculas = array();

            //Al arreglo, le agregamos el elemento items de tipo ARRAY
            $peliculas["items"] = array();

            $res = $pelicula->obtenerPeliculas();

            //Validar que haya elementos 
            if($res->rowCount())
            {
                //Convertimos a objeto lo que vino de la query y se los asignamos al arreglo
                while($row = $res->fetch(PDO::FETCH_ASSOC))
                {
                    //PRIMER ELEMENTO CON INDICES ASOCIADOS (id,nombre, imagen)
                    $item = array(
                        'id' => $row['id'],
                        'nombre' => $row['nombre'],
                        'imagen' => $row['imagen']
                    );
                    
                    //Metemos al array peliculas, estos elementos
                    array_push($peliculas['items'],$item);
                }

                //Parseamos a JSON el arreglo y lo imprimimos
                //echo json_encode($peliculas);
                $this->printJSON($peliculas);
            }
            else
            {
                //echo json_encode(array('mensaje' => 'No hay elementos registrados'));
                $this->error('No hay elementos registrados');
            }

        }

        function getById($id)
        {
            $pelicula = new Pelicula();

            //Declaramos un arreglo de peliculas
            $peliculas = array();

            //Al arreglo, le agregamos el elemento items de tipo ARRAY
            $peliculas["items"] = array();

            $res = $pelicula->obtenerPelicula($id);

            //Validar que regrese un elemento
            if($res->rowCount() == 1)
            {
                $row = $res->fetch();

                //CREACION DEL PRIMER ELEMENTO CON INDICES ASOCIADOS (id,nombre, imagen)
                $item = array(
                    'id' => $row['id'],
                    'nombre' => $row['nombre'],
                    'imagen' => $row['imagen']
                );
                    
                //Metemos al array peliculas, estos elementos
                array_push($peliculas['items'],$item);
                

                //Parseamos a JSON el arreglo y lo imprimimos
                //echo json_encode($peliculas);
                $this->printJSON($peliculas);
            }
            else
            {
                //echo json_encode(array('mensaje' => 'No hay elementos registrados'));
                $this->error('No hay elementos registrados');
            }

        }

        //Funcion para insertar por medio de la api
        function add($item)
        {
            $pelicula = new Pelicula();

            $res = $pelicula->nuevaPelicula($item);

            $this->exito('Nueva pelicula registrada');
        }

        function printJSON($array)
        {
            echo '<code>' . json_encode($array) . '</code>';
        }

        function exito($mensaje)
        {
            echo '<code>' . json_encode($mensaje) . '</code>';
        }

        function error($mensaje)
        {
            echo '<code>' . json_encode(array('mensaje' => $mensaje)) . '</code>';
        }

        function subirImagen($file){
            $directorio = "imagenes/";
    
            $this->imagen = basename($file["name"]);
            $archivo = $directorio . basename($file["name"]);
    
            $tipoArchivo = strtolower(pathinfo($archivo, PATHINFO_EXTENSION));
        
            // valida que es imagen
            $checarSiImagen = getimagesize($file["tmp_name"]);
    
            if($checarSiImagen != false){
                //validando tamaño del archivo
                $size = $file["size"];
    
                if($size > 500000){
                    $this->error = "El archivo tiene que ser menor a 500kb";
                    return false;
                }else{
    
                    //validar tipo de imagen
                    if($tipoArchivo == "jpg" || $tipoArchivo == "jpeg"){
                        // se validó el archivo correctamente
                        if(move_uploaded_file($file["tmp_name"], $archivo)){
                            //echo "El archivo se subió correctamente";
                            return true;
                        }else{
                            $this->error = "Hubo un error en la subida del archivo";
                            return false;
                        }
                    }else{
                        $this->error = "Solo se admiten archivos jpg/jpeg";
                        return false;
                    }
                }
            }else{
                $this->error = "El documento no es una imagen";
                return false;
            }
        }

        function getImagen()
        {
            return $this->imagen;
        }

        function getError()
        {
            return $this->error;
        }
        
    }
    

?>
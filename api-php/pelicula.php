<?php
    include_once('db.php');

    //Esta clase solo trata con la base de datos
    class Pelicula extends DB{

        //Retornaremos un objeto con todas las peliculas
        function obtenerPeliculas()
        {
            $query = $this->connect()->query("SELECT * FROM pelicula");

            return $query;
        }

        //Funcion para obtener solo una pelicula
        function obtenerPelicula($id)
        {
            $query = $this->connect()->prepare('SELECT * FROM pelicula WHERE id = :id');
            $query->execute(['id' => $id]);

            return $query; //Retornamos el objeto
        }

        //Funcion para ingresar datos, recibe un arreglo con indice nombre e imagen
        function nuevaPelicula($pelicula)
        {
            $query = $this->connect()->prepare('INSERT INTO pelicula (nombre,imagen) VALUES (:nombre,:imagen)');
            $query->execute(['nombre' => $pelicula['nombre'], 'imagen' => $pelicula['imagen']]);

            return $query; //Retornamos el obje 
        }
    }
?>
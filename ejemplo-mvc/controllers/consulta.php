<?php

class Consulta extends Controller{

    function __construct(){

        //LLamando al constructor de controler
        parent::__construct();
        $this->view->alumnos = [];

        //$this->view->render('consulta/index');

        //echo "<p>Nuevo controlador Main</p>";
    }


     function render()
     {
        //Cargaremos la informacion en el render
        $alumnos = $this->model->get();
        $this->view->alumnos = $alumnos;

        $this->view->render('consulta/index');

     }

     //Cargar vista para ver detalles del alumno
     function verAlumno($param = null)
     {
       // var_dump($param); comprobar que si envia los parametros
       $idAlumno = $param[0];
       $alumno = $this->model->getById($idAlumno);

       //Activamos una sesion con el id del alumno
       session_start();
       $_SESSION['id_verAlumno'] = $alumno->matricula;

       $this->view->alumno = $alumno; //Pasarle el objeto a la vista
       $this->view->mensaje = "";

       //Renderizar la vista para ver los detalles
       $this->view->render('consulta/detalle');
     }

     //Actualizar en la BD al alumno
     function actualizarAlumno()
     {
      session_start();
      //tomamos el id de la sesion que inciciamos en verAlumno, para evitar que modificen esa info
      $matricula = $_SESSION['id_verAlumno'];
      $nombre = $_POST['nombre'];
      $apellido = $_POST['apellido'];

      //Destruimos la sesion
      unset($_SESSION['id_verAlumno']);

      if($this->model->update([
        'matricula' => $matricula,
        'nombre' => $nombre,
        'apellido' => $apellido
      ]))
      {
        // actualizar alumno exito
        $alumno = new Alumno();
        $alumno->matricula = $matricula;
        $alumno->nombre = $nombre;
        $alumno->apellido = $apellido;

        //Enviamos el obj alumno a la vista, recordar que el index de consulta ya recibe un obj
        $this->view->alumno = $alumno;
        $this->view->mensaje = "alumno actualizado";

      }
      else{
        $this->view->mensaje = "Error al actualizar alumno";
      }

      //Cargamos la vista
      $this->view->render("consulta/detalle");

     }

     //eliminar en la BD
     function eliminarAlumno($param = null)
     {
        //Mapeamos la matricula
        $matricula = $param[0];

        if($this->model->delete($matricula))
        {
          $this->view->mensaje = "Alumno eliminado correctamente";

        }else{
          $this->view->mensaje = "No se pudo eliminar el alumno";
        }

        //Despes de eliminar renderizamos la pagina inicial
        $this->view->render("consulta/index");
     }



 
    
}

?>
<?php

    $txtNombre = "";
    $rdgLenguaje = "";

    $chkphp = "";
    $chkhtml = "";
    $chkcss = "";

    $lsAnime = "";

    $txtComentario = "";

    if($_POST)
    {
        //if ternario: si hay informacion...        asignaselo         si no, dejalo vacio
        $txtNombre = (isset($_POST['txtNombre'])) ? $_POST['txtNombre'] : "" ;
        $rdgLenguaje = (isset($_POST['lenguaje'])) ? $_POST['lenguaje'] : "" ;

        //          si el valor que viene es "si", lo marcamos como checked
        $chkphp = (isset($_POST['chkphp']) == "si") ? "checked" : "" ;
        $chkhtml = (isset($_POST['chkhtml']) == "si") ? "checked" : "" ;
        $chkcss = (isset($_POST['chkcss']) == "si") ? "checked" : "" ;

        $lsAnime = ( isset($_POST['lsAnime']) )? $_POST['lsAnime'] : "";

        $txtComentario = ( isset($_POST['txtComentario'])) ? $_POST['txtComentario']:"";

        //print_r($_POST); // para ver que informacion se proceso

        //Aqui se pueden escribir instrucciones
        //Alterar valores
        //Realizar operaciones
    }


?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Formulario</title>
</head>
<body>

    <?php if($_POST){ ?> <!-- Codigo embebido php para mostrar los envios -->

    <strong>Hola</strong>: 
    <?php echo $txtNombre ?>
    <br>

    <strong>Tu lenguaje es: </strong> 
    <?php echo $rdgLenguaje ?>
    <br>

    <strong>Estas aprendiendo: </strong> <br>
    -<?php echo ($chkphp == "checked") ? "PHP":""?> <br>
    -<?php echo ($chkhtml == "checked") ? "HTML":""?> <br>
    -<?php echo ($chkcss == "checked") ? "CSS":""?> <br>

    <strong>Estas viendo:</strong>
    <?php echo $lsAnime; ?>
    <br><br>

    <strong>Tu mensaje es:</strong>
    <?php echo $txtComentario; ?>
    <br><br>

    <?php } ?>

    <form action="ejercicio31.php" method="post">
    
        <!-- Para no perder el valor del input al enviar la informacion -->
        Nombre:<br>
        <input value="<?php echo $txtNombre?>" type="text" name="txtNombre" id="">
        <br><br>

        <!-- Usando radio (seleccionar solo una opcion) esto se logra con el mismo name en todos, el value los diferencia-->
        ¿Te gusta?                   <!-- codigo para que una vez se envie, se quede el valor seleccionado -->
        <br> php: <input type="radio" <?php echo ($rdgLenguaje == "php") ? "checked":""?> name="lenguaje"  value = "php" id="">
        <br> html: <input type="radio" <?php echo ($rdgLenguaje == "html") ? "checked":""?> name="lenguaje" value = "html" id="">
        <br> css: <input type="radio" <?php echo ($rdgLenguaje == "css") ? "checked":""?> name="lenguaje" value = "css" id="">

        <!-- Usando checkboxes (seleccionar varias opciones) -->
        <br><br>
        Estas aprendiendo...         <!-- para que los valores se queden seleccionados al envio -->
        <br> php:<input type="checkbox" <?php echo $chkphp ?> name="chkphp" value="si" id="">
        <br> html:<input type="checkbox" <?php echo $chkhtml ?> name="chkhtml" value="si" id="">
        <br> css:<input type="checkbox"<?php echo $chkcss ?>  name="chkcss" value="si" id="">
        
        <!-- Usando opciones (solo se puede seleccionar una opcion) -->
        <br><br>
        ¿Que anime te gusta?... <br>
        <select name="lsAnime" id="">
            <option value="">[Ninguna Serie]</option> <!-- para que se mantenga la seleccion -->
            <option value="naruto" <?php echo ($lsAnime=="naruto")?"selected":""; ?> >Naruto</option>
            <option value="bleach" <?php echo ($lsAnime=="bleach")?"selected":""; ?> >Bleach</option>
            <option value="dragon" <?php echo ($lsAnime=="dragon")?"selected":""; ?> >Dragon Ball</option>
        </select>

        <!-- Usando textAreas -->
        <br><br>
        ¿Tienes alguna duda? <br> <!-- Para que no se borre el comentario -->    
        <textarea name="txtComentario" id="" cols="30" rows="10">
       
            <?php echo $txtComentario ?> 
        </textarea>

        <br><br>
        <input type="submit" value="Enviar informacion">

    </form>
    
</body>
</html>
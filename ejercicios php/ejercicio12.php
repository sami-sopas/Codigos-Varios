<?php

    if($_POST){
        $valorA = $_POST['valorA'];
        $valorB = $_POST['valorB'];

        if($valorA == $valorB)
        {
            echo "Valores iguales";
        }
        else
        {
            echo "Valores diferentes";
        }
    }


?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>if elses</title>
</head>
<body>
<form action="ejercicio11.php" method="post">
        
        Valor A:
        <input type="text" name="valorA" id="">
        <br>
        Valor B:
        <input type="text" name="valorB" id="">
        <br>

        <input type="submit" value="Calcular">

    </form>
</body>
</html>
<?php
    
    if($_POST)
    {
        $valorA = $_POST['valorA'];
        $valorB = $_POST['valorB'];
        
        if($valorA > $valorB)
        {
            echo "Valor A es mayor que Valor B";
        }
        else
        {
            echo "Valor B es mayor que valor A";
        }

    }
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Operadores relacionales</title>
</head>
<body>
    
    <form action="ejercicio9.php" method="post">
        
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
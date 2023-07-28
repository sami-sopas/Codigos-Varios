<?php
    
    if($_POST)
    {
        $valorA = $_POST['valorA'];
        $valorB = $_POST['valorB'];

        //Suma
        $suma = $valorA + $valorB;

        //Resta
        $resta =$valorA - $valorB;

        //Division
        $division = $valorA / $valorB;

        //Multiplicacion
        $multi = $valorA * $valorB;
        
        echo "<br>".$suma;
        echo "<br>".$resta;
        echo "<br>".$division;
        echo "<br>".$multi;
        
        if($valorA==$valorB)
        {
            echo "valor A es igual que valor B";

            if($valorA == 4)
            {
                echo "El valor de A es 4";
            }
        }
    }
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title> anidaciones</title>
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
<?php include("conexion.php") ?>

<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>PHP</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-KK94CHFLLe+nY2dmCWGMq91rCGa5gtU4mk92HdvYe+M/SXH301p5ILy+dN9+nJOZ" crossorigin="anonymous">

    <style>
      @font-face {
     font-family: fuenteCinna;
     src: url(Keepsmile.otf);
    }

    header{
        font-family: fuenteCinna;
        margin:0;
    }

    #links{
        text-decoration: none;
        color:rgb(45,42,38);
    }

    header{
        display: flex;
        height: 70px;
        justify-content: space-between;
        align-items: center;
        background-color: rgb(189,157,192);
        padding: 10px;
    }
    .logo{
        display: flex;
        align-items: center;
    }
    .logo img{
        height: 110px;
        margin-right: 10px;
    }

    nav a{
        padding-right: 25px;
    }

    nav a:hover{
        color:white;
    }

    .contenedor a{
        display: flex;
        align-items: center;
        color:pink;
        position: relative;
        left: 45px;
        top:60px;
        margin: 10px;
        font-size: 40px;

    }

    .imagen{
        display: flex;
        position: absolute;
        top:120px;
        right: 120px;
    }

    .imagen2{
        display: flex;
        position: absolute;
        top:85px;
        right:180px;
    }
    </style>
</head>
<body>

<header>
        <a href="index.html" class="logo" id="links">
            <img src="kuromi.png" alt="kuromi">
           <h2 class="nombre-pagina">Panaderia</h2>
        </a>
        <nav>
            <a href="" id="links">Hola</a>
            <a href="" id="links">Adios</a>
            <a href="" id="links">Si</a>
        </nav>
    </header>

<div class="container p-4">
  
    <div class="row">

        <div class="col-md-4">

            <?php if(isset($_SESSION['message'])) { ?>
                <div class="alert alert-<?=$_SESSION['message_type'];?> alert-dismissible fade show" role="alert">
                    <?= $_SESSION['message'] ?>
                    <button type="button" class="btn-close" data-bs-dismiss="alert" aria-label="Close"></button>
                    </div>
            <?php session_unset(); } ?>  

            <div style="margin-left: 17px" class="card card-body">
                <form action="insert.php" method="POST">
                    <div class="form-group">
                        <input type="text" name="id" class="form-control"
                        placeholder="ID" autofocus>
                    </div>
                    <br>
                    <div class="form-group">
                    <input type="text" name="nombre" class="form-control"
                        placeholder="Nombre"></textarea>
                    </div>
                    <br>
                    <div class="form-group">
                        <input type="text" name="cantidad" class="form-control"
                        placeholder="Cantidad">
                    </div>
                    <br>
                    <div class="d-grid gap-2">
                    <input type="submit" class="btn btn-success btn-block"
                    name="save_task" value="Guardar pan">
                    </div>
                </form>
            </div>

        </div>

        <div class="cold-md-8">
            <table style="margin: 20px;" class="table table-bordered">
                <thead>
                    <tr>
                        <th width="100px">ID</th>
                        <th width="150px">Nombre</th>
                        <th width="150px">Cantidad</th>
                    </tr>
                </thead>
                <tbody>
                    <?php
                    $query = "SELECT * FROM pan;";
                    $result_pan = mysqli_query($miConexion,$query);

                    while($row = mysqli_fetch_array($result_pan)) { ?>
                        <tr>
                            <td><?php echo $row['id'] ?></td>
                            <td><?php echo $row['nombre'] ?></td>
                            <td><?php echo $row['cantidad'] ?></td>
                        </tr>

                    <?php } ?> 
                </tbody>
            </table>

        </div>
    </div>
</div>

<div class="imagen2">
    <img height="250px" width="540px" src="cinna2.png" alt="cinnamorrol2">
</div>

<script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
<script src="https://cdn.jsdelivr.net/npm/bootstrap@4.3.1/dist/js/bootstrap.min.js" integrity="sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM" crossorigin="anonymous"></script>
<script src="https://cdn.jsdelivr.net/npm/popper.js@1.14.7/dist/umd/popper.min.js" integrity="sha384-UO2eT0CpHqdSJQ6hJty5KVphtPhzWj9WO1clHTMGa3JDZwrnQq4sF86dIHNDz0W1" crossorigin="anonymous"></script> 
    
</body>
</html>

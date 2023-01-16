<?php
try {
    //Informacion de la BD
    $cons_usuario = "Alonso";
    $cons_contra = ".TEKP!bida5NzPc";
    $cons_base_datos = "urbvan";
    $cons_equipo = "localhost";
    $conn = @mysqli_connect($cons_equipo, $cons_usuario, $cons_contra, $cons_base_datos);

    $error = mysqli_connect_error();
    if ($error) throw new Exception($error);
} catch (Exception $th) {
    // header('Location: 500.php');
    die('Error en la peticion' . $th);
}

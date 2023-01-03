<?php
try {
    //Informacion de la BD
    $cons_usuario = "root";
    $cons_contra = "";
    $cons_base_datos = "examen_bautista";
    $cons_equipo = "localhost";
    $conn = @mysqli_connect($cons_equipo, $cons_usuario, $cons_contra, $cons_base_datos);

    $error = mysqli_connect_error();
    if ($error) throw new Exception($error);
} catch (Exception $th) {
    echo 'Error al hacer la conexion';
}
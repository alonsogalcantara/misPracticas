<?php

require_once "conectiondb.php";

$nombre = $_REQUEST['firstName'];
$id_materia = $_REQUEST['materias'];

$sqlInsert = "INSERT INTO usuarios(nombre, Materia) values('$nombre', $id_materia)";

if ($conn->query($sqlInsert) === TRUE) {
    echo "Insertado correctamente: " . $sqlInsert;
    header("Location: index.php");
} else {
    echo "ERROR: Hush! Sorry $sqlInsert. "
        . mysqli_error($conn);
}

mysqli_close($conn);
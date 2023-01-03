<?php

require_once "conectiondb.php";

$peticion = "SELECT usr.Nombre AS 'Alumno', mtr.nombre_materia AS 'Materia', prf.nombre_profesor as 'Profesor' FROM usuarios usr left join materia mtr on(usr.Materia=mtr.id_material) left join profesores prf on(mtr.Profesor=prf.id_profesor)";
$result = mysqli_query($conn, $peticion);
mysqli_close($conn);

function cleanData(&$str)
{
    $str = preg_replace("/\t/", "\\t", $str);
    $str = preg_replace("/\r?\n/", "\\n", $str);
    if (strstr($str, '"')) $str = '"' . str_replace('"', '""', $str) . '"';
}

// file name for download
$filename = "usuarios.xls";

header("Content-Disposition: attachment; filename=\"$filename\"");
header("Content-Type: application/vnd.ms-excel");

$flag = false;
foreach ($result as $row) {
    if (!$flag) {
        // display field/column names as first row
        echo implode("\t", array_keys($row)) . "\n";
        $flag = true;
    }
    array_walk($row, __NAMESPACE__ . '\cleanData');
    echo implode("\t", array_values($row)) . "\n";
}

exit;
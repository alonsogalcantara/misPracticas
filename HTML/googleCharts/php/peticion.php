<?php

require_once "conectionUrbvan.php";

$peticion = "SELECT Alias, Apellidos, Nombre, Dirección, Población, Teléfono, Móvil, Email, Observaciones, Sexo, `Fecha Nacimiento`, `Estado Civil` FROM `contactos` limit 10000;";

$result = mysqli_query($conn, $peticion);
mysqli_close($conn);

if (!$result) {
    die(json_encode(array("message" => "Error en la peticion")));
}

while ($fila = $result->fetch_assoc()) {
    $ALIAS = ($fila['Alias']);
    $APELLIDO = ($fila['Apellidos']);
    $NOMBRE = ($fila['Nombre']);
    $DIRECCION = $fila['Dirección'];
    $POBLACION = ($fila['Población']);
    $TELEFONO = ($fila['Teléfono']);
    $MOVIL = ($fila['Móvil']);
    $EMAIL = ($fila['Email']);
    $OBSERVACIONES = $fila['Observaciones'];
    $SEXO = ($fila['Sexo']);
    $FECHA_NACIMIENTO = ($fila['Fecha Nacimiento']);
    $ESTADO_CIVIL = ($fila['Estado Civil']);

    $resultados[]  = array(
        "alias" => $ALIAS,
        "apellidop" => $APELLIDO,
        "nombre" => $NOMBRE,
        "direccion" => $DIRECCION,
        "poblacion" => $POBLACION,
        "telefono" => $TELEFONO,
        "movil" => $MOVIL,
        "email"=>$EMAIL,
        "observaciones" => $OBSERVACIONES,
        "sexo" => $SEXO,
        "fecha_nacimiento"=>$FECHA_NACIMIENTO,
        "estado_civil"=>$ESTADO_CIVIL
    );
}

echo json_encode($resultados);

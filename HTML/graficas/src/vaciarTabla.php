<?php
require_once "./src/conectiondb.php";

$peticion = "truncate usuarios;";

$result = mysqli_query($conn, $peticion);
mysqli_close($conn);

header("Location: index.php");
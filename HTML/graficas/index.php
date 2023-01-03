<!DOCTYPE html>
<html lang="es">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">

    <title>Pruebas Dashboard</title>

    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet"
        integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous">

    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.6.1/jquery.js"></script>
    <script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>

    <script type="module" src="js/getAlumnos.js"></script>
    <script src="js/dashboard.js"></script>
    </script>
    <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
</head>

<body>
    <div class="container-md">
        <div class="row">
            <div class="col-4">
                <h1>Insertar usuarios</h1>
                <form action="insert.php">
                    <input class="form-control" type="text" name="firstName" placeholder="Nombre" id="firstName"
                        disabled>
                    <div class="input-group mt-3">
                        <label class="input-group-text" for="materias">Materias</label>
                        <select name="materias" id="materias" class="form-select form-select-sm"
                            aria-label=".form-select-sm example" disabled>
                            <option value="1" selected>Matematicas 1</option>
                            <option value="2">Español 1</option>
                            <option value="3">Ciencias Sociales</option>
                            <option value="4">Matematicas 2</option>
                            <option value="4">Historia de la Filosofia</option>
                            <option value="4">Etica y Filosofia</option>
                            <option value="4">Economia</option>
                            <option value="4">Fisica</option>
                            <option value="4">Programacion</option>
                        </select>
                    </div>

                    <br>
                    <input class="btn btn-primary mb-3" type="submit" value="Insertar" disabled>
                </form>
                <a href="./prueba_data.php">El otro</a>
                <div class="row justify-content-start">
                    <div class="col-3">
                        <form action="vaciarTabla.php">
                            <input class="btn btn-primary mb-3" type="submit" value="Vaciar Tabla" disabled>
                        </form>
                    </div>
                    <div class="col">
                        <form action="exportar.php">
                            <input class="btn btn-primary mb-3" type="submit" value="Exportar tabla" disabled>
                        </form>
                    </div>
                </div>
            </div>

            <!-- ++++++++++++++++++++++++++++++++++++++++++++++++++++++++ -->
            <!-- ++++++++++++++++++++ T A B L A +++++++++++++++++++++++++ -->
            <!-- ++++++++++++++++++++++++++++++++++++++++++++++++++++++++ -->
            <div class="col-8">
                <div id="table_div"></div>
            </div>
        </div>

        <div id='buttons' class='btn'><button type="button" class="btn btn-primary" onclick="releaseFilter();">Clear
                filter:
                names</button> </div>
        <div id="standalone_table_div" class='dashboard_div'></div>

        <div class="dashboard my-4" id="dashboard">
            <div id="programmatic_dashboard_div">
                <div id="programmatic_control_div" style="padding-left: 2em; min-width: 250px"></div>
                <div id="programmatic_chart_div"></div>
                <div id="standalone_table_div"></div>
                <div class="my-5" id="chart_div"></div>
            </div>
        </div>
    </div>

    <!-- <canvas id="myChart"></canvas> -->
</body>

</html>
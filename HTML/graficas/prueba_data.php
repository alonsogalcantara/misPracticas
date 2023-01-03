<?php
require_once './php/conection.php';
$sql = "SELECT YEAR(`dt`) 'Anio', AVG(AverageTemperature) 'avg' FROM `temperatura` GROUP BY `Anio`";
$pais_avg = "SELECT `Country` 'pais', AVG(AverageTemperature) 'avg' FROM `temperatura` GROUP BY `Country` ORDER BY AVG(AverageTemperature) DESC limit 10;
";

$r_query = mysqli_query($con, $sql);
$r_query_pais = mysqli_query($con, $pais_avg);

while ($row = mysqli_fetch_array($r_query)) {
    $global[] = array($row['Anio'], $row['avg']);
}

while ($row_pais = mysqli_fetch_array($r_query_pais)) {
    $global_pais[] = array($row_pais['pais'], $row_pais['avg']);
}

// echo var_dump(json_encode($array_anio));
?>
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Prueba </title>
</head>

<body>
    <div>
        <canvas id="line_chart"></canvas>
    </div>

    <div>
        <canvas id="bar_chart"></canvas>
    </div>
    <div>
        <canvas id="pie_chart"></canvas>
    </div>

    <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>

    <script>
        const ctx = document.getElementById('line_chart');
        const ctxBar = document.getElementById('bar_chart');
        const ctxPie = document.getElementById('pie_chart');

        const data = <?= json_encode($global); ?>;
        const data_pais = <?= json_encode($global_pais); ?>;

        new Chart(ctx, {
            type: 'line',
            data: {
                datasets: [{
                    label: 'Avg temperature',
                    data: data,
                    borderWidth: 1,
                    'fill': false,
                }]
            },
            options: {
                scales: {
                    y: {
                        beginAtZero: true
                    },
                    myScale: {
                        type: 'logarithmic',
                        position: 'right', // `axis` is determined by the position as `'y'`
                    }
                }
            }
        });

        new Chart(ctxBar, {
            type: 'bar',
            data: {
                'labels': data_pais.map(paises => paises[0]),
                datasets: [{
                    data: data_pais.map(avgs => avgs[1])
                }]
            }
        });

        new Chart(ctxPie, {
            type: 'pie',
            data: {
                'labels': data_pais.map(paises => paises[0]),
                datasets: [{
                    data: data_pais.map(avgs => avgs[1])
                }]
            }
        });
    </script>

</body>

</html>
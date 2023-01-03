google.charts.load('current', {
    'packages': 'corechart'
});


google.charts.setOnLoadCallback(drawChart)

function drawChart() {
    $.ajax({
        url: 'http://www.apis.com/bautista/analisis.php',
        dataType: 'json',
        success: function (materias) {
            const listMap = materias.map(materias => [materias.Materia, materias.Cantidad]);
            var data = google.visualization.arrayToDataTable([['Materia', 'Cantidad']].concat(listMap));

            var options = {
                title: 'Materias',
                width: '100%',
                height: 720
            };

            var chart = new google.visualization.PieChart(document.getElementById('piechart'));

            chart.draw(data, options);
        }
    });
}


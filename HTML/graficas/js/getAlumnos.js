google.charts.load('current', {
    'packages': 'table'
});


google.charts.setOnLoadCallback(drawTable);

console.log('Estamos en la funcion')
// Ya es el google chart
function drawTable() {
    $.ajax({
        url: 'http://www.apis.com/bautista/verAlumnos.php',
        dataType: 'json',
        success: function (students) {
            const data = new google.visualization.DataTable();
            data.addColumn('string', 'Alumno');
            data.addColumn('string', 'Materia');
            data.addColumn('string', 'Profesor');

            data.addRows(students.map(students => [students.Estudiante, students.Materia, students.Profesor]));

            var table = new google.visualization.Table(document.getElementById('table_div'));

            table.draw(data, {
                title: 'Tabla de alumnos',
                showRowNumber: true,
                width: '100%',
                height: '100%',
                page: true,
                pageSize: 20
            });
        }
    });
}
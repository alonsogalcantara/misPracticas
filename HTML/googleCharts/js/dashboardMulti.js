var requestOptions = {
    method: 'GET',
    redirect: 'follow'
};

async function drawTable() {
    const res = await fetch("http://www.apis.com/bautista/gender.php", requestOptions).catch(error => console.log('error', error));
    const jsonObject = await res.json()

    const personas = await Promise.all(
        jsonObject.map(async (res) => {
            return await res
        })
    )
    
    const listMap = personas.map(personas => [personas.nombre, personas.app, personas.sexo, personas.edad, personas.correo, personas.telefono, personas.educacion, personas.trabajo, personas.experiencia, personas.salario, personas.estado_civil, personas.hijos]);
    const data = [['Nombre', 'Appellido', 'Genero', 'Edad', 'Correo', 'Telefono', 'Educacion', 'Trabajo', 'Experiencia', 'Salario', 'Estado Civil', 'Hijos']].concat(listMap)
    
    let dataGoogle = google.visualization.arrayToDataTable(data);

    var dashboard = new google.visualization.Dashboard(document.querySelector('#dashboard-multy'));

    var stringFilter = new google.visualization.ControlWrapper({
        controlType: 'StringFilter',
        containerId: 'string_filter_div',
        options: {
            filterColumnIndex: 0
        }
    });

    var table = new google.visualization.ChartWrapper({
        chartType: 'Table',
        containerId: 'table_div_multy',
        options: {
            showRowNumber: false,
            page: true,
            pageSize: 20,
            allowHtml: true
        }
    });

    var formatter = new google.visualization.NumberFormat(
        { prefix: '$', negativeColor: 'red', negativeParens: true, 'groupingSymbol': ',' });
    formatter.format(dataGoogle, 9);

    var formatter = new google.visualization.NumberFormat(
        { suffix: ' Años', negativeColor: 'red', negativeParens: true, 'fractionDigits': 0 });
    formatter.format(dataGoogle, 3);
    formatter.format(dataGoogle, 8);

    var formatter = new google.visualization.BarFormat({ width: 120 });
    formatter.format(dataGoogle, 8)

    var formatter = new google.visualization.PatternFormat(
        '<a href="mailto:{1}">{0} {2}</a>');
    // Apply formatter and set the formatted value of the first column.
    formatter.format(dataGoogle, [0, 4, 1]);

    var view = new google.visualization.DataView(dataGoogle);
    view.setColumns([0, 2, 3, 5, 6, 7, 8, 9, 10, 11]); // Create a view with the first column only.

    dashboard.bind([stringFilter], [table]);
    dashboard.draw(dataGoogle);
}

google.load('visualization', '1', { packages: ['controls'], callback: drawTable });
function getYear(dt) {
    var result = google.visualization.data.group(
        dt,
        [9],
        [{ 'column': 9, 'aggregation': google.visualization.data.count, 'type': 'number' }]
    );

    return result
}

function drawTable() {
    $.ajax({
        async: true,
        url: '../php/peticion.php',
        type: 'html',
        dataType: 'json',
        success: function (contactos) {

            columnas = [['Alias', 'Apellidos', 'Nombre', 'Dirección', 'Población', 'Teléfono', 'Móvil', 'Email', 'Observaciones', 'Sexo', 'Fecha Nacimiento', 'Estado Civil']]
            listContacts = columnas.concat(contactos.map(contacto => [contacto.alias,
            contacto.apellidop,
            contacto.nombre,
            contacto.direccion,
            contacto.poblacion,
            contacto.telefono,
            contacto.movil,
            contacto.email,
            contacto.observaciones,
            contacto.sexo,
            new Date(contacto.fecha_nacimiento),
            contacto.estado_civil
            ]))

            let dataGoogle = google.visualization.arrayToDataTable(listContacts);

            var dashboard = new google.visualization.Dashboard(document.querySelector('dashboard-multy'));

            var stringFilter = new google.visualization.ControlWrapper({
                controlType: 'StringFilter',
                containerId: 'string_filter_div',
                options: {
                    filterColumnIndex: 0
                }
            });

            var categoryFilterPoblacion = new google.visualization.ControlWrapper({
                controlType: 'CategoryFilter',
                containerId: 'cathegoric_filter_poblacion_div',
                options: {
                    filterColumnIndex: 4,
                    ui: {
                        caption: 'Elige la Poblacion',
                        allowTyping: false
                    }
                }
            });

            var categoryFilterGenero = new google.visualization.ControlWrapper({
                controlType: 'CategoryFilter',
                containerId: 'cathegoric_filter_genero_div',
                options: {
                    filterColumnIndex: 9,
                    ui: {
                        caption: 'Elige un Genero',
                        allowTyping: false
                    }
                }
            });

            var categoryFilterEstadoCivil = new google.visualization.ControlWrapper({
                controlType: 'CategoryFilter',
                containerId: 'cathegoric_filter_estado_civil_div',
                options: {
                    filterColumnIndex: 11,
                    ui: {
                        caption: 'Elige un Estado Civil',
                        allowTyping: false
                    }
                }
            });

            var dataRangeFilterNacimiento = new google.visualization.ControlWrapper({
                controlType: 'DateRangeFilter',
                containerId: 'date_range_filter_nacimiento_div',
                options: {
                    filterColumnIndex: 10,
                    ui: {
                        formatType: 'short',
                        step: 'day',
                        showRangeValues: true,
                        orientation: 'horizontal',
                        label: 'Año'
                    }
                }
            });

            var table = new google.visualization.ChartWrapper({
                chartType: 'Table',
                containerId: 'table_div',
                options: {
                    showRowNumber: true,
                    page: true,
                    pageSize: 20,
                    allowHtml: true
                }
            })

            // Create a pie chart, passing some options
            var barChart = new google.visualization.ChartWrapper({
                chartType: 'BarChart',
                containerId: 'calendar_basic',
                view: { 'columns': [9, 10] }
            });

            var formatter_short = new google.visualization.DateFormat({ formatType: 'short', pattern: "d/MM/YYYY" });
            formatter_short.format(dataGoogle, 10);

            dashboard.bind([stringFilter,
                categoryFilterPoblacion,
                categoryFilterGenero,
                categoryFilterEstadoCivil,
                dataRangeFilterNacimiento], [table, barChart]);

            dashboard.draw(dataGoogle);
        }
    });
}

google.load('visualization', '51', { packages: ['controls'], callback: drawTable });
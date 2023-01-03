google.charts.load('current', {
    'packages': ['corechart', 'controls', 'table']
});

google.charts.setOnLoadCallback(drawDashboard);

// grouped data for some visual elements
function getGroupedData(data) {
    var dt_grouped = google.visualization.data.group(
        data,
        [2],
        [
            {
                column: 9,
                aggregation: google.visualization.data.avg,
                type: 'number',
            },
        ]);
    return dt_grouped;
}

// update all dependent charts with grouped data
function updateView_(event) {
    var data = tableWrapper.getDataTable();
    barChart.setDataTable(getGroupedData(data));
    // redraw the pie chart to reflect changes
    barChart.draw();
}

function selectHandler() {
    var selection = table.getSelection();
    var values = [];
    for (var i = 0; i < selection.length; i++) {
        var item = selection[i];
        if (item.row != null && item.column != null) {
            var str = data.getFormattedValue(item.row, item.column);
        } else if (item.row != null) {
            var str = data.getFormattedValue(item.row, 0);
        } else if (item.column != null) {
            var str = data.getFormattedValue(0, item.column);
        }
        values.push(str);
    }
    if (values.length > 0) {
        changeFilter(values);
    }
    else {
        // select all values
        releaseFilter();
    }
    return 0;
}

// changes the filter, used outside the function
releaseFilter = function () {
    filterName.setState(state);
    filterName.draw();
    table.setSelection();
};
a=1
function drawDashboard() {
    $.ajax({
        url: 'http://www.apis.com/bautista/gender.php',
        dataType: 'json',
        success: function (personas) {
            const listMap = personas.map(personas => [personas.nombre, personas.app, personas.sexo, personas.edad, personas.correo, personas.telefono, personas.educacion, personas.trabajo, personas.experiencia, personas.salario, personas.estado_civil, personas.hijos]);
            var data = google.visualization.arrayToDataTable([['Nombre', 'Appellido', 'Genero', 'Edad', 'Correo', 'Telefono', 'Educacion', 'Trabajo', 'Experiencia', 'Salario', 'Estado Civil', 'Hijos']].concat(listMap));

            // name filter
            var filterName = new google.visualization.ControlWrapper({
                'controlType': 'CategoryFilter',
                'containerId': 'name_filter_div',
                'options': {
                    'filterColumnLabel': 'Nombre'
                }
            });

            var rangeAgeSlider = new google.visualization.ControlWrapper({
                'controlType': 'NumberRangeFilter',
                'containerId': 'programmatic_control_div',
                'options': {
                    'filterColumnLabel': 'Edad'
                }
            });

            var rangeSalarySlider = new google.visualization.ControlWrapper({
                'controlType': 'NumberRangeFilter',
                'containerId': 'programmatic_control_div',
                'options': {
                    'filterColumnLabel': 'Salario'
                }
            });

            var genderFilter = new google.visualization.ControlWrapper({
                'controlType': 'CategoryFilter',
                'containerId': 'programmatic_control_div',
                'options': {
                    'filterColumnLabel': 'Genero',
                    'ui': {
                        'allowTyping': false,
                        'allowMultiple': false,
                        'orientation': 'horizontal',
                        'showRangeValues': false,
                        'label': ''
                    }
                }
            });

            // Create a pie chart, passing some options
            var tableChart = new google.visualization.ChartWrapper({
                'chartType': 'Table',
                'containerId': 'programmatic_chart_div',
                'options': {
                    'width': '100%',
                    'height': '100%',
                    'title': 'Tabla de Test',
                    'ShowRowNumber': 'True',
                    'page': 'True',
                    'pageSize': '20',
                    'allowHtml': 'true'
                }
            });

            var barChart = new google.visualization.ChartWrapper({
                'chartType': 'Bar',
                'containerId': 'chart_div',
                'options': {
                    'width': '100%',
                    'height': '100%',
                    bars: 'vertical',
                    hAxis: {
                        title: 'Promedio salario por genero',
                        minValue: 0
                    },
                    vAxis: {
                        title: 'Genero'
                    }
                },
                dataTable: getGroupedData(data)
            });

            // Standalone table. Serves as a filter, changes values in the
            // real filter control by the listener
            var table = new google.visualization.Table(document.getElementById('standalone_table_div'));

            var state = filterName.getState();
            // console.log(state)
            // add handler to the table
            // Add our selection handler.
            google.visualization.events.addListener(table, 'select', selectHandler);

            var tableWrapper = new google.visualization.ChartWrapper({
                chartType: 'Table',
                containerId: 'hidden_table_div',
            });

            google.visualization.events.addListener(
                tableWrapper,
                'ready',
                updateView_);

            barChart.draw();
            // table.draw(data, tableProperties);
            // dashboard.draw(data);

            var formatter = new google.visualization.NumberFormat(
                { prefix: '$', negativeColor: 'red', negativeParens: true, 'groupingSymbol': ',' });
            formatter.format(data, 9);

            var formatter = new google.visualization.NumberFormat(
                { suffix: ' Años', negativeColor: 'red', negativeParens: true, 'fractionDigits': 0 });
            formatter.format(data, 3);
            formatter.format(data, 8);

            var formatter = new google.visualization.BarFormat({ width: 120 });
            formatter.format(data, 8)

            var formatter = new google.visualization.PatternFormat(
                '<a href="mailto:{1}">{0} {2}</a>');
            // Apply formatter and set the formatted value of the first column.
            formatter.format(data, [0, 4, 1]);

            var view = new google.visualization.DataView(data);
            view.setColumns([0, 2, 3, 5, 6, 7, 8, 9, 10, 11]); // Create a view with the first column only.

            var dashboard = new google.visualization.Dashboard(document.getElementById('programmatic_dashboard_div'));

            dashboard.bind([rangeSalarySlider, genderFilter], [tableChart]);
            dashboard.bind(genderFilter, rangeSalarySlider);
            dashboard.draw(view);
        }
    });
}
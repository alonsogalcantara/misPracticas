import folium
import branca
import webbrowser

#Creamos el mapa de nuevo para partir de 0
mi_mapa = folium.Map(location=(17.666667, -100), zoom_start = 9,min_zoom = 5, max_zoom = 11, control_scale = True, no_touch = True, tiles = "OpenStreetMap")

longUsr1 = 17.666667

#Lo que va adentro del marcador
html = "<p>Latitud: 17.666667</p><p>Longitud: -100</p><p>Usr 1</p>"
iframe1 = branca.element.IFrame(html=html, width=250, height=250)

html = "<p>Latitud: 17.67</p><p>Longitud: -99</p><p>Usr 2</p>"
iframe2 = branca.element.IFrame(html=html, width=250, height=250)

html = "<p>Latitud: 17.89</p><p>Longitud: -100</p><p>Usr 3</p>"
iframe3 = branca.element.IFrame(html=html, width=250, height=250)

html = "<p>Latitud: 17.80</p><p>Longitud: -100.2</p><p>Usr 4</p>"
iframe4 = branca.element.IFrame(html=html, width=250, height=250)

html = "<p>Latitud: 17.40</p><p>Longitud: -99.95</p><p>Usr 5</p>"
iframe5 = branca.element.IFrame(html=html, width=250, height=250)

marcador1 = folium.Marker(
    location = (longUsr1, -100),
    popup = folium.Popup(iframe1, max_width=500),
    icon = folium.Icon(color="black")
)

marcador2 = folium.Marker(
    location = (17.67, -99),
    popup = folium.Popup(iframe2, max_width=500),
    icon = folium.Icon(color="black")
)

marcador3 = folium.Marker(
    location = (17.89, -100),
    popup = folium.Popup(iframe3, max_width=500),
    icon = folium.Icon(color="black")
)

marcador4 = folium.Marker(
    location = (17.80, -100.2),
    popup = folium.Popup(iframe4, max_width=500),
    icon = folium.Icon(color="black")
)

marcador5 = folium.Marker(
    location = (17.40, -99.95),
    popup = folium.Popup(iframe5, max_width=500),
    icon = folium.Icon(color="black")
)

# Añadimos los marcadores al mapa
marcador1.add_to(mi_mapa)
marcador2.add_to(mi_mapa)
marcador3.add_to(mi_mapa)
marcador4.add_to(mi_mapa)
marcador5.add_to(mi_mapa)

# Y guardamos el mapa
mi_mapa.save("mapa.html")
print("Hecho!")
webbrowser.open_new_tab('mapa.html')

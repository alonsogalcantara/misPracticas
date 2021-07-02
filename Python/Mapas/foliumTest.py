import folium
import branca
import webbrowser
from geopy.geocoders import Nominatim

def getMyLocation():
    import geocoder #Importamos libreria

    #Inicializamos el objeto Nominatim
    Nomi_locator = Nominatim(user_agent="My App")

    my_location= geocoder.ipinfo('me')

    #Mi longitud y latitud
    return my_location.geojson["features"][0]["properties"]["lat"], my_location.geojson["features"][0]["properties"]["lng"]

def createMap():
    #Asociamos variables segun la longitud y la latitud del usuario
    longUsr1, latiUsr1 = getMyLocation()

    #Creamos el mapa de nuevo para partir de 0
    mi_mapa = folium.Map(location=(longUsr1, latiUsr1), zoom_start = 9,min_zoom = 5, control_scale = True, no_touch = True, tiles = "OpenStreetMap")

    #Lo que va adentro del marcador
    html = f"<p>Latitud: {longUsr1}</p><p>Longitud: {latiUsr1}</p><p>Usr 1</p>"

    #Se agrega el frame
    #Y se asocia lo que va a ir dentro del marcador
    iframe1 = branca.element.IFrame(html=html, width=250, height=250)

    #Se agrega el marcador
    marcador1 = folium.Marker(
        location = (longUsr1, latiUsr1),
        popup = folium.Popup(iframe1, max_width=500),
        icon = folium.Icon(color="black")
    )

    #Añadimos los marcadores al mapa
    marcador1.add_to(mi_mapa)

    # Y guardamos el mapa
    mi_mapa.save("mapa.html")
    print("¡Hecho!")
    webbrowser.open_new_tab('mapa.html')

createMap()
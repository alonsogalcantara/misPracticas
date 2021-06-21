import folium
import branca
import webbrowser
from geopy.geocoders import Nominatim

#initialize the Nominatim object
Nomi_locator = Nominatim(user_agent="My App")

address= "Mexico City"

#get the location detail 
Mylocation = Nomi_locator.geocode(address)

print("Tu ubicacion es:", Mylocation)
print(f"Latitud {Mylocation} es: {Mylocation.latitude}")
print(f"Longitud {Mylocation} es: {Mylocation.longitude}")

latiUsr1 = Mylocation.longitude
longUsr1 = Mylocation.latitude



#Creamos el mapa de nuevo para partir de 0
mi_mapa = folium.Map(location=(longUsr1, latiUsr1), zoom_start = 9,min_zoom = 5, max_zoom = 11, control_scale = True, no_touch = True, tiles = "OpenStreetMap")

#Lo que va adentro del marcador
html = f"<p>Latitud: {longUsr1}</p><p>Longitud: {latiUsr1}</p><p>Usr 1</p>"
iframe1 = branca.element.IFrame(html=html, width=250, height=250)

marcador1 = folium.Marker(
    location = (longUsr1, latiUsr1),
    popup = folium.Popup(iframe1, max_width=500),
    icon = folium.Icon(color="black")
)

# Añadimos los marcadores al mapa
marcador1.add_to(mi_mapa)

# Y guardamos el mapa
mi_mapa.save("mapa.html")
print("Hecho!")
webbrowser.open_new_tab('mapa.html')

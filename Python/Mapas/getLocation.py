from geopy.geocoders import Nominatim

#initialize the Nominatim object
Nomi_locator = Nominatim(user_agent="My App")

address= "Mexico City"

#get the location detail 
location = Nomi_locator.geocode(address)

print("Tu ubicacion es:", location)
print(f"Latitud {location} es: {location.latitude}")
print(f"Longitud {location} es: {location.longitude}")
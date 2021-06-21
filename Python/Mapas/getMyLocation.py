from typing import Type
from geopy.geocoders import Nominatim
import geocoder

def getMyLocation():

    #initialize the Nominatim object
    Nomi_locator = Nominatim(user_agent="My App")

    my_location= geocoder.ipinfo('me')

    #my latitude and longitude coordinates
    lat, lng = my_location.geojson["features"][0]["properties"]["lat"], my_location.geojson["features"][0]["properties"]["lng"]
    
    return lat, lng
    
print(getMyLocation())
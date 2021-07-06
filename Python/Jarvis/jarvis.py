#Importamos la libreria
import pyttsx3
import datetime

#Inicializamos pyttsx3
engine = pyttsx3.init()

#Declaramos
voice = engine.getProperty("voices")
engine.setProperty("voices", voice[0].id)

def speak(audio = str()):
    """Esta funcion hace que el asistente hable lo que se le pase por la variable de audio
    Audio: String"""
    engine.say(audio)
    engine.runAndWait()

def time() -> str():
    """Esta funcion dice la hora actual"""
    return f"La hora es {datetime.datetime.now().strftime('%I:%M:%S')}"

def date() -> str():
    """Esta funcion regresa la fecha actual"""
    return f"Hoy es {int(datetime.datetime.now().year)} del mes {int(datetime.datetime.now().month)} del día {int(datetime.datetime.now().day)}"

def sayGood():
    hour = datetime.datetime.now().hour
    if hour >=6 and hour < 12:
        speak("Buenos días")
    elif hour >= 12 and hour < 18:
        speak("Buenas tardes")
    else:
        speak("Buenas noches")
    

def wishme():
    """Esta fucion da la bienvenida"""
    speak("¡Bienvenido de vuelta!")
    speak(time())
    sayGood()
    speak(date())
    speak("¿En que puedo ayudarte?")

wishme()

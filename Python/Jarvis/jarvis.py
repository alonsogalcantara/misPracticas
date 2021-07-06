#Importamos la libreria
import pyttsx3
import datetime
import speech_recognition as sr

#Inicializamos pyttsx3
engine = pyttsx3.init()

#Declaramos
voice = engine.getProperty("voices")
engine.setProperty("voices", voice[0].id)

def speak(audio = str()):
    """Hace que el asistente hable lo que se le pase por la variable de audio
    Audio: String"""
    engine.say(audio)
    engine.runAndWait()

def time() -> str():
    """Dice la hora actual"""
    return f"La hora es {datetime.datetime.now().strftime('%I:%M:%S')}"

def date() -> str():
    """Regresa la fecha actual"""
    return f"Hoy es {int(datetime.datetime.now().year)} del mes {int(datetime.datetime.now().month)} del día {int(datetime.datetime.now().day)}"

def sayGood():
    """Nos dice los buenos días/tardes/noces"""
    hour = datetime.datetime.now().hour
    if hour >=6 and hour < 12:
        speak("Buenos días")
    elif hour >= 12 and hour < 18:
        speak("Buenas tardes")
    else:
        speak("Buenas noches")
    
def wishme():
    """Da la bienvenida"""
    sayGood()
    speak("¡Bienvenido de vuelta!")
    speak(time())
    speak(date())
    speak("¿En que puedo ayudarte?")

def takeCommand():
    """Reconoce la voz"""
    r = sr.Recognizer()
    with sr.Microphone() as source:
        print("Escuchando...")
        r.pause_threshold = 1
        audio = r.listen(source)

    try:
        print("Reconociendo")
        query = r.recognize_google(audio, "es=MX")
        print(query)
    except Exception as e:
        print(e)
        speak("Repíte lo que dijiste, porfavor")
        return "None"
    return query

if __name__ == "__main__":
    wishme()

    while True:
        query = takeCommand().lower()
        print(query)

        if "time" in query:
            time()
        elif "date" in query:
            date()
        elif "offline" in query:
            quit()
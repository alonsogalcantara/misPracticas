#Importamos la libreria
import pyttsx3

#Inicializamos pyttsx3
engine = pyttsx3.init()

#Declaramos
voice = engine.getProperty("voices")
engine.setProperty("voices", voice[0].id)


def speak(audio = str()):
    engine.say(audio)
    engine.runAndWait()

speak("Hello there")
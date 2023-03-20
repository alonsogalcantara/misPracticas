from PIL import Image

# Lista de caracteres ASCII
ASCII_CHARS = ["@", "#", "S", "%", "?", "*", "+", ";", ":", ",", "."]

# Función para convertir la imagen a escala de grises
def to_greyscale(image):
  return image.convert("L")

# Función para convertir el valor del píxel a un carácter ASCII
def pixel_to_ascii(image):
  pixels = image.getdata()
  ascii_str = ""
  for pixel in pixels:
    ascii_str += ASCII_CHARS[pixel//25]
  return ascii_str

# Función para convertir la imagen a ascii art
def image_to_ascii(image):
  # Redimensionar la imagen según el ancho deseado
  width = int(input("Ingrese el ancho del ascii art: "))
  height = int(width * image.height / image.width)
  image = image.resize((width, height))

  # Convertir la imagen a escala de grises y obtener el valor de cada píxel
  greyscale_image = to_greyscale(image)
  ascii_str = pixel_to_ascii(greyscale_image)

  # Dividir la cadena en líneas según el ancho de la imagen
  ascii_lines = []
  for i in range(0, len(ascii_str), width):
    ascii_lines.append(ascii_str[i:i+width])
  
  # Unir las líneas con saltos de línea y devolver el resultado
  return "\n".join(ascii_lines)

# Leer la imagen desde un archivo
# image_path = input("Ingrese la ruta de la imagen: ")
# image_path = "./Moon.jpg"
image_path = "./Sun.jpg"
image = Image.open(image_path)

# Convertir la imagen a ascii art y mostrarla en pantalla
ascii_art = image_to_ascii(image)
print(ascii_art)
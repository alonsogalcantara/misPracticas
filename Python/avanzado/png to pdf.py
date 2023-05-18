from importlib.resources import path
import os

path = './'
os.chdir(path)

# Obtiene los documentos de la carpeta
file_list = os.listdir(path)

# Filtro que solo sean imagenes
file_list_images = filter(lambda x: ".jpg" in x or ".png" in x, file_list)

for x in file_list_images:
    if "t." in x or "T." in x:
        os.remove(f"{x}")

file_list_images = filter(lambda x: ".jpg" in x or ".png" in x or 't.' in x, file_list)

# Asignacion de llave a cada fichero
aux_list = []
for file in file_list_images:
    aux_list.append(int(file.split(".")[0]))

# Conversion a dicccionario
imgs_dict = dict(zip(aux_list, file_list))

# input(imgs_dict)

# Ordenamiento
aux_imgs_dict = dict(sorted(imgs_dict.items()))

list_named = " ".join(aux_imgs_dict.values())

os.system(f"py -m img2pdf {list_named} -o out.pdf")

input("Presione enter para terminar...")
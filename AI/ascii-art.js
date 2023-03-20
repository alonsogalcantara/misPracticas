// Función para convertir la imagen a ascii art
function imageToAscii(image) {
  // Crear un elemento canvas y obtener su contexto
  var canvas = document.createElement("canvas");
  var context = canvas.getContext("2d");

  // Redimensionar el canvas según el ancho deseado
  var width = parseInt(prompt("Ingrese el ancho del ascii art: "));
  var height = Math.floor(width * image.height / image.width);
  canvas.width = width;
  canvas.height = height;

  // Dibujar la imagen en el canvas
  context.drawImage(image, 0, 0, width, height);

  // Obtener los datos de los píxeles del canvas
  var imageData = context.getImageData(0, 0, width, height);
  var pixels = imageData.data;

  // Cadena de caracteres ASCII
  var asciiChars = "@#S%?*+;:,. ";

  // Convertir el valor de cada píxel a un carácter ASCII
  var asciiStr = "";
  
   for (var i = 0; i < pixels.length; i +=4) {
    // Obtener el promedio de los canales rojo, verde y azul (escala de grises)
    var grayscale = (pixels[i] + pixels[i+1] + pixels[i+2]) /3;
    
    // Asignar un carácter ASCII según el valor del píxel
    var index = Math.floor(grayscale /25);
    asciiStr += asciiChars[index];
    
    // Añadir un salto de línea al final de cada fila
    if ((i/4 +1) % width ==0) {
      asciiStr += "\n";
    }
   }

   // Devolver el resultado
   return asciiStr;
}

// Leer la imagen desde una URL
var imageUrl = prompt("Ingrese la URL de la imagen: ");
var image = new Image();
image.crossOrigin = 'anonymous';
image.src = imageUrl;

// Otra parte del codigo
// Crear un elemento <img>
// var img = document.createElement("img");
// // Asignar el atributo src con la URL de la imagen
// img.src = imageUrl;
// // console.log(image.src);
// var div = document.getElementById("img-container");
// div.appendChild(img);

// Esperar a que la imagen se cargue y convertirla a ascii art
image.onload = function() {
    var para = document.createElement("p");
    para.innerText = imageToAscii(image);

    var div_text = document.getElementById("text-container");
    div_text.appendChild(para);
//    console.log(asciiArt);
}
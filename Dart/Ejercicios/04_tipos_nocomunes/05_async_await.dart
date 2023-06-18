
import 'dart:io';

void main(List<String> args) async {
  
  String path = Directory.current.path + '\\assets\\personas.txt';

  //leerArchivo(path).then( print ); async
  String texto = await leerArchivo(path); //Le indicamos a que espere a que el FUTURE se resuelva
  print(texto);

  print('Fin del main');
  
}

//si le agregamos la palabra async a la funcion SIEMPRE DEBERA RETORNAR UN FUTURE

Future<String> leerArchivo(String path) async
{
  //Vamos hacer la referencia al archivo de texto en Window
  File file = new File(path);

  return file.readAsString();
}
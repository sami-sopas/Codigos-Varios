
import 'dart:io';

void main(List<String> args) {
  
  //Vamos a leer un archivo en windows
  File file = new File(Directory.current.path + '\\assets\\personas.txt');

  //                 Este metodo resolveria la promesa
  Future<String> f = file.readAsString();

  // Este no serviria para promesas
  //String f = file.readAsStringSync();

  //print(f);
  
  //Despues de cumplir la promesa, se ejecutaria esta linea
  f.then((texto) => print(texto));


  print('Fin del main');

}
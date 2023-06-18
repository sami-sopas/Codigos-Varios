import 'dart:io';
main()
{
  //Imprimir en terminal
  stdout.writeln("Escriba su nombre");

  //Leer teclado, si regresa nulo, regresaremos no hay valor
  String nombre = stdin.readLineSync() ?? '\n';

  stdout.writeln('Tu nombre es: $nombre');

  
}
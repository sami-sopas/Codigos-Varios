
import 'dart:io';

main()
{
  stdout.writeln("Escribe tu edad");

  //la convertimos a int el string que se lee y validamos en caso de que sea nulo regresar un 0
  int edad = int.parse(stdin.readLineSync() ?? '0');

  if(edad > 18)
  {
    stdout.writeln("Es mayor");
  }
  else
  {
    stdout.writeln("Eres menor");
    
  }
}
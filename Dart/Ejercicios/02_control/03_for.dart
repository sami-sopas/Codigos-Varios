
import 'dart:io';

main()
{
  for(int i = 0; i < 5; i++)
  {
    print('Index I: ${2+2}'); 
  }

  //tablas de multriplicar

  stdout.writeln("Escribe un numero para la tabla");
  int numero = int.parse(stdin.readLineSync() ?? '0');

  for(int i = 1; i < 11; i++)
  {
    print('$numero * $i = ${numero*i}');
  }
}
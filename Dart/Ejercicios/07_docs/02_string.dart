
main()
{
  String nombre = 'Fer';
  String apellido = 'Herrera';

  String nombreCompleto = '$nombre' ' ' 'Herrera';

  print('String: $nombreCompleto');

  print('Length: ${nombreCompleto.length}'); //Imprime longitud de string

  print('Containts F: ${ nombreCompleto.contains('F')}'); //Imprime True si encuentra una F

  print('EndsWith a: ${ nombreCompleto.endsWith('a')}'); //Si termina con a

  print('Padleft: ${ nombreCompleto.padLeft(20,'...')}'); //Agregar el patron(...) por cada espacio para llegar a la longitud de 20 en el String
  print('Padleft: ${ nombreCompleto.padRight(20,'...')}'); //Agregar el patron(...) por cada espacio para llegar a la longitud de 20 en el String

  print('Operador []: ${ nombreCompleto[0] }'); //Imprime la F solo 
  print('Operador *: ${ nombreCompleto * 2}'); //Duplica el valor del string

  print('ReplaceAll: ${ nombreCompleto.replaceAll('e','a')}'); //Reemplazar todas las a por e

  print('SubString: ${ nombreCompleto.substring(0,5)}...'); //Limita el string de 
  print('indexOf: ${ nombreCompleto.indexOf(' ')}'); //Regresa la posicion de X caracter en un string

  print('Split: ${ nombreCompleto.split(' ')}'); //Regresa una lista de strings [Fer, Herrera]
}
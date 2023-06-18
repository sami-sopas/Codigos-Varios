main()
{
  // Operadores de asignacion
  int a = 10;
  int b = 1;

  //b ??= 20; //Asignar el valor unicamente si la variable es null

  //print(b);


  // Operadores condicionales
  int c = 23;
  String resp = c > 26 ? 'C es mayor que 25' : 'C es menor que 25'; //Operador ternario

  //print(resp); C es mayoe que 25

  //Aqui decimos que si b es nulo, que agarre el valor de a
  int d = b ?? a;

  //print(d); Imprime 1 


  // Operadores relacionales
  // Todos retornar un valor booleano
  /*
    > Mayor que
    < Menor que
    >= Mayor o igual que
    <= Menor o igual que

    == Revisa si dos objetos son iguales
    != Revosa si dos objetos son diferentes
  */

  String persona1 = 'Fer';
  String persona2 = 'Beto';

  //print(persona1==persona2); false

  int x = 20;
  int y = 30;

  //print(x < y); true

  // Operador de tipo
  int i = 10;
  String j = '10';

  print( i is int ); 



}
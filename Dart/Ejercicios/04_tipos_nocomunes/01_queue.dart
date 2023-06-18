import 'dart:collection';

main()
{
  Queue<int> cola = new Queue();

   //Encolamos los siguientes numeros
  cola.addAll([10,20,30,40,50]);

  //Asignamos a i el indice de la cola
  Iterator i = cola.iterator;

  //Realizamos un barrido de los elementos
  while(i.moveNext())
  {
    print(i.current);
  }

  ///Los imprime de la siguiente manera
  /// 10
  /// 20
  /// 30
  /// 40
  /// 50
}
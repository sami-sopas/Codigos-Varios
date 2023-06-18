
void main(List<String> args) {
  
  List<int> lista = [1,2,3,4,5];
  List<int> lista2; //null
  List<int> lista3 = [3,1,2,15,-10];
  List<String> nombres = ['Tony','Peter'];

  print('Length: ${ lista.length}'); //Cuenta los elementos de una lista
  print('First: ${ lista[0]}'); //Primer elemento de la lista
  print('First: ${ lista.first}'); //Otro metodo para el primer elemento de la lista
  print('Last: ${ lista.last}'); //Ultimo elemento de la lista

  print('isEmpty: ${ lista.isEmpty}'); //Booleano para saber si la lista esta vacia
  //print('isEmpty?: ${ lista2?.isEmpty}'); Por null safety, no deja verificar si es vacio

  print('asMap: ${ lista.asMap()}'); //Convierte la lista a mapa con su key y valor

  Map listaMapa = lista.asMap();
  print('ListaMapa: ${ listaMapa[4]}');//Retorna el 5 usando la llave 4

  Map nombreMapa = nombres.asMap();
  print('nombreMapa: ${ nombreMapa}');
  print('nombreMapa: ${ nombreMapa[1]}'); //Retorna peter

  print('indexOf: ${ nombres.indexOf('Peter')}'); //Muestra la posicion donde esta peter

  //Realiza un barrido hasta que cumpla la condicion que le pasemos
  int mayor3 = lista.indexWhere( (numero) {

    //if( numero > 3) {
    //  return true;
    //}
    //else{
    //  return false;
    //}
    return numero > 3; //mas resumido
  });

  print('indexWhere mayor a 3: $mayor3');//Retorna la posicion donde hay un valor mayor a 3

  print('Remove: ${ nombres.remove('Tony') }'); //Regresa un bool si hace la eliminacion
  print('Remove: ${ nombres }'); //Vemos que se elimino Tony

  lista.shuffle(); //Pone los elementos en aleatorio
  print('Shuffle: $lista');

  lista3.sort(); //Ordena la lista de menor a mayor
  print('Sort: ${ lista3 }');
  print('Sort: ${ lista3.reversed.toList() }'); //La ordena de mayor a menor, pero regresa un iterable

  nombres.forEach( (nombre) { 
    nombre = nombre.toUpperCase();
    print(nombre);
  });

  print('Listado: $nombres');

  //El map es como un foreach que modifica la lista, no la original y regresa un iterable
  final newList = nombres.map((nombre) => nombre.toUpperCase());
  print('newList: ${newList.toList()}'); //Lo regresamos a lista




}
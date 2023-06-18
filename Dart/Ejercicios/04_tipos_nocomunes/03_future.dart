//Los futures son como las promesas de Javascript

//Un future es una tarea asincrona que se va a realizar en un futuro
void main(List<String> args) {
  
//                                                            | funcion anonima
  Future<String> timeout = Future.delayed(Duration(seconds: 3),() {
      print('3 segundos despues'); //Se ejecuta en otro hilo
      return 'Retorno del future';
  });

  //Esta linea se ejecuta hasta que termine el proces del Future
  timeout.then( (texto) => print(texto));
  //Metodo mas corto: timeout.then( print );

  print('Fin del main');
}
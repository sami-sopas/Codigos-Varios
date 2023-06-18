// Un stream es un flujo de informacion como un rio

import 'dart:async';

main()
{
  //                                        Lo transformamos para que lea mas de 1 stream
  final StreamController streamController = new StreamController.broadcast();

  //Los stream controllers son asincronos
  streamController.stream.listen( //Definicion del listen
    (data)  => print('Despegando: $data'), //Lo que hara cuando llege informacion
    onError: (err) => print('Error! $err'),
    onDone: () => print('Mision completa'), //Se ejecuta cuando se completa el sync.close()
    cancelOnError: false //Para que no se siga ejecutando el programa despues de un error
   );

    streamController.stream.listen( //Definicion del listen
    (data)  => print('Despegando: $data'), //Lo que hara cuando llege informacion
    onError: (err) => print('Error! $err'),
    onDone: () => print('Mision completa'), //Se ejecuta cuando se completa el sync.close()
    cancelOnError: false //Para que no se siga ejecutando el programa despues de un error
    );

   //Colocando informacion al stream
   streamController.sink.add('Apollo 11');
   streamController.sink.add('Apollo 12');
   streamController.sink.add('Apollo 13');
   streamController.sink.addError('Tenemos un pedo');
   streamController.sink.add('Apollo 14');
   streamController.sink.add('Apollo 15');

   streamController.sink.close(); //Para cerrar el stream

   print('Fin del main');
}
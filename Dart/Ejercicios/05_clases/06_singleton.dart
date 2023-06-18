/// La idea de un patron singleton es que
/// en memoria solo exista una instancia de mi servicio
/// sin importar cuantas referencias haga de eso


import 'clases/mi_servicio.dart';

void main(List<String> args) {
  

 // 2 instancias en memoria diferentes
  final spotifyService = new MiServicio();
  spotifyService.url = 'https://api.spotify.com';

  final spotifyService2 = new MiServicio();
  spotifyService2.url = 'https://api.spotify.com/v2';

  print( spotifyService == spotifyService2);  // True

  print( spotifyService.url );
  print( spotifyService2.url ); //Estas dos lineas imprimirian lo mismo

}
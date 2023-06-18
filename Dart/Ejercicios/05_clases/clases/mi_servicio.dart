
class MiServicio {

  //Propiedad estatica privada que mantiene la instancia en memoria
  static final MiServicio _singleton = new MiServicio._internal(); 

  // Constructor factory para revisar si existe una instancia
  factory MiServicio(){
    return _singleton;
  }

  // Constructor privado que genera una instancia
  MiServicio._internal(); 



  String url = 'https://abc';
  String key = 'ABC123';
}
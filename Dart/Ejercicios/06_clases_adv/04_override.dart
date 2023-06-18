
class Persona {

  String? nombre;
  int? edad;

  //Argumentos obligatorios posicionales
  Persona(this.nombre,this.edad);

  void imprimirNombre() => print('Nombre: $nombre, Edad: $edad');
}

class Cliente extends Persona {

  String? direccion;
  List ordenes = [];

  //Al momento de crear el Cliente, Se crea tambien
  //una instancia de la Persona
  Cliente(int edadActual, String nombreActual):
  super(nombreActual,edadActual);

  //Sobreescribimos el metodo con Override
  @override
  void imprimirNombre() {
    super.imprimirNombre(); //Para imprimir pero usando el metodo de Persona
    print('Cliente: $nombre ($edad)');
  }
}

void main(List<String> args) {

  final pedro = new Cliente(33,'Pedro');

  pedro.imprimirNombre();
  
}
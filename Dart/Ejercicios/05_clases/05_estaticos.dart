/// El STATIC sirve para acceder a alguna propiedad
/// sin tener que realizar una instancia de una clase


class Herramientas {

  // Con el const evitamos que se pueda modificar la lista
  static const List<String> listado = ['martillo','llave','Desarmados'];

  static void imprimirListado() => listado.forEach(print);
}


void main(List<String> args) {

  //final herr = new Herramientas();

  //Herramientas.listado.add('Tenazas');

  //Herramientas.listado.forEach(print);
  Herramientas.imprimirListado();
  
}
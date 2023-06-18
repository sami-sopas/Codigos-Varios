/// Los Mixins sirven para darle propiedades y metodos
/// a otras clases, parecido a los Extended
/// 
/// Diferencias:
/// Los Mixins no pueden ser instanciados, como una clase abstracta
/// Los Mixins no usan constructores

// class
mixin Logger {
  
  void imprimir( String texto) {
    final hoy = DateTime.now();
    print('$hoy :::: $texto');
  }

}

mixin Logger2 {
  
  void imprimir2( String texto) {
    final hoy = DateTime.now();
    print('$hoy :::: $texto');
  }

}

//Para heredar del Mixin, se usa la palabra with, para agregar mas se usa ,
abstract class Astro with Logger,Logger2 {

  String? nombre;

  Astro() {
    imprimir('-- init del Astro --');
  }

  void existo() {
    imprimir('-- Soy un ser celestial y existo --');
  }

}

//Aqui heredamos de una clase y de mixins
class Asteroide extends Astro with Logger,Logger2{

  //String nombre;

  Asteroide(nombre) {
    this.nombre = nombre;
    imprimir('Soy $nombre');
    imprimir2('Soy $nombre');
  }
}

void main(List<String> args) {

  final ceres = new Asteroide('Ceres');
  
}
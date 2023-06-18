
class Rectangulo {

  int? base;
  int? altura;
  int? area;
  String? tipo; // cuadrado: base = altura, rectangulo: base != altura

  // El factory debe regresar una instancia nueva o previamente creada,
  // puede ser utilizado para algun calculo
  factory Rectangulo(int base,int altura) {
    
    if(base == altura)
    {
      return Rectangulo.cuadrado( base );
    }
    else
    {
      return Rectangulo.rectangulo(base,altura);
    }
  }

  Rectangulo.cuadrado(int base) {
    this.base = base;
    this.altura = base;
    this.area = base * base;
    this.tipo = 'Cuadrado';
  }

    Rectangulo.rectangulo(int base, int altura) {
    this.base = base;
    this.altura = base;
    this.area = base * altura;
    this.tipo = 'Rectangulo';
  }

  @override
  String toString() {
    //Hacemos un mapa y despues lo pasamos a string
    return {'base':base,'altura':altura,'area':area,'tipo':tipo}.toString();
  }
}

void main(List<String> args) {

  final figura = new Rectangulo(10,20);

  print(figura);
  
}
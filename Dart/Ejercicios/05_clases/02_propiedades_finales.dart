
class Cuadrado{

  //public:
  final int lado;
  final int area;

  //Error
  //Cuadrado(int lado, int area)
  //{
  //  this.lado = lado;
  //  this.area = area;
  //}

  //Calculamos el area apartir del lado
  Cuadrado( int lado ):
    this.lado = lado,
    this.area = lado * lado;
}

void main(List<String> args) {

  final cuadrado = new Cuadrado(10);

  // Error: cuadrado.lado = 20;

  print(cuadrado.area);
  


}
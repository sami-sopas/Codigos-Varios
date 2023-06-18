
/// Las clases abstractas son para evitar crear instancias
/// de estas, y que solo funcionen como un "cascaron"

abstract class Vehiculo {

  bool encendido = false;

  void encender() {
    encendido = true;
    print('Vehiculo encendido');
  }

    void apagar() {
    encendido = false;
    print('Vehiculo apagado');
  }


  //Podemos definir metodos para que las otras clases
  //que hereden, las desarrollan
  bool revisarMotor();
}

//Esta clase hereda los metodos y propiedades de Vehiculo
class Carro extends Vehiculo{

  int kilometraje = 0;

  //Aqui es donde sobreescribimos un metodo del padre
  @override
  bool revisarMotor()
  {
    print('Motor OK');
    return true;
  }

}

main()
{
  final ford = new Carro();
  //final ford = new Vehiculo();

  ford.encender();
  ford.apagar();

  ford.revisarMotor();
}
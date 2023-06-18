
class Vehiculo {

  bool encendido = false;

  void encender() {
    encendido = true;
    print('Vehiculo encendido');
  }

    void apagar() {
    encendido = false;
    print('Vehiculo apagado');
  }
}

//Esta clase hereda los metodos y propiedades de Vehiculo
class Carro extends Vehiculo{

  int kilometraje = 0;

}

main()
{
  final ford = new Carro();

  ford.encender();
}
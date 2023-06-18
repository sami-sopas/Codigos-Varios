class Persona{

  // Atributos--------------------
  String? nombre;
  int? edad;
  String _bio = 'Hola, soy una propiedad privada'; //El _ indica que sera un atributo privado

  // Getters y Setters-------------

  // Getter publico
  String get bio {
    return _bio.toUpperCase();
  }
  //String get bio => _bio.toUpperCase();


  // Setter publico
  void set bio(String texto){
    _bio = texto;
  } 
  //set bio ( String texto ) => _bio = texto;


  // Constructores-----------------

  
 // Persona(String nombre, int edad) {
  //  //print('Constructor');
  //  this.nombre = nombre;
  //  this.edad = edad;
  //}

  //otra sintaxis...
  Persona(
    this.nombre, //Argumento posicional obligatorio
    { this.edad = 0} //Argumento opcional y con un valor por defecto
    );

    //Sobrecarga de operador con constructur con nombre
    Persona.persona30( this.nombre ){
      this.edad = 30;
    }

    Persona.persona40(String nombre)
    {
      this.edad = 30;
      this.nombre = nombre;
    }
  

  // Metodos-----------------------
  @override
  String toString() => 'Nombre: $nombre, Edad: $edad, Bio: $_bio';
  
  
}
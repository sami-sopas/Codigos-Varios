import 'clases/persona.dart';

void main(List<String> args) {
  

final persona = new Persona('Fer',edad: 33);
final persona30 = new Persona.persona30('Marie');
final persona40 = new Persona.persona40('Bien');

//persona.nombre = 'Fer';
//persona.edad = 33;
//persona.bio = 'Nacio por ahi';

//Otra manera de asignarle datos a los atributos
//persona..nombre = 'Fer'
//       ..edad = 33;
//       ..bio = 'Nacio por ahi'; // privado

persona.bio = 'Cambie el valor'; //Usando un setter

print(persona40); //Usando un getter



}

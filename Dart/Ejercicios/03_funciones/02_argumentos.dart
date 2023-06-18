
//Para que el argumento sea solo null o string, usamos el ?
//Si queremos que un argumento sea OPCIONAL, lo encerramos entre corchetes
                       
//            null o string                 opcional
void saludar(String? mensaje, [String nombre = '<inserte nombre>'] )
{
  print('Saludar 1: $mensaje $nombre');
}

//Argumentos a las funciones POR NOMBRE, se usan LLAVES
void saludar2(
  String? mensaje, //obligatorio tambien pero es (argumento por posicion)
  {required String nombre, //Hacemos que este parametro sea obligatorio (argumento por nombre)
  int edad = 10
  })
{
  print('Saludar 2: $mensaje $nombre $edad');

}



main()
{
  saludar('Hola','Fergi');
  saludar2('Saludos',edad: 20, nombre: 'tony' );
}


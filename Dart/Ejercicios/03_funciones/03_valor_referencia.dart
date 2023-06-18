String capitalizar(String texto)
{
  texto = texto.toUpperCase();
  return texto;
}

// Los objetos de manera predeterminada se enviar por REFERENCIA
Map<String,String> capitalizarMapa(Map<String,String> mapa)
{
  // Romper el referencia
  mapa = {...mapa}; //Se esparce el mapa para crear una copia de el

                              // el ? sirve para prevenir nulos
  mapa['nombre'] = mapa['nombre']?.toUpperCase() ?? 'No hay nombre';

  return mapa;
}

main()
{
  String nombre = 'fer';
  String nombre2 = capitalizar(nombre);

  print(nombre);
  print(nombre2);
 
  
  Map<String,String> persona ={
    'nombre':'Tony Stark'
  };

    Map<String,String> persona2 = capitalizarMapa(persona);

    print(persona);
    print(persona2);
}
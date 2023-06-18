
main()
{

  final persona = {
    'nombre'  : 'Fernando',
    'apellido': 'Herrera',
    'edad'    : 33
  };

  final direccion = {
    'ciudad': 'Otawa',
    'pais'  : 'Canada'
  };

  print('Persona: $persona');
  print('Length: ${ persona.length}'); //Imprime el numero de pares de valores en el mapa
  print('keys: ${ persona.keys}'); //Imprime las llaves del mapa (regresa un iterable)
  print('values: ${ persona.values }'); //Imprime los valores del mapa (iterable tambien)

  persona.addAll(direccion); //Los pares de valores de direccion ahora seran parte de persona
  print('AddAll: $persona');

  persona.remove('pais'); //Eliminar el par pais
  print('remove: $persona');

  //Eliminar dada una condicion (retorna un bool)
  //persona.removeWhere( (key,value) {
  //  if(key != 'nombre') {
  //    return true;
  //  }else {
  //    return false;
  //  }
  //});  

  // Metodo mas corto para eliminar dada una condicion
  // persona.removeWhere((key, value) => key == 'nombre' ? false : true);

  print('RemoveWhere: $persona');

  //Este metodo no regresa nada
  persona.forEach( (key,value) {
    print('key: $key  value: $value');
  });

  //Este metodo retorna un nuevo mapa con el mismo par de valores y con las modificaciones hechas
  final nuevoMapa = persona.map((key, value) {
    return MapEntry(key, value.toString().toUpperCase());
  });

  print('Persona map: $nuevoMapa');
}
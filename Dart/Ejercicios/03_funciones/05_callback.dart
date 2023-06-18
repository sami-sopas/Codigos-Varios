/// Un callback es una funcion que se llama
/// dentro de otra funcion
main()
{
  //Cuando se haga lo de la funcion, despues de imprimira a la persona
  obtenerUsuario('100',(Map persona ) {
    print(persona);
  });

}

void obtenerUsuario(String id, Function callback)
{
  Map usuario = {
    'id' : id,
    'nombre' : 'Carlos'
  };

  //Aqui ya tenemos al usuario cargado

  callback(usuario); //Ahora llamamos a la funcion callback, salta hasta el print(persona)


}
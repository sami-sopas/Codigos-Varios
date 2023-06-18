
main()
{
  int a = 10, b = 20;
  int resultado = sumarFlecha(10, 20);

  List<int> listado = [1,2,3,4,5,6,6,7,8,9,10,10,1];

  //Esta funcion filtra los numeros mayores a 4, FUNCION NORMAL
  //var nuevoListado = listado.where( (numero) {
  //  return numero > 4;
  //}) ;

    //Esta funcion filtra los numeros mayores a 4, FUNCION FLECHA
    var nuevoListado = listado.where((n) => n > 4); //Regresa un objeto de tipo ITERABLE 
 
    //Lo convertimos a SET para quitar elementos repetidos y lo regresamos a una lista
    print(nuevoListado.toSet().toList()); 

}

//Funcion normal
int sumar(int x,int y)
{
  return x + y;
}

// Funcion flecha
// Se recomienda usar cuando se tiene una sola instruccion y debe retornarla
int sumarFlecha(int x,int y) => x + y;
main()
{
  //Final y const sirve para variables que no cambiaran de valor
  int a = 10;
  final double b = 10;
  const double c = 10;

  late final double x; //Sirve para indicar que una variable la inicializaremos mas tarde
  x = 10.25;

  print(x);

  final List<String> personasFinal = ['Juan','Pedro','Fernando']; //Lista que puede modificar sus valores
  const List<String> personasConst = ['Juan','Pedro','Fernando']; //Lista que no va ser modificada jamas

  personasFinal.add('Maria');
  personasConst.add('Maria');

  print(personasConst);
}
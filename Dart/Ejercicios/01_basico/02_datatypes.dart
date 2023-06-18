main()
{
  // --- Numbers

  int a = 10;
  double b = 5.5;

  int? c = null; //Indicamos que c puede ser nulo

  int _a = 30;
  double $b = 40;

  double resultado = _a + $b;

  print(resultado);

  // --- Strings

  String nombre = 'Tony';
  String? nombre2 = "Tony";
  String nombre3= "0'Connor";
  String apellido = "Stark";

  String nombreCompleto = "$nombre2 $apellido"; //Interpolacion de strings

  String multilinea = '''
  Hola mundo
  ¿Como estas?
  $nombre2
  O'Connor
  ''';

  print(nombreCompleto);

  // --- Booleans

  bool isActive = true;;
  bool isNotActive = !isActive;

  print(isNotActive);

  // --- Lists (permite elementos duplicados)

  List<String> letras = ['a','b','c'];

  letras[0] = 'f';

  letras.add('g'); //Agrega al final de la lista
  letras.add('g');
  letras.add('g');

  print(letras); //[f, b, c, g, g, g]

  // --- Sets (no permite elementos duplicados)

  Set<String> letras2 = {'a','b','c'};

  letras2.add('f');
  
  print(letras2); //{a, b, c, f}

  // --- Maps (diccionarios)
  //Se componen de una llave y un valor

  Map<String,dynamic> ironman = {
//   llave       valor
    'nombre': 'Tony Stark', 
    'poder': 'inteligencia',
    'nivel': 9000,
  };

  print(ironman['nombre']); //Tony Starl

  Map<String,dynamic> capitan = new Map();

  capitan.addAll({
    'nombre': 'Steve',
    'poder':'La queso',
    'nivel': 5000,
  });

  print(capitan);





  


}
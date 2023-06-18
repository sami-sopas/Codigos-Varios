import 'dart:math';

main()
{
  int random = Random().nextInt(7);

  switch(random) // 0 1 2 3 4 5 6
  {
    case 0:
      print('Lunes');
    break;

    case 1:
      print('Martes');
    break;

    case 2:
      print('Miercoles');
    break;

    case 3:
      print('Jueves');
    break;

    case 4:
      print('Viernes');
    break;
    
    case 5:
      print('Sabado');
    break;

    case 6:
      print('Domingo');
    break;
    
    default:
    print('No es un dia de la semana');
  }
}
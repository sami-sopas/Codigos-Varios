/**
 * Un operador es un simbolo que
 * le indica al compilador que
 * debe realizar una tarea matematica,
 * relacional o logica y debe producir
 * un resultado
 */
main()
{
  int a = 10 + 5; //  +   15
  a = 20 - 10;    //  -   10
  a = 10 * 2;     //  *   20

  double b = 10 / 2;  //        /    5
  b = 10.0 % 3;       //        %    1 Sobrante de la division
  b = -b;             //        -expr Cambiar el valor de la expresion
 
  int c = 10 ~/ 3;    //       ~/    Division comun y corriente

  int d = 1;
  d++;                //       ++    Incrementa el valor en 1 
  d--;                //       --    Decrementa el valor en 1

  d +=2;             //       +=     Incrementa el valor en 2 
  d -=2;             //       -=     Decrementa el valor en 2

  

  print(a); 


}
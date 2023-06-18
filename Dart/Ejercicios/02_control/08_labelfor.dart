main()
{
  outerLoop: //Etiqueta del ciclo
  for(int i = 0; i < 5; i++)
  {
    print('Valor de i: $i');

    innerLoop:
    for(int j = 0; j < 5; j++)
    {
      print('Valor de j: $j');

      if(j==2)
      {
        break outerLoop; //Indicamos que romperemos desde el primer ciclo mediante su tag
      }
    

    }
  }
}
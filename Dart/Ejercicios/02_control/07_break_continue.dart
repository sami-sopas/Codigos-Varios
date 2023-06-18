
main()
{
  for(int i = 0; i < 10; i++)
  {
    if(i == 5)
    {
      continue; //El 5 no se imprimiria
    }
    print(i);

    if(i == 2)
    {
      break;
    }
  }
}
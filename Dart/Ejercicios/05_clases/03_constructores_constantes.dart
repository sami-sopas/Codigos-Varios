
class Location {

  final double lat;
  final double lng;

  const Location(this.lat,this.lng);


}

void main(List<String> args) {

  final sanFrancisco1 = new Location(10.20,35.300);
  final sanFrancisco2 = new Location(10.20,35.301);
  final sanFrancisco3 = new Location(10.20,35.301);

  // print(sanFrancisco1 == sanFrancisco2); //False
  // print(sanFrancisco2 == sanFrancisco3); //False
  
  const sanFrancisco4 = const Location(10.20,35.300);
  const sanFrancisco5 = const Location(10.20,35.301);
  const sanFrancisco6 = const Location(10.20,35.301);

  const berlin = const Location(10.20,35.301);

  print(sanFrancisco4 == sanFrancisco5); //False
  print(sanFrancisco5 == sanFrancisco6); //True
  print(berlin == sanFrancisco6); //True

  //Se crean en el mismo espacio de memoria
}
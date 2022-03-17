void main(List<String> arguments) {
  //#1 - Growable
  var numList = [1,2,3];
  print(numList); 
  numList.add(12);
  print(numList); 
 
  //#2 - Fixed Length
  var numListSec = List<int>.filled(1, 0, growable: true);
  numListSec[0] = 1;
  print(numListSec);
}

void main(List<String> arguments) {
  var i = 1;
  while (i <= 10) {
    if (i % 5 == 0) {
      print("The first multiple of 5 between 1 and 10 is : ${i}");
      break;
      //exit the loop if the first multiple is found
    }
    i++;
  }
}

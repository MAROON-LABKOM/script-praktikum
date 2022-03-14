void main(List<String> arguments) {
  var num = 5;
  var factorial = 1;

  do {
    factorial = factorial * num;
    num--;
  } while (num >= 1);
  print("The factorial is ${factorial}");
}

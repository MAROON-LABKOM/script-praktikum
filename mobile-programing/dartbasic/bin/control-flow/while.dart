void main(List<String> arguments) {
  var num = 5;
  var factorial = 1;

 while (num >= 1) {
    factorial = factorial * num;
    num--;
  } 
  
  print("The factorial is ${factorial}");
}

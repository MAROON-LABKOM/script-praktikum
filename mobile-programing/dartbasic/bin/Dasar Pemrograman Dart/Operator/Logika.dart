void main(List<String> arguments) {
  var conFirst = true;
  var conSecond = false;
  bool isTrue;
 
  isTrue = conFirst && conSecond;
  print(isTrue);
 
  isTrue = conFirst || conSecond;
  print(isTrue);
 
  isTrue = !conSecond;
  print(isTrue);
}

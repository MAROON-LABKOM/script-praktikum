class Human { 
  String firstName = "";
  String lastName = "";
  int age = 0;

  Human(String firstName, String lastName, int age){
    this.firstName = firstName;
    this.lastName = lastName;
    this.age = age;
  }
  
  void printHuman() {
    print(firstName);
    print(lastName);
    print(age);
  }
}

class AboutHuman extends Human {
  AboutHuman(String firstName, String lastName, int age) : super(firstName, lastName, age);
  String msg = "Kamu seorang Android Developer";

  @override
  void printHuman() {
    super.printHuman();
    print(msg);
  }
}

void main(List<String> arguments) {
  Human person = Human("Dimas", "Purnomo", 22);
  person.printHuman();

  AboutHuman about = AboutHuman("Dimas", "Purnomo", 25);
  about.printHuman();
}
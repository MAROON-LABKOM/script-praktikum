void main(List<String> arguments) {
  //#1 - Map Literal
  var mapLiteral = {'username':'dimas211','password':'065118211@123'}; 
   mapLiteral['npm'] = '065118211'; 
   print(mapLiteral); 
   //#2 - Map Constructor
   var mapConstructor = new Map(); 
   mapConstructor['Usrname'] = 'admin'; 
   mapConstructor['Password'] = 'admin@123'; 
   print(mapConstructor); 
}

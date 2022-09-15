import 'dart:io';

double calc(double a, double b, String operation) {
  double result = 0;
  switch (operation) {
    case "+":
      result = a + b;
      break;
    case "-":
      result = a - b;
      break;
    case "*":
      result = a * b;
      break;
    case "/":
      result = a / b;
      break;
    case "%":
      result = a % b;
      break;
  }
  return result;
}

String? promptEquation() {
  print("Enter a 2 number operation: ");
  String? equation = stdin.readLineSync();
  return equation;
}

void main(List<String> args) {
  String? equation = promptEquation();
  final eq = equation?.split(" ");
  double r = calc(double.parse(eq![0]), double.parse(eq[2]), eq[1]);
  print("$equation = $r");
}

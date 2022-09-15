import 'dart:io';

double promptAnswer(String questionText) {
  print(questionText);
  double a = double.parse(stdin.readLineSync()!);
  return a;
}

class MathQuestion {
  String? question;
  double? answer;

  MathQuestion(String aQuestion, double aAnswer) {
    this.question = aQuestion;
    this.answer = aAnswer;
  }
}

void main(List<String> args) {
  List<MathQuestion> questions = [
    MathQuestion("3 + 5", 8.0),
    MathQuestion("10 - 7", 3.0),
    MathQuestion("100 * 9", 900.0)
  ];

  int score = 0;

  for (MathQuestion q in questions) {
    double userAnswer = promptAnswer(q.question!);
    userAnswer == q.answer ? score++ : score;
  }

  print("You got ${score}/${questions.length}");
}

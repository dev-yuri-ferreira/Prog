import 'dart:math';

import 'package:flutter/material.dart';

void main() {
  runApp(
      MaterialApp(title: "Contador de pessoas", home: Home())); //Material App
}

class Home extends StatefulWidget {
  @override
  HomeState createState() => HomeState();
}

class HomeState extends State<Home> {
  @override
  int _pessoa = 0;
  String _mensagem = "Pode entrar!";
  void _changePeople(int delta) {
    setState(() {
      _pessoa = int_changeWithinRange(_pessoa, delta);
      _mensagem = _validatePeople(_pessoa);
    });
  }

  int_changeWithinRange(int p, int modifier) {
    return (p + modifier <= 20) ? max(p + modifier, 0) : 20;
  }

  String _validatePeople(int nPessoas) {
    return nPessoas < 20 ? "Pode entrar!" : "Lotado, não pode entrar.";
  }

  Widget build(BuildContext context) {
    return Stack(
      children: <Widget>[
        Image.asset(
          "Imagens/restaurante.jpeg",
          fit: BoxFit.cover,
          height: 1000.0,
        ),
        Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            Text(
              "Pessoas: $_pessoa",
              style: TextStyle(
                  color: Colors.white,
                  fontWeight: FontWeight.bold,
                  backgroundColor: Color.fromARGB(100, 0, 0, 0)),
            ), //text
            Row(
              mainAxisAlignment: MainAxisAlignment.center,
              children: <Widget>[
                Padding(
                  padding: const EdgeInsets.all(10.0),
                  child: ButtonTheme(
                    height: 30.0,
                    highlightColor: Colors.indigo,
                    child: ElevatedButton(
                      onPressed: () {
                        _changePeople(1);
                      },
                      child: Text(
                        "+1",
                        style: TextStyle(color: Colors.white, fontSize: 25.0),
                      ),
                    ),
                  ),
                ),
                Padding(
                  padding: const EdgeInsets.all(10.0),
                  child: ButtonTheme(
                    height: 30.0,
                    highlightColor: Colors.indigo,
                    child: ElevatedButton(
                      onPressed: () {
                        _changePeople(-1);
                      },
                      child: Text(
                        "-1",
                        style: TextStyle(color: Colors.white, fontSize: 25.0),
                      ),
                    ),
                  ),
                ),
              ],
            ),
            Text(
              _mensagem,
              style: const TextStyle(
                  color: Colors.white,
                  fontStyle: FontStyle.italic,
                  fontSize: 30,
                  backgroundColor: Color.fromARGB(100, 0, 0, 0)),
            ) //text
          ], //widget
        ) //Column
      ],
    );
  }
}

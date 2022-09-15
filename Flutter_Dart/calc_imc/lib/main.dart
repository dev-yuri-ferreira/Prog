import 'package:flutter/material.dart';

void main() {
  runApp(MaterialApp(
    title: "Calculadora IMC",
    theme: ThemeData(primarySwatch: Colors.deepPurple),
    home: Home(),
  ));
}

class Home extends StatefulWidget {
  @override
  _HomeState createState() => _HomeState();
}

class _HomeState extends State<Home> {
  TextEditingController pesoController = TextEditingController();
  TextEditingController alturaController = TextEditingController();
  GlobalKey<FormState> _formKey = GlobalKey<FormState>();
  String _textInfo = "";
  void _resetCampos() {
    _formKey.currentState!.reset();
    pesoController.clear();
    alturaController.clear();
    setState(() {
      _textInfo = "";
    });
  }

  String _imcString(double imc, int precision) {
    String imcResult = "(${imc.toStringAsPrecision(4)})";
    String textResult = "";
    if (imc < 18.6)
      textResult = "Abaixo do peso ";
    else if (imc >= 18.6 && imc < 24.9)
      textResult = "Peso ideal ";
    else if (imc >= 24.9 && imc < 29.9)
      textResult = "Levemente acima do peso ";
    else if (imc >= 29.9 && imc < 34.9)
      textResult = "Obesidade Grau I ";
    else if (imc >= 34.9 && imc < 39.9)
      textResult = "Obesidade Grau II ";
    else if (imc >= 40) textResult = "Obesidade Grau III ";
    String fullResult = textResult + imcResult;
    return fullResult;
  }

  void _calcular() {
    setState(() {
      double peso = double.parse(pesoController.text);
      double altura = double.parse(alturaController.text) / 100;
      double imc = peso / (altura * altura);
      _textInfo = _imcString(imc, 4);
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
        appBar: AppBar(
          title: Text("Calculadora de IMC"),
          centerTitle: true,
          actions: <Widget>[
            IconButton(
              icon: Icon(Icons.refresh),
              onPressed: _resetCampos,
            )
          ],
        ),
        body: SingleChildScrollView(
          padding: EdgeInsets.fromLTRB(10.0, 0.0, 10.0, 0.0),
          child: Form(
            key: _formKey,
            child: Column(
              crossAxisAlignment: CrossAxisAlignment.stretch,
              children: <Widget>[
                Icon(Icons.person, size: 120, color: Colors.deepPurple),
                TextFormField(
                  keyboardType: TextInputType.number,
                  decoration: InputDecoration(
                      labelText: "Peso (kg)",
                      labelStyle: TextStyle(color: Colors.deepPurple)),
                  textAlign: TextAlign.center,
                  style: TextStyle(color: Colors.deepPurple, fontSize: 25.0),
                  controller: pesoController,
                  validator: (value) {
                    return value!.isEmpty ? "Insira seu Peso!" : null;
                  },
                ),
                TextFormField(
                  keyboardType: TextInputType.number,
                  decoration: InputDecoration(
                      labelText: "Altura (cm)",
                      labelStyle: TextStyle(color: Colors.deepPurple)),
                  textAlign: TextAlign.center,
                  style: TextStyle(color: Colors.deepPurple, fontSize: 25.0),
                  controller: alturaController,
                  validator: (value) {
                    return value!.isEmpty ? "Insira sua altura!" : null;
                  },
                ),
                Padding(
                  padding: EdgeInsets.only(top: 10.0, bottom: 10.0),
                  child: ButtonTheme(
                      height: 50.0,
                      highlightColor: Colors.indigo,
                      child: ElevatedButton(
                          onPressed: () {
                            //if (_formKey.currentState!.validate())
                            _calcular();
                          },
                          child: Text(
                            "Calcular",
                            style:
                                TextStyle(color: Colors.white, fontSize: 25.0),
                          ))),
                ),
                Padding(
                  padding: EdgeInsets.only(top: 10.0, bottom: 10.0),
                  child: ButtonTheme(
                      height: 50.0,
                      highlightColor: Colors.indigo,
                      child: ElevatedButton(
                          onPressed: () {
                            //if (_formKey.currentState!.validate())
                            _resetCampos();
                          },
                          child: Text(
                            "Reset",
                            style:
                                TextStyle(color: Colors.white, fontSize: 25.0),
                          ))),
                ),
                Text(_textInfo,
                    style: TextStyle(color: Colors.deepPurple, fontSize: 25.0)),
              ],
            ),
          ),
        ));
  }
}


import 'dart:ffi';

void main(List<String> args) {

  double numero = 3.1416;
  double infinito = double.infinity;
  

  print('Firma: ${ numero.sign } :: $numero'); //Regresa 1.0 si el numero es positivo
  
  print('isFinite: ${ numero.isFinite } :: $numero'); //False

  print('isFinite: ${ infinito.isFinite } :: $infinito'); //True, but why?

  print('abs: ${ numero.abs() } :: $numero'); //Devuelve el absoluto de un numero

  print('ceil: ${ numero.ceil() } :: $numero'); //Devuelve el siguiente numero entero mas cercano

  print('ceilToDouble: ${ numero.ceilToDouble() } :: $numero'); //Devuelve el numero entero mas cercano pero en double

  print('abs: ${ numero.abs() } :: $numero'); //Devuelve el absoluto de un numero

  print('round: ${ numero.round() } :: $numero'); //Redondea un numero a entero mas cercano 3.6 -> 3

  print('clamp: ${ numero.clamp(1, 3) } :: $numero'); //Devuelve un numero basado en un limite
}
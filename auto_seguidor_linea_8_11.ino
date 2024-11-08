#include <AFMotor.h>

// Pines de los sensores
const int ledPin1 = 22; // izquierda
const int ledPin2 = 24;
const int ledPin3 = 26; // centro
const int ledPin4 = 28;
const int ledPin5 = 30; // derecha

int lado = 0; // 0 = IZQUIERDA, 1 = DERECHA. Indica el último lado donde se detectó la pista.

AF_DCMotor motor1(3);  // Motor 1 conectado a entrada 3 (Derecha)
AF_DCMotor motor2(4);  // Motor 2 conectado a entrada 4 (Izquierda)

void setup() {
  Serial.begin(9600);
  
  // Configuración de pines de sensores
  pinMode(ledPin1, INPUT);
  pinMode(ledPin2, INPUT);
  pinMode(ledPin3, INPUT);
  pinMode(ledPin4, INPUT);
  pinMode(ledPin5, INPUT);

  // Espera hasta que el sensor central detecte pista para empezar el movimiento
  while (true) {
    int value1 = digitalRead(ledPin1);
    int value2 = digitalRead(ledPin2);
    int value3 = digitalRead(ledPin3);
    int value4 = digitalRead(ledPin4);
    int value5 = digitalRead(ledPin5);

    if (value1 == 1 && value2 == 1 && value3 == 0 && value4 == 1 && value5 == 1) {
      delay(2000); // Espera 2 segundos antes de comenzar
      motor1.setSpeed(98);
      motor2.setSpeed(100);
      motor1.run(FORWARD);
      motor2.run(FORWARD);
      break;
    }
  }
}

void loop() {
  // Leer valores de los sensores
  int value1 = digitalRead(ledPin1);
  int value2 = digitalRead(ledPin2);
  int value3 = digitalRead(ledPin3);
  int value4 = digitalRead(ledPin4);
  int value5 = digitalRead(ledPin5);

  // Control del motor según sensores
  if (value4 == 0 && value5 == 0) { // Ambos sensores de la derecha detectan pista
    lado = 1;
    motor1.setSpeed(30); 
    motor2.setSpeed(100);
  } else if (value4 == 0 && value5 == 1) { // Primer sensor derecho detecta pista
    lado = 1;
    motor1.setSpeed(30);
    motor2.setSpeed(100);
  } else if (value4 == 1 && value5 == 0) { // Segundo sensor derecho detecta pista
    lado = 1;
    motor1.setSpeed(28);
    motor2.setSpeed(100);
  } else if (value1 == 0 && value2 == 0) { // Ambos sensores de la izquierda detectan pista
    lado = 0;
    motor1.setSpeed(96);
    motor2.setSpeed(30);
  } else if (value1 == 1 && value2 == 0) { // Primer sensor izquierdo detecta pista
    lado = 0;
    motor1.setSpeed(96);
    motor2.setSpeed(30);
  } else if (value1 == 0 && value2 == 1) { // Segundo sensor izquierdo detecta pista
    lado = 0;
    motor1.setSpeed(96);
    motor2.setSpeed(30);
  } else if (value1 == 1 && value2 == 1 && value3 == 1 && value4 == 1 && value5 == 1) { 
    // Todos los sensores detectan pista perdida
    if (lado == 0) {
      motor1.setSpeed(86);
      motor2.setSpeed(30);
    } else {
      motor1.setSpeed(28);
      motor2.setSpeed(90);
    }
  } else if (value1 == 1 && value2 == 1 && value3 == 0 && value4 == 1 && value5 == 1) {
    // Sensor central detecta pista
    motor1.setSpeed(96);
    motor2.setSpeed(100);
  }
}



//Dejo funciones de doblado por si las quieren usar. Quizas lo hace mas lento y no queremos, por eso no las use.
void derechaLeve(int value1, int value2, int value3, int value4, int value5){
  motor1.setSpeed(10);
  motor2.setSpeed(50);
}

void derechaFuerte(int value1, int value2, int value3, int value4, int value5){
  motor1.setSpeed(0);
  motor2.setSpeed(70);
}

void izquierdaLeve(int value1, int value2, int value3, int value4, int value5){
  motor1.setSpeed(50);
  motor2.setSpeed(10);
}

void izquierdaFuerte(int value1, int value2, int value3, int value4, int value5){
  motor1.setSpeed(70);
  motor2.setSpeed(0);
}

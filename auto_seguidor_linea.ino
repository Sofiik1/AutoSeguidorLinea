#include <AFMotor.h>

// Pines de los sensores
const int ledPin1 = 52;
const int ledPin2 = 50;
const int ledPin3 = 48;
const int ledPin4 = 46;
const int ledPin5 = 44;


AF_DCMotor motor1(3);  // Motor 1 conectado a entrada 3
AF_DCMotor motor2(4);  // Motor 2 conectado a entrada 4


void setup() {
  // Inicia la comunicación serial para mostrar los resultados
  Serial.begin(9600);
  //delay(5000) DESCOMENTAR ANTES DE ENTREGAR

  // Configura los pines como entradas
  pinMode(ledPin1, INPUT);
  pinMode(ledPin2, INPUT);
  pinMode(ledPin3, INPUT);
  pinMode(ledPin4, INPUT);
  pinMode(ledPin5, INPUT);
}

void loop() {
  // Lee los valores de los sensores
  int value1 = digitalRead(ledPin1);
  int value2 = digitalRead(ledPin2);
  int value3 = digitalRead(ledPin3);
  int value4 = digitalRead(ledPin4);
  int value5 = digitalRead(ledPin5);

  // Muestra los resultados en el monitor serial
  Serial.print("Sensor 1: "); Serial.println(value1);
  Serial.print("Sensor 2: "); Serial.println(value2);
  Serial.print("Sensor 3: "); Serial.println(value3);
  Serial.print("Sensor 4: "); Serial.println(value4);
  Serial.print("Sensor 5: "); Serial.println(value5);

  // Espera un poco antes de volver a leer (pcional)
  if(value1 == 1 || value2 == 1 || value3 == 1 || value4 == 1 || value5 == 1){
    motor1.setSpeed(255); // Configurar la velocidad del motor (0-255)
    motor2.setSpeed(255); // Configurar la velocidad del motor (0-255)
    motor1.run(FORWARD);
    motor2.run(FORWARD);
  }
  else {
    motor1.run(RELEASE);
    motor2.run(RELEASE);
  }
  delay(500);  // 500 milisegundos de espera
}
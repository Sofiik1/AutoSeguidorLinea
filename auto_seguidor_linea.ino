#include <AFMotor.h>

// Pines de los sensores
const int ledPin1 = 22; //izq
const int ledPin2 = 24;
const int ledPin3 = 26;
const int ledPin4 = 28;
const int ledPin5 = 30; //der

int lado = 0; //Uso 0 = IZQUIERDA y 1 = DERECHA. Cuando no este tomando la pista voy a usar este valor como el ultimo estado.
//El valor me va a indicar de que lado vi por ultima vez la pista (lado al que doblar)

AF_DCMotor motor1(3);  // Motor 1 conectado a entrada 3 DERECHA 
AF_DCMotor motor2(4);  // Motor 2 conectado a entrada 4 izquierda


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

  while (true) {
      int value1 = digitalRead(ledPin1); // Izquierda
      int value2 = digitalRead(ledPin2);
      int value3 = digitalRead(ledPin3); // Centro
      int value4 = digitalRead(ledPin4);
      int value5 = digitalRead(ledPin5); // Derecha

      if (value1 == 1 && value2 == 1 && value3 == 0 && value4 == 1 && value5 == 1) {
        delay(2000); // Espera 2 segundos
        motor1.setSpeed(50); // Configurar velocidad inicial del motor1
        motor2.setSpeed(50); // Configurar velocidad inicial del motor2
        motor1.run(FORWARD);
        motor2.run(FORWARD);
        break; // Sale del bucle al iniciar el movimiento
      }
    }
  
}

void loop() {
  
  // Lee los valores de los sensores
  int value1 = digitalRead(ledPin1); //izq
  int value2 = digitalRead(ledPin2);
  int value3 = digitalRead(ledPin3);
  int value4 = digitalRead(ledPin4);
  int value5 = digitalRead(ledPin5); //der

  
    // Baja la velocidad de motor1 si el sensor derecho se apaga
  if (value4 == 0 && value5 == 0) { //Los dos sensores de la derecha detectan pista. Gira SOLO rueda izquierda
    lado = 1;
    motor1.setSpeed(0); 
    motor2.setSpeed(50);
  } else if(value4 == 0 && value5 == 1){ //El primer sensor derecho detecta pista. Gira MAS rueda izquierda
    lado = 1;
    motor1.setSpeed(0);
    motor2.setSpeed(50);
  } else if(value4 == 1 && value5 == 0){//Mismo que anterior
    lado = 1;
    motor1.setSpeed(0);
    motor2.setSpeed(50);
  } else if(value1 == 0 && value2 == 0){//Los dos sensores de la izquierda detectan pista
    lado = 0;
    motor1.setSpeed(50);
    motor2.setSpeed(0);
  } else if(value1 == 1 && value2 == 0){
    lado = 0;
    motor1.setSpeed(50);
    motor2.setSpeed(0);
  } else if(value1 == 0 && value2 == 1){
    lado = 0;
    motor1.setSpeed(50);
    motor2.setSpeed(0);
  } else if(value1 == 1 && value2 == 1 && value3 == 1 && value4 == 1 && value5 == 1){ 
    if (lado == 0){
      motor1.setSpeed(50);
      motor2.setSpeed(0);
    } else {
      motor1.setSpeed(0);
      motor2.setSpeed(50);
    }
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

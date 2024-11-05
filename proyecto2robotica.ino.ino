#include <AFMotor.h>


AF_DCMotor motor1(3);  // Motor 1 conectado a entrada 3
AF_DCMotor motor2(4);  // Motor 2 conectado a entrada 4


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  motor1.setSpeed(255); // Configurar la velocidad del motor (0-255)
  motor1.run(FORWARD);
  motor2.setSpeed(255); // Configurar la velocidad del motor (0-255)
  motor2.run(FORWARD);
}

void loop() {
  // Girar el motor hacia adelante
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  delay(2000);  // Girar por 2 segundos
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  delay(2000);
}
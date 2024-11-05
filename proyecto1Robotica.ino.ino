#include <AFMotor.h>


const int boton1 = 52;
const int boton2 = 50;
AF_DCMotor motor(4);  // Motor 4 conectado a MOTOR A

int velocidad = 255;                   // Valor inicial del PWM (brillo del LED)
const int dutyCycle = 255;          // Valor máximo de PWM (brillo máximo)
const int paso = dutyCycle * 0.2;   // Incremento/decremento del 20% (51 en escala de 0-255)
bool direccion = true;


void setup() {
  // put your setup code here, to run once:
  pinMode(boton1, INPUT);
  pinMode(boton2, INPUT);
  Serial.begin(9600);
  motor.setSpeed(255); // Configurar la velocidad del motor (0-255)
  motor.run(FORWARD);
}

void loop() {
  // boton1
  if(digitalRead(boton1) == LOW){
    Serial.println("apretado 1");
    if(velocidad >=255){
      velocidad = 0;
      motor.setSpeed(velocidad);
    }
    else{
      velocidad += paso;
      motor.setSpeed(velocidad);
    }
    delay(200);
  }
  else if(digitalRead(boton1) == HIGH){
    Serial.println("suelto");
    delay(100);
  }


  if(digitalRead(boton2) == LOW) { // Si boton2 está presionado
    Serial.println("apretado2");
    direccion = !direccion;        // Cambia la dirección
    delay(300);                    // Pequeño retardo para evitar múltiples cambios por una sola pulsación
      // Control del motor según la dirección
    if(direccion) {
      // Configuración para una dirección
      motor.run(RELEASE);
      motor.run(BACKWARD);
      Serial.println("Motor backward");
    } else {
      // Configuración para la otra dirección
      motor.run(RELEASE);
      motor.run(FORWARD);
      Serial.println("Motor forward");
    }
  }
  else if(digitalRead(boton2) == HIGH){
    Serial.println("suelto");
    delay(100);
  }

} 

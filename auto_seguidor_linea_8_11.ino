#include <AFMotor.h>
#include <LiquidCrystal.h>

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

LiquidCrystal lcd(32,33,34,35,36,37);


//PONGO EL IZQ 1/8 MENOR AL DERECHO PORQUE TIRAN DISTINTA POTENCIA
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

  lcd.begin(16,2);
  lcd.setCursor(2,0);

  while (true) {
      int value1 = digitalRead(ledPin1); // Izquierda
      int value2 = digitalRead(ledPin2);
      int value3 = digitalRead(ledPin3); // Centro
      int value4 = digitalRead(ledPin4);
      int value5 = digitalRead(ledPin5); // Derecha

      if (value1 == 1 && value2 == 1 && value3 == 0 && value4 == 1 && value5 == 1) {
        lcd.setCursor(2,0);
        lcd.print("4");
        delay(1000); // Espera 5 segundos
        lcd.setCursor(2,0);
        lcd.print("3");
        delay(1000); // Espera 5 segundos
        lcd.setCursor(2,0);
        lcd.print("2");
        delay(1000); // Espera 5 segundos
        lcd.setCursor(2,0);
        lcd.print("1");
        delay(1000); // Espera 5 segundos
        lcd.setCursor(2,0);
        lcd.print("GO!");
        delay(1000); // Espera 5 segundos
        motor1.setSpeed(100); // Configurar velocidad inicial del motor1
        motor2.setSpeed(90); // Configurar velocidad inicial del motor2
        motor1.run(FORWARD);
        motor2.run(FORWARD);
        break; // Sale del bucle al iniciar el movimiento
      }
    }
    lcd.setCursor(2,0);
    lcd.print("LA COLAPINTA");
  
}

void loop() {
  
  // Lee los valores de los sensores
  int value1 = digitalRead(ledPin1); //izq
  int value2 = digitalRead(ledPin2);
  int value3 = digitalRead(ledPin3);
  int value4 = digitalRead(ledPin4);
  int value5 = digitalRead(ledPin5); //der

  
    // Baja la velocidad de motor1 si el sensor derecho se apaga
  if (value1 == 1 && value2 == 1 && value3 == 1 && value4 == 0 && value5 == 0) { //AMBOS SENSORES DERECHA
    lado = 1;
    motor1.setSpeed(5); 
    motor2.setSpeed(110);

    lcd.setCursor(2,0);
    lcd.print("LA COLAPINTA");
  } else if(value1 == 1 && value2 == 1 && value3 == 1 && value4 == 0 && value5 == 1){ //SENSOR MEDIO DERECHA
    lado = 1;
    motor1.setSpeed(60);
    motor2.setSpeed(120);

    lcd.setCursor(2,0);
    lcd.print("LA COLAPINTA");
  } else if(value1 == 1 && value2 == 1 && value3 == 0 && value4 == 0 && value5 == 1){
    motor1.setSpeed(30);
    motor2.setSpeed(120);

    lcd.setCursor(2,0);
    lcd.print("LA COLAPINTA");
  } else if(value1 == 1 && value2 == 1 && value3 == 1 && value4 == 1 && value5 == 0){ //SENSOR FULL DERECHA
    lado = 1;
    motor1.setSpeed(5);
    motor2.setSpeed(125);

    lcd.setCursor(2,0);
    lcd.print("LA COLAPINTA");
  } else if(value1 == 0 && value2 == 0 && value3 == 1 && value4 == 1 && value5 == 1){ //AMBOS SENSORES IZQUIERDA
    lado = 0;
    motor1.setSpeed(125);
    motor2.setSpeed(10);

    lcd.setCursor(2,0);
    lcd.print("LA COLAPINTA");
  } else if(value1 == 1 && value2 == 0 && value3 == 1 && value4 == 1 && value5 == 1){ //SENSOR MEDIO IZQUIERDA
    lado = 0;
    motor1.setSpeed(120);
    motor2.setSpeed(40);

    lcd.setCursor(2,0);
    lcd.print("LA COLAPINTA");
  } else if(value1 == 1 && value2 == 0 && value3 == 0 && value4 == 1 && value5 == 1){
    motor1.setSpeed(120);
    motor2.setSpeed(30);

    lcd.setCursor(2,0);
    lcd.print("LA COLAPINTA");
  } else if(value1 == 0 && value2 == 1 && value3 == 1 && value4 == 1 && value5 == 1){ //SENSOR FULL IZQUIERDA
    lado = 0;
    motor1.setSpeed(125);
    motor2.setSpeed(5);

    lcd.setCursor(2,0);
    lcd.print("LA COLAPINTA");
  } else if (value1 == 1 && value2 == 1 && value3 == 0 && value4 == 1 && value5 == 1) {
      motor1.setSpeed(120); // Configurar velocidad inicial del motor1
      motor2.setSpeed(110); // Configurar velocidad inicial del motor2

      lcd.setCursor(2,0);
      lcd.print("LA COLAPINTA");
  } else if(value1 == 1 && value2 == 1 && value3 == 1 && value4 == 1 && value5 == 1){  //NINGUNO, RECUPERO PISTA
    if (lado == 0){
      motor1.setSpeed(100);
      motor2.setSpeed(10);
      lcd.setCursor(2,0);
      lcd.print("LA COLAPINTA");
      
    } else {
      motor1.setSpeed(10);
      motor2.setSpeed(100);
      lcd.setCursor(2,0);
      lcd.print("LA COLAPINTA");
    }
  } else {
    motor1.setSpeed(120);
    motor2.setSpeed(120);
  }

  
}
//Dejo funciones de doblado por si las quieren usar. Quizas lo hace mas lento y no queremos, por eso no las use.
void derechaLeve(int value1, int value2, int value3, int value4, int value5){
  motor1.setSpeed(35);
  motor2.setSpeed(70);
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

// buzzer
int bocina = 2;

// sensores en digital
int izq = 3;
int der = 4;

// pines para los motores
int ena = 5;
int mizq1 = 7;
int mizq2 = 8;

int enb = 6;
int mder1 = 9;
int mder2 = 10;

int vel = 180;

void setup() {
  Serial.begin(9600);

  // buzzer como salida
  pinMode(bocina, OUTPUT);
  
  // inicializamos los sensores en modo entrada
  pinMode(izq, INPUT);
  pinMode(der, INPUT);

  // inicializar motor izquierdo
  pinMode(ena, OUTPUT);
  pinMode(mizq1, OUTPUT);
  pinMode(mizq2, OUTPUT);

  // inicializar motor derecho
  pinMode(enb, OUTPUT);
  pinMode(mder1, OUTPUT);
  pinMode(mder2 ,OUTPUT);
}

void loop() {

  // 1 es negro, 0 es blanco
  int sensor_izq = digitalRead(izq);
  int sensor_der = digitalRead(der);

  // mostramos en el monitor serie los valores leídos
  Serial.print("Sensor IZQ: ");
  Serial.print(sensor_izq);
  delay(100);
  Serial.print("\tSensor DER: ");
  Serial.println(sensor_der);

  if(sensor_izq == 1 && sensor_der == 1) {
    ADELANTE(vel);
    digitalWrite(bocina, LOW);
  }
  if(sensor_izq == 0 && sensor_der == 0) { // se salió del camino.
    PARAR();
    digitalWrite(bocina, LOW);
  }
  if(sensor_izq == 0 && sensor_der == 1) {
    DERECHA(vel);
    digitalWrite(bocina, HIGH);
  }
  if(sensor_izq == 1 && sensor_der == 0) {
    IZQUIERDA(vel);
    digitalWrite(bocina, HIGH);
  }

}

// función ADELANTE(int vel)
void ADELANTE(int vel) {
   //Direccion motor A
   digitalWrite (mizq1, HIGH);
   digitalWrite (mizq2, LOW);
   analogWrite (ena, vel); //Velocidad motor A
   //Direccion motor B
   digitalWrite (mder1, HIGH);
   digitalWrite (mder2, LOW);
   analogWrite (enb, vel); //Velocidad motor B
}

// función ATRAS(int vel)
void ATRAS(int vel){
   //Direccion motor A
   digitalWrite (mizq1, LOW);
   digitalWrite (mizq2, HIGH);
   analogWrite (ena, vel); //Velocidad motor A
   //Direccion motor B
   digitalWrite (mder1, LOW);
   digitalWrite (mder2, HIGH);
   analogWrite (enb, vel); //Velocidad motor B
}

// función DERECHA(int vel)
void DERECHA(int vel){
   //Direccion motor A
   digitalWrite (mizq1, LOW);
   digitalWrite (mizq2, HIGH);
   analogWrite (ena, vel); //Velocidad motor A
   //Direccion motor B
   digitalWrite (mder1, LOW);
   digitalWrite (mder2, HIGH);
   analogWrite (enb, vel); //Velocidad motor B
}

// función IZQUIERDA(int vel)
void IZQUIERDA(int vel){
   //Direccion motor A
   digitalWrite (mizq1, LOW);
   digitalWrite (mizq2, HIGH);
   analogWrite (ena, vel); //Velocidad motor A
   //Direccion motor B
   digitalWrite (mder1, LOW);
   digitalWrite (mder2, HIGH);
   analogWrite (enb, vel); //Velocidad motor B
}

// función PARAR()
void PARAR(){
   digitalWrite (mizq1, LOW);
   digitalWrite (mizq2, LOW);

   digitalWrite (mder1, LOW);
   digitalWrite (mder2, LOW);  
}

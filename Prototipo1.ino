int pinOut = 2;

float frecuencia_max = 50;
float frecuencia_min = 0;

float anchoPulso_max = 500;
float anchoPulso_min = 100;

float max_voltaje = 52;

float tiempoPulsoTotal;
float cicloDeTrabajo;
float clicloDeDescanso;

float tempFrecuencia;
float tempAncho;

bool res;

void setup() {
  pinMode(pinOut, OUTPUT);

  Serial.begin(115200);
  Serial.println("Tiki");
  
}


void loop() {
  // put your main code here, to run repeatedly:
  tempFrecuencia = 50;
  tempAncho = 100;

  tiempoPulsoTotal, cicloDeTrabajo, clicloDeDescanso = calcularCicloDeTrabajo(tempFrecuencia, tempAncho);

  Serial.println(cicloDeTrabajo);
  Serial.println(clicloDeDescanso);

  analogWrite(pinOut, 255);
  delayMicroseconds(cicloDeTrabajo);
  delay(3000);
  digitalWrite(pinOut, LOW);
  delayMicroseconds(clicloDeDescanso);
  delay(5000);
}

float calcularCicloDeTrabajo(float frecuencia, float anchoPulso) {

  if (frecuencia < frecuencia_min) {
    frecuencia = frecuencia_min;
  }
  if (anchoPulso < anchoPulso_min) {
    anchoPulso = anchoPulso_min;
  }

  tiempoPulsoTotal = (1/frecuencia) * 1000; // (1/50) * 1000 = 20
  cicloDeTrabajo = anchoPulso/tiempoPulsoTotal; // 100 / 20 = 5
  clicloDeDescanso = tiempoPulsoTotal-cicloDeTrabajo; //  20 - 5 = 15

  return tiempoPulsoTotal, cicloDeTrabajo, clicloDeDescanso;
}

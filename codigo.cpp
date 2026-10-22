const int RELAY_PIN = 0;
const int SWITCH_PIN = 4;

const unsigned long CHUVA_OFF = 25000;
const unsigned long CHUVA_ON = 10000;
const unsigned long SECA_OFF = 5000;
const unsigned long SECA_ON = 20000;

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(SWITCH_PIN, INPUT_PULLUP);
  digitalWrite(RELAY_PIN, LOW);
}

void loop() {
  bool modoChuva = (digitalRead(SWITCH_PIN) == HIGH);

  unsigned long tempoDesligado = modoChuva ? CHUVA_OFF : SECA_OFF;
  unsigned long tempoLigado = modoChuva ? CHUVA_ON : SECA_ON;

  digitalWrite(RELAY_PIN, LOW);
  delay(tempoDesligado);

  digitalWrite(RELAY_PIN, HIGH);
  delay(tempoLigado);
}

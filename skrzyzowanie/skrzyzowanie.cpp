#define ZIELONA_1 2
#define CZERWONA_1 3

#define ZIELONA_2 4
#define CZERWONA_2 5

#define ZIELONA_3 6
#define CZERWONA_3 7

#define ZIELONA_4 8
#define CZERWONA_4 9

#define CZAS_ZIELONE 4000
#define CZAS_PRZERWY 2000

unsigned long poprzedniCzas = 0;

int grupa = 0;
int stan = 0;
// 0 = jedna zielona + 3 czerwone
// 1 = wszystkie czerwone

void setup() {
  pinMode(ZIELONA_1, OUTPUT);
  pinMode(CZERWONA_1, OUTPUT);

  pinMode(ZIELONA_2, OUTPUT);
  pinMode(CZERWONA_2, OUTPUT);

  pinMode(ZIELONA_3, OUTPUT);
  pinMode(CZERWONA_3, OUTPUT);

  pinMode(ZIELONA_4, OUTPUT);
  pinMode(CZERWONA_4, OUTPUT);

  ustawZielone();
}

void loop() {
  unsigned long aktualnyCzas = millis();

  if (stan == 0) {

    // Zielone œwieci przez 4 sekundy
    if (aktualnyCzas - poprzedniCzas >= CZAS_ZIELONE) {
      poprzedniCzas = aktualnyCzas;

      stan = 1;
      ustawCzerwone();
    }

  } else {

    // Wszystkie czerwone przez 2 sekundy
    if (aktualnyCzas - poprzedniCzas >= CZAS_PRZERWY) {
      poprzedniCzas = aktualnyCzas;

      grupa++;

      if (grupa > 3) {
        grupa = 0;
      }

      stan = 0;
      ustawZielone();
    }
  }
}

void ustawZielone() {

  // Wszystkie czerwone
  digitalWrite(CZERWONA_1, HIGH);
  digitalWrite(CZERWONA_2, HIGH);
  digitalWrite(CZERWONA_3, HIGH);
  digitalWrite(CZERWONA_4, HIGH);

  // Wszystkie zielone wy³¹czone
  digitalWrite(ZIELONA_1, LOW);
  digitalWrite(ZIELONA_2, LOW);
  digitalWrite(ZIELONA_3, LOW);
  digitalWrite(ZIELONA_4, LOW);

  // Zielone dla aktualnej grupy
  if (grupa == 0) {
    digitalWrite(ZIELONA_1, HIGH);
    digitalWrite(CZERWONA_1, LOW);
  }
  else if (grupa == 1) {
    digitalWrite(ZIELONA_2, HIGH);
    digitalWrite(CZERWONA_2, LOW);
  }
  else if (grupa == 2) {
    digitalWrite(ZIELONA_3, HIGH);
    digitalWrite(CZERWONA_3, LOW);
  }
  else if (grupa == 3) {
    digitalWrite(ZIELONA_4, HIGH);
    digitalWrite(CZERWONA_4, LOW);
  }
}

void ustawCzerwone() {

  // Wszystkie zielone wy³¹czone
  digitalWrite(ZIELONA_1, LOW);
  digitalWrite(ZIELONA_2, LOW);
  digitalWrite(ZIELONA_3, LOW);
  digitalWrite(ZIELONA_4, LOW);

  // Wszystkie czerwone w³¹czone
  digitalWrite(CZERWONA_1, HIGH);
  digitalWrite(CZERWONA_2, HIGH);
  digitalWrite(CZERWONA_3, HIGH);
  digitalWrite(CZERWONA_4, HIGH);
}

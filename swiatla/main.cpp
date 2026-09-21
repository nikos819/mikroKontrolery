#define ledZiel1 2
#define ledZiel2 4
#define ledCzer1 3
#define ledCzer2 5

unsigned long poprzedniCzas = 0;

int stan = 0;

// Czasy
const unsigned long czasZielone = 2000;  // 4 sekundy
const unsigned long czasPrzerwy = 4000;  // 2 sekundy

void ustawSwiatla(bool ziel1, bool czerw1, bool ziel2, bool czerw2) {
    digitalWrite(ledZiel1, ziel1);
    digitalWrite(ledCzer1, czerw1);
    digitalWrite(ledZiel2, ziel2);
    digitalWrite(ledCzer2, czerw2);
}

void setup() {
    pinMode(ledZiel1, OUTPUT);
    pinMode(ledZiel2, OUTPUT);
    pinMode(ledCzer1, OUTPUT);
    pinMode(ledCzer2, OUTPUT);

    // Kierunek 1 zielone, kierunek 2 czerwone
    ustawSwiatla(HIGH, LOW, LOW, HIGH);
}

void loop() {

    unsigned long aktualnyCzas = millis();

    if (aktualnyCzas - poprzedniCzas >=
        (stan == 0 || stan == 2 ? czasZielone : czasPrzerwy)) {

        poprzedniCzas = aktualnyCzas;

        if (stan == 0) {
            // 4 sekundy:
            // Kierunek 1 zielone, kierunek 2 czerwone
            ustawSwiatla(HIGH, LOW, LOW, HIGH);

            stan = 1;
        }
        else if (stan == 1) {
            // 2 sekundy:
            // OBA KIERUNKI CZERWONE
            ustawSwiatla(LOW, HIGH, LOW, HIGH);

            stan = 2;
        }
        else if (stan == 2) {
            // 4 sekundy:
            // Kierunek 1 czerwone, kierunek 2 zielone
            ustawSwiatla(LOW, HIGH, HIGH, LOW);

            stan = 3;
        }
        else {
            // 2 sekundy:
            // OBA KIERUNKI CZERWONE
            ustawSwiatla(LOW, HIGH, LOW, HIGH);

            stan = 0;
        }
    }
}

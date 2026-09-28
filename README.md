# Program sterujący 8 diodami na wzór skrzyżowania w Ostrzeszowie

## Opis

Program sterujący 8 diodami LED na wzór sygnalizacji świetlnej na skrzyżowaniu w Ostrzeszowie.

## Układ

Układ składa się z 4 grup świateł:

- Grupa 1: zielona – pin 2, czerwona – pin 3
- Grupa 2: zielona – pin 4, czerwona – pin 5
- Grupa 3: zielona – pin 6, czerwona – pin 7
- Grupa 4: zielona – pin 8, czerwona – pin 9

## Działanie

Każda grupa otrzymuje zielone światło na 4 sekundy.

Następnie przez 2 sekundy świecą wszystkie czerwone światła, po czym zielone światło otrzymuje kolejna grupa.

## Sekwencja

🟢 🔴 🔴 🔴

🔴 🔴 🔴 🔴

🔴 🟢 🔴 🔴

🔴 🔴 🔴 🔴

🔴 🔴 🟢 🔴

🔴 🔴 🔴 🔴

🔴 🔴 🔴 🟢

🔴 🔴 🔴 🔴

## Wykorzystane technologie

- Arduino Uno
- 8 diod LED
- `millis()`
- Arduino IDE

## Czas działania

- Zielone światło: 4 sekundy
- Wszystkie czerwone światła: 2 sekundy

## Autor

Projekt wykonany w ramach nauki programowania mikrokontrolerów.

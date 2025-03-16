#define PIR_PIN 2
#define SOUND_PIN 3
#define RELAY_PIN 4

bool lightState = false;

void setup() {
    pinMode(PIR_PIN, INPUT);
    pinMode(SOUND_PIN, INPUT);
    pinMode(RELAY_PIN, OUTPUT);
    digitalWrite(RELAY_PIN, LOW); // Light OFF by default
}

void loop() {
    if (digitalRead(PIR_PIN) == HIGH) {
        digitalWrite(RELAY_PIN, HIGH); // Turn light ON
        delay(5000); // Keep it ON for 5 sec
    }

    if (digitalRead(SOUND_PIN) == HIGH) {
        lightState = !lightState; // Toggle state
        digitalWrite(RELAY_PIN, lightState ? HIGH : LOW);
        delay(500); // Debounce
    }
}

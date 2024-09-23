// Controller for LPF and LDMOS amplifier
// Christopher F. Moran, VK2MEI
//
#define BAND_IN A0
#define NUM_SAMPLES 3

#define RLY_10M D2
#define RLY_15M D3
#define RLY_30M D3
#define RLY_40M D4
#define RLY_80M D5

void setup() {
    Serial.begin(9600);
    while(!Serial) {
        ;               // We might need this for some USB boards.  No harm
    }
    Serial.println("Starting up");

    // Set up the I/O pins
    pinMode(RLY_10M, OUTPUT);
    pinMode(RLY_15M, OUTPUT);
    pinMode(RLY_30M, OUTPUT);
    pinMode(RLY_40M, OUTPUT);
    pinMode(RLY_80M, OUTPUT);
}

void loop() {
    delay(1000);
    int i = 0;
    int vBand = 0;
    int vRes = 0;
    // For more stable output, average
    // the data from the ACC port
    for(i=0; i < NUM_SAMPLES; i++) {
        vBand += analogRead(BAND_IN);
        delay(200);
    }
    vRes = vBand / NUM_SAMPLES;
    Serial.print("Reading ");
    Serial.print(vRes);

    if(vRes == 0)
      Serial.println(" Transceiver OFF");
    // You will probably need to adjust these values
    // to suit your transceiver, as they were determined
    // experimentally.
    else if(vRes > 0 && vRes < 100) {
      Serial.println(" 30m");
      outputsOff();
      digitalWrite(RLY_30M, HIGH);
    }
    else if(vRes >= 100 && vRes < 200) {
      Serial.println(" 6m");
      outputsOff();
    }
    else if(vRes >= 200 && vRes < 235) {
      Serial.println(" 10m/12m");
      outputsOff();
      digitalWrite(RLY_10M, HIGH);
    }
    else if(vRes >= 250 && vRes < 350) {
      Serial.println(" 17m/15m");
      outputsOff();
      digitalWrite(RLY_15M, HIGH);
    }
    else if(vRes >= 350 && vRes < 450) {
      Serial.println(" 20m");
      outputsOff();
      digitalWrite(RLY_30M, HIGH);
    }
    else if(vRes >= 450 && vRes < 550) {
        Serial.println(" 40m/60m");
        outputsOff();
        digitalWrite(RLY_40M, HIGH);
    }
    else if(vRes >= 550 && vRes < 650) {
      Serial.println(" 80m");
      outputsOff();
      digitalWrite(RLY_80M, HIGH);
    }
    else if(vRes >= 650 && vRes < 800) {
      Serial.println(" 160m/630m");
      outputsOff();
    }
}

void outputsOff(void) {
    digitalWrite(RLY_10M, LOW);
    digitalWrite(RLY_15M, LOW);
    digitalWrite(RLY_30M, LOW);
    digitalWrite(RLY_40M, LOW);
    digitalWrite(RLY_80M, LOW);
}

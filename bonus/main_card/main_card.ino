/* Arduino Uno Card */

struct pins {
    bool input;
    bool output;
    bool status;
    bool use;
};

struct pins card_pins[15];

void setup()
{
    Serial.begin(115200);

    for (int a = 0; a < 15; ++a) {
        card_pins[a].input = false;
        card_pins[a].output = false;
        card_pins[a].status = false;
        card_pins[a].use = false;
    }
}

void setup_out(int pin)
{
    if (pin >= 2 && pin <= 13) {
        pinMode(pin, OUTPUT);
        Serial.println("Pin setup");
        card_pins[pin].input = false;
        card_pins[pin].output = true;
        card_pins[pin].input = false;
        card_pins[pin].use = true;
    } else {
        Serial.println("Wrong pin");
    }
}

void setup_in(int pin)
{
    if (pin >= 2 && pin <= 13) {
        pinMode(pin, INPUT);
        Serial.println("Pin setup");
        card_pins[pin].input = true;
        card_pins[pin].output = false;
        card_pins[pin].input = true;
        card_pins[pin].status = false;
        card_pins[pin].use = true;
    } else {
        Serial.println("Wrong pin");
    }
}

void set_low(int pin) 
{
    if (pin < 2 || pin > 13) {
        Serial.println("Wrong pin");
        return;
    }
    if (card_pins[pin].use == false) {
        Serial.println("Pin not setup");
        return;
    }
    if (card_pins[pin].output == false) {
        Serial.println("this pin is not an output");
        return;
    }
    card_pins[pin].status = false;
}

void set_high(int pin) 
{
    if (pin < 2 || pin > 13) {
        Serial.println("Wrong pin");
        return;
    }
    if (card_pins[pin].use == false) {
        Serial.println("Pin not setup");
        return;
    }
    if (card_pins[pin].output == false) {
        Serial.println("this pin is not an output");
        return;
    }
    card_pins[pin].status = true;
}

void compute(void)
{
    for (int a = 0; a < 15; ++a) {
        if (card_pins[a].use == true && card_pins[a].output == true) {
            Serial.println(a);
            if (card_pins[a].status == true)
                digitalWrite(a, HIGH);
            else
                digitalWrite(a, LOW);
            Serial.println("pin " + String(a) + " (output) : " + (card_pins[a].status == HIGH ? "high" : "low"));
        }
    }
    delay(500);
    for (int a = 0; a < 15; ++a) {
        if (card_pins[a].use == true && card_pins[a].input == true) {
            int status = digitalRead(a);
            if (status == HIGH)
                card_pins[a].status = true;
            else
                card_pins[a].status = false;
            Serial.println("pin " + String(a) + " (input) : " + (status == HIGH ? "high" : "low"));
        } else {
            Serial.println("pin " + String(a) + " (unused or undefined)");
        }
    }
}

void loop() 
{
    String input;
    char read_str[200];
    int pin;
    bool continue_val = false;

    while (continue_val == false) {
        input[0] = 0;
        input = Serial.readString();
        if (sscanf(input.c_str(), "%s %d", read_str, &pin) == 2 || (sscanf(input.c_str(), "%s", read_str) == 1 && String(read_str) == "compute"))
            continue_val = true;
    }
    String command(read_str);
    Serial.println(command);
    Serial.println(pin);
    if (command == "in")
        setup_in(pin);
    if (command == "out")
        setup_out(pin);
    if (command == "high")
        set_high(pin);
    if (command == "low")
        set_low(pin);
    if (command == "compute")
        compute();
}

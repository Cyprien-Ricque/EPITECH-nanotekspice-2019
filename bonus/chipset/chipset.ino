/* Arduino Leonardo Code */

int current_chipset = 0;

const int in_std[] = {1, 2, 5, 6, 8, 9, 12, 13};
const int out_std[] = {3, 4, 10, 11};

const int out_inv[] = {2, 4, 6, 8, 10, 12};
const int in_inv[] = {1, 3, 5, 9, 11, 13};

void setup() {
    Serial.begin(115200);
}

void chipset_config(const int tab_in[], const int tab_out[])
{
    for (int a = 0; a < sizeof(tab_in); ++a)
        pinMode(a, INPUT);
    for (int a = 0; a < sizeof(tab_out); ++a)
        pinMode(a, OUTPUT);
}

void setup_chipset(int new_chipset)
{
    if (new_chipset == 4001 || new_chipset == 4002 || new_chipset == 4030 || new_chipset == 4071 || new_chipset == 4081) {
        chipset_config(in_std, out_std);
    } else if (new_chipset == 4069) {
        chipset_config(in_inv, out_inv);
    }
}

void calc_4001(void)
{
    for (int a = 0; a < 8; a += 2) {
        Serial.println("Work on chipset 4001");
        if (digitalRead(in_std[a]) == LOW && digitalRead(in_std[a + 1]) == LOW)
            digitalWrite(out_std[a / 2], HIGH);
        else
            digitalWrite(out_std[a / 2], LOW);
    }
}

void calc_4002(void)
{
    for (int a = 0; a < 8; a += 2) {
        Serial.println("Work on chipset 4002");
        if (digitalRead(in_std[a]) == HIGH && digitalRead(in_std[a + 1]) == HIGH)
            digitalWrite(out_std[a / 2], HIGH);
        else
            digitalWrite(out_std[a / 2], LOW);
    }
}

void calc_4030(void)
{
    for (int a = 0; a < 8; a += 2) {
        Serial.println("Work on chipset 4030");
        if ((digitalRead(in_std[a]) == HIGH && digitalRead(in_std[a + 1]) == LOW) ||
            (digitalRead(in_std[a]) == LOW && digitalRead(in_std[a + 1]) == HIGH))
            digitalWrite(out_std[a / 2], HIGH);
        else
            digitalWrite(out_std[a / 2], LOW);
    }
}

void calc_4071(void)
{
    for (int a = 0; a < 8; a += 2) {
        Serial.println("Work on chipset 4071");
        if (digitalRead(in_std[a]) == HIGH || digitalRead(in_std[a + 1]) == HIGH)
            digitalWrite(out_std[a / 2], HIGH);
        else
            digitalWrite(out_std[a / 2], LOW);
    }
}

void calc_4081(void)
{
    for (int a = 0; a < 8; a += 2) {
        Serial.println("Work on chipset 4081");
        if (digitalRead(in_std[a]) == digitalRead(in_std[a + 1]))
            digitalWrite(out_std[a / 2], HIGH);
        else
            digitalWrite(out_std[a / 2], LOW);
    }
}

void calc_4069(void)
{
    for (int a = 0; a < 8; a += 2) {
        Serial.println("Work on chipset 4069");
        digitalWrite(out_inv[a], !digitalRead(in_inv[a]));
    }
}

void loop() {
    String input = "";
    int previous_chipset = current_chipset;

    if (Serial.available())
        input = Serial.readString();
    if (input == "4001")
        current_chipset = 4001;
    else if (input == "4002")
        current_chipset = 4002;
    else if (input == "4030")
        current_chipset = 4030;
    else if (input == "4071")
        current_chipset = 4071;
    else if (input == "4081")
        current_chipset = 4081;
    else if (input == "4069")
        current_chipset = 4069;
    if (current_chipset != previous_chipset)
        setup_chipset(current_chipset);
    if (current_chipset == 4001)
        calc_4001();
    else if (current_chipset == 4002)
        calc_4002();
    else if (current_chipset == 4030)
        calc_4030();
    else if (current_chipset == 4071)
        calc_4071();
    else if (current_chipset == 4081)
        calc_4081();
    else if (current_chipset == 4069)
        calc_4069();
}

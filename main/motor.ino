#define lmotorf 16
#define lmotorb 17
#define rmotorf 5
#define rmotorb 19

void motor_setup()
{
        pinMode(lmotorf, OUTPUT);
        pinMode(rmotorf, OUTPUT);
        pinMode(lmotorb, OUTPUT);
        pinMode(rmotorb, OUTPUT);
}

void GoFrwrd()
{
        //both sensors on white
        // go forward
        digitalWrite(lmotorf, HIGH);
        digitalWrite(rmotorf, HIGH);
        digitalWrite(lmotorb, LOW);
        digitalWrite(rmotorb, LOW);
}
void TurnRight()
{
        //right sensor on black line
        // turn right
        digitalWrite(lmotorf, HIGH);
        digitalWrite(rmotorf, LOW);
        digitalWrite(lmotorb, LOW);
        digitalWrite(rmotorb, HIGH);
}
void TurnLeft()
{
        //left sensor on black line
        // turn left
        digitalWrite(lmotorf, LOW);
        digitalWrite(rmotorf, HIGH);
        digitalWrite(lmotorb, HIGH);
        digitalWrite(rmotorb, LOW);
}
void Stop()
{
        digitalWrite(lmotorf, LOW);
        digitalWrite(rmotorf, LOW);
        digitalWrite(lmotorb, LOW);
        digitalWrite(rmotorb, LOW);
}
void GoBack()
{
        digitalWrite(lmotorf, LOW);
        digitalWrite(rmotorf, LOW);
        digitalWrite(lmotorb, HIGH);
        digitalWrite(rmotorb, HIGH);
}
/*
Course: CISC 1600
Name: Jan Czeladko
Date: February 5, 2025
File: finalexam.cpp
Assignment: Generate the minimum thickness of a nuclear reactor's wall (in units)
needed to deflect/trap neutrons with following properties:
- The neutrons enter the wall at the random angle between -70 and +70 degrees.
- After each collision with the wall, the neutron travels a random distance between 0.6 and 1.3 units,
and changes its angle by a random amount -10 >= A >= -170 or 10 <= A <= 170.
- Assume that after 7 collisions the neutron is trapped.
- Assume that up to 2% of neutrons may escape through the wall without posing a threat.
*/

#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

const int NUM_NEUTRONS = 10000;
const int MAX_COLLISIONS = 7;
const double ALLOWED_MAX_RATIO = 0.02;

const double START_THICKNESS = 1.0;
const double STEP_THICKNESS  = 1.0;

const double MIN_ANGLE_ENTRY = -70.0;
const double MAX_ANGLE_ENTRY =  70.0;

const double MIN_DISTANCE = 0.6;
const double MAX_DISTANCE = 1.3;

const double MIN_ANGLE_DEFLECTION = 10.0;
const double MAX_ANGLE_DEFLECTION = 170.0;

unsigned int seed = int(time(0));
double random(unsigned int &seed);

double randRange(double minVal, double maxVal);

double genAngleEntry();
double genDistance();
double genAngleDeflection();

double degToRad(double deg);
double deltaX(double d, double Ad, double Ae);

bool simulateEscape(double wallThickness);
int countEscapedNeutrons(double wallThickness);
bool wallIsAcceptable(double ratio);

double findRequiredThickness();

int main()
{
    double requiredThickness = findRequiredThickness();

    cout << "Required wall thickness: " << requiredThickness << endl;
    return 0;
}

double random(unsigned int &seed)
{
    const int MODULUS = 15749;
    const int MULTIPLIER = 69069;
    const int INCREMENT = 1;
    seed = (MULTIPLIER * seed + INCREMENT) % MODULUS;
    return double(seed) / MODULUS;
}

double randRange(double minVal, double maxVal)
{
    return minVal + (maxVal - minVal) * random(seed);
}

double genAngleEntry()
{
    return randRange(MIN_ANGLE_ENTRY, MAX_ANGLE_ENTRY);
}

double genDistance()
{
    return randRange(MIN_DISTANCE, MAX_DISTANCE);
}

double genAngleDeflection()
{
    if (random(seed) < 0.5)
        return randRange(-MAX_ANGLE_DEFLECTION, -MIN_ANGLE_DEFLECTION);
    else
        return randRange(MIN_ANGLE_DEFLECTION, MAX_ANGLE_DEFLECTION);
}

double degToRad(double deg)
{
    return deg * M_PI / 180.0;
}

double deltaX(double d, double Ad, double Ae)
{
    return d * cos(degToRad(Ad - Ae));
}

bool simulateEscape(double wallThickness)
{
    double Ae = genAngleEntry();
    double x = 0.0;

    for (int collisions = 0; collisions < MAX_COLLISIONS; collisions++)
    {
        double d  = genDistance();
        double Ad = genAngleDeflection();

        x += deltaX(d, Ad, Ae);

        if (x >= wallThickness)
            return true;
    }

    return false;
}

int countEscapedNeutrons(double wallThickness)
{
    int escaped = 0;

    for (int i = 0; i < NUM_NEUTRONS; i++)
    {
        if (simulateEscape(wallThickness))
            escaped++;
    }
    return escaped;
}

bool wallIsAcceptable(double ratio)
{
    return ratio <= ALLOWED_MAX_RATIO;
}

double findRequiredThickness()
{
    double thickness = START_THICKNESS;

    while (true)
    {
        int escaped = countEscapedNeutrons(thickness);
        double ratio = double(escaped) / NUM_NEUTRONS;

        if (wallIsAcceptable(ratio))
            return thickness;

        thickness += STEP_THICKNESS;
    }
}

/*
Sample Output:
Required wall thickness: 4
*/
// Problem:
// An artificial satellite made entirely of gold is orbiting mars at a velocity of roughly 7.003687 kilometers per second. 
// The satellite was launched by a rocket exactly 1748 kilometers above the surface of mars.

// What is the maximum orbital period, given it will be unharmed?

#include <iostream>
#include <vector>
#include <cmath>

// G = 6.674×10^-20 km^3/kg s^2
const double G = 6.674 * pow(10, -20);

// Mass of Mars in kg, Radius in km
const double MMars = 6.417 * pow(10,23);
const double RMars = 3389.5;

// Density of Gold: 19.3 * 10^12 kg/km^3
const double DGold = 19.3 * pow(10,12);

// Radius of Satellite in km
const double RSat = 1748; // should be <= 1748

// Mass of Satellite in kg
const double MSat = DGold * M_PI * 4 / 3 * pow(RSat, 3);

struct point{
	double x;
	double y;
};

point add(point a, point b){
    point c {a.x + b.x, a.y + b.y};
    return c;
}

point multiply(point a, double i){
    point c {a.x * i, a.y * i};
    return c;
}

bool equal(point a, point b){
    double tolerance = 1; // in km
    double dx = abs(a.x - b.x);
    double dy = abs(a.y - b.y);
    return (dx <= tolerance && dy <= tolerance);
}

double distance(point p){
	return sqrt(pow(p.x,2) + pow(p.y,2));
}

point a(point p){
    double r3 = pow(distance(p), 3);
    point a = multiply(p, -1 / r3 * G * (MMars + MSat));
	return a;
}

int main(){
	// point p0 {1748 + RMars, 0};
	// point v0 {0, 7.003687};
	point p0 {1748 + RMars, 0};
	point v0 {0, 7.003687};

    double crash = RMars + RSat;

    double increment = pow(10, -1); // in seconds
    double stop = pow(10, 7) * increment; // stop at n seconds
    
	point p {p0};
	point v {v0};
    double r = distance(p);
    double min_distance = r;
    double max_distance = r;

    double t = 0;
    while((t < stop && r >= crash && !(equal(p0, p) && equal(v0, v))) || t < 1 ){
        p = add(p, multiply(v, increment));
        v = add(v, multiply(a(p), increment));
        r = distance(p);
        if(r < min_distance) min_distance = r;
        if(r > max_distance) max_distance = r;
        t += increment;
    }

	std::cout << "p(0): " << p0.x << ' ' << p0.y << '\n';
	std::cout << "v(0): " << v0.x << ' ' << v0.y << '\n';
	std::cout << "p: " << p.x << ' ' << p.y << '\n';
	std::cout << "v: " << v.x << ' ' << v.y << '\n';
	std::cout << "t = " << t << '\n';
    //std::cout << "Min distance between two bodies: " << min_distance - crash << '\n';
    //std::cout << "Max distance between two bodies: " << max_distance - crash << '\n';
    std::cout << "Min distance between two center of mass: " << min_distance << '\n';
    std::cout << "Max distance between two center of mass: " << max_distance << '\n';
    //std::cout << "TEST: " << MSat;
	return 0;
}
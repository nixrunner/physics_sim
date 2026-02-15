#include <iostream>
#include <cmath>

#define T_END (500.0)
#define DT    (0.2)
#define PI    (3.14159265)

class Body {
private:
    double x;
    double y;
    double z;
    double yaw;
    double v;
public:
    Body(double x_init, double y_init, double z_init, double yaw_init, double v_init)
    : x(x_init), y(y_init), z(z_init), yaw(yaw_init), v(v_init) {}



    void step(double dt){
        x += v * sin(yaw * PI / 180.0) * DT;
        y += v * cos(yaw * PI / 180.0) * DT;
    };

    void log(){
        std::cout << this->x << " \n";
        std::cout << this->y << " \n";
    };
};

void step(double& t ){
    t += DT;
}

int main()
{
    Body ship(0.0,0.0,0.0,30.0,10);
    double sim_time = 0.0;
    double dt = DT;


    while(sim_time < T_END){
        ship.step(DT);
        step(sim_time);
    }
    ship.log();

    return 0;
}

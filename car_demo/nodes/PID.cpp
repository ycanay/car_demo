#include"PID.h"

PID::PID(){
    this->proportion_constant = 0;
    this->derivative_constant = 0;
    this->integral_constant = 0;
    this->last_error = 0;
    this->error_sum = 0;
    this->set_point = 0;
}


PID::PID(double KP, double KD, double KI)
{
    this->proportion_constant = KP;
    this->derivative_constant = KD;
    this->integral_constant = KI;
    this->last_error = 0;
    this->error_sum = 0;
    this->set_point = 0;
}

PID::PID(double KP, double KD, double KI, double set_point)
{
    this->proportion_constant = KP;
    this->derivative_constant = KD;
    this->integral_constant = KI;
    this->last_error = 0;
    this->error_sum = 0;
    this->set_point = set_point;
}

PID::~PID()
{
}

double PID::get_control_input(double current_value){
    double error = set_point - current_value;
    double proportional_error = error;
    double integral_error = error_sum + error;
    double derivative_error = error - last_error;
    last_error = error;
    return proportion_constant * proportional_error + integral_constant * integral_error + derivative_constant * derivative_error;
}

double PID::get_set_point(){
    return set_point;
}

void PID::set_set_point(double new_set_point){
    this->set_point = new_set_point;
}

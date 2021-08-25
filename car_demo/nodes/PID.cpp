#include"PID.h"

PID::PID(){
    this->proportion_constant = 0;
    this->derivative_constant = 0;
    this->integral_constant = 0;
    this->last_error = 0;
    this->error_sum = 0;
    this->set_point = 0;
    this->max_control_input = 1;
    this->min_control_input = -1;
}


PID::PID(double KP, double KD, double KI)
{
    this->proportion_constant = KP;
    this->derivative_constant = KD;
    this->integral_constant = KI;
    this->last_error = 0;
    this->error_sum = 0;
    this->set_point = 0;
    this->max_control_input = 1;
    this->min_control_input = -1;
}

PID::PID(double KP, double KD, double KI, double set_point)
{
    this->proportion_constant = KP;
    this->derivative_constant = KD;
    this->integral_constant = KI;
    this->last_error = 0;
    this->error_sum = 0;
    this->set_point = set_point;
    this->max_control_input = 1;
    this->min_control_input = -1;
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
    double control = proportion_constant * proportional_error + integral_constant * integral_error + derivative_constant * derivative_error;
    if (control > max_control_input){
        control = max_control_input;
    }
    else if(control < min_control_input){
        control = min_control_input;
    }
    
    return control;
}

double PID::get_set_point(){
    return set_point;
}

void PID::set_set_point(double new_set_point){
    this->set_point = new_set_point;
}

void PID::set_control_input_limits(double max, double min){
    this->max_control_input = max;
    this->min_control_input = min;
}
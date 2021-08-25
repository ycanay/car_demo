#ifndef PID_H_
#define PID_H_

class PID
{
private:
    double proportion_constant;
    double derivative_constant;
    double integral_constant;
    double last_error;
    double error_sum;
    double set_point;
    double max_control_input;
    double min_control_input;
public:
    PID();
    PID(double KP, double KD, double KI);
    PID(double KP, double KD, double KI, double set_point);
    ~PID();
    double get_control_input(double current_value);
    
    double get_set_point();
    void set_set_point(double new_set_point);

    void set_control_input_limits(double max, double min);
};


#endif //PID_H_
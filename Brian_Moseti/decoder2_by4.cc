#include"decoder_2by4.h"
#include"driver.h"
#include"monitor.h"
#include<systemc.h>

int sc_main(int argc, char *argv[]){
//some signals for interconnections                                             
sc_signal<bool> in1,in2, out1, out2,out3,out4;
//module instances                                                              
two_by_four dec("decoder_instance");
driver dr("driver");
monitor mn("monitor");
//interconnections b2in modules                                                 
dr.d_a(in1);
dec.r(in1);
mn.m_a(in1);

dr.d_b(in2);
dec.s(in2);
mn.m_b(in2);

dec.e(out1);
mn.m_c(out1);

dec.f(out2);
mn.m_d(out2);

dec.g(out3);
mn.m_e(out3);

dec.h(out4);
mn.m_f(out4);


//create a trace file with nanosecond resolution
sc_trace_file *tf;
tf = sc_create_vcd_trace_file("timing_diagram");
tf->set_time_unit(1, SC_NS);
//trace the signals interconnecting modules
sc_trace(tf, in1, "binary_input1"); // signals to be traced
sc_trace(tf, in2, "binary_input2");
sc_trace(tf, out1, "inputs_are_zero_and_zero");
sc_trace(tf, out2, "inputs_are_zero_and_one");
sc_trace(tf, out3, "inputs_are_one_and_zero");
sc_trace(tf, out4, "input_are_one_and_one");


//run a simulation for 20 systemc nano-seconds
if( !sc_pending_activity() )
sc_start(25,SC_NS);
//close the trace file
sc_close_vcd_trace_file(tf);
return 0;}

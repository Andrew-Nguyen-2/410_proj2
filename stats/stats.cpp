/*
 * Stats.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 */

//TODO fill in content

#include "../includes/stats.h"

Stats::Stats(std::vector<PCB> &finished_vector): vec(&finished_vector), av_wait_time(0.0), av_turnaround_time(0.0), av_response_time(0.0){

}

//loops thru vec, prints 1 line for each process using the following format
//Process 1 Required CPU time:2  arrived:0 started:0 finished:2
//if there are 10 processes in vector, should print 10 lines
void Stats::showAllProcessInfo(){
	for (unsigned int i = 0; i < vec->size(); i++){
		PCB temp = (*vec)[i];
		int process = temp.process_number;
		int cpu = temp.required_cpu_time;
		int arrive = temp.arrival_time;
		int start = temp.start_time;
		int finish = temp.finish_time;
		std::cout << "Process " << process <<
				" Required CPU time:" << cpu << " arrived:" << arrive <<
				" started:" << start << " finished:" << finish << std::endl;
	}
}

//after a process is placed in the ready_q, how long does
//it take before its placed on the processor?
//response_time per process = start_time - arrival_time
//this function returns the average over all processes
float Stats::get_av_response_time(){
	float total;
	for (unsigned int i = 0; i < vec->size(); i++){
		int response_time = (*vec)[i].start_time - (*vec)[i].arrival_time;
		total += response_time;
	}
	return total / vec->size();
}

//after a process is placed in the ready_q, how long does
//it take to complete?
//turnaround time per process = finish_time - arrival_time
//this funtion returns the average over all processes
float Stats::get_av_turnaround_time(){
	float total;
	for (unsigned int i = 0; i < vec->size(); i++){
		int turnaround_time = (*vec)[i].finish_time - (*vec)[i].arrival_time;
		total += turnaround_time;
	}
	return total / vec->size();
}

//after a process is placed in the ready_q, how much time does it
//spend waiting for processor time?
//wait time per process = finish_time - arrival_time-required_CPU_time
//this funtion returns the average over all processes
float Stats::get_av_wait_time(){
	float total;
	for (unsigned int i = 0; i < vec->size(); i++){
		int wait_time = (*vec)[i].finish_time - (*vec)[i].arrival_time - (*vec)[i].required_cpu_time;
		total += wait_time;
	}
	return total / vec->size();
}



/*
 * Stats.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 */

//TODO fill in content

#include "../includes/stats.h"

Stats::Stats(std::vector<PCB> &finished_vector): vec(&finished_vector), av_wait_time(0), av_turnaround_time(0), av_response_time(0){
	calcStats();
}

//loops thru vec, prints 1 line for each process using the following format
//Process 1 Required CPU time:2  arrived:0 started:0 finished:2
//if there are 10 processes in vector, should print 10 lines
void Stats::showAllProcessInfo(){
	for (unsigned int i = 0; i < vec->size(); i++){
		int process = (*vec)[i].process_number;
		int cpu = (*vec)[i].required_cpu_time;
		int arrive = (*vec)[i].arrival_time;
		int start = (*vec)[i].start_time;
		int finish = (*vec)[i].finish_time;
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
	return av_response_time;
}

//after a process is placed in the ready_q, how long does
//it take to complete?
//turnaround time per process = finish_time - arrival_time
//this funtion returns the average over all processes
float Stats::get_av_turnaround_time(){
	return av_turnaround_time;
}

//after a process is placed in the ready_q, how much time does it
//spend waiting for processor time?
//wait time per process = finish_time - arrival_time-required_CPU_time
//this funtion returns the average over all processes
float Stats::get_av_wait_time(){
	return av_wait_time;
}

void Stats::calcStats(){
	float start_time = 0.0;
	float arrival_time = 0.0;
	float finish_time = 0.0;
	float cpu_time = 0.0;

	for (unsigned int i = 0; i < vec->size(); i++){
		start_time += (*vec)[i].start_time;
		arrival_time += (*vec)[i].arrival_time;
		finish_time += (*vec)[i].finish_time;
		cpu_time += (*vec)[i].required_cpu_time;
	}

	float wait = finish_time - arrival_time - cpu_time;
	float turnaround = finish_time - arrival_time;
	float response = start_time - arrival_time;

	av_wait_time = wait / vec->size();
	av_turnaround_time = turnaround / vec->size();
	av_response_time = response / vec->size();
}



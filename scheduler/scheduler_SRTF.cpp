/*
 * SchedulerSRTF.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 *
 *      implements shortest remaining time first scheduling algorithm
 *     pre-emptive
 */

//TODO fill in content
#include <algorithm>
#include "../includes/scheduler_SRTF.h"

//override base class behaviour if necessary, otherwise call it
bool Scheduler_SRTF::time_to_switch_processes(int tick_count, PCB &p){
	sort();
	return Scheduler::time_to_switch_processes(tick_count, p);
}

// helper function used to sort the vector by remaining_cpu_time
// in ascending order (low to high)
bool sort_CPU(const PCB &a, const PCB &b){
	return a.remaining_cpu_time < b.remaining_cpu_time;
}

//SRTF-preemptive - sort ready_q by remaining_cpu_time whenever add(PCB p)
//or time_to_switch_processes is called
void Scheduler_SRTF::sort(){
	std::vector<PCB> sorted;
	while (!ready_q->empty()){
		sorted.push_back(ready_q->front());
		ready_q->pop();
	}
	std::sort(sorted.begin(), sorted.end(), sort_CPU);

	for (unsigned int i = 0; i < sorted.size(); i++){
		ready_q->push(sorted[i]);
	}
}

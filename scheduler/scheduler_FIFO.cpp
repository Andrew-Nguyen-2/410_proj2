/*
 * SchedulerSTRR.cpp
 *
 *  Created on: Sep 7, 2019
 *      Author: keith
 *
 *      implements FIFO scheduling algorithm
 *      not pre-emptive
 */

//TODO fill in content

#include "../includes/scheduler_FIFO.h"

//override base class behaviour if necessary, otherwise call it
bool Scheduler_FIFO::time_to_switch_processes(int tick_count, PCB &p){
	if (p.remaining_cpu_time <= 0){
		return true;
	}
	return false;
}

//FIFO - not preemptive - no sorting needed
void Scheduler_FIFO::sort(){
}

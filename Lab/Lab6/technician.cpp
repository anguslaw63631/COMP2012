#include <iostream>
#include "technician.h"
#include "computer.h"
#include "electronics.h"

const int MAX_NUM_TECHNICIAN = 10;

// TODO: initialize the static varibles of class Technician
Technician* Technician::technician_list[MAX_NUM_TECHNICIAN] = {nullptr};
int Technician::num_technician = 0;
// TODO: Implement the constructor
Technician::Technician(std::string name, Diagnosis_Tool* diagnosis_tool){
    this->name = name;
    num_order_finished = 0 ;
    this->diagnosis_tool = diagnosis_tool;
    technician_list[num_technician] = this;
    ++num_technician;
}

Technician::~Technician(){
    delete diagnosis_tool;
}

CPU* Technician::acquire_CPU(CPU_Model model) const {
    return new CPU(model);
}

MEM* Technician::acquire_MEM(MEM_Model model) const {
    return new MEM(model);
}

// TODO: implement repair function
void Technician::repair(Computer* computer){
    bool cpuNeedRepair = diagnosis_tool->diagnose(computer->cpu);
    bool memNeedRepair = diagnosis_tool->diagnose(computer->mem);

    if(!cpuNeedRepair){
        //std::cout<<"cpu!"<<std::endl;
        CPU* tempCPU = acquire_CPU(diagnosis_tool->get_CPU_Model(computer->cpu));
        delete computer->cpu;
        computer->cpu = tempCPU;
        ++CPU::defect_count;
        //CPU::manufacture_count++;
        computer->cpu->healthy = true;
    }

    if(!memNeedRepair){
        //std::cout<<"mem!"<<std::endl;
        MEM* tempMEM = acquire_MEM(diagnosis_tool->get_MEM_Model(computer->mem));
        delete computer->mem;
        computer->mem = tempMEM;
        ++MEM::defect_count;
        //++MEM::manufacture_count;
        computer->mem->healthy = true;
    }
    num_order_finished++;
}

void Technician::print_report(){
    std::cout << "----------------------" << std::endl;
    std::cout << "REPORT FOR TECHNICIANS" << std::endl;
    std::cout << "----------------------" << std::endl;
    std::cout.width(20);
    std::cout << std::left << "NAME" << "ORDERS_COMPLETED" << std::endl;
    for(int i = 0; i < num_technician; ++i){
        std::cout.width(20);
        std::cout << std::left << technician_list[i]->name << technician_list[i]->num_order_finished << std::endl;
    }
}

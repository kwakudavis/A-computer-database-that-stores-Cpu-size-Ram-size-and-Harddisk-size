#include "Computer.h"


Computer::Computer(unsigned int cpuSpeed , unsigned int ramSize , unsigned int harddiskSize ) {

	Cpu.setSpeed(cpuSpeed);
	Ram.setRamSize(ramSize);
	Harddisk.setHarddiskSize(harddiskSize);

}

void Computer::display() {
	std::cout << Cpu.getSpeed() << " ";
	std::cout << Ram.getRamSize() << " ";
	std::cout << Harddisk.getHarddiskSize() <<endl;


}


bool Computer::save(ostream& outputStream) {
	bool status = false;
	
	
	
	if (outputStream) {

		outputStream << Cpu.getSpeed()<<" ";
		outputStream << Ram.getRamSize()<<" ";
		outputStream << Harddisk.getHarddiskSize()<<endl;

	 status = true;
	 }
	 return status;
	
}


bool Computer::load(istream& inputStream) {
bool	state = false;
	
		std::string computer_line;

		
		getline(inputStream, computer_line);  //get line
		
		if (computer_line != "") {
			

			//Loading lines 

			int lineLength = computer_line.length();

			//split line 
			//Get Cpu speed
			int start = 0;
			int found = computer_line.find(' ');
			string value;
			int set;


			value = computer_line.substr(start, found);
			set = stoi(value);
			Cpu.setSpeed(set);


			//Get Ram size
			start = found + 1;
			computer_line = computer_line.substr(0, lineLength);
			found = computer_line.find(' ');
			value = computer_line.substr(start, found);
			set = stoi(value);
			Ram.setRamSize(set);

			//Get Harddisk size

			value = computer_line.substr(found + 1, lineLength);
			set = stoi(value);
			Harddisk.setHarddiskSize(set);
			state = true;

		}
	return state;

}

// Question1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Computer.h";

bool list();
bool add();
int menu();

int main()
{


	/**
	Computer Hp;

	Hp.display();

	std::filebuf fb, fb1;
	fb.open(FILENAME, std::ios::out);//connecting output stream buffer to file

	std::ostream  outputstream(&fb);


	if (Hp.save(outputstream) == true) {

		std::cout << "file has been written successfully" << endl;
		fb.close();
	}
	**/
	/**
	fb1.open(FILENAME, std::ios::in); //connecting input file buffer to file
	std::istream inputstream(&fb1);  //creating an input file stream
	if (Hp.load(inputstream) == true) {

		std::cout << "file has been read successfully" << endl;
		fb1.close();
	}
	**/




	while (true) {
		switch (menu())
		{
		case 1:

			if (add() == true) {  //adding a new computer test 
				std::cout << "Computer has been added successfully" << endl;

			}
			break;

		case 2:

			list();
			break;
		case 3:
			exit(EXIT_FAILURE);

		
		default:
			std::cout << "enter a valid input";
			break;
		}

	}



}


bool add() {//A function that adds new computer records to the existing computer database
	//open file 
	int speed;
	int ram_size;
	int harddisk_size;

	std::cout << "Enter computer speed"<<endl;
	std::cin >> speed;

	std::cout << "Enter Ram size" << endl;
	std::cin >> ram_size;

	std::cout << "Enter Harddisk size" << endl;
	std::cin >> harddisk_size;

	Computer new_computer(speed,ram_size,harddisk_size);

	std::filebuf fb;
	fb.open(FILENAME, std::ios::app);
	std::ostream  outputstream(&fb);

	if (new_computer.save(outputstream)) {
	
		return true;
	}
	else {
	
		return false;
	}


}


bool list() {//A function that displays all the computers in the database
	Computer computer_load_object;

	std::filebuf fb;
	fb.open(FILENAME, std::ios::in);
	std::istream  inputstream(&fb);


	while (!inputstream.eof()){
	
		computer_load_object.load(inputstream);
		computer_load_object.display();
	
	}

	return true;
}

int menu() {
	int state;

	std::cout << "1.Add a new computer to the database" << endl;
	std::cout << "2.List all computers in the database." << endl;
	std::cout << "3.Exit" << endl;
	std::cout << "Enter choice: _" << endl;
	std::cin >> state;

	return state;
}





// Run program: Ctrl + 5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

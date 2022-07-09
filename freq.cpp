#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>

#define GLYPH ""
#define DELIMITER ":"
#define FILE_PATH "/proc/cpuinfo"


using namespace std;

void get() {
	
	ifstream inputFileStream(FILE_PATH); //Opening a filestream

	int count = 0,	//|Declaring vars that wiil containg the raw sum of Hz from all cpu cores 
	    sum = 0;	//|

	string temp; //A temporary buffer for a loop that will read and process the file

	while (getline (inputFileStream, temp)) { //Reading the file line by line
		
		string token = temp.substr(0, temp.find(DELIMITER));	//|Separating a token at the beggining of each line
		if (token == "cpu MHz		"){			//|and determining if it is the line that we need in our case
			
			string Hz = temp.substr(11, 4); //Getting the frequency itself
			double hz = stoi(Hz); //Converting a number (e.g. 1234) in string variable to an integer
			
			cout << "Core " << count << " is " << hz / 1000 << " GHz" << endl;

			sum = sum + hz; //Summing all the hz in cores
			count++; //Counting the amount of cores
		}

	}

	inputFileStream.close(); //Closing filestream

	double averageHz = sum / count;
	cout << "The average frequency among the cores is " << averageHz / 1000 << "GHz" << endl; 

}

int main() {

	while(true) {
		
		using namespace std::this_thread;
		using namespace std::chrono;
		get();
		sleep_for(nanoseconds(10));
		sleep_until(system_clock::now() + seconds(1));	

	}
	return 0;

}

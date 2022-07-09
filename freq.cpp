#include <iostream>
#include <fstream>

#define GLYPH ""
#define DELIMITER ":"

using namespace std;

int main() {
	
	string file,
	       temp;

	ifstream inputFileStream("/proc/cpuinfo");

	int count = 0, 
	    sum = 0;

	while (getline (inputFileStream, temp)) {
		
		file = file + "\n" + temp;

		string token = temp.substr(0, temp.find(DELIMITER));
		if (token == "cpu MHz		"){
			
			string Hz = temp.substr(11, 4);
			int hz = stoi(Hz);

			sum = sum + hz;
			count++;
		}

	}

	inputFileStream.close(); 

	cout << "sum is " << sum << endl;
	cout << "count is " << count << endl;

	int averageHz = (sum / count);

	cout << "The average frequency among the cores is " << averageHz / 1000 << "Hz" << endl; 

	return(0);

}

#include <iostream>
#include <fstream>

#define GLYPH ""

using namespace std;

int main() {
	
	string file, temp;
	string delimiter = ":";
	ifstream inputFileStream("/proc/cpuinfo");



	int count = 0, 
	    sum = 0;

	while (getline (inputFileStream, temp)) {
		
		file = file + "\n" + temp;

		string token = temp.substr(0, temp.find(delimiter));
		if (token == "cpu MHz		"){
			
			string Hz = temp.substr(11, 4);
			int hz = stoi(Hz);

			sum = sum + hz;
			count++;
		}

	}

	inputFileStream.close(); 

	int averageHz = sum / count;

	cout << GLYPH << " " << averageHz << endl; 

	return(0);

}

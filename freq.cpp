#include <iostream>
#include <fstream>

using namespace std;

int main() {
	
	string file, temp;
	string delimiter = ":";
	ifstream inputFileStream("/proc/cpuinfo");
	
	while (getline (inputFileStream, temp)) {
		
		file = file + "\n" + temp;

		string token = temp.substr(0, temp.find(delimiter));
		if (token == "cpu MHz		"){
			
			cout << token << endl;

		}

	}
	
	inputFileStream.close(); 

//	cout << file << endl;

	return(0);

}

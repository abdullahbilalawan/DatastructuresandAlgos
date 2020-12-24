#include "Module.h"
#include "Student.h"
#include "map"


Student::Student(const string& uid) {

    this->uid=uid;// uid member added in the header file

    //assign the year

    this->year = this->uid.at(2);
    //as given  in probelm 3rd index is year
}

// add module with one necessary check and other are in specific subclasses
bool Student::addModule(string moduleCode, float mark) {
    /**
     * see student.h
     * implemented in parent class
     * because generic for all
     */
    // if code exist in MCT
    if(MCT.find(moduleCode)==MCT.end()){

        return false;
    }
    // if code has a year tht is against the student degree
    if(moduleCode.at(2) != this->year){
        return false;
    }

    //check max credit for each year

    switch (moduleCode.at(2)) {

        case 2 || 3:
            if(mark>120){
                return false;
            }
            break;
        case 7:
            if(mark>180){
                return false;
            }
            break;

        case default:
            break;




    }
    //check max no of modules
    if(modules.size()>19){
        return false;
    }
    else {
        modules.emplace({moduleCode, mark});

        return true;
    }
}

bool Student::updateMark(string moduleCode, float mark) {

    /**
     * implemented in parent class because generic for all
     *
     *
     */


    //if the module is not added
    if(modules.empty()){
        return false
    }



    //finding the current module if it is already there

    // if not found

    if(modules.find(moduleCode) == modules.end()){
        return false;
    }



    if(MCT.find(moduleCode) == MCT.end()) {
        return false;
    }

    //updating the value

    else {

        modules.insert({moduleCode, mark});

        return true;

    }
}

float Student::cwa() const {
	// virtual function ->abstract
	return 0.0;
}

string Student::calcDegClass() const {
	// virtual function -> abstract
	return "DUMMY STRING";
}

istream& operator>>(istream& is, Student& student) {
	// input stream
	string mod_code,mark; //reading combined (line) first from getline then breaking




	string line="N";

	while (!line.empty() ){ //reading all the lines till empty
	    getline(is,line); // put stream line in line string


	}

	//break the line into code and marks by " "space

	mod_code = line.substr(0,5); //using string substring method
	mark = line.substr(7,8);

	//now add module
	if( Student::addModule(mod_code, mark)) {
	    //added
	} else{
	    //nothing
	}



	return is;
}

ostream& operator<<(ostream& os, const Student& student) {
	// Output stream

	os<< student.uid << "\t"<< student.calcDegClass();
	return os;
}


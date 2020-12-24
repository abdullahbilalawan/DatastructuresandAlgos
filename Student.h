#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
#include <string>
#include <list>
#include <map>
using std::istream;
using std::ostream;
using std::string;
using std::list;

const int MAX_MODULES = 20; // should you need to use something like this
const int BSC_YEAR_CREDIT = 120;
const int MSC_YEAR_CREDIT = 180;

class Student {  // class declared abstract here as no Student Object is formed
public:





	//==default constructor removed

	// Constructor, with student's userid as argument
	Student(const string& uid);

	// If you need non-default versions of destructors, copy constructors
	// etc. please define yourself. Here I assume the default versions
	// are ok. You will not be tested on copy constructing/assigning.

	// Add this module to the student, with the given mark.
	// If moduleCode does not exist in the MCT table,
	// or if the module is of the wrong year group for this student,
	// or if the student already have this module,
	// or if adding this module exceeds the total credits of this year,
	// do nothing and return false. Otherwise return true.
	bool addModule(string moduleCode, float mark);


	/**
	  total credits of year are
	 dependent on student type are checked in other than Student.cpp
	 */

	// Update the mark of this module.
	// If moduleCode does not appear in the MCT table,
	// or if the student have not already added this module,
	// do nothing and return false. Otherwise return true.
	bool updateMark(string moduleCode, float mark);

	/**
	 * this function can be implemented in the parent class
	 * as we have to update the current mark
	 * @return
	 */



	// Returns the CWA of the student taking all the modules added so
	// far into account.
	// For BSc students it is a weighted average of Y2 and Y3 CWAs.
	// For MSc students it is a weighted average of all modules.
	// It should still calculate even if not a whole year worth of
	// modules have been added.
	// If no modules have been added so far, return 0.
	virtual float cwa() const;
	/*
	 * no need to add implementation in student class as cwa is subclass specific
	 */

	// Returns a string which is one of the degree classification
	// results (see webpage for details).
	// If insufficient credits have been entered, return
	// "INSUFFICIENT CREDITS".
	virtual string calcDegClass() const;

	// add any protected/private member variables


    //addition of class members
protected:

    string uid;
    string year;



    //a map to store  student modules and their marks
    std::map <string,float> modules;


public:
    // The input stream operator, that reads module code and marks from the
	// input stream and add it to the student as done by addModule().
	// In situations where addModule() would have returned false, do not add
	// and quietly move on to the next module.
	friend istream& operator>>(istream& is, Student& student);

	// The output stream operator, printing uid and degree class info
	// of the student as specified in the webpage.
	friend ostream& operator<<(ostream& os, const Student& student);
};

class BScStudent : public Student {
public:


	BScStudent(const string& uid);

	// CWA for Y2 and Y3 respectively.
	// Same rules as Student::cwa() regarding not having a whole year's
	// worth of modules applies here.
	virtual float y2cwa() const;
	virtual float y3cwa() const;


	// you may need to override some functions in the base class
	virtual float cwa() const override;

	// add any protected/private member variables
    //variables required because of Y2 and Y3 as maps to store modules
    std::map <string,float> modules_y2;
    std::map <string,float> modules_y3;

	// ---no members required here

};

class BScStudentOld : public BScStudent {
public:
	BScStudentOld(const string& uid);

	// DONE: you may need to override some functions in the base class

    float y2cwa() const ;
    float y3cwa() const ;
    float cwa() const override;
    string calcDegClass() const override;


	// DONE: add any protected/private member variables


	//variables required because of Y2 and Y3 as maps to store modules
    std::map <string,float> modules_y2;
    std::map <string,float> modules_y3;


    //concatenate them to modules for other functions such as add_module
    void concatenate_y2_y3();

    float fail_credits();
    bool  credit_check();






};

class BScStudentNew : public BScStudent {
public:
	BScStudentNew(const string& uid);

    // DONE: you may need to override some functions in the base class

    float y2cwa() const ;
    float y3cwa() const ;
    float cwa() const override;
    string calcDegClass() const override;
	// DONE: add any protected/private member variables


    //variables required because of Y2 and Y3 as maps to store modules
    std::map <string,float> modules_y2;
    std::map <string,float> modules_y3;


    //concatenate them to modules for other functions such as add_module
    void concatenate_y2_y3();
    float fail_credits();
    bool  credit_check();
};

class MScStudent : public Student {
public:
	MScStudent(const string& uid);

	// DONE: you may need to override some functions in the base class

    float cwa() const override;
    string calcDegClass() const override;

	// DONE: add any protected/private member variables

	float total_credits();




};

#endif

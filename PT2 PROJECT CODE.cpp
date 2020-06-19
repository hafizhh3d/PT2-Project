#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

	//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
	//															  //
	//				CLASS HEADER AND IMPLEMENTATION				  //
	//															  //
	//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//


//============================================================//
//			      Abstract Parent Class Person				  //
//															  //
// Class Relation : Lecturer, Student, Staff 				  //
// Relationship : Inheritance, Polymorphism			  		  //
// 															  //
// This class will be the base and parent class for Person    //
// related class											  //
//============================================================//

class Person
{
	protected :
		string name; // Variable for Person Name
	public :
		Person(string name = "") // Default Constructor for Person Class
		{
			this->name = name;
		}
		void setName(string name) // Mutator for Person Name
		{
			this->name = name;
		}
		string getName() // Accessor for Person Name
		{
			return name;
		}
		virtual void showInfo() = 0; // Dynamic Binding for Polymorphism and Pure Virtual Methods
};

//============================================================//
//			      Abstract Parent Class Residence			  //
//															  //
// Class Relation : UTM, Outside			 				  //
// Relationship : Inheritance, Polymorphism			  		  //
// 															  //
// This class will be the base and parent class for Residence //
// related class											  //
//============================================================//

class Residence
{
	protected :
		string country; // Variable for Residence Country
		string state; // Variable for Residence State
	public :
		Residence(string country = "", string state = "") // Default Constructor for Residence Class
		{
			this->country = country;
			this->state = state;
		}
		void setCountry(string country) // Mutator for Residence Country
		{
			this->country = country;
		}
		void setState(string state) // Mutator for Residence State
		{
			this->state = state;
		}
		string getCountry() // Accessor for Residence Country
		{
			return country;
		}
		string getState() // Accessor for Residence State
		{
			return state;
		}
		virtual void dispInfo() = 0; // Dynamic Binding for Polymorphism and Pure Virtual Methods
};

//============================================================//
//			      		Class Course				   		  //
//															  //
// Class Relation : Lecturer, Student						  //
// Relationship : Composition								  //
//  														  //
// This class store the Course name and code for the person.  //
// This class will have a composition realtionship with		  //
// Lecturer and Student Class 								  //
//============================================================//

class Course
{
	private :
		string name; // Variable for Course Name
		string code; // Variable for Course Code
	public :
		Course(string name = "", string code = "") // Default Constructor for Course Class
		{
			this->name = name;
			this->code = code;
		}
		void setName(string name) // Mutator for Course Name
		{
			this->name = name;
		}
		void setCode(string code) // Mutator for Course Code
		{
			this->code = code;
		}
		string getName() // Accessor for Course Name
		{
			return name;
		}
		string getCode() // Accessor for Course Code
		{
			return code;
		}
};

//============================================================//
//			      		Class Department			   		  //
//															  //
// Class Relation : Staff									  //
// Relationship : Composition								  //
//  														  //
// This class store the Department name for the Staff.  	  //
// This class will have a composition realtionship with		  //
// Staff Class 												  //
//============================================================//

class Department
{
	private :
		string name; // Variable for Department Name
	public :
		Department(string name = "") // Default Constructor for Department Name
		{
			this->name = name;
		}
		void setName(string name) // Mutator for Department Name
		{
			this->name = name; 
		}
		string getName() // Accessor for Department Name
		{
			return name;
		}
};

//============================================================//
//			      		Class UTM					   		  //
//															  //
// Class Relation : Residence								  //
// Relationship : Polymorphism, Inheritance					  //
//															  //
// Class Realtion : Lecturer, Student, Staff				  //
// Realtionship : Aggregation								  // 
//  														  //
// This class store the UTM Address for Person Class.	  	  //
// This class will have a aggregation realtionship with		  //
// Person Class, so it can be exist or not depending on where //
// the person live.											  //
//============================================================//

class UTM : public Residence // Inheritance from Residence Class
{
	private :
		string kolej; // Variable for UTM Kolej
		string block; // Variable for UTM Block
	public :
		UTM(string kolej = "", string block = "") // Default Constructor for UTM Class
		{
			this->kolej = kolej;
			this->block = block;
		}
		void setKolej(string kolej) // Mutator for UTM Kolej
		{
			this->kolej = kolej;
		}
		void setBlock(string block) // Mutator for UTM Block
		{
			this->block = block;
		}
		string getKolej() // Accessor for UTM Kolej
		{
			return kolej;
		}
		string getBlock() // Accessor for UTM Block
		{
			return block;
		}
		void dispInfo() // Overriden Function from Base Class Residence
		{
			cout << left << setw(10) << "Kolej" << ": "<< kolej << endl;
			cout << setw(10) << "Block" << ": " << block << endl;
		}
};

//============================================================//
//			      		Class Outside				   		  //
//															  //
// Class Relation : Residence								  //
// Relationship : Polymorphism, Inheritance					  //
//															  //
// Class Relation : Lecturer, Student, Staff				  //
// Realtionship : Aggregation								  // 
//  														  //
// This class store the Outside Address for Person Class.  	  //
// This class will have a aggregation realtionship with		  //
// Person Class, so it can be exist or not depending on where //
// the person live.											  //
//============================================================//

class Outside : public Residence // Inheritance from Residence Class
{
	protected :
		string address; // Variable for Outside Addrress
		string city; // Variable for Outside City
	public :
		Outside(string address = "", string city = "") // Default Constructor for Outside Class
		{
			this->address = address;
			this->city = city;
		}
		void setAddres(string address) // Mutator for Outside Address
		{
			this->address = address;
		}
		void setCity(string city) // Mutator for Outside City
		{
			this->city = city;
		}
		string getAddress() // Accessor for Outside Address
		{
			return address;
		}
		string getCity() // Accessor for Outside City
		{
			return city;
		}
		void dispInfo() // Overriden Function from Base Class Residence
		{
			cout << left << setw(10) << "City" << ": " << city << endl;
			cout << setw(10) << "Address" << ": " << address << endl;
		}
};

//============================================================//
//			      		Class Lecturer				   		  //
//															  //
// Class Relation : Person									  //
// Relationship : Polymorphism, Inheritance					  //
//															  //
// Class Relation : Course									  //
// Relationship : Composition								  //
//															  //
// Class Relation : UTM, Outside							  //
// Realtionship : Aggregation								  // 
//  														  //
// This class store the Lecturer data.  					  //
// The base class came from Person.							  //
// This class have a composition relationship with Course 	  //
// Class because they must have a Course sign in to. 		  //
// This class will have a aggregation relationship with		  //
// UTM and Outside, so it can be exist or not depending on    //
// where the person live.									  //
//============================================================//

class Lecturer : public Person // Inheritance from Person Class
{
	private :
		Course course; // Variable for Lecturer Course
		UTM *kolej; // Pointer Variable for Lecturer UTM Adrress
		Outside *address; // Pointer Variable for Lecturer Outside UTM Adrress
	public :
		Lecturer (string name = "", string courseName = "", string courseCode = "", UTM *kolejUTM = NULL, Outside *addressNonUTM = NULL) : course(courseName, courseCode) // Default Constructor for Lecturer Class with Compositition
		{
			this->name = name;
			this->kolej = kolejUTM;
			this->address = addressNonUTM;
		}
		void setCourseName(string courseName) // Mutator for Lecturer Course Name
		{
			course.setName(courseName);
		}
		void setCourseCode(string courseCode) // Mutator for Lecturer Course Code
		{
			course.setCode(courseCode);
		}
		void setUTMCountry(string country) // Mutator for Lecturer UTM Country
		{
			this->kolej->setCountry(country);
		}
		void setUTMState(string state) // Mutator for Lecturer UTM State
		{
			this->kolej->setState(state);
		}
		void setUTMKolej(string kolej) // Mutator for Lecturer UTM Kolej
		{
			this->kolej->setKolej(kolej);
		}
		void setUTMBlock(string block) // Mutator for Lecturer UTM Block
		{
			this->kolej->setBlock(block);
		}
		void setOutsideCountry(string country) // Mutator for Lecturer Outside Country
		{
			this->address->setCountry(country);
		}
		void setOutsideState(string state) // Mutator for Lecturer Outside State
		{
			this->address->setState(state);
		}
		void setOutsideAddress(string address) // Mutator for Lecturer Outside Address
		{
			this->address->setAddres(address);
		}
		void setOutsideCity(string city) // Mutator for Lecturer Outside City
		{
			this->address->setCity(city);
		}
		string getCourseName() // Accessor for Lecturer Course Name
		{
			return course.getName();
		}
		string getCourseCode() // Accessor for Lecturer Course Code
		{
			return course.getCode();
		}
		string getUTMCountry() // Accessor for Lecturer UTM Country
		{
			return kolej->getCountry();
		}
		string getUTMState() // Accessor for Lecturer UTM State
		{
			return kolej->getState();
		}
		string getUTMKolej() // Accessor for Lecturer UTM Kolej
		{
			return kolej->getKolej();
		}
		string getUTMBlock() // Accessor for Lecturer UTM Block
		{
			return kolej->getBlock();
		}
		string getOutsideCountry() // Accessor for Lecturer Outside Country
		{
			return address->getCountry();
		}
		string getOutsideState() // Accessor for Lecturer Outside State
		{
			return address->getState();
		}
		string getOutsideAddress() // Accessor for Lecturer Outside Address
		{
			return address->getAddress();
		}
		string getOutsideCity() // Accessor for Lecturer Outside City
		{
			return address->getCity();
		}
		void showInfo() // Overriden Function from Base Class Person
		{
			cout << left << setw(20) << "Name" << ": " << name << endl;
			cout << setw(20) << "Course" << ": " << course.getName() << endl;
			cout << setw(20) << "Course Code" << ": " << course.getCode() << endl;
			
			if (kolej == NULL)
			{
				cout << setw(20) << "Country" << ": " << address->getCountry() << endl;
				cout << setw(20) << "State" << ": " << address->getState() << endl;
				cout << setw(20) << "City" << ": " << address->getCity() << endl;
				cout << setw(20) << "Address" << ": " << address->getAddress() << endl;
			}
			else
			{
				cout << setw(20) << "Country" << ": " << kolej->getCountry() << endl;
				cout << setw(20) << "State" << ": " << kolej->getState() << endl;
				cout << setw(20) << "Kolej" << ": " << kolej->getKolej() << endl;
				cout << setw(20) << "Block" << ": " << kolej->getBlock() << endl;
			}
		}
};


//============================================================//
//			      		Class Student				   		  //
//															  //
// Class Relation : Person									  //
// Relationship : Polymorphism, Inheritance					  //
//															  //
// Class Relation : Course									  //
// Relationship : Composition								  //
//															  //
// Class Relation : UTM, Outside							  //
// Realtionship : Aggregation								  // 
//  														  //
// This class store the Student data.  		     			  //
// The base class came from Person.							  //
// This class have a composition relationship with Course 	  //
// Class because they must have a Course sign in to. 		  //
// This class will have a aggregation relationship with		  //
// UTM and Outside, so it can be exist or not depending on    //
// where the person live.									  //
//============================================================//

class Student : public Person // Inheritance from Person Class
{
	private :
		string metric; // Variable for Student Metric ID
		Course course; // Variable for Student Course
		UTM *kolej; // Pointer Variable for Student UTM Address
		Outside *address; // Pointer Variable for Student Outside UTM Address
	public :  
		Student (string metric = "", string name = "", string courseName = "", string courseCode = "", UTM *kolejUTM = NULL, Outside *addressNonUTM = NULL) : course(courseName, courseCode) // Default Constructor for Student Class with Compositition
		{
			this->name = name;
			this->metric = metric;
			this->kolej = kolejUTM;
			this->address = addressNonUTM;
		}
		void setMetric(string metric) // Mutator for Student Metric ID
		{
			this->metric = metric;
		}
		void setCourseName(string courseName) // Mutator for Student Course Name
		{
			course.setName(courseName);
		}
		void setCourseCode(string courseCode) // Mutator for Student Course Code
		{
			course.setCode(courseCode);
		}
		void setUTMCountry(string country) // Mutator for Student UTM Country
		{
			this->kolej->setCountry(country);
		}
		void setUTMState(string state) // Mutator for Student UTM State
		{
			this->kolej->setState(state);
		}
		void setUTMKolej(string kolej) // Mutator for Student UTM Kolej
		{
			this->kolej->setKolej(kolej);
		}
		void setUTMBlock(string block) // Mutator for Student UTM Block
		{
			this->kolej->setBlock(block);
		}
		void setOutsideCountry(string country) // Mutator for Student Outside Country
		{
			this->address->setCountry(country);
		}
		void setOutsideState(string state) // Mutator for Student Outside State
		{
			this->address->setState(state);
		}
		void setOutsideAddress(string address) // Mutator for Student Outside Address
		{
			this->address->setAddres(address);
		}
		void setOutsideCity(string city) // Mutator for Student Outside City
		{
			this->address->setCity(city);
		}
		string getMetric() // Accessor for Student Metric ID
		{
			return metric;
		}
		string getCourseName() // Accessor for Student Course Name
		{
			return course.getName();
		}
		string getCourseCode() // Accessor for Student Course Code
		{
			return course.getCode();
		}
		string getUTMCountry() // Accessor for Student UTM Country
		{
			return kolej->getCountry();
		}
		string getUTMState() // Accessor for Student UTM State
		{
			return kolej->getState();
		}
		string getUTMKolej() // Accessor for Student UTM Kolej
		{
			return kolej->getKolej();
		}
		string getUTMBlock() // Accessor for Student UTM Block
		{
			return kolej->getBlock();
		}
		string getOutsideCountry() // Accessor for Student Outside Country
		{
			return address->getCountry();
		}
		string getOutsideState() // Accessor for Student Outside State
		{
			return address->getState();
		}
		string getOutsideAddress() // Accessor for Student Outside Address
		{
			return address->getAddress();
		}
		string getOutsideCity() // Accessor for Student Outside City
		{
			return address->getCity();
		}
		void showInfo() // Overriden Function from Base Class Person
		{
			cout << left << setw(20) << "Name" << ": " << name << endl;
			cout << setw(20) << "Metric ID" << ":" << metric << endl;
			cout << setw(20) << "Course" << ": " << course.getName() << endl;
			cout << setw(20) << "Course Code" << ": " << course.getCode() << endl;
			
			if (kolej == NULL)
			{
				cout << setw(20) << "Country" << ": " << address->getCountry() << endl;
				cout << setw(20) << "State" << ": " << address->getState() << endl;
				cout << setw(20) << "City" << ": " << address->getCity() << endl;
				cout << setw(20) << "Address" << ": " << address->getAddress() << endl;
			}
			else
			{
				cout << setw(20) << "Country" << ": " << kolej->getCountry() << endl;
				cout << setw(20) << "State" << ": " << kolej->getState() << endl;
				cout << setw(20) << "Kolej" << ": " << kolej->getKolej() << endl;
				cout << setw(20) << "Block" << ": " << kolej->getBlock() << endl;
			}
		}
};


//============================================================//
//			      		Class Staff 				   		  //
//															  //
// Class Relation : Person									  //
// Relationship : Polymorphism, Inheritance					  //
//															  //
// Class Relation : Department								  //
// Relationship : Composition  								  //
//															  //
// Class Relation : UTM, Outside							  //
// Realtionship : Aggregation								  // 
//  														  //
// This class store the Staff data.  	    				  //
// The base class came from Person.							  //
// This class will have a aggregation relationship with		  //
// UTM and Outside, so it can be exist or not depending on    //
// where the person live.									  //
//============================================================//

class Staff : public Person // Inheritance from Person Class
{
	private :
		Department department; // Variable for Staff Department
		UTM *kolej; // Pointer Variable for Staff UTM Address
		Outside *address; // Pointer Variable for Staff Outside UTM Address
	public :
		Staff (string name = "", string departmentName = "", UTM *kolejUTM = NULL, Outside *addressNonUTM = NULL) : department(departmentName) // Default Constructor for Staff Class
		{
			this->name = name;
			this->kolej = kolejUTM;
			this->address = addressNonUTM;
		}
		void setDepartment(string department) // Mutator for Staff Department
		{
			this->department.setName(department);
		}
		void setUTMCountry(string country) // Mutator for Staff UTM Country
		{
			this->kolej->setCountry(country);
		}
		void setUTMState(string state) // Mutator for Staff UTM State
		{
			this->kolej->setState(state);
		}
		void setUTMKolej(string kolej) // Mutator for Staff UTM Kolej
		{
			this->kolej->setKolej(kolej);
		}
		void setUTMBlock(string block) // Mutator for Staff UTM Block
		{
			this->kolej->setBlock(block);
		}
		void setOutsideCountry(string country) // Mutator for Staff Outside Country
		{
			this->address->setCountry(country);
		}
		void setOutsideState(string state) // Mutator for Staff Outside State
		{
			this->address->setState(state);
		}
		void setOutsideAddress(string address) // Mutator for Staff Outside Address
		{
			this->address->setAddres(address);
		}
		void setOutsideCity(string city) // Mutator for Staff Outside City
		{
			this->address->setCity(city);
		}
		string getDepartment() // Accessor for Staff Department
		{
			return department.getName();
		}
		string getUTMCountry() // Accessor for Staff UTM Country
		{
			return kolej->getCountry();
		}
		string getUTMState() // Accessor for Staff UTM State
		{
			return kolej->getState();
		}
		string getUTMKolej() // Accessor for Staff UTM Kolej
		{
			return kolej->getKolej();
		}
		string getUTMBlock() // Accessor for Staff UTM Block
		{
			return kolej->getBlock();
		}
		string getOutsideCountry() // Accessor for Staff Outside Country
		{
			return address->getCountry();
		}
		string getOutsideState() // Accessor for Staff Outside State
		{
			return address->getState();
		}
		string getOutsideAddress() // Accessor for Staff Outside Address
		{
			return address->getAddress();
		}
		string getOutsideCity() // Accessor for Staff Outside City
		{
			return address->getCity();
		}
		void showInfo() // Overriden Function from Base Class Person
		{
			cout << left << setw(20) << "Name" << ": " << name << endl;
			cout << setw(20) << "Department" << ": " << department.getName() << endl;
			
			if (kolej == NULL)
			{
				cout << setw(20) << "Country" << ": " << address->getCountry() << endl;
				cout << setw(20) << "State" << ": " << address->getState() << endl;
				cout << setw(20) << "City" << ": " << address->getCity() << endl;
				cout << setw(20) << "Address" << ": " << address->getAddress() << endl;
			}
			else
			{
				cout << setw(20) << "Country" << ": " << kolej->getCountry() << endl;
				cout << setw(20) << "State" << ": " << kolej->getState() << endl;
				cout << setw(20) << "Kolej" << ": " << kolej->getKolej() << endl;
				cout << setw(20) << "Block" << ": " << kolej->getBlock() << endl;
			}
		}
};

	//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
	//															  //
	//					FUNCTION FOR MAIN						  //
	//															  //
	//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//


//============================================================//
//						menu()								  //
//					Input  = None							  //
//					Output = Display Menu					  //
//															  //
// This Function will display the menu for the user to choose //
//============================================================//

void menu () // Function to Show Menu
{
	cout << "===================" << endl;
	cout << "UTM STUDENT TRACKER" << endl;
	cout << "===================" << endl << endl;
	
	cout << "1. ADD DATA" << endl;
	cout << "2. DELETE DATA" << endl;
	cout << "3. DISPLAY DATA" << endl;
	cout << "4. EXIT PROGRAM" << endl;
	
	cout << endl << "Choose what you want to do : ";
}

//============================================================//
//						addUndergraduate()					  //
//					Input  = undergraduate, countUG			  //
//					Output = Adding New Input for UG		  //
//															  //
// This Function will add new entry for UG					  //
//============================================================//

void addUndergraduate(Student *&undergraduate, int &countUG)
{
	string name; // Temporary variable for Undergraduate Name
	string metric; // Temporary variable for Undergraduate Metric
	
	cout << endl << endl;
	cout << "--==--==--==--==--==--==--==--==--" << endl;
	cout << "Adding new Undergraduate Input" << endl;
	cout << "--==--==--==--==--==--==--==--==--" << endl << endl;
	cout << "Name : ";
	cin >> name;
	cout << "Metric : ";
	cin >> metric;
	
	try
	{
		if (undergraduate == 0)
		throw "Empty!";
		
		Student *temp;
		
		temp = new Student[countUG+1];
		
		for (int i = 0; i < countUG; i++)
		{
			temp[i] = undergraduate[i];
		}
		
		temp[countUG].setName(name);
		temp[countUG].setMetric(metric);
		
		delete [] undergraduate;
		
		countUG++;
		
		undergraduate = temp;
	}
	catch (const char *msg)
	{
		undergraduate= new Student[1];
		undergraduate[0].setName(name);
		undergraduate[0].setMetric(metric);
		countUG++;
	}
	
	/*
	if (undergraduate != 0) // IF it have been initialized
	{
		Student *temp;
		
		temp = new Student[countUG+1];
		
		for (int i = 0; i < countUG; i++)
		{
			temp[i] = undergraduate[i];
		}
		
		temp[countUG].setName(name);
		temp[countUG].setMetric(metric);
		
		delete [] undergraduate;
		
		countUG++;
		
		undergraduate = temp;
	}
	else // If it still empty
	{
		undergraduate= new Student[1];
		undergraduate[0].setName(name);
		undergraduate[0].setMetric(metric);
		countUG++;
	}
	*/
	
	return;
}
// addPostgraduate(){}
// addStaff(){}

// deleteUndergraduate(){}
// deletePostgraduate(){}
// deleteStaff(){}

void displayUndergraduate(Student *undergraduate, int countUG)
{
	try
	{
		if (countUG == 0)
		throw "There is no input!";
		
		cout << left << setw (5) << "No" << setw(15) << "Name" << setw(10) << "Metric" << endl;
		for (int i = 0; i < countUG; i++)
		{
			cout << left << setw (5) << i+1 << setw(15) << undergraduate[i].getName() << setw(10) << undergraduate[i].getMetric() << endl;
		}
	}
	catch (const char *msg)
	{
		cout << msg;
	}
	
	/*
	if (countUG == 0)
	{
		cout << "There is no input!" << endl;
		return;
	}
	else
	{
		cout << left << setw (5) << "No" << setw(15) << "Name" << setw(10) << "Metric" << endl;
		for (int i = 0; i < countUG; i++)
		{
			cout << left << setw (5) << i+1 << setw(15) << undergraduate[i].getName() << setw(10) << undergraduate[i].getMetric() << endl;
		}
	}
	*/
}
// displayPostgraduate(){}
// displayStaff(){}


int main ()
{
	int choice, choiceAdd, choiceDelete, choiceDisplay; // Variable for Choice
	
	Student *undergraduate = 0; // Pointer Variable for Undergraduate
	//Student *postgraduate; // Pointer Variable for Postgraduate
	//Lecturer *lecturer; // Pointer Variable for Lecturer
	//Staff *staff; // Pointer Variable for Staff
	
	int countUG = 0; // Counter for Undergraduate
	//int countPG = 0; // Counter for Postgraduate
	//int countLecturer = 0; // Counter for Lecturer
	//int countStaff = 0; // Counter for Staff
	
	//============================================================//
	//			This Do While Loop will always display			  //
	//			the Menu and ask the user to input what			  //
	//			they want to do									  //
	//============================================================//
	
	do
	{
		system("cls");
		menu();
		cin >> choice;
		cout << endl << endl;
		
		switch (choice)
		{
			
			//============================================================//
			//			Choice 1 = ADD DATA								  //
			// The Add Data will ask the user to input what data they	  //
			// want to add to a particular Object 						  //
			//============================================================//
			
			case 1 :
				cout <<"=-=-=-=-=-=-=-" << endl;
				cout << "ADD DATA" << endl;
				cout <<"=-=-=-=-=-=-=-" << endl << endl;
				
				cout << "1> ADD UNDERGRADUATE" << endl;
				cout << "2> ADD POSTGRADUATE" << endl;
				cout << "3> ADD STAFF" << endl;
				
				cout << endl << "Choose what data you want to Add :";
				cin >> choiceAdd;
				
				//============================================================//
				//		       			ChoiceAdd  							  //
				// The ChoiceAdd will determine which data to be added based  //
				// on the menu they chosen			 						  //
				//============================================================//
				
				switch (choiceAdd)
				{
					case 1 :
						//cout << "ADD UNDERGADUATESTUDENT DONE!!!" << endl;
						addUndergraduate(undergraduate, countUG); // Function to add Undergraduate Data
						// Function Object to add Undergraduate Student
						break;
					case 2 :
						cout << "ADD POSTGRADUATESTUDENT DONE!!!" << endl;
						// addPostgraduate();
						// Function Object to add Postgraduate Student
						break;
					case 3  :
						cout << "ADD STAFF DONE!!!" << endl;
						// addStaff();
						// Function Object to add Staff
						break;
					default :
						cout << "Input Not Recognized!!!!" << endl;
						break;
				}
				cout << endl;
				system("pause");
				break;
				
			//============================================================//
			//			Choice 2 = REMOVE DATA							  //
			// The Remove Data will ask the user to input what data they  //
			// want to remove from a particular Object 					  //
			//============================================================//
			
			case 2 :
				cout <<"=-=-=-=-=-=-=-" << endl;
				cout << "DELETE DATA" << endl << endl;
				cout <<"=-=-=-=-=-=-=-" << endl << endl;
				
				cout << "1> DELETE UNDERGRADUATE" << endl;
				cout << "2> DELETE POSTGRADUATE" << endl;
				cout << "3> DELETE STAFF" << endl;
				
				cout << endl << "Choose what data you want to Delete :";
				cin >> choiceDelete;
				
				//============================================================//
				//		       			ChoiceDelete						  //
				// The ChoiceDelete will determine which data to be deleted   //
				// based on the menu they chosen			 				  //
				//============================================================//
				
				switch (choiceDelete)
				{
					case 1 :
						cout << "DELETE UNDERGADUATESTUDENT DONE!!!" << endl;
						// deleteUndergraduate();
						// Function Object to delete Undergraduate Student
						break;
					case 2 :
						cout << "DELETE POSTGRADUATESTUDENT DONE!!!" << endl;
						// deletePostgraduate();
						// Function Object to delete Postgraduate Student
						break;
					case 3  :
						cout << "DELETE STAFF DONE!!!" << endl;
						// deleteStaff();
						// Function Object to delete Staff
						break;
					default :
						cout << "Input Not Recognized!!!!" << endl;
						break;
				}
				cout << endl;
				system("pause");
				break;
				
			//============================================================//
			//			Choice 3 = DISPLAY DATA							  //
			// The Display Data will show all of the data that is stored  //
			// in the computer						 					  //
			//============================================================//
			
			case 3 :
				cout <<"=-=-=-=-=-=-=-" << endl;
				cout << "DISPLAY DATA" << endl << endl;
				cout <<"=-=-=-=-=-=-=-" << endl << endl;
				
				cout << "1> DISPLAY UNDERGRADUATE" << endl;
				cout << "2> DISPLAY POSTGRADUATE" << endl;
				cout << "3> DISPLAY STAFF" << endl;
				
				cout << endl << "Choose what data you want to Display :";
				cin >> choiceDisplay;
				
				//============================================================//
				//		       			choiceDisplaly						  //
				// The choiceDisplaly will determine which data to be 	      //
				// displayed based on the menu they chosen			 		  //
				//============================================================//
				
				switch (choiceDisplay)
				{
					case 1 :
						//cout << "DISPLAY UNDERGADUATESTUDENT DONE!!!" << endl;
						displayUndergraduate(undergraduate, countUG);
						// Function Object to delete Undergraduate Student
						break;
					case 2 :
						cout << "DISPLAY POSTGRADUATESTUDENT DONE!!!" << endl;
						// displayPostgraduate();
						// Function Object to delete Postgraduate Student
						break;
					case 3  :
						cout << "DISPLAY STAFF DONE!!!" << endl;
						// displayStaff();
						// Function Object to delete Staff
						break;
					default :
						cout << "Input Not Recognized!!!!" << endl;
						break;
				}
				cout << endl;
				system("pause");
				break;
				
			//============================================================//
			//			Choice 4 = EXIT PROGRAM							  //
			// This will exit the program								  //
			//============================================================//
				
			case 4 : 
				exit(1);
			
			default :
				cout << "Input Not Recognized!!!" << endl;
				system("pause");
				break;
		}
	} while (choice != 4); ;// This argument check wheter the choice is 4 (exit) or not
	
	return 0;
}

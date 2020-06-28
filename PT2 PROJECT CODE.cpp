#include <iostream>
#include <iomanip>
#include <fstream>
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
		void allocateUTM() // Allocate UTM Class
		{
			kolej = new UTM;
			address = 0;
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
		void allocateOutside() // Allocate Outside Class
		{
			address = new Outside;
			kolej = 0;
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
		bool checkInside() // To Check whether Lecturer Inside or not
		{
			bool inside = false;
			
			if (address == 0);
			inside = true;
			
			return inside;
		}
		void showInfo() // Overriden Function from Base Class Person
		{
			cout << left << setw(20) << "Name" << ": " << name << endl;
			cout << setw(20) << "Course" << ": " << course.getName() << endl;
			cout << setw(20) << "Course Code" << ": " << course.getCode() << endl;
			
			if (kolej == 0)
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
		void allocateUTM() // Allocate UTM Class
		{
			kolej = new UTM;
			address = 0;
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
		void allocateOutside() // Allocate Outside Class
		{
			address = new Outside;
			kolej = 0;
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
		bool checkInside() // To Check whether Student Inside or not
		{
			bool inside = false;
			
			if (address == 0);
			inside = true;
			
			return inside;
		}
		void showInfo() // Overriden Function from Base Class Person
		{
			cout << left << setw(20) << "Name" << ": " << name << endl;
			cout << setw(20) << "Metric ID" << ": " << metric << endl;
			cout << setw(20) << "Course" << ": " << course.getName() << endl;
			cout << setw(20) << "Course Code" << ": " << course.getCode() << endl;
			
			
			if (kolej == 0)
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
		void allocateUTM() // Allocate UTM Class
		{
			kolej = new UTM;
			address = 0;
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
		void allocateOutside() // Allocate Outside Class
		{
			address = new Outside;
			kolej = 0;
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
		bool checkInside() // To Check whether Staff Inside or not
		{
			bool inside = false;
			
			if (address == 0);
			inside = true;
			
			return inside;
		}
		void showInfo() // Overriden Function from Base Class Person
		{
			cout << left << setw(20) << "Name" << ": " << name << endl;
			cout << setw(20) << "Department" << ": " << department.getName() << endl;
			
			if (kolej == 0)
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
	
	cout << endl;
	cout << "4. SEARCH DATA" << endl;
	cout << endl;
	
	cout << "5. READ DATA" << endl;
	cout << "6. SAVE DATA" << endl;
	
	cout << endl;
	cout << "7. EXIT PROGRAM" << endl;
	
	cout << endl << "Choose what you want to do : ";
}

//============================================================//
//						addUndergraduate()					  //
//					Input  = *undergraduate, countUG		  //
//					Output = Adding New Input for UG		  //
//															  //
// This Function will add new entry for UG.					  //
// It have a handle execption program to check wheter it's 	  //
// empty or have been filled already.						  //
//============================================================//

void addUndergraduate(Student *&undergraduate, int &countUG)
{
	int choice; // Variable for Choice
	string name; // Temporary variable for Undergraduate Name
	string metric; // Temporary variable for Undergraduate Metric
	string courseName; // Temporary variable for Undergraduate Course Name
	string courseCode; // Temporary variable for Undergraduate Course Code
	string country; // Temporary variable for Undergraduate Country
	string state; // Temporary variable for Undergraduate State
	string kolej; // Temporary variable for Undergraduate Kolej
	string block; // Temporary variable for Undergraduate Block
	string city; // Temporary variable for Undergraduate City
	string address; // Temporary variable for Undergraduate Address
	
	cin.ignore(); // Clearing the Buffer
	cout << endl << endl;
	cout << "--==--==--==--==--==--==--==--==--" << endl;
	cout << "Adding New Undergraduate Input" << endl;
	cout << "--==--==--==--==--==--==--==--==--" << endl << endl;
	cout << "Name : ";
	getline(cin, name); // User Input for Name
	cout << "Metric : ";
	getline(cin, metric); // User Input for Metric
	cout << "Course Name : ";
	getline(cin, courseName); // User Input for Course Name
	cout << "Course Code : ";
	getline(cin, courseCode); // User Input for Course Code
	
	cout << endl << endl;
	cout << "1. Inside UTM" << endl;
	cout << "2. Outside UTM" << endl;
	cout << "Where do they live : "; // Asking the User for Choice of Living Place
	cin >> choice; // User Input to determine Choice
	
	//================================//
	// This Switch statements will determine which data need to be added 
	// based on the choice what the user input. 
	//
	// If the user input 1 it will automatically set the Country to Malaysia
	// and the State to Johor Bahru.
	// If the user input 2 it will ask all of the data needed.
	//================================//
	
	cin.ignore(); // Clearing the Buffer
	switch (choice)
	{
		//==================//
		// Choice 1 is for the Undergraduate who is staying inside UTM.
		// The Country will be automatically set to Malaysia and the 
		// state will be set to Johor Bahru, so the user will only need
		// to add the Kolej and Block data.
		//==================//
		
		case 1 :
			country = "Malaysia";
			state = "Johor Bahru";
			
			cout << "Kolej : ";
			getline(cin, kolej); // User Input for Kolej
			cout << "Block : ";
			getline(cin, block); // User Input for Block
			break;
			
		//==================//
		// Choice 2 is for the Undergraduate who is staying Outside UTM.
		// The user will need to enter all of the required info from 
		// country up to their address all by themselves, as it is not
		// been set in the first time.
		//==================//
		case 2 :
			cout << "Country : ";
			getline(cin, country);
			cout << "State : ";
			getline(cin, state);
			cout << "City : ";
			getline(cin, city);
			cout << "Address : ";
			getline(cin, address);
			break;
		//==================//
		// The default option is when the user input the choice that
		// is not 1 or 2. It will terminate the addUndergraduate
		// function and go back to the main menu.
		//==================// 
		default :
			cout << "Input Not Recognized!" << endl;
			cout << "Going back to Main Menu..." << endl;
			return;
	}
	
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
		temp[countUG].setCourseName(courseName);
		temp[countUG].setCourseCode(courseCode);
		
		if (choice == 1)
		{
			temp[countUG].allocateUTM();
			temp[countUG].setUTMCountry(country);
			temp[countUG].setUTMState(state);
			temp[countUG].setUTMKolej(kolej);
			temp[countUG].setUTMBlock(block);
		}
		else if (choice == 2)
		{
			temp[countUG].allocateOutside();
			temp[countUG].setOutsideCountry(country);
			temp[countUG].setOutsideState(state);
			temp[countUG].setOutsideCity(city);
			temp[countUG].setOutsideAddress(address);
		}
		
		delete [] undergraduate;
		
		countUG++;
		
		undergraduate = temp;
	}
	catch (const char *msg)
	{
		undergraduate= new Student[1];
		
		undergraduate[0].setName(name);
		undergraduate[0].setMetric(metric);
		undergraduate[0].setCourseName(courseName);
		undergraduate[0].setCourseCode(courseCode);
		
		if (choice == 1)
		{
			undergraduate[0].allocateUTM();
			undergraduate[0].setUTMCountry(country);
			undergraduate[0].setUTMState(state);
			undergraduate[0].setUTMKolej(kolej);
			undergraduate[0].setUTMBlock(block);
		}
		else if (choice == 2)
		{
			undergraduate[0].allocateOutside();
			undergraduate[0].setOutsideCountry(country);
			undergraduate[0].setOutsideState(state);
			undergraduate[0].setOutsideCity(city);
			undergraduate[0].setOutsideAddress(address);
		}
		
		countUG++;
	}
	
	return;
}

//============================================================//
//						addPostgraduate()					  //
//					Input  = *postgraduate, countPG			  //
//					Output = Adding New Input for PG		  //
//															  //
// This Function will add new entry for PG.					  //
// It have a handle execption program to check wheter it's 	  //
// empty or have been filled already.						  //
//============================================================//

void addPostgraduate(Student *&postgraduate, int &countPG)
{
	int choice; // Variable for Choice
	string name; // Temporary variable for Postgraduate Name
	string metric; // Temporary variable for Postgraduate Metric
	string courseName; // Temporary variable for Postgraduate Course Name
	string courseCode; // Temporary variable for Postgraduate Course Code
	string country; // Temporary variable for Postgraduate Country
	string state; // Temporary variable for Postgraduate State
	string kolej; // Temporary variable for Postgraduate Kolej
	string block; // Temporary variable for Postgraduate Block
	string city; // Temporary variable for Postgraduate City
	string address; // Temporary variable for Postgraduate Address
	
	cin.ignore(); // Clearing the Buffer
	cout << endl << endl;
	cout << "--==--==--==--==--==--==--==--==--" << endl;
	cout << "Adding New Postgraduate Input" << endl;
	cout << "--==--==--==--==--==--==--==--==--" << endl << endl;
	cout << "Name : ";
	getline(cin, name); // User Input for Name
	cout << "Metric : ";
	getline(cin, metric); // User Input for Metric
	cout << "Course Name : ";
	getline(cin, courseName); // User Input for Course Name
	cout << "Course Code : ";
	getline(cin, courseCode); // User Input for Course Code
	
	cout << endl << endl;
	cout << "1. Inside UTM" << endl;
	cout << "2. Outside UTM" << endl;
	cout << "Where do they live : "; // Asking the User for Choice of Living Place
	cin >> choice; // User Input to determine Choice
	
	//================================//
	// This Switch statements will determine which data need to be added 
	// based on the choice what the user input. 
	//
	// If the user input 1 it will automatically set the Country to Malaysia
	// and the State to Johor Bahru.
	// If the user input 2 it will ask all of the data needed.
	//================================//
	
	cin.ignore(); // Clearing the Buffer
	switch (choice)
	{
		//==================//
		// Choice 1 is for the Postgraduate who is staying inside UTM.
		// The Country will be automatically set to Malaysia and the 
		// state will be set to Johor Bahru, so the user will only need
		// to add the Kolej and Block data.
		//==================//
		
		case 1 :
			country = "Malaysia";
			state = "Johor Bahru";
			
			cout << "Kolej : ";
			getline(cin, kolej); // User Input for Kolej
			cout << "Block : ";
			getline(cin, block); // User Input for Block
			break;
			
		//==================//
		// Choice 2 is for the Postgraduate who is staying Outside UTM.
		// The user will need to enter all of the required info from 
		// country up to their address all by themselves, as it is not
		// been set in the first time.
		//==================//
		case 2 :
			cout << "Country : ";
			getline(cin, country);
			cout << "State : ";
			getline(cin, state);
			cout << "City : ";
			getline(cin, city);
			cout << "Address : ";
			getline(cin, address);
			break;
		//==================//
		// The default option is when the user input the choice that
		// is not 1 or 2. It will terminate the addUndergraduate
		// function and go back to the main menu.
		//==================// 
		default :
			cout << "Input Not Recognized!" << endl;
			cout << "Going back to Main Menu..." << endl;
			return;
	}
	
	try
	{
		if (postgraduate == 0)
		throw "Empty!";
		
		Student *temp;
		
		temp = new Student[countPG+1];
		
		for (int i = 0; i < countPG; i++)
		{
			temp[i] = postgraduate[i];
		}
		
		temp[countPG].setName(name);
		temp[countPG].setMetric(metric);
		temp[countPG].setCourseName(courseName);
		temp[countPG].setCourseCode(courseCode);
		
		if (choice == 1)
		{
			temp[countPG].allocateUTM();
			temp[countPG].setUTMCountry(country);
			temp[countPG].setUTMState(state);
			temp[countPG].setUTMKolej(kolej);
			temp[countPG].setUTMBlock(block);
		}
		else if (choice == 2)
		{
			temp[countPG].allocateOutside();
			temp[countPG].setOutsideCountry(country);
			temp[countPG].setOutsideState(state);
			temp[countPG].setOutsideCity(city);
			temp[countPG].setOutsideAddress(address);
		}
		
		delete [] postgraduate;
		
		countPG++;
		
		postgraduate = temp;
	}
	catch (const char *msg)
	{
		postgraduate= new Student[1];
		
		postgraduate[0].setName(name);
		postgraduate[0].setMetric(metric);
		postgraduate[0].setCourseName(courseName);
		postgraduate[0].setCourseCode(courseCode);
		
		if (choice == 1)
		{
			postgraduate[0].allocateUTM();
			postgraduate[0].setUTMCountry(country);
			postgraduate[0].setUTMState(state);
			postgraduate[0].setUTMKolej(kolej);
			postgraduate[0].setUTMBlock(block);
		}
		else if (choice == 2)
		{
			postgraduate[0].allocateOutside();
			postgraduate[0].setOutsideCountry(country);
			postgraduate[0].setOutsideState(state);
			postgraduate[0].setOutsideCity(city);
			postgraduate[0].setOutsideAddress(address);
		}
		
		countPG++;
	}
	
	return;
}

//============================================================//
//						addLecturer()						  //
//					Input  = *lecturer, countLecturer		  //
//					Output = Adding New Input for Lecturer	  //
//															  //
// This Function will add new entry for Lecturer.			  //
// It have a handle execption program to check wheter it's 	  //
// empty or have been filled already.						  //
//============================================================//

void addLecturer(Lecturer *&lecturer, int &countLecturer)
{
	int choice; // Variable for Choice
	string name; // Temporary variable for Lecturer Name
	string courseName; // Temporary variable for Lecturer Course Name
	string courseCode; // Temporary variable for Lecturer Course Code
	string country; // Temporary variable for Lecturer Country
	string state; // Temporary variable for Lecturer State
	string kolej; // Temporary variable for Lecturer Kolej
	string block; // Temporary variable for Lecturer Block
	string city; // Temporary variable for Lecturer City
	string address; // Temporary variable for Lecturer Address
	
	cin.ignore(); // Clearing The Buffer
	cout << endl << endl;
	cout << "--==--==--==--==--==--==--==--==--" << endl;
	cout << "Adding New Lecturer Input" << endl;
	cout << "--==--==--==--==--==--==--==--==--" << endl << endl;
	cout << "Name : ";
	getline(cin, name); // User Input for Name
	cout << "Course Name : ";
	getline(cin, courseName); // User Input for Course Name
	cout << "Course Code : ";
	getline(cin, courseCode); // User Input for Course Code
	
	cout << endl << endl;
	cout << "1. Inside UTM" << endl;
	cout << "2. Outside UTM" << endl;
	cout << "Where do they live : "; // Asking the User for Choice of Living Place
	cin >> choice; // User Input to determine Choice
	
	//================================//
	// This Switch statements will determine which data need to be added 
	// based on the choice what the user input. 
	//
	// If the user input 1 it will automatically set the Country to Malaysia
	// and the State to Johor Bahru.
	// If the user input 2 it will ask all of the data needed.
	//================================//
	
	cin.ignore(); // Clearing the Buffer
	switch (choice)
	{
		//==================//
		// Choice 1 is for the Lecturer who is staying inside UTM.
		// The Country will be automatically set to Malaysia and the 
		// state will be set to Johor Bahru, so the user will only need
		// to add the Kolej and Block data.
		//==================//
		
		case 1 :
			country = "Malaysia";
			state = "Johor Bahru";
			
			cout << "Kolej : ";
			getline(cin, kolej); // User Input for Kolej
			cout << "Block : ";
			getline(cin, block); // User Input for Block
			break;
			
		//==================//
		// Choice 2 is for the Lecturer who is staying Outside UTM.
		// The user will need to enter all of the required info from 
		// country up to their address all by themselves, as it is not
		// been set in the first time.
		//==================//
		case 2 :
			cout << "Country : ";
			getline(cin, country);
			cout << "State : ";
			getline(cin, state);
			cout << "City : ";
			getline(cin, city);
			cout << "Address : ";
			getline(cin, address);
			break;
		//==================//
		// The default option is when the user input the choice that
		// is not 1 or 2. It will terminate the addUndergraduate
		// function and go back to the main menu.
		//==================// 
		default :
			cout << "Input Not Recognized!" << endl;
			cout << "Going back to Main Menu..." << endl;
			return;
	}
	
	try
	{
		if (lecturer == 0)
		throw "Empty!";
		
		Lecturer *temp;
		
		temp = new Lecturer[countLecturer+1];
		
		for (int i = 0; i < countLecturer; i++)
		{
			temp[i] = lecturer[i];
		}
		
		temp[countLecturer].setName(name);
		temp[countLecturer].setCourseName(courseName);
		temp[countLecturer].setCourseCode(courseCode);
		
		if (choice == 1)
		{
			temp[countLecturer].allocateUTM();
			temp[countLecturer].setUTMCountry(country);
			temp[countLecturer].setUTMState(state);
			temp[countLecturer].setUTMKolej(kolej);
			temp[countLecturer].setUTMBlock(block);
		}
		else if (choice == 2)
		{
			temp[countLecturer].allocateOutside();
			temp[countLecturer].setOutsideCountry(country);
			temp[countLecturer].setOutsideState(state);
			temp[countLecturer].setOutsideCity(city);
			temp[countLecturer].setOutsideAddress(address);
		}
		
		delete [] lecturer;
		
		countLecturer++;
		
		lecturer = temp;
	}
	catch (const char *msg)
	{
		lecturer = new Lecturer[1];
		
		lecturer[0].setName(name);
		lecturer[0].setCourseName(courseName);
		lecturer[0].setCourseCode(courseCode);
		
		if (choice == 1)
		{
			lecturer[0].allocateUTM();
			lecturer[0].setUTMCountry(country);
			lecturer[0].setUTMState(state);
			lecturer[0].setUTMKolej(kolej);
			lecturer[0].setUTMBlock(block);
		}
		else if (choice == 2)
		{
			lecturer[0].allocateOutside();
			lecturer[0].setOutsideCountry(country);
			lecturer[0].setOutsideState(state);
			lecturer[0].setOutsideCity(city);
			lecturer[0].setOutsideAddress(address);
		}
		
		countLecturer++;
	}
	
	return;
}

//============================================================//
//						addStaff()							  //
//					Input  = *staff, countStaff	 			  //
//					Output = Adding New Input for Staff		  //
//															  //
// This Function will add new entry for Staff.				  //
// It have a handle execption program to check wheter it's 	  //
// empty or have been filled already.						  //
//============================================================//

void addStaff(Staff *&staff, int &countStaff)
{
	int choice; // Variable for Choice
	string name; // Temporary variable for Staff Name
	string department; // Temporary variable for Staff Departmemt
	string country; // Temporary variable for Staff Country
	string state; // Temporary variable for Staff State
	string kolej; // Temporary variable for Staff Kolej
	string block; // Temporary variable for Staff Block
	string city; // Temporary variable for Staff City
	string address; // Temporary variable for Staff Address
	
	cin.ignore(); // Clearing the Buffer
	cout << endl << endl;
	cout << "--==--==--==--==--==--==--==--==--" << endl;
	cout << "Adding New Staff Input" << endl;
	cout << "--==--==--==--==--==--==--==--==--" << endl << endl;
	cout << "Name : ";
	getline(cin, name); // User Input for Name
	cout << "Department : ";
	getline(cin, department); // User Input for Department
	
	cout << endl << endl;
	cout << "1. Inside UTM" << endl;
	cout << "2. Outside UTM" << endl;
	cout << "Where do they live : "; // Asking the User for Choice of Living Place
	cin >> choice; // User Input to determine Choice
	
	//================================//
	// This Switch statements will determine which data need to be added 
	// based on the choice what the user input. 
	//
	// If the user input 1 it will automatically set the Country to Malaysia
	// and the State to Johor Bahru.
	// If the user input 2 it will ask all of the data needed.
	//================================//
	
	cin.ignore(); // Clearing the Buffer
	switch (choice)
	{
		//==================//
		// Choice 1 is for the Staff who is staying inside UTM.
		// The Country will be automatically set to Malaysia and the 
		// state will be set to Johor Bahru, so the user will only need
		// to add the Kolej and Block data.
		//==================//
		
		case 1 :
			country = "Malaysia";
			state = "Johor Bahru";
			
			cout << "Kolej : ";
			getline(cin, kolej); // User Input for Kolej
			cout << "Block : ";
			getline(cin, block); // User Input for Block
			break;
			
		//==================//
		// Choice 2 is for the Staff who is staying Outside UTM.
		// The user will need to enter all of the required info from 
		// country up to their address all by themselves, as it is not
		// been set in the first time.
		//==================//
		case 2 :
			cout << "Country : ";
			getline(cin, country);
			cout << "State : ";
			getline(cin, state);
			cout << "City : ";
			getline(cin, city);
			cout << "Address : ";
			getline(cin, address);
			break;
		//==================//
		// The default option is when the user input the choice that
		// is not 1 or 2. It will terminate the addStaff
		// function and go back to the main menu.
		//==================// 
		default :
			cout << "Input Not Recognized!" << endl;
			cout << "Going back to Main Menu..." << endl;
			return;
	}
	
	try
	{
		if (staff == 0)
		throw "Empty!";
		
		Staff *temp;
		
		temp = new Staff[countStaff+1];
		
		for (int i = 0; i < countStaff; i++)
		{
			temp[i] = staff[i];
		}
		
		temp[countStaff].setName(name);
		temp[countStaff].setDepartment(department);
		
		if (choice == 1)
		{
			temp[countStaff].allocateUTM();
			temp[countStaff].setUTMCountry(country);
			temp[countStaff].setUTMState(state);
			temp[countStaff].setUTMKolej(kolej);
			temp[countStaff].setUTMBlock(block);
		}
		else if (choice == 2)
		{
			temp[countStaff].allocateOutside();
			temp[countStaff].setOutsideCountry(country);
			temp[countStaff].setOutsideState(state);
			temp[countStaff].setOutsideCity(city);
			temp[countStaff].setOutsideAddress(address);
		}
		
		delete [] staff;
		
		countStaff++;
		
		staff = temp;
	}
	catch (const char *msg)
	{
		staff = new Staff[1];
		
		staff[0].setName(name);
		staff[0].setDepartment(department);
		
		if (choice == 1)
		{
			staff[0].allocateUTM();
			staff[0].setUTMCountry(country);
			staff[0].setUTMState(state);
			staff[0].setUTMKolej(kolej);
			staff[0].setUTMBlock(block);
		}
		else if (choice == 2)
		{
			staff[0].allocateOutside();
			staff[0].setOutsideCountry(country);
			staff[0].setOutsideState(state);
			staff[0].setOutsideCity(city);
			staff[0].setOutsideAddress(address);
		}
		
		countStaff++;
	}
	
	return;
}

//============================================================//
//					displayUdergraduate()                     //
//					Input  = *undergraduate, countUG          //
//					Output = Displaying Undergradaute Data    //
//															  //
// This Function will display the Undergraduate data that have//
// been stored in the machine.                                //
//============================================================//

void displayUndergraduate(Student *undergraduate, int countUG)
{
	
	try
	{
		if (countUG == 0)
		throw "There is no input!";
		
		
		for (int i = 0; i < countUG; i++)
		{
			cout << endl << endl;
			cout << "-=-=-=-=-=-=-=" << endl;
			cout << "Data " << i+1 << endl;
			cout << "-=-=-=-=-=-=-=" << endl;
			undergraduate[i].showInfo();
		}
	}
	catch (const char *msg)
	{
		cout << endl;
		cout << msg << endl;
		cout << "Going Back to Main Menu..." << endl;
	}
}

//============================================================//
//					displayPostgraduate()                     //
//					Input  = *postgraduate, countPG           //
//					Output = Displaying Postgraduate Data     //
//															  //
// This Function will display the Postgraduate data that have //
// been stored in the machine.                                //
//============================================================//

void displayPostgraduate(Student *postgraduate, int countPG)
{
	
	try
	{
		if (countPG == 0)
		throw "There is no input!";
		
		
		for (int i = 0; i < countPG; i++)
		{
			cout << endl << endl;
			cout << "-=-=-=-=-=-=-=" << endl;
			cout << "Data " << i+1 << endl;
			cout << "-=-=-=-=-=-=-=" << endl;
			postgraduate[i].showInfo();
		}
	}
	catch (const char *msg)
	{
		cout << endl;
		cout << msg << endl;
		cout << "Going Back to Main Menu..." << endl;
	}
}

//============================================================//
//						displaylecturer()                     //
//					Input  = *lecturer, countlecturer         //
//					Output = Displaying Lecturer Data	      //
//															  //
// This Function will display the Lecturer data that have	  //
// been stored in the machine.                                //
//============================================================//

void displayLecturer(Lecturer *lecturer, int countLecturer)
{
	
	try
	{
		if (countLecturer == 0)
		throw "There is no input!";
		
		
		for (int i = 0; i < countLecturer; i++)
		{
			cout << endl << endl;
			cout << "-=-=-=-=-=-=-=" << endl;
			cout << "Data " << i+1 << endl;
			cout << "-=-=-=-=-=-=-=" << endl;
			lecturer[i].showInfo();
		}
	}
	catch (const char *msg)
	{
		cout << endl;
		cout << msg << endl;
		cout << "Going Back to Main Menu..." << endl;
	}
}

//============================================================//
//						displayStaff()                        //
//					Input  = *staff, countStaff         	  //
//					Output = Displaying Staff Data            //
//															  //
// This Function will display the Staff data that have        //
// been stored in the machine.                                //
//============================================================//

void displayStaff(Staff *staff, int countStaff)
{
	
	try
	{
		if (countStaff == 0)
		throw "There is no input!";
		
		
		for (int i = 0; i < countStaff; i++)
		{
			cout << endl << endl;
			cout << "-=-=-=-=-=-=-=" << endl;
			cout << "Data " << i+1 << endl;
			cout << "-=-=-=-=-=-=-=" << endl;
			staff[i].showInfo();
		}
	}
	catch (const char *msg)
	{
		cout << endl;
		cout << msg << endl;
		cout << "Going Back to Main Menu..." << endl;
	}
}

//============================================================//
//					searchUndergraduate()                     //
//					Input  = google, countUG       			  //	
//					Output = Displaying the search string     //
//															  //
// This Function will display the string that is searched by  //
// the user in the Undergraduate data.						  //
//============================================================//

void searchUndergraduate(string google, Student *undergraduate, int countUG)
{
	int count = 0; // Variable for counter
	bool check = false; // Variable to check
	
	try
	{
		if (countUG == 0)
		throw "Input is Empty!";
		
		for (int i = 0; i < countUG; i -= -1)
		{
			check = false;
			
			if (undergraduate[i].getName().find(google) < undergraduate[i].getName().size())
			{
				check = true;
				goto found;
			}
			if (undergraduate[i].getMetric().find(google) < undergraduate[i].getMetric().size())
			{
				check = true;
				goto found;
			}
			if (undergraduate[i].getCourseName().find(google) < undergraduate[i].getCourseName().size())
			{
				check = true;
				goto found;
			}
			if (undergraduate[i].getCourseCode().find(google) < undergraduate[i].getCourseCode().size())
			{
				check = true;
				goto found;
			}
			
			/*if (undergraduate[i].getOutsideCountry().empty())
			{
				cout << "CTACHT" << endl;
				cout << undergraduate[i].getOutsideCountry();
				cout << endl;
				goto utm;
			}
			/*else if (!undergraduate[i].getUTMKolej().empty())
			{
				cout << "GOT" << endl;
				cout << undergraduate[i].getUTMKolej();
				cout << endl;
				goto utm;
			}*/
			cout << "GOT" << endl;
			
			/*utm :
			if (undergraduate[i].getUTMCountry().find(google) < undergraduate[i].getUTMCountry().size())
			{
				check = true;
				goto found;
			}
			if (undergraduate[i].getUTMState().find(google) < undergraduate[i].getUTMState().size())
			{
				check = true;
				goto found;
			}
			if (undergraduate[i].getUTMKolej().find(google) < undergraduate[i].getUTMKolej().size())
			{
				check = true;
				goto found;
			}
			if (undergraduate[i].getUTMBlock().find(google) < undergraduate[i].getUTMBlock().size())
			{
				check = true;
				goto found;
			}
			//goto found;*/
		
			outside :
			if (undergraduate[i].getOutsideCountry().find(google) < undergraduate[i].getOutsideCountry().size())
			{
				check = true;
				goto found;
			}
			if (undergraduate[i].getOutsideState().find(google) < undergraduate[i].getOutsideState().size())
			{
				check = true;
				goto found;	
			}
			if (undergraduate[i].getOutsideCity().find(google) < undergraduate[i].getOutsideCity().size())
			{
				check = true;
				goto found;
			}
			if (undergraduate[i].getOutsideAddress().find(google) < undergraduate[i].getOutsideAddress().size())
			{
				check = true;
				goto found;
			}
		
			found :
			if (check)
			{
				undergraduate[i].showInfo();
				cout << endl << endl;
				count++;
			}
		}
			
		if (count == 0)
		{
			cout << "No Matched Input";
		}
	}
	catch (const char *error)
	{
		cout << error << endl;
	}
}


//============================================================//
//						searchData()                     	  //
//					Input  = countUG, countPG, countLecturer  //
//							 countStaff, *undergraduate,	  //
//							 *postgraduate, *lecturer, *staff //	
//					Output = Displaying the search string     //
//															  //
// This Function will display the string that is searched by  //
// the user.												  //
//============================================================//

void searchData(int countUG, int countPG, int countLecturer, int countStaff, Student *undergraduate, Student *postgraduate, Lecturer *lecturer, Staff *staff)
{
	string google; // Variable for User Input to search data
	
	cout << "Please enter the string that you wish to search : ";
	cin >> google;
	
	cout << endl << endl;
	cout << "-===-===-===-===-===-" << endl;
	cout << "     UNDERGRADUATE   " << endl;
	cout << "-===-===-===-===-===-" << endl;
	cout << endl;
	
	searchUndergraduate(google, undergraduate, countUG); // Calling Function searchUndergraduate
	
	cout << endl << endl;
}

//============================================================//
//						readUndergraduate()					  //
//					Input  = *undergraduate, countUG		  //
//					Output = Reading New Input for UG		  //
//															  //
// This Function will read new entry for UG.				  //
// It have a handle execption program to check wheter it's 	  //
// empty or have been filled already and to check whether the //
// program exist or not.									  //
//============================================================//

void readUndergraduate(Student *&undergraduate, int &countUG)
{
	string fileName; // Variable for File Name
	
	cin.ignore();
	cout << endl << endl;
	cout << "--==--==--==--==--==--==--==--==--" << endl;
	cout << "Reading New Undergraduate Input" << endl;
	cout << "--==--==--==--==--==--==--==--==--" << endl << endl;
	
	cout << "Please be advised that the data follow this structure of data writing : " << endl << endl;
	
	cout << "NAME, METRIC, COURSE NAME, COURSE CODE, OUTSIDE/INSIDE, COUNTRY/(IF INSIDE SKIP THIS), STATE/(IF INSIDE SKIP THIS), CITY/KOLEJ, ADDRESS/BLOCK" << endl << endl;
	
	cout << "Enter the name file you want to read from : ";
	getline(cin, fileName);
	
	clear :
	try
	{
		if (countUG != 0)
		{
			throw "There is data saved in the program right now!";
		}
		
		try
		{
			ifstream file (fileName.c_str());
		
			if (!file)
			{
				throw "Error! File unable to be Open!";
			}
			
			string choice; // Variable for Choice
			string name; // Temporary variable for Undergraduate Name
			string metric; // Temporary variable for Undergraduate Metric
			string courseName; // Temporary variable for Undergraduate Course Name
			string courseCode; // Temporary variable for Undergraduate Course Code
			string country; // Temporary variable for Undergraduate Country
			string state; // Temporary variable for Undergraduate State
			string kolej; // Temporary variable for Undergraduate Kolej
			string block; // Temporary variable for Undergraduate Block
			string city; // Temporary variable for Undergraduate City
			string address; // Temporary variable for Undergraduate Address
	
			while (getline(file, name, ','))
			{
				getline(file, metric, ','); // Read Input for Metric
				getline(file, courseName, ','); // Read Input for Course Name
				getline(file, courseCode, ','); // Read Input for Course Code
				getline(file, choice, ','); // Read Input to determine Choice
			
				int choose;
				if (choice == "Inside")
				{
					choose = 1;
				}
				else
				{
					choose = 2;
				}
				//================================//
				// This Switch statements will determine which data need to be added 
				// based on the choice what the user input. 
				//
				// If the data input 1 it will automatically set the Country to Malaysia
				// and the State to Johor Bahru.
				// If the user input 2 it will ask all of the data needed.
				//================================//
				switch (choose)
				{
					//==================//
					// Choice 1 is for the Undergraduate who is staying inside UTM.
					// The Country will be automatically set to Malaysia and the 
					// state will be set to Johor Bahru, so the user will only need
					// to add the Kolej and Block data.
					//==================//
		
					case 1 :
					country = "Malaysia";
					state = "Johor Bahru";
				
					getline(file, kolej, ','); // Read Input for Kolej
					getline(file, block, '\n'); // Read Input for Block
					break;
				
					//==================//
					// Choice 2 is for the Undergraduate who is staying Outside UTM.
					// The user will need to enter all of the required info from 
					// country up to their address all by themselves, as it is not
					// been set in the first time.
					//==================//
				
					case 2 :
					getline(file, country, ',');
					getline(file, state, ',');
					getline(file, city, ',');
					getline(file, address, '\n');
					break;
				}
	
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
					temp[countUG].setCourseName(courseName);
					temp[countUG].setCourseCode(courseCode);
			
					if (choose == 1)
					{
						temp[countUG].allocateUTM();
						temp[countUG].setUTMCountry(country);
						temp[countUG].setUTMState(state);
						temp[countUG].setUTMKolej(kolej);
						temp[countUG].setUTMBlock(block);
					}
					else if (choose == 2)
					{
						temp[countUG].allocateOutside();
						temp[countUG].setOutsideCountry(country);
						temp[countUG].setOutsideState(state);
						temp[countUG].setOutsideCity(city);
						temp[countUG].setOutsideAddress(address);
					}
		
					delete [] undergraduate;
			
					countUG++;
		
					undergraduate = temp;
				}
				catch (const char *msg)
				{
					undergraduate = new Student[1];
					
					undergraduate[0].setName(name);
					undergraduate[0].setMetric(metric);
					undergraduate[0].setCourseName(courseName);
					undergraduate[0].setCourseCode(courseCode);
				
					if (choose == 1)
					{
						undergraduate[0].allocateUTM();
						undergraduate[0].setUTMCountry(country);
						undergraduate[0].setUTMState(state);
						undergraduate[0].setUTMKolej(kolej);
						undergraduate[0].setUTMBlock(block);
					}
					else if (choose == 2)
					{
						undergraduate[0].allocateOutside();
						undergraduate[0].setOutsideCountry(country);
						undergraduate[0].setOutsideState(state);
						undergraduate[0].setOutsideCity(city);
						undergraduate[0].setOutsideAddress(address);
					}
					countUG++;
				}
			}
			cout << endl << endl << "Data Have been Succesfully read!" << endl;
		}
		catch (const char *error)
		{
			cout << error << endl;
		}
	}
	catch (const char *clear)
	{
		char choice;
		
		cout << clear << endl;
		cout << "Do you want to erase the data (y/n) : ";
		cin >> choice;
		
		if (choice == 'y')
		{
			countUG = 0;
			goto clear;
		}
	}
}

//============================================================//
//						readPostgraduate()					  //
//					Input  = *postgraduate, countPG	 		  //
//					Output = Reading New Input for PG		  //
//															  //
// This Function will read new entry for PG.				  //
// It have a handle execption program to check wheter it's 	  //
// empty or have been filled already and to check whether the //
// program exist or not.									  //
//============================================================//

void readPostgraduate(Student *&postgraduate, int &countPG)
{
	string fileName; // Variable for File Name
	
	cin.ignore();
	cout << endl << endl;
	cout << "--==--==--==--==--==--==--==--==--" << endl;
	cout << "Reading New Postgraduate Input" << endl;
	cout << "--==--==--==--==--==--==--==--==--" << endl << endl;
	
	cout << "Please be advised that the data follow this structure of data writing : " << endl << endl;
	
	cout << "NAME, METRIC, COURSE NAME, COURSE CODE, OUTSIDE/INSIDE, COUNTRY/(IF INSIDE SKIP THIS), STATE/(IF INSIDE SKIP THIS), CITY/KOLEJ, ADDRESS/BLOCK" << endl << endl;
	
	cout << "Enter the name file you want to read from : ";
	getline(cin, fileName);
	
	clear :
	try
	{
		if (countPG != 0)
		{
			throw "There is data saved in the program right now!";
		}
		
		try
		{
			ifstream file (fileName.c_str());
		
			if (!file)
			{
				throw "Error! File unable to be Open!";
			}
			
			string choice; // Variable for Choice
			string name; // Temporary variable for Postgraduate Name
			string metric; // Temporary variable for Postgraduate Metric
			string courseName; // Temporary variable for Postgraduate Course Name
			string courseCode; // Temporary variable for Postgraduate Course Code
			string country; // Temporary variable for Postgraduate Country
			string state; // Temporary variable for Postgraduate State
			string kolej; // Temporary variable for Postgraduate Kolej
			string block; // Temporary variable for Postgraduate Block
			string city; // Temporary variable for Postgraduate City
			string address; // Temporary variable for Postgraduate Address
	
			while (getline(file, name, ','))
			{
				getline(file, metric, ','); // Read Input for Metric
				getline(file, courseName, ','); // Read Input for Course Name
				getline(file, courseCode, ','); // Read Input for Course Code
				getline(file, choice, ','); // Read Input to determine Choice
			
				int choose;
				if (choice == "Inside")
				{
					choose = 1;
				}
				else
				{
					choose = 2;
				}
				//================================//
				// This Switch statements will determine which data need to be added 
				// based on the choice what the user input. 
				//
				// If the data input 1 it will automatically set the Country to Malaysia
				// and the State to Johor Bahru.
				// If the user input 2 it will ask all of the data needed.
				//================================//
				switch (choose)
				{
					//==================//
					// Choice 1 is for the Postgraduate who is staying inside UTM.
					// The Country will be automatically set to Malaysia and the 
					// state will be set to Johor Bahru, so the user will only need
					// to add the Kolej and Block data.
					//==================//
		
					case 1 :
					country = "Malaysia";
					state = "Johor Bahru";
				
					getline(file, kolej, ','); // Read Input for Kolej
					getline(file, block, '\n'); // Read Input for Block
					break;
				
					//==================//
					// Choice 2 is for the Postgraduate who is staying Outside UTM.
					// The user will need to enter all of the required info from 
					// country up to their address all by themselves, as it is not
					// been set in the first time.
					//==================//
				
					case 2 :
					getline(file, country, ',');
					getline(file, state, ',');
					getline(file, city, ',');
					getline(file, address, '\n');
					break;
				}
	
				try
				{
					if (postgraduate == 0)
					throw "Empty!";
			
					Student *temp;
		
					temp = new Student[countPG+1];
			
					for (int i = 0; i < countPG; i++)
					{
						temp[i] = postgraduate[i];
					}
		
					temp[countPG].setName(name);
					temp[countPG].setMetric(metric);
					temp[countPG].setCourseName(courseName);
					temp[countPG].setCourseCode(courseCode);
			
					if (choose == 1)
					{
						temp[countPG].allocateUTM();
						temp[countPG].setUTMCountry(country);
						temp[countPG].setUTMState(state);
						temp[countPG].setUTMKolej(kolej);
						temp[countPG].setUTMBlock(block);
					}
					else if (choose == 2)
					{
						temp[countPG].allocateOutside();
						temp[countPG].setOutsideCountry(country);
						temp[countPG].setOutsideState(state);
						temp[countPG].setOutsideCity(city);
						temp[countPG].setOutsideAddress(address);
					}
		
					delete [] postgraduate;
			
					countPG++;
		
					postgraduate = temp;
				}
				catch (const char *msg)
				{
					postgraduate = new Student[1];
					
					postgraduate[0].setName(name);
					postgraduate[0].setMetric(metric);
					postgraduate[0].setCourseName(courseName);
					postgraduate[0].setCourseCode(courseCode);
				
					if (choose == 1)
					{
						postgraduate[0].allocateUTM();
						postgraduate[0].setUTMCountry(country);
						postgraduate[0].setUTMState(state);
						postgraduate[0].setUTMKolej(kolej);
						postgraduate[0].setUTMBlock(block);
					}
					else if (choose == 2)
					{
						postgraduate[0].allocateOutside();
						postgraduate[0].setOutsideCountry(country);
						postgraduate[0].setOutsideState(state);
						postgraduate[0].setOutsideCity(city);
						postgraduate[0].setOutsideAddress(address);
					}
					countPG++;
				}
			}
			cout << endl << endl << "Data Have been Succesfully read!" << endl;
		}
		catch (const char *error)
		{
			cout << error << endl;
		}
	}
	catch (const char *clear)
	{
		char choice;
		
		cout << clear << endl;
		cout << "Do you want to erase the data (y/n) : ";
		cin >> choice;
		
		if (choice == 'y')
		{
			countPG = 0;
			goto clear;
		}
	}
}

//============================================================//
//						readLecturer()						  //
//					Input  = *lecturer, countLecturer 		  //
//					Output = Reading New Input for Lecturer   //
//															  //
// This Function will read new entry for Lecturer.			  //
// It have a handle execption program to check wheter it's 	  //
// empty or have been filled already and to check whether the //
// program exist or not.									  //
//============================================================//

void readLecturer(Lecturer *&lecturer, int &countLecturer)
{
	string fileName; // Variable for File Name
	
	cin.ignore();
	cout << endl << endl;
	cout << "--==--==--==--==--==--==--==--==--" << endl;
	cout << "Reading New Lecturer Input" << endl;
	cout << "--==--==--==--==--==--==--==--==--" << endl << endl;
	
	cout << "Please be advised that the data follow this structure of data writing : " << endl << endl;
	
	cout << "NAME, COURSE NAME, COURSE CODE, OUTSIDE/INSIDE, COUNTRY/(IF INSIDE SKIP THIS), STATE/(IF INSIDE SKIP THIS), CITY/KOLEJ, ADDRESS/BLOCK" << endl << endl;
	
	cout << "Enter the name file you want to read from : ";
	getline(cin, fileName);
	
	clear :
	try
	{
		if (countLecturer != 0)
		{
			throw "There is data saved in the program right now!";
		}
		
		try
		{
			ifstream file (fileName.c_str());
		
			if (!file)
			{
				throw "Error! File unable to be Open!";
			}
			
			string choice; // Variable for Choice
			string name; // Temporary variable for Lecturer Name
			string courseName; // Temporary variable for Lecturer Course Name
			string courseCode; // Temporary variable for Lecturer Course Code
			string country; // Temporary variable for Lecturer Country
			string state; // Temporary variable for Lecturer State
			string kolej; // Temporary variable for Lecturer Kolej
			string block; // Temporary variable for Lecturer Block
			string city; // Temporary variable for Lecturer City
			string address; // Temporary variable for Lecturer Address
	
			while (getline(file, name, ','))
			{
				getline(file, courseName, ','); // Read Input for Course Name
				getline(file, courseCode, ','); // Read Input for Course Code
				getline(file, choice, ','); // Read Input to determine Choice
			
				int choose;
				if (choice == "Inside")
				{
					choose = 1;
				}
				else
				{
					choose = 2;
				}
				//================================//
				// This Switch statements will determine which data need to be added 
				// based on the choice what the user input. 
				//
				// If the data input 1 it will automatically set the Country to Malaysia
				// and the State to Johor Bahru.
				// If the user input 2 it will ask all of the data needed.
				//================================//
				switch (choose)
				{
					//==================//
					// Choice 1 is for the Lecturer who is staying inside UTM.
					// The Country will be automatically set to Malaysia and the 
					// state will be set to Johor Bahru, so the user will only need
					// to add the Kolej and Block data.
					//==================//
		
					case 1 :
					country = "Malaysia";
					state = "Johor Bahru";
				
					getline(file, kolej, ','); // Read Input for Kolej
					getline(file, block, '\n'); // Read Input for Block
					break;
				
					//==================//
					// Choice 2 is for the Lecturer who is staying Outside UTM.
					// The user will need to enter all of the required info from 
					// country up to their address all by themselves, as it is not
					// been set in the first time.
					//==================//
				
					case 2 :
					getline(file, country, ',');
					getline(file, state, ',');
					getline(file, city, ',');
					getline(file, address, '\n');
					break;
				}
	
				try
				{
					if (lecturer == 0)
					throw "Empty!";
			
					Lecturer *temp;
		
					temp = new Lecturer[countLecturer+1];
			
					for (int i = 0; i < countLecturer; i++)
					{
						temp[i] = lecturer[i];
					}
		
					temp[countLecturer].setName(name);
					temp[countLecturer].setCourseName(courseName);
					temp[countLecturer].setCourseCode(courseCode);
			
					if (choose == 1)
					{
						temp[countLecturer].allocateUTM();
						temp[countLecturer].setUTMCountry(country);
						temp[countLecturer].setUTMState(state);
						temp[countLecturer].setUTMKolej(kolej);
						temp[countLecturer].setUTMBlock(block);
					}
					else if (choose == 2)
					{
						temp[countLecturer].allocateOutside();
						temp[countLecturer].setOutsideCountry(country);
						temp[countLecturer].setOutsideState(state);
						temp[countLecturer].setOutsideCity(city);
						temp[countLecturer].setOutsideAddress(address);
					}
		
					delete [] lecturer;
			
					countLecturer++;
		
					lecturer = temp;
				}
				catch (const char *msg)
				{
					lecturer = new Lecturer[1];
					
					lecturer[0].setName(name);
					lecturer[0].setCourseName(courseName);
					lecturer[0].setCourseCode(courseCode);
				
					if (choose == 1)
					{
						lecturer[0].allocateUTM();
						lecturer[0].setUTMCountry(country);
						lecturer[0].setUTMState(state);
						lecturer[0].setUTMKolej(kolej);
						lecturer[0].setUTMBlock(block);
					}
					else if (choose == 2)
					{
						lecturer[0].allocateOutside();
						lecturer[0].setOutsideCountry(country);
						lecturer[0].setOutsideState(state);
						lecturer[0].setOutsideCity(city);
						lecturer[0].setOutsideAddress(address);
					}
					countLecturer++;
				}
			}
			cout << endl << endl << "Data Have been Succesfully read!" << endl;
		}
		catch (const char *error)
		{
			cout << error << endl;
		}
	}
	catch (const char *clear)
	{
		char choice;
		
		cout << clear << endl;
		cout << "Do you want to erase the data (y/n) : ";
		cin >> choice;
		
		if (choice == 'y')
		{
			countLecturer = 0;
			goto clear;
		}
	}
}

//============================================================//
//						readStaff()							  //
//					Input  = *staff, countStaff 		  	  //
//					Output = Reading New Input for Staff      //
//															  //
// This Function will read new entry for Staff.				  //
// It have a handle execption program to check wheter it's 	  //
// empty or have been filled already and to check whether the //
// program exist or not.									  //
//============================================================//

void readStaff(Staff *&staff, int &countStaff)
{
	string fileName; // Variable for File Name
	
	cin.ignore();
	cout << endl << endl;
	cout << "--==--==--==--==--==--==--==--==--" << endl;
	cout << "Reading New Staff Input" << endl;
	cout << "--==--==--==--==--==--==--==--==--" << endl << endl;
	
	cout << "Please be advised that the data follow this structure of data writing : " << endl << endl;
	
	cout << "NAME, DEPARTMENT, OUTSIDE/INSIDE, COUNTRY/(IF INSIDE SKIP THIS), STATE/(IF INSIDE SKIP THIS), CITY/KOLEJ, ADDRESS/BLOCK" << endl << endl;
	
	cout << "Enter the name file you want to read from : ";
	getline(cin, fileName);
	
	clear :
	try
	{
		if (countStaff != 0)
		{
			throw "There is data saved in the program right now!";
		}
		
		try
		{
			ifstream file (fileName.c_str());
		
			if (!file)
			{
				throw "Error! File unable to be Open!";
			}
			
			string choice; // Variable for Choice
			string name; // Temporary variable for Staff Name
			string department; // Temporary variable for Staff Department
			string country; // Temporary variable for Staff Country
			string state; // Temporary variable for Staff State
			string kolej; // Temporary variable for Staff Kolej
			string block; // Temporary variable for Staff Block
			string city; // Temporary variable for Staff City
			string address; // Temporary variable for Staff Address
	
			while (getline(file, name, ','))
			{
				getline(file, department, ','); // Read Input for Department
				getline(file, choice, ','); // Read Input to determine Choice
			
				int choose;
				if (choice == "Inside")
				{
					choose = 1;
				}
				else
				{
					choose = 2;
				}
				//================================//
				// This Switch statements will determine which data need to be added 
				// based on the choice what the user input. 
				//
				// If the data input 1 it will automatically set the Country to Malaysia
				// and the State to Johor Bahru.
				// If the user input 2 it will ask all of the data needed.
				//================================//
				switch (choose)
				{
					//==================//
					// Choice 1 is for the Staff who is staying inside UTM.
					// The Country will be automatically set to Malaysia and the 
					// state will be set to Johor Bahru, so the user will only need
					// to add the Kolej and Block data.
					//==================//
		
					case 1 :
					country = "Malaysia";
					state = "Johor Bahru";
				
					getline(file, kolej, ','); // Read Input for Kolej
					getline(file, block, '\n'); // Read Input for Block
					break;
				
					//==================//
					// Choice 2 is for the Staff who is staying Outside UTM.
					// The user will need to enter all of the required info from 
					// country up to their address all by themselves, as it is not
					// been set in the first time.
					//==================//
				
					case 2 :
					getline(file, country, ',');
					getline(file, state, ',');
					getline(file, city, ',');
					getline(file, address, '\n');
					break;
				}
	
				try
				{
					if (staff == 0)
					throw "Empty!";
			
					Staff *temp;
		
					temp = new Staff[countStaff+1];
			
					for (int i = 0; i < countStaff; i++)
					{
						temp[i] = staff[i];
					}
		
					temp[countStaff].setName(name);
					temp[countStaff].setDepartment(department);
			
					if (choose == 1)
					{
						temp[countStaff].allocateUTM();
						temp[countStaff].setUTMCountry(country);
						temp[countStaff].setUTMState(state);
						temp[countStaff].setUTMKolej(kolej);
						temp[countStaff].setUTMBlock(block);
					}
					else if (choose == 2)
					{
						temp[countStaff].allocateOutside();
						temp[countStaff].setOutsideCountry(country);
						temp[countStaff].setOutsideState(state);
						temp[countStaff].setOutsideCity(city);
						temp[countStaff].setOutsideAddress(address);
					}
		
					delete [] staff;
			
					countStaff++;
		
					staff = temp;
				}
				catch (const char *msg)
				{
					staff = new Staff[1];
					
					staff[0].setName(name);
					staff[0].setDepartment(department);
				
					if (choose == 1)
					{
						staff[0].allocateUTM();
						staff[0].setUTMCountry(country);
						staff[0].setUTMState(state);
						staff[0].setUTMKolej(kolej);
						staff[0].setUTMBlock(block);
					}
					else if (choose == 2)
					{
						staff[0].allocateOutside();
						staff[0].setOutsideCountry(country);
						staff[0].setOutsideState(state);
						staff[0].setOutsideCity(city);
						staff[0].setOutsideAddress(address);
					}
					countStaff++;
				}
			}
			cout << endl << endl << "Data Have been Succesfully read!" << endl;
		}
		catch (const char *error)
		{
			cout << error << endl;
		}
	}
	catch (const char *clear)
	{
		char choice;
		
		cout << clear << endl;
		cout << "Do you want to erase the data (y/n) : ";
		cin >> choice;
		
		if (choice == 'y')
		{
			countStaff = 0;
			goto clear;
		}
	}
}

//============================================================//
//						saveUndergraduate()					  //
//					Input  = *undergraduate, countUG	      //
//					Output = Reading New Input for UG         //
//															  //
// This Function will write entry for UG that have been stored//
// in the program.											  //
// It have a handle execption program to check wheter it's 	  //
// empty or have been filled already						  //									  //
//============================================================//


void saveUndergraduate(Student *undergraduate, int countUG)
{
	string fileName; // Variable for File Name
	
	cin.ignore();
	cout << endl << endl;
	cout << "--==--==--==--==--==--==--==--==--" << endl;
	cout << "Saving Undergraduate Data" << endl;
	cout << "--==--==--==--==--==--==--==--==--" << endl << endl;
	
	cout << "Enter the name file you want to save to (with .txt) : ";
	getline(cin, fileName);
	
	try
	{
		if (countUG == 0)
		throw "There is no Input!";
		
		ofstream out (fileName.c_str());
		
		for (int i = 0; i < countUG; i -= -1)
		{
			out << undergraduate[i].getName() << ",";
			out << undergraduate[i].getMetric() << ",";
			out << undergraduate[i].getCourseName() << ",";
			out << undergraduate[i].getCourseCode() << ",";
			
			if (undergraduate[i].checkInside())
			{
				out << "Inside,";
				out << undergraduate[i].getUTMCountry() << ",";
				out << undergraduate[i].getUTMState() << ",";
				out << undergraduate[i].getUTMKolej() << ",";
				out << undergraduate[i].getUTMBlock() << endl;
			}
			else
			{
				out << "Outside,";
				out << undergraduate[i].getOutsideCountry() << ",";
				out << undergraduate[i].getOutsideState() << ",";
				out << undergraduate[i].getOutsideCity() << ",";
				out << undergraduate[i].getOutsideAddress() << endl;
			}
		}
	}
	catch (const char *error)
	{
		cout << error << endl;
	}
}

//============================================================//
//						savePostgraduate()					  //
//					Input  = *postgraduate, countPG	  	      //
//					Output = Reading New Input for PG         //
//															  //
// This Function will write entry for PG that have been stored//
// in the program.											  //
// It have a handle execption program to check wheter it's 	  //
// empty or have been filled already						  //									  //
//============================================================//


void savePostgraduate(Student *postgraduate, int countPG)
{
	string fileName; // Variable for File Name
	
	cin.ignore();
	cout << endl << endl;
	cout << "--==--==--==--==--==--==--==--==--" << endl;
	cout << "Saving Postgraduate Data" << endl;
	cout << "--==--==--==--==--==--==--==--==--" << endl << endl;
	
	cout << "Enter the name file you want to save to (with .txt) : ";
	getline(cin, fileName);
	
	try
	{
		if (countPG == 0)
		throw "There is no Input!";
		
		ofstream out (fileName.c_str());
		
		for (int i = 0; i < countPG; i -= -1)
		{
			out << postgraduate[i].getName() << ",";
			out << postgraduate[i].getMetric() << ",";
			out << postgraduate[i].getCourseName() << ",";
			out << postgraduate[i].getCourseCode() << ",";
			
			if (postgraduate[i].checkInside())
			{
				out << "Inside,";
				out << postgraduate[i].getUTMCountry() << ",";
				out << postgraduate[i].getUTMState() << ",";
				out << postgraduate[i].getUTMKolej() << ",";
				out << postgraduate[i].getUTMBlock() << endl;
			}
			else
			{
				out << "Outside,";
				out << postgraduate[i].getOutsideCountry() << ",";
				out << postgraduate[i].getOutsideState() << ",";
				out << postgraduate[i].getOutsideCity() << ",";
				out << postgraduate[i].getOutsideAddress() << endl;
			}
		}
	}
	catch (const char *error)
	{
		cout << error << endl;
	}
}

//============================================================//
//						saveLecturer()					  	  //
//					Input  = *lecturer, countLecturer  	      //
//					Output = Reading New Input for Lecturer   //
//															  //
// This Function will write entry for Lecturer that have been //
// stored in the program.									  //
// It have a handle execption program to check wheter it's 	  //
// empty or have been filled already						  //									  //
//============================================================//


void saveLecturer(Lecturer *lecturer, int countLecturer)
{
	string fileName; // Variable for File Name
	
	cin.ignore();
	cout << endl << endl;
	cout << "--==--==--==--==--==--==--==--==--" << endl;
	cout << "Saving Lecturer Data" << endl;
	cout << "--==--==--==--==--==--==--==--==--" << endl << endl;
	
	cout << "Enter the name file you want to save to (with .txt) : ";
	getline(cin, fileName);
	
	try
	{
		if (countLecturer == 0)
		throw "There is no Input!";
		
		ofstream out (fileName.c_str());
		
		for (int i = 0; i < countLecturer; i -= -1)
		{
			out << lecturer[i].getName() << ",";
			out << lecturer[i].getCourseName() << ",";
			out << lecturer[i].getCourseCode() << ",";
			
			if (lecturer[i].checkInside())
			{
				out << "Inside,";
				out << lecturer[i].getUTMCountry() << ",";
				out << lecturer[i].getUTMState() << ",";
				out << lecturer[i].getUTMKolej() << ",";
				out << lecturer[i].getUTMBlock() << endl;
			}
			else
			{
				out << "Outside,";
				out << lecturer[i].getOutsideCountry() << ",";
				out << lecturer[i].getOutsideState() << ",";
				out << lecturer[i].getOutsideCity() << ",";
				out << lecturer[i].getOutsideAddress() << endl;
			}
		}
	}
	catch (const char *error)
	{
		cout << error << endl;
	}
}

//============================================================//
//						saveStaff()						  	  //
//					Input  = *staff, countStaff  		      //
//					Output = Reading New Input for Lecturer   //
//															  //
// This Function will write entry for Staff that have been	  //
// stored in the program.									  //
// It have a handle execption program to check wheter it's 	  //
// empty or have been filled already						  //									  //
//============================================================//


void saveStaff(Staff *staff, int countStaff)
{
	string fileName; // Variable for File Name
	
	cin.ignore();
	cout << endl << endl;
	cout << "--==--==--==--==--==--==--==--==--" << endl;
	cout << "Saving Staff Data" << endl;
	cout << "--==--==--==--==--==--==--==--==--" << endl << endl;
	
	cout << "Enter the name file you want to save to (with .txt) : ";
	getline(cin, fileName);
	
	try
	{
		if (countStaff == 0)
		throw "There is no Input!";
		
		ofstream out (fileName.c_str());
		
		for (int i = 0; i < countStaff; i -= -1)
		{
			out << staff[i].getName() << ",";
			out << staff[i].getDepartment() << ",";
			
			if (staff[i].checkInside())
			{
				out << "Inside,";
				out << staff[i].getUTMCountry() << ",";
				out << staff[i].getUTMState() << ",";
				out << staff[i].getUTMKolej() << ",";
				out << staff[i].getUTMBlock() << endl;
			}
			else
			{
				out << "Outside,";
				out << staff[i].getOutsideCountry() << ",";
				out << staff[i].getOutsideState() << ",";
				out << staff[i].getOutsideCity() << ",";
				out << staff[i].getOutsideAddress() << endl;
			}
		}
	}
	catch (const char *error)
	{
		cout << error << endl;
	}
}

	//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
	//															  //
	//						MAIN FUNCTION						  //
	//															  //
	//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//

int main ()
{
	int choice, choiceAdd, choiceDelete, choiceDisplay, choiceRead, choiceSave; // Variable for Choice
	
	Student *undergraduate = 0; // Pointer Variable for Undergraduate and make it point to NULL
	Student *postgraduate = 0; // Pointer Variable for Postgraduate and make it point to NULL
	Lecturer *lecturer = 0; // Pointer Variable for Lecturer and make it point to NULL
	Staff *staff = 0; // Pointer Variable for Staff and make it point to NULL
	
	int countUG = 0; // Counter for Undergraduate
	int countPG = 0; // Counter for Postgraduate
	int countLecturer = 0; // Counter for Lecturer
	int countStaff = 0; // Counter for Staff
	
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
				cout << "3> ADD LECTURER" << endl;
				cout << "4> ADD STAFF" << endl;
				
				cout << endl << "Choose what data you want to Add : ";
				cin >> choiceAdd;
				
				//============================================================//
				//		       			ChoiceAdd  							  //
				// The ChoiceAdd will determine which data to be added based  //
				// on the menu they chosen			 						  //
				//============================================================//
				
				switch (choiceAdd)
				{
					case 1 :
						addUndergraduate(undergraduate, countUG); // Function to add Undergraduate Data
						break;
					case 2 :
						addPostgraduate(postgraduate, countPG); // Function to add Postgraduate Data
						break;
					case 3 :
						addLecturer(lecturer, countLecturer); // Function to add Lecturer Data
						break;
					case 4 :
						addStaff(staff, countStaff); // Function to add Staff Data
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
				cout << "3> DELETE LECTURER" << endl;
				cout << "4> DELETE STAFF" << endl;
				
				cout << endl << "Choose what data you want to Delete : ";
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
					case 3 :
						cout << "DELETE LECTURER DONE!!!" << endl;
						// deleteLecturer();
						// Function Object to delete Lecturer
						break;
					case 4 :
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
				cout << "3> DISPLAY LECTURER" << endl;
				cout << "4> DISPLAY STAFF" << endl;
				
				cout << endl << "Choose what data you want to Display : ";
				cin >> choiceDisplay;
				
				//============================================================//
				//		       			choiceDisplaly						  //
				// The choiceDisplaly will determine which data to be 	      //
				// displayed based on the menu they chosen			 		  //
				//============================================================//
				
				switch (choiceDisplay)
				{
					case 1 :
						displayUndergraduate(undergraduate, countUG); // Display the list of Undergraduate 
						break;
					case 2 :
						displayPostgraduate(postgraduate, countPG); // Display the list of Postgraduate
						break;
					case 3 :
						displayLecturer(lecturer, countLecturer); // Display the list of Lecturer
						break;
					case 4 :
						displayStaff(staff, countStaff); // Display the list of Staff
						break;
					default :
						cout << "Input Not Recognized!!!!" << endl;
						break;
				}
				cout << endl;
				system("pause");
				break;
				
			//============================================================//
			//			Choice 4 = SEARCH DATA							  //
			// This will search the string that the user desired to search//
			// in this program.   										  //
			//============================================================//
				
			case 4 : 
				searchData(countUG, countPG, countLecturer, countStaff, undergraduate, postgraduate, lecturer, staff); // Calling Function searchData
				system("pause");
				break;
				
			//============================================================//
			//			Choice 5 = READ DATA							  //
			// This will read the data and stored it in the program.      //
			//============================================================//
				
			case 5 : 
				cout <<"=-=-=-=-=-=-=-" << endl;
				cout << "READ DATA" << endl << endl;
				cout <<"=-=-=-=-=-=-=-" << endl << endl;
				
				cout << "1> READ UNDERGRADUATE" << endl;
				cout << "2> READ POSTGRADUATE" << endl;
				cout << "3> READ LECTURER" << endl;
				cout << "4> READ STAFF" << endl;
				
				cout << endl << "Choose what data you want to Read : ";
				cin >> choiceRead;
				
				//============================================================//
				//		       			choiceRead   						  //
				// The choiceDisplaly will determine which data to be 	      //
				// read based on the menu they chosen	  			 		  //
				//============================================================//
				
				switch (choiceRead)
				{
					case 1 :
						readUndergraduate(undergraduate, countUG); // Read the list of Undergraduate 
						break;
					case 2 :
						readPostgraduate(postgraduate, countPG); // Read the list of Postgraduate
						break;
					case 3 :
						readLecturer(lecturer, countLecturer); // Read the list of Lecturer
						break;
					case 4 :
						readStaff(staff, countStaff); // Read the list of Staff
						break;
					default :
						cout << "Input Not Recognized!!!!" << endl;
						break;
				}
				cout << endl;
				system("pause");
				break;
			
			//============================================================//
			//			Choice 6 = SAVE DATA							  //
			// This will save the data that is stored in the program.     //
			//============================================================//
				
			case 6 : 
				cout <<"=-=-=-=-=-=-=-" << endl;
				cout << "SAVE DATA" << endl << endl;
				cout <<"=-=-=-=-=-=-=-" << endl << endl;
				
				cout << "1> SAVE UNDERGRADUATE" << endl;
				cout << "2> SAVE POSTGRADUATE" << endl;
				cout << "3> SAVE LECTURER" << endl;
				cout << "4> SAVE STAFF" << endl;
				
				cout << endl << "Choose what data you want to Save : ";
				cin >> choiceSave;
				
				//============================================================//
				//		       			choiceSave							  //
				// The choiceDisplaly will determine which data to be 	      //
				// saved based on the menu they chosen				 		  //
				//============================================================//
				
				switch (choiceSave)
				{
					case 1 :
						saveUndergraduate(undergraduate, countUG); // Save the list of Undergraduate 
						break;
					case 2 :
						savePostgraduate(postgraduate, countPG); // Save the list of Postgraduate
						break;
					case 3 :
						//saveLecturer(lecturer, countLecturer); // Save the list of Lecturer
						break;
					case 4 :
						//saveStaff(staff, countStaff); // Save the list of Staff
						break;
					default :
						cout << "Input Not Recognized!!!!" << endl;
						break;
				}
				cout << endl;
				system("pause");
				break;
								
			//============================================================//
			//			Choice 7 = EXIT PROGRAM							  //
			// This will exit the program								  //
			//============================================================//
				
			case 7 : 
				cout << "Exiting Program...." << endl;
				cout << "Thanks for using our Program ^_^" << endl;
				break;
			
			default :
				cout << "Input Not Recognized!!!" << endl;
				system("pause");
				break;
		}
	} while (choice != 7); ;// This argument check wheter the choice is 4 (exit) or not
	
	return 0;
}

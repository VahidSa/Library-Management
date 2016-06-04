#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
class address {
private:
	char city[33];
	char street[33];
	char ave[33];
	int pelak;
	long int postal_code;
public:
	virtual void scan_address(void) {
		cout << "please Enter the name of the city : " << endl;
		cin >> this->city;
		cout << "please Enter the name of the street : " << endl;
		cin >> this->street;
		cout << "please Enter the namer of the avenue : " << endl;
		cin >> this->ave;
		cout << "please Enter the pelak of the house : " << endl;
		cin >> this->pelak;
		cout << "please Enter the postal code : " << endl;
		cin >> this->postal_code;
	}
	virtual void print_address(void) {
		cout << "the city of the exact person is equal with : " << endl;
		cout << this->city;
		cout << "the street of the exact person is equal with : " << endl;
		cout << this->street;
		cout << "the avenue of the exact person is equal with : " << endl;
		cout << this->ave;
		cout << "the pelak of the house is equal with : " << endl;
		cout << this->pelak;
		cout << "the postal code of the house is equal with : " << endl;
		cout << this->postal_code;
	}
};
class person {
public:
	int birth_Day;
	int birth_month;
	int birth_year;
	string first_name;
	string last_name;
	long int personal_code;
	friend void print_person(person);
	virtual void show_person(void) {
		cout << "the birth day of the person is equal with : " << endl;
		cout << this->birth_Day;
		cout << "the birth month of the person is equal with : " << endl;
		cout << this->birth_month;
		cout << "the birth year of the person is equal with : " << endl;
		cout << this->birth_year;
		cout << "the personal code of the person is equal with : " << endl;
		cout << this->personal_code;
		cout << "the full name of the person is equal with : " << endl;
		cout << this->first_name << "   " << this->last_name;
	}
	virtual void scan_person(void) {
		cout << "please Enter the first name of the person : " << endl;
		cin >> this->first_name;
		cout << "please Enter the last name of the person : " << endl;
		cin >> this->last_name;
		cout << "please Enter the birth day of the person : " << endl;
		cin >> this->birth_Day;
		cout << "please Enter the birth month of the person : " << endl;
		cin >> this->birth_month;
		cout << "pleasd Enter the birth year of the person : " << endl;
		cin >> this->birth_year;
		cout << "please Enter the personal code of the person :  " << endl;
		cin >> this->personal_code;
	}

};
class worker :public person, public address {
private:
	string job;
	long int salery;
public:
	virtual void scan_address(void) {
		address::scan_address();
	}
	virtual void print_address(void) {
		address::print_address();
	}
	virtual void scan_person(void) {
		person::scan_person();
		cout << "please Enter the job of the exact person : " << endl;
		cin >> this->job;
		cout << "please Enter the salery of the exact person : " << endl;
		cin >> this->salery;
	}
	virtual void show_person(void) {
		person::show_person();
		cout << "the job of the exact person is equal with : " << endl;
		cout << this->job << endl;
		cout << "the salery of the exact person is equal with : " << endl;
		cout << this->salery << endl;
	}
	worker &operator=(const worker &w){
		first_name = w.first_name;
		last_name = w.last_name;
		personal_code = w.personal_code;
		job = w.job;
		salery = w.salery;
		return *this;
	}
};
class workers {
private :
	int plenty_worker=0;
	int n;
	worker karmand;
	vector <worker> karmandan;
public :
	worker &operator[](const int index){
		for(int i=0; i<plenty_worker;i++)
			if(index == karmandan[i].personal_code)
				return karmandan[i];
	}
	void Edit(void) {
	  string Fname;
	  string Lname;
	  int serial;
	  int i;
	  cout << "if you want to Edit by serial Enter <1> or by name Enter <2> : " << endl;
	  int e;
	  cin >> e;
	  if (e != 1 || e != 2) {
	    do {
	      cout << "the number that you Entered is irrelevant please try again : " << endl;
	      cin >> e;
	    } while (e != 1 || e != 2);
	  }
	  if (e == 2) {
	    cout << "please Enter the first name of that you want to Edit for it : " << endl;
	    cin >> Fname;
	    cout << "please Enter the first name of that you want to Edit for it : " << endl;
	    cin >> Lname;
	    for (i = 0;i < plenty_worker;i++)
	      if (karmandan[i].first_name == Fname)
	        if(karmandan[i].last_name == Lname)
	          karmandan[i].worker::scan_person();
	    if(i==plenty_worker && karmandan[i].last_name != Lname)
	      cout << "this wasn't in the directory" << endl;
	  }
	  if (e == 1) {
	    cout << "please Enter the serial number of that you want to Edit it : " << endl;
	    cin >> serial;
	    for (i = 0;i < plenty_worker;i++)
	      if (karmandan[i].personal_code == serial)
	          karmandan[i].worker::scan_person();
	    if(i==plenty_worker && karmandan[i].personal_code != serial)
	      cout << "this wasn't in the directory" << endl;
	  }
	 }
	  void Delete(void) {
	    string name;
	    string Fname;
	    string Lname;
	    int i;
	    cout << "please Enter the first name of that you want to Delete  it : " << endl;
	    cin >> Fname;
	    cout << "please Enter the last name of that you want to Delete  it : " << endl;
	    cin >> Fname;
	    for (i = 0;i < plenty_worker;i++)
	      if (karmandan[i].first_name == Fname)
	        if(karmandan[i].last_name == Lname)
	          karmandan.erase(karmandan.begin()+i);
	    if(i==plenty_worker && karmandan[i].last_name != Lname)
	      cout << "this wasn't in the directory" << endl;
	  }
	void scan_workers(void) {
		cout << "please Enter the plenty of the workers : " << endl;
		cin >> n;
		for (int i = 0;i < n;i++) {
			karmandan.push_back(karmand);
			karmandan[i+plenty_worker].worker::scan_person();
		}
		plenty_worker += n;
		cout << "the information of the workers have been successfuly Entered." << endl;
	}
	void print_workers(void) {
		cout << "the plenty of the workers is equal with : " << endl;
		cout << this->plenty_worker;
		cout << "the information's are equal with : " << endl;
		for (int i = 0;i < this->plenty_worker;i++) {
			cout << "the info of the " << i + 1 << " worker is equal with : " << endl;
			karmandan[i].worker::show_person();
			karmandan[i].worker::print_address();
		}
		cout << "the information's have been successfuly Entered." << endl;
	}
	bool Search_Workers(void){
		bool check = false;
		string name;
		string Fname;
		string Lname;
		long int serial;
		cout << "if you want to search by serial Enter <1> or by name Enter <2> : " << endl;
		int e;
		cin >> e;
		if (e != 1 || e != 2) {
			do {
				cout << "the number that you Entered is irrelevant please try again : ";
				cin >> e;
			} while (e != 1 || e != 2);
		}
		if (e == 2) {
			cout << "please Enter the first name of that you want to search for it : ";
			cin >> Fname;
			cout << "please Enter the first name of that you want to search for it : ";
			cin >> Lname;
			for (int i = 0;i < plenty_worker;i++) {
				if (karmandan[i].first_name == Fname)
					if(karmandan[i].last_name == Lname)
						return true;
			}
			return true;
		}
		if (e == 1) {
			cout << "please Enter the serial number of that you want to search : " << endl;
			cin >> serial;
			for (int i = 0;i < plenty_worker;i++) {
				if (karmandan[i].personal_code == serial) {
					check = true;
					return check;
				}
			}
			return check;
		}
		return check;
	}

};
class member :public person, public address {
private:
	string type;
	string licence;
	int time;
public:
	virtual void scan_address(void) {
		address::scan_address();
	}
	virtual void print_address(void) {
		address::print_address();
	}
	virtual void scan_person(void) {
		person::scan_person();
		cout << "please Enter the type of the membership of the exact person : " << endl;
		cin >> this->type;
		cout << "please Enter the licence of the exact person : " << endl;
		cin >> this->licence;
		cout << "please Enter the lenght of the membership of the exact person : " << endl;
		cin >> this->time;
	}
	virtual void show_person(void) {
		person::show_person();
		cout << "the type of the member ship of the exact person is equal with : " << endl;
		cout << this->type;
		cout << "the licence of the exact person is equal with : " << endl;
		cout << this->licence;
		cout << "the length of the membership of the exact person is equal with : " << endl;
		cout << this->time;
	}
	member &operator=(const member &m){
		first_name = m.first_name;
		last_name = m.last_name;
		personal_code = m.personal_code;
		type = m.type;
		licence = m.licence;
		return *this;
	}
};
class Members {
private :
	member ozv;
	vector <member> ozvha;
	int plenty_members;
	int n;
public :
	member &operator[](const int index){
		for(int i=0; i<plenty_members;i++)
			if(index == ozvha[i].personal_code)
				return ozvha[i];
	}
	void Edit(void) {
		string Fname;
		string Lname;
		int serial;
		int i;
		cout << "if you want to Edit by serial Enter <1> or by name Enter <2> : " << endl;
		int e;
		cin >> e;
		if (e != 1 || e != 2) {
			do {
				cout << "the number that you Entered is irrelevant please try again : " << endl;
				cin >> e;
			} while (e != 1 || e != 2);
		}
		if (e == 2) {
			cout << "please Enter the first name of that you want to Edit for it : " << endl;
			cin >> Fname;
			cout << "please Enter the first name of that you want to Edit for it : " << endl;
			cin >> Lname;
			for (i = 0;i < plenty_members;i++)
				if (ozvha[i].first_name == Fname)
					if(ozvha[i].last_name == Lname)
						ozvha[i].member::scan_person();
			if(i==plenty_members && ozvha[i].last_name != Lname)
				cout << "this wasn't in the directory" << endl;
		}
		if (e == 1) {
		  cout << "please Enter the serial number of that you want to Edit it : " << endl;
		  cin >> serial;
		  for (int i = 0;i < plenty_members;i++)
		    if (ozvha[i].personal_code == serial)
		        ozvha[i].member::scan_person();
		  if(i==plenty_members && ozvha[i].personal_code != serial)
		    cout << "this wasn't in the directory" << endl;
		}
	}
		void Delete(void) {
			string name;
			string Fname;
			string Lname;
			int i;
			cout << "please Enter the nFirst ame of that you want to Delete  it : " << endl;
			cin >> Fname;
			cout << "please Enter the Last name of that you want to Delete  it : " << endl;
			cin >> Lname;
			for (i = 0;i < plenty_members;i++)
				if (ozvha[i].first_name == Fname)
					if(ozvha[i].last_name == Lname)
						ozvha.erase(ozvha.begin()+i);
			if(i==plenty_members && ozvha[i].last_name != Lname)
				cout << "this wasn't in the directory" << endl;
		}
	void scan_members(void) {
		cout << "please Enter the plenty of the member's that you want to Enter : " << endl;
		cin >> n;
		for (int i = 0;i < n;i++) {
			cout << "please Enter the informatin about the " << plenty_members + 1 << " member : " << endl;
			ozvha.push_back(ozv);
			ozvha[plenty_members+i].member::scan_person();
			ozvha[plenty_members+i].member::scan_address();
		}
		plenty_members += n;
		cout << "the information's have been successfuly scanned." << endl;
	}
	void print_members(void) {
		cout << "the plenty of the member is equal with : " << endl;
		cout << this->plenty_members;
		cout << "the information about the members is equal with : " << endl;
		for (int i = 0;i < this->plenty_members;i++) {
			cout << "the info about the " << i + 1 << " member is equal whith : " << endl;
			ozvha[i].member::show_person();
			ozvha[i].member::print_address();
		}
		cout << "the information's haven successfuly printed." << endl;
	}
	bool Search_members(void){
		bool check = false;
		string Fname;
		string Lname;
		long int serial;
		cout << "if you want to search by serial Enter <1> or by name Enter <2> : " << endl;
		int e;
		cin >> e;
		if (e != 1 || e != 2) {
			do {
				cout << "the number that you Entered is irrelevant please try again : ";
				cin >> e;
			} while (e != 1 || e != 2);
		}
		if (e == 2) {
			cout << "please Enter the first name of that you want to search for it : ";
			cin >> Fname;
			cout << "please Enter the first name of that you want to search for it : ";
			cin >> Lname;
			for (int i = 0;i < plenty_members;i++) {
				if (ozvha[i].first_name == Fname)
					if(ozvha[i].last_name == Lname)
						return true;
			}
			return true;
		}
		if (e == 1) {
			cout << "please Enter the serial number of that you want to search it: " << endl;
			cin >> serial;
			for (int i = 0;i < plenty_members;i++) {
				if (ozvha[i].personal_code == serial) {
					check = true;
					return check;
				}
			}
			return check;
		}
	return check;
	}
};
class Booker :public person, public address {
private:
	long int salery;
public:
	virtual void scan_address(void) {
		address::scan_address();
	}
	virtual void print_address(void) {
		address::print_address();
	}
	virtual void scan_person(void) {
		person::scan_person();
		cout << "please Enter the salery of the exact person : " << endl;
		cin >> this->salery;
	}
	virtual void show_person(void) {
		person::show_person();
		cout << "the salery of the exact person is equal with : " << endl;
		cout << this->salery << endl;
	}

	Booker &operator=(const Booker &b){
		first_name = b.first_name;
		last_name = b.last_name;
		personal_code = b.personal_code;
		salery = b.salery;
		return *this;
	}
};
class Bookers {
private :
	Booker ketabdar;
	vector <Booker> bos;
	int plenty_bookers;
	int n;
public :
	Booker &operator[](const int index){
		for(int i=0; i<plenty_bookers;i++)
			if(index == bos[i].personal_code)
				return bos[i];
	}
	void Edit(void) {
	  string Fname;
	  string Lname;
	  int serial;
	  int i;
	  cout << "if you want to Edit by serial Enter <1> or by name Enter <2> : " << endl;
	  int e;
	  cin >> e;
	  if (e != 1 || e != 2) {
	    do {
	      cout << "the number that you Entered is irrelevant please try again : " << endl;
	      cin >> e;
	    } while (e != 1 || e != 2);
	  }
	  if (e == 2) {
	    cout << "please Enter the first name of that you want to Edit for it : " << endl;
	    cin >> Fname;
	    cout << "please Enter the first name of that you want to Edit for it : " << endl;
	    cin >> Lname;
	    for ( i = 0;i < plenty_bookers;i++)
	      if (bos[i].first_name == Fname)
	        if(bos[i].last_name == Lname)
	          bos[i].Booker::scan_person();
	    if(i==plenty_bookers && bos[i].last_name != Lname)
	      cout << "this wasn't in the directory" << endl;
	  }
	  if (e == 1) {
	    cout << "please Enter the serial number of that you want to Edit it : " << endl;
	    cin >> serial;
	    for (i = 0;i < plenty_bookers;i++)
	      if (bos[i].personal_code == serial)
	          bos[i].Booker::scan_person();
	    if(i==plenty_bookers && bos[i].personal_code != serial)
	      cout << "this wasn't in the directory" << endl;
	  }
	 }
	  void Delete(void) {
	    string name;
	    string Fname;
	    string Lname;
	    int i;
	    cout << "please Enter the first name of that you want to Delete  it : " << endl;
	    cin >> Fname;
	    cout << "please Enter the last name of that you want to Delete  it : " << endl;
	    cin >> Lname;
	    for (i = 0;i < plenty_bookers;i++)
	      if (bos[i].first_name == Fname)
	        if(bos[i].last_name == Lname)
	          bos.erase(bos.begin()+i);
	    if(i==plenty_bookers && bos[i].last_name != Lname)
	      cout << "this wasn't in the directory" << endl;
	  }
	void scan_bookers(void) {
		cout << "please Enter the information's about the booker's : " << endl;
		cin >> n;
		for (int i = 0;i < n;i++) {
			cout << "please Enter the informatin about the " << plenty_bookers + 1 << " Booker : " << endl;
			bos.push_back(ketabdar);
			bos[plenty_bookers+i].Booker::scan_person();
			bos[plenty_bookers+i].Booker::scan_address();
		}
		plenty_bookers += n;
		cout << "you have successfuly Entered the information's of the bookers." << endl;
	}
	void print_bookers(void) {
		cout << "the plenty of  the bookers in the exact library is equal with : " << endl;
		cout << this->plenty_bookers;
		for (int i;i < this->plenty_bookers;i++) {
			cout << "the information's about the " << i + 1 << " booker is equal with : " << endl;
			bos[i].Booker::show_person();
			bos[i].Booker::print_address();
		}
		cout << "the information about the booker's have been printed successfuly." << endl;
	}
	bool Search_Bookers(void){
		bool check = false;
		string Fname;
		string Lname;
		long int serial;
		cout << "if you want to search by serial Enter <1> or by name Enter <2> : " << endl;
		int e;
		cin >> e;
		if (e != 1 || e != 2) {
			do {
				cout << "the number that you Entered is irrelevant please try again : ";
				cin >> e;
			} while (e != 1 || e != 2);
		}
		if (e == 2) {
			cout << "please Enter the first name of that you want to search for it : ";
			cin >> Fname;
			cout << "please Enter the first name of that you want to search for it : ";
			cin >> Lname;
			for (int i = 0;i < plenty_bookers;i++) {
				if (bos[i].first_name == Fname)
					if(bos[i].last_name == Lname)
						return true;
			}
			return true;
		}
		if (e == 1) {
			cout << "please Enter the serial number of that you want to search it: " << endl;
			cin >> serial;
			for (int i = 0;i < plenty_bookers;i++) {
				if (bos[i].personal_code == serial) {
					check = true;
					return check;
				}
			}
			return false;
		}
	return check;
	}
};
class Object {
public:
	string Name;
	double price;
	bool barrow = false;
	virtual void Scanf_obj() {
		cout << "Enter Name: ";
		cin >> this->Name;
		cout << "Enter price: ";
		cin >> this->price;
		//	cout<<"Enter Date of publish: ";
		//	cin>>this->ta;
	}
	virtual void Show_obj() {
		cout << "Name: " << this->Name << endl;
		cout << "Price: " << this->price << endl;
		//	cout<<"Date of publish: "<<this->ta;
	}
	//virtual bool barrow(char*) = 0;
};
class Book : public Object {
public:
	long int BookISBN;
	string BookWriter;	//string
	virtual void Scanf_obj() {
		Object::Scanf_obj();
		cout << "Enter ISBN: ";
		cin >> this->BookISBN;
		cout << "Enter Name of BookWriter: ";
		cin >> this->BookWriter;
	}
	virtual void Show_obj() {
		Object::Show_obj();
		cout << "ISBN: " << this->BookISBN << endl;
		cout << "Name of BookWriter: " << this->BookWriter << endl;
	}
	Book &operator=(const Book &b) {
		Name = b.Name;
		this->price = b.price;
		this->BookISBN = b.BookISBN;
		this->BookWriter = b.BookWriter;
		return *this;
	}
	bool operator == (const Book &local) {
		bool check = false;
		if (this->Name == local.Name) {
			if (this->price == local.price) {
				if (this->barrow == local.barrow) {
					if (this->BookISBN == local.BookISBN) {
						if (this->BookWriter == local.BookWriter) {
							check = true;
							return check;
						}
					}
				}
			}
		}
		return check;
	}
};
class Books {
	Book boo;
	int BooksNumbers=0;
	int n;
	vector <Book> bo;
public:
	Book &operator[](const int index){
		return bo[index];
	}
	void Edit(void) {
		string name;
		int serial;
		int i;
		cout << "if you want to Edit by serial Enter <1> or by name Enter <2> : " << endl;
		int e;
		cin >> e;
		if (e != 1 || e != 2) {
			do {
				cout << "the number that you Entered is irrelevant please try again : " << endl;
				cin >> e;
			} while (e != 1 || e != 2);
		}
		if (e == 2) {
			cout << "please Enter the name of that you want to Edit for it : " << endl;
			cin >> name;
			for (i = 0;i < BooksNumbers;i++)
				if (bo[i].Name == name)
					bo[i].Book::Scanf_obj();
			if(i==BooksNumbers && bo[i].Name != name)
				cout << "this wasn't in the directory" << endl;
		}
		if (e == 1) {
			cout << "please Enter the serial number of that you want to Edit it : " << endl;
			cin >> serial;
			for (int i = 0;i < BooksNumbers;i++)
				if (bo[i].BookISBN == serial)
					bo[i].Book::Scanf_obj();
			if(i==BooksNumbers && bo[i].Name != name)
				cout << "this wasn't in the directory" << endl;
		}
	}
		void Delete(){
			string name;
			int i;
			cout << "please Enter the name of that you want to Delete  it : " << endl;
			cin >> name;
			for (i = 0;i < BooksNumbers;i++)
				if (bo[i].Name == name)
					bo.erase(bo.begin()+i);
			if(i==BooksNumbers && bo[i].Name != name)
				cout << "this wasn't in the directory" << endl;
		}
	void Scanf_obj() {
		cout << "How many book details do you want to enter: ";
		cin >> n;
		for (int i=0 ; i<n ;i++) {
			bo.push_back(boo);
			bo[BooksNumbers+i].Book::Scanf_obj();
		}
		BooksNumbers += n ;
	}
	void Show_obj() {
		for (int i = 0;i<bo.size();i++)
			bo[i].Book::Show_obj();
	}
	bool barrow_book(void) {
		bool check = false;
		string name;
		int serial_book;
		cout << "if you want to search by serial Enter <1> or by name Enter <2> : " << endl;
		int e;
		cin >> e;
		if (e != 1 || e != 2) {
			do {
				cout << "the number that you Entered is irrelevant please try again : " << endl;
				cin >> e;
			} while (e != 1 || e != 2);
		}
		if (e == 2) {
			cout << "please Enter the name of the book that you want to search for it : " << endl;
			cin >> name;
			for (int i = 0;i < BooksNumbers;i++) {
				if (bo[i].Name == name) {
					if (bo[i].barrow == false) {
						check = true;
						bo[i].barrow = check;
						cout << "the Entered book has been succssesfully barrowed." << endl;
						return check;
					}
					else {
						cout << "the exact book that you Entered was barrowed before." << endl;
						return check;
					}
				}
			}
			cout << "the exact book wasn't in the directory to barrow it" << endl;
			return check;
		}
		if (e == 1) {
			cout << "please Enter the serial number of the book that you want to barrow : " << endl;
			cin >> serial_book;
			for (int i = 0;i < BooksNumbers;i++) {
				if (bo[i].BookISBN == serial_book) {
					if (bo[i].barrow == false) {
						check = true;
						bo[i].barrow = check;
						cout << "the Entered book has been succssesfully barrowed." << endl;
						return check;
					}
					else {
						cout << "the exact book that you Entered was barrowed before." << endl;
						return check;
					}
				}
			}
			cout << "the exact book wasn't in the directory to barrow it" << endl;
			return check;
		}
		return check;
	}
	bool Search_book(void){
		bool check=false;
		string name;
		int serial_book;
		cout << "if you want to search by serial Enter <1> or by name Enter <2> : " << endl;
		int e;
		cin >> e;
		if (e != 1 || e != 2) {
			do {
				cout << "the number that you Entered is irrelevant please try again : " << endl;
				cin >> e;
			} while (e != 1 || e != 2);
		}
		if (e == 2) {
			cout << "please Enter the name of the book that you want to search for it : " << endl;
			cin >> name;
			for (int i = 0;i < BooksNumbers;i++) {
				if (bo[i].Name == name)
					return true;
			}
			return false;
		}
		return check;
		if (e == 1) {
			cout << "please Enter the serial number of the book that you want to search it : " << endl;
			cin >> serial_book;
			for (int i = 0;i < BooksNumbers;i++) {
				if (bo[i].BookISBN == serial_book) {
					check = true;
					return check;
				}
			}
			return true;
		}
		return false;
	}
};
class Newspaper : public Object {
public:
	int serial_ISBN;
	char pub[33];
	virtual void Scanf_obj() {
		Object::Scanf_obj();
		cout << "please Enter the serial number of the newspaper : " << endl;
		cin >> this->serial_ISBN;
		cout << "please Enter the name of the publication : " << endl;
		cin >> this->pub;
	}
	virtual void Show_obj() {
		Object::Show_obj();
		cout << "the serial number of the newspaper is equal with : " << endl;
		cout << this->serial_ISBN;
		cout << "the name of the publication is equal with : " << endl;
		cout << this->pub;
	}
	bool operator == (const Newspaper &local) {
		bool check = false;
		if (this->Name == local.Name) {
			if (this->price == local.price) {
				if (this->barrow == local.barrow) {
					if (this->serial_ISBN == local.serial_ISBN) {
							check = true;
							return check;
					}
				}
			}
		}
		return check;
	}
	Newspaper &operator=(const Newspaper &n){
		Name = n.Name;
		price = n.price;
		return *this;
	}
};
class Newspapers {
private :
	Newspaper nee;
	int NewspapersNumbers=0;
	int n;
	vector <Newspaper> ne;
public:
	virtual void Scanf_obj() {
		cout << "How many newspaper details do you want to enter: ";
		cin >> n;
		for (int i = 0;i<n;i++) {
			ne.push_back(nee);
			ne[NewspapersNumbers+i].Newspaper::Scanf_obj();
		}
		NewspapersNumbers += n;
	}
	void Edit(void) {
		string name;
		int i;
		cout << "please Enter the name of that you want to Edit for it : " << endl;
		cin >> name;
		for (i = 0;i < NewspapersNumbers;i++)
			if (ne[i].Name == name)
				ne[i].Newspaper::Scanf_obj();
		if(i==NewspapersNumbers && ne[i].Name != name)
			cout << "this wasn't in the directory" << endl;
	}
	void Delete(void) {
		string name;
		int i;
		cout << "please Enter the name of that you want to Delete  it : " << endl;
		cin >> name;
		for (i = 0;i < NewspapersNumbers;i++)
			if (ne[i].Name == name)
				ne.erase(ne.begin()+i);
		if(i==NewspapersNumbers && ne[i].Name != name)
			cout << "this wasn't in the directory" << endl;
	}
	virtual void Show_obj() {
		for (int i = 0;i<ne.size();i++)
			ne[i].Newspaper::Show_obj();
	}
	Newspaper &operator[](const int index){
		return ne[index];
	}
	bool Search_newspaper(void){
		bool check=false;
		string name;
		int serial_newspaper;
		cout << "if you want to search by serial Enter <1> or by name Enter <2> : " << endl;
		int e;
		cin >> e;
		if (e != 1 || e != 2) {
			do {
				cout << "the number that you Entered is irrelevant please try again : " << endl;
				cin >> e;
			} while (e != 1 || e != 2);
		}
		if (e == 2) {
			cout << "please Enter the name of the newspaper that you want to search for it : " << endl;
			cin >> name;
			for (int i = 0;i < NewspapersNumbers;i++) {
				if (ne[i].Name == name) {
					check = true;
					return check;		//return true
				}
			}
			return check;
		}
		if (e == 1) {
			cout << "please Enter the serial number of the newspaper that you want to search : " << endl;
			cin >> serial_newspaper;
			for (int i = 0;i < NewspapersNumbers;i++) {
				if (ne[i].serial_ISBN == serial_newspaper) {
						check = true;
						return check;
				}
			}
			return check;
		}
		return check;
	}
	bool barrow_news(void) {
		bool check = false;
		int serial_newspaper;
		string name_newspaper;
		cout << "if you want to search by serial Enter <1> or by name Enter <2> : " << endl;
		int e;
		cin >> e;
		if (e != 1 || e != 2) {
			do {
				cout << "the number that you Entered is irrelevant please try again : " << endl;
				cin >> e;
			} while (e != 1 || e != 2);
		}
		if (e == 2) {
			cout << "please Enter the name of the book that you want to search for it : " << endl;
			cin >> name_newspaper;
			for (int i = 0;i < NewspapersNumbers;i++) {
				if (ne[i].Name == name_newspaper) {
					if (ne[i].barrow == false) {
						check = true;
						ne[i].barrow = check;
						cout << "the Entered book has been succssesfully barrowed." << endl;
						return check;
					}
					else {
						cout << "the exact book that you Entered was barrowed before." << endl;
						return check;
					}
				}
			}
			cout << "the exact book wasn't in the directory to barrow it" << endl;
			return check;
		}
		if (e == 1) {
			cout << "please Enter the serial number of the book that you want to barrow : " << endl;
			cin >> serial_newspaper;
			for (int i = 0;i < serial_newspaper;i++) {
				if (ne[i].serial_ISBN == serial_newspaper) {
					if (ne[i].barrow == false) {
						check = true;
						ne[i].barrow = check;
						cout << "the Entered book has been succssesfully barrowed." << endl;
						return check;
					}
					else {
						cout << "the exact book that you Entered was barrowed before." << endl;
						return check;
					}
				}
			}
			cout << "the exact book wasn't in the directory to barrow it" << endl;
			return check;
		}
		return check;
	}

};
class magazin :public Object {
public :
	string type;
	unsigned int serial_ISBN;
	unsigned int pages;
	string pub;
	virtual void Scanf_obj() {
		Object::Scanf_obj();
		cout << "please Enter the type of the magazin : " << endl;
		cin >> this->type;
		cout << "please Enter the serial number of the magazin : " << endl;
		cin >> this->serial_ISBN;
		cout << "please Enter the plenty of the pages of the magazin : " << endl;
		cin >> this->pages;
		cout << "please Enter the name of the publication : " << endl;
		cin >> this->pub;
	}
	virtual void Show_obj() {
		Object::Show_obj();
		cout << "the type of the magazin is equal with : " << endl;
		cout << this->type;
		cout << "the serial number of the magazin is equal with : " << endl;
		cout << this->serial_ISBN;
		cout << "the number of the pages of the magazin is equal with : " << endl;
		cout << this->pages;
		cout << "the name of the publication is equal with : " << endl;
		cout << this->pub;
	}
	bool operator == (const magazin &local) {
		bool check = false;
		if (this->Name == local.Name) {
			if (this->price == local.price) {
				if (this->barrow == local.barrow) {
					if (this->serial_ISBN == local.serial_ISBN) {
						if (this->pages == local.pages) {
							if (this->type == local.type) {
								if (this->pub == local.pub) {
									check = true;
									return check;
								}
							}
						}
					}
				}
			}
		}
		return check;
	}
	magazin &operator=(const magazin &b){
		Name = b.Name;
		price = b.price;
		return *this;
	}
};
class magazins {
	magazin maa;
	int magazinsNumbers=0;
	int n;
	vector <magazin> ma;
public:
	void Edit(void) {
		string name;
		int i;
		cout << "please Enter the name of that you want to Edit  it : " << endl;
		cin >> name;
		for (i = 0;i < magazinsNumbers;i++)
			if (ma[i].Name == name)
				ma[i].magazin::Scanf_obj();
		if(i==magazinsNumbers && ma[i].Name != name)
			cout << "this wasn't in the directory" << endl;
	}
	void Delete(void) {
		string name;
		int i;
		cout << "please Enter the name of that you want to Delete  it : " << endl;
		cin >> name;
		for (i = 0;i < magazinsNumbers;i++)
			if (ma[i].Name == name)
				ma.erase(ma.begin()+i);
		if(i==magazinsNumbers && ma[i].Name != name)
			cout << "this wasn't in the directory" << endl;
	}
	virtual void Scanf_obj() {
		cout << "How many magazin details do you want to enter: ";
		cin >> n;
		for (int i=0 ; i<n ; i++) {
			ma.push_back(maa);
			ma[magazinsNumbers+i].magazin::Scanf_obj();
		}
		magazinsNumbers += n ;
	}
	virtual void Show_obj() {
		for (int i = 0;i<ma.size();i++)
			ma[i].magazin::Show_obj();
	}
	magazin &operator[](const int index){
		return ma[index];
	}
	bool Search_magazin(void){
		bool check=false;
		string name;
		int serial_magazin;
		cout << "if you want to search by serial Enter <1> or by name Enter <2> : " << endl;
		int e;
		cin >> e;
		if (e != 1 || e != 2) {
			do {
				cout << "the number that you Entered is irrelevant please try again : " << endl;
				cin >> e;
			} while (e != 1 || e != 2);
		}
		if (e == 2) {
			cout << "please Enter the name of the magazin that you want to search for it : " << endl;
			cin >> name;
			for (int i = 0;i < magazinsNumbers;i++) {
				if (ma[i].Name == name) {
					check = true;
					return check;
				}
			}
			return check;
		}
		if (e == 1) {
			cout << "please Enter the serial number of the magazin that you want to search : " << endl;
			cin >> serial_magazin;
			for (int i = 0;i < magazinsNumbers;i++) {
				if (ma[i].serial_ISBN == serial_magazin) {
						check = true;
						return check;
				}
			}
		return check;
		}
	return check;
	}
	bool barrow_magazin(void) {
		bool check = false;
		int serial_magazin;
		char name_magazin[33];
		cout << "if you want to search by serial Enter <1> or by name Enter <2> : " << endl;
		int e;
		cin >> e;
		if (e != 1 || e != 2) {
			do {
				cout << "the number that you Entered is irrelevant please try again : " << endl;
				cin >> e;
			} while (e != 1 || e != 2);
		}
		if (e == 2) {
			cout << "please Enter the name of the book that you want to search for it : " << endl;
			cin >> name_magazin;
			for (int i = 0;i < this->magazinsNumbers;i++) {
				if (ma[i].Name == name_magazin) {
					if (ma[i].barrow == false) {
						check = true;
						ma[i].barrow = check;
						cout << "the Entered magazin has been succssesfully barrowed." << endl;
						return check;
					}
					else {
						cout << "the exact magazin that you Entered was barrowed before." << endl;
						return check;
					}
				}
			}
			cout << "the exact book wasn't in the directory to barrow it" << endl;
			return check;
		}
		if (e == 1) {
			cout << "please Enter the serial number of the book that you want to barrow : " << endl;
			cin >> serial_magazin;
			for (int i = 0;i < this->magazinsNumbers;i++) {
				if (ma[i].serial_ISBN == serial_magazin) {
					if (ma[i].barrow == false) {
						check = true;
						ma[i].barrow = check;
						cout << "the Entered book has been succssesfully barrowed." << endl;
						return check;
					}
					else {
						cout << "the exact book that you Entered was barrowed before." << endl;
						return check;
					}
				}
			}
			cout << "the exact book wasn't in the directory to barrow it" << endl;
			return check;
		}
		return check;
	}
};
int main(){
	Books b;
	Newspapers n;
	magazins mag;
	Members mem;
	workers wr;
	Bookers br;
	int ch=1;
	while(ch!=0){
		cout << "1.Add Member"<<endl<<endl;
		cout << "2.Add Booker"<<endl<<endl;
		cout << "3.Add Worker"<<endl<<endl;
		cout << "4.Add Book"<<endl<<endl;
		cout << "5.Add Newspaper"<<endl<<endl;
		cout << "6.Add Magazin"<<endl<<endl;
		cout << "7.Show All Members Details"<<endl<<endl;
		cout << "8.Show All Bookers Details"<<endl<<endl;
		cout << "9.Show All Workers Details"<<endl<<endl;
		cout << "10.Show All Books Details"<<endl<<endl;
		cout << "11.Show All Newspaper Details"<<endl<<endl;
		cout << "12.Show All Magazin Details"<<endl<<endl;
		cout << "13.barrow Book"<<endl<<endl;
		cout << "14.barrow Newspaper"<<endl<<endl;
		cout << "15.barrow Magazin"<<endl<<endl;
		cout << "16.Search Book"<<endl<<endl;
		cout << "17.Search Magazin"<<endl<<endl;
		cout << "18.Search Newspaper"<<endl<<endl;
		cout << "19.Search Members"<<endl<<endl;
		cout << "20.Search Workers"<<endl<<endl;
		cout << "21.Search Bookers"<<endl<<endl;
		cout << "22.Edit Book"<<endl<<endl;
		cout << "23.Edit Newspaper"<<endl<<endl;
		cout << "24.Edit Magazin"<<endl<<endl;
		cout << "25.Edit Member"<<endl<<endl;
		cout << "26.Edit Worker"<<endl<<endl;
		cout << "27.Edit Booker"<<endl<<endl;
		cout << "28.Delete Book"<<endl<<endl;
		cout << "29.Delete Newspaper"<<endl<<endl;
		cout << "30.Delete Magazin"<<endl<<endl;
		cout << "31.Delete Member"<<endl<<endl;
		cout << "32.Delete Worker"<<endl<<endl;
		cout << "33.Delete Booker"<<endl<<endl;
		cout << "34.Exit"<<endl<<endl;
		cin>>ch;
		if (ch < 1 || ch > 34) {
			do {
				cout << "the number that you Entered is invalid please try again : " << endl;
				cin >> ch;
			} while (ch < 1 || ch > 25);
		}
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		switch (ch){
			case 1:
				mem.scan_members();
				break;
			case 2 :
				br.scan_bookers();
				break;
			case 3 :
				wr.scan_workers();
				break;
			case 4:
				b.Scanf_obj();
				break;
			case 5 :
				n.Scanf_obj();
				break;
			case 6 :
				mag.Scanf_obj();
				break;
			case 7:
				mem.print_members();
				break;
			case 8 :
				br.print_bookers();
				break;
			case 9 :
				wr.print_workers();
				break;
			case 10:
				b.Show_obj();
				break;
			case 11:
				n.Show_obj();
				break;
			case 12:
				mag.Show_obj();
				break;
			case 13:
				b.barrow_book();
				break;
			case 14:
				n.barrow_news();
				break;
			case 15:
				mag.barrow_magazin();
				break;
			case 16:
				b.Search_book();
				break;
			case 17:
				mag.Search_magazin();
				break;
			case 18:
				n.Search_newspaper();
				break;
			case 19:
				mem.Search_members();
				break;
			case 20:
				wr.Search_Workers();
				break;
			case 21:
				br.Search_Bookers();
				break;
			case 22:
				b.Edit();
				break;
			case 23:
				n.Edit();
				break;
			case 24:
				mag.Edit();
				break;
			case 25:
				mem.Edit();
				break;
			case 26:
				wr.Edit();
				break;
			case 27:
				br.Edit();
				break;
			case 28:
			  b.Delete();
			  break;
			case 29:
			  n.Delete();
			  break;
			case 30:
			  mag.Delete();
			  break;
			case 31:
			  mem.Delete();
			  break;
			case 32:
			  wr.Delete();
			  break;
			case 33:
				br.Delete();
				break;
			case 34:
				exit(0);
				break;
			default:
				break;
			}
	}
	return 0;
}

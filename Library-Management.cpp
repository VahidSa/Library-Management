#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
class Date {
private :
	int Day;
	int Month;
	int Year;
public :
	void input_date(void) {
		cout << "please Enter the date of the topic : " << endl;
		cin >> this->Day;
		cout << "please Enter thr month of the topic : " << endl;
		cin >> this->Month;
		cout << "please Enter the year of the topic : " << endl;
		cin >> this->Year;
	}
	void output_date(void) {
		cout << "the day of the exact topic is equal with : " << endl;
	}
};
class address {
private :
	char city[33];
	char street[33];
	char ave[33];
	int pelak;
	long int postal_code;
public :
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
	virtual void print_address(void){
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
private :
	int birth_Day;
	int birth_month;
	int birth_year;
	char first_name[333];
	char last_name[333];
	long int personal_code;
	friend void print_person(person);
public :
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
class worker :public person ,public address{
private :
	char job[33];
	long int salery;
public:
	virtual void scan_address(void) {
		address::scan_address();
	}
	virtual void print_address(void) {
		address::print_address();
	}
	virtual void scan_person(void){
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
};
class member :public person,public address {
private :
	char type[33];
	char licence[33];
	int time;
public :
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
/*
	member operator == (const member &local) {

	}
*/
};

class Object {
	public :
	char Name[33];
	double price;
	Date ta;
	virtual void Scanf_obj(){
		cout<<"Enter Name: ";
		cin>>this->Name;
		cout<<"Enter price: ";
		cin>>this->price;
		cout<<"Enter Date of publish: ";
	//	cin>>this->ta;
	}
	virtual void Show_obj(){
		cout<<"Name: "<<this->Name;
		cout<<"Price: "<<this->price;
	//	cout<<"Date of publish: "<<this->ta;
	}
};
class Book:Object{
	long int BookISBN;
	char BookWriter[30];	//string
	virtual void Scanf_obj(){
		Object::Scanf_obj();
		cout<<"Enter ISBN: ";
		cin>>this->BookISBN;
		cout<<"Enter Name of BookWriter: ";
		cin>>this->BookWriter;
	}
	virtual void Show_obj(){
		Object::Show_obj();
		cout<<"ISBN: "<<this->BookISBN<<endl;
		cout<<"Name of BookWriter: "<<this->BookWriter;
	}
};
class magazin :public Object {
private:
	char type[33];
	unsigned int num;
	unsigned int pages;
	char pub;
public:

};
class Newspapers :public Object {
private :
	Date ta;

};
class Books{
	static int BooksNumbers;
public:
	Book *bo;
	bo = new Book[BooksNumbers];
/*
	void Add_Books(){
		bookCopy = new Books[BooksNumbers];
		cout<<"Enter How many Book Details you want enter:";
		cin>>BookNumber;
		BooksNumbers+=BookNumber;
		bookCopy=book;								//؟؟؟!!
		book = new Books[BooksNumbers];
		for(int i=0;i<BooksNumbers;i++){
			cout<<"Enter Name: ";
			cin>>book->BookName;
		}
*/
};
int main()
{
	//Books b;
	//b.InputBooks();
	//b.ShowAll();
    return 0;
}


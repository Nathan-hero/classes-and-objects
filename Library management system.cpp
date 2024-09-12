#include <iostream>
#include<fstream>
#include<string>
#include <iomanip>
using namespace std;

class mainMenu{
	private:
		int choice;
		//for adding Books
		string name;
		string author;
		string year;
		
		
		public:
			void addBook(){
				
				ofstream book("book.txt", ios::app);
				system("cls");
				cout<<"[Warning: Do not use space]\n";
				
				cout << "Add name of book: ";
				cin >> name;
				cout << "Add author: ";
				cin >> author;
				cout << "Add year of publication: ";
				cin >> year;
				
				if(book.is_open()){
					book << name << " " << author << " " << year << " " << endl;
					
					cout << "\nData added successfully\n";
				}
			
					cout << endl;
					system("pause");
					system("cls");
					
					book.close();
			
			}
			
			void searchBook(){
				
				bool found = false;
				ifstream book("book.txt");
				string keyword;
				
				cout << "Enter Name of book: ";
				cin >> keyword;
				
				while (book >> name >> author >> year){
			
					if (keyword == name){
					
					cout << "\nBook Found!\n";
					cout << "\nBook Name: " << setw(10) << name;
					cout << "\nAuthor: "<< setw(10) << author;
					cout << "\nYear: "<< setw(10) << year;
					cout << endl;
					system("pause");
					system("cls");
					found = true;
					
					
					break;
				}
			}
	if (found == false) 
	cout << "\nNo book found!"; 
	cout << endl << endl; 
	system("pause"); 
	system("cls"); 

book.close(); 
		}
	
			void display(){
				ifstream book("book.txt");
				cout << "Book\t\t\t\tAuthor\t\t\tYear\n";
				while (book >> name >> author >> year){
					cout<< setw(20) << name << setw(20) << author << setw(20) << year << endl; 
				}
				cout << endl;
					system("pause");
					system("cls");
					book.close();
			}
		
};


int main(){
	mainMenu m1;
	int choice;
	while(true){
	
	cout << "===========[MainMenu]===========\n";
	cout << "[1]Add Book\n[2]Display Books\n[3]Search Book\n[4]Exit\n";
	cout << "===========[UserInput]===========\n";
	cin >> choice;
	
	switch(choice){
	
	case 1:
	m1.addBook();
	break;
	
	case 2:
	m1.display();
	break;
	
	case 3:
	m1.searchBook();
	break;
	
	case 4: 	
		cout << "Happy Reading XD";
		return 0;
		
		cout << "Invalid option\n";
		system ("pause");
		system ("cls");

	}
	};
}

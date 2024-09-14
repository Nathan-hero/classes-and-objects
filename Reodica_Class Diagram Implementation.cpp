#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>

using namespace std;

class menu {
	
	public:
	
        int menu_choice;
        
        void MainMenu() {
            cout << "=====[Shop N' Go]=====\n";
            cout << "Input the corresponding number based on your preferred option:\n";
            cout << "[1] Check products\n[2] Check cart\n[3] Exit\n";
        }
};

class product {
    public:
        string item_name[2][5] = {{"Figurine A","Figurine B","Viekk Pro","Artist Pro","Poster   "},
                                  {"AB", "AC", "AD", "AE", "AF"}};
        int item_price[5] = {800, 650, 7000, 13000, 50};

        void prod() {//Display
            cout << "ID" << "\t\t\t" << "Name" << "\t\t\t" << "Price\n";
            for (int i = 0; i < 5; i++) {
                cout << item_name[1][i] << "\t\t\t" << item_name[0][i] << "\t\t\t" << item_price[i] << endl;
            }
        }

        void toUpperCase(string &str) {
            for (char &c : str) {
                c = toupper(c);
            }
        }

        void addprod(int &increment, int item_quantity[5], int item_location[10], string &chosen) {
		    cout << "Input the ID of your chosen item\n";
            getline(cin, chosen);
            toUpperCase(chosen);
            bool confirm = true;
		
            for (int i = 0; i < 6; i++) {
                if (chosen == item_name[1][i]) {
                    cout << "Enter amount for " << item_name[0][i] << ": ";
                    cin >> item_quantity[increment];
                    item_location[increment] = i;
                    increment++;
                    confirm = false;
					break;
				}
			}if (confirm == true){
				cout << "No item with that ID\n";
				system("pause");
				system("cls");
				}
		}
        
};

class cart {
    public:
        void CartDisplay(int item_location[10], int item_quantity[10], int item_price[5], string item_name[2][5], int increment){
            if (increment == 0) {
                cout << "The cart is empty\n";
                return;
            }
            cout << "ID" << "\t\t\t" << "Name" << "\t\t\t" << "Price" << "\t\t\t" << "Quantity\n";
            for (int i = 0; i < increment; i++) {
                int loc = item_location[i];
                cout << item_name[1][loc] << "\t\t\t" << item_name[0][loc] << "\t\t" << item_price[loc] << "\t\t\t" << item_quantity[i] << endl;
            }
        }
};

class order {
	private:
		
	public:
		void OrderDisplay(int item_location[10], int item_quantity[10], int item_price[5], string item_name[2][5], int increment){
			int grand_total;
			
			for (int i = 0; i < increment; i++) {
                int loc = item_location[i];
                
                cout << "\n\nOrder ID: " << i+1 << endl;
                cout << "Total amount: " << item_price[loc] * item_quantity[i] << endl;
                cout << "Order details\n";
            	
            	grand_total = grand_total + item_price[loc] * item_quantity[i];
            	
            	cout << "ID" << "\t\t\t" << "Name" << "\t\t\t" << "Price" << "\t\t\t" << "Quantity\n";
			    cout << item_name[1][loc] << "\t\t\t" << item_name[0][loc] << "\t\t" << item_price[loc] << "\t\t\t" << item_quantity[i] << endl;
			}
			
			cout << endl << "Grand total of: " << grand_total;
		}
};



int main() {
    menu m1;
    product a1;
    cart c1;
    order o1;

    string chosen;
    int increment = 0;
    char y_n;

    // Data for items
    int item_quantity[10] = {};  // Tracks quantities of items
    int item_location[10] = {};  // Tracks locations of added items

    bool running = true;

    while (running) {
        m1.MainMenu();
        cin >> m1.menu_choice;
        cin.ignore();  

        switch (m1.menu_choice) {
            case 1: {
                bool adding = true;
                while (adding) {
                    a1.prod(); 
                    a1.addprod(increment, item_quantity, item_location, chosen);
                
				    cout << endl;
                
                    cout << "Add another item? (Y/N): ";
                    cin >> y_n;
                    cin.ignore();
                    
    					cout << endl;
    					system("pause");
    					system("cls");

                    if (toupper(y_n) != 'Y') {
                        adding = false;
                    }
                }
                break;
            }
            case 2: {
            	cout << "You can only store 10 items in the cart\n\n";
                c1.CartDisplay(item_location, item_quantity, a1.item_price, a1.item_name, increment);
                 if (item_quantity[0] == 0){
                    	system ("pause");
                    	system ("cls");
						break;
					}
                	
                char chkout;
				cout << "Checkout? (Y/N): ";
                cin >> chkout;
                cin.ignore();
                
                
    			cout << endl;
    			system("pause");
    			system("cls");
                
                if (toupper(chkout) == 'Y'){
                	cout << "=====[Successfuly ordered]=====\n";
                	cout << "You have successfully checked out the products!\n\n";
                	o1.OrderDisplay(item_location, item_quantity, a1.item_price, a1.item_name, increment);
					return 1;
				}
				
                break;
            }

            
              case 3:{
              	cout << "Thankyou for using our app and happy shopping!\n";
            	running = false;
				break;
			}
			
			default:{
				cout << "Invalid input\n";
				system("pause");
				system("cls");
				break;
			}
        }
        
    }

    return 0;
}

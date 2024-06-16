
// List of all the variables used in the program :
// shop_no -> Number of shops in Big Hub
// shop_cust -> Array to store the capacity of each shop
// curr_customers -> Array to store the number of customers in each shop
// choice -> Variable to store the choice of the user
// shop_no_add -> Shop number entered by the user when a person enters Big Hub
// shop_no_remove -> Shop number entered by the user when a person leaves Big Hub

#include <bits/stdc++.h>
using namespace std;

void display_result(int shop_no, int curr_customers[]) // Function to display the number of customers in each shop
{
    cout<<"         Number of customers in each shop : "<<endl;
    for (int i=0;i<shop_no;i++)
    {
        cout<<"         Shop "<<i+1<<" has "<<curr_customers[i]<<" customer(s)"<<endl;
    }
}

int main()
{
    cout<<endl;

    cout<<"                                     ==========Welcome to Big Hub!=========="<<endl;

    cout<<endl;

    int shop_no; // Number of shops in Big Hub
    cout<<"         How many shops are there in Big Hub? : ";
    cin>>shop_no;
    int shop_cust[shop_no];

    cout<<endl;

    cout<<"         How many customers can each shop accomodate at one time?"<<endl<<endl;
    for (int i=0;i<shop_no;i++)
    {
        cout<<"         Capacity of shop "<<i+1<<" : ";
        cin>>shop_cust[i];
    }

    int curr_customers[shop_no];
    for (int i=0;i<shop_no;i++)
    {
        curr_customers[i] = 0;
    }

    int choice;
    while (true)
    {
        cout<<endl;

        cout<<"         Enter 1 if a person entered Big Hub"<<endl;
        cout<<"         Enter 2 if a person left Big Hub"<<endl;
        cout<<"         Enter 3 if it is closing time :("<<endl<<endl;
        cout<<"         What is currently happening? : ";
        cin>>choice;

        cout<<endl;

        if (choice==1) // If a person entered Big Hub
        {
            int shop_no_add;
            cout<<"         Which shop did the person enter? : ";
            cin>>shop_no_add;

            cout<<endl;

            if ((shop_no_add<=0) || (shop_no_add>shop_no)) // If the shop number entered is invalid
            {
                cout<<"         Invalid shop number! Shop not found!"<<endl;
            }
            else
            {
                if (curr_customers[shop_no_add-1] < shop_cust[shop_no_add-1])
                {
                    curr_customers[shop_no_add-1]++;
                }
                else
                {
                    cout<<"         Shop is already full! Can't enter!"<<endl;
                }
            }

            display_result(shop_no, curr_customers); // Displaying the number of customers in each shop
        }

        else if (choice==2) // If a person left Big Hub
        {
            int shop_no_remove;
            cout<<"         Which shop did the person leave? : ";
            cin>>shop_no_remove;

            cout<<endl;

            if ((shop_no_remove<=0) || (shop_no_remove>shop_no))
            {
                cout<<"         Invalid shop number! Shop not found!"<<endl;
            }
            else
            {
                if (curr_customers[shop_no_remove-1] >= shop_cust[shop_no_remove-1])
                {
                    curr_customers[shop_no_remove-1]--;
                }
                else
                {
                    cout<<"         Shop is already empty! Can't leave!"<<endl;
                }
            }

            display_result(shop_no, curr_customers); // Displaying the number of customers in each shop
        }

        else if (choice==3)
        {
            display_result(shop_no, curr_customers);
            cout<<endl;
            cout<<"                                 ==========Thank you for visiting Big Hub!=========="<<endl;
            return 0;
        }

        else cout<<"            Invalid choice! Try again";
    }
}

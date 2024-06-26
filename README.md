## Demo_Authentication_System_cpp
![image](https://github.com/SimarjeetxSingh/Demo_Authentication_System_cpp/assets/130891817/1ee3934b-d0b7-4797-ab84-a087ed6548c8)


# Security System in C++
## Overview
This project is a console-based security system implemented in C++. It allows users to register, log in, and change their passwords. The system uses file handling to store and retrieve user credentials.

## Features
1. **Register**: Users can register by providing a username, password, and age. These details are stored in a file.
2. **Login**: Registered users can log in by entering their username and password. The system reads the stored credentials from the file and validates them.
3. **Change Password**: Logged-in users can change their password by providing their old password and then entering a new password twice for confirmation.
4. **End Program**: The program can be terminated by selecting the appropriate option from the menu.

## Code Explanation

### Including Libraries
```cpp
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;
```

These libraries are essential for input/output operations, file handling, and string manipulations.

### Main Function and Menu
```cpp
int main() {
    int a, i=0;
    string text, old, password1, password2, pass, name, password0, age, user, word, word1;
    string creds[2], cp[2];
    cout<<"        Security System  "<<endl;
    cout<< "_____________________________"<<endl<<endl;
    cout<<"|         1. Register         |"<<endl;
    cout<<"|         2. Login            |"<<endl;
    cout<<"|         3. Change Password  |"<<endl;
    cout<<"|_________4. End Program______|"<<endl<<endl;
```

### Register

```cpp
case 1: {
    cout<<"___________________________"<<endl;
    cout<<"|---------Register--------|"<<endl;
    cout<<"|_________________________|"<<endl<<endl;
    cout<<" Please Enter Username:- ";
    cin>>name;
    cout<<" Please Enter the Password:- ";
    cin>>password0;
    cout<<" Please Enter your Age:- ";
    cin>>age;

    ofstream of1;
    of1.open("ssimar.txt");
    if(of1.is_open()){
        of1<<name<<"\n";
        of1<<password0;
        cout<<" Registration successful "<<endl;
    }
    break;
}
```

#### Explanation:
- **Display Interface**: The program presents a user-friendly interface for registration.
- **Input**: Prompts the user to enter their username, password, and age using `cin`.
- **File Handling**: Opens a file named "ssimar.txt" in write mode (`ofstream`).
- **Storage**: Writes the entered username and password into the file.
- **Confirmation**: Prints a message confirming successful registration.

This section allows new users to register by storing their credentials in a text file named "ssimar.txt".
<hr>

![Screenshot 2024-06-27 011614](https://github.com/SimarjeetxSingh/Demo_Authentication_System_cpp/assets/130891817/352ef6e5-8b99-41fa-b322-d2b6c6ab20dd)
<hr>
### Login

```cpp
case 2: {
    i = 0;
    cout << "________________________" << endl;
    cout << "|---------Login--------|" << endl;
    cout << "|______________________|" << endl << endl;
    
    ifstream of2;
    of2.open("ssimar.txt");
    cout << "Please Enter the Username:- ";
    cin >> user;
    cout << " Please Enter the Password:- ";
    cin >> pass;
    
    if (of2.is_open()) {
        while (!of2.eof()) {
            while (getline(of2, text)) {
                istringstream iss(text);
                iss >> word;
                creds[i] = word;
                i++;
            }
            if (user == creds[0] && pass == creds[1]) {
                cout << " ----Login Successful----" << endl << endl;
                cout << " Details: " << endl;
                cout << "Username: " + name << endl;  // Assuming 'name' is the registered username
                cout << "Password: " + pass << endl;
                cout << "Age: " + age << endl;  // Assuming 'age' is the registered age
            } else {
                cout << endl << endl;
                cout << " Incorrect Credentials " << endl;
                cout << " 1. Press 2 to login  " << endl;
                cout << " 2. Press 3 to change password " << endl;
                break;
            }
        }
    }
    break;
}
```

#### Explanation:
- **Display Interface**: Displays a login prompt for the user.
- **File Handling**: Opens the "ssimar.txt" file for reading (`ifstream`).
- **Input**: Prompts the user to enter their username and password using `cin`.
- **Validation**: Reads each line from the file to compare with the entered username and password.
- **Authentication**: If the entered credentials match those in the file, the login is successful, and user details (assuming 'name' and 'age' are previously registered) are displayed.
- **Error Handling**: If credentials don't match, it prompts the user for correct input or password change.

This section handles user login by verifying the entered credentials against those stored in the "ssimar.txt" file.
<hr>

![Screenshot 2024-06-27 011636](https://github.com/SimarjeetxSingh/Demo_Authentication_System_cpp/assets/130891817/8bff3955-4b3e-4926-907f-4e9881391e1c)
<hr>

### Change Password
```cpp
case 3: {
    i=0;
    cout<<"---------Change Password--------"<<endl;
    ifstream of0;
    of0.open("ssimar.txt");
    cout<<"Enter the Old password:- ";
    cin>>old;
    if(of0.is_open()) {            
        while(of0.eof()) {
            while(getline(of0, text)) {
                istringstream iss(text);
                iss>>word1;
                cp[i]=word1;
                i++;
            }
            if(old==cp[1]) {
                of0.close();
                ofstream of1;
                of1.open("ssimar.txt");
                if(of1.is_open()) {
                    cout<<" Enter your new password:- ";
                    cin>>password1;
                    cout<<"Enter your password again:- ";
                    cin>>password2;
                    if(password1==password2) {
                        of1<<cp[0]<<"\n";
                        of1<<password1;
                        cout<<"Password changed successfully"<<endl;
                    } else {
                        of1<<cp[0]<<"\n";
                        of1<<old;
                        cout<<"Passwords do not match"<<endl;
                    }
                }
            } else {
                cout<<" Please enter a valid password "<<endl;
                break;
            }
        }
    }
    break;
}
```
This section allows the user to change their password by first verifying the old password.
<hr>

![Screenshot 2024-06-27 011652](https://github.com/SimarjeetxSingh/Demo_Authentication_System_cpp/assets/130891817/0cd17c14-de15-43ff-8e0b-27a1a4784c1c)
<hr>

### End Program
```cpp
case 4: {
    cout<<"--------------Thank you!-------------\n";
    cout<<"Now press 5 to exit ";
    break;
}
case 5: {
    exit(a);
}
default:
    cout<<"Enter a valid choice ";
}
```

This section handles program termination.

### Loop and Exit
```cpp
} while(a != 5);
return 0;
}
```
The loop ensures that the menu keeps appearing until the user decides to exit.
<hr>

![Screenshot 2024-06-27 011747](https://github.com/SimarjeetxSingh/Demo_Authentication_System_cpp/assets/130891817/a862781e-3f5a-4697-884a-73e8688d491a)
<hr>
## Key Concepts
- **File Handling**: The program demonstrates how to read from and write to files using `ifstream` and `ofstream`.
- **String Manipulation**: Use of `istringstream` to extract words from a string.
- **Control Structures**: Use of loops and conditional statements to control the flow of the program.
  <hr>
![Screenshot 2024-06-27 011814](https://github.com/SimarjeetxSingh/Demo_Authentication_System_cpp/assets/130891817/381e0949-6182-4fb8-bb14-55771bd06c8e)
<hr>
## Conclusion
This project showcases a basic implementation of a security system using C++. It covers essential programming concepts such as file handling, user input/output, and basic authentication mechanisms.
<hr>

![Screenshot 2024-06-27 011834](https://github.com/SimarjeetxSingh/Demo_Authentication_System_cpp/assets/130891817/d4fcb18c-315a-4046-b006-b4650403b35c)

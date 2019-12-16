//-----------------------------------------------
//author: Angel Moreta
//-----------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void clearScreen();
void menu(string &fileName);
void encryptFile(fstream &input, fstream &output, int);
void decryptFile(fstream &input, fstream &output, int);

int main(){
    const int ENCRYPT = 10;
    string fileName;
    const string fileEncryptedName = "encrypted.txt"; 

    menu(fileName);
    //create file object + open file 
    fstream fileFilter(fileName, ios::in);
    fstream encryptedFile(fileEncryptedName, ios::out);

    
    // verify if file is in directory
    clearScreen();
    if(!fileFilter)
    {
        cout << "\n\n** File was not found, program has been terminated **\n\n";
        exit(1);
    } else {
        // encrypt the file and save in a .txt file
        encryptFile( fileFilter, encryptedFile,  ENCRYPT );
        cout << "\nfilename --> " << fileName << " <--  was encrypted" << endl;
        cout <<"***************************************";
        cout <<"\n\n\n\n\n";
        cout << "** Encrypted file was saved as: " << fileEncryptedName << endl; 
        cout <<"\n\n\n\n\n";
        cout <<"***************************************" << endl;
    }
    // close files
    fileFilter.close();
    encryptedFile.close();
    return 0;
};

void clearScreen(){ // clear the screen 
    cout << string( 100, '\n' );
}

void menu(string &fileName){
    char choice;
    cout << "* Welcome to encrypter by Angel Moreta *" << endl; // welcome user
    cout << "( A ) to encrypt a .txt file | ( B ) to descrypt a .txt file: ";
    cin >> choice;
    
    // RIGHT NOW WORKING WITH OPTION A
    if (tolower(choice) == 'a'){
        // search for file 
        cout << "\nEnter file you wish to encrypt: ";
        cin >> fileName;
    };

}

// pass file as a ref
void encryptFile(fstream &input, fstream &output, int ENCRYPT){
    char content; // hold changed content
    input.get(content); // first char of the file
    
    // as long file dont end; loop
    while (!input.fail())
    {
       content += ENCRYPT;
       output.put(content); // put in encrypted.txt the encrypted content.
       input.get(content);
    }
}

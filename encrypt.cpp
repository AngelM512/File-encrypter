//-----------------------------------------------
//author: Angel Moreta
//-----------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// function prototypes
void clearScreen();
char menu(string &fileName, fstream &input);
void encryptFile(fstream &input, fstream &output, int);
void decryptFile(fstream &input, fstream &output);

int main(){
    // Vars + Objects
    const int ENCODE = 10;
    char choice;
    string fileName;
    const string fileEncryptedName = "encrypted.txt"; 
    const string fileDescrypt = "descrypted.txt";
    //create file object 
    fstream fileFilter;
    fstream encryptedFile;

    // display menu + return a char
    choice = menu(fileName, fileFilter);

    //clear
    clearScreen();  
    
    switch (choice)
    {
    case 'a':
        fileFilter.open(fileName, ios::in);
        encryptedFile.open(fileEncryptedName, ios::out);
        /* call function */
        encryptFile( fileFilter, encryptedFile, ENCODE);
        break;
    case 'b':
        encryptedFile.open(fileEncryptedName, ios::in);
        fileFilter.open(fileDescrypt, ios::out);
        /* call function */
        decryptFile(encryptedFile, fileFilter);
        break;
    
    }

    // close files, end program
    fileFilter.close();
    encryptedFile.close();
    cout << "File has been closed\n" << endl;
    return 0;
};

// pass file as a ref
void encryptFile(fstream &input, fstream &output, int ENCRYPT){
    char content; // hold changed content
    input.get(content); // first char of the file
    
    // as long file dont end; loop
    while ( !input.fail() )
    {
       content += ENCRYPT;
       output.put(content); // put in encrypted.txt the encrypted content.
       input.get(content);
    }
    cout << "\n\n\n\n\n\n\n\n";
    cout << "File was encrypted and save as --> encrypted.txt" << endl;
}

void decryptFile(fstream &input, fstream &output)
{
    char content;
    input.get(content);
    // as long file dont end; loop
    while ( !input.fail() )
    {
       content -= 10;
       output.put(content);
       input.get(content);
    };
    cout << "\n\n\n\n\n\n\n\n";
    cout << "File was decrypted and save as --> decrypted.txt" << endl;

}

void clearScreen()
{ 
    // clear the screen 
    cout << string( 100, '\n' );
}

char menu(string &fileName, fstream &input) 
{
    bool flag = true;
    char choice;
    cout << "\n\n* Welcome to encrypter by Angel Moreta *\n\n"; // welcome user
   
    do {
        cout << "( A ) to encrypt a .txt file | ( B ) to descrypt a .txt file: ";
        cin >> choice;
        if ( tolower( choice ) == 'a' )
        {
            cout << "Enter file file: ";
            cin >> fileName;
            
            // check if file exist
            input.open(fileName);
            if (!input)
            {
                cout << "NON-Existing file; try again" << endl;
                continue;
                };

            // break loop
            flag = false;
        } else if ( tolower( choice ) == 'b' )
        {
            // return choice val + end loop
            return choice;
            flag = false;
        }
        else
        {
            cout << "\n\n* Functionality not available *\n\n";
           
        } 
    } while (flag == true);
    
    return tolower( choice );
};




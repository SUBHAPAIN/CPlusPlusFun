#include <iostream>
#include <cstdlib> // for system()
#include <windows.h> // for sleep
#include <ctime> // for time()
using namespace std;

void pause(int t){                                // to sleep some time
    Sleep(t * 1000);
}

void countdown(int s) {
    while (s > 0) {
        cout << "\r"<<s<< " seconds remaining..." << flush;  // overwrite same line
        pause(1);  // Wait for 1 second
        s--;
    }
    cout << endl;
}

int choice(){                           // for choose the option..
    int c;
    int attempts = 3;

    while (attempts > 0){
        cout<<"\n\nINPUT YOUR CHOICE:";
        cin >> c;
        if (cin.fail()){                    // cin.fail check input is fail
            cin.clear();                    // clear the error flag
            cin.ignore(1000 , '\n');        // ignore the worng input
            attempts--;
            cout<<"\nInvaid input.. ("<<attempts<<" Left)";
        }
        else {
            break;
        }
    }

    if (attempts == 0){
            cout<<"\n\n\n\t\t\t!!!! Going Back.......";
            pause(1);
    }
    return c;
}

void t_quiz();
    int asking();
void Design();
void mquiz();
void tic_tac_toe();
    void reset();
    void model();
    bool checkvictory();
    bool checktie();
    void input();
void math_operation();
void s_media();

int main(){
    Top:
    int i;
    system("cls || clear");
    cout<<"----------  H   O   M   E  ----------\n\n\n";
    for (i = 0; i < 65; i++){
        cout<<"=";
    }
    cout<<"\n\n1. TECH QUIZ GAME:\n";
    for (i = 0; i < 50; i++){
        cout<<"-";
    }
    cout<<"\n2. DESIGN BY LOOP:\n";
    for (i = 0; i < 50; i++){
        cout<<"-";
    }
    cout<<"\n3. MATH QUIZ:\n";
    for (i = 0; i < 50; i++){
        cout<<"-";
    }
    cout<<"\n4. TIC-TAC-TOE GAME:\n";
    for (i = 0; i < 50; i++){
        cout<<"-";
    }
    cout<<"\n5. MATHEMATICAL OPRATIONS:\n";
    for (i = 0; i < 50; i++){
        cout<<"-";
    }
    cout<<"\n6. Social Media Accounts.\n";
    for (i = 0; i < 50; i++){
        cout<<"_";
    }
    cout<<"\n7. EXIT.\n\n";
    for (i = 0; i < 65; i++){
        cout<<"=";
    }
    pause(2);
    int x = choice();
    if (x == 0 || x > 7){
        cout<<"\n\nSorry I didn't get a response from you...!";
        cout<<"\nRefreshing....";
        countdown(8);
    }
    if (x == 1){
        cout<<"\nOkay....\n\n\t\t\t,Going To TECH_QUIZ Section.......";
        countdown(3);
        t_quiz();
    }
    else if (x == 2){
        cout<<"\nOkay....\n\n\t\t\t,Going To TECH_QUIZ Section.......";
        countdown(3);
        Design();
    }
    else if (x == 3){
        cout<<"\nOkay....\n\n\t\t\t,Going To MATH_Quiz Section.......";
        countdown(3);
        mquiz();
    }
    else if (x == 4){
        cout<<"\nOkay....\n\n\t\t\t,interesting..! you are going To Play (TIC-TAC-TOE)";
        countdown(3);
        tic_tac_toe();
    }
    else if (x == 5){
        cout<<"\nOkay....\n\n\t\t\t,Now you want to doing calculations..";
        countdown(3);
        math_operation();
    }
    else if (x == 6){
        cout<<"\nOkay....\n\n\t\t\tSocial Media Accounts...";
        countdown(3);
        s_media();
    }
    else if (x == 7)
        return 0;
    
    goto Top;
}
///////////////   TECH    QUIZ     SECTION    //////////////

struct quiz {
    string question;
    string options[4];
    int c_answer;
};

int asking(quiz q, int &score) {
    cout <<"\n\n"<< q.question <<"\n";

    for (int i = 0; i < 4; i++) {
        cout << i+1 << ". "<<q.options[i]<<"\n";
    }

    int answer = choice();
    if (answer == 0 || answer > 4){
        cout<< "\n\nAre You Want To Back..";
        cout<< "\nYOUR TOTAL SCORE IS : "<<score<<endl;
        pause(2);
        countdown(9);
        return 1;
    }

    if (answer == q.c_answer) {
        cout << "\nCorrect!\n";
        score++;
    } else {
        cout << "Wrong! The correct answer was \" " << q.options[q.c_answer] << " \".\n";
    }
    
}

void t_quiz() {
    system("cls || clear");
    srand(time(0));                 // for rand()
    quiz Q[50]{                     // struct data type(input qustions)
        {"What is the main function of a CPU?", {"Storage", "Processing", "Input", "Output"}, 2},
        {"Which company developed the Android operating system?", {"Apple", "Google", "Microsoft", "IBM"}, 2},
        {"What does HTML stand for?", {"Hyperlink Markup Language", "HyperText Markup Language", "HomeTool Markup Language", "HyperText Machine Language"}, 2},
        {"What is the full form of RAM?", {"Random Access Memory", "Read Access Memory", "Run Access Memory", "Real Access Memory"}, 1},
        {"What type of language is Python?", {"Low-level", "Assembly", "High-level", "Machine"}, 3},
        {"Which of these is an example of IoT?", {"Laptop", "Smartwatch", "Printer", "Monitor"}, 2},
        {"Who invented the World Wide Web?", {"Bill Gates", "Steve Jobs", "Tim Berners-Lee", "Linus Torvalds"}, 3},
        {"Which device is used to connect a computer to the internet?", {"Scanner", "Modem", "Printer", "Projector"}, 2},
        {"What is the main function of an operating system?", {"To compile code", "To manage hardware and software resources", "To process data", "To perform calculations"}, 2},
        {"What does SQL stand for?", {"Structured Query Language", "Standard Query Language", "Simple Query Language", "System Query Language"}, 1},
        {"Which programming language is primarily used for web development?", {"Python", "C++", "HTML", "Java"}, 3},
        {"What is the primary function of a router?", {"To store data", "To send data across networks", "To print data", "To calculate data"}, 2},
        {"In computer science, what does AI stand for?", {"Automated Intelligence", "Advanced Intelligence", "Artificial Intelligence", "Applied Intelligence"}, 3},
        {"Which is a type of malware?", {"Application", "Spreadsheet", "Virus", "Database"}, 3},
        {"Which storage is volatile?", {"Hard Disk", "SSD", "RAM", "DVD"}, 3},
        {"What does URL stand for?", {"Universal Resource Locator", "Uniform Resource Locator", "Uniform Research Locator", "Universal Research Locator"}, 2},
        {"Which language is known as the 'mother of all languages' in computer programming?", {"Python", "C", "Java", "JavaScript"}, 2},
        {"Who is known as the 'father of computers'?", {"Bill Gates", "Charles Babbage", "Alan Turing", "Steve Jobs"}, 2},
        {"What is used to protect a computer network?", {"Keyboard", "Firewall", "Monitor", "Mouse"}, 2},
        {"Which part of a computer performs calculations?", {"RAM", "Hard Disk", "Processor", "Mouse"}, 3},
        {"Which programming language is best known for data analysis?", {"Python", "Java", "C++", "HTML"}, 1},
        {"What does USB stand for?", {"Universal Serial Bus", "Universal System Bus", "United System Bus", "Universal Storage Bus"}, 1},
        {"What is a byte?", {"1 bit", "4 bits", "8 bits", "16 bits"}, 3},
        {"Which of these is an input device?", {"Monitor", "Printer", "Mouse", "Speaker"}, 3},
        {"What type of software is Microsoft Word?", {"Operating System", "System Software", "Utility Software", "Application Software"}, 4},
        {"In binary, what number does '101' represent?", {"3", "4", "5", "6"}, 3},
        {"Which protocol is used to transfer files over the Internet?", {"HTTP", "FTP", "SMTP", "POP"}, 2},
        {"Which is not an operating system?", {"Linux", "Windows", "Oracle", "MacOS"}, 3},
        {"Which unit measures processing speed?", {"Hertz", "Inches", "Bytes", "Pixels"}, 1},
        {"What does GUI stand for?", {"Graphical User Internet", "Global User Interface", "Graphical User Interface", "Graphic Usage Interface"}, 3},
        {"What does IP in IP address stand for?", {"Internet Program", "Internet Protocol", "Internet Password", "Internal Protocol"}, 2},
        {"What is a gigabyte?", {"1024 bytes", "1024 kilobytes", "1024 megabytes", "1024 bits"}, 3},
        {"Which of these is an optical storage device?", {"SSD", "Hard Drive", "RAM", "CD"}, 4},
        {"What type of software is Linux?", {"Firmware", "Application Software", "Operating System", "Utility Software"}, 3},
        {"What is the smallest unit of data in computing?", {"Bit", "Byte", "Kilobyte", "Megabyte"}, 1},
        {"Who co-founded Microsoft?", {"Steve Jobs", "Larry Page", "Mark Zuckerberg", "Bill Gates"}, 4},
        {"Which of these is a popular database management system?", {"Photoshop", "SQL Server", "AutoCAD", "Excel"}, 2},
        {"What is the term for upgrading parts of a computer?", {"Networking", "Overclocking", "Cloud computing", "Upgrading"}, 4},
        {"Which of these is a browser?", {"Linux", "Windows", "Chrome", "iOS"}, 3},
        {"What does HTTP stand for?", {"HyperText Transfer Protocol", "Hyper Transfer Text Protocol", "HighText Transfer Protocol", "Hyperlink Text Transfer Protocol"}, 1},
        {"Which is a key component of AI?", {"Algorithm", "HTML", "CSS", "FTP"}, 1},
        {"What type of language is Assembly?", {"High-level", "Low-level", "Object-oriented", "Functional"}, 2},
        {"What is used to view web pages?", {"Compiler", "Router", "Browser", "IDE"}, 3},
        {"Which company is known for the iPhone?", {"Google", "Samsung", "Apple", "Microsoft"}, 3},
        {"Which protocol secures data on the internet?", {"HTTP", "FTP", "SMTP", "HTTPS"}, 4},
        {"What is malware?", {"Hardware", "Software", "Harmful software", "Harmful hardware"}, 3},
        {"What does CSS stand for?", {"Cascading Style Sheets", "Coding Style Sheets", "Computer Style Sheets", "Color Style Sheets"}, 1},
        {"Which is a type of cloud storage?", {"Dropbox", "Microsoft Word", "Excel", "Linux"}, 1},
        {"What is the role of a compiler?", {"To execute programs", "To translate code", "To design web pages", "To store data"}, 2},
        {"Which of these devices is used for output?", {"Keyboard", "Mouse", "Printer", "RAM"}, 3}
    };

    int score = 0;
    for (int i = 0; i < 75; i++)
    {
    cout<<"=";
    }
    printf("\n\t\t W  E  L  L  C  O  M  E_   T  O _   Q  U  I  Z.\n\n\t\t\t(NOTE:To Exit Answer Zero.)\n");
    for (int i = 0; i < 75; i++)
    {
    cout<<"=";
    }
    // shuffle question
    for (int i = 0; i < 50; i++) {
        int randomIndex = rand() % 50;
        swap(Q[i], Q[randomIndex]);         // swap the questions
    }

    // Ask questions
    for (int i = 0; i < 50; i++) {
        if((asking(Q[i], score)) == 1){
            break;
        }
    }

    cout << "\nQuiz over! You scored: " << score << " .\n";
    pause(5);
}
///////////////   DESIGN     BY      LOOP     //////////////

void Design(){
    top:
    system("cls || clear");
    for (int i = 1; i <= 10; i++){                                               //////   Wellcome section  //////
            for (int j = 1; j <= 40; j++){
                if ( i == 1 || j == 1 || i == 10 ||j == 40)
                cout<<"H ";
            else if (i == 5 && (j > 3 && j < 10))
                cout<<"";
            else if (i == 5 && j == 20)
                cout<<"Wellcome To Design section";
            else if (i ==5 && (j > 20 && j < 27))
                cout<<"";
            else {
                cout<<"  ";
               
            }
            }
            cout<<endl;
        }

    cout<<endl<<"1. DIAMOND PYRAMID";
    cout<<endl<<"\n2. HOLLOW SQUARE PATTERN";
    cout<<endl<<"\n3. INVERTED HALF-HALF PYRAMID";
    cout<<endl<<"\n4. SPECIAL_DESIGN";
    cout<<endl<<"\n5. EXIT...";
    int X = choice();
    if (X == 0 || X > 5){                               //  Wrong input //
        cout<<"\nRefreshing...";
        pause(2);
        goto top;
    }
    else if (X == 1){                                   // 1st option //
        int n;
        cout<<endl<<"\n\"DIAMOND PYRAMID\"\n";
        cout<<"ENTER A NUMBER(5-80):";
        cin>>n;
        if (n%2 == 0)           // for make odd number //
            n=n-1;

        int ns=n/2;
        int st=1;
    
        for (int i = 1; i <= n; i++){
            for (int i = 1; i <= ns; i++){
                cout<<"  ";
            }
            if (i < (n / 2 + 1))
                ns--;
            else
                ns++;
            for (int j = 1; j <= st; j++){
                cout<<"* ";
            }
            if (i < (n / 2) + 1)
                st+=2;
            else
                st-=2;
                cout<<"\n";
        }
    }

    else if (X == 2){
        int n;
        cout<<endl<<"\n\"HOLLOW SQUARE PATTERN\"\n";
        cout<<"ENTER A NUMBER(2-50):";
        cin>>n;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if ( i== 1 || j == 1 || i == n ||j == n)
                    cout<<"* ";
                else{
                    cout<<"  ";   
                }
            }
            cout<<"\n";
        }
    }

    else if (X == 3){
        int n;
        cout<<endl<<"\n\"INVERTED HALF-HALF PYRAMID\"\n";
        cout<<"ENTER A NUMBER(10-40):";
        cin>>n;
        int st=n-1;
        int ns=1;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= st; j++){
                cout<<"* ";
            }
            if (i == 1)
                cout<<"* ";
            else {
                for (int k =1 ; k <= ns; k++){
                    cout<<"  ";
                    }
                }
                ns+=2;
                for (int j = 1; j <= st; j++){
                cout<<"* ";
                }
            st--;
            cout<<endl;
        }
    }

    else if (X == 4){
        int n;
        cout<<endl<<"\n\"SPECIAL_DESIGN\"\n";
        cout<<"ENTER A NUMBER(2-10):";
        cin>>n;
        for (int i = 1; i <= 2*n-1; i++){
            for (int j = 1; j <= 2*n-1; j++){
                int a=i;
                if (i > n) a = 2*n-i;
                int b = j;
                if (j > n) b = 2*n-j;
                int x = a;
                if(a > b) x = b;
                int c = n-x+1;
                cout<<c<<" ";
            }
        cout<<endl;
        }
    }

    else if (X == 5){
        cout<<"\nOKAY.. EXiting....";
        pause(2);
        return;
    }
    A:
    cout<<"\n\nPress 1 for back..";
    int p = choice();
    if (p == 1){
        countdown(3);
        goto top;
    }
    else {
        goto A;
    }
}
////////   M   A   T   H      Q   U   I   Z   /////////////
 void mquiz()
{
    system("cls");
    cout<<"\nWellcome to Random math_quiz world\n";
    for (int i = 0; i < 50; i++){
    cout<<"=";
    }
    int score = 0;
    int a, b, c, d;
    srand(time(NULL));
    while(1){
        a = rand() % 3;
        b = rand() % 20;
        c = rand() % 10;
        if (a == 0){                                                ////   M  U  L  T  I  P  L   Y  ////
            cout<<"\n\nMultiply "<<b<<"*"<<c<<":";
            cin>>d;
            cout<<endl<<endl;
            for (int i = 0; i < 20; i++){
                cout<<"_";
                }
            if (d == b * c){
                score++;
                cout<<"\nYou Are right.\n";
            }
            else {
                cout<<"\nyou are wrong...\n";
            }
            for (int i = 0; i < 20; i++){
                cout<<"_";
            }

            cout<<"\n\n\t\t\t\t\tYour Score:"<<score;
            cout<<"\n\n\n\n\n\nDo YOu Want to play ?\n\n1). YES, Of Course.\n2). No, Lets go back.";
            int x = choice();
            if (x != 1){
                countdown(4);
                return;
            }
        }

        else if (a == 1){                                       ////   A   D   D   ////
            cout<<"\n\nADD "<<b<<"+"<<c<<":";
            cin>>d;
            cout<<endl<<endl;
            for (int i = 0; i < 20; i++){
                cout<<"_";
                }
            if (d == b + c){
                score++;
                cout<<"\nYou Are right.\n";
            }
            else {
                cout<<"\nyou are wrong...\n";
            }
            for (int i = 0; i < 20; i++){
                cout<<"_";
            }

            cout<<"\n\n\t\t\t\t\tYour Score:"<<score;
            cout<<"\n\n\n\n\n\nDo YOu Want to play ?\n\n1). YES, Of Course.\n2). No, Lets go back.";
            int x = choice();
            if (x != 1){
                countdown(4);
                return;
            }
        }

        else if (a == 2){                                       ////   S  U  B  T  R  U  C  T   ////
            cout<<"\n\nsubtruct "<<b<<"-"<<c<<":";
            cin>>d;
            cout<<endl<<endl;
            for (int i = 0; i < 20; i++){
                cout<<"_";
                }
            if (d == b - c){
                score++;
                cout<<"\nYou Are right.\n";
            }
            else {
                cout<<"\nyou are wrong...\n";
            }
            for (int i = 0; i < 20; i++){
                cout<<"_";
            }

            cout<<"\n\n\t\t\t\t\tYour Score:"<<score;
            cout<<"\n\n\n\n\n\nDo YOu Want to play ?\n\n1). YES, Of Course.\n2). No, Lets go back.";
            int x = choice();
            if (x != 1){
                countdown(4);
                return;
            }
        }
    }
}
//////////   T I C - T A C - T O E    /////////////
char matrix[3][3];
char turn = 'X';

void reset() {                          // reset the matrix
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = ' ';
        }
    }
}

void model() {
    cout << "\n";
    cout << "     |     |     " << endl;
    cout << "  " << matrix[0][0] << "  |  " << matrix[0][1] << "  |  " << matrix[0][2] << "\n";
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << matrix[1][0] << "  |  " << matrix[1][1] << "  |  " << matrix[1][2] << "\n";
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << matrix[2][0] << "  |  " << matrix[2][1] << "  |  " << matrix[2][2] << "\n";
    cout << "     |     |     " << endl;
}

bool checkvictory() {
    for (int i = 0; i < 3; i++) {                                                                 
        if ((matrix[i][0] == matrix[i][1] && matrix[i][0] == matrix[i][2] && matrix[i][0] != ' ') || 
            (matrix[0][i] == matrix[1][i] && matrix[0][i] == matrix[2][i] && matrix[0][i] != ' ')) {            // row  or column cheack
            return true;
        }
    }
    if ((matrix[0][0] == matrix[1][1] && matrix[0][0] == matrix[2][2] && matrix[0][0] != ' ') ||
        (matrix[0][2] == matrix[1][1] && matrix[0][2] == matrix[2][0] && matrix[0][2] != ' ')) {                // diagonal cheack
        return true;
    }
    return false;
}

bool checktie() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void input() {
    int digit;
    int row = -1, column = -1;
    while (true) {
        if (turn == 'X') {
            cout << "Enter player X: ";
        } else {
            cout << "Enter player O: ";
        }
        cin >> digit;

        if (digit < 1 || digit > 9) {
            cout << "Invalid input. Please enter a number between 1 and 9." << endl;
            continue;
        }

        switch (digit) {
        case 1: 
            row = 0; 
            column = 0; 
            break;
        case 2: 
            row = 0; 
            column = 1; 
            break;
        case 3: 
            row = 0; 
            column = 2; 
            break;
        case 4: 
            row = 1; 
            column = 0; 
            break;
        case 5: 
            row = 1; 
            column = 1; 
            break;
        case 6: 
            row = 1;
            column = 2; 
            break;
        case 7:    
            row = 2; 
            column = 0; 
            break;
        case 8: 
            row = 2; 
            column = 1; 
            break;
        case 9: 
            row = 2; 
            column = 2; 
            break;
        default: cout << "Invalid input" << endl; return;
    }

        if (matrix[row][column] != 'X' && matrix[row][column] != 'O') {             /// insure thet the place is not filled
            matrix[row][column] = turn;
            model();
            turn = (turn == 'X') ? 'O' : 'X';
            break;
        } else {
            cout << "Place is already filled. Try again." << endl;
        }
    }
}

void tic_tac_toe(){
    int op;
    do {
        system("cls");
        cout << "\nWelcome to the TIC-TAC-TOE GAME" << endl;
        cout << "\nThe numbers represent the positions:\n" << endl;
        cout << "     |     |     " << endl;
        cout << "  1  |  2  |  3  \n";
        cout << "_____|_____|_____" << endl;
        cout << "     |     |     " << endl;
        cout << "  4  |  5  |  6  \n";
        cout << "_____|_____|_____" << endl;
        cout << "     |     |     " << endl;
        cout << "  7  |  8  |  9  \n";
        cout << "     |     |     " << endl;

        cout << "\nFirst player is player X" << endl;
        cout << "Second player is player O" << endl;
        turn='X';

        reset();
        model();

        while (true) {
            input();
            if (checkvictory()) {
                cout<<"\n-------------------------------------------\n";
                cout << "Player " << (turn == 'X' ? 'O' : 'X') << " wins....!" << endl;
                cout<<"\n-------------------------------------------\n";
                break;
            }
            if (checktie()) {
                cout << "It's a tie..!" << endl;
                break;
            }
        }

        cout << "\nDo you want to play again?" << endl;
        cout << "1. Yes\n2. No" << endl;
        cout << "Enter no.: ";
        cin >> op;
    } while (op == 1);
    cout<<"\nOk going Back..\n";
    countdown(3);
}
//////  M  A  T  H  -  O  P  R  A  T  I  O  N   //////
void math_operation(){
    top:
    system("cls");
    for(int i = 0; i <= 14; i++){
        cout<<"+-";
    }
    cout<<"\nArithmatic Operation Section:\n";
    for(int i = 0; i <= 14; i++){
        cout<<"+-";
    }
    cout<<endl<<endl;

    for (int i = 0; i < 20; i++){
        cout<<"_";
    }
    cout<<"\n1. Addition.\n";
    for (int i = 0; i < 20; i++){
        cout<<"_";
    }
    cout<<"\n2. Subtraction.\n";
    for (int i = 0; i < 20; i++){
        cout<<"_";
    }
    cout<<"\n3. MUltipication.\n";
    for (int i = 0; i < 20; i++){
        cout<<"_";
    }
    cout<<"\n4. Divition.\n";
    for (int i = 0; i < 20; i++){
        cout<<"_";
    }
    cout<<"\n5. Go Back Home.\n";
    for (int i = 0; i < 20; i++){
        cout<<"_";
    }
    int ans;
    int c = choice();
    if (c == 0 || c > 5){
        goto top;
    }
    else if (c == 1){
        int a, b;
        cout<<"\ninput both Number:\n";
        cin>>a>>b;
        ans = a + b;
    }
    else if (c == 2){
        int a, b;
        cout<<"\ninput both Number:\n";
        cin>>a>>b;
        ans = a - b;
    }
    else if (c == 3){
        int a, b;
        cout<<"\ninput both Number:\n";
        cin>>a>>b;
        ans = a * b;
    }
    else if (c == 4){
        int a, b;
        cout<<"\ninput both Number:\n";
        cin>>a>>b;
        ans = a / b;
    }
    cout<<endl<<endl;
    if(c != 5){
        for (int i = 0; i < 3; i++){
            cout<<"+ - * / ";
        }
        cout<<"\nAnswer is: "<<ans<<endl;
        for (int i = 0; i < 3; i++){
            cout<<"+ - * / ";
        }
        cout<<endl;
        countdown(10);
        goto top;
    }
    cout<<"Exiting...";
    pause(2);
}
/////  S o c i a l   M e d i a   //////
void s_media(){
    top:
    system("cls");
    cout<<"Hiii...\nDear user what do want to view:\n";
    cout<<"1) Instagram account.\n";
    cout<<"2) Youtube channel.\n";
    cout<<"3) LinkedIn Profile.\n";
    cout<<"4) GitHub Account.\n";
    cout<<"5) Not Intersted.\n";
    int x = choice();
    if (x == 0 || x > 5){
        cout<<"\nwrong Input.....!";
        pause(5);
    }
    else if (x == 1){
        system("start https://www.instagram.com/subhapain604/");
        pause(5);
    }
    else if (x == 2){
        system("start https://www.youtube.com/@Shorts_Master_1234");
        pause(5);
    }
    else if (x == 3){
        system("start https://www.linkedin.com/in/subhapain/");
        pause(5);
    }
    else if (x == 4){
        system("start https://github.com/SUBHAPAIN");
        pause(5);
    }
    else if (x == 5){
        return;
    }
    goto top;
}
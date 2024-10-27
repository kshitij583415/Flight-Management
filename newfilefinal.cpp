// #include <iostream>
// #include <string>
// #include <algorithm>
// #include <vector>
// #include <fstream>
// #include <sstream>
// #include <stdlib.h>
// #include <stdio.h>
// #include <iomanip>
// #include "displaytrain.h"
// #include "station.h"
// #include "userguid.h"
// #include "time.h"
// #include <ctime>
// #include <stdexcept>
#include<bits/stdc++.h>

using namespace std;


class Seatlayout
{
public:
    int numsofRows;
    int seatperRows = 6;
    vector<vector<int>> array2D;
    vector<int> booked;

    // default constructor
    Seatlayout()
    {
    }

    // display the seatlayout of every coach
    void intialize(string file_name)
    {
        ifstream file(file_name);

        if (file.is_open())
        {
            string line;
            while (getline(file, line))
            {
                istringstream iss(line);
                vector<int> row;
                int number;
                while (iss >> number)
                {
                    row.push_back(number);
                }
                array2D.push_back(row);
            }

            file.close();
        }
        else
        {
            cout << "Unable to open the file." << std::endl;
        }
    }

    void display()
    {
        // cout << " Available seats" << endl;
        // for (int i = 0; i < numsofRows; i++)
        // {
        //     for (int j = 0; j < 6; j++)
        //     {
        //         if (array2D[i][j] == booked[i])
        //         {
        //             cout << " ";
        //         }
        //         else
        //         {
        //             cout << array2D[i][j];
        //         }
        //     }
        //     cout << endl;
        // }
        display2d(array2D);
    }
};

class TrainCoach
{
public:
    string coachtype;
    int coachnumber;
    int availableseats;
    // composition relation
    Seatlayout tcoach;
    // default constructor
    TrainCoach()
    {
    }

    // parameterised constructor
    TrainCoach(string a, int b, int c, Seatlayout d)
    {
        this->coachtype = a;
        this->coachnumber = b;
        this->availableseats = c;
        this->tcoach = d;
    }
    void printcoachdetails()
    {
        cout << coachtype << endl;
        cout << coachnumber << endl;
        cout << availableseats << endl;
        tcoach.display();
    }
};

class Train
{
public:
    int trainNumber;
    string trainName;
    int numOfCoaches;
    string locoType;
    double maxspeed;
    // agregation relation
    vector<TrainCoach> tc;
    // default constructor
    Train()
    {
    }

    // parameterised constructor
    Train(int a, string h, int num, string loco, double p)
    {
        this->trainNumber = a;
        this->trainName = h;
        this->numOfCoaches = num;
        this->locoType = loco;
        this->maxspeed = p;
    }

    void addcoach(TrainCoach t)
    {
        tc.push_back(t);
    }

    void view()
    {
        for (int i = 0; i < tc.size(); i++)
        {
            string p = "Coach";
            printBoxWithLabel(p.append(to_string(i + 1)));
        }
    }

    void printtriandetail()
    {
        cout << trainName << endl;
        cout << trainNumber << endl;
        cout << numOfCoaches << endl;
        cout << locoType << endl;
        cout << maxspeed << endl;
        view();
    }
};

class Station
{
public:
    string name;
    string state;
    double meanSeaLevel;
    int totalStaff;
    string stationMaster;

    // default constructor
    Station()
    {
    }

    // parameterised constructor
    Station(string a, string b, double c, int d, string e)
    {
        this->name = a;
        this->state = b;
        this->meanSeaLevel = c;
        this->totalStaff = d;
        this->stationMaster = e;
    }
};

class Route
{
public:
    int numOfstations;
    double distancetravelled;
    string form;
    string to;
    // agregation relation
    vector<Station> rt;
    Train *t1;
    // default constructor
    Route()
    {
    }

    // parameterised constructor
    Route(int a, double b)
    {
        this->numOfstations = a;
        this->distancetravelled = b;
        // this->form = rt[0].name;
        // this->to = rt[rt.size()-1].name;
    }

    void loadstation(vector<Station> t)
    {
        rt = t;
        for (int i = 0; i < rt.size(); i++)
        {
            printBoxWithLabel(rt[i].name);
        }
    }

    void displayroute()
    {
        cout << numOfstations << endl;
        cout << distancetravelled << endl;
        cout << form << endl;
        cout << to << endl;
    }

    void saveDataToFile(const vector<Station> &stations, const string &filename)
    {
        ofstream file(filename);

        if (file.is_open())
        {
            for (const auto &station : stations)
            {
                file << station.name << "," << station.state << "," << station.meanSeaLevel << ","
                     << station.totalStaff << "," << station.stationMaster << "\n";
            }

            file.close();
            cout << "Data saved to " << filename << endl;
        }
        else
        {
            cerr << "Error: Unable to open file " << filename << endl;
        }
    }

    vector<Station> loadDataFromFile(const string &filename)
    {
        vector<Station> stations;
        ifstream file(filename);

        if (file.is_open())
        {
            string line;
            while (getline(file, line))
            {
                Station station;
                size_t pos = 0;
                string token;

                // Parse comma-separated values
                for (int i = 0; i < 5; ++i)
                {
                    pos = line.find(',');
                    token = line.substr(0, pos);
                    line.erase(0, pos + 1);

                    switch (i)
                    {
                    case 0:
                        station.name = token;
                        break;
                    case 1:
                        station.state = token;
                        break;
                    case 2:
                        station.meanSeaLevel = stod(token);
                        break;
                    case 3:
                        station.totalStaff = stoi(token);
                        break;
                    case 4:
                        station.stationMaster = token;
                        break;
                    default:
                        break;
                    }
                }

                stations.push_back(station);
            }

            file.close();
            // cout << "Data loaded from " << filename << endl;
        }
        else
        {
            cerr << "Error: Unable to open file " << filename << endl;
        }

        return stations;
    }

    Station findstation(string a)
    {
        Station t;
        for (int i = 0; i < rt.size(); i++)
        {
            if (rt[i].name == a)
            {
                t = rt[i];
            }
        }
        return t;
    }

    int countstation(Station a, Station b)
    {
        int count = 0;
        bool foundStartStation = false;

        for (int i = 0; i < rt.size(); i++)
        {
            if (rt[i].name == a.name)
            {
                foundStartStation = true;
            }

            if (foundStartStation)
            {
                count++;

                if (rt[i].name == b.name)
                {
                    // Stop counting when we reach station 'b'
                    break;
                }
            }
        }

        // If either station 'a' or station 'b' is not found, return -1 indicating invalid input.
        if (!foundStartStation || count == rt.size())
        {
            return -1;
        }

        return count - 1; // Excluding the start station 'a' from the count.
    }
};

class Paymentdetails
{
public:
    int tid;
    string modeofpayment;
    double amtpaid;

    // default constructor
    Paymentdetails()
    {
    }

    // parameterised constuctor
    Paymentdetails(int a, string b, double f)
    {
        this->tid = a;
        this->modeofpayment = b;
        this->amtpaid = f;
    }

    // print payment details of payment
    void printPaymentdetails()
    {
        cout << "********************************************" << endl;
        cout << "*            Payment Details              *" << endl;
        cout << "********************************************" << endl;
        cout << "* Transaction Id:   " << setw(18) << left << tid << " *" << endl;
        cout << "* Mode of payment:  " << setw(18) << left << modeofpayment << " *" << endl;
        cout << "* Amount paid:      $" << setw(17) << left << amtpaid << " *" << endl;

        // Get the time string
        std::string timeStr = displaytime();
        cout << "* Time:             " << setw(18) << left << timeStr << " *" << endl;

        cout << "********************************************" << endl;
    }
};

class ticket
{
public:
    int pnr;
    string from;
    string to;
    double fare;
    double distance;
    string bordingstation;
    string destination;
    string time_taken;
    int trainnumber;
    int coachnumber;
    string coachtype;

    // default constructor
    ticket()
    {
    }

    // parameterised constructor
    ticket(int a, string b, string c, double d, double e, string h, int i, int k, string j)
    {
        this->pnr = a;
        this->from = b;
        this->to = c;
        this->fare = d;
        this->distance = e;
        this->time_taken = h;
        this->trainnumber = i;
        this->coachnumber = k;
        this->coachtype = j;
    }

    void displayticket()
    {
        cout << "********************************************" << endl;
        cout << "*                Ticket Details             *" << endl;
        cout << "********************************************" << endl;
        cout << "* PNR:        " << setw(30) << left << pnr << " *" << endl;
        cout << "* From:       " << setw(30) << left << from << " *" << endl;
        cout << "* To:         " << setw(30) << left << to << " *" << endl;
        cout << "* Fare:       $" << setw(29) << left << fare << " *" << endl;
        cout << "* Distance:   " << setw(30) << left << distance << " *" << endl;
        cout << "* Time Taken: " << setw(30) << left << time_taken << " *" << endl;
        cout << "* Train No:   " << setw(30) << left << trainnumber << " *" << endl;
        cout << "* Coach Type: " << setw(30) << left << coachtype << " *" << endl;
        cout << "********************************************" << endl;
    }
};

class OrderFoodInTrain
{
public:
    double ordertotal;
    int ordid;
    int num;
    string listofitems[10];

    // default constructor
    OrderFoodInTrain()
    {
    }

    // parameterised constructor
    OrderFoodInTrain(double a, int b, string c[10], int n)
    {
        this->ordertotal = a;
        this->ordid = b;
        this->num = n;
        for (int i = 0; i < num; i++)
        {
            this->listofitems[i] = c[i];
        }
    }

    // toprintmneu
    void printmenu()
    {
        printBoxFromFile("menu.txt");
    }

    // diplay order details
    void display()
    {
        cout << ordertotal << endl;
        cout << ordid << endl;
        for (int i = 0; i < num; i++)
        {
            cout << listofitems[i] << " ";
        }
    }

    void placeFoodOrder()
    {
        double total;
        int orderId;
        int numItems;

        // Get order details from the user
        orderId = rand();

        cout << "Enter total amount: $";
        cin >> total;

        cout << "Enter the number of items: ";
        cin >> numItems;

        if (numItems > 10)
        {
            cout << "Maximum number of items allowed is 10." << endl;
            return;
        }

        string items[10];
        printmenu();
        for (int i = 0; i < numItems; i++)
        {
            cout << "Enter item " << i + 1 << ": ";
            cin.ignore(); // To consume the newline character left by the previous cin
            getline(cin, items[i]);
        }

        // Create an instance of OrderFoodInTrain using the user input
        OrderFoodInTrain order(total, orderId, items, numItems);

        // Display the order details
        cout << "\nYour order details:\n";
        order.display();
        cout << endl;
    }
};

class userguide
{
public:
    void registration()
    {
        printBoxFromFile("registration.txt");
    }

    void signup()
    {
        printBoxFromFile("signup.txt");
    }

    void forgotaccountdetails()
    {
        printBoxFromFile("forget_password.txt");
    }

    void farebreakdown()
    {
        printBoxFromFile("fare.txt");
    }

    void cancelledticket()
    {
        printBoxFromFile("cancelticket.txt");
    }

    void usermannual()
    {
        printBoxFromFile("usermannual.txt");
    }

    void contactus()
    {
        printBoxFromFile("contact.txt");
    }
};

/*----------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------*/

class username
{
public:
    string name;
    string password;
    string question;
    string answer;
    int loginid;
    vector<int> v;
    // default constructor
    username()
    {
    }

    // parameterised constructor
    username(string n, string psd, string question, string answer)
    {
        this->name = n;
        this->password = psd;
        this->question = question;
        this->answer = answer;
    }

    username login(vector<string> &username, vector<string> &pwd, vector<string> &question, vector<string> &index, vector<string> &answer);
    username Register(vector<string> &question);
    void forgot_password(vector<string> &username, vector<string> &question, vector<string> &index, vector<string> &answer, vector<string> password);
};

class PaymentDet
{
private:
    static PaymentDet *instance;
    int tid;
    std::string modeofpayment;
    double amtpaid;
    PaymentDet() : tid(0), modeofpayment(""), amtpaid(0.0) {}

public:
    static PaymentDet *getInstance()
    {
        if (!instance)
        {
            instance = new PaymentDet();
        }
        return instance;
    }

    void setTransactionId(int id)
    {
        tid = id;
    }

    void setModeOfPayment(const std::string &mode)
    {
        modeofpayment = mode;
    }

    void setAmountPaid(double amount)
    {
        amtpaid = amount;
    }

    void displayPaymentDetails()
    {
        std::cout << "********************************************" << std::endl;
        std::cout << "*            Payment Details              *" << std::endl;
        std::cout << "********************************************" << std::endl;
        std::cout << "* Transaction Id:   " << tid << " *" << std::endl;
        std::cout << "* Mode of payment:  " << modeofpayment << " *" << std::endl;
        std::cout << "* Amount paid:      $" << amtpaid << " *" << std::endl;
        std::cout << "********************************************" << std::endl;
    }
};

class TrainBooking
{
public:
    double fare;
    string ticketbooked;
    vector<int> seatno;
    long long int pnr;
    ticket *tick;
    Route r;
    Paymentdetails *p1;
    vector<username> name;
    // default constructor
    TrainBooking()
    {
    }

    // parameterised constructor
    TrainBooking(double f, string l, long long int p2)
    {
        this->fare = f;
        this->ticketbooked = l;
        this->pnr = p2;
    }

    void bookticket(username u, Route r)
    {
        if (!u.loginid)
            return;
        int a, b, n;
        string ta1, t2;
        r.loadstation(r.loadDataFromFile("stations.txt"));
        cout << "Where whould you like to start your journey from?" << endl;
        cin >> ta1;
        Station from = r.findstation(ta1);
        if (from.name != ta1)
            cout << "Enter vlaid name" << endl;
        cout << "Destination" << endl;
        cin >> t2;
        Station to = r.findstation(t2);
        if (to.name != t2)
            cout << "Enter vlaid name" << endl;
        int count = r.countstation(from, to);
        cout << count << endl;

        double fare1 = count * 10.88;
        cout << "choose coach" << endl;
        r.t1->view();
        cin >> a;
        TrainCoach f = r.t1->tc[a - 1];
        cout << "choose seat" << endl;
        r.t1->tc[a - 1].tcoach.display();
        cout << "Number of seats to book" << endl;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> b;
            seatno.push_back(b);
            r.t1->tc[a - 1].tcoach.booked.push_back(b);
        }
        int p = (count / 80) * 60;
        pnr = rand();
        tick = new ticket(pnr, ta1, t2, fare1, count * 1.6, to_string(p), r.t1->trainNumber, r.t1->tc[a - 1].coachnumber, r.t1->tc[a - 1].coachtype);
        tick->displayticket();
        printBoxWithLabel("make payment");
        cout << "select mode of payment" << endl;
        int l;
        cout << "1.UPI  2.Online banking 3.Account transfer 4.debitcard" << endl;
        cin >> l;
        cout << "to pay enter 1 else o";
        int v;
        cin >> v;
        if (v == 1)
        {
            cout << "payment successful" << endl;
        }
        string yt;
        if (l == 1)
            yt = "UPI";
        else if (l == 2)
            yt = "Online banking";
        else if (l == 3)
            yt = "Account Transfer";
        else if (l == 4)
            yt = "Debit card";
        else
            yt = "other options";
        p1 = new Paymentdetails(rand(), yt, fare1);
        p1->printPaymentdetails();
        u.v = seatno;
        name.push_back(u);
    }
};

void display(vector<string> &question)
{
    for (const auto &line : question)
    {
        cout << line << endl;
    }
    return;
}

username username::Register(vector<string> &question)
{
    string t, q, l, p;
    cout << "Enter the username" << endl;
    cin >> t;
    cout << "Enter the password" << endl;
    cin >> q;
    display(question);
    cout << "seclect a question and Enter the number" << endl;
    cin >> l;
    cout << "Enter the answer" << endl;
    cin >> p;
    username user(t, q, l, p);
    ofstream outputfile("username.txt", ios::app);
    if (outputfile.is_open())
    {
        outputfile << "\n"
                   << t;
    }

    ofstream outputfile1("password.txt", ios::app);
    if (outputfile1.is_open())
    {
        outputfile1 << "\n"
                    << q;
    }

    ofstream outputfile2("index.txt", ios::app);
    if (outputfile2.is_open())
    {
        outputfile2 << "\n"
                    << l;
    }

    ofstream outputfile8("answer.txt", ios::app);
    if (outputfile8.is_open())
    {
        outputfile8 << "\n"
                    << p;
    }
    printBoxWithLabel("Registration successfull!! login now with password");
    return user;
}

// forgot_password(username, question, index, answer, password);
void username::forgot_password(vector<string> &username, vector<string> &question, vector<string> &index, vector<string> &answer, vector<string> password)
{
    string p, l;
    cout << "Enter username" << endl;
    cin >> p;
    int q = 0;
    for (int i = 0; i < username.size(); i++)
    {
        if (p == username[i])
        {
            q = i;
        }
    }
    if (q == 0)
    {
        cout << "username not found!!Register" << endl;
        return;
    }
    // cout << q << endl;
    cout << "Please answer the following question" << endl;
    cout << question[stoi(index[q]) - 1] << endl;
    cin >> l;
    if (answer[q] == l)
    {
        cout << "Your password is :-" << password[q] << endl;
    }
    else
        cout << "wrong answer" << endl;
}

username username::login(vector<string> &usern, vector<string> &pwd, vector<string> &question, vector<string> &index, vector<string> &answer)
{
    string t, q;
    int i;
    cout << "Enter the username" << endl;
    cin >> t;
    cout << "Enter the password" << endl;
    cin >> q;
    for (i = 0; i < usern.size(); i++)
    {
        if (t == usern[i] && pwd[i] == q)
        {
            printBoxWithLabel("Login successfull!!");
            // cout << "Login successfull!!" << endl;
            break;
        }
    }
    if (i < usern.size() + 1)
    {
        // cout << "HI" << endl;
        username user(t, q, index[i], answer[i]);
        user.loginid = rand();
        return user;
    }
    /* write a code in such a way that it form s an object and it return it to the function call*/
    else if (i > usern.size() + 1)
    {
        cout << "username or password is incorrect" << endl;
        cout << "Want to register 1 esle press any key" << endl;
        cin >> i;
        if (i == 1)
            Register(question);
        else
        {
            username user1;
            user1.loginid = 0;
            return user1;
        }
    }
}
int main()
{
    string filename1 = "username.txt"; // Replace "file.txt" with your file name
    string filename2 = "password.txt";
    string filename3 = "question.txt";
    string filename4 = "index.txt";
    string filename5 = "answer.txt";

    vector<string> username1; // Vector to store the lines
    vector<string> password;  // Vector to store the lines
    vector<string> question;
    vector<string> index;
    vector<string> answer;

    ifstream fileu(filename1);
    ifstream filep(filename2);
    ifstream filei(filename4);
    ifstream filea(filename5);

    if (fileu.is_open() && filep.is_open() && filei.is_open() && filea.is_open())
    {
        string line1;
        string line2;
        string line3;
        string line4;
        while (getline(fileu, line1) && getline(filep, line2) && getline(filei, line3) && getline(filea, line4))
        {
            username1.push_back(line1);
            password.push_back(line2);
            index.push_back(line3);
            answer.push_back(line4);
        }
        fileu.close();
        filep.close();
        filei.close();
        filea.close();
    }
    else
    {
        cout << "Unable to open file." << endl;
        return 1;
    }

    ifstream fileq(filename3);
    if (fileq.is_open())
    {
        string line;
        while (getline(fileq, line))
        {
            question.push_back(line);
        }
        fileq.close();
    }
    else
    {
        cout << "Unable to open file." << endl;
        return 1;
    }

    // Print the lines stored in the vector
    // for (int i = 0; i < username.size(); i++)
    // {
    //     cout << (i + 1) << "." << username[i] << "       " << password[i] << "       " << index[i] << "       " << answer[i] << endl;
    // }
    // display(question);
    // login(username, password, question);
    // forgot_password(username, question, index, answer, password);

    // initializer_list of seatlayout
    Seatlayout st1;
    st1.numsofRows = 8;
    st1.intialize("seatlayout1.txt");
    Seatlayout st2;
    st2.numsofRows = 6;
    st2.intialize("seatlayout2.txt");
    // display2d(st1.array2D);
    // display2d(st2.array2D);
    Seatlayout st3;
    st3.numsofRows = 8;
    st3.intialize("seatlayout3.txt");
    // display2d(st3.array2D);
    Seatlayout st4;
    st4.numsofRows = 6;
    st4.intialize("seatlayout4.txt");
    // display2d(st4.array2D);
    //---------------------------------------------------------------
    // intializng the coaches of train
    TrainCoach tc1("AC2", 123, 48, st1);
    TrainCoach tc2("AC3", 456, 36, st2);
    TrainCoach tc3("GN", 789, 48, st3);
    TrainCoach tc4("GN", 321, 36, st4);
    // tc1.printcoachdetails();
    // tc2.printcoachdetails();
    // tc3.printcoachdetails();
    // tc4.printcoachdetails();
    //----------------------------------------------------------------------
    Train TREXP(853, "Vande Bharat Express", 4, "Eng-11", 180.88);
    TREXP.addcoach(tc1);
    TREXP.addcoach(tc2);
    TREXP.addcoach(tc3);
    TREXP.addcoach(tc4);
    // TREXP.view();

    // --------------------------------------------------------------------
    Route r1(4, 4);
    vector<Station> v;
    string filename = "stations.txt";
    v = r1.loadDataFromFile(filename);
    r1.rt = v;
    r1.t1 = &TREXP;
    username pl;
    // pl = pl.login(username1, password, question, index, answer);
    // pl = pl.Register(question);
    // pl.forgot_password(username1, question, index, answer, password);
    TrainBooking Tbook;
    Tbook.r = r1;

    userguide ug;

    OrderFoodInTrain OFT;
    printBoxWithLabel("WELCOME TO IR.UNITED");
    while (1)
    {
        cout << "Enter the choice" << endl;
        int choice;
        cin >> choice;
        int ugc;
        switch (choice)
        {
        case 1:
            // Assuming the necessary variables are declared and initialized
            pl = pl.login(username1, password, question, index, answer);
            Tbook.bookticket(pl, r1);
            break;
        case 2:
            pl = pl.Register(question);
            break;
        case 3:
            pl.forgot_password(username1, question, index, answer, password);
            break;
        case 4:
            pl = pl.login(username1, password, question, index, answer);
            if (pl.loginid)
            {
                OFT.placeFoodOrder();
            }
            else
            {
                cout << "please login then progress" << endl;
            }
            break;
        case 5:
            printBoxFromFile("choice.txt");
            cin >> ugc;
            switch (ugc)
            {
            case 1:
                ug.registration();
                break;
            case 2:
                ug.signup();
                break;
            case 3:
                ug.forgotaccountdetails();
                break;
            case 4:
                ug.farebreakdown();
                break;
            case 5:
                ug.cancelledticket();
                break;
            case 6:
                ug.usermannual();
                break;
            case 7:
                ug.contactus();
                break;
            default:
                cout << "Enter the valid choice for Query" << endl;
                break;
            }
            break;

        case 6:
            exit(0);
            break;
        default:
            cout << "Enter the valid choice for Query" << endl;
            break;
        }
    }

    RailSystem railSystem;

    try
    {
        Station foundStation = railSystem.findStationByName("ExampleStation");
        // Do something with the foundStation
    }
    catch (const RailSystemException &e)
    {
        std::cerr << "Rail System Error: " << e.what() << std::endl;
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Invalid Argument Error: " << e.what() << std::endl;
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "Out of Range Error: " << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "General Error: " << e.what() << std::endl;
    }
    return 0;
}
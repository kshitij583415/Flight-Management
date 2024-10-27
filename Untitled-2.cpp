#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>

// Function to print a box with label
void printBoxWithLabel(const std::string &label)
{
    int width = label.length() + 4;
    std::cout << std::string(width, '-') << std::endl;
    std::cout << "| " << label << " |" << std::endl;
    std::cout << std::string(width, '-') << std::endl;
}

class Seatlayout
{
public:
    int numsofRows;
    int seatperRows = 6;
    std::vector<std::vector<int>> array2D;
    std::vector<int> booked;

    // Default constructor
    Seatlayout() {}

    // Display the seat layout of every coach
    void initialize(std::string file_name)
    {
        std::ifstream file(file_name);

        if (file.is_open())
        {
            std::string line;
            while (std::getline(file, line))
            {
                std::istringstream iss(line);
                std::vector<int> row;
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
            std::cout << "Unable to open the file." << std::endl;
        }
    }

    void display()
    {
        std::cout << "Available seats" << std::endl;
        for (int i = 0; i < numsofRows; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (std::find(booked.begin(), booked.end(), array2D[i][j]) != booked.end())
                {
                    std::cout << " ";
                }
                else
                {
                    std::cout << array2D[i][j];
                }
            }
            std::cout << std::endl;
        }
    }
};

class TrainCoach
{
public:
    std::string coachtype;
    int coachnumber;
    int availableseats;
    // Composition relation
    Seatlayout tcoach;

    // Default constructor
    TrainCoach() {}

    // Parameterized constructor
    TrainCoach(std::string a, int b, int c, Seatlayout d)
    {
        this->coachtype = a;
        this->coachnumber = b;
        this->availableseats = c;
        this->tcoach = d;
    }

    void printcoachdetails()
    {
        std::cout << coachtype << std::endl;
        std::cout << coachnumber << std::endl;
        std::cout << availableseats << std::endl;
        tcoach.display();
    }
};

class Train
{
public:
    int trainNumber;
    std::string trainName;
    int numOfCoaches;
    std::string locoType;
    double maxspeed;
    // Aggregation relation
    std::vector<TrainCoach> tc;

    // Default constructor
    Train() {}

    // Parameterized constructor
    Train(int a, std::string h, int num, std::string loco, double p)
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
            std::string p = "Coach";
            printBoxWithLabel(p.append(std::to_string(i + 1)));
        }
    }

    void printtraindetails()
    {
        std::cout << trainName << std::endl;
        std::cout << trainNumber << std::endl;
        std::cout << numOfCoaches << std::endl;
        std::cout << locoType << std::endl;
        std::cout << maxspeed << std::endl;
        view();
    }
};

class Station
{
public:
    std::string name;
    std::string state;
    double meanSeaLevel;
    int totalStaff;
    std::string stationMaster;

    // Default constructor
    Station() {}

    // Parameterized constructor
    Station(std::string a, std::string b, double c, int d, std::string e)
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
    std::string form;
    std::string to;
    // Aggregation relation
    std::vector<Station> rt;
    Train *t1;

    // Default constructor
    Route() {}

    // Parameterized constructor
    Route(int a, double b)
    {
        this->numOfstations = a;
        this->distancetravelled = b;
    }

    void loadstation(std::vector<Station> t)
    {
        rt = t;
        for (const auto &station : rt)
        {
            printBoxWithLabel(station.name);
        }
    }

    void displayroute()
    {
        std::cout << numOfstations << std::endl;
        std::cout << distancetravelled << std::endl;
        std::cout << form << std::endl;
        std::cout << to << std::endl;
    }

    void saveDataToFile(const std::vector<Station> &stations, const std::string &filename)
    {
        std::ofstream file(filename);

        if (file.is_open())
        {
            for (const auto &station : stations)
            {
                file << station.name << "," << station.state << "," << station.meanSeaLevel << ","
                     << station.totalStaff << "," << station.stationMaster << "\n";
            }

            file.close();
            std::cout << "Data saved to " << filename << std::endl;
        }
        else
        {
            std::cerr << "Error: Unable to open file " << filename << std::endl;
        }
    }

    std::vector<Station> loadDataFromFile(const std::string &filename)
    {
        std::vector<Station> stations;
        std::ifstream file(filename);

        if (file.is_open())
        {
            std::string line;
            while (std::getline(file, line))
            {
                Station station;
                size_t pos = 0;
                std::string token;

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
            std::cout << "Data loaded from " << filename << std::endl;
        }
        else
        {
            std::cerr << "Error: Unable to open file " << filename << std::endl;
        }

        return stations;
    }

    Station findstation(std::string a)
    {
        Station t;
        for (const auto &station : rt)
        {
            if (station.name == a)
            {
                t = station;
                break;
            }
        }
        return t;
    }

    int countstation(Station a, Station b)
    {
        int count = 0;
        bool found = false;
        for (const auto &station : rt)
        {
            if (station.name == a.name)
            {
                found = true;
            }
            if (found && station.name != b.name)
            {
                count++;
            }
            if (station.name == b.name)
            {
                break;
            }
        }
        return count;
    }
};

class Paymentdetails
{
public:
    int tid;
    std::string modeofpayment;
    double amtpaid;

    // Default constructor
    Paymentdetails() {}

    // Parameterized constructor
    Paymentdetails(int a, std::string b, double f)
    {
        this->tid = a;
        this->modeofpayment = b;
        this->amtpaid = f;
    }

    // Print payment details
    void printPaymentdetails()
    {
        std::cout << tid << std::endl;
        std::cout << modeofpayment << std::endl;
        std::cout << amtpaid << std::endl;
    }
};

class ticket
{
public:
    int pnr;
    std::string from;
    std::string to;
    double fare;
    double distance;
    std::string bordingstation;
    std::string destination;
    std::string time_taken;
    int trainnumber;
    int coachnumber;
    std::string coachtype;

    // Default constructor
    ticket() {}

    // Parameterized constructor
    ticket(int a, std::string b, std::string c, double d, double e, std::string h, int i, int k, std::string j)
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
        std::cout << pnr << std::endl;
        std::cout << from << std::endl;
        std::cout << to << std::endl;
        std::cout << fare << std::endl;
        std::cout << distance << std::endl;
        std::cout << time_taken << std::endl;
        std::cout << trainnumber << std::endl;
        std::cout << coachtype << std::endl;
    }
};

class OrderFoodInTrain
{
public:
    double ordertotal;
    int ordid;
    int num;
    std::string listofitems[10];

    // Default constructor
    OrderFoodInTrain() {}

    // Parameterized constructor
    OrderFoodInTrain(double a, int b, std::string c[10], int n)
    {
        this->ordertotal = a;
        this->ordid = b;
        this->num = n;
        for (int i = 0; i < num; i++)
        {
            this->listofitems[i] = c[i];
        }
    }

    // To print menu
    void printmenu()
    {
    }

    // Display order details
    void display()
    {
        std::cout << ordertotal << std::endl;
        std::cout << ordid << std::endl;
        for (int i = 0; i < num; i++)
        {
            std::cout << listofitems[i] << " ";
        }
    }
};

class UserGuide
{
public:
    void registration()
    {
        printBoxWithLabel("registration.txt");
    }

    void signup()
    {
        printBoxWithLabel("signup.txt");
    }

    void forgotaccountdetails()
    {
        printBoxWithLabel("forget_password.txt");
    }

    void farebreakdown()
    {
        printBoxWithLabel("fare.txt");
    }

    void cancelledticket()
    {
        printBoxWithLabel("cancelticket.txt");
    }

    void usermanual()
    {
        printBoxWithLabel("usermanual.txt");
    }

    void contactus()
    {
        printBoxWithLabel("contact.txt");
    }
};

class Username
{
public:
    std::string name;
    std::string password;
    std::string question;
    std::string answer;
    int loginid;
    std::vector<int> v;

    // Default constructor
    Username() {}

    // Parameterized constructor
    Username(std::string n, std::string psd, std::string question, std::string ans)
    {
        this->name = n;
        this->password = psd;
        this->question = question;
        this->answer = ans;
    }

    Username login(std::vector<std::string> &username, std::vector<std::string> &pwd, std::vector<std::string> &question, std::vector<std::string> &index, std::vector<std::string> &answer);
    Username Register(std::vector<std::string> &question);
    void forgot_password(std::vector<std::string> &username, std::vector<std::string> &question, std::vector<std::string> &index, std::vector<std::string> &answer, std::vector<std::string> &password);
};

Username Username::Register(std::vector<std::string> &question)
{
    std::string t, q, l, p;
    std::cout << "Enter the username: ";
    std::cin >> t;
    std::cout << "Enter the password: ";
    std::cin >> q;
    for (int i = 0; i < username.size(); i++)
    {
        if (t == username[i])
        {
            std::cout << "Username already exists!" << std::endl;
            return Username();
        }
    }
    display(question);
    std::cout << "Select a question and enter the number: ";
    std::cin >> l;
    std::cout << "Enter the answer: ";
    std::cin >> p;
    Username user(t, q, l, p);
    std::ofstream outputfile("username.txt", std::ios::app);
    if (outputfile.is_open())
    {
        outputfile << "\n"
                   << t;
    }

    std::ofstream outputfile1("password.txt", std::ios::app);
    if (outputfile1.is_open())
    {
        outputfile1 << "\n"
                    << q;
    }

    std::ofstream outputfile2("index.txt", std::ios::app);
    if (outputfile2.is_open())
    {
        outputfile2 << "\n"
                    << l;
    }

    std::ofstream outputfile8("answer.txt", std::ios::app);
    if (outputfile8.is_open())
    {
        outputfile8 << "\n"
                    << p;
    }

    std::cout << "Registration successful!" << std::endl;
    return user;
}

Username Username::login(std::vector<std::string> &username, std::vector<std::string> &pwd, std::vector<std::string> &question, std::vector<std::string> &index, std::vector<std::string> &answer)
{
    std::string t, q;
    std::cout << "Enter the username: ";
    std::cin >> t;
    std::cout << "Enter the password: ";
    std::cin >> q;
    int a = -1;
    for (int i = 0; i < username.size(); i++)
    {
        if (t == username[i])
        {
            a = i;
            break;
        }
    }
    if (a == -1 || q != pwd[a])
    {
        std::cout << "Invalid username or password!" << std::endl;
        return Username();
    }
    return Username(username[a], pwd[a], question[a], answer[a]);
}

void Username::forgot_password(std::vector<std::string> &username, std::vector<std::string> &question, std::vector<std::string> &index, std::vector<std::string> &answer, std::vector<std::string> &password)
{
    std::string t, q;
    std::cout << "Enter the username: ";
    std::cin >> t;
    int a = -1;
    for (int i = 0; i < username.size(); i++)
    {
        if (t == username[i])
        {
            a = i;
            break;
        }
    }
    if (a == -1)
    {
        std::cout << "Username not found!" << std::endl;
        return;
    }
    displayquestion(a, question);
    std::cout << "Enter the number corresponding to your question: ";
    std::cin >> q;
    if (q != index[a])
    {
        std::cout << "Invalid question!" << std::endl;
        return;
    }
    std::cout << "Answer: ";
    std::string p;
    std::cin >> p;
    if (p == answer[a])
    {
        std::cout << "Your password is: " << password[a] << std::endl;
    }
    else
    {
        std::cout << "Incorrect answer!" << std::endl;
    }
}

class Railways
{
public:
    std::vector<Username> u;

    Railways() {}

    void adduser(Username a)
    {
        u.push_back(a);
    }

    void displayusers()
    {
        for (const auto &user : u)
        {
            std::cout << user.name << std::endl;
        }
    }

    void displayuserdetails(Username a)
    {
        std::cout << a.name << std::endl;
        std::cout << a.question << std::endl;
        std::cout << a.answer << std::endl;
    }

    void saveusers()
    {
        std::ofstream outputfile("username.txt");
        if (outputfile.is_open())
        {
            for (const auto &user : u)
            {
                outputfile << user.name << std::endl;
            }
            outputfile.close();
        }
        else
        {
            std::cout << "Error: Unable to open the file" << std::endl;
        }
    }

    void loadusers()
    {
        std::string line;
        std::ifstream file("username.txt");
        if (file.is_open())
        {
            while (getline(file, line))
            {
                Username user(line, "", "", "");
                u.push_back(user);
            }
            file.close();
        }
        else
        {
            std::cout << "Error: Unable to open the file" << std::endl;
        }
    }
};

int main()
{
    Railways railways;
    railways.loadusers();

    std::cout << "Welcome to Railways Management System" << std::endl;

    while (true)
    {
        std::cout << "1. Register\n2. Login\n3. Forgot Password\n4. Exit" << std::endl;
        int choice;
        std::cin >> choice;
        if (choice == 1)
        {
            Username user = railways.Register();
            if (user.name != "")
            {
                railways.adduser(user);
            }
        }
        else if (choice == 2)
        {
            Username user = railways.login();
            if (user.name != "")
            {
                std::cout << "Login successful!" << std::endl;
                railways.displayuserdetails(user);
                railways.saveusers();
            }
        }
        else if (choice == 3)
        {
            railways.forgot_password();
        }
        else if (choice == 4)
        {
            railways.saveusers();
            break;
        }
        else
        {
            std::cout << "Invalid choice! Please try again." << std::endl;
        }
    }

    return 0;
}

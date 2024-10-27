#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include "displaytrain.h"
#include "station.h"
#include "userguid.h"
#include "time.h"

// // class Station
// // {
// // public:
// //     std::string name;
// //     std::string state;
// //     double meanSeaLevel;
// //     int totalStaff;
// //     std::string stationMaster;
// // };

// // void saveDataToFile(const std::vector<Station> &stations, const std::string &filename)
// // {
// //     std::ofstream file(filename);

// //     if (file.is_open())
// //     {
// //         for (const auto &station : stations)
// //         {
// //             file << station.name << "," << station.state << "," << station.meanSeaLevel << ","
// //                  << station.totalStaff << "," << station.stationMaster << "\n";
// //         }

// //         file.close();
// //         std::cout << "Data saved to " << filename << std::endl;
// //     }
// //     else
// //     {
// //         std::cerr << "Error: Unable to open file " << filename << std::endl;
// //     }
// // }

// // std::vector<Station> loadDataFromFile(const std::string &filename)
// // {
// //     std::vector<Station> stations;
// //     std::ifstream file(filename);

// //     if (file.is_open())
// //     {
// //         std::string line;
// //         while (std::getline(file, line))
// //         {
// //             Station station;
// //             size_t pos = 0;
// //             std::string token;

// //             // Parse comma-separated values
// //             for (int i = 0; i < 5; ++i)
// //             {
// //                 pos = line.find(',');
// //                 token = line.substr(0, pos);
// //                 line.erase(0, pos + 1);

// //                 switch (i)
// //                 {
// //                 case 0:
// //                     station.name = token;
// //                     break;
// //                 case 1:
// //                     station.state = token;
// //                     break;
// //                 case 2:
// //                     station.meanSeaLevel = std::stod(token);
// //                     break;
// //                 case 3:
// //                     station.totalStaff = std::stoi(token);
// //                     break;
// //                 case 4:
// //                     station.stationMaster = token;
// //                     break;
// //                 default:
// //                     break;
// //                 }
// //             }

// //             stations.push_back(station);
// //         }

// //         file.close();
// //         std::cout << "Data loaded from " << filename << std::endl;
// //     }
// //     else
// //     {
// //         std::cerr << "Error: Unable to open file " << filename << std::endl;
// //     }

// //     return stations;
// // }

// // void printData(const std::vector<Station> &stations)
// // {
// //     for (const auto &station : stations)
// //     {
// //         std::cout << "Name: " << station.name << std::endl;
// //         std::cout << "State: " << station.state << std::endl;
// //         std::cout << "Mean Sea Level: " << station.meanSeaLevel << std::endl;
// //         std::cout << "Total Staff: " << station.totalStaff << std::endl;
// //         std::cout << "Station Master: " << station.stationMaster << std::endl;
// //         std::cout << std::endl;
// //     }
// // }

// // int main()
// // {
// //     std::vector<Station> stations;

// //     // Create Station objects and populate their values
// //     Station station1;
// //     station1.name = "Station 1";
// //     station1.state = "State 1";
// //     station1.meanSeaLevel = 100.0;
// //     station1.totalStaff = 50;
// //     station1.stationMaster = "Station Master 1";

// //     Station station2;
// //     station2.name = "Station 2";
// //     station2.state = "State 2";
// //     station2.meanSeaLevel = 200.0;
// //     station2.totalStaff = 30;
// //     station2.stationMaster = "Station Master 2";

// //     // Add Station objects to the vector
// //     stations.push_back(station1);
// //     stations.push_back(station2);

// //     // Save data to a file
// //     saveDataToFile(stations, "stations.txt");

// //     // Load data from the file
// //     std::vector<Station> loadedStations = loadDataFromFile("stations.txt");

// //     // Print the loaded data
// //     printData(loadedStations);

// //     return 0;
// // }
// // vector<vector<int>> array2D;
// // void intialize(string file_name)
// // {
// //     ifstream file(file_name);

// //     if (file.is_open())
// //     {
// //         string line;
// //         while (getline(file, line))
// //         {
// //             istringstream iss(line);
// //             vector<int> row;
// //             int number;
// //             while (iss >> number)
// //             {
// //                 row.push_back(number);
// //             }
// //             array2D.push_back(row);
// //         }

// //         file.close();
// //     }
// //     else
// //     {
// //         cout << "Unable to open the file." << std::endl;
// //     }
// // }

// class Station
// {
// public:
//     string name;
//     string state;
//     double meanSeaLevel;
//     int totalStaff;
//     string stationMaster;
//     vector<Station> loadDataFromFile(const string &filename)
//     {
//         vector<Station> stations;
//         ifstream file(filename);

//         if (file.is_open())
//         {
//             string line;
//             while (getline(file, line))
//             {
//                 Station station;
//                 size_t pos = 0;
//                 string token;

//                 // Parse comma-separated values
//                 for (int i = 0; i < 5; ++i)
//                 {
//                     pos = line.find(',');
//                     token = line.substr(0, pos);
//                     line.erase(0, pos + 1);

//                     switch (i)
//                     {
//                     case 0:
//                         station.name = token;
//                         break;
//                     case 1:
//                         station.state = token;
//                         break;
//                     case 2:
//                         station.meanSeaLevel = stod(token);
//                         break;
//                     case 3:
//                         station.totalStaff = stoi(token);
//                         break;
//                     case 4:
//                         station.stationMaster = token;
//                         break;
//                     default:
//                         break;
//                     }
//                 }

//                 stations.push_back(station);
//             }

//             file.close();
//             cout << "Data loaded from " << filename << endl;
//         }
//         else
//         {
//             cerr << "Error: Unable to open file " << filename << endl;
//         }

//         return stations;
//     }
// };
// int main()
// {
//     Station t1;
//     vector<Station> v;
//     v = t1.loadDataFromFile("stations.txt");
//     for (int i = 0; i < v.size(); i++)
//     {
//         cout << v[i].name;
//     }
//     return 0;
// }

// #include <sstream>

// // ...

// // // Inside the loop where you parse the values
// // case 2:
// // {
// //     try {
// //         station.meanSeaLevel = stod(token);
// //     } catch (const std::invalid_argument& e) {
// //         cerr << "Error: Invalid meanSeaLevel value for station " << station.name << endl;
// //         station.meanSeaLevel = 0.0; // Set a default value or handle the error accordingly
// //     }
// //     break;
// // }

class Station
{
public:
    string name;
    string state;
    double meanSeaLevel;
    int totalStaff;
    string stationMaster;
};

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
        cout << "Data loaded from " << filename << endl;
    }
    else
    {
        cerr << "Error: Unable to open file " << filename << endl;
    }

    return stations;
}

void printData(const vector<Station> &stations)
{
    for (const auto &station : stations)
    {
        cout << "Name: " << station.name << endl;
        cout << "State: " << station.state << endl;
        cout << "Mean Sea Level: " << station.meanSeaLevel << endl;
        cout << "Total Staff: " << station.totalStaff << endl;
        cout << "Station Master: " << station.stationMaster << endl;
        cout << endl;
    }
}

int main()
{
    vector<Station> stations;

    // Create Station objects and populate their values
    Station station1;
    station1.name = "Station 1";
    station1.state = "State 1";
    station1.meanSeaLevel = 100.0;
    station1.totalStaff = 50;
    station1.stationMaster = "Station Master 1";

    Station station2;
    station2.name = "Station 2";
    station2.state = "State 2";
    station2.meanSeaLevel = 200.0;
    station2.totalStaff = 30;
    station2.stationMaster = "Station Master 2";

    // Add Station objects to the vector
    stations.push_back(station1);
    stations.push_back(station2);

    // Save data to a file
    saveDataToFile(stations, "stations.txt");

    // Load data from the file
    vector<Station> loadedStations = loadDataFromFile("stations.txt");

    // Print the loaded data
    printData(loadedStations);

    return 0;
}

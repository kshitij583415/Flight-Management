
// void saveDataToFile(const vector<Station> &stations, const string &filename)
// {
//     ofstream file(filename);

//     if (file.is_open())
//     {
//         for (const auto &station : stations)
//         {
//             file << station.name << "," << station.state << "," << station.meanSeaLevel << ","
//                  << station.totalStaff << "," << station.stationMaster << "\n";
//         }

//         file.close();
//         cout << "Data saved to " << filename << endl;
//     }
//     else
//     {
//         cerr << "Error: Unable to open file " << filename << endl;
//     }
// }

// vector<Station> loadDataFromFile(const string &filename)
// {
//     vector<Station> stations;
//     ifstream file(filename);

//     if (file.is_open())
//     {
//         string line;
//         while (getline(file, line))
//         {
//             Station station;
//             size_t pos = 0;
//             string token;

//             // Parse comma-separated values
//             for (int i = 0; i < 5; ++i)
//             {
//                 pos = line.find(',');
//                 token = line.substr(0, pos);
//                 line.erase(0, pos + 1);

//                 switch (i)
//                 {
//                 case 0:
//                     station.name = token;
//                     break;
//                 case 1:
//                     station.state = token;
//                     break;
//                 case 2:
//                     station.meanSeaLevel = stod(token);
//                     break;
//                 case 3:
//                     station.totalStaff = stoi(token);
//                     break;
//                 case 4:
//                     station.stationMaster = token;
//                     break;
//                 default:
//                     break;
//                 }
//             }

//             stations.push_back(station);
//         }

//         file.close();
//         cout << "Data loaded from " << filename << endl;
//     }
//     else
//     {
//         cerr << "Error: Unable to open file " << filename << endl;
//     }

//     return stations;
// }

// void printData(const vector<Station> &stations)
// {
//     for (const auto &station : stations)
//     {
//         cout << "Name: " << station.name << endl;
//         cout << "State: " << station.state << endl;
//         cout << "Mean Sea Level: " << station.meanSeaLevel << endl;
//         cout << "Total Staff: " << station.totalStaff << endl;
//         cout << "Station Master: " << station.stationMaster << endl;
//         cout << endl;
//     }
// }

// int main()
// {
//     vector<Station> stations;

//     // Create Station objects and populate their values
//     Station station1;
//     station1.name = "Station 1";
//     station1.state = "State 1";
//     station1.meanSeaLevel = 100.0;
//     station1.totalStaff = 50;
//     station1.stationMaster = "Station Master 1";

//     Station station2;
//     station2.name = "Station 2";
//     station2.state = "State 2";
//     station2.meanSeaLevel = 200.0;
//     station2.totalStaff = 30;
//     station2.stationMaster = "Station Master 2";

//     // Add Station objects to the vector
//     stations.push_back(station1);
//     stations.push_back(station2);

//     // Save data to a file
//     saveDataToFile(stations, "stations.txt");

//     // Load data from the file
//     vector<Station> loadedStations = loadDataFromFile("stations.txt");

//     // Print the loaded data
//     printData(loadedStations);

//     return 0;
// }

#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

void ensureOutputDirectoriesExist() {
    std::error_code ec;

    fs::path logsFolder = "logs";
    fs::path outputFolder = "output";

    if(!fs::exists(logsFolder)){
        std::cout << "[INFO] 'logs/' folder missing. Creating directory..." << std::endl;
        fs::create_directory(logsFolder, ec);

        if(ec){
            std::cerr << "Error failed to create logs folder" << ec.message() << std::endl;
        } 
    }
    if (!fs::exists(outputFolder)){
        std::cout << "[INFO] 'output/' folder missing. Creating directory..." << std::endl;
        fs::create_directory(outputFolder, ec);
    }
}

// now we append mode logg here
void Logmessage(const std::string& message){
    fs::create_directories("logs");
    std::ofstream logFile("logs/app.log", std::ios::app);
    if(logFile.is_open()){
        logFile << "[LOG]" << message << "\n";
        logFile.close();
    }
}



int main() {
    ensureOutputDirectoriesExist();

    fs::path configpath = "config/config.txt";
    fs::path datapath = "data/data.csv";

    Logmessage("starting application");

    // Check if the config file exists
    if(!fs::exists(configpath)) {
        std::cerr << "configfile does not exist or path is faulty" << std::endl;
        Logmessage("ERROR: Config file missing at " + configpath.string());
        return 1;
    }
    else{
        std::cout <<"Successfully found the file in configpath" << std::endl;
    }
    
    if(!fs::exists(datapath)) {
        std::cerr << "file does not exist or path is faulty" << std::endl;
        Logmessage("ERROR: data file missing at " + datapath.string());
        return 1;
    }
    else{
    std::cout <<"Successfully found the file in datapath" << std::endl;
    }

    Logmessage("All input paths verified successfully.");


    //read the files
    std::ifstream configFile (configpath);
    std::string line;
    std::cout << "--- CONFIG FILE CONTENTS ---" << std::endl;
    while (std::getline(configFile, line)){
        std::cout << line << std::endl;
    }
    configFile.close();


        //read the files
    std::ifstream dataFile(datapath);
    std::cout << "--- DATA FILE CONTENTS ---" << std::endl;
    while (std::getline(dataFile, line)){
        std::cout << line << std::endl;
    }
    dataFile.close();

    Logmessage("Application finished running.");
    return 0;
}
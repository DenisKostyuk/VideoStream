#pragma once
#include <fstream>
#include <string>
#include <mutex>
#include <chrono>
#include<ctime>

class Logger {
private:
	std::ofstream file;
	std::mutex logMutex;
public:
    Logger() {
        file.open("log.txt", std::ios::out | std::ios::app);

        if (!file.is_open()) {
            MessageBoxA(NULL, "Logger FAILED to open file!", "ERROR", MB_OK);
        }
    }

	~Logger() {
		if (file.is_open()) file.close();
	}

    void Log(const std::string& msg) {
        std::lock_guard<std::mutex> lock(logMutex);

        auto now = std::chrono::system_clock::now();
        std::time_t time = std::chrono::system_clock::to_time_t(now);

        std::tm tm;
        localtime_s(&tm, &time);

        char buffer[64];
        strftime(buffer, sizeof(buffer),
            "%Y-%m-%d %H:%M:%S",
            &tm);

        file << buffer << " | " << msg << std::endl;
        file.flush();
    }
};
#ifndef NETCOVER_INI_WORKER_H
#define NETCOVER_INI_WORKER_H

#include <string>
#include <unordered_map>

namespace Netcover::INI
{
    class Worker
    {
        public:
            Worker(std::string file) : file(file) { }
            void setFile(std::string file) { this->file = file; }
            void read();
            void save();
            std::unordered_map<std::string, std::unordered_map<std::string, std::string>>& operator*() { return fileMap; }
            std::unordered_map<std::string, std::string>& operator[](std::string section) { return fileMap[section]; }

        private:
            std::unordered_map<std::string, std::unordered_map<std::string, std::string>> fileMap;
            std::string file;
    };
}

#endif
#include <netcover/ini/Worker.h>
#include <netcover/ini/Errors.h>
#include <netcover/exceptions/ini/FileNotFoundException.h>
#include <netcover/exceptions/ini/IncorrectFormatException.h>
#include <netcover/exceptions/general/SyscallException.h>
#include <netcover/tools/String.h>

#include <fstream>
#include <filesystem>
#include <iostream>

using namespace Netcover::INI;

void Worker::read()
{
    if(!std::filesystem::exists(file))
        throw Exceptions::INI::FileNotFoundException("File not found.");

    std::ifstream inFile(file);

    if(!inFile.is_open())
        throw Exceptions::General::SyscallException("Cannot open file.");

    std::string line, section;
    int lineCounter = 0;

    while(std::getline(inFile, line))
    {
        lineCounter++;
        Tools::String::trim(line);

        if(line.length() == 0) continue;

        if(line[0] == ';')
        {
            continue;
        }
        else if(line[0] == '[') // line defines section
        {
            line.pop_back();
            Tools::String::pop_front(line);
            Tools::String::trim(line);
            section = line;
        }
        else // line defines parameter
        {
            if(section.length() == 0)
                throw Exceptions::INI::IncorrectFormatException("Field defined outside of section.", Errors::FIELD_OUTSIDE_SECTION, lineCounter);

            std::string key, value;

            unsigned long int i;

            for(i = 0; i < line.length() && line[i] != '='; i++);

            key = line;
            key.erase(i, key.length());
            Tools::String::trim(key);

            if(key.length() == 0)
                throw Exceptions::INI::IncorrectFormatException("Field defined without key.", Errors::KEY_EMPTY, lineCounter);

            value = line;
            value.erase(0, i+1);
            Tools::String::trim(value);

            if(value.length() == 0)
                throw Exceptions::INI::IncorrectFormatException("Field defined without value.", Errors::VALUE_EMPTY, lineCounter);

            fileMap[section][key] = value;
        }
    }
}
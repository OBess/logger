#pragma once
#ifndef FILE_LOGGER_HPP
#define FILE_LOGGER_HPP

// C++
#include <string>
#include <fstream>
#include <chrono>
#include <ctime>

// Custom
#include "logger.hpp"

class file_logger : public logger
{
public:
   file_logger(const std::string &file_path) : m_file_path(file_path), m_level(1)
   {
      file.open(m_file_path, std::ios_base::app);
   }

   ~file_logger()
   {
      file.close();
   };

private:
   void open() override
   {
   }

   void write(const std::string &message) override
   {
      std::time_t time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
      file << m_level++ << ", " << std::ctime(&time) << '[' << std::endl;
      file << '\t' << message << std::endl;
      file << ']' << std::endl;
   }

   void close() override
   {
      file.flush();
   }

   std::ofstream file;
   std::string m_file_path;
   int m_level;
};

#endif //FILE_LOGGER_HPP
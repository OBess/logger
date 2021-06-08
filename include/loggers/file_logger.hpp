#pragma once
#ifndef FILE_LOGGER_HPP
#define FILE_LOGGER_HPP

// C++
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>

// Custom
#include "logger.hpp"

class file_logger : public logger
{
public:
   file_logger(const std::string &file_path) : m_file_path(file_path) {}
   ~file_logger() = default;

private:
   void open() override
   {
      file.open(m_file_path, std::ios_base::app);
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
      file.close();
   }

   std::ofstream file;
   std::string m_file_path;
   static int m_level;
};

int file_logger::m_level = 1;

#endif //FILE_LOGGER_HPP
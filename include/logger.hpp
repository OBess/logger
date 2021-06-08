#pragma once
#ifndef LOGGER_HPP
#define LOGGER_HPP

// C++
#include <string>

class logger
{
public:
   logger(const int &lvl = 0) : m_level(lvl) {}
   virtual ~logger() = default;

   void Log(const std::string &message) const
   {
      this->open();
      this->write(message);
      this->close();
   }

protected:
   virtual void open() const = 0;
   virtual void write(const std::string &message) const = 0;
   virtual void close() const = 0;

   const int &getLevel()
   {
      return m_level++;
   }

private:
   int m_level;
};

#endif //LOGGER_HPP
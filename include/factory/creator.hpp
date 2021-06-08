#pragma once
#ifndef CREATOR_HPP
#define CREATOR_HPP

// C++
#include <string>

// Custom
#include "../loggers/logger.hpp"

class creator
{
public:
   virtual ~creator() = default;

   void Log(const std::string &message)
   {
      logger *logg = this->getLogger();
      logg->Log(message);
      delete logg;
   }

protected:
   virtual logger *getLogger() const = 0;
};

#endif //CREATOR_HPP
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
   virtual logger *getLogger() const = 0;
};

#endif //CREATOR_HPP
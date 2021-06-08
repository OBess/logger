// C++
#include <iostream>
#include <memory>

// Custom
#include "include/factory/console_creator.hpp"
#include "include/factory/file_creator.hpp"

int main()
{
   // Test 1 - console logger
   auto console = std::make_unique<console_creator>();
   console->Log("Start work");
   console->Log("Did something");
   console->Log("End work");

   // Test 2 - file logger
   auto file = std::make_unique<file_creator>("log.txt");
   file->Log("Start work");
   file->Log("Did something");
   file->Log("End work");

   return EXIT_SUCCESS;
}
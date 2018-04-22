#include "ConfigParser.h"


int main()
{
  ConfigParser config = ConfigParser();
  config.read("../examples/conf1.conf");

  config.printConfig();
}

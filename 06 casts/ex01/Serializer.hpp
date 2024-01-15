#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <cerrno>
# include <climits>
# include <cfloat>
# include <string>
# include <exception>
# include <iostream>
# include <limits>
# include <stdlib.h>
# include <iostream>
# include <iomanip>
# include <math.h>
# include <bitset>
// # include <cstdint>
# include <stdint.h>

struct Data {
  std::string name;
  int         age;
};

class Serializer {
  public:
    static uintptr_t serialize  (Data* ptr);
    static Data*     deserialize(uintptr_t raw);
};

#endif
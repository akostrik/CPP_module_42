#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream> // std
# include <stdint.h> // uintptr_t

struct Data {
  std::string name;
  int         age;
};

class Serializer {
  private:
                   Serializer  ();
                   Serializer  (const Serializer &obj);
  Serializer       &operator = (const Serializer &obj);

  public:
                   ~Serializer ();
  static uintptr_t serialize   (Data* ptr);
  static Data*     deserialize (uintptr_t raw);
};

#endif
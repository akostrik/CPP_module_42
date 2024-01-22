#include "Serializer.hpp"

int main() {
  Data        data              = {"Peter", 25};
  uintptr_t   serialized_data   = Serializer::serialize(&data);
  Data*       deserialized_data = Serializer::deserialize(serialized_data);

  std::cout << "Name, age before the operation " << deserialized_data->name << ", " << deserialized_data->age << std::endl;
  std::cout << "data ptr                       " << &data                        << std::endl;
  std::cout << "Serialized data ptr            " << serialized_data              << std::endl;
  std::cout << "Deserialized data ptr          " << deserialized_data            << std::endl;
  std::cout << "&data == deserialized_data ?   " << (&data == deserialized_data) << std::endl;
  std::cout << "Name, age after the operation  " << deserialized_data->name << ", " << deserialized_data->age << std::endl;
  return 0;
}

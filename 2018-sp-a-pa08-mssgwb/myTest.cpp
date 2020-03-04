/* main and it's supporting extras
*/

#include "MyUnorderedMap.h"


int main()
{
  std::string my_id[2];
  get_identity(my_id);
  std::cout << my_id[0] << "-" << my_id[1] << std::endl;

  MyUnorderedMap<std::string, long> unordered_map_obj;
  MyUnorderedMap<std::string, long> unordered_map_obj2;
  MyUnorderedMap<std::string, long> unordered_map_obj3;

  unordered_map_obj.clear();
  unordered_map_obj3["key22"] = 5;
  unordered_map_obj3.print();
  cout << endl;

  unordered_map_obj.insert(MyPair<std::string, long>("aoeu", 2));
  cout << endl;
  unordered_map_obj.insert(MyPair<std::string, long>("key2", 4));
  cout << endl;
  unordered_map_obj.insert(MyPair<std::string, long>("key3", 6));
  cout << endl;
  unordered_map_obj.insert(MyPair<std::string, long>("key4", 6));
  unordered_map_obj.insert(MyPair<std::string, long>("key5", 6));
  unordered_map_obj.insert(MyPair<std::string, long>("key6", 6));
  unordered_map_obj.insert(MyPair<std::string, long>("key7", 20));
  unordered_map_obj.insert(MyPair<std::string, long>("key8", 20));
  unordered_map_obj.insert(MyPair<std::string, long>("key9", 20));
  unordered_map_obj.insert(MyPair<std::string, long>("key10", 20));
  cout << endl;
  unordered_map_obj.at("key5") = 37;
  unordered_map_obj["key22"] = 5;
  cout << "Finding Key 5: "<<(unordered_map_obj.find("key35") == nullptr) << endl;
  
  unordered_map_obj.erase("aoeu");
  unordered_map_obj.erase("key2");
  unordered_map_obj.erase("key3");
  unordered_map_obj.erase("key4");
  unordered_map_obj.erase("key5");
  unordered_map_obj.erase("key6");
  unordered_map_obj.erase("key7");
  unordered_map_obj.erase("key8");
  unordered_map_obj.erase("key9");
  unordered_map_obj.erase("key10");
  
  unordered_map_obj.print();
  cout << endl;

  cout << "Data Size: " << unordered_map_obj.size() << endl;
  cout << "Count: " << unordered_map_obj.count("aoeu") << endl;
  //unordered_map_obj.insert(MyPair<std::string, int>("aoeu", 2));
  //unordered_map_obj["key3"] = 5;
  //unordered_map_obj.at("key5") = 37;

  cout << "\nMap obj 2" << endl;
  unordered_map_obj3 = unordered_map_obj2 = unordered_map_obj;
  unordered_map_obj.clear();
  unordered_map_obj2.print();
  MyUnorderedMap<std::string, long> unordered_map_obj4(unordered_map_obj2);

  return 0;
}


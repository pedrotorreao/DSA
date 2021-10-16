/*********************************************************************************************/
/* Problem: Animal Shelter (CtCi 3.6) ********/
/*********************************************************************************************/
/*
--Problem statement:
  An animal shelter, which holds only dogs and cats, operates on a stricty "first in, first out"
  basis. People must adopt either the "oldest" (based on arrival time) of all animals at the
  shelter, or they can select whether they would prefer a dog or a cat (and will receive the
  oldest animal of that type). They cannot select which specific animal they would like. Create
  the data structure to maintain this system and implement operations such as enqueue, dequeueAny,
  dequeueDog and dequeueCat. You may use the built-in LinkedList data structure.

--Reasoning:


--Time complexity:

--Space complexity:

*/

#include <iostream>
#include <string>
#include <list>

class AnimalShelterQueue
{
private:
  std::list<std::string> shelter_queue;

public:
  void enqueue(std::string str)
  {
    //..code
  }

  std::string dequeueAny(void)
  {
    //..code
  }

  std::string dequeueDog(void)
  {
    //..code
  }

  std::string dequeueCat(void)
  {
    //..code
  }

  AnimalShelterQueue(/* args */) {}
  ~AnimalShelterQueue() {}
};

int main()
{
  AnimalShelterQueue shelter;

  // ..code

  return 0;
}

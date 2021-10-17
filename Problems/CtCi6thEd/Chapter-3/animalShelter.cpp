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
  Maintain two queues internally, one for dogs and the other for cats. Keep also an integer to
  store the order in which the elements are entered. Both of these queues store the animals name
  and the order. When asked to dequeueAny(), compare both queue's front elements, the one with
  the lower value of order is the one entered first, so it's the one which should be dequeued.

--Time complexity: O(1)

--Space complexity: O(N), where N is the total number of animals

*/

#include <iostream>
#include <string>
#include <cctype>
#include <list>
#include <utility>
#include <vector>

class AnimalShelterQueue
{
private:
  std::list<std::pair<std::string, int>> dog_queue;
  std::list<std::pair<std::string, int>> cat_queue;
  int order;

public:
  void enqueue(std::pair<char, std::string> animal_id)
  {
    char whatAnimal{};
    whatAnimal = toupper(animal_id.first);

    if (whatAnimal == 'D')
    {
      ++order;
      dog_queue.push_back(std::make_pair(animal_id.second, order));
    }
    else if (whatAnimal == 'C')
    {
      ++order;
      cat_queue.push_back(std::make_pair(animal_id.second, order));
    }
    else
    {
      std::cout << "Sorry, but the animal shelter holds only dogs and cats\n";
    }
  }

  std::string dequeueAny(void)
  {
    if (dog_queue.empty() && cat_queue.empty())
    {
      return "There are no animals in the shelter";
    }

    if (dog_queue.empty() || (dog_queue.front().second > cat_queue.front().second))
    {
      return dequeueCat();
    }

    return dequeueDog();
  }

  std::string dequeueDog(void)
  {
    if (!dog_queue.empty())
    {
      std::string dog_name = dog_queue.front().first;
      dog_queue.pop_front();

      return dog_name;
    }
    return "There are no Dogs in the shelter";
  }

  std::string dequeueCat(void)
  {
    if (!cat_queue.empty())
    {
      std::string cat_name = cat_queue.front().first;
      cat_queue.pop_front();

      return cat_name;
    }
    return "There are no Cats in the shelter";
  }

  void shelter_animals(void)
  {
    if (!dog_queue.empty())
    {
      std::cout << "Dogs: ";
      auto it = dog_queue.begin();
      while (it != dog_queue.end())
      {
        std::cout << it->first << "  ";
        ++it;
      }
      std::cout << "\n";
    }
    else
    {
      std::cout << "Dogs: empty\n";
    }

    if (!cat_queue.empty())
    {
      std::cout << "Cats: ";
      auto it = cat_queue.begin();
      while (it != cat_queue.end())
      {
        std::cout << it->first << "  ";
        ++it;
      }
      std::cout << "\n";
    }
    else
    {
      std::cout << "Cats: empty\n";
    }
    std::cout << "\n";
  }

  AnimalShelterQueue()
  {
    this->order = 0;
  }
  ~AnimalShelterQueue() = default;
};

int main()
{
  AnimalShelterQueue shelter;

  std::vector<std::pair<char, std::string>> animals{
      {'D', "Hulk"}, {'C', "Garfield"}, {'C', "Soneca"}, {'D', "Piaba"}, {'C', "Nino"}, {'D', "Toto"}, {'D', "Baleia"}, {'C', "Jao"}};

  std::cout << "Dequeue any: " << shelter.dequeueAny() << "\n";
  std::cout << "Dequeue dog: " << shelter.dequeueDog() << "\n";
  std::cout << "Dequeue cat: " << shelter.dequeueCat() << "\n";

  for (auto animal : animals)
  {
    shelter.enqueue(animal);
  }

  shelter.shelter_animals();

  std::cout << "Dequeue any: " << shelter.dequeueAny() << "\n";
  std::cout << "Dequeue any: " << shelter.dequeueAny() << "\n";

  shelter.shelter_animals();

  std::cout << "Dequeue dog: " << shelter.dequeueDog() << "\n";
  shelter.shelter_animals();
  std::cout << "Dequeue cat: " << shelter.dequeueCat() << "\n";
  shelter.shelter_animals();

  std::cout << "Dequeue any: " << shelter.dequeueAny() << "\n";
  shelter.shelter_animals();

  return 0;
}

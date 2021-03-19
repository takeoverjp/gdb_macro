#include <iostream>
#include <memory>
#include <vector>

class Animal {
 public:
  virtual ~Animal() {}
  virtual void MakeSound() const { std::cout << "#!@" << std::endl; }
};

class Cat : public Animal {
 public:
  virtual ~Cat() {}
  virtual void MakeSound() const { std::cout << "Meow" << std::endl; }
};

class Dog : public Animal {
 public:
  virtual ~Dog() {}
  virtual void MakeSound() const { std::cout << "Bow" << std::endl; }
};

class Human : public Animal {
 public:
  explicit Human(int age) : age_(age) {}
  virtual ~Human() {}
  virtual void MakeSound() const { std::cout << "Hello" << std::endl; }

 private:
  int age_;
};

class Baby : public Human {
 public:
  explicit Baby(int age, bool can_stand) : Human(age), can_stand_(can_stand) {}
  virtual ~Baby() {}
  virtual void MakeSound() const { std::cout << "Baboo" << std::endl; }

 private:
  bool can_stand_;
};

static void Chorus(const std::vector<std::unique_ptr<Animal>>& animals) {
  for (const auto& animal : animals) {
    animal->MakeSound();
  }
}

int main() {
  std::vector<std::unique_ptr<Animal>> animals;
  animals.push_back(std::make_unique<Animal>());
  animals.push_back(std::make_unique<Cat>());
  animals.push_back(std::make_unique<Dog>());
  animals.push_back(std::make_unique<Human>(20));
  animals.push_back(std::make_unique<Baby>(3, true));

  Chorus(animals);
  return 0;
}

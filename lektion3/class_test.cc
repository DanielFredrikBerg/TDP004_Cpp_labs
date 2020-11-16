class Race
{
public:
  virtual void eat() = 0;
  
};

class Human : public Race
{
public:
  void eat() override;
  
};

class Orc : public Race
{
public:
  void eat() override { return; }
      
}; 

class Uruk_Hai : public Human, public Orc
{
  
public:
  using Human::eat;
};

int main() 
{
  Uruk_Hai* uruk = new Uruk_Hai;
  uruk->eat();
  return 0;
}

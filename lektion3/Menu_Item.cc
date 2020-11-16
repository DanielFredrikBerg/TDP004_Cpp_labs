#include <string>
#include <vector>

class Menu_Item
{
public:
  Menu_Item(string const& t) : title(t) {}
  virtual ~Menu_Item();
  virtual void execute() = 0;
private:
  string title;
};


class Menu : public Menu_Item
{
public:
  Menu(string const& t) : Menu_Item(t) {}
  ~Menu() { /* delete all items in list */ }
  void add_menu_item(Menu_Item* i) { item_list.push_back(i); }
  void execute() override { /* user chose one menu item and execute i */ }
private:
  vector<Menu_Item*> item_list;
};

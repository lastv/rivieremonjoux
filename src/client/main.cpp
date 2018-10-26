#include <iostream>
#include <SFML/Graphics.hpp>
#include <typeinfo>
#include "string.h"
#include "state.h"
#include "render.h"

#define quote(x) #x

using namespace std;
using namespace state;
using namespace render;
using namespace sf;

void renderWindow(ElementTabLayer* layer) {

    sf::RenderWindow window(sf::VideoMode(1440,1160), "Darkest Dungeon Like");

    sf::Sprite sprite;
    sf::Font font;
    font.loadFromFile("res/dc_o.ttf");
    sf::Text title(layer->getTitle(),font,50);
    title.move(600.f,100.f);


    while (window.isOpen())
   {
       // handle events
       sf::Event event;
       while (window.pollEvent(event))
       {
           if(event.type == sf::Event::Closed)
               window.close();
       }


       window.clear(sf::Color::Black);
       if (layer->getSurfaceList().size() != 1){
         for (uint i=0;i<layer->getSurfaceList().size();i++){
            sprite = layer->getSurface(i)->getSprite();
            sprite.setPosition(std::get<0>(layer->getCoords()[i]),std::get<1>(layer->getCoords()[i]));
            window.draw(sprite);
          }
        } else {
          sprite = layer->getSurface(0)->getSprite();
          sprite.setScale(1.15f,1.7f);
          window.draw(sprite);
        }
       window.draw(title);
       window.display();
   }

}

std::string elementClassNameToString(const char* name){
    std::string intemediary(name);
    return intemediary;
  }



void affichagebeauTest(std::string testname){
  for (int comt=0;comt<50;comt++){
           cout << '_';
  }
  cout << endl;
  for (int comt=0;comt<20;comt++){
  cout << ' ';}
  cout  << "Test " <<testname<< endl;
}

int main(int argc,char* argv[])
{


    //printf("%s\n", argv[1]);
    //printf("%d\n", argc);


    if (argc == 2) {
      if ( !strcmp(argv[1],"hello") ){
        cout << "Bonjour le monde!" << endl;
      } else if (!strcmp(argv[1],"state") ) {
        cout << "Test des différents états" << endl;


         {
           affichagebeauTest("MobileElements");
           MobileElements* e = new MobileElements(true);
           cout <<"is Character:"<< e->isCharacter() << endl;
           cout << "is Static"<<e->isStatic() << endl;
         };
         {
           affichagebeauTest("Character");
           Character* e = new Character(5,2,3,4,5,"test");
           cout <<  " is Character: "<<e->isCharacter() <<endl;
           cout << " is Static: " << e->isStatic()<< endl;
           cout << " life: " << e->getLife()<<endl;
           cout << " life Max: " << e->getLifeMAX()<<endl;
           cout << " att: " << e->getATT()<<endl;
           cout << " def: " << e->getDEF()<< endl;
           cout <<  " spd: "<< e->getSPD()<<endl;
           cout <<  " crit: "<< e->getCrit()<<endl;
           cout <<  " State: "<< e->getState()[0]<<endl;
           cout <<" "<<endl;
           cout <<"Change state to normal"<<endl;
           e->changeState(0);
           cout << "State "<<e->getState()[0] << " State size "<<e->getState().size()<<endl;
           cout <<"Change state to 5"<<endl;
           e->changeState(5);
           cout << "State "<<e->getState()[0] << " State size "<<e->getState().size()<<endl;
           cout <<"Change state to poisoned"<<endl;
           e->changeState(1);
           cout << "State "<<e->getState()[0] << " State size "<<e->getState().size()<<endl;
           cout <<"Change state to poisoned and staggered"<<endl;
           e->changeState(2);
           cout << "State "<<e->getState()[0] << " State size "<<e->getState().size()<<endl;
           cout << "State "<<e->getState()[1] << " State size "<<e->getState().size()<<endl;
           cout <<"Change state to normal"<<endl;
           e->changeState(0);
           cout << "State "<<e->getState()[0] << " State size "<<e->getState().size()<<endl;
           cout <<"Change state to stagered"<<endl;
           e->changeState(2);
           cout << "State "<<e->getState()[0] << " State size "<<e->getState().size()<<endl;
           cout <<"Change state to poisoned and staggered"<<endl;
           e->changeState(1);
           cout << "State "<<e->getState()[0] << " State size "<<e->getState().size()<<endl;
           cout << "State "<<e->getState()[1] << " State size "<<e->getState().size()<<endl;
           cout <<"Change state to poisoned"<<endl;
           e->changeState(1);
           cout << "State "<<e->getState()[0] << " State size "<<e->getState().size()<<endl;
           cout << "State "<<e->getState()[1] << " State size "<<e->getState().size()<<endl;
           cout <<"Change state to stagered"<<endl;
           e->changeState(2);
           cout << "State "<<e->getState()[0] << " State size "<<e->getState().size()<<endl;
           cout << "State "<<e->getState()[1] << " State size "<<e->getState().size()<<endl;
           cout <<"Change state to dead"<<endl;
           e->changeState(3);
           cout << "State "<<e->getState()[0] << " State size "<<e->getState().size()<<endl;
           cout <<"Change state to dead"<<endl;
           e->changeState(3);
           cout << "State "<<e->getState()[0] << " State size "<<e->getState().size()<<endl;
           cout <<"Change state to poisoned"<<endl;
           e->changeState(1);
           cout << "State "<<e->getState()[0] << " State size "<<e->getState().size()<<endl;
           cout <<"Change state to stagered"<<endl;
           e->changeState(2);
           cout << "State "<<e->getState()[0] << " State size "<<e->getState().size()<<endl;
           cout <<"Change state to normal"<<endl;
           e->changeState(0);
           cout << "State "<<e->getState()[0] << " State size "<<e->getState().size()<<endl;
           cout <<" "<<endl;
           cout <<"Change life to -10"<<endl;
           e->setLife(-10);
           cout << "New Life "<<e->getLife() <<endl;
           cout <<"Change life to 10"<<endl;
           e->setLife(10);
           cout << "New Life "<<e->getLife() <<endl;
         };
         {
           affichagebeauTest("Hero");
           Hero* e = new Hero;
           cout << " is monster?" << e->isMonster() <<endl;
           affichagebeauTest("Monsters");
           Monsters* m = new Monsters;
           cout <<  " is monster?" <<m->isMonster() <<endl;
         };
         {
           affichagebeauTest("Tank (une des unitées)");
           Tank* e = new Tank(1,2,3,4,5,"Hadrien");
           cout << " is Character: " <<e->isCharacter() << endl;
           cout << " is Static: "<< e->isStatic() << endl;
           cout <<  " life: "<<e->getLife() <<endl;
           cout << " life Max: "<< e->getLifeMAX()<<endl;
           cout << " att: "<< e->getATT() <<endl;
           cout<< " def: "<<  e->getDEF() << endl;
           cout << " spd: "<< e->getSPD() <<endl;
           cout  << " crit: "<< e->getCrit()<<endl;
           cout  << " State: "<< e->getState()[0]<<endl;
           cout << " Name: "<< e->getName() <<endl;
         };
         {
           affichagebeauTest("Team");
           Tank* e1 = new Tank(1,2,3,4,5,"Hadrien1");
           Tank* e2 = new Tank(1,2,3,4,5,"Hadrien2");
           Tank* e3 = new Tank(1,2,3,4,5,"Hadrien3");
           Tank* e4 = new Tank(1,2,3,4,5,"Hadrien4");
           cout <<"Team creation (of Tanks)"<<endl;
           Team* t=new Team();
           t->addToTeam(e1);
           t->addToTeam(e2);
           t->addToTeam(e3);
           t->addToTeam(e4);
           for (uint i =0;i<t->getTeam().size();i++){Character* intermediary =t->getTeam()[i];cout<<"Tank name "<<intermediary->getName()<<endl;};
           cout <<"removing an element of Team"<<endl;
           t->removeFromTeam(e3);
           for (uint i =0;i<t->getTeam().size();i++){cout<<"Tank name "<<t->getTeam()[i]->getName()<<endl;};
           cout <<"is monster team? "<< t-> isHeroTeam() <<endl;
         };
         {
           affichagebeauTest("StaticElements");
           StaticElements* s = new StaticElements(true);
           cout << "is Building: "<<s->isBuilding() << endl;
           cout << "is Static: "<<s->isStatic() << endl;
         };
         {
           affichagebeauTest("Dungeon");
           std::vector<std::string> maplist;
           maplist.push_back("Map1");
           maplist.push_back("Map2");
           Dungeon* d = new Dungeon(maplist);
           for (uint i =0;i<d->getMapNames().size();i++){cout<<"Map name "<<d->getMapNames()[i]<<endl;};
         };
         {
           affichagebeauTest("Room");
           Tank* e1 = new Tank(1,2,3,4,5,"Hadrien1");
           Tank* e2 = new Tank(1,2,3,4,5,"Hadrien2");
           Blob* b3 = new Blob(1,2,3,4,5,"Hadrien3");
           cout <<"Teams creations"<<endl;
           Team* t1=new Team();
           t1->addToTeam(e1);
           t1->addToTeam(e2);
           Team* t2=new Team();
           t1->addToTeam(b3);
           Room* r = new Room(t1,t2);
         };
         {
           affichagebeauTest("Items");
           Item* s = new Item("potion");
           cout << "is Building: "<<s->isBuilding() << endl;
           cout << "is Static: "<<s->isStatic() << endl;
           cout << "Item Name: "<<s ->getName() << endl;
         };
         {
           affichagebeauTest("Inventory");
           Item* s1 = new Item("potion1");
           Item* s2 = new Item("potion2");
           Item* s3 = new Item("potion3");
           Inventory* i= new Inventory(2);
           cout << "Test adding to inventory" << endl;
           i->addItem(s1->getName());
           i->addItem(s2->getName());
           i->addItem(s1->getName());
           for (auto it : i->getInventory()){
             cout << "Item " <<it.first<<" value "<<it.second<< endl;
           }
           cout << "Test adding too much to inventory" << endl;
           i->addItem(s3->getName());
           for (auto it : i->getInventory()){
             cout << "Item " <<it.first<<" value "<<it.second<< endl;
           }
           cout << "Test clearing from inventory" << endl;
           i->clearItem("potion1");
           for (auto it : i->getInventory()){
             cout << "Item " <<it.first<<" value "<<it.second<< endl;
           }
           cout << "Test removing too much from inventory" << endl;
           i->removeItem("potion1",3);
           for (auto it : i->getInventory()){
             cout << "Item " <<it.first<<" value "<<it.second<< endl;
            }
          };
          {
            affichagebeauTest("Tavern (has a team of max 1 member)");
            Blob* b = new Blob(1,2,3,4,5,"Hadrien");
            Team* t=new Team();
            t->addToTeam(b);
            Tavern* ta = new Tavern(t,1);
            cout << "Adding one character to the team and testing if the team in the tavern is full"<<endl;
            ta->isTeamFull();
            cout << "Getting stats of team member"<<endl;
            ta->getStat(b);
           };

      } else if (!strcmp(argv[1],"render") ) {
          affichagebeauTest("render");
          {

          ElementTab* e =new ElementTab();
          Team* t1=new Team();
          Team* t2=new Team();
          Sorcerer* sorcerer = new Sorcerer(10,20,3,40,5,"Sorcerer");
          t1->addToTeam(sorcerer);
          t2->addToTeam(sorcerer);
          Tavern* tav= new Tavern(t1,1);
          Inventory* inv= new Inventory();
          std::map<std::string,int> shopinventory;
          Shop* shop= new Shop(inv,shopinventory,12);

          Village* r = new Village(tav,shop,3,inv,t1); //Decomenter pour Obtenir l'affichage de l'etat village
          //Room* r = new Room(t1,t2); //Decomenter pour Obtenir l'affichage de l'etat Room
          e->add(r,elementClassNameToString(typeid(r).name()));
          ElementTabLayer* E =new ElementTabLayer(e);
          E->getElementTabTextures();
          renderWindow(E);
          };
      } else {
        cout << "Veuillez tapez hello s'il vous plait." << endl;
      }
    }
    return 0;
}

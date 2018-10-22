// Generated by dia2code
#ifndef STATE__MOBILEELEMENTS__H
#define STATE__MOBILEELEMENTS__H


namespace state {
  class Element;
}

#include "Element.h"

namespace state {

  /// class MobileElements - 
  class MobileElements : public state::Element {
    // Attributes
  protected:
    bool staticElement     = false;
    bool ischaracter;
    // Operations
  public:
    bool isStatic ();
    bool isCharacter ();
    MobileElements (bool iscara);
    ~MobileElements ();
    // Setters and Getters
    bool getStaticElement() const;
    void setStaticElement(bool staticElement);
    bool getIscharacter() const;
    void setIscharacter(bool ischaracter);
  };

};

#endif

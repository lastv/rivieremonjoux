// Generated by dia2code
#ifndef STATE__ELEMENT__H
#define STATE__ELEMENT__H


namespace state {

  /// class Element - 
  class Element {
    // Attributes
  protected:
    bool staticElement;
    // Operations
  public:
    Element (bool isstat);
    ~Element ();
    // Setters and Getters
    bool getStaticElement() const;
    void setStaticElement(bool staticElement);
  };

};

#endif
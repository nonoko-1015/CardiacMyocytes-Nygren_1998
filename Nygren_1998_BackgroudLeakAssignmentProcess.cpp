
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998_BackgroudLeakAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998_BackgroudLeakAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );

    PROPERTYSLOT_SET_GET( Real, g );

  }

  Nygren_1998_BackgroudLeakAssignmentProcess()
  {
    // do nothing
  }

  SIMPLE_SET_GET_METHOD( Real, g );


  virtual void initialize()
  {
    Process::initialize();

    i = getVariableReference( "i" ).getVariable();
    V = getVariableReference( "V" ).getVariable();
    E = getVariableReference( "E" ).getVariable();

  }

  virtual void fire()
  {
    i->setValue( g * ( V->getValue() - E->getValue()) );

  }

 protected:

  Variable* i;
  Variable* V;
  Variable* E;

  Real g;

};

LIBECS_DM_INIT( Nygren_1998_BackgroudLeakAssignmentProcess, Process );

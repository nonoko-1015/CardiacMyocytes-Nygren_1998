
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998E_KAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998E_KAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );

    PROPERTYSLOT_SET_GET( Real, R );
    PROPERTYSLOT_SET_GET( Real, T );
    PROPERTYSLOT_SET_GET( Real, F );

  }

  Nygren_1998E_KAssignmentProcess()
  {
    // do nothing
  }

  SIMPLE_SET_GET_METHOD( Real, R );
  SIMPLE_SET_GET_METHOD( Real, T );
  SIMPLE_SET_GET_METHOD( Real, F );


  virtual void initialize()
  {
    Process::initialize();

    E_K  = getVariableReference( "E_K" ).getVariable();
    K_c  = getVariableReference( "K_c" ).getVariable();
    K_i  = getVariableReference( "K_i" ).getVariable();

  }

  virtual void fire()
  {
    E_K->setValue( 1 * (((R*T)/F)*log((K_c->getMolarConc()*1000)/(K_i->getMolarConc()*1000))) );

  }

 protected:

  Variable* E_K;
  Variable* K_c;
  Variable* K_i;

  Real R;
  Real T;
  Real F;

};

LIBECS_DM_INIT( Nygren_1998E_KAssignmentProcess, Process );

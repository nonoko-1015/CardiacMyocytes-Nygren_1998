
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998E_CaAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998E_CaAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );

    PROPERTYSLOT_SET_GET( Real, R );
    PROPERTYSLOT_SET_GET( Real, T );
    PROPERTYSLOT_SET_GET( Real, F );

  }

  Nygren_1998E_CaAssignmentProcess()
  {
    // do nothing
  }

  SIMPLE_SET_GET_METHOD( Real, R );
  SIMPLE_SET_GET_METHOD( Real, T );
  SIMPLE_SET_GET_METHOD( Real, F );


  virtual void initialize()
  {
    Process::initialize();

    E_Ca  = getVariableReference( "E_Ca" ).getVariable();
    Ca_c  = getVariableReference( "Ca_c" ).getVariable();
    Ca_i  = getVariableReference( "Ca_i" ).getVariable();

  }

  virtual void fire()
  {
    E_Ca->setValue( 1 * (((R*T)/(2.00000*F))*log(Ca_c->getValue()/Ca_i->getValue())) );

  }

 protected:

  Variable* E_Ca;
  Variable* Ca_c;
  Variable* Ca_i;

  Real R;
  Real T;
  Real F;

};

LIBECS_DM_INIT( Nygren_1998E_CaAssignmentProcess, Process );

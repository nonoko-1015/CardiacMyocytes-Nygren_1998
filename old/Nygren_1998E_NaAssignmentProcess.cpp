
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998E_NaAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998E_NaAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );

    PROPERTYSLOT_SET_GET( Real, R );
    PROPERTYSLOT_SET_GET( Real, T );
    PROPERTYSLOT_SET_GET( Real, F );

  }

  Nygren_1998E_NaAssignmentProcess()
  {
    // do nothing
  }

  SIMPLE_SET_GET_METHOD( Real, R );
  SIMPLE_SET_GET_METHOD( Real, T );
  SIMPLE_SET_GET_METHOD( Real, F );


  virtual void initialize()
  {
    Process::initialize();

    E_Na  = getVariableReference( "E_Na" ).getVariable();
    Na_c  = getVariableReference( "Na_c" ).getVariable();
    Na_i  = getVariableReference( "Na_i" ).getVariable();

  }

  virtual void fire()
  {
    E_Na->setValue( 1 * (((R*T)/F)*log((Na_c->getMolarConc()*1000)/(Na_i->getMolarConc()*1000))) );

  }

 protected:

  Variable* E_Na;
  Variable* Na_c;
  Variable* Na_i;

  Real R;
  Real T;
  Real F;

};

LIBECS_DM_INIT( Nygren_1998E_NaAssignmentProcess, Process );


#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998i_B_NaAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998i_B_NaAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );

    PROPERTYSLOT_SET_GET( Real, g_B_Na );

  }

  Nygren_1998i_B_NaAssignmentProcess()
  {
    // do nothing
  }

  SIMPLE_SET_GET_METHOD( Real, g_B_Na );


  virtual void initialize()
  {
    Process::initialize();

    i_B_Na  = getVariableReference( "i_B_Na" ).getVariable();
    V  = getVariableReference( "V" ).getVariable();
    E_Na  = getVariableReference( "E_Na" ).getVariable();

  }

  virtual void fire()
  {
    i_B_Na->setValue( 1 * (g_B_Na*(V->getValue()-E_Na->getValue())) );

  }

 protected:

  Variable* i_B_Na;
  Variable* V;
  Variable* E_Na;

  Real g_B_Na;

};

LIBECS_DM_INIT( Nygren_1998i_B_NaAssignmentProcess, Process );

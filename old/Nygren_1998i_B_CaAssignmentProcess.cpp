
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998i_B_CaAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998i_B_CaAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );

    PROPERTYSLOT_SET_GET( Real, g_B_Ca );

  }

  Nygren_1998i_B_CaAssignmentProcess()
  {
    // do nothing
  }

  SIMPLE_SET_GET_METHOD( Real, g_B_Ca );


  virtual void initialize()
  {
    Process::initialize();

    i_B_Ca  = getVariableReference( "i_B_Ca" ).getVariable();
    V  = getVariableReference( "V" ).getVariable();
    E_Ca  = getVariableReference( "E_Ca" ).getVariable();

  }

  virtual void fire()
  {
    i_B_Ca->setValue( 1 * (g_B_Ca*(V->getValue()-E_Ca->getValue())) );

  }

 protected:

  Variable* i_B_Ca;
  Variable* V;
  Variable* E_Ca;

  Real g_B_Ca;

};

LIBECS_DM_INIT( Nygren_1998i_B_CaAssignmentProcess, Process );

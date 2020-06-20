
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998i_susAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998i_susAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );

    PROPERTYSLOT_SET_GET( Real, g_sus );

  }

  Nygren_1998i_susAssignmentProcess()
  {
    // do nothing
  }

  SIMPLE_SET_GET_METHOD( Real, g_sus );


  virtual void initialize()
  {
    Process::initialize();

    i_sus  = getVariableReference( "i_sus" ).getVariable();
    r_sus  = getVariableReference( "r_sus" ).getVariable();
    s_sus  = getVariableReference( "s_sus" ).getVariable();
    V  = getVariableReference( "V" ).getVariable();
    E_K  = getVariableReference( "E_K" ).getVariable();

  }

  virtual void fire()
  {
    i_sus->setValue( 1 * (g_sus*r_sus->getValue()*s_sus->getValue()*(V->getValue()-E_K->getValue())) );

  }

 protected:

  Variable* i_sus;
  Variable* r_sus;
  Variable* s_sus;
  Variable* V;
  Variable* E_K;

  Real g_sus;

};

LIBECS_DM_INIT( Nygren_1998i_susAssignmentProcess, Process );

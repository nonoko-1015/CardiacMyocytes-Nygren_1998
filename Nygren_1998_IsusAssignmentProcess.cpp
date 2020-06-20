
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998_IsusAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998_IsusAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );

    PROPERTYSLOT_SET_GET( Real, g_sus );
  }

  Nygren_1998_IsusAssignmentProcess()
  {
    // do nothing
  }

  SIMPLE_SET_GET_METHOD( Real, g_sus );

  virtual void initialize()
  {
    Process::initialize();

    tau_r_sus  = getVariableReference( "tau_r_sus" ).getVariable();
    r_sus_infinity  = getVariableReference( "r_sus_infinity" ).getVariable();
    tau_s_sus  = getVariableReference( "tau_s_sus" ).getVariable();
    s_sus_infinity  = getVariableReference( "s_sus_infinity" ).getVariable();
    i_sus  = getVariableReference( "i_sus" ).getVariable();
    r_sus  = getVariableReference( "r_sus" ).getVariable();
    s_sus  = getVariableReference( "s_sus" ).getVariable();
    V  = getVariableReference( "V" ).getVariable();
    E_K  = getVariableReference( "E_K" ).getVariable();

  }

  virtual void fire()
  {
    v = V->getValue();
    i_sus->setValue( g_sus*r_sus->getValue()*s_sus->getValue()*(v-E_K->getValue()) );
    tau_r_sus->setValue( 0.00900000/(1.00000+exp((v+5.00000)/12.0000))+0.000500000 );
    r_sus_infinity->setValue( 1.00000/(1.00000+exp((v+4.30000)/-8.00000)) );
    tau_s_sus->setValue( 0.0470000/(1.00000+exp((v+60.0000)/10.0000))+0.300000 );
    s_sus_infinity->setValue( 0.400000/(1.00000+exp((v+20.0000)/10.0000))+0.600000 );

  }

 protected:

  Variable* tau_r_sus;
  Variable* r_sus_infinity;
  Variable* tau_s_sus;
  Variable* s_sus_infinity;
  Variable* i_sus;
  Variable* r_sus;
  Variable* s_sus;
  Variable* V;
  Variable* E_K;

  Real g_sus;
  Real v;
};

LIBECS_DM_INIT( Nygren_1998_IsusAssignmentProcess, Process );

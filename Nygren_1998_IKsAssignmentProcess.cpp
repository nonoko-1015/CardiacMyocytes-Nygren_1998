
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998_IKsAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998_IKsAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );

    PROPERTYSLOT_SET_GET( Real, g_Ks );

  }

  Nygren_1998_IKsAssignmentProcess()
  {
    // do nothing
  }

  SIMPLE_SET_GET_METHOD( Real, g_Ks );


  virtual void initialize()
  {
    Process::initialize();

    tau_n  = getVariableReference( "tau_n" ).getVariable();
    n_infinity  = getVariableReference( "n_infinity" ).getVariable();
    i_Ks  = getVariableReference( "i_Ks" ).getVariable();
    n  = getVariableReference( "n" ).getVariable();
    V  = getVariableReference( "V" ).getVariable();
    E_K  = getVariableReference( "E_K" ).getVariable();

  }

  virtual void fire()
  {
    v = V->getValue();
    tau_n->setValue( 0.700000+0.400000*exp(-(pow((v-20.0000)/20.0000, 2.00000))) );
    n_infinity->setValue( 1.00000/(1.00000+exp((v-19.9000)/-12.7000)) );
    i_Ks->setValue( g_Ks*n->getValue()*(v-E_K->getValue()) );

  }

 protected:

  Variable* tau_n;
  Variable* n_infinity;
  Variable* i_Ks;
  Variable* n;
  Variable* V;
  Variable* E_K;

  Real g_Ks;
  Real v;
};

LIBECS_DM_INIT( Nygren_1998_IKsAssignmentProcess, Process );

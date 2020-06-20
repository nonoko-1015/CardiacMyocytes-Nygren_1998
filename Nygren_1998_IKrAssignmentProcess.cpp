
#include "libecs.hpp"
#include "Process.hpp"

USE_LIBECS;

LIBECS_DM_CLASS( Nygren_1998_IKrAssignmentProcess, Process )
{

 public:

  LIBECS_DM_OBJECT( Nygren_1998_IKrAssignmentProcess, Process )
  {
    INHERIT_PROPERTIES( Process );

    PROPERTYSLOT_SET_GET( Real, g_Kr );
  }

  Nygren_1998_IKrAssignmentProcess()
  {
    // do nothing
  }

  SIMPLE_SET_GET_METHOD( Real, g_Kr );

  virtual void initialize()
  {
    Process::initialize();

    tau_p_a  = getVariableReference( "tau_p_a" ).getVariable();
    p_a_infinity  = getVariableReference( "p_a_infinity" ).getVariable();
    p_i  = getVariableReference( "p_i" ).getVariable();
    i_Kr  = getVariableReference( "i_Kr" ).getVariable();
    p_a  = getVariableReference( "p_a" ).getVariable();
    V  = getVariableReference( "V" ).getVariable();
    E_K  = getVariableReference( "E_K" ).getVariable();

  }

  virtual void fire()
  {
    v = V->getValue();
    tau_p_a->setValue( 0.0311800+0.217180*exp(-(pow((v+20.1376)/22.1996, 2.00000))) );
    p_a_infinity->setValue( 1.00000/(1.00000+exp((v+15.0000)/-6.00000)) );
    p_i->setValue( 1.00000/(1.00000+exp((v+55.0000)/24.0000)) );
    i_Kr->setValue( g_Kr*p_a->getValue()*p_i->getValue()*(v-E_K->getValue()) );

  }

 protected:

  Variable* tau_p_a;
  Variable* p_a_infinity;
  Variable* i_Kr;
  Variable* p_a;
  Variable* p_i;
  Variable* V;
  Variable* E_K;

  Real g_Kr;
  Real v;
};

LIBECS_DM_INIT( Nygren_1998_IKrAssignmentProcess, Process );
